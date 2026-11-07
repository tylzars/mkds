#pragma once

#include "types.h"
#include "Main/Unknown/unk_02175000.h" // SceneCallbacks

// The three scene numbers of gSceneNumbers: +0 the previous scene (declared u8[2];
// read by the scenes' init functions as `*a` / `a[0]` and by UpdateEmblemScene), mScene the scene
// being run, mNextScene the scene to run next (-1 = none yet). No typed global holds this
// object, and other typedefs view the same object: Unk0203a0dc, Unk0204a598, Unk02111324,
// Unk0218052c; several scene functions take it as s16 * or void *.
typedef struct SceneNumbers {
    /* 00 */ u8 mUnk_00[0x2];
    // Number of the scene being run: the index of gSceneFuncs and of the scene-name table
    // gSceneNames (data_usa_021541a8).
    /* 02 */ s16 mScene;
    // Scene to run next, -1 until set. Written by the update slots (also through the other typedef
    // views and as a[2]) and by RunScene when the scene ends (code_020487fc.c:242, :264, :359,
    // :367, :370); read by RunScene (:276) and RunScenes.
    /* 04 */ s16 mNextScene;
} SceneNumbers;

// Runs one scene to its end: loads the scene's archives from a->mScene (LoadArchiveSlotsForScene), generic
// set-up, mInit once, a wait loop without slots, the update loop (mUpdate, then slot 0x0c, every
// frame) until a slot sets a->mNextScene or func_020435c4 is non-zero, the fade-out loop, a wait
// loop, mRelease once, generic tear-down.
void RunScene(SceneNumbers *param_1, const SceneCallbacks *param_2);
