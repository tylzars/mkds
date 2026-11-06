#pragma once

#include "types.h"
#include "Main/Unknown/code_02036c5c.h"
#include "code_020182c0.h" // Unk020182c0
#include "Main/Unknown/unk_02175628.h" // Unk02175628
#include "code_02017f24.h" // NNSiFndHeapHead
#include "code_0200db4c.h"
#include "Main/Unknown/code_020d22c0.h" // Unk020f41c4_B
#include "code_0214f4a4.h" // PMSleepCallbackInfo
#include "Main/Unknown/code_02105ec0.h" // Unk0217d060

// Object behind data_021759d0 (0x7c bytes); the 0x14 bytes at 0x2a are the source of a block move into
// data_0217aa08.
typedef struct Unk021759d0 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ Unk0217d060 mUnk_08;
    /* 1c */ union {
        s32 mUnk_1c;
        struct {
            s32 mUnk_1c_0 : 1;
            s32 mUnk_1c_1 : 1;
            s32 mUnk_1c_2 : 1;
            s32 mUnk_1c_3 : 1;
        };
    };
    /* 20 */ s32 mUnk_20;
    /* 24 */ NNSiFndHeapHead *mHeap;
    /* 28 */ s16 mUnk_28;
    /* 2a */ u8 mUnk_2a[0x14];
    /* 3e */ u16 mUnk_3e;
    /* 40 */ u8 mUnk_40;
    /* 41 */ u8 mUnk_41[0x3];
    /* 44 */ s32 mUnk_44;
    /* 48 */ u32 mUnk_48;
    /* 4c */ u32 mUnk_4c;
    /* 50 */ u16 mUnk_50;
    /* 52 */ u8 mUnk_52[0x2];
    /* 54 */ BOOL mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ Unk020f41c4_B mUnk_60;
    /* 78 */ s32 mUnk_78;
} Unk021759d0;

// The callbacks of one scene (0x20 bytes). RunScene copies it to mSceneCallbacks and calls mInit
// once, then mUpdate and the unnamed slot 0x0c every frame, then mRelease once. 0x0c is the second
// per-frame slot (it runs after mUpdate in the same pass and mostly copies the two 2D lists). 0x10
// and 0x14 are called from two library callbacks registered in func_02049c3c; 0x18 and 0x1a are
// fade lengths passed to func_02037288 / func_02036d3c; 0x1c is a flag for func_02037658; all stay
// unnamed. One instance per scene (the 16 entries of gSceneFuncs): seven tables are named, the
// others are unnamed tables or stack literals.
typedef struct SceneCallbacks {
    // Called once before the scene's frames with the scene numbers. Allocates the scene's objects
    // from the scene heap (the heap of RunScenes' frame, destroyed when the scene ends).
    /* 00 */ void (*mInit)();
    // One per-frame step, called every pass of the update loops and of the fade-out loop (then with
    // a == NULL), with the scene numbers and mSceneFrames. A second per-frame slot (0x0c) runs
    // after it. Scenes write their next scene into a->mNextScene here; the Menu scene does not
    // (RunScene ends it).
    /* 04 */ void (*mUpdate)();
    // Called once after the loops. Calls the scene's undo functions and clears the scene's globals;
    // it frees nothing by itself except in the WiFi scene (the heap of func_0202bb60): the scene
    // heap is destroyed by the caller. The Race slot also writes a save block in kind 6.
    /* 08 */ void (*mRelease)();
    /* 0c */ void (*mUnk_0c)();
    /* 10 */ void (*mUnk_10)(void);
    /* 14 */ void (*mUnk_14)(void);
    /* 18 */ s16 mUnk_18;
    /* 1a */ s16 mUnk_1a;
    /* 1c */ int mUnk_1c;
} SceneCallbacks;

// Object behind data_021759cc.
typedef struct Unk021759cc {
    /* 000 */ void *mUnk_000;
    /* 004 */ OSThread mUnk_004;
    /* 0bc */ u8 mUnk_0bc[8];
    /* 0c4 */ OSThreadQueue mUnk_0c4;
    /* 0cc */ PMSleepCallbackInfo mUnk_0cc;
    /* 0d8 */ PMSleepCallbackInfo mUnk_0d8;
    // Passes of RunScene's update loop and fade-out loop since they began (RunScene zeroes it at
    // :192 and :376); not counted while func_020487fc_inline6 is true (mode 5 with a flag, or the
    // data_0217aa00 flag tests). Only the Race slots use it (kind 6: the first 0x708 frames,
    // thresholds 0x5a ...).
    /* 0e4 */ s32 mSceneFrames;
    /* 0e8 */ s32 mUnk_0e8;
    // Copy of the running scene's SceneCallbacks, written once by RunScene; slots 0x10 / 0x14 and
    // the fade lengths are read from it (code_0204984c.c:125, :132, :431-438).
    /* 0ec */ SceneCallbacks mSceneCallbacks;
    /* 10c */ s32 mUnk_10c;
    /* 110 */ BOOL mUnk_110;
    /* 114 */ u8 mUnk_114[4];
    /* 118 */ s32 mUnk_118;
    /* 11c */ s32 mUnk_11c;
    /* 120 */ s8 mUnk_120;
} Unk021759cc;

// Part of Unk021755a0 at 0x28, 0x38, 0x70 and 0x80: seven halfwords.
typedef struct Unk021755a0_28 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u8 mUnk_0e[0x2];
} Unk021755a0_28;

// Object behind member 0x6c of Unk021755a0.
typedef struct Unk021755a0_6c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk021755a0_6c;

// Object behind data_021755a0.
typedef struct Unk021755a0 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u16 mUnk_16;
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    /* 1c */ u16 mUnk_1c;
    /* 1e */ u16 mUnk_1e;
    /* 20 */ u16 mUnk_20;
    /* 22 */ u16 mUnk_22;
    /* 24 */ u16 mUnk_24;
    /* 26 */ u16 mUnk_26;
    /* 28 */ Unk021755a0_28 mUnk_28;
    /* 38 */ Unk021755a0_28 mUnk_38;
    /* 48 */ Unk0203810c mUnk_48;
    /* 58 */ Unk0203810c mUnk_58;
    /* 68 */ u16 mUnk_68;
    /* 6a */ u16 mUnk_6a;
    /* 6c */ Unk021755a0_6c *mUnk_6c;
    /* 70 */ Unk021755a0_28 mUnk_70;
    /* 80 */ Unk021755a0_28 mUnk_80;
    /* 90 */ Unk0203810c mUnk_90;
    /* a0 */ Unk0203810c mUnk_a0;
    /* b0 */ u16 mUnk_b0;
    /* b2 */ u16 mUnk_b2;
    /* b4 */ u32 mUnk_b4;
    /* b8 */ void (*mUnk_b8)(void);
    /* bc */ u64 mUnk_bc;
    /* c4 */ u64 mUnk_c4;
    /* cc */ u32 mUnk_cc;
    /* d0 */ u32 mUnk_d0;
    /* d4 */ u32 mUnk_d4;
    /* d8 */ u8 mUnk_d8;
} Unk021755a0;

// Objects whose layout isn't known yet.
extern Unk021755a0 *data_021755a0;
extern Unk02175628 data_021755dc;
typedef struct Unk02175624 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ s32 mUnk_08;
    /* 0c */ BOOL mUnk_0c;
} Unk02175624;

extern Unk02175624 *data_02175624;
// 0x5c-byte entries; func_020708a4 writes the halfword at 0x00 of entry Kart.mEntryIndex.
typedef struct Unk0217566a {
    /* 00 */ u16 mBitMask;
    /* 02 */ u8 mUnk_02[0x5a];
} Unk0217566a;

extern Unk0217566a data_0217566a[];
// Entries of 0x0c bytes from 0x9b0 of Unk021759c8.
typedef struct Unk021759c8_9b0 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ union {
        s32 mUnk_08;
        struct {
            u32 mUnk_08_0 : 29;
            s32 mUnk_08_29 : 1;
            u32 mUnk_08_30 : 1;
            u32 mUnk_08_31 : 1;
        };
    };
} Unk021759c8_9b0;

// 0x70-byte entries from the start of Unk021759c8; mLoaded is nonzero while its archive is loaded.
typedef struct ArchiveSlot {
    /* 00 */ Unk020182c0 mArchive;
    /* 68 */ s32 mLoaded;
    /* 6c */ Unk02018344 *mData;
} ArchiveSlot;

// The 0xa0 bytes at 0x8c8 of Unk021759c8.
typedef struct Unk021759c8_8c8 {
    /* 00 */ u8 mUnk_00[0x80];
    /* 80 */ u32 *mUnk_80;
    /* 84 */ void *mUnk_84;
    /* 88 */ u32 *mUnk_88;
    /* 8c */ s32 mUnk_8c;
    /* 90 */ s32 mUnk_90;
    /* 94 */ s32 mUnk_94;
    /* 98 */ s32 mUnk_98;
    /* 9c */ s32 mUnk_9c;
} Unk021759c8_8c8;

typedef struct Unk021759c8 {
    union {
        ArchiveSlot mUnk_00[20];
        struct {
            /* 00 */ u8 mUnk_00_pad[0xd8];
            /* d8 */ s32 mUnk_d8;
            /* 0dc */ u8 mUnk_0dc[0x6c];
            /* 148 */ s32 mUnk_148;
            /* 14c */ u8 mUnk_14c[0x1bc];
            /* 308 */ s32 mUnk_308;
            /* 30c */ u8 mUnk_30c[0x6c];
            /* 378 */ s32 mUnk_378;
            /* 37c */ u8 mUnk_37c[0x6c];
            /* 3e8 */ s32 mUnk_3e8;
            /* 3ec */ u8 mUnk_3ec[0x6c];
            /* 458 */ s32 mUnk_458;
            /* 45c */ u8 mUnk_45c[0xdc];
            /* 538 */ s32 mUnk_538;
            /* 53c */ u8 mUnk_53c[0x6c];
            /* 5a8 */ s32 mUnk_5a8;
            /* 5ac */ u8 mUnk_5ac[0xdc];
            /* 688 */ s32 mUnk_688;
            /* 68c */ u8 mUnk_68c[0x6c];
            /* 6f8 */ s32 mUnk_6f8;
            /* 6fc */ u8 mUnk_6fc[0x6c];
            /* 768 */ s32 mUnk_768;
            /* 76c */ u8 mUnk_76c[0x6c];
            /* 7d8 */ s32 mUnk_7d8;
            /* 7dc */ u8 mUnk_7dc[0x70];
            /* 84c */ void *mUnk_84c;
            /* 850 */ Unk020182c0 mUnk_850;
            /* 8b8 */ s32 mUnk_8b8;
            /* 8bc */ void *mUnk_8bc;
        };
    };
    /* 8c0 */ u32 mUnk_8c0;
    /* 8c4 */ void *mUnk_8c4;
    /* 8c8 */ Unk021759c8_8c8 mUnk_8c8;
    /* 968 */ Unk02003024 mUnk_968;
    /* 9b0 */ Unk021759c8_9b0 mUnk_9b0[16];
    /* a70 */ void *mUnk_a70;
    /* a74 */ void *mUnk_a74;
    /* a78 */ NNSiFndHeapHead *mUnk_a78;
    /* a7c */ NNSiFndHeapHead *mUnk_a7c;
    /* a80 */ NNSiFndHeapHead *mUnk_a80;
} Unk021759c8;

extern Unk021759c8 *data_021759c8;
extern Unk021759cc *data_021759cc;
extern Unk021759d0 *data_021759d0;

// Object at data_usa_021759b8: 0x400 bytes (the end of them is the top of the stack of the OSThread) and two words.
typedef struct Unk021759b8 {
    /* 000 */ u8 mUnk_000[0x400];
    /* 400 */ OSThread mUnk_400;
    /* 4b8 */ u8 mUnk_4b8[8];
    /* 4c0 */ s32 mUnk_4c0;
    /* 4c4 */ s32 mUnk_4c4;
} Unk021759b8;

extern Unk021759b8 data_usa_021759b8;
extern vu16 data_021758e8[];
extern vu16 data_02175928[];
extern u8 data_02175dd8[];
// Object at data_02175614: a word and a function pointer.
typedef struct Unk02175614 {
    /* 00 */ volatile s32 mUnk_00;
    /* 04 */ s32 (*mUnk_04)();
} Unk02175614;

extern Unk02175614 data_02175614;

// Eight halfwords at data_usa_021755e4: two groups of four.
typedef struct Unk021755e4 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
} Unk021755e4;

extern Unk021755e4 data_usa_021755e4;

// Object func_0204a620 to func_0204a978 take: a buffer, two halfword counters and two words. The buffer holds a word
// at 0x00 and byte pairs from 0x04; its size is 0xdcc bytes.
extern Unk02175650 data_02175650[];

// Entry of the table at 0x440 of data_02175ec0: a four-bit part in the low bits of the first word, then two words.
typedef struct Unk02175ec0_440 {
    /* 00 */ u32 mUnk_00_0 : 4;
    /* 00 */ u32 mUnk_00_4 : 28;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 *mUnk_08;
} Unk02175ec0_440;

// Nine bytes that func_0204d28c builds on the stack and passes to func_02006d3c: two four-bit parts, a 24-bit part,
// a word and a byte.
typedef struct Unk02175ec0_msg {
    /* 00 */ u32 mUnk_00_0 : 4;
    /* 00 */ u32 mUnk_00_4 : 4;
    /* 00 */ u32 mUnk_00_8 : 24;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08;
} Unk02175ec0_msg;

struct Unk0204c090;
struct Unk02003024;

// Part of data_02175ec0 from 0x440: the table, then nine words at 0x46cc.
typedef struct Unk02175ec0_440s {
    /* 0000 */ Unk02175ec0_440 mUnk_0000[32];
    /* 0180 */ u8 mUnk_0180[0x97c];
    /* 0afc */ void *mUnk_0afc;
    /* 0b00 */ u32 mUnk_0b00;
    /* 0b04 */ u32 mUnk_0b04;
    /* 0b08 */ s32 mUnk_0b08;
    /* 0b0c */ u8 mUnk_0b0c[0x3bb4];
    /* 46c0 */ struct Unk0204c090 *mUnk_46c0;
    /* 46c4 */ struct Unk0204c090 *mUnk_46c4;
    /* 46c8 */ struct Unk0204c090 *mUnk_46c8;
    /* 46cc */ s32 mUnk_46cc;
    /* 46d0 */ s32 mUnk_46d0;
    /* 46d4 */ BOOL mUnk_46d4;
    /* 46d8 */ s32 mUnk_46d8;
    /* 46dc */ s32 mUnk_46dc;
    /* 46e0 */ BOOL mUnk_46e0;
    /* 46e4 */ s32 mUnk_46e4;
    /* 46e8 */ s32 mUnk_46e8;
    /* 46ec */ s32 mUnk_46ec;
} Unk02175ec0_440s;

// Object at data_02175ec0.
typedef struct Unk02175ec0 {
    /* 0000 */ u32 mUnk_0000;
    /* 0004 */ BOOL mUnk_0004;
    /* 0008 */ BOOL mUnk_0008;
    /* 000c */ s32 mUnk_000c;
    /* 0010 */ void (*mUnk_0010)(s32 a);
    /* 0014 */ void *(*mUnk_0014)(s32 a, u32 b, void *c);
    /* 0018 */ s32 mUnk_0018;
    /* 001c */ struct Unk02003024 *mUnk_001c;
    /* 0020 */ void *mUnk_0020;
    /* 0024 */ s32 mUnk_0024;
    /* 0028 */ s32 mUnk_0028;
    /* 002c */ s32 mUnk_002c;
    /* 0030 */ u16 mUnk_0030;
    /* 0032 */ u8 mUnk_0032[0xe];
    /* 0040 */ u8 mUnk_0040[0x400];
    /* 0440 */ Unk02175ec0_440s mUnk_0440;
} Unk02175ec0;

extern Unk02175ec0 data_02175ec0;
extern void (*data_usa_02175584)(s32);
extern s32 data_usa_02175e84;
extern s32 data_usa_02175e80;
