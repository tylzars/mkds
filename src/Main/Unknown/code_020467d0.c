#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0205d0bc.h"
#include "Main/Unknown/code_0205dc54.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_021759c0.h"

s32 func_02046a88(void *a) {
    Unk021a9034 b = data_02164838;

    func_020487fc(a, &b);
    return 0;
}

void func_02046a3c(void *a) {
    data_021759c0 = HeapAlloc(a, 0x400);
    data_021759c0->mCourseList = HeapAlloc(a, 0x21);
    func_0205d0bc(a);
    func_0205dc54(a);
}

void func_02046968(s32 a) {
    u8 b[2] = {0};
    s32 i;
    u8 n;
    u8 m;

    n = 0;
    m = 0;
    for (i = 0; i < a; i++) {
        if (data_021759c0->mUnk_68[i].mUnk_08.mUnk_00 != 4) {
            if (data_021759c0->mUnk_68[i].mUnk_08.mUnk_00 == 0 || data_021759c0->mUnk_68[i].mUnk_08.mUnk_00 == 3) {
                n++;
            }
            m++;
            if (data_021759c0->mUseTeams != 0) {
                b[data_021759c0->mUnk_68[i].mUnk_08.mTeamIndex]++;
            }
        }
    }
    data_021759c0->mKartCount = m;
    data_021759c0->mUnk_3d1 = n;
    for (i = 0; i < 2; i++) {
        data_021759c0->mTeamKartCounts[i] = b[i];
    }
}

void func_020468b0(int a, u32 b, u32 c, int d, u32 e, int f) {
    data_021759c0->mUnk_250[a].mCharacterIndex = b;
    data_021759c0->mUnk_250[a].mUnk_08.mUnk_00 = d;
    data_021759c0->mUnk_250[a].mUnk_08.mUnk_0c = a;
    data_021759c0->mUnk_250[a].mKartIndex = c;
    data_021759c0->mUnk_250[a].mUnk_08.mTeamIndex = e;
    data_021759c0->mUnk_250[a].mUnk_08.mUnk_08 = f;
    data_021759c0->mUnk_250[a].mUnk_08.mUnk_10 = d == 2 ? 0 : 3;
    data_021759c0->mUnk_250[a].mUnk_08.mUnk_14 = 0;
    if (f != 3) {
        data_021759c0->mUnk_250[a].mUnk_08.mUnk_14 |= 1;
    }
}

s32 func_0204684c(s32 a) {
    s32 i;
    s32 j;
    s8 r;

    r = -1;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (a == data_02154128[i][j]) {
                r = j + i * 4;
                break;
            }
        }
    }
    return r;
}

u32 func_02046828(s32 a) {
    return data_02154128[(u32) a / 4][a % 4];
}

s32 func_020467d0(s32 a) {
    s32 r;
    s32 i;
    s32 j;

    r = 9;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (a == data_02154128[i][j]) {
                r = i;
            }
        }
    }
    return r;
}
