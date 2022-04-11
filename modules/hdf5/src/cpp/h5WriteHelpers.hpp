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
#define H5_BUILT_AS_DYNAMIC_LIB
#include <hdf5.h>
#include "ArrayOf.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
void*
h5WriteNelsonToHdf5(ArrayOf& data, hid_t& type_id, hid_t& dspace_id, std::wstring& error);
//=============================================================================
}
//=============================================================================
