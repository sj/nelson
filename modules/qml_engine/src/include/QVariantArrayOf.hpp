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
#include "nlsQml_engine_exports.h"
#include <QtCore/QVariant>
#include <QtCore/QMetaType>
//=============================================================================
namespace Nelson {
//=============================================================================
NLSQML_ENGINE_IMPEXP ArrayOf
QVariantToArrayOf(QVariant Q);
NLSQML_ENGINE_IMPEXP bool
canBeConvertedToArrayOf(QVariant Q);
NLSQML_ENGINE_IMPEXP QVariant
ArrayOfToQVariant(ArrayOf A, int id);
NLSQML_ENGINE_IMPEXP QVariant
ArrayOfToQVariant(ArrayOf A);
//=============================================================================
} // namespace Nelson
//=============================================================================
