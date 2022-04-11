//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
// Generated by Nelson Interface Generator 1.0.0
//=============================================================================
#include <algorithm>
#include "slicot_mb04mdBuiltin.hpp"
#include "Error.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
#ifdef __cplusplus
extern "C"
{
#endif
    extern int
    mb04md_(int* N, double* MAXRED, double* A, int* LDA, double* SCALE, int* INFO);
#ifdef __cplusplus
}
#endif
//=============================================================================
// [MAXRED_OUT, A_OUT, SCALE, INFO] = slicot_mb04md(MAXRED_IN, A_IN)
//=============================================================================
ArrayOfVector
Nelson::SlicotGateway::slicot_mb04mdBuiltin(int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    nargoutcheck(nLhs, 0, 4);
    nargincheck(argIn, 2, 2);
    // INPUT VARIABLES
    // IN/OUT VARIABLES
    ArrayOf MAXRED = argIn[0];
    Dimensions dimsMAXRED = MAXRED.getDimensions();
    MAXRED.promoteType(NLS_DOUBLE);
    ArrayOf MAXRED_output = MAXRED;
    MAXRED_output.ensureSingleOwner();
    double* MAXRED_output_ptr = (double*)MAXRED_output.getDataPointer();
    ArrayOf A = argIn[1];
    Dimensions dimsA = A.getDimensions();
    A.promoteType(NLS_DOUBLE);
    ArrayOf A_output = A;
    A_output.ensureSingleOwner();
    double* A_output_ptr = (double*)A_output.getDataPointer();
    // LOCAL VARIABLES
    ArrayOf N = ArrayOf::int32VectorConstructor(1);
    int* N_ptr = (int*)N.getDataPointer();
    N_ptr[0] = (int)A.getColumns();
    ArrayOf LDA = ArrayOf::int32VectorConstructor(1);
    int* LDA_ptr = (int*)LDA.getDataPointer();
    LDA_ptr[0] = std::max(1, (int)A.getColumns());
    // OUTPUT VARIABLES
    ArrayOf SCALE_output
        = ArrayOf::doubleMatrix2dConstructor((indexType)1, (indexType)(int)A.getColumns());
    double* SCALE_output_ptr = (double*)SCALE_output.getDataPointer();
    ArrayOf INFO_output = ArrayOf::int32VectorConstructor(1);
    int* INFO_output_ptr = (int*)INFO_output.getDataPointer();
    // CHECK INPUT VARIABLES DIMENSIONS
    if (!dimsMAXRED.isScalar()) {
        Error(_W("Input argument #1: scalar expected."));
    }
    Dimensions dimsA_expected((int)A.getRows(), (int)A.getColumns());
    if (!dimsA.equals(dimsA_expected)) {
        Error(_("Input argument #2: wrong size.") + " " + dimsA_expected.toString() + " "
            + "expected" + ".");
    }
    // CALL EXTERN FUNCTION
    try {
        mb04md_(N_ptr, MAXRED_output_ptr, A_output_ptr, LDA_ptr, SCALE_output_ptr, INFO_output_ptr);
    } catch (const std::runtime_error&) {
        Error("mb04md function fails.");
    }
    // ASSIGN OUTPUT VARIABLES
    if (nLhs > 0) {
        retval << MAXRED_output;
    }
    if (nLhs > 1) {
        retval << A_output;
    }
    if (nLhs > 2) {
        retval << SCALE_output;
    }
    if (nLhs > 3) {
        retval << INFO_output;
    }
    return retval;
}
//=============================================================================
