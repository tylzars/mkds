#pragma once

#include "types.h"

typedef struct Ncgr Ncgr;
typedef struct Nscr Nscr;
typedef struct Nclr Nclr;

// Argument of AdvanceLld.
typedef struct OamBuffer {
    /* 000 */ u8 mOams[0x400];
    /* 400 */ u16 mOamCount;
    /* 402 */ u16 mUnk_402;
} OamBuffer;

// Object behind the pointer at 0x85c of Emblem.
typedef struct Lld {
    /* 00 */ u16 mEntryCount;
    /* 02 */ u8 mUnk_02[0x2];
    /* 04 */ struct LldEntry *mEntries;
    /* 08 */ void *mCells;
    /* 0c */ void *mCellAnims;
    /* 10 */ s32 mOffsetX;
    /* 14 */ s32 mOffsetY;
} Lld;

// Object behind gEmblem, allocated by InitEmblem.
typedef struct Emblem {
    /* 0000 */ OamBuffer mUnk_0000;
    /* 0404 */ OamBuffer mUnk_0404;
    /* 0808 */ Nclr *mEmblemMONclr;
    /* 080c */ Nclr *mEmblemMBNclr;
    /* 0810 */ Ncgr *mEmblemMONcgr;
    /* 0814 */ Ncgr *mEmblemMBNcgr;
    /* 0818 */ Nscr *mEmblemMNscr;
    /* 081c */ Nscr *mEmblemMBgNscr;
    /* 0820 */ struct Unk02021dc8 *mEmblemMNcer;
    /* 0824 */ struct Unk02021dc8 *mEmblemMNanr;
    /* 0828 */ struct Lld *mEmblemMLld;
    /* 082c */ Nclr *mEmblemSONclr;
    /* 0830 */ Nclr *mEmblemSBNclr;
    /* 0834 */ Ncgr *mEmblemSONcgr;
    /* 0838 */ Ncgr *mEmblemSBNcgr;
    /* 083c */ Ncgr *mEmblemTemplateBNcgr;
    /* 0840 */ Nscr *mEmblemSToolNscr;
    /* 0844 */ Nscr *mEmblemSBgNscr;
    /* 0848 */ Nscr *mEmblemSTemplateFrameNscr;
    /* 084c */ Nscr *mEmblemSTemplateDarkNscr;
    /* 0850 */ struct Unk02021dc8 *mEmblemSNcer;
    /* 0854 */ struct Unk02021dc8 *mEmblemSNanr;
    /* 0858 */ struct Lld *mEmblemSLld;
    /* 085c */ Lld *mEmblemTemplateSLld;
    /* 0860 */ Ncgr *mEmblemCameraSONcgr;
    /* 0864 */ Ncgr *mEmblemCameraSBNcgr;
    /* 0868 */ Nscr *mEmblemCameraSDSNscr;
    /* 086c */ Nscr *mEmblemCameraSBgNscr;
    /* 0870 */ struct Unk02021dc8 *mEmblemCameraSNcer;
    /* 0874 */ struct Unk02021dc8 *mEmblemCameraSNanr;
    /* 0878 */ struct Lld *mEmblemCameraSLld;
    /* 087c */ u8 mUnk_087c[0x200];
    /* 0a7c */ u8 mUnk_0a7c[0x200];
    /* 0c7c */ u8 mUnk_0c7c[0x400];
    /* 107c */ s32 mUnk_107c;
    /* 1080 */ s32 mUnk_1080;
    /* 1084 */ s32 mUnk_1084;
    /* 1088 */ s32 mUnk_1088;
    /* 108c */ UnkFunc *mUnk_108c;
    /* 1090 */ s32 mUnk_1090;
    /* 1094 */ s32 mUnk_1094;
    /* 1098 */ s32 mUnk_1098;
    /* 109c */ s32 mUnk_109c;
    /* 10a0 */ s32 mUnk_10a0;
    /* 10a4 */ s32 mUnk_10a4;
    /* 10a8 */ s32 mUnk_10a8;
    /* 10ac */ BOOL mUnk_10ac;
    /* 10b0 */ BOOL mUnk_10b0;
    /* 10b4 */ s32 mUnk_10b4;
    /* 10b8 */ BOOL mUnk_10b8;
    /* 10bc */ s32 mUnk_10bc;
} Emblem;

extern Emblem *gEmblem;

void InitEmblem(void);
