//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "ConvertCharsToStrings.hpp"
#include "Error.hpp"
#include "convertCharsToStringsBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector
Nelson::StringGateway::convertCharsToStringsBuiltin(
    Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    if (nLhs > (int)argIn.size()) {
        Error(_W("Number of Input arguments must the same as output."));
    }
    return ConvertCharsToStrings(argIn);
}
//=============================================================================