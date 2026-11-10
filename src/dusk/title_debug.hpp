#pragma once

// TEMPORARY title-stage diagnostics. To remove: delete this file and every line containing
// TITLE_DEBUG_LOG (`grep -rn TITLE_DEBUG src`).
// Set to 0 to compile the logging out without removing it.
#define TITLE_DEBUG_ENABLED 0

#if TARGET_PC && TITLE_DEBUG_ENABLED

#include "d/d_com_inf_game.h"
#include "dusk/game_mode.hpp"
#include "dusk/logging.h"
#include "dusk/settings.h"

#include <string>

inline void titleDebugLog(const char* where) {
    const auto* gm = dusk::gamemode::getGameModeManager().getCurrentGameMode();
    DuskLog.info("[title-debug] {}: mode={} cfgStage={} next={} pt={} rm={} ly={} | start={} rm={} ly={}",
                 where, gm ? gm->getId() : std::string{"<null>"},
                 static_cast<int>(dusk::getSettings().game.titleScreenStage.getValue()),
                 dComIfGp_getNextStageName(), dComIfGp_getNextStagePoint(),
                 dComIfGp_getNextStageRoomNo(), dComIfGp_getNextStageLayer(),
                 dComIfGp_getStartStageName(), dComIfGp_getStartStageRoomNo(),
                 dComIfGp_getStartStageLayer());
}

#define TITLE_DEBUG_LOG(where) titleDebugLog(where)

#else

#define TITLE_DEBUG_LOG(where) ((void)0)

#endif
