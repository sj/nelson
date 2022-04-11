//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "NelsonGateway.hpp"
#include "corrcoefBuiltin.hpp"
#include "varBuiltin.hpp"
#include "meanBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"statistics";
//=============================================================================
static const nlsGateway gateway[] = {
    { "corrcoef", (ptrBuiltin)Nelson::StatisticsGateway::corrcoefBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "var", (ptrBuiltin)Nelson::StatisticsGateway::varBuiltin, 1, 3, CPP_BUILTIN_WITH_EVALUATOR },
    { "mean", (ptrBuiltin)Nelson::StatisticsGateway::meanBuiltin, 1, 4,
        CPP_BUILTIN_WITH_EVALUATOR },
};
//=============================================================================
NLSGATEWAYFUNC(gateway)
//=============================================================================
NLSGATEWAYINFO(gateway)
//=============================================================================
NLSGATEWAYREMOVE(gateway)
//=============================================================================
NLSGATEWAYNAME()
//=============================================================================
