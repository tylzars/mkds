#pragma once

#include "03/code_021be610.h"
#include "03/code_021d1fd0.h"
#include "03/code_021c209c.h"
#include "03/code_021c4ad4.h"
#include "03/code_021cfa68.h"
#include "types.h"
#include "03/code_021d1770.h" // OamRange
#include "03/code_021d1d88.h"
#include "03/code_021d1da8.h"
#include "code_02003024.h" // FSArchive
#include "03/code_021bf098.h"
#include "03/code_021c2530.h"
#include "03/code_021c25e0.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"
#include "03/types_021d299c.h"

typedef struct Jb3List {
    /* 00 */ u32 mIdTimerTask;
    /* 04 */ u8 mIdTimer[4];
    /* 08 */ u16 *mJb3ListBackNsc;
    /* 0c */ void *mYbBgStep2NclFiles[2];
    /* 14 */ BgTextCanvas *mUnk_14;
    /* 18 */ OamEntry *mUnk_18[7];
    /* 34 */ OamEntry *mUnk_34;
    /* 38 */ u32 mScrollTask;
    /* 3c */ u32 mBgOffsetTask;
    /* 40 */ u8 mUnk_40;
    /* 41 */ u8 mScrollTimer;
    /* 42 */ u8 mReturnId;
    /* 43 */ u8 mUnk_43;
    /* 44 */ u8 mBgOffsetPending;
    /* 45 */ u8 mUnk_45;
    /* 46 */ u8 mUnk_46;
    /* 47 */ u8 mUnk_47;
} Jb3List;

// Objects whose layout isn't known yet.
typedef struct Unk021da280 Unk021da280;
typedef struct Unk021cf260 Unk021cf260;
extern SlideButtons *data_ov003_021da108;
extern u8 data_ov003_021da10c;
extern OamRange **gSelectionObjects;
// Object behind gLinkLevel.
typedef struct LinkLevel {
    /* 00 */ OamEntry *mUnk_00;
    /* 04 */ u32 mTask;
    /* 08 */ s8 mUnk_08;
} LinkLevel;

extern LinkLevel *gLinkLevel;

// The on-screen keys of the Edit screen.
typedef struct EditKeyboard {
    /* 000 */ void *mRowTexts[3][4];
    /* 030 */ OamEntry *mKeys[0x2f];
    /* 0ec */ OamEntry *mExtraKeys[4];
    /* 0fc */ OamRange *mRow4Keys[2];
    /* 104 */ void *mUnk_104[4];
    /* 114 */ OamRange *mCursor;
    /* 118 */ TaskEntry *mStepTask;
    /* 11c */ u8 mInput;
    /* 11d */ u8 mPage;
    /* 11e */ s8 mPressedKeyIndex;
    /* 11f */ s8 mHighlightedKeyIndex;
    /* 120 */ s8 mUnk_120;
    /* 121 */ s8 mCursorKeyIndex;
    /* 122 */ u8 mRepeatCalls;
    /* 123 */ u8 mRemoveCharEnabled;
    /* 124 */ u8 mAddCharEnabled;
    /* 125 */ u8 mRemoveDisabledSoundPlayed;
} EditKeyboard;

extern EditKeyboard *gEditKeyboard;
struct EditAddrKeyboard;
extern struct EditAddrKeyboard *gEditAddrKeyboard;
extern u8 gValueRecordsRequestSucceeded[];
struct ValueRecordsRequest;
extern struct ValueRecordsRequest *gValueRecordsRequest;
extern u8 gLanguageIndex[];
extern u8 data_ov003_021da170[];
extern void *data_ov003_021da174;
extern u8 data_ov003_021da1a8;
extern u8 data_ov003_021da1b0[];
extern u8 data_ov003_021da1bc[];
extern u8 data_ov003_021da1c0;
extern u8 data_ov003_021da1c4;
extern u8 data_ov003_021da1c8[];
extern u8 data_ov003_021da1cc;
extern u8 data_ov003_021da1d4;
extern u8 data_ov003_021da1d8;
extern u8 data_ov003_021da1dc;
extern u8 data_ov003_021da1e8[];
extern u8 gApListScrollY[];
struct ApList;
extern struct ApList *gApList;
struct Edit;
extern struct Edit *gEdit;
struct EditAddr;
extern struct EditAddr *gEditAddr;
extern u8 gJb4ErrorCode[];
extern u8 gJb3ListSelectedId;
extern u8 gJb3ListMode;
extern u8 gJb3ListSelectedRow;
extern u16 gJb3ListScrollY;
extern Jb3List *gJb3List;
extern u8 data_ov003_021da218;
extern u8 data_ov003_021da21c;
extern u8 data_ov003_021da220[];
extern u8 data_ov003_021da224;
extern u8 data_ov003_021da228[];
extern u16 data_ov003_021da22c;
extern u8 gApSelectedIndex[];
struct Ap;
extern struct Ap *gAp;
extern s8 gWaySavedIndex;
extern s8 gWaySelectedIndex;
extern u8 data_ov003_021da240[];
extern u8 *gYbBgStep21Ncl;
extern u8 data_ov003_021da248;
extern u8 data_ov003_021da24c[];
extern u8 data_ov003_021da250;
extern u8 data_ov003_021da254;
extern u8 data_ov003_021da258;
struct Unk021da25c;
extern struct Unk021da25c *data_ov003_021da25c;
extern u8 data_ov003_021da260[];
struct Unk021cca74;
extern struct Unk021cca74 *data_ov003_021da268;
struct Unk021da26c;
extern struct Unk021da26c *data_ov003_021da26c;
struct Unk021cd5e0;
extern struct Unk021cd5e0 *data_ov003_021da270;
struct SoundData;
extern struct SoundData *gSoundData;
extern void *data_ov003_021da278;
struct Unk021ce0f0;
extern struct Unk021ce0f0 *data_ov003_021da27c;
extern Unk021da280 *data_ov003_021da280;
// Object behind data_ov003_021da284: func_ov003_021ceaf8 passes 0x00 to GetOamRangeEntryPosition and reads the byte at
// 0x1e; func_ov003_021cef80 reads the byte at 0x1b.
typedef struct Unk021da284 {
    /* 00 */ OamRange *mUnk_00;
    /* 04 */ OamRange *mUnk_04;
    /* 08 */ OamRange *mUnk_08[2];
    /* 10 */ void *mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u16 mUnk_18;
    /* 1a */ s8 mUnk_1a;
    /* 1b */ s8 mUnk_1b;
    /* 1c */ u8 mUnk_1c;
    /* 1d */ u8 mUnk_1d;
    /* 1e */ u8 mUnk_1e;
} Unk021da284;

extern Unk021da284 *data_ov003_021da284;
extern Unk021cf260 *data_ov003_021da288;
extern u16 *data_ov003_021da28c[];
extern UnkFunc *data_ov003_021da2a4;
typedef struct Unk021da2ac_100 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[0x40];
} Unk021da2ac_100;

// Object behind data_ov003_021da2ac.
typedef struct Unk021da2ac {
    /* 000 */ u8 pad_000[0x100];
    /* 100 */ Unk021da2ac_100 mUnk_100[2];
    /* 188 */ u8 pad_188[0x78];
    /* 200 */ u16 mUnk_200;
    /* 202 */ u16 mUnk_202;
    /* 204 */ u32 mUnk_204;
    /* 208 */ u32 mUnk_208[16];
    /* 248 */ u8 pad_248[0x400];
    /* 648 */ u16 mUnk_648;
    /* 64a */ u16 mUnk_64a;
    /* 64c */ u8 mUnk_64c[0x404];
    /* a50 */ u8 mUnk_a50[0x40];
    /* a90 */ u8 mUnk_a90;
    /* a91 */ u8 mUnk_a91;
    /* a92 */ u8 mUnk_a92;
    /* a93 */ u8 mUnk_a93;
    /* a94 */ u32 mUnk_a94;
    /* a98 */ u32 mUnk_a98;
    /* a9c */ u32 mUnk_a9c;
    /* aa0 */ u8 *mUnk_aa0[2];
    /* aa8 */ u8 mUnk_aa8[4];
    /* aac */ u8 mUnk_aac;
    /* aad */ u8 mUnk_aad[3];
    /* ab0 */ Unk021da2ac_100 *mUnk_ab0;
    /* ab4 */ u32 mUnk_ab4;
    /* ab8 */ u32 mUnk_ab8;
    /* abc */ u32 mUnk_abc;
    /* ac0 */ u32 mUnk_ac0;
    /* ac4 */ u32 mUnk_ac4;
    /* ac8 */ u32 mUnk_ac8;
    /* acc */ u8 mUnk_acc;
    /* acd */ u8 mUnk_acd[0x33];
    /* b00 */ u8 mUnk_b00[4];
} Unk021da2ac;

extern Unk021da2ac *data_ov003_021da2ac;
// Object of 0xe8 bytes: a pointer at 0x00, 32 pointers from 0x04, the list of them at 0x84, an FSArchive at 0x88
// and a halfword at 0xe4.
typedef struct DwcArchive {
    /* 00 */ void *mTables;
    /* 04 */ void *mUnk_04[0x20];
    /* 84 */ PointerStack *mUnk_84;
    /* 88 */ FSArchive mArchive;
    /* e4 */ u16 mLockId;
    /* e6 */ u8 mUnk_e6[2];
} DwcArchive;

extern DwcArchive *gDwcArchive;
// Two objects of 0x228 bytes: 32 objects from 0x000, two list heads at 0x200 and 0x210, a pointer at 0x220 and the
// list of the free objects at 0x224.
typedef struct OamRanges {
    /* 000 */ OamRange mRanges[0x20];
    /* 200 */ OamRange mListStart;
    /* 210 */ OamRange mListEnd;
    /* 220 */ void *mUnk_220;
    /* 224 */ PointerStack *mFreeRanges;
} OamRanges;

extern OamRanges *gOamRanges;
// Eight-byte records at the start of a resource: a number at 0x00 and the offset of a table at 0x04.
typedef struct NceImage {
    /* 00 */ u16 mEntryCount;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mEntriesOffset;
} NceImage;

extern NceImage *gNceFiles[];
extern BlendBrightnessFadeSlot *gBlendBrightnessFadeSlots;
extern TextCanvases *gTextCanvases;
extern u8 gLcdOff;
extern u8 gTouchRepeatFrames;
extern KeyTouchInput *gKeyTouchInput;
extern u8 gKeyRepeatFrames[];
extern UnkFunc *gSavedIrqFunction;
extern u32 gSavedIrqMask;
struct OamBuffers;
extern struct OamBuffers *gOamBuffers;
struct ObjCharRanges;
extern struct ObjCharRanges *gObjCharRanges;
extern u32 gSavedBankSettings[];
struct TaskList;
extern struct TaskList *gTaskLists;
