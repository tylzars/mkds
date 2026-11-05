#pragma once

#include "types.h"

// Never returns: loops RunScenes, taking the group from data_0217aa20 +4. First scene 9 (6 when the
// word at 0x027ffc40 is 2). Body of the main thread (func_02039c98).
void RunScenesForever(void);
// Runs the scenes of one group (data_0217aa20 +0, 0 or 1) one after another until the group
// changes: sets the group up (func_0205e0b0), keeps gSceneNumbers (previous, current, next), runs
// gSceneFuncs[number] inside a new heap (func_020364f8), takes the next number or 9, tears the
// group down. Reloads overlay 3 for data_021759d0->mUnk_20 == 4.
s32 RunScenes(s16 *a);
void func_0205dee0(void);
