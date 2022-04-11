//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#define _SCL_SECURE_NO_WARNINGS
//=============================================================================
#include "SparseRealPart.hpp"
#include "ClassName.hpp"
#include "Error.hpp"
#include "SparseType.hpp"
#include <Eigen/Sparse>
//=============================================================================
namespace Nelson {
//=============================================================================
ArrayOf
SparseRealPart(ArrayOf a)
{
    ArrayOf res;
    if (!a.isSparse()) {
        Error(_W("Sparse expected."));
    }
    switch (a.getDataClass()) {
    case NLS_LOGICAL: {
        try {
            indexType rows = a.getDimensionLength(0);
            indexType cols = a.getDimensionLength(1);
            Eigen::SparseMatrix<double, 0, signedIndexType>* spmatDST
                = new Eigen::SparseMatrix<double, 0, signedIndexType>(rows, cols);
            Eigen::SparseMatrix<logical, 0, signedIndexType>* spmatSRC
                = (Eigen::SparseMatrix<logical, 0, signedIndexType>*)a.getSparseDataPointer();
            for (indexType k = 0; k < (indexType)spmatSRC->outerSize(); ++k) {
                for (Eigen::SparseMatrix<logical, 0, signedIndexType>::InnerIterator it(
                         *spmatSRC, k);
                     it; ++it) {
                    if (it.value() != 0) {
                        spmatDST->coeffRef(it.row(), it.col()) = it.value() == 1;
                    }
                }
            }
            spmatDST->finalize();
            spmatDST->makeCompressed();
            void* pRes = (void*)spmatDST;
            res = ArrayOf(NLS_DOUBLE, a.getDimensions(), pRes, true);
        } catch (const std::bad_alloc&) {
            Error(ERROR_MEMORY_ALLOCATION);
        }
    } break;
    case NLS_DOUBLE: {
        return ArrayOf(a);
    } break;
    case NLS_DCOMPLEX: {
        try {
            indexType rows = a.getDimensionLength(0);
            indexType cols = a.getDimensionLength(1);
            Eigen::SparseMatrix<double, 0, signedIndexType>* spmatDST
                = new Eigen::SparseMatrix<double, 0, signedIndexType>(rows, cols);
            Eigen::SparseMatrix<doublecomplex, 0, signedIndexType>* spmatSRC
                = (Eigen::SparseMatrix<doublecomplex, 0, signedIndexType>*)a.getSparseDataPointer();
            for (indexType k = 0; k < (indexType)spmatSRC->outerSize(); ++k) {
                for (Eigen::SparseMatrix<doublecomplex, 0, signedIndexType>::InnerIterator it(
                         *spmatSRC, k);
                     it; ++it) {
                    if (it.value().real() != 0.) {
                        spmatDST->coeffRef(it.row(), it.col()) = it.value().real();
                    }
                }
            }
            spmatDST->finalize();
            spmatDST->makeCompressed();
            void* pRes = (void*)spmatDST;
            res = ArrayOf(NLS_DOUBLE, a.getDimensions(), pRes, true);
        } catch (const std::bad_alloc&) {
            Error(ERROR_MEMORY_ALLOCATION);
        }
    } break;
    default: {
        Error(_("Cannot do real with current type '") + ClassName(a) + "'.");
    } break;
    }
    return res;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
