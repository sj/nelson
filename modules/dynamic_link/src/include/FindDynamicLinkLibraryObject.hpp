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
#include "DynamicLinkLibraryObject.hpp"
#include "nlsDynamic_link_exports.h"
//=============================================================================
namespace Nelson {
//=============================================================================
NLSDYNAMIC_LINK_IMPEXP ArrayOfVector
findDynamicLinkLibraryObject(const std::wstring& libraryName, int nLhs);
//=============================================================================
} // namespace Nelson
//=============================================================================
