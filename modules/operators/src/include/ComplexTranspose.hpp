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
 * Transposes the argument.
 */
NLSOPERATORS_IMPEXP ArrayOf
ComplexTranspose(const ArrayOf& A, bool& needToOverload);
} // namespace Nelson
//=============================================================================
