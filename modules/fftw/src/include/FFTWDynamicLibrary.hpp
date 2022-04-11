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
#include "nlsFftw_exports.h"
//=============================================================================
namespace Nelson {
//=============================================================================
NLSFFTW_IMPEXP bool
loadFFTWLibrary(void);
//=============================================================================
NLSFFTW_IMPEXP bool
loadFFTWLibrary(const std::wstring& fftwLibraryName, const std::wstring& fftwfLibraryName);
//=============================================================================
NLSFFTW_IMPEXP bool
freeFFTWLibrary();
//=============================================================================
}
//=============================================================================
