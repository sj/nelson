//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// Alternatively, you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this program. If not, see <http://www.gnu.org/licenses/>.
// LICENCE_BLOCK_END
//=============================================================================
#include <fmt/printf.h>
#include <fmt/format.h>
#include <fmt/xchar.h>
#include "Assert_IsEqual.hpp"
#include "Error.hpp"
#include "i18n.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
static std::wstring
formatMessage(const ArrayOf& computedArray, const ArrayOf& expectedArray)
{
    std::wstring message;
    bool doDefaultMessage = false;
    if ((computedArray.isCharacterArray()
            && (computedArray.isRowVector() || computedArray.isScalar() || computedArray.isEmpty()))
        && (expectedArray.isCharacterArray()
               && (expectedArray.isRowVector() || expectedArray.isScalar()
                      || expectedArray.isEmpty()))) {
        std::wstring computed = computedArray.getContentAsWideString();
        std::wstring expected = expectedArray.getContentAsWideString();
        message = fmt::sprintf(
            _W("Assertion failed: expected '%s' and computed '%s' values are different."), expected,
            computed);
    } else {
        if (computedArray.isScalar() && expectedArray.isScalar()) {
            if (computedArray.getDataClass() == expectedArray.getDataClass()) {
                switch (expectedArray.getDataClass()) {
                case NLS_LOGICAL: {
                    logical computed = computedArray.getContentAsLogicalScalar();
                    logical expected = expectedArray.getContentAsLogicalScalar();
                    message = fmt::sprintf(_W("Assertion failed: expected (%s) and computed (%s) "
                                              "values are different."),
                        expected ? L"true" : L"false", computed ? L"true" : L"false");
                } break;
                case NLS_STRING_ARRAY: {
                    std::wstring computed = computedArray.getContentAsWideString();
                    std::wstring expected = expectedArray.getContentAsWideString();
                    message
                        = fmt::sprintf(_W("Assertion failed: expected \"%s\" and computed \"%s\" "
                                          "values are different."),
                            expected, computed);

                } break;
                case NLS_DOUBLE: {
                    double computed = ArrayOf(computedArray).getContentAsDoubleScalar();
                    double expected = ArrayOf(expectedArray).getContentAsDoubleScalar();
                    message = fmt::sprintf(_W("Assertion failed: expected (%lg) and computed (%lg) "
                                              "values are different."),
                        expected, computed);
                } break;
                case NLS_INT32: {
                    int32 computed = ArrayOf(computedArray).getContentAsInteger32Scalar();
                    int32 expected = ArrayOf(expectedArray).getContentAsInteger32Scalar();
                    message = fmt::sprintf(_W("Assertion failed: expected (%ls) and computed (%ls) "
                                              " values are different."),
                        fmt::to_wstring(expected), fmt::to_wstring(computed));
                } break;
                case NLS_UINT64: {
                    uint64 computed = ArrayOf(computedArray).getContentAsUnsignedInteger64Scalar();
                    uint64 expected = ArrayOf(expectedArray).getContentAsUnsignedInteger64Scalar();
                    message = fmt::sprintf(_W("Assertion failed: expected (%s) and computed (%s)  "
                                              "values are different."),
                        fmt::to_wstring(expected), fmt::to_wstring(computed));
                } break;
                default: {
                    doDefaultMessage = true;
                } break;
                }
            } else {
                doDefaultMessage = true;
            }
        } else {
            doDefaultMessage = true;
        }
    }

    if (doDefaultMessage) {
        message = _W("Assertion failed: expected and computed values are different.");
    }
    return message;
}
//=============================================================================
bool
Assert_IsEqual(
    Evaluator* eval, const ArrayOf& computedArray, const ArrayOf& expectedArray, std::wstring& msg)
{
    bool bRes = false;
    Context* context = eval->getContext();
    FunctionDef* funcDef = nullptr;
    std::string IsEqualToName = "isequalto";
    if (context->lookupFunction(IsEqualToName, funcDef)) {
        if ((funcDef->type() == NLS_BUILT_IN_FUNCTION) || (funcDef->type() == NLS_MACRO_FUNCTION)) {
            ArrayOfVector argInCopy(2);
            argInCopy << computedArray;
            argInCopy << expectedArray;
            try {
                ArrayOfVector resVect = funcDef->evaluateFunction(eval, argInCopy, 1);
                if (resVect.size() != 1) {
                    Error(_W("isequalto returns more than one output argument."));
                }
                ArrayOf r = resVect[0];
                if (r.isScalar() && r.isLogical()) {
                    bRes = r.getContentAsLogicalScalar() ? true : false;
                } else {
                    Error(_W("isequalto must return an logical."));
                }
            } catch (const Exception&) {
                Error(_W("isequalto returns an unexpected error."));
            }
        }
    } else {
        Error("isequalto function not found.");
    }
    if (!bRes) {
        msg = formatMessage(computedArray, expectedArray);
    } else {
        msg.clear();
    }
    return bRes;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
