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
#include "nlsOperators_exports.h"
//=============================================================================
namespace Nelson {
/**
 * Element-wise left divide.
 * DOTLEFTDIVIDE Element-wise Left-Division Operator
 */

NLSOPERATORS_IMPEXP ArrayOf
DotLeftDivide(const ArrayOf& A, const ArrayOf& B, bool& needToOverload);
//=============================================================================
} // namespace Nelson
//=============================================================================
