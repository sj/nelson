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
#include "nlsJson_exports.h"
//=============================================================================
namespace Nelson {
NLSJSON_IMPEXP ArrayOf
jsonDecode(const std::wstring& stringToDecode, std::wstring& errorMessage);
};
//=============================================================================
