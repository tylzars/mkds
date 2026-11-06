#pragma once

#include "types.h"

// Screen numbers: the first argument of func_020ccc74 (stored as the current screen number, member 0xc of the object
// behind data_0217b43c) and the number func_020cccb4 returns for the previous screen. Only the screens that have a
// single number and a named Init class are defined; the other numbers stay literals.
// InitSelectEngine / ReleaseSelectEngine (started and released by func_020cb6c0 and func_020cb618).
#define SCREEN_SELECT_ENGINE 4
// InitSelectBattleStage / ReleaseSelectBattleStage.
#define SCREEN_SELECT_BATTLE_STAGE 0x11
// InitMissionRunLVsel / ReleaseMissionRunLVsel.
#define SCREEN_MISSION_RUN_LVSEL 0x12
// InitMissionRunMSsel / ReleaseMissionRunMSsel.
#define SCREEN_MISSION_RUN_MSSEL 0x13
// InitTimeAttackTopMenu / ReleaseTimeAttackTopMenu.
#define SCREEN_TIME_ATTACK_TOP_MENU 0x14
// InitSelectGhost (released by ReleaseSelectGhost).
#define SCREEN_SELECT_GHOST 0x1a

void func_020ccc74(s32 a, s32 b);
