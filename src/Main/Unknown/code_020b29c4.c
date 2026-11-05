#include "Main/Unknown/code_020b29c4.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_02055000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020b252c.h"
#include "Main/Unknown/code_020b2a4c.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma thumb on
#pragma optimize_for_size on
u32 func_020b29c4(void) {
    u32 a = 0;
    u32 b = 0;
    u32 c = 0;
    u32 d;

    if (IsRaceStartSequenceDone() != 0 && GetRaceStartSequenceFrames() > 0xf0 && func_020b2a4c() == 0 &&
        (func_020b252c() != 2 || IsWinnerDecided() == FALSE)) {
        d = 1;
        if (func_020b252c() == MODE_MISSION_RUN) {
            if ((func_020b252c() == MODE_MISSION_RUN ? IsWinnerDecided() : 0) != FALSE) {
                d = 0;
            }
        }
        if (d != 0) {
            c = 1;
        }
    }
    if (c != 0) {
        if (func_020b252c() != 5) {
            b = 1;
        }
    }
    if (b != 0) {
        if (func_020b2ec0() != 0 || func_02055b1c() == FALSE) {
            a = 1;
        }
    }
    return a;
}
#pragma thumb off
