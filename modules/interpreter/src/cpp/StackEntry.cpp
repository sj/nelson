//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "StackEntry.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
StackEntry::StackEntry(const std::string& cntxt, const std::string& det, int id)
{
    cname = cntxt;
    detail = det;
    tokid = id;
}
//=============================================================================
StackEntry::StackEntry() : cname("base"), detail("base") {}
//=============================================================================
StackEntry::~StackEntry() = default;
//=============================================================================
} // namespace Nelson
//=============================================================================
