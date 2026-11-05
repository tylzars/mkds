#include "Main/Unknown/code_020f9c6c.h"
#include "code_02012b30.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020fe450.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02079b40.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f1a24.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f73a4.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_020f81c0.h"
#include "Main/Unknown/code_020f82c4.h"
#include "Main/Unknown/code_020f9334.h"
#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_020fcbb8.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_02109054.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01fff000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020fc000.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01fff434.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_0208eb10.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020fcb9c.h"
#include "Main/Unknown/code_020fcedc.h"
#include "Main/Unknown/code_020ff000.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210e000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020f2000.h"
#include "Main/Unknown/code_020fa000.h"
#include "Main/Unknown/code_020f92e8.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020fd254.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_0210a000.h"

void func_020fcb30(Unk020fc2e8 *p) {
    p->mUnk_170 = 1;
}

void func_020fcac0(Unk020fc2e8 *a) {
    func_02046be8(&a->mUnk_2e8, (UnkFunc *const *) data_0216c6b4, 8, a);
    Matrix4x3Identity((Unk02012f58 *) a->mUnk_2b4);
    a->mUnk_274 = 1;
    a->mUnk_276 = gRaceProgress->mKartAtRank[0];
    a->mUnk_278 = 0;
    a->mUnk_26c = 0;
    a->mUnk_270 = 0xdc;
    a->mUnk_280 = 0;
    a->mUnk_2e4 = 0;
}

void func_020fc94c(Unk020fc2e8 *p) {
    func_0210b850(&p->mUnk_300);
    p->mUnk_000.mUnk_00.mUnk_30 = (void (*)(void *, void *, void *)) func_0210a67c;
    p->mUnk_160 = 0;
    p->mUnk_000.mUnk_0c4 = p->mUnk_000.mPos;
    func_020f9c40((s32) p);
    p->mUnk_000.mFlags |= 0x200000;
    func_020fd254(p);
    if (gRaceProgress->mRaceDone != 0) {
        p->mUnk_274 = 1;
        p->mUnk_276 = gRaceProgress->mKartAtRank[(p->mUnk_274 & 0xff) - 1];
    } else {
        p->mUnk_276 = gRaceProgress->mKartAtRank[(p->mUnk_274 & 0xff) - 1];
        while (IsKartEnded(p->mUnk_276) != 0 && (u32) p->mUnk_274 < (u32) data_021759c0->mKartCount) {
            p->mUnk_274++;
            p->mUnk_276 = gRaceProgress->mKartAtRank[(p->mUnk_274 & 0xff) - 1];
        }
    }
    p->mUnk_260 = 0x32000;
    p->mUnk_264 = 0xf000;
    p->mUnk_268 = 0;
    p->mUnk_27c = 0x1a000;
    p->mUnk_298.x = 0;
    p->mUnk_298.y = 0;
    p->mUnk_298.z = 0;
    Vec3Sub(&p->mUnk_000.mVelocity, &p->mUnk_298, &p->mUnk_28c);
    p->mUnk_000.mUnk_d0 = &p->mUnk_000.mUnk_0c4;
    func_0208adc8(&p->mUnk_000.mUnk_7c, 1);
}

void func_020fc8ec(Unk020fc2e8 *e, s32 a) {
    Kart *p;

    if (e->mUnk_228 != NULL) {
        return;
    }
    func_020fcb9c((s32) e, a);
    p = e->mUnk_228->mKart;
    e->mUnk_2f8 = ((e->mUnk_000.mFlags & 0x40000000) || (p->mUnk_48 & 1)) ? 2 : 3;
    e->mUnk_2fa = 1;
}

s32 func_020fc79c(Unk020eda5c *a, Unk020fc2e8 *e) {
    Kart *p;

    func_020f9114(e);
    if (a->mUnk_00c->mUnk_1f0.mUnk_00 != NULL) {
        func_020ed268((Unk020ec8bc *) e, a, 0x14, 0xcc, 1, 1, 0, 0x6000, e->mUnk_276, 1);
        func_02046bcc(e->mUnk_2e8, 1);
    } else {
        func_020fcb9c((s32) e, (u16) gRaceProgress->mKartAtRank[0]);
        p = e->mUnk_228->mKart;
        e->mUnk_2f8 = ((e->mUnk_000.mFlags & 0x40000000) || (p->mUnk_48 & 1)) ? 2 : 3;
        e->mUnk_2fa = 1;
        if (e->mUnk_000.mFlags & 0x8000000) {
            func_020fe71c(5, e->mUnk_228->mKartIndex, e->mUnk_000.mId);
        }
    }
    func_020fc94c(e);
    // one 36-byte copy of the three vectors (three Vec3 assignments give 0x160 bytes against 0x150)
    *(Matrix3x3 *) &e->mUnk_000.mUnk_94 = *(Matrix3x3 *) &a->mUnk_02c.mUnk_00;
    if (e->mUnk_000.mFlags & 0x8000000) {
        e->mUnk_2f8 = 0;
        e->mUnk_2fa = 1;
    }
    return 1;
}

void func_020fc654(Unk020fc2e8 *p) {
    Vec3 buf;
    s16 v;
    s32 a;

    a = p->mUnk_260;
    if (p->mUnk_000.mFlags & 0x40000000) {
        p->mUnk_268 += 0x5dc;
        v = gPairsByAngle[(p->mUnk_268 >> 4) * 2];
        Vec3AddScaled(a + (s32) (((s64) p->mUnk_264 * v) >> 12), &p->mUnk_000.mUnk_f0, &p->mUnk_000.mPos, &buf);
        Vec3Sub(&buf, &p->mUnk_000.mUnk_0c4, &buf);
        Vec3AddScaled(0x333, &buf, &p->mUnk_000.mUnk_0c4, &p->mUnk_000.mUnk_0c4);
    } else {
        p->mUnk_000.mUnk_0c4.y += p->mUnk_000.mVelocity.y >> 1;
        p->mUnk_268 += 0x5dc;
        v = gPairsByAngle[(p->mUnk_268 >> 4) * 2];
        a += (s32) (((s64) p->mUnk_264 * v) >> 12);
        a = a + p->mUnk_000.mPos.y - p->mUnk_000.mUnk_0c4.y;
        p->mUnk_000.mUnk_0c4.y += (s32) (((s64) a * 0x19a) >> 12);
        p->mUnk_000.mUnk_0c4.x = p->mUnk_000.mPos.x;
        p->mUnk_000.mUnk_0c4.z = p->mUnk_000.mPos.z;
    }
}

void func_020fc2e8(Unk020fc2e8 *p, Vec3 *v, s32 v1, Vec3 *v2) {
    Vec3 buf;
    Vec3 v3;
    Vec3 *v4 = &p->mUnk_28c;
    Vec3 *v5 = &p->mUnk_298;
    s32 ok;

    if (v2 != NULL) {
        if ((s64) v->x * v->x + (s64) v->y * v->y + (s64) v->z * v->z >= 0x10) {
            func_02039860(v, &p->mUnk_000.mUnk_94.mUnk_00[2]);
        }
        v5->x = (s32) (((s64) v5->x * 0xccd) >> 12);
        v5->y = (s32) (((s64) v5->y * 0xccd) >> 12);
        v5->z = (s32) (((s64) v5->z * 0xccd) >> 12);
        Vec3AddScaled(0x3000, v5, v2, &buf);
        func_020397a8(&buf, &p->mUnk_000.mUnk_94.mUnk_00[2], &buf);
        if ((s64) buf.x * buf.x + (s64) buf.y * buf.y + (s64) buf.z * buf.z >= 0x10) {
            func_02039860(&buf, &p->mUnk_000.mUnk_94.mUnk_00[0]);
        }
    } else {
        if ((s64) v->x * v->x + (s64) v->y * v->y + (s64) v->z * v->z >= 0x10) {
            func_02039860(v, &buf);
        }
        if (buf.x * buf.x + buf.z * buf.z < 0x112510) {
            return;
        }
        p->mUnk_000.mUnk_94.mUnk_00[2] = buf;
        if (v1 != 0) {
            v5->x += (s32) (((s64) (v->x - v4->x - v5->x) * 0x148) >> 12);
            v5->z += (s32) (((s64) (v->z - v4->z - v5->z) * 0x148) >> 12);
        } else {
            v5->x = (s32) (((s64) v5->x * 0xc00) >> 12);
            v5->z = (s32) (((s64) v5->z * 0xc00) >> 12);
        }
        v3 = data_0216c6a8;
        v3.x = (s32) (((s64) v5->x * 0x3000) >> 12);
        v3.z = (s32) (((s64) v5->z * 0x3000) >> 12);
        buf = v3;
        func_020397a8(&buf, &p->mUnk_000.mUnk_94.mUnk_00[2], &p->mUnk_000.mUnk_94.mUnk_00[0]);
        if ((s64) p->mUnk_000.mUnk_94.mUnk_00[0].x * p->mUnk_000.mUnk_94.mUnk_00[0].x +
                (s64) p->mUnk_000.mUnk_94.mUnk_00[0].y * p->mUnk_000.mUnk_94.mUnk_00[0].y +
                (s64) p->mUnk_000.mUnk_94.mUnk_00[0].z * p->mUnk_000.mUnk_94.mUnk_00[0].z >=
            0x10) {
            ok = func_02039860(&p->mUnk_000.mUnk_94.mUnk_00[0], &p->mUnk_000.mUnk_94.mUnk_00[0]);
        } else {
            ok = 0;
        }
        if (ok == 0) {
            Vec3 t = {0, 0, 0};
            t.x = p->mUnk_000.mUnk_94.mUnk_00[0].z;
            t.z = -p->mUnk_000.mUnk_94.mUnk_00[0].x;
            p->mUnk_000.mUnk_94.mUnk_00[0] = t;
        }
    }
    func_020397a8(&p->mUnk_000.mUnk_94.mUnk_00[2], &p->mUnk_000.mUnk_94.mUnk_00[0], &p->mUnk_000.mUnk_94.mUnk_00[1]);
    *v4 = *v;
}

void func_020fc2c0(Unk020fc2e8 *a) {
    func_02046b40(a->mUnk_2e8);
    func_020f9320(&a->mUnk_000, (u32) 0x3c000400u);
}

#pragma thumb off

void func_020fc268(Unk020fc2e8 *param_1) {
    func_020f2228((Unk020f1d70 *) param_1, 0xd000);
    if (param_1->mUnk_000.mFlags & 1) {
        return;
    }
    func_0210b7ec(&param_1->mUnk_300, param_1->mUnk_000.mUnk_d4 & ~0xc000001f);
    if (param_1->mUnk_270 == 1) {
        return;
    }
    func_02109078(&param_1->mUnk_000.mUnk_00, param_1->mUnk_270, 0x7f, 0);
}

static inline Vec3 *func_020fbd98_inline(Unk020fc2e8 *p) {
    if (p->mUnk_2f6 >= 3) {
        if (p->mUnk_228->mKart->mUnk_48 & 1) {
            return &p->mUnk_228->mKart->mUnk_244;
        }
    } else if (p->mUnk_000.mFlags & 0x40000000) {
        return &p->mUnk_000.mUnk_f0;
    }
    return NULL;
}

void func_020fbd98(Unk020fc2e8 *param_1) {
    u32 i;
    s32 r;
    s32 v;
    void *q;
    Kart *p;

    if (param_1->mUnk_2ec == 8) {
        param_1->mUnk_26c = func_0208ec64((u32) param_1->mUnk_000.mUnk_d0);
    }
    func_020ec918((Unk020ec8bc *) param_1, param_1->mUnk_27c, 0x21, param_1->mUnk_276, 1);
    if (!(param_1->mUnk_000.mFlags & 1)) {
        func_0210b7ec(&param_1->mUnk_300, param_1->mUnk_000.mUnk_d4 & ~0xc000001f);
        if (param_1->mUnk_270 != 1) {
            func_02109078(&param_1->mUnk_000.mUnk_00, param_1->mUnk_270, 0x7f, 0);
        }
    }
    param_1->mUnk_000.mVelocity.y -= (s32) (((s64) * (s32 *) param_1->mUnk_12c * 0x66) >> 12);
    if (param_1->mUnk_000.mFlags & 1) {
        return;
    }
    func_020fc654(param_1);
    q = func_020fbd98_inline(param_1);
    func_020fc2e8(param_1, &param_1->mUnk_000.mVelocity, 1, q);
    if (param_1->mUnk_278 == 0) {
        if (gRaceProgress->mRaceDone != 0) {
            param_1->mUnk_274 = 1;
            param_1->mUnk_276 = gRaceProgress->mKartAtRank[(u8) param_1->mUnk_274 - 1];
        } else {
            param_1->mUnk_276 = gRaceProgress->mKartAtRank[(u8) param_1->mUnk_274 - 1];
            while (IsKartEnded(param_1->mUnk_276) != 0 && (u32) param_1->mUnk_274 < (u8) data_021759c0->mKartCount) {
                (param_1->mUnk_274)++;
                param_1->mUnk_276 = gRaceProgress->mKartAtRank[(u8) param_1->mUnk_274 - 1];
            }
        }
        if (param_1->mUnk_276 ==
                (u16) (!(param_1->mUnk_000.mUnk_78 & 0x8000) ? (u16) (param_1->mUnk_000.mUnk_78 & ~0xff00) : 8) ||
            func_02068eac(GetKart(param_1->mUnk_276)) != 0) {
            param_1->mUnk_278 = 1;
        } else {
            param_1->mUnk_280 |= 1 << param_1->mUnk_276;
        }
    }
    if (param_1->mUnk_278 != 0) {
        u32 n;
        n = (u8) data_021759c0->mKartCount;
        for (i = 1; i <= n; i = (u16) (i + 1)) {
            param_1->mUnk_276 = gRaceProgress->mKartAtRank[(u8) i - 1];
            if (func_02068eac(GetKart(param_1->mUnk_276)) == 0) {
                break;
            }
        }
        param_1->mUnk_280 |= 1 << param_1->mUnk_276;
    }
    if (func_020fcbb8(param_1, param_1->mUnk_276) != 0) {
        p = param_1->mUnk_228->mKart;
        r = ((param_1->mUnk_000.mFlags & 0x40000000) || (p->mUnk_48 & 1)) ? 2 : 3;
        param_1->mUnk_2f8 = r;
        param_1->mUnk_2fa = 1;
        if (param_1->mUnk_000.mFlags & 0x8000000) {
            func_020fe71c(5, param_1->mUnk_228->mKartIndex, param_1->mUnk_000.mId);
        }
        return;
    }
    r = (u16) func_02061f90();
    if ((param_1->mUnk_280 & (1 << r)) != 0 && param_1->mUnk_276 != r && IsKartEnded(r) != 0 &&
        func_020fcbb8(param_1, r) != 0) {
        p = param_1->mUnk_228->mKart;
        v = ((param_1->mUnk_000.mFlags & 0x40000000) || (p->mUnk_48 & 1)) ? 2 : 3;
        param_1->mUnk_2f8 = v;
        param_1->mUnk_2fa = 1;
        if (param_1->mUnk_000.mFlags & 0x8000000) {
            func_020fe71c(5, param_1->mUnk_228->mKartIndex, param_1->mUnk_000.mId);
        }
        return;
    }
    if (param_1->mUnk_2ec <= 0xa8c) {
        return;
    }
    v = (u16) gRaceProgress->mKartAtRank[0];
    if (param_1->mUnk_228 != NULL) {
        return;
    }
    if ((u32) v >= 8) {
        v = 0;
    }
    func_020fcb9c((s32) param_1, (u16) v);
    p = param_1->mUnk_228->mKart;
    r = ((param_1->mUnk_000.mFlags & 0x40000000) || (p->mUnk_48 & 1)) ? 2 : 3;
    param_1->mUnk_2f8 = r;
    param_1->mUnk_2fa = 1;
}

void func_020fbd4c(Unk020fc2e8 *param_1) {
    param_1->mUnk_27c = Vec3Length(&param_1->mUnk_000.mVelocity);
    param_1->mUnk_284 = 0x1e000;
    if (param_1->mUnk_228->mKartIndex == data_021759c0->mEntryIndex) {
        param_1->mUnk_270 = 0xdd;
    }
}

void func_020fbc18(Unk020fc2e8 *param_1) {
    s32 r;
    void *q;
    Kart *p;

    p = param_1->mUnk_228->mKart;
    r = 0x800;
    if ((param_1->mUnk_000.mFlags & 0x10000000) && (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        r += 0x19a;
    }
    if (param_1->mUnk_27c > 0xd000) {
        param_1->mUnk_27c -= 0xccd;
    } else {
        param_1->mUnk_27c += 0xccd;
    }
    func_020fcedc(param_1, r, param_1->mUnk_27c, param_1->mUnk_284);
    if (!(param_1->mUnk_000.mFlags & 1)) {
        func_0210b7ec(&param_1->mUnk_300, param_1->mUnk_000.mUnk_d4 & ~0xc000001f);
        if (param_1->mUnk_270 != 1) {
            func_02109078(&param_1->mUnk_000.mUnk_00, param_1->mUnk_270, 0x7f, 0);
        }
    }
    if ((s64) param_1->mUnk_238.x * param_1->mUnk_238.x + (s64) param_1->mUnk_238.z * param_1->mUnk_238.z <
        0x1900000000LL) {
        param_1->mUnk_2f8 = 4;
        param_1->mUnk_2fa = 1;
    }
    func_020fc654(param_1);
    q = func_020fbd98_inline(param_1);
    func_020fc2e8(param_1, &param_1->mUnk_000.mVelocity, 1, q);
}

void func_020fbae0(Unk020fc2e8 *param_1) {
    s32 i;
    void *q;
    Unk020f371c *p;

    if (param_1->mUnk_27c > 0xd000) {
        param_1->mUnk_27c -= 0xccd;
    } else {
        param_1->mUnk_27c += 0xccd;
    }
    func_020ec918((Unk020ec8bc *) param_1, param_1->mUnk_27c, 0x21, param_1->mUnk_276, 1);
    if (!(param_1->mUnk_000.mFlags & 1)) {
        func_0210b7ec(&param_1->mUnk_300, param_1->mUnk_000.mUnk_d4 & ~0xc000001f);
        if (param_1->mUnk_270 != 1) {
            func_02109078(&param_1->mUnk_000.mUnk_00, param_1->mUnk_270, 0x7f, 0);
        }
    }
    if (param_1->mUnk_000.mFlags & 1) {
        return;
    }
    func_020fc654(param_1);
    q = func_020fbd98_inline(param_1);
    func_020fc2e8(param_1, &param_1->mUnk_000.mVelocity, 1, q);
    p = param_1->mUnk_228->mUnk_1f0.mUnk_00;
    for (i = 0; i < 4; i++) {
        if (p == param_1->mUnk_168) {
            param_1->mUnk_2f8 = 3;
            param_1->mUnk_2fa = 1;
        }
        p = p->mUnk_00[0];
    }
}

void func_020fba6c(Unk020fc2e8 *param_1) {
    param_1->mUnk_264 = 0x5000;
    param_1->mUnk_288 = 0x3e8;
    Vec3Sub(&param_1->mUnk_238, &param_1->mUnk_298, &param_1->mUnk_28c);
    if (param_1->mUnk_26c != 0) {
        func_0208eb10(param_1->mUnk_26c);
        param_1->mUnk_26c = 0;
    }
    if (param_1->mUnk_000.mFlags & 0x8000000) {
        func_020fe71c(5, param_1->mUnk_228->mKartIndex, param_1->mUnk_000.mId);
    }
}

void func_020fb7f8(Unk020fc2e8 *param_1) {
    Vec3 v;
    void *q;

    if (param_1->mUnk_27c > 0xd000) {
        param_1->mUnk_27c -= 0xccd;
    } else {
        param_1->mUnk_27c += 0xccd;
    }
    param_1->mUnk_260 -= 0xccd;
    param_1->mUnk_288 += 0x2d;
    if ((u32) param_1->mUnk_25c < 0x8000) {
        param_1->mUnk_284 -= 0x666;
    } else {
        param_1->mUnk_284 -= 0xccd;
    }
    func_020fce94(param_1, 0x4cd, param_1->mUnk_27c, param_1->mUnk_284, param_1->mUnk_288);
    if (!(param_1->mUnk_000.mFlags & 1)) {
        func_0210b7ec(&param_1->mUnk_300, param_1->mUnk_000.mUnk_d4 & ~0xc000001f);
        if (param_1->mUnk_270 != 1) {
            func_02109078(&param_1->mUnk_000.mUnk_00, param_1->mUnk_270, 0x7f, 0);
        }
    }
    func_020fc654(param_1);
    if ((u32) param_1->mUnk_25c < 0x11f40) {
        q = func_020fbd98_inline(param_1);
        if (q != NULL) {
            v.x = param_1->mUnk_250.x * 2;
            v.y = param_1->mUnk_250.y * 2;
            v.z = param_1->mUnk_250.z * 2;
            func_020397a8(q, &v, &v);
            Vec3AddScaled((s32) (((s64) (param_1->mUnk_25c - 0x10000) * 0xccd) >> 12), q, &v, &v);
        } else {
            v.x = (s32) (((s64) param_1->mUnk_250.z * 0x2000) >> 12);
            v.y = (s32) (((s64) (param_1->mUnk_25c - 0x10000) * 0xccd) >> 12);
            v.z = -(s32) (((s64) param_1->mUnk_250.x * 0x2000) >> 12);
        }
        if (param_1->mUnk_2ec == 0) {
            Vec3Sub(&v, &param_1->mUnk_298, &param_1->mUnk_28c);
        }
        func_020fc2e8(param_1, &v, 1, q);
        return;
    }
    param_1->mUnk_2f8 = 5;
    param_1->mUnk_2fa = 1;
}

void func_020fb770(Unk020fc2e8 *param_1) {
    enum { K0 } k;

    if (param_1->mUnk_000.mUnk_d0 == &param_1->mUnk_000.mUnk_0c4) {
        param_1->mUnk_000.mPos = param_1->mUnk_000.mUnk_0c4;
        param_1->mUnk_000.mUnk_d0 = &param_1->mUnk_000.mPos;
    }
    param_1->mUnk_260 = 0x28000;
    param_1->mUnk_264 = 0x333;
    k = param_1->mUnk_000.mKind;
    param_1->mUnk_000.mUnk_100 = gItemKinds[k].mUnk_74;
    param_1->mUnk_000.mFlags |= 0x800000;
    param_1->mUnk_2a4 = param_1->mUnk_28c;
    param_1->mUnk_27c = 0x3000;
    param_1->mUnk_284 = 0x59a;
}

void func_020fb61c(Unk020fc2e8 *param_1) {
    Vec3 v;
    Vec3 *q;
    s32 x;
    s32 y;
    s32 z;

    param_1->mUnk_260 += 0x4cd;
    func_020fcce4(param_1, param_1->mUnk_264, param_1->mUnk_260);
    if ((s32) param_1->mUnk_264 < 0xb33) {
        param_1->mUnk_264 += 0x52;
    }
    if (param_1->mUnk_260 > 0x2d000) {
        param_1->mUnk_2f8 = 6;
        param_1->mUnk_2fa = 1;
    }
    param_1->mUnk_27c -= 0xa14;
    param_1->mUnk_284 -= 0x102;
    if (param_1->mUnk_284 < 0x7b) {
        param_1->mUnk_284 = 0x7b;
    }
    q = func_020fbd98_inline(param_1);
    if (q != NULL) {
        Vec3AddScaled(param_1->mUnk_27c, q, &param_1->mUnk_22c, &v);
    } else {
        z = param_1->mUnk_22c.z;
        y = param_1->mUnk_27c;
        x = param_1->mUnk_22c.x;
        v.x = x;
        v.y = y;
        v.z = z;
    }
    Vec3Sub(&v, &param_1->mUnk_2a4, &v);
    Vec3AddScaled(param_1->mUnk_284, &v, &param_1->mUnk_2a4, &param_1->mUnk_2a4);
    func_020fc2e8(param_1, &param_1->mUnk_2a4, 0, q);
}

void func_020fb5dc(Unk020fc2e8 *param_1) {
    enum { K0 } k;

    param_1->mUnk_260 = 0x28000;
    k = param_1->mUnk_000.mKind;
    param_1->mUnk_000.mUnk_100 = gItemKinds[k].mUnk_74;
    param_1->mUnk_000.mUnk_100 += 0x800;
    func_020f9c6c(&param_1->mUnk_000);
}

void func_020fb46c(Unk020fc2e8 *param_1) {
    s32 r;
    Vec3 v;

    param_1->mUnk_260 -= 0x7000;
    func_020fcce4(param_1, 0xb33, param_1->mUnk_260);
    if (param_1->mUnk_260 < -0x32000) {
        func_020f7104(&param_1->mUnk_000, 0);
        if (param_1->mUnk_000.mFlags & 0x8000000) {
            func_020fe71c(5, param_1->mUnk_228->mKartIndex, param_1->mUnk_000.mId);
        }
    } else {
        Vec3 *pv;

        pv = &param_1->mUnk_000.mPos;
        if (func_01ffdee4(pv, &param_1->mUnk_000.mPrevPos, 0, param_1->mUnk_000.mUnk_dc, 4, param_1->mUnk_000.mUnk_da,
                          &v, NULL, NULL, &param_1->mUnk_000.mUnk_fc, NULL, NULL, NULL, NULL) != 0) {
            Vec3Add(&v, pv, pv);
            func_020f7104(&param_1->mUnk_000, 0);
            if (param_1->mUnk_000.mFlags & 0x8000000) {
                func_020fe71c(5, param_1->mUnk_228->mKartIndex, param_1->mUnk_000.mId);
            }
        }
    }
    r = func_020fa0b8(param_1, gItemKinds[param_1->mUnk_000.mKind].mUnk_74,
                      gItemKinds[param_1->mUnk_000.mKind].mUnk_78);
    if (func_020f9ce8(&param_1->mUnk_000) != 0) {
        return;
    }
    if (r) {
        func_020fa030(&param_1->mUnk_000);
    }
}

void func_020fb35c(Unk020fc2e8 *param_1) {
    Unk0212c400 **p;
    struct Unk0208e490 *q;
    s32 *v;

    param_1->mUnk_000.mFlags |= 0x800000;
    param_1->mUnk_000.mUnk_100 = 0;
    param_1->mUnk_000.mUnk_68 = data_02159d84;
    param_1->mUnk_2b0 = func_0208e490(1, &param_1->mUnk_000.mPos, func_020f9160(&param_1->mUnk_000) == 0 ? 1 : 0);
    q = param_1->mUnk_2b0;
    if (q != NULL) {
        v = q->mUnk_9c;
        v[0] = 0x1000;
        v[1] = 0x1000;
        v[2] = 0x1000;
    }
    func_020f91fc(param_1, 0xdf);
    if (data_0217c780 & 1) {
        p = func_0210e128(func_02108ea0(0));
        if (data_0217d084.mUnk_0c != 0) {
            if (*p != NULL) {
                func_0212c6f0(p, 0);
            }
            if (*p != NULL) {
                func_0212c6f0(p, 0);
            }
            func_0212ecc0(p, 0, 0xe0);
        }
    }
    func_02073fb0(param_1->mUnk_000.mUnk_d4 & ~0xc000001f, 0x1000);
}

void func_020fb2b4(Unk020fc2e8 *param_1) {
    u32 v;

    v = param_1->mUnk_2ec;
    if (func_020fa0b8(param_1, data_0217bd3c, data_0217bd44)) {
        func_020f9fa8(&param_1->mUnk_000);
    }
    if (v < 0x16) {
        return;
    }
    if (v == 0x16) {
        param_1->mUnk_2e4 = 1;
    } else if (v == 0x2a) {
        func_020f9c40((s32) param_1);
    }
    if (v <= 0x55) {
        return;
    }
    ReleaseItemPoolObject(&gItemPools[param_1->mUnk_000.mKind], &param_1->mUnk_000);
}

void *func_020fb208(void *param_1, Unk020fc2e8 *param_2, void *param_3) {
    void *r;
    void *t;

    if (param_2 != NULL && param_3 != NULL) {
        func_020ff1b8(func_02039828(&param_2->mUnk_000.mVelocity, (Vec3 *) &param_2->mUnk_130) < 0 ? 1 : 0,
                      &param_2->mUnk_000.mVelocity.y);
    }
    t = func_020fecdc(param_1, param_2, param_3);
    r = func_020ff040(t, param_2 != NULL ? (void *) &param_2->mUnk_21c : 0, param_3);
    if (param_2 != NULL && param_3 == NULL) {
        func_020ff1a0(param_2->mUnk_000.mVelocity.y, &param_2->mUnk_2fc);
    }
    if (param_2 != NULL && param_3 != NULL) {
        return func_020fe8ac(param_2->mUnk_000.mKind);
    }
    return r;
}

void func_020fb038(Unk020fc2e8 *param_1) {
    s32 v;
    Unk020fb038 s;
    Kart *q;
    s32 r;

    func_020f8e78(param_1);
    if (param_1->mUnk_21c != 0) {
        func_020ec8bc((Unk020ec8bc *) param_1, 0x14, 0xcc, 1, 0, param_1->mUnk_2fc, (u16) gRaceProgress->mKartAtRank[0],
                      1);
        func_02046bcc(&param_1->mUnk_2e8, 1);
    } else if (param_1->mUnk_000.mFlags & 0x8000000) {
        v = (u16) gRaceProgress->mKartAtRank[0];
        if (param_1->mUnk_228 == NULL) {
            func_020fcb9c((s32) param_1, v);
            q = param_1->mUnk_228->mKart;
            r = ((param_1->mUnk_000.mFlags & 0x40000000) || (q->mUnk_48 & 1)) ? 2 : 3;
            param_1->mUnk_2f8 = r;
            param_1->mUnk_2fa = 1;
        }
    } else {
        v = (u16) gRaceProgress->mKartAtRank[0];
        func_020fcb9c((s32) param_1, v);
        q = param_1->mUnk_228->mKart;
        r = ((param_1->mUnk_000.mFlags & 0x40000000) || (q->mUnk_48 & 1)) ? 2 : 3;
        param_1->mUnk_2f8 = r;
        param_1->mUnk_2fa = 1;
        if (param_1->mUnk_000.mFlags & 0x8000000) {
            func_020fe71c(5, param_1->mUnk_228->mKartIndex, param_1->mUnk_000.mId);
        }
    }
    func_020fc94c(param_1);
    if ((s64) param_1->mUnk_000.mVelocity.x * param_1->mUnk_000.mVelocity.x +
            (s64) param_1->mUnk_000.mVelocity.y * param_1->mUnk_000.mVelocity.y +
            (s64) param_1->mUnk_000.mVelocity.z * param_1->mUnk_000.mVelocity.z >=
        0x10) {
        func_02039860(&param_1->mUnk_000.mVelocity, &s.mUnk_00);
    }
    func_020d7b88((Vec3 *) &s.mUnk_00, &s.mUnk_0c);
    func_01ffccd0(&param_1->mUnk_000.mUnk_94, &s.mUnk_0c);
}

void func_020faed0(Unk020fc2e8 *param_1, s32 param_2, s32 param_3) {
    u32 n;
    Vec3 v;
    void *q;

    if (param_1->mUnk_000.mFlags & 0x2000) {
        if (func_020f91c4(&param_1->mUnk_000, 0x6a4) != 0) {
            return;
        }
    }
    v.x = v.z = param_1->mUnk_000.mUnk_68.x;
    v.y = param_1->mUnk_000.mUnk_68.y;
    if (param_1->mUnk_000.mUnk_d8 != 0x1f) {
        u32 i;
        Unk0201290c *o;

        o = data_0217bd38->mUnk_004;
        n = (u16) param_1->mUnk_000.mUnk_d8;
        for (i = 0; i < o->mEntryCount; i++) {
            func_02013468(o, i, n);
        }
    }
    if (param_1->mUnk_000.mFlags & 0x80000) {
        q = func_020ed98c(&param_1->mUnk_000, (Vec3 *) param_2);
    } else {
        Vec3 *pv;

        pv = param_1->mUnk_000.mUnk_d0;
        param_1->mUnk_000.mUnk_94.mUnk_00[3].x = pv->x >> 4;
        param_1->mUnk_000.mUnk_94.mUnk_00[3].y = pv->y >> 4;
        param_1->mUnk_000.mUnk_94.mUnk_00[3].z = pv->z >> 4;
        q = &param_1->mUnk_000.mUnk_94;
    }
    func_020ea8a8(data_0217bd38, q, &v, 0x1f);
    if (param_1->mUnk_000.mUnk_d8 == 0x1f) {
        return;
    }
    {
        u32 i;
        Unk0201290c *o;

        o = data_0217bd38->mUnk_004;
        for (i = 0; i < o->mEntryCount; i++) {
            func_02013468(o, i, 0x1f);
        }
    }
}

void func_020fae74(Unk020fc2e8 *param_1, s32 param_2, s32 param_3) {
    Unk0208e490 *q;

    if (param_1->mUnk_2f6 != 7) {
        func_020faed0(param_1, param_2, param_3);
        return;
    }
    q = param_1->mUnk_2b0;
    if (q == NULL) {
        return;
    }
    q->mUnk_b4 = (param_1->mUnk_000.mFlags & 0x10000) == 0;
}

s32 func_020fade4(Unk020fc2e8 *param_1) {
    if (param_1->mUnk_2f6 != 7) {
        func_02046be8(&param_1->mUnk_2e8, (UnkFunc *const *) data_0216c6b4, 8, param_1);
        param_1->mUnk_2f8 = 7;
        param_1->mUnk_2fa = 1;
        if ((param_1->mUnk_000.mFlags & 0x180000) == 0) {
            param_1->mUnk_000.mUnk_120 = (void (*)(struct ItemObject *)) func_020fc2c0;
        }
        param_1->mUnk_000.mFlags &= ~0x8000;
        param_1->mUnk_000.mFlags |= 0x80000;
        func_020f9c6c(&param_1->mUnk_000);
        param_1->mUnk_000.mUnk_78 &= ~0x4000;
    }
    return 1;
}

BOOL func_020fadcc(Unk020fc2e8 *param_1) {
    return param_1->mUnk_2f6 == 7;
}

Vec3 *func_020fad9c(Unk020fc2e8 *param_1, s32 *param_2, s32 *param_3) {
    *param_2 = param_1->mUnk_2ec;
    *param_3 = (s32) (((s64) param_1->mUnk_000.mUnk_68.z * data_0217bd40) >> 12);
    return &param_1->mUnk_000.mPos;
}

#pragma thumb on

void func_020fad00(void) {
    s32 a;
    s32 b;
    s32 v;

    data_0217bd3c = 0x1e000;
    data_0217bd40 = DivFixed12(0x1000, data_0217bd3c);
    data_0217bd44 = 0x299a;
    a = data_0217bd3c;
    b = gItemKinds[5].mUnk_6c;
    v = (s32) (((s64) a * b) >> 12);
    data_0217bd34 = v;
    v >>= 12;
    data_0217bd34 = v;
    data_0217bd34 = v * v;
    data_0217bd38 = func_020ed490(data_0216c6f4, data_0216c704);
    if (data_021759c0->mCourseId == 0x1d) {
        func_02013044(data_0217bd38->mUnk_004, 0);
    }
}

#pragma thumb off

BOOL func_020faca4(s32 param_1) {
    if (param_1 != 0x13) {
        return gItemPools[gItemInfos[param_1].mObjectKind].mUnk_0c -
                   gItemPools[gItemInfos[param_1].mObjectKind].mReservedCount >=
               gItemInfos[param_1].mObjectCount;
    }
    return FALSE;
}

static inline BOOL func_020fab34_inline(s32 param_1) {
    if (param_1 != 0x13) {
        return gItemPools[gItemInfos[param_1].mObjectKind].mUnk_0c -
                   gItemPools[gItemInfos[param_1].mObjectKind].mReservedCount >=
               gItemInfos[param_1].mObjectCount;
    }
    return FALSE;
}

BOOL func_020fab34(s32 *param_1) {
    s32 i;
    s32 v;
    ItemInfo *e;
    s32 n;

    i = *param_1;
    if (i == 0x13) {
        goto done;
    }
    if (data_021759c0->mMode == 5) {
        e = &gItemInfos[i];
        n = e->mObjectCount;
        v = n * func_020fa0e8(e->mObjectKind, 0);
        if (func_020fab34_inline(i) != FALSE && data_0217aa14->mUnk_724 >= v) {
            return FALSE;
        }
    } else {
        if (func_020fab34_inline(i) != FALSE) {
            return FALSE;
        }
    }
done:
    *param_1 = data_021759c0->mMode == 5 ? 4 : 2;
    return TRUE;
}

BOOL func_020faa78(s32 param_1) {
    ItemInfo *e;
    s32 n;
    ItemPool *r;
    enum { K0 } k;

    e = &gItemInfos[param_1];
    k = e->mObjectKind;
    r = &gItemPools[k];
    n = e->mObjectCount;
    while (r->mUnk_0c - r->mReservedCount < n) {
        if (gItemKinds[k].mLimit == 1) {
            return FALSE;
        }
        if (TryReleaseFirstItemObject(r) == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

void func_020fa9e4(void) {
    enum { K0 } i;
    u16 j;

    for (i = 0; i < 0xe; i++) {
        TryReleaseFirstItemObject(&gItemPools[i]);
    }
    for (j = 0; j < gKartItemsCount; j++) {
        func_020f0044(&(gKartItems)[j]);
    }
}

void UpdateItems(void) {
    enum { K0 } i;
    u16 j;

    if (data_021759c0->mMode == 5) {
        func_020fec30();
        func_020feb44();
    }
    for (i = 0; i < 0xe; i++) {
        if (gItemPools[i].mActiveCount != 0) {
            UpdateItemPool(&gItemPools[i]);
        }
    }
    for (j = 0; j < gKartItemsCount; j++) {
        UpdateKartItems(&(gKartItems)[j]);
    }
    func_020f8258();
    func_02104368();
    func_02104ff8();
}

void func_020fa8ac(void *a) {
    enum { K0 } i;
    void *q;

    q = &((Unk020e6b38 *) func_020e6b38())->mUnk_18;
    func_020e6a74();
    for (i = 0; i < 0xe; i++) {
        if (gItemPools[i].mTakenCount > 0 && gItemPools[i].mUnk_40 == 0) {
            DrawItemPool(&gItemPools[i], q);
        }
    }
}

void func_020fa78c(s32 param_1, s32 param_2, s32 param_3) {
    s32 v;
    BOOL c;

    if ((gKartItems)[param_1].mHeldItem.mUnk_00 != 0x13) {
        return;
    }
    v = data_021759c0->mCurrentEntries[param_1].mPlayer.mKind;
    if (v == 3) {
        return;
    }
    if (data_021759c0->mMode == 2) {
        c = FALSE;
        if ((u32) v > 3) {
        } else if ((1 << v) & 0xd) {
            c = TRUE;
        }
        StartItemSlot(&(gKartItems)[param_1], param_2, func_020a1cd8(param_1), c ? 1 : 0, param_3);
    } else {
        c = FALSE;
        if ((u32) v > 3) {
        } else if ((1 << v) & 0xd) {
            c = TRUE;
        }
        StartItemSlot(&(gKartItems)[param_1], param_2, GetKartRank(param_1), c ? 1 : 0, param_3);
    }
}

static inline s32 func_020fa4c8_inline(ItemObject *e, Kart *a) {
    Vec3 b;
    Vec3 c;
    s32 d1;
    s32 d2;
    s32 r;
    s32 x;
    s64 f;

    if (!(e->mFlags & 0x8000)) {
        return 1;
    }
    if ((u16) a->mIndex != (u16) (!(e->mUnk_78 & 0x8000) ? (u16) (e->mUnk_78 & ~0xff00) : 8)) {
        return 1;
    }
    if (e->mVelocity.x != 0 || e->mVelocity.y != 0 || e->mVelocity.z != 0 || a->mForwardSpeed != 0) {
        Vec3Sub(&e->mPrevPos, &a->mUnk_1e4, &b);
        b.y = 0;
        Vec3Sub(&e->mPos, &a->mUnk_1d8, &c);
        c.y = 0;
        d1 = func_02039828(&b, &b);
        d2 = func_02039828(&c, &c);
        if (d1 - 0x1000 > d2) {
            return 1;
        }
    }
    r = e->mUnk_e0;
    x = e->mPos.x - a->mUnk_1d8.x;
    f = (s64) (e->mPos.z - a->mUnk_1d8.z) * (e->mPos.z - a->mUnk_1d8.z) +
        ((s64) x * x + (s64) (e->mPos.y - a->mUnk_1d8.y) * (e->mPos.y - a->mUnk_1d8.y));
    return f < (s64) r * r ? 1 : 0;
}

s32 func_020fa4c8(Kart *param_1) {
    s32 i;
    s32 n;
    BOOL fl;
    s32 v;
    s32 lim;
    ItemObject *e;
    enum { K0 } k;

    n = 0;
    fl = (param_1->mUnk_48 & 0x8000000) != 0;
    lim = 0xf;
    for (i = 0; i < data_0217b5a8; i++) {
        if (!(data_0217b5bc[i] & 0x4000)) {
            continue;
        }
        e = data_0217b5c4[i];
        if (fl && !(e->mFlags & 0x200000)) {
            continue;
        }
        if (!func_020f97e0(e, param_1)) {
            continue;
        }
        v = func_020fa4c8_inline(e, param_1);
        if (v == 0) {
            continue;
        }
        if ((param_1->mUnk_7c & 0x2000) && func_020f9880(e) != 0) {
            continue;
        }
        data_0217bd30[n++] = e;
        if (e->mFlags & 0x1000) {
            func_020eda5c(&(gKartItems)[(u16) (e->mUnk_78 & ~0xff00)].mItemInUse, e);
        }
        k = e->mKind;
        if (gItemKinds[k].mUnk_88 != 0) {
            if (func_020f9880(e) != 0) {
                func_020f6be8(e, &param_1->mUnk_1b8, &param_1->mVelocity, &param_1->mUnk_05c);
                func_020f6f10(e, 1, (u16) param_1->mIndex);
            } else {
                func_020f7430(e, 1);
            }
        }
        if (n >= 0x10) {
            n = lim;
        }
    }
    return n;
}

#pragma thumb on

#pragma thumb off

struct ItemObject *func_020fa4b4(u32 arg0) {
    return data_0217bd30[arg0];
}

#pragma thumb off

void *StartItemObjectOrZero(s32 param_1, u16 param_2, void *param_3, void *param_4) {
    ItemObject *p;
    ItemPool *e;

    p = 0;
    if (gItemPools[param_1].mLimit - gItemPools[param_1].mReservedCount <= 0) {
        return 0;
    }
    func_020f1048(&gItemPools[param_1], 1, (ItemObject **) &p, param_2, param_3);
    e = &gItemPools[param_1];
    e->mReservedCount++;
    StartItemObject(&gItemPools[p->mKind], p);
    func_020f98a0(p, param_3, param_4, 0, 0);
    if (param_2 == 8) {
        p->mUnk_78 |= data_02159cbc;
    }
    return p;
}

#pragma thumb on

static inline ItemObject *func_020fa3d0_inline(s32 param_1, u16 param_2, void *param_3, void *param_4) {
    ItemObject *p;
    ItemPool *e;

    p = 0;
    if (gItemPools[param_1].mLimit - gItemPools[param_1].mReservedCount <= 0) {
        return 0;
    }
    func_020f1048(&gItemPools[param_1], 1, (ItemObject **) &p, param_2, param_3);
    e = &gItemPools[param_1];
    e->mReservedCount++;
    StartItemObject(&gItemPools[p->mKind], p);
    func_020f98a0(p, param_3, param_4, 0, 0);
    if (param_2 == 8) {
        p->mUnk_78 |= data_02159cbc;
    }
    return p;
}

void func_020fa294(void) {
    u32 i;
    u32 n;
    u32 v;
    ItemObject *p;
    Vec3 m;
    enum { K0 } k;
    CourseMapRow *e;

    n = gCourseMap->mRowCount;
    for (i = 0; i < n; i++) {
        e = &gCourseMap->mRows[i];
        if (e->mUnk_24 == 0x6d) {
            k = e->mUnk_28;
            if (func_01ffdee4(e, 0, 0, 0xa000, 8, -2, 0, &m, 0, 0, 0, 0, 0, &v) == 0) {
                m = data_02159cb0;
            }
            p = func_020fa3d0_inline(k, 8, e, &m);
            if (p != 0) {
                void (*t)(ItemObject *);

                k = p->mKind;
                t = gItemKinds[k].mUnk_28;
                if ((p->mFlags & 0x180000) == 0) {
                    p->mUnk_120 = t;
                }
                func_020f6a6c(p, &v);
            }
        }
    }
}

void InitItems(void) {
    void *b;
    s32 a;
    s32 i;
    enum { K0 } j;
    Unk020f40dc *p;
    u8 v;

    b = GetHeap(func_020364e8());
    a = 0;
    CreateItemSlotTables();
    func_020f82e8(1);
    func_020f82c4(1);
    func_020f82a4(1);
    CreateItemInfos();
    InitItemKinds();
    func_020f73a4();
    func_020f357c();
    v = data_021759c0->mKartCount;
    gKartItemsCount = v;
    (void *) gKartItems = HeapAlloc(b, v * 0x210);
    for (i = 0; i < gKartItemsCount; i++) {
        InitKartItems(&(gKartItems)[i], (u16) i);
    }
    gItemPools = HeapAlloc(b, 0x3b8);
    for (j = 0; j < 0xe; j++) {
        CreateItemPool(&gItemPools[j], j, &a);
    }
    CreateItemModels();
    if (data_021759c0->mMode == 5) {
        func_020fe46c();
        func_020fe450();
    }
    if (data_021759c0->mMode == 1) {
        for (i = 0; i < gKartItemsCount; i++) {
            p = &(gKartItems)[i].mHeldItem;
            func_020f47e4(p, 5);
            switch (func_02079b40((u16) i)) {
                case 0:
                    func_020f4754(p, 1);
                    break;
                case 1:
                    func_020f4754(p, 2);
                    break;
            }
        }
    }
    data_0217bd30 = HeapAlloc(GetHeap(func_020364e8()), 0x40);
    func_020fa294();
    func_02102674();
    func_02103468();
    func_02104970();
}

s32 func_020fa0e8(s32 param_1, s32 param_2) {
    switch (param_2) {
        case 0:
            return (u8) ((u8) gItemKinds[param_1].mUnk_4c + 1);
        case 1:
            return 0x12;
        case 2:
            return 3;
        case 3:
            return (u8) ((param_1 == 0xb ? 3 : 2) + 1);
    }
    return 0;
}

#pragma thumb off

s32 func_020fa0b8(void *param_1, s32 param_2, s32 param_3) {
    ItemObject *p = param_1;

    if (p->mUnk_68.z < param_2) {
        p->mUnk_68.z += param_3;
        if (p->mUnk_68.z > param_2) {
            p->mUnk_68.z = param_2;
        }
        return 1;
    }
    return 0;
}

void func_020fa030(ItemObject *param_1) {
    ItemKind *e;
    enum { K0 } k;
    s32 m;

    k = param_1->mKind;
    param_1->mFlags |= 0x40;
    param_1->mUnk_68.y = param_1->mUnk_68.z;
    param_1->mUnk_68.x = param_1->mUnk_68.y;
    e = &gItemKinds[k];
    m = e->mUnk_6c;
    param_1->mUnk_dc = (s32) (((s64) param_1->mUnk_68.y * e->mUnk_64) >> 12);
    param_1->mUnk_e0 = (s32) (((s64) param_1->mUnk_68.y * m) >> 12);
    func_020d5148(param_1->mUnk_da, param_1->mUnk_e0 + 0xa000);
}

void func_020f9fa8(ItemObject *param_1) {
    ItemKind *e;
    enum { K0 } k;
    s32 m;

    k = param_1->mKind;
    param_1->mFlags |= 0x40;
    param_1->mUnk_68.y = param_1->mUnk_68.z;
    param_1->mUnk_68.x = param_1->mUnk_68.y;
    e = &gItemKinds[k];
    m = e->mUnk_6c;
    param_1->mUnk_dc = (s32) (((s64) param_1->mUnk_68.y * e->mUnk_64) >> 12);
    param_1->mUnk_e0 = (s32) (((s64) param_1->mUnk_68.y * m) >> 12);
    func_020d5148(param_1->mUnk_da, param_1->mUnk_e0);
}

void func_020f9f08(void *param_1, s32 param_2, s32 param_3) {
    ItemObject *p = param_1;
    enum { K0 } k;
    s32 m;

    k = p->mKind;
    m = gItemKinds[k].mUnk_68;
    p->mUnk_68.x = (s32) (((s64) p->mUnk_68.z * param_2) >> 12);
    p->mUnk_68.y = (s32) (((s64) p->mUnk_68.z * param_3) >> 12);
    p->mUnk_dc = (s32) (((s64) p->mUnk_68.y * gItemKinds[k].mUnk_64) >> 12);
    p->mUnk_e0 = (s32) (((s64) p->mUnk_68.y * m) >> 12);
    func_020d5148(p->mUnk_da, p->mUnk_e0 + 0xa000);
}

s32 func_020f9dc8(ItemObject *param_1) {
    ItemKind *e;
    enum { K0 } k;
    s32 m;

    if (param_1->mUnk_100 <= -0x29 || param_1->mUnk_100 >= 0x29 || param_1->mUnk_68.x - param_1->mUnk_68.y <= -0x29 ||
        param_1->mUnk_68.x - param_1->mUnk_68.y >= 0x29) {
        k = param_1->mKind;
        param_1->mFlags |= 0x40;
        param_1->mUnk_68.y += param_1->mUnk_100;
        param_1->mUnk_100 += (s32) (((s64) (param_1->mUnk_68.z - param_1->mUnk_68.y) * 0x333) >> 12);
        param_1->mUnk_100 = (s32) (((s64) param_1->mUnk_100 * 0xc00) >> 12);
        param_1->mUnk_68.x = param_1->mUnk_68.z * 2 - param_1->mUnk_68.y;
        e = &gItemKinds[k];
        m = e->mUnk_6c;
        param_1->mUnk_dc = (s32) (((s64) param_1->mUnk_68.y * e->mUnk_64) >> 12);
        param_1->mUnk_e0 = (s32) (((s64) param_1->mUnk_68.y * m) >> 12);
        func_020d5148(param_1->mUnk_da, param_1->mUnk_e0 + 0xa000);
        return 1;
    }
    param_1->mUnk_100 = 0;
    return 0;
}

s32 func_020f9ce8(ItemObject *param_1) {
    ItemKind *e;
    enum { K0 } k;
    s32 m;

    if (param_1->mUnk_100 != 0) {
        k = param_1->mKind;
        param_1->mFlags |= 0x40;
        param_1->mUnk_68.y += (s32) (((s64) (param_1->mUnk_100 - param_1->mUnk_68.y) * 0x333) >> 12);
        param_1->mUnk_68.x = param_1->mUnk_68.z * 2 - param_1->mUnk_68.y;
        e = &gItemKinds[k];
        m = e->mUnk_6c;
        param_1->mUnk_dc = (s32) (((s64) param_1->mUnk_68.y * e->mUnk_64) >> 12);
        param_1->mUnk_e0 = (s32) (((s64) param_1->mUnk_68.y * m) >> 12);
        func_020d5148(param_1->mUnk_da, param_1->mUnk_e0 + 0xa000);
        return 1;
    }
    return 0;
}

void func_020f9ca8(void *param_1) {
    ItemObject *p = param_1;

    if (p->mUnk_da != -1) {
        return;
    }
    p->mUnk_da = func_020d555c(&p->mPos, p->mUnk_e0 + 0xa000, 0x4000, p);
}

void func_020f9c6c(ItemObject *param_1) {
    if (param_1->mUnk_da != -1) {
        return;
    }
    param_1->mUnk_da = func_020d555c(&param_1->mPos, param_1->mUnk_e0, 0x4000, param_1);
}

#pragma thumb on
