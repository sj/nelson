//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "QObject_iswindowtypeBuiltin.hpp"
#include "ClassName.hpp"
#include "Error.hpp"
#include "QmlHandleObject.hpp"
#include "iswindowtypeQObject.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector
Nelson::QmlEngineGateway::QObject_iswindowtypeBuiltin(int nLhs, const ArrayOfVector& argIn)
{
    nargincheck(argIn, 1, 1);
    nargoutcheck(nLhs, 0, 1);
    ArrayOfVector retval;
    ArrayOf param1 = argIn[0];
    if (param1.isHandle()) {
        std::wstring className;
        ClassName(param1, className);
        if (className != QOBJECT_CATEGORY_STR) {
            Error(_W("QObject handle expected."));
        }
        retval.push_back(iswindowtypeQObject(param1));
    } else {
        Error(ERROR_WRONG_ARGUMENT_1_TYPE_HANDLE_EXPECTED);
    }
    return retval;
}
//=============================================================================
