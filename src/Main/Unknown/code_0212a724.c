#include "Main/Unknown/code_0212a724.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02120610.h"

s32 func_0212a8d0(void) {
    BOOL r = FALSE;
    if (!data_0217aa08->mUnk_00->mUnk_31_4) {
        if (func_021213f4() != 0) {
            r = TRUE;
        }
    }
    return r;
}

#pragma thumb on
void func_0212a724(void) {
    s32 a[2] = {0x4000, 0x4000};
    u8 b[2][2][2] = {{{0x50, 0x10}, {0x50, 0x10}}, {{0x50, 0x10}, {0x50, 0x10}}};
    u8 c[2][12][2] = {
        {{8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}},
        {{16, 16},
         {16, 16},
         {16, 16},
         {16, 16},
         {16, 16},
         {16, 16},
         {16, 16},
         {16, 16},
         {16, 16},
         {16, 16},
         {16, 16},
         {16, 16}}};
    s32 i;
    s32 j;
    s32 l;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            a[1] -= func_021243ac(gKeyboard->mUnk_00, data_0215d0e4[i][j], gKeyboard->mBnlls[i], b[i][j][0], b[i][j][1],
                                  data_0215d128[i][j][0], gKeyboard->mNcer, gKeyboard->mBncls[i],
                                  gKeyboard->mUnk_74[i][1], a[1]);
        }
    }
    for (j = 0; j < 2; j++) {
        for (l = 0; l < 2; l++) {
            for (i = 0; i < data_0215d0e0[j]; i++) {
                a[l] -= func_021243ac(gKeyboard->mUnk_00, data_0215d134[j][i], gKeyboard->mBnlls[j], c[j][i][0],
                                      c[j][i][1], data_0215d14c[j][i], gKeyboard->mNcer, gKeyboard->mBncls[j],
                                      gKeyboard->mUnk_74[j][l], a[l]);
            }
        }
    }
}
#pragma thumb off
