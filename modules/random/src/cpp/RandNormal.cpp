//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "RandNormal.hpp"
#include "Error.hpp"
#include "RandomInterface.hpp"
//=============================================================================
namespace Nelson {
ArrayOf
RandNormal(Evaluator* eval, NelsonType cl)
{
    Dimensions dims(1, 1);
    return RandNormal(eval, dims, cl);
}
//=============================================================================
ArrayOf
RandNormal(Evaluator* eval, Dimensions& dims, NelsonType cl)
{
    dims.simplify();
    if (eval->RandomEngine == nullptr) {
        Error(_W("random engine not initialized."));
    }
    auto* randEngine = static_cast<RandomInterface*>(eval->RandomEngine);
    switch (cl) {
    case NLS_SINGLE: {
        indexType nbElements = dims.getElementCount();
        single* mat = static_cast<single*>(
            ArrayOf::allocateArrayOf(cl, nbElements, Nelson::stringVector(), false));
        randEngine->getValuesAsSingle(mat, nbElements, dims.getColumns(), RNG_DISTRIBUTION_NORMAL);
        return ArrayOf(cl, dims, mat, false);
    } break;
    case NLS_DOUBLE: {
        indexType nbElements = dims.getElementCount();
        double* mat = static_cast<double*>(
            ArrayOf::allocateArrayOf(cl, nbElements, Nelson::stringVector(), false));
        randEngine->getValuesAsDouble(mat, nbElements, dims.getColumns(), RNG_DISTRIBUTION_NORMAL);
        return ArrayOf(cl, dims, mat, false);
    } break;
    default:
        Error(ERROR_TYPE_NOT_SUPPORTED);
    }
    return ArrayOf();
}
//=============================================================================
} // namespace Nelson
//=============================================================================
