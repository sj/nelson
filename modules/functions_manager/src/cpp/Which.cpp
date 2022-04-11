//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "Which.hpp"
#include "BuiltInFunctionDefManager.hpp"
#include "Error.hpp"
#include "GatewayInfo.hpp"
#include "ModulesManager.hpp"
#include "PathFuncManager.hpp"
#include "characters_encoding.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
wstringVector
WhichAll(const std::wstring& functionname)
{
    wstringVector result;
    PathFuncManager::getInstance()->find(functionname, result);
    BuiltInFunctionDefManager::getInstance()->find(wstring_to_utf8(functionname), result);
    return result;
}
//=============================================================================
std::wstring
Which(const std::wstring& functionname)
{
    std::wstring origin;
    if (!PathFuncManager::getInstance()->find(functionname, origin)) {
        BuiltInFunctionDefManager::getInstance()->find(wstring_to_utf8(functionname), origin);
    }
    return origin;
}
//=============================================================================
wstringVector
WhichModule(const std::wstring& functionname)
{
    wstringVector res;
    wstringVector paths = WhichAll(functionname);
    if (!paths.empty()) {
        for (const auto& path : paths) {
            std::wstring moduleName = ModulesManager::Instance().findModuleNameByPath(path);
            if (!moduleName.empty()) {
                res.push_back(moduleName);
            } else {
                stringVector functionsList;
                std::wstring errorMessage;
                bool bRes = GatewayInfo(path, moduleName, functionsList, errorMessage);
                if (bRes) {
                    res.push_back(moduleName);
                } else {
                    res.push_back(L"");
                }
            }
        }
    }
    return res;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
