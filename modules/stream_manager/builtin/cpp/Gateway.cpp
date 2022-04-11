//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "FilesManager.hpp"
#include "Interface.hpp"
#include "NelsonGateway.hpp"
#include "diaryBuiltin.hpp"
#include "dlmwriteBuiltin.hpp"
#include "fcloseBuiltin.hpp"
#include "fgetlBuiltin.hpp"
#include "fgetsBuiltin.hpp"
#include "filereadBuiltin.hpp"
#include "filewriteBuiltin.hpp"
#include "fopenBuiltin.hpp"
#include "fprintfBuiltin.hpp"
#include "freadBuiltin.hpp"
#include "frewindBuiltin.hpp"
#include "fseekBuiltin.hpp"
#include "fsizeBuiltin.hpp"
#include "ftellBuiltin.hpp"
#include "fwriteBuiltin.hpp"
#include "loadBuiltin.hpp"
#include "saveBuiltin.hpp"
#include "feofBuiltin.hpp"
#include "ferrorBuiltin.hpp"
#include "fscanfBuiltin.hpp"
#include "sscanfBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"stream_manager";
//=============================================================================
static const nlsGateway gateway[] = {
    { "diary", (ptrBuiltin)Nelson::StreamGateway::diaryBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "fopen", (ptrBuiltin)Nelson::StreamGateway::fopenBuiltin, 4, 4, CPP_BUILTIN_WITH_EVALUATOR },
    { "fclose", (ptrBuiltin)Nelson::StreamGateway::fcloseBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "fwrite", (ptrBuiltin)Nelson::StreamGateway::fwriteBuiltin, 1, 3,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "fread", (ptrBuiltin)Nelson::StreamGateway::freadBuiltin, 1, 3, CPP_BUILTIN_WITH_EVALUATOR },
    { "fprintf", (ptrBuiltin)Nelson::StreamGateway::fprintfBuiltin, 1, 3,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "fgetl", (ptrBuiltin)Nelson::StreamGateway::fgetlBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "fgets", (ptrBuiltin)Nelson::StreamGateway::fgetsBuiltin, 1, 2, CPP_BUILTIN_WITH_EVALUATOR },
    { "ftell", (ptrBuiltin)Nelson::StreamGateway::ftellBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "frewind", (ptrBuiltin)Nelson::StreamGateway::frewindBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "fseek", (ptrBuiltin)Nelson::StreamGateway::fseekBuiltin, 1, 3, CPP_BUILTIN_WITH_EVALUATOR },
    { "fsize", (ptrBuiltin)Nelson::StreamGateway::fsizeBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "dlmwrite", (ptrBuiltin)Nelson::StreamGateway::dlmwriteBuiltin, 0, -3,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "fileread", (ptrBuiltin)Nelson::StreamGateway::filereadBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "filewrite", (ptrBuiltin)Nelson::StreamGateway::filewriteBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "load", (ptrBuiltin)Nelson::StreamGateway::loadBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "save", (ptrBuiltin)Nelson::StreamGateway::saveBuiltin, 0, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "feof", (ptrBuiltin)Nelson::StreamGateway::feofBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "ferror", (ptrBuiltin)Nelson::StreamGateway::ferrorBuiltin, 2, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "fscanf", (ptrBuiltin)Nelson::StreamGateway::fscanfBuiltin, 2, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "sscanf", (ptrBuiltin)Nelson::StreamGateway::sscanfBuiltin, 3, 4, CPP_BUILTIN },
};
//=============================================================================
static bool
initializeModule(Nelson::Evaluator* eval)
{
    if (eval->FileManager == nullptr) {
        Interface* io = eval->getInterface();
        Nelson::FilesManager* fm;
        try {
            fm = new Nelson::FilesManager(io);
        } catch (const std::bad_alloc&) {
            fm = nullptr;
        }
        if (fm) {
            eval->FileManager = (void*)fm;
            return true;
        }
    }
    return false;
}
//=============================================================================
static bool
finishModule(Nelson::Evaluator* eval)
{
    if (eval->FileManager != nullptr) {
        Nelson::FilesManager* fm = (Nelson::FilesManager*)eval->FileManager;
        delete fm;
        eval->FileManager = nullptr;
        return true;
    }
    return false;
}
//=============================================================================
NLSGATEWAYFUNCEXTENDED(gateway, (void*)initializeModule)
//=============================================================================
NLSGATEWAYINFO(gateway)
//=============================================================================
NLSGATEWAYREMOVEEXTENDED(gateway, (void*)finishModule)
//=============================================================================
NLSGATEWAYNAME()
//=============================================================================
