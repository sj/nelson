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
#include "nlsMatio_exports.h"
#include "ArrayOf.hpp"
#include "Evaluator.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
NLSMATIO_IMPEXP ArrayOf
LoadMatioFile(
    Evaluator* eval, const std::wstring& filename, const wstringVector& names, bool asStruct);
//=============================================================================
} // namespace Nelson
//=============================================================================
