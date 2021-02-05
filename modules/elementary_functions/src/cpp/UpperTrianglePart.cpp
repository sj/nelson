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
#include <string>
#include "nlsConfig.h"
#include "UpperTrianglePart.hpp"
#include "Error.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
template <class T>
ArrayOf
UpperTrianglePartComplex(const ArrayOf& A, signedIndexType offset)
{
    Class classA = A.getDataClass();
    Dimensions dimsA = A.getDimensions();
    indexType nbElements = dimsA.getElementCount();
    T* D = (T*)ArrayOf::allocateArrayOf(classA, nbElements, stringVector(), true);
    auto* Dz = reinterpret_cast<std::complex<T>*>(D);
    T* S = (T*)A.getDataPointer();
    auto* Sz = reinterpret_cast<std::complex<T>*>(S);
    indexType C = dimsA.getColumns();
    indexType R = dimsA.getRows();
#if defined(_NLS_WITH_OPENMP)
#pragma omp parallel for
#endif
    for (ompIndexType i = 0; i < (ompIndexType)C; i++) {
        auto v = (signedIndexType)(i + 1 - offset);
        indexType iSize = std::min(std::max(v, (signedIndexType)0), (signedIndexType)R);
        memcpy(&Dz[i * R], &Sz[i * R], iSize * sizeof(std::complex<T>));
    }
    return ArrayOf(classA, dimsA, D);
}
//=============================================================================

template <class T>
ArrayOf
UpperTrianglePartReal(const ArrayOf& A, signedIndexType offset)
{
    Class classA = A.getDataClass();
    Dimensions dimsA = A.getDimensions();
    indexType nbElements = dimsA.getElementCount();
    T* D = (T*)ArrayOf::allocateArrayOf(classA, nbElements, stringVector(), true);
    T* S = (T*)A.getDataPointer();
    indexType C = dimsA.getColumns();
    indexType R = dimsA.getRows();
#if defined(_NLS_WITH_OPENMP)
#pragma omp parallel for
#endif
    for (ompIndexType i = 0; i < (ompIndexType)C; i++) {
        auto v = (signedIndexType)(i + 1 - offset);
        indexType iSize = std::min(std::max(v, (signedIndexType)0), (signedIndexType)R);
        memcpy(&D[i * R], &S[i * R], iSize * sizeof(T));
    }
    return ArrayOf(classA, dimsA, D);
}
//=============================================================================
ArrayOf
UpperTrianglePart(const ArrayOf& A, signedIndexType offset, bool& needToOverload)
{
    ArrayOf res;
    needToOverload = false;
    if (!(A.is2D() || A.isVector() || A.isEmpty())) {
        Error(_W("Vector or matrix 2D expected."));
    }
    Dimensions dimsA = A.getDimensions();
    switch (A.getDataClass()) {
    case NLS_LOGICAL: {
        if (A.isSparse()) {
            needToOverload = true;
            return ArrayOf();
        }
        res = UpperTrianglePartReal<logical>(A, offset);

    } break;
    case NLS_CHAR: {
        res = UpperTrianglePartReal<charType>(A, offset);
    } break;
    case NLS_UINT8: {
        res = UpperTrianglePartReal<uint8>(A, offset);
    } break;
    case NLS_UINT16: {
        res = UpperTrianglePartReal<uint16>(A, offset);
    } break;
    case NLS_UINT32: {
        res = UpperTrianglePartReal<uint32>(A, offset);
    } break;
    case NLS_UINT64: {
        res = UpperTrianglePartReal<uint64>(A, offset);
    } break;
    case NLS_INT8: {
        res = UpperTrianglePartReal<int8>(A, offset);
    } break;
    case NLS_INT16: {
        res = UpperTrianglePartReal<int16>(A, offset);
    } break;
    case NLS_INT32: {
        res = UpperTrianglePartReal<int32>(A, offset);
    } break;
    case NLS_INT64: {
        res = UpperTrianglePartReal<int64>(A, offset);
    } break;
    case NLS_SINGLE: {
        res = UpperTrianglePartReal<single>(A, offset);
    } break;
    case NLS_DOUBLE: {
        if (A.isSparse()) {
            needToOverload = true;
            return ArrayOf();
        }
        res = UpperTrianglePartReal<double>(A, offset);

    } break;
    case NLS_SCOMPLEX: {
        res = UpperTrianglePartComplex<single>(A, offset);
    } break;
    case NLS_DCOMPLEX: {
        if (A.isSparse()) {
            needToOverload = true;
            return ArrayOf();
        }
        res = UpperTrianglePartComplex<double>(A, offset);

    } break;
    default: {
        needToOverload = true;
        return ArrayOf();
    } break;
    }
    return res;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
