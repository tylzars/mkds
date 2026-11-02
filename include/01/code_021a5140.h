#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_020b4000.h"

// Object behind the pointer at 0x85c of Unk021ca41c.
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
typedef struct Unk021ca41c {
    /* 0000 */ u8 mUnk_0000[0x404];
    /* 0404 */ u8 mUnk_0404[0x404];
    /* 0808 */ Unk020b4a44 *mUnk_0808;
    /* 080c */ Unk020b4a44 *mUnk_080c;
    /* 0810 */ Unk020b4934 *mUnk_0810;
    /* 0814 */ Unk020b4934 *mUnk_0814;
    /* 0818 */ Unk020b47d8 *mUnk_0818;
    /* 081c */ Unk020b47d8 *mUnk_081c;
    /* 0820 */ struct Unk02021dc8 *mUnk_0820;
    /* 0824 */ struct Unk02021dc8 *mUnk_0824;
    /* 0828 */ void *mUnk_0828;
    /* 082c */ Unk020b4a44 *mUnk_082c;
    /* 0830 */ Unk020b4a44 *mUnk_0830;
    /* 0834 */ Unk020b4934 *mUnk_0834;
    /* 0838 */ Unk020b4934 *mUnk_0838;
    /* 083c */ Unk020b4934 *mUnk_083c;
    /* 0840 */ Unk020b47d8 *mUnk_0840;
    /* 0844 */ Unk020b47d8 *mUnk_0844;
    /* 0848 */ Unk020b47d8 *mUnk_0848;
    /* 084c */ Unk020b47d8 *mUnk_084c;
    /* 0850 */ struct Unk02021dc8 *mUnk_0850;
    /* 0854 */ struct Unk02021dc8 *mUnk_0854;
    /* 0858 */ void *mUnk_0858;
    /* 085c */ Unk021ca41c_085c *mUnk_085c;
    /* 0860 */ Unk020b4934 *mUnk_0860;
    /* 0864 */ Unk020b4934 *mUnk_0864;
    /* 0868 */ Unk020b47d8 *mUnk_0868;
    /* 086c */ Unk020b47d8 *mUnk_086c;
    /* 0870 */ struct Unk02021dc8 *mUnk_0870;
    /* 0874 */ struct Unk02021dc8 *mUnk_0874;
    /* 0878 */ void *mUnk_0878;
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
} Unk021ca41c;

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

extern Unk021ca41c *gEmblem;

void InitEmblem(void);
