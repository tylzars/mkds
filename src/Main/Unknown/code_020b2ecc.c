#include "Main/Unknown/code_020b2ecc.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_020b24e4.h"
#include "Main/Unknown/code_020b29c4.h"
#include "Main/Unknown/code_020b2b54.h"
#include "Main/Unknown/code_020b2b70.h"
#include "Main/Unknown/code_020b2c80.h"
#include "Main/Unknown/code_020b2e98.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b3278.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b1de4.h"

#pragma thumb on
#pragma optimize_for_size on
void *func_020b320c(s32 a, s32 b) {
    s32 c[11] = {0x5d, 0x67, 0x62, 0x64, 0x65, 0x66, 0x69, 0x62, 0x61, 0x5f, 0x75};

    if (func_020b24e4() == 2) {
        c[0] = 0x6a;
        c[8] = 0x63;
    }
    if (a != 0) {
        c[2] = 0x60;
    }
    return GetBmgEntry(func_020b47cc("common.bmg"), c[b]);
}

void ClearChoisesSListValueCounts(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gChoisesS->mLists[i].mValueCount = 0;
    }
}

void func_020b31b8(s32 a, s32 b) {
    s32 n;

    n = gChoisesS->mLists[a].mValueCount;
    gChoisesS->mLists[a].mValueCount = n + 1;
    gChoisesS->mLists[a].mValues[n] = b;
}

s32 func_020b3120(s32 a) {
    s32 i = 0;
    s32 n;
    s32 k;
    ChoisesS *d;

    if (func_020b2e98() != 0) {
        k = func_020b2d04();
        n = gChoisesS->mLists[k].mValueCount;
        for (; i < n; i++) {
            if (gChoisesS->mUnk_028 == gChoisesS->mLists[k].mValues[i]) {
                break;
            }
        }
        if (n == 1) {
            a = 0;
        } else if (n == 2) {
            if (a != 0 && i + a >= 0 && i + a < n) {
                gChoisesS->mUnk_034 = 0;
                func_02105ac0(0);
            } else {
                a = 0;
            }
        } else if (a != 0) {
            gChoisesS->mUnk_034 = 0;
            func_02105ac0(0);
        }
        d = gChoisesS;
        d->mUnk_028 = d->mLists[k].mValues[(n + (i + a)) % n];
    }
    return i;
}

static inline ChoisesS *func_020b302c_inline(void) {
    return gChoisesS;
}

u32 func_020b302c(void) {
    u32 r = 0;
    s32 n;
    s32 k;
    s32 i;
    Unk020ae244 e[6];
    s32 d;
    s32 t;

    if (func_020b2e98() != 0) {
        func_020b3120(0);
        k = func_020b2d04();
        n = gChoisesS->mLists[k].mValueCount;
        for (i = 0, d = 0xc - n * 2; i < n; i++) {
            t = (d + i * 4) * 8 + 6;
            e[i].mUnk_00 = 8;
            e[i].mUnk_04 = 0xf8;
            e[i].mUnk_02 = t;
            e[i].mUnk_06 = t + 0x16;
        }
        for (i = 0; i < n; i++) {
            if (func_020ae244(func_020b2b54(), e[i]) != 0) {
                if (gChoisesS->mUnk_028 != func_020b302c_inline()->mLists[k].mValues[i]) {
                    gChoisesS->mUnk_028 = gChoisesS->mLists[k].mValues[i];
                    func_020b3120(0);
                } else {
                    gChoisesS->mUnk_010 = TRUE;
                }
                r = 1;
            }
        }
        if (r != 0) {
            if (gChoisesS->mUnk_028 == 0) {
                func_02105c4c();
            } else {
                func_020b3278();
            }
        }
    }
    return r;
}

void func_020b3008(void) {
    ChoisesS *p;

    gChoisesS->mUnk_024 = 0;
    p = gChoisesS;
    p->mUnk_028 = p->mLists[func_020b2d04()].mValues[0];
}

void func_020b2f88(s32 a) {
    if (gChoisesS->mUnk_00c != 0) {
        return;
    }
    if (a != 0 && func_020b2e98() == 0) {
        if (func_020b29c4() != 0) {
            gChoisesS->mUnk_000 = a;
        } else if (func_020b2b70() != 0) {
            gChoisesS->mUnk_008 = a;
        } else {
            return;
        }
        func_020b3008();
    } else if (a == 0 && func_020b2e98() != 0) {
        if (func_020b29c4() != 0) {
            gChoisesS->mUnk_000 = a;
        } else if (func_020b2b70() != 0) {
            gChoisesS->mUnk_008 = a;
        } else {
            return;
        }
    }
    if (gChoisesS->mUnk_024 != 0) {
        gChoisesS->mUnk_00c = 1;
    }
}

u32 func_020b2f58(void) {
    if ((func_020b2f38() == 6 && func_020b2f18() == 9) || (func_020b2f38() == 7 && func_020b2f18() == 9)) {
        return 1;
    }
    return 0;
}
#pragma thumb off

s8 func_020b2f38(void) {
    Unk021759c0 *d = data_021759c0;

    if (d->mMode == MODE_MISSION_RUN) {
        return d->mMissionTableRow;
    }
    return -1;
}

s8 func_020b2f18(void) {
    Unk021759c0 *d = data_021759c0;

    if (d->mMode == MODE_MISSION_RUN) {
        return d->mMissionTableColumn;
    }
    return -1;
}

#pragma thumb on
u32 func_020b2ecc(void) {
    s32 v1;
    s32 r;

    r = func_0205fd78(func_020b2f38(), func_020b2f18(), &v1);
    if (func_020b2d54() == 0 && gChoisesS->mUnk_020 != FALSE && r != 0 && (u32) (v1 - 5) <= 2) {
        return 1;
    }
    return 0;
}
#pragma thumb off
