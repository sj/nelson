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
#include "Types.hpp"
#include "nlsTypes_exports.h"
//=============================================================================
namespace Nelson {
//=============================================================================
NLSTYPES_IMPEXP NelsonType
StringToClass(const std::wstring& classname);
//=============================================================================
NLSTYPES_IMPEXP NelsonType
StringToClass(const std::wstring& classname, bool& haveError);
//=============================================================================
NLSTYPES_IMPEXP NelsonType
StringToClass(const std::string& classname);
//=============================================================================
NLSTYPES_IMPEXP NelsonType
StringToClass(const std::string& classname, bool& haveError);
//=============================================================================
} // namespace Nelson
//=============================================================================
