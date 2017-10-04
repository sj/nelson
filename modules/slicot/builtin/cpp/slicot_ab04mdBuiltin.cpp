//=============================================================================
// LICENCE_BLOCK_BEGIN
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// LICENCE_BLOCK_END
//=============================================================================
// Generated by Nelson Interface Generator 1.0.0
//=============================================================================
#include "Error.hpp"
#include "slicot_ab04mdBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
#ifdef __cplusplus
extern "C"
{
#endif
extern int ab04md_ ( const char *TYPE, int *N, int *M, int *P, double *ALPHA, double *BETA, double *A, int *LDA, double *B, int *LDB, double *C, int *LDC, double *D, int *LDD, int *IWORK, double *DWORK, int *LDWORK, int *INFO);
#ifdef __cplusplus
}
#endif
//=============================================================================
// [A_OUT, B_OUT, C_OUT, D_OUT, INFO] = slicot_ab04md(TYPE, ALPHA, BETA, A_IN, B_IN, C_IN, D_IN)
//=============================================================================
ArrayOfVector Nelson::SlicotGateway::slicot_ab04mdBuiltin(Evaluator* eval, int nLhs, const ArrayOfVector& argIn)
{
    ArrayOfVector retval;
    if (nLhs > 5)
    {
        Error(eval, ERROR_WRONG_NUMBERS_OUTPUT_ARGS);
    }
    if (argIn.size() != 7)
    {
        Error(eval, ERROR_WRONG_NUMBERS_INPUT_ARGS);
    }
    // INPUT VARIABLES
    ArrayOf TYPE = argIn[0];
    std::string TYPE_string = TYPE.getContentAsCString();
    const char* TYPE_ptr = TYPE_string.c_str();
    ArrayOf ALPHA = argIn[1];
    ALPHA.promoteType(NLS_DOUBLE);
    double *ALPHA_ptr = (double*)ALPHA.getDataPointer();
    ArrayOf BETA = argIn[2];
    BETA.promoteType(NLS_DOUBLE);
    double *BETA_ptr = (double*)BETA.getDataPointer();
    // IN/OUT VARIABLES
    ArrayOf A = argIn[3];
    A.promoteType(NLS_DOUBLE);
    ArrayOf A_output = A;
    A_output.ensureSingleOwner();
    double *A_output_ptr = (double*)A_output.getDataPointer();
    ArrayOf B = argIn[4];
    B.promoteType(NLS_DOUBLE);
    ArrayOf B_output = B;
    B_output.ensureSingleOwner();
    double *B_output_ptr = (double*)B_output.getDataPointer();
    ArrayOf C = argIn[5];
    C.promoteType(NLS_DOUBLE);
    ArrayOf C_output = C;
    C_output.ensureSingleOwner();
    double *C_output_ptr = (double*)C_output.getDataPointer();
    ArrayOf D = argIn[6];
    D.promoteType(NLS_DOUBLE);
    ArrayOf D_output = D;
    D_output.ensureSingleOwner();
    double *D_output_ptr = (double*)D_output.getDataPointer();
    // OUTPUT VARIABLES
    ArrayOf INFO_output = ArrayOf::int32VectorConstructor(1);
    int *INFO_output_ptr = (int*)INFO_output.getDataPointer();
    // LOCAL VARIABLES
    ArrayOf N_local = ArrayOf::int32VectorConstructor(1);
    int* N_local_ptr = (int*)N_local.getDataPointer();
    N_local_ptr[0] = (int)A.getDimensions().getRows();
    ArrayOf M_local = ArrayOf::int32VectorConstructor(1);
    int* M_local_ptr = (int*)M_local.getDataPointer();
    M_local_ptr[0] = (int)B.getDimensions().getColumns();
    ArrayOf P_local = ArrayOf::int32VectorConstructor(1);
    int* P_local_ptr = (int*)P_local.getDataPointer();
    P_local_ptr[0] = (int)C.getDimensions().getRows();
    ArrayOf LDA_local = ArrayOf::int32VectorConstructor(1);
    int* LDA_local_ptr = (int*)LDA_local.getDataPointer();
    LDA_local_ptr[0] = std::max(1, (int)A.getDimensions().getRows());
    ArrayOf LDB_local = ArrayOf::int32VectorConstructor(1);
    int* LDB_local_ptr = (int*)LDB_local.getDataPointer();
    LDB_local_ptr[0] = std::max(1, (int)A.getDimensions().getRows());
    ArrayOf LDC_local = ArrayOf::int32VectorConstructor(1);
    int* LDC_local_ptr = (int*)LDC_local.getDataPointer();
    LDC_local_ptr[0] = std::max(1, (int)C.getDimensions().getRows());
    ArrayOf LDD_local = ArrayOf::int32VectorConstructor(1);
    int* LDD_local_ptr = (int*)LDD_local.getDataPointer();
    LDD_local_ptr[0] = std::max(1, (int)C.getDimensions().getRows());
    ArrayOf IWORK_local = ArrayOf::int32Matrix2dConstructor(1 , (int)A.getDimensions().getRows());
    int* IWORK_local_ptr = (int*)IWORK_local.getDataPointer();
    ArrayOf DWORK_local = ArrayOf::doubleMatrix2dConstructor(1 , std::max(1, (int)A.getDimensions().getRows()));
    double * DWORK_local_ptr = (double*)DWORK_local.getDataPointer();
    ArrayOf LDWORK_local = ArrayOf::int32VectorConstructor(1);
    int* LDWORK_local_ptr = (int*)LDWORK_local.getDataPointer();
    LDWORK_local_ptr[0] = std::max(1, (int)A.getDimensions().getRows());
    // CALL EXTERN FUNCTION
    try
    {
        ab04md_ ( TYPE_ptr, N_local_ptr, M_local_ptr, P_local_ptr, ALPHA_ptr, BETA_ptr, A_output_ptr, LDA_local_ptr, B_output_ptr, LDB_local_ptr, C_output_ptr, LDC_local_ptr, D_output_ptr, LDD_local_ptr, IWORK_local_ptr, DWORK_local_ptr, LDWORK_local_ptr, INFO_output_ptr);
    }
    catch (std::runtime_error &e)
    {
        Error(eval, "ab04md function fails.");
    }
    // ASSIGN OUTPUT VARIABLES
    if (nLhs > 0)
    {
        retval.push_back(A_output);
    }
    if (nLhs > 1)
    {
        retval.push_back(B_output);
    }
    if (nLhs > 2)
    {
        retval.push_back(C_output);
    }
    if (nLhs > 3)
    {
        retval.push_back(D_output);
    }
    if (nLhs > 4)
    {
        retval.push_back(INFO_output);
    }
    return retval;
}
//=============================================================================
