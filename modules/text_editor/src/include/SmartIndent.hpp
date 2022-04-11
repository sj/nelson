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
#include <string>
#include "nlsText_editor_exports.h"
//=============================================================================
namespace Nelson {
NLSTEXT_EDITOR_IMPEXP void
smartIndent(const std::wstring& filename, int tabsize = 2, bool doBackup = false);
}
//=============================================================================
