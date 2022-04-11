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
#include "Evaluator.hpp"
#include "nlsRandom_exports.h"
//=============================================================================
namespace Nelson {
NLSRANDOM_IMPEXP ArrayOf
RandNormal(Evaluator* eval, NelsonType cl);
NLSRANDOM_IMPEXP ArrayOf
RandNormal(Evaluator* eval, Dimensions& dims, NelsonType cl);
} // namespace Nelson
//=============================================================================
