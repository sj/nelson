//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include "loadBuiltin.hpp"
#include "Error.hpp"
#include "IsValidVariableName.hpp"
#include "BuiltInFunctionDefManager.hpp"
#include "PathFuncManager.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
// load(filename, '-mat') regardless file extension force as .mat
// load(filename, '-nh5') regardless file extension force as .nh5
// load(filename, variables)
//=============================================================================
static bool
isOption(const std::wstring& param)
{
    return param.size() > 2 && param[0] == L'-';
}
//=============================================================================
static bool
isFile(const std::wstring& _filename)
{
    boost::filesystem::path filename(_filename);
    bool fileExistPreviously = false;
    try {
        fileExistPreviously
            = boost::filesystem::exists(filename) && !boost::filesystem::is_directory(filename);
    } catch (const boost::filesystem::filesystem_error& e) {
        if (e.code() == boost::system::errc::permission_denied) {
            Error(_W("Permission denied."));
        }
        fileExistPreviously = false;
    }
    return fileExistPreviously;
}
//=============================================================================
ArrayOfVector
Nelson::StreamGateway::loadBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    nargoutcheck(nLhs, 0, 1);
    nargincheck(argIn, 1);
    std::wstring paramFilename = argIn[0].getContentAsWideString();
    if (paramFilename.empty()) {
        Error(_W("Filename is empty"));
    }
    wstringVector names;
    bool forceAsMat = false;
    bool forceAsNh5 = false;
    for (size_t k = 1; k < argIn.size(); k++) {
        ArrayOf paramK = argIn[k];
        std::wstring param = paramK.getContentAsWideString();
        if (isOption(param)) {
            if (param == L"-mat" && !forceAsNh5) {
                forceAsMat = true;
            } else if (param == L"-nh5" && !forceAsMat) {
                forceAsNh5 = true;
            } else {
                Error(_W("Valid option expected."));
            }
        } else {
            if (IsValidVariableName(param)) {
                names.push_back(param);
            } else {
                Error(_W("Valid variable name expected."));
            }
        }
    }
    bool fileExistPreviously = isFile(paramFilename);
    if (!fileExistPreviously) {
        std::string extension = boost::filesystem::extension(paramFilename);
        if (extension.empty()) {
            paramFilename = paramFilename + L".nh5";
            fileExistPreviously = isFile(paramFilename);
        }
    }
    if (!fileExistPreviously) {
        Error(_W("File does not exist."));
    }

    std::string loadFunctionName;
    if (forceAsMat || forceAsNh5) {
        if (forceAsNh5) {
            loadFunctionName = "loadnh5";
        } else {
            loadFunctionName = "loadmat";
        }
    } else {
        bool isNh5 = false;
        bool isMat = false;
        // try detect if it is a .nh5
        FunctionDef* funcDef = nullptr;
        if (!PathFuncManager::getInstance()->find("isnh5file", funcDef)) {
            BuiltInFunctionDefManager::getInstance()->find("isnh5file", funcDef);
        }
        if (funcDef) {
            ArrayOfVector inputArguments;
            inputArguments.push_back(ArrayOf::characterArrayConstructor(paramFilename));
            ArrayOfVector res = funcDef->evaluateFunction(eval, inputArguments, 1);
            if (res.size() == 1) {
                isNh5 = res[0].getContentAsLogicalScalar();
            }
        }

        if (!isNh5) {
            // try detect if it is a .mat
            FunctionDef* funcDef = nullptr;
            if (!PathFuncManager::getInstance()->find("ismatfile", funcDef)) {
                BuiltInFunctionDefManager::getInstance()->find("ismatfile", funcDef);
            }
            if (funcDef) {
                ArrayOfVector inputArguments;
                inputArguments.push_back(ArrayOf::characterArrayConstructor(paramFilename));
                ArrayOfVector res = funcDef->evaluateFunction(eval, inputArguments, 1);
                if (res.size() == 1) {
                    isMat = res[0].getContentAsLogicalScalar();
                }
            }
        }
        if (isNh5) {
            loadFunctionName = "loadnh5";
        } else if (isMat) {
            loadFunctionName = "loadmat";
        } else {
            loadFunctionName = "loadnh5";
        }
    }

    FunctionDef* funcDef = nullptr;
    if (!PathFuncManager::getInstance()->find(loadFunctionName, funcDef)) {
        if (!BuiltInFunctionDefManager::getInstance()->find(loadFunctionName, funcDef)) {
            Error(_W("load function expected."));
        }
    }
    ArrayOfVector inputArguments;
    inputArguments.push_back(ArrayOf::characterArrayConstructor(paramFilename));
    for (const std::wstring& name : names) {
        inputArguments.push_back(ArrayOf::characterArrayConstructor(name));
    }
    return funcDef->evaluateFunction(eval, inputArguments, nLhs);
}
//=============================================================================
