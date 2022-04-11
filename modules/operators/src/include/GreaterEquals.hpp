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
#include "nlsOperators_exports.h"
#include "ArrayOf.hpp"
//=============================================================================
namespace Nelson {
/**
 * Element-wise compare (ge) of two arrays: C = A >= B
 */
NLSOPERATORS_IMPEXP ArrayOf
GreaterEquals(const ArrayOf& A, const ArrayOf& B, bool& needToOverload);
}
//=============================================================================
