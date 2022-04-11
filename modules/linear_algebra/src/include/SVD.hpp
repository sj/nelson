//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#pragma once
//=============================================================================
#include "ArrayOf.hpp"
#include "nlsLinear_algebra_exports.h"
//=============================================================================
namespace Nelson {
//=============================================================================
enum SVD_FLAG
{
    SVD_DEFAULT,
    SVD_ECON,
    SVD_0
};
//=============================================================================
NLSLINEAR_ALGEBRA_IMPEXP void
SVD(const ArrayOf& A, ArrayOf& s);
NLSLINEAR_ALGEBRA_IMPEXP void
SVD(const ArrayOf& A, SVD_FLAG flag, ArrayOf& U, ArrayOf& S);
NLSLINEAR_ALGEBRA_IMPEXP void
SVD(const ArrayOf& A, SVD_FLAG flag, ArrayOf& U, ArrayOf& S, ArrayOf& V);
} // namespace Nelson
//=============================================================================
