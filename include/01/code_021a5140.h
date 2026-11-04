#pragma once

#include "types.h"

typedef struct Ncgr Ncgr;
typedef struct Nscr Nscr;
typedef struct Nclr Nclr;

// Object behind the pointer at 0x85c of Emblem.
typedef struct Unk021ca41c_085c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[0x2];
    /* 04 */ struct Unk021a5a58 *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
} Unk021ca41c_085c;

// Object behind gEmblem, allocated by InitEmblem.
typedef struct Emblem {
    /* 0000 */ u8 mUnk_0000[0x404];
    /* 0404 */ u8 mUnk_0404[0x404];
    /* 0808 */ Nclr *mEmblemMONclr;
    /* 080c */ Nclr *mEmblemMBNclr;
    /* 0810 */ Ncgr *mEmblemMONcgr;
    /* 0814 */ Ncgr *mEmblemMBNcgr;
    /* 0818 */ Nscr *mEmblemMNscr;
    /* 081c */ Nscr *mEmblemMBgNscr;
    /* 0820 */ struct Unk02021dc8 *mEmblemMNcer;
    /* 0824 */ struct Unk02021dc8 *mEmblemMNanr;
    /* 0828 */ void *mEmblemMLld;
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
    /* 0858 */ void *mEmblemSLld;
    /* 085c */ Unk021ca41c_085c *mEmblemTemplateSLld;
    /* 0860 */ Ncgr *mEmblemCameraSONcgr;
    /* 0864 */ Ncgr *mEmblemCameraSBNcgr;
    /* 0868 */ Nscr *mEmblemCameraSDSNscr;
    /* 086c */ Nscr *mEmblemCameraSBgNscr;
    /* 0870 */ struct Unk02021dc8 *mEmblemCameraSNcer;
    /* 0874 */ struct Unk02021dc8 *mEmblemCameraSNanr;
    /* 0878 */ void *mEmblemCameraSLld;
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
    /* 10ac */ s32 mUnk_10ac;
    /* 10b0 */ s32 mUnk_10b0;
    /* 10b4 */ s32 mUnk_10b4;
    /* 10b8 */ s32 mUnk_10b8;
    /* 10bc */ s32 mUnk_10bc;
} Emblem;

// Block of 20 halfwords that func_020391d4 fills with defaults and func_02038d88 reads.
typedef struct Unk020391d4 {
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
} Unk020391d4;

extern Emblem *gEmblem;

void InitEmblem(void);
