//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "macroargsBuiltin.hpp"
#include "Error.hpp"
#include "MacroArguments.hpp"
#include "ToCellString.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector
Nelson::FunctionsGateway::macroargsBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    nargoutcheck(nLhs, 0, 2);
    nargincheck(argIn, 1, 1);
    std::wstring wfunctionname;
    if (argIn[0].isRowVectorCharacterArray()) {
        wfunctionname = argIn[0].getContentAsWideString();
    } else {
        Error(ERROR_WRONG_ARGUMENT_1_TYPE_STRING_EXPECTED);
    }
    wstringVector Inputs;
    wstringVector Outputs;
    bool bOK = MacroArguments(eval, wfunctionname, Inputs, Outputs);
    if (bOK) {
        retval << ToCellStringAsColumn(Inputs);
        if (nLhs > 1) {
            retval << ToCellStringAsColumn(Outputs);
        }
    } else {
        Error(_W("function macro name not found."));
    }
    return retval;
}
//=============================================================================
