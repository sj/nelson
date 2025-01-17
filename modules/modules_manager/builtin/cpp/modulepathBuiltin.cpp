//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "modulepathBuiltin.hpp"
#include "Error.hpp"
#include "ModulePath.hpp"
#include "ModulesHelpers.hpp"
#include "ModulesManager.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
#define STR_OPTION_ETC L"etc"
#define STR_OPTION_BIN L"bin"
#define STR_OPTION_ROOT L"root"
#define STR_OPTION_BUILTIN L"builtin"
#define STR_OPTION_SCRIPTS L"functions"
#define STR_OPTION_TESTS L"tests"

//=============================================================================
ArrayOfVector
Nelson::ModulesManagerGateway::modulepathBuiltin(int nLhs, const ArrayOfVector& argIn)
{
    // st = modulepath('existing_module')
    // return a struct with different paths of an existing module (shortname)
    // p = modulepath('path', 'module short name', 'etc')
    // p = modulepath('path', 'module short name', 'bin')
    // p = modulepath('path', 'module short name', 'root')
    // p = modulepath('path', 'module short name', 'builtin')
    ArrayOfVector retval;
    if ((argIn.size() != 1) && (argIn.size() != 3)) {
        Error(ERROR_WRONG_NUMBERS_INPUT_ARGS);
    }
    nargoutcheck(nLhs, 0, 1);
    if (argIn.size() == 1) {
        std::wstring moduleshortname;
        if (argIn[0].isRowVectorCharacterArray()) {
            moduleshortname = argIn[0].getContentAsWideString();
        } else {
            Error(ERROR_WRONG_ARGUMENT_1_TYPE_STRING_EXPECTED);
        }
        if (IsExistingModuleName(moduleshortname)) {
            retval << ArrayOf::characterArrayConstructor(GetModulePath(moduleshortname));
        } else {
            Error(_W("invalid module name."));
        }
    } else // argIn.size() == 3
    {
        std::wstring modulerootpath;
        std::wstring moduleshortname;
        std::wstring option;
        if (argIn[0].isRowVectorCharacterArray()) {
            modulerootpath = argIn[0].getContentAsWideString();
        } else {
            Error(ERROR_WRONG_ARGUMENT_1_TYPE_STRING_EXPECTED);
        }
        if (argIn[1].isRowVectorCharacterArray()) {
            moduleshortname = argIn[1].getContentAsWideString();
        } else {
            Error(ERROR_WRONG_ARGUMENT_2_TYPE_STRING_EXPECTED);
        }
        if (argIn[2].isRowVectorCharacterArray()) {
            option = argIn[2].getContentAsWideString();
        } else {
            Error(ERROR_WRONG_ARGUMENT_3_TYPE_STRING_EXPECTED);
        }
        if (option == STR_OPTION_ETC) {
            retval << ArrayOf::characterArrayConstructor(
                ModulePath(modulerootpath, moduleshortname, GET_ETC_PATH));
        } else if (option == STR_OPTION_BIN) {
            retval << ArrayOf::characterArrayConstructor(
                ModulePath(modulerootpath, moduleshortname, GET_BINARY_PATH));
        } else if (option == STR_OPTION_ROOT) {
            retval << ArrayOf::characterArrayConstructor(
                ModulePath(modulerootpath, moduleshortname, GET_ROOT_PATH));
        } else if (option == STR_OPTION_BUILTIN) {
            retval << ArrayOf::characterArrayConstructor(
                ModulePath(modulerootpath, moduleshortname, GET_DYNLIB_FULLPATH));
        } else if (option == STR_OPTION_SCRIPTS) {
            retval << ArrayOf::characterArrayConstructor(
                ModulePath(modulerootpath, moduleshortname, GET_SCRIPT_PATH));
        } else {
            Error(_W("Argument #3 must be a valid option."));
        }
    }
    return retval;
}
//=============================================================================
