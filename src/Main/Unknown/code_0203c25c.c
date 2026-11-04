#include "Main/Unknown/code_0203c25c.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020b1cdc.h"

u16 func_0203c4d0(u8 a) {
    u16 r = 0;
    Unk0217561c_4dc *t = data_0217561c->mUnk_4dc;
    if (t != NULL) {
        switch (data_021759c0->mUnk_08) {
            case 0:
                break;
            case 3: {
                u16 k = 1;
                if (data_021759c0->mUseTeams != 0) {
                    if (data_021759c0->mKartCount > 3) {
                        if (data_021759c0->mTeamKartCounts[0] <= 1 || data_021759c0->mTeamKartCounts[1] <= 1) {
                            k = 8;
                        } else {
                            k = 0xf;
                        }
                    } else {
                        k = 8;
                    }
                }
                r = k + 8 - data_021759c0->mKartCount;
                break;
            }
            case 5:
                r = 9 - data_021759c0->mKartCount;
                break;
        }
        r = (t + r + 1)->mUnk_00[a - 1];
    }
    return r;
}

void func_0203c2e4(u16 a) {
    u32 o;
    Unk0217561c_14 *p = (Unk0217561c_14 *) ((u8 *) &data_0217561c->mUnk_14[0] + a * 0x8c);
    BOOL f = FALSE;
    switch (p->mUnk_00) {
        case 1:
        case 2:
        case 3:
            f = TRUE;
            break;
    }
    if (f == FALSE) {
        u32 v;
        s32 i;
        o = p->mUnk_3c_0;
        v = (u16) (data_021759c0->mKartCount - data_0217561c->mUnk_000[0].mUnk_10);
        p->mUnk_3c_0 = data_021759c0->mKartCount - data_0217561c->mUnk_000[0].mUnk_10;
        for (i = 0; i < data_021759c0->mKartCount; i++) {
            Unk0217561c_14 *q = (Unk0217561c_14 *) ((u8 *) &data_0217561c->mUnk_14[0] + i * 0x8c);
            if (i != a) {
                u32 m = q->mUnk_3c_0;
                if (m > o && m <= v) {
                    q->mUnk_3c_0--;
                }
            }
        }
        data_0217561c->mUnk_000[0].mUnk_10++;
    }
    if (data_021759c0->mUnk_08 == 2) {
        func_020a16d0(a);
    }
    p->mUnk_00 = 4;
    func_02069044(func_0207a974(a));
    func_020b1cdc(a, 1);
    if (func_0203ef58() != 0) {
        switch (data_021759c0->mUnk_08) {
            case 1:
                break;
            case 2:
                func_020a12b8();
                break;
            case 4:
                func_0203eb38();
                break;
            case 5:
                func_0203ecf0();
                break;
            default:
                func_0203ee28();
                break;
        }
    }
}

BOOL func_0203c25c(u16 a) {
    BOOL f = FALSE;
    BOOL r;
    switch (data_0217561c->mUnk_000[a].mUnk_14) {
        case 1:
        case 2:
        case 3:
            f = TRUE;
            break;
    }
    r = f == FALSE;
    if (r != FALSE) {
        r = func_02044618() == data_0217561c->mUnk_000[a].mUnk_38;
    }
    return r != FALSE;
}
