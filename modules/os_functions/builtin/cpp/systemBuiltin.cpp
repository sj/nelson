//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "systemBuiltin.hpp"
#include "Error.hpp"
#include "SystemCommand.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
ArrayOfVector
Nelson::OsFunctionsGateway::systemBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    nargincheck(argIn, 1, 2);
    nargoutcheck(nLhs, 0, 2);
    ArrayOfVector retval;
    bool bEcho = false;
    bool bParallel = false;
    if (argIn.size() > 1) {
        if (argIn[1].isRowVectorCharacterArray()) {
            std::wstring flag = argIn[1].getContentAsWideString();
            if (flag.compare(L"-echo") == 0) {
                bEcho = true;
                bParallel = false;
            } else if (flag.compare(L"-parallel") == 0) {
                bEcho = false;
                bParallel = true;
            } else {
                Error(_W("Unrecognized option. \"-echo\" or \"-parallel\" expected."));
            }
        } else {
            Error(ERROR_WRONG_ARGUMENT_2_TYPE_STRING_EXPECTED);
        }
    }
    if (bParallel) {
        wstringVector commands = argIn[0].getContentAsWideStringVector(false);
        Dimensions outDims = argIn[0].getDimensions();
        std::vector<int> ierrs;
        wstringVector results = ParallelSystemCommand(commands, ierrs, eval->haveEventsLoop());
        double* pdRes = (double*)ArrayOf::allocateArrayOf(NLS_DOUBLE, commands.size());
        ArrayOf ret = ArrayOf(NLS_DOUBLE, outDims, pdRes);
        for (size_t k = 0; k < commands.size(); ++k) {
            pdRes[k] = (double)ierrs[k];
        }
        retval << ret;
        if (nLhs > 1) {
            ArrayOf* pArray = (ArrayOf*)ArrayOf::allocateArrayOf(NLS_STRING_ARRAY, results.size());
            ArrayOf outRet = ArrayOf(NLS_STRING_ARRAY, outDims, pArray);
            for (size_t k = 0; k < results.size(); ++k) {
                pArray[k] = ArrayOf::characterArrayConstructor(results[k]);
            }
            retval << outRet;
        }
    } else {
        if (nLhs == 0) {
            bEcho = true;
        }
        std::wstring cmd;
        if (argIn[0].isRowVectorCharacterArray()) {
            cmd = argIn[0].getContentAsWideString();
        } else {
            Error(ERROR_WRONG_ARGUMENT_1_TYPE_STRING_EXPECTED);
        }
        int ierr = 0;
        ArrayOf ret
            = ArrayOf::characterArrayConstructor(SystemCommand(cmd, ierr, eval->haveEventsLoop()));
        if (bEcho) {
            Interface* io = eval->getInterface();
            std::wstring msg = ret.getContentAsWideString();
            io->outputMessage(msg);
        }
        retval << ArrayOf::doubleConstructor(static_cast<double>(ierr));
        if (nLhs > 1) {
            retval << ret;
        }
    }
    return retval;
}
//=============================================================================
