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
#include "nlsCore_exports.h"
//=============================================================================
namespace Nelson {
NLSCORE_IMPEXP unsigned int
getMaxNumCompThreads();
NLSCORE_IMPEXP unsigned int
setMaxNumCompThreads(unsigned int _nbOfCores);
NLSCORE_IMPEXP unsigned int
setDefaultMaxNumCompThreads();
} // namespace Nelson
//=============================================================================
