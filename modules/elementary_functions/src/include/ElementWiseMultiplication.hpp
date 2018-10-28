//=============================================================================
// Copyright (c) 2016-2018 Allan CORNET (Nelson)
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
#pragma once
//=============================================================================
#include "ArrayOf.hpp"
#include "nlsElementary_functions_exports.h"
//=============================================================================
namespace Nelson {
//=============================================================================
NLSELEMENTARY_FUNCTIONS_IMPEXP ArrayOf
elementWiseMultiplication(ArrayOf& A, ArrayOf& B, bool& needToOverload);
//=============================================================================
template <class T> T scalarInteger_times_scalarInteger(T a, T b) {
    T c;
    if ((b > 0 && a > std::numeric_limits<T>::max() / b)
        || (b < 0 && a < std::numeric_limits<T>::min() / b))
        {
        if (a < 0 && b < 0) {
            c = std::numeric_limits<T>::max();
        } else if (a > 0 && b < 0) {
            c = std::numeric_limits<T>::min();
        } else if (a < 0 && b > 0) {
            c = std::numeric_limits<T>::min();
        } else if (a > 0 && b > 0) {
            c = std::numeric_limits<T>::max();
        }
    } else {
		c = a * b;
    }
    return c;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
