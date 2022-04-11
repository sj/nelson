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
 * vertcat ([;]).
 */
NLSOPERATORS_IMPEXP ArrayOf
VertCat(ArrayOf& A, ArrayOf& B, bool mustRaiseError, bool& bSuccess);
}
//=============================================================================
