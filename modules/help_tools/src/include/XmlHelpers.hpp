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
#include <libxml/xmlreader.h>
#include <string>
//=============================================================================
namespace Nelson {
std::wstring
getXmlFileEncoding(const std::wstring& filename);
xmlDoc*
readDocument(const std::string& xmlCode, bool validate, std::wstring& error);
} // namespace Nelson
//=============================================================================
