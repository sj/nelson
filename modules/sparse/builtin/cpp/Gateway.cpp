//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "IJVBuiltin.hpp"
#include "NelsonGateway.hpp"
#include "fullBuiltin.hpp"
#include "nnzBuiltin.hpp"
#include "nzmaxBuiltin.hpp"
#include "sparseBuiltin.hpp"
#include "sparsedouble_ctransposeBuiltin.hpp"
#include "sparsedouble_horzcat_sparsedoubleBuiltin.hpp"
#include "sparsedouble_imagBuiltin.hpp"
#include "sparsedouble_realBuiltin.hpp"
#include "sparsedouble_transposeBuiltin.hpp"
#include "sparsedouble_uminusBuiltin.hpp"
#include "sparsedouble_vertcat_sparsedoubleBuiltin.hpp"
#include "sparselogical_ctransposeBuiltin.hpp"
#include "sparselogical_horzcat_sparselogicalBuiltin.hpp"
#include "sparselogical_imagBuiltin.hpp"
#include "sparselogical_realBuiltin.hpp"
#include "sparselogical_transposeBuiltin.hpp"
#include "sparselogical_uminusBuiltin.hpp"
#include "sparselogical_vertcat_sparselogicalBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"sparse";
//=============================================================================
static const nlsGateway gateway[] = {
    { "sparse", (ptrBuiltin)Nelson::SparseGateway::sparseBuiltin, 1, 6,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "full", (ptrBuiltin)Nelson::SparseGateway::fullBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "sparsedouble_uminus", (ptrBuiltin)Nelson::SparseGateway::sparsedouble_uminusBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "sparselogical_uminus", (ptrBuiltin)Nelson::SparseGateway::sparselogical_uminusBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },

    { "sparselogical_real", (ptrBuiltin)Nelson::SparseGateway::sparselogical_realBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "sparselogical_imag", (ptrBuiltin)Nelson::SparseGateway::sparselogical_imagBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "sparsedouble_real", (ptrBuiltin)Nelson::SparseGateway::sparsedouble_realBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "sparsedouble_imag", (ptrBuiltin)Nelson::SparseGateway::sparsedouble_imagBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "IJV", (ptrBuiltin)Nelson::SparseGateway::IJVBuiltin, -1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "sparselogical_vertcat_sparselogical",
        (ptrBuiltin)Nelson::SparseGateway::sparselogical_vertcat_sparselogicalBuiltin, 1, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "sparselogical_horzcat_sparselogical",
        (ptrBuiltin)Nelson::SparseGateway::sparselogical_horzcat_sparselogicalBuiltin, 1, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "sparsedouble_vertcat_sparsedouble",
        (ptrBuiltin)Nelson::SparseGateway::sparsedouble_vertcat_sparsedoubleBuiltin, 1, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "sparsedouble_horzcat_sparsedouble",
        (ptrBuiltin)Nelson::SparseGateway::sparsedouble_horzcat_sparsedoubleBuiltin, 1, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "sparselogical_ctranspose",
        (ptrBuiltin)Nelson::SparseGateway::sparselogical_ctransposeBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "sparsedouble_ctranspose", (ptrBuiltin)Nelson::SparseGateway::sparsedouble_ctransposeBuiltin,
        1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "nnz", (ptrBuiltin)Nelson::SparseGateway::nnzBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "nzmax", (ptrBuiltin)Nelson::SparseGateway::nzmaxBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "sparselogical_transpose", (ptrBuiltin)Nelson::SparseGateway::sparselogical_transposeBuiltin,
        1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "sparsedouble_transpose", (ptrBuiltin)Nelson::SparseGateway::sparsedouble_transposeBuiltin, 1,
        1, CPP_BUILTIN_WITH_EVALUATOR },
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
