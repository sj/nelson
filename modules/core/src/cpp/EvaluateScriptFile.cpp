//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS /* _wfopen */
#endif
//=============================================================================
#include <boost/filesystem.hpp>
#include "Error.hpp"
#include "EvaluateScriptFile.hpp"
#include "ParserInterface.hpp"
#include "IsEmptyScriptFile.hpp"
#include "NelsonConfiguration.hpp"
#include "ChangeDirectory.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
static void
mustBeExistingFile(const std::wstring& filename)
{
    bool bIsFile;
    try {
        bIsFile = boost::filesystem::exists(filename) && !boost::filesystem::is_directory(filename);
    } catch (const boost::filesystem::filesystem_error&) {
        bIsFile = false;
    }
    if (!bIsFile) {
        Error(_W("File does not exist.") + L"\n" + filename);
    }
}
//=============================================================================
static FILE*
filePointerWithoutShebang(const boost::filesystem::path& absolutePath)
{
#ifdef _MSC_BUILD
    FILE* fr = _wfopen(absolutePath.generic_wstring().c_str(), L"rt");
#else
    FILE* fr = fopen(absolutePath.generic_string().c_str(), "rt");
#endif
    if (!fr) {
        return fr;
    }
    bool bBOM = false;
    bool bSheBang = false;
    char _buffer[8192];
    fpos_t pos;
    fgetpos(fr, &pos); //-V530 //-V575
    const char* utf8bom = "\xef\xbb\xbf";
    // UTF-8 bom
    indexType nread = fread(_buffer, sizeof(char), strlen(utf8bom), fr);
    if (nread == 0) {
        fsetpos(fr, &pos);
        fgetpos(fr, &pos); //-V530
    } else {
        _buffer[nread] = '\0';
        bBOM = (strcmp(_buffer, utf8bom) == 0);
        if (bBOM) {
            fgetpos(fr, &pos); //-V530
        } else {
            fsetpos(fr, &pos);
        }
    }
    if (fgets(_buffer, 4096, fr) != nullptr) {
        const char* shebang = "#!";
        bSheBang = (strncmp(_buffer, shebang, strlen(shebang)) == 0);
        if (bSheBang) {
            fgetpos(fr, &pos); //-V530
        } else {
            fsetpos(fr, &pos);
        }
    } else {
        fsetpos(fr, &pos);
        fgetpos(fr, &pos); //-V530
    }
    return fr;
}
//=============================================================================
bool
EvaluateScriptFile(Evaluator* eval, const std::wstring& filename, bool bChangeDirectory)
{
    bool bNeedToRestoreDirectory = false;

    mustBeExistingFile(filename);
    if (IsEmptyScriptFile(filename)) {
        return true;
    }
    boost::filesystem::path initialDir = boost::filesystem::current_path();
    boost::filesystem::path fileToEvaluate(filename);
    boost::filesystem::path absolutePath = boost::filesystem::absolute(fileToEvaluate);
    if (fileToEvaluate.has_branch_path() && bChangeDirectory) {
        bNeedToRestoreDirectory = true;
        boost::filesystem::path newDir = fileToEvaluate.parent_path();
        ChangeDirectory(newDir.generic_wstring(), false);
    }
    FILE* fr = filePointerWithoutShebang(absolutePath);
    if (fr == nullptr) {
        if (bNeedToRestoreDirectory) {
            ChangeDirectory(initialDir.generic_wstring(), false);
        }
        return false;
    }
    eval->pushEvaluateFilenameList(absolutePath.generic_wstring());
    ParserState pstate = ParseError;
    AbstractSyntaxTree::clearReferences();
    AbstractSyntaxTreePtrVector pt;

    try {
        pstate = parseFile(fr, absolutePath.generic_string());
        pt = AbstractSyntaxTree::getReferences();
    } catch (const Exception&) {
        eval->popEvaluateFilenameList();
        AbstractSyntaxTree::deleteReferences();
        fclose(fr);
        if (bNeedToRestoreDirectory) {
            ChangeDirectory(initialDir.generic_wstring(), false);
        }
        throw; //-V565
    }

    Exception currentException;
    bool needThrowException = false;
    MacroFunctionDef* fptr = nullptr;
    try {
        fptr = new MacroFunctionDef(absolutePath.generic_wstring(), true);
        try {
            ArrayOfVector argIn;
            fptr->evaluateFunction(eval, argIn, 0);
        } catch (std::bad_alloc&) {
        } //-V565
    } catch (const Exception& ce) {
        currentException = ce;
        needThrowException = true;
    }

    eval->popEvaluateFilenameList();

    AbstractSyntaxTree::deleteReferences(pt);
    AbstractSyntaxTree::clearReferences();

    if (fptr != nullptr) {
        delete fptr;
        fptr = nullptr;
    }

    if (fr) {
        fclose(fr);
        fr = nullptr;
    }

    if (bNeedToRestoreDirectory) {
        ChangeDirectory(initialDir.generic_wstring(), false);
    }

    if (needThrowException) {
        throw currentException;
    }
    return true;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
