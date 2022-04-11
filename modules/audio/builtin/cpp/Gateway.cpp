//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "AudioHelpers.hpp"
#include "NelsonGateway.hpp"
#include "audiodevinfoBuiltin.hpp"
#include "audioinfoBuiltin.hpp"
#include "audiometadataBuiltin.hpp"
#include "audioplayerBuiltin.hpp"
#include "audioplayer_deleteBuiltin.hpp"
#include "audioplayer_displayBuiltin.hpp"
#include "audioplayer_fieldnamesBuiltin.hpp"
#include "audioplayer_getBuiltin.hpp"
#include "audioplayer_ismethodBuiltin.hpp"
#include "audioplayer_ispropBuiltin.hpp"
#include "audioplayer_isvalidBuiltin.hpp"
#include "audioplayer_pauseBuiltin.hpp"
#include "audioplayer_playBuiltin.hpp"
#include "audioplayer_propertiesBuiltin.hpp"
#include "audioplayer_resumeBuiltin.hpp"
#include "audioplayer_setBuiltin.hpp"
#include "audioplayer_stopBuiltin.hpp"
#include "audioplayer_usedBuiltin.hpp"
#include "audioreadBuiltin.hpp"
#include "audiosupportedformatsBuiltin.hpp"
#include "audiowriteBuiltin.hpp"
#include "beepBuiltin.hpp"
#include "playBuiltin.hpp"
#include "playblockingBuiltin.hpp"
#include "resumeBuiltin.hpp"
#include "stopBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"audio";
//=============================================================================
static const nlsGateway gateway[] = {
    { "audiodevinfo", (ptrBuiltin)Nelson::AudioGateway::audiodevinfoBuiltin, 1, -1 },
    { "audioplayer", (ptrBuiltin)Nelson::AudioGateway::audioplayerBuiltin, 1, -1 },
    { "audioplayer_display", (ptrBuiltin)Nelson::AudioGateway::audioplayer_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "audioplayer_disp", (ptrBuiltin)Nelson::AudioGateway::audioplayer_displayBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "audioplayer_delete", (ptrBuiltin)Nelson::AudioGateway::audioplayer_deleteBuiltin, 0, 1 },
    { "audioplayer_isvalid", (ptrBuiltin)Nelson::AudioGateway::audioplayer_isvalidBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "audioplayer_fieldnames", (ptrBuiltin)Nelson::AudioGateway::audioplayer_fieldnamesBuiltin, 1,
        1 },
    { "audioplayer_properties", (ptrBuiltin)Nelson::AudioGateway::audioplayer_propertiesBuiltin, 1,
        1 },
    { "audioplayer_get", (ptrBuiltin)Nelson::AudioGateway::audioplayer_getBuiltin, 1, 2 },
    { "audioplayer_set", (ptrBuiltin)Nelson::AudioGateway::audioplayer_setBuiltin, 0, 3 },
    { "audioplayer_play", (ptrBuiltin)Nelson::AudioGateway::audioplayer_playBuiltin, 0, -1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "audioplayer_playblocking", (ptrBuiltin)Nelson::AudioGateway::audioplayer_playblockingBuiltin,
        0, -1, CPP_BUILTIN_WITH_EVALUATOR },
    { "audioplayer_pause", (ptrBuiltin)Nelson::AudioGateway::audioplayer_pauseBuiltin, 0, 1 },
    { "audioplayer_resume", (ptrBuiltin)Nelson::AudioGateway::audioplayer_resumeBuiltin, 0, 1 },
    { "audioplayer_stop", (ptrBuiltin)Nelson::AudioGateway::audioplayer_stopBuiltin, 0, 1 },
    { "audioplayer_used", (ptrBuiltin)Nelson::AudioGateway::audioplayer_usedBuiltin, 1, 0 },
    { "audioplayer_isprop", (ptrBuiltin)Nelson::AudioGateway::audioplayer_ispropBuiltin, 1, 2 },
    { "audioplayer_ismethod", (ptrBuiltin)Nelson::AudioGateway::audioplayer_ismethodBuiltin, 1, 2 },
    { "playblocking", (ptrBuiltin)Nelson::AudioGateway::playblockingBuiltin, 0, -1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "play", (ptrBuiltin)Nelson::AudioGateway::playBuiltin, 0, -1, CPP_BUILTIN_WITH_EVALUATOR },
    { "stop", (ptrBuiltin)Nelson::AudioGateway::stopBuiltin, 0, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "resume", (ptrBuiltin)Nelson::AudioGateway::resumeBuiltin, 0, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "beep", (ptrBuiltin)Nelson::AudioGateway::beepBuiltin, 1, 1 },
    { "audioread", (ptrBuiltin)Nelson::AudioGateway::audioreadBuiltin, 2, 3 },
    { "audioinfo", (ptrBuiltin)Nelson::AudioGateway::audioinfoBuiltin, 1, 1 },
    { "audiometadata", (ptrBuiltin)Nelson::AudioGateway::audiometadataBuiltin, 1, -1 },
    { "audiosupportedformats", (ptrBuiltin)Nelson::AudioGateway::audiosupportedformatsBuiltin, 1,
        0 },
    { "audiowrite", (ptrBuiltin)Nelson::AudioGateway::audiowriteBuiltin, 0, -3 },
};
//=============================================================================
static bool
initializeAudioModule(Nelson::Evaluator* eval)
{
    initializeAudio();
    return true;
}
//=============================================================================
static bool
finishAudioModule(Nelson::Evaluator* eval)
{
    terminateAudio();
    return true;
}
//=============================================================================
NLSGATEWAYFUNCEXTENDED(gateway, (void*)initializeAudioModule)
//=============================================================================
NLSGATEWAYINFO(gateway)
//=============================================================================
NLSGATEWAYREMOVEEXTENDED(gateway, (void*)finishAudioModule)
//=============================================================================
NLSGATEWAYNAME()
//=============================================================================
