#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_0207a104.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_020815a0.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02087934.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0208c4e8.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_02090354.h"
#include "Main/Unknown/code_020a02f8.h"
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
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_0203c5ac.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_02103840.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_02109184.h"
#include "Main/Unknown/code_0210a664.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0210fa40.h"
#include "Main/Unknown/code_021035ac.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "01/code_0218155c.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"

BOOL func_0206a24c(Kart *p) {
    Unk0206ceb4 *s;
    s32 v;

    s = &p->mUnk_538;
    if ((p->mUnk_4c & 0x10000040) || (p->mUnk_48 & 0x10000)) {
        return FALSE;
    }
    s->mUnk_0c = 0;
    s->mUnk_0e = 0x258;
    p->mUnk_41c.x = 0x1000;
    p->mUnk_41c.y = 0x1000;
    p->mUnk_41c.z = 0x1000;
    p->mUnk_3a4 = 0;
    p->mUnk_4c |= 0x10000;
    p->mUnk_48 |= 0x4000000;
    if (p->mUnk_7c & 1) {
        func_02074874(0x1f40);
    }
    p->mUnk_394 = 0xb33;
    func_020eff40(&(data_027e00c8)[p->mIndex]);
    v = data_021759c0->mMode;
    if (v == 4) {
        if (v == 4) {
            func_ov001_0218173c();
        }
    }
    if (!(p->mUnk_48 & 0x840)) {
        func_0210af40(p, p->mUnk_3cc, 0);
    }
    return TRUE;
}

void func_02069f6c(Kart *p) {
    Unk0206ceb4 *s;

    s = &p->mUnk_538;
    if (s->mUnk_0e <= 0) {
        if (s->mUnk_0c == 0) {
            func_021090c4(&p->mUnk_00, 0xed, 0x7f, 0);
        }
        s->mUnk_0c++;
        if (s->mUnk_0c >= 0x19) {
            p->mUnk_398 = 0x1000;
            p->mUnk_434 = 0x1000;
            p->mUnk_41c.x = 0x1000;
            p->mUnk_41c.y = 0x1000;
            p->mUnk_41c.z = 0x1000;
            p->mUnk_bc.x = (s32) (((s64) p->mUnk_428.x * p->mUnk_41c.x) >> 12);
            p->mUnk_bc.y = (s32) (((s64) p->mUnk_428.y * p->mUnk_41c.y) >> 12);
            p->mUnk_bc.z = (s32) (((s64) p->mUnk_428.z * p->mUnk_41c.z) >> 12);
            p->mUnk_bc.y = (s32) (((s64) p->mUnk_434 * p->mUnk_bc.y) >> 12);
            if (s->mUnk_0c > 0x19) {
                p->mUnk_4c &= ~0x10000;
                if (!(p->mUnk_4c & 0x10080)) {
                    p->mUnk_394 = 0x1000;
                }
                return;
            }
            p->mUnk_4c |= 0x100;
            return;
        }
        p->mUnk_398 = 0x1000;
        p->mUnk_4c |= 0x100;
        p->mUnk_41c.x = data_usa_02154de4[s->mUnk_0c];
        p->mUnk_41c.y = data_usa_02154e48[s->mUnk_0c];
        p->mUnk_41c.z = data_usa_02154eac[s->mUnk_0c];
        p->mUnk_434 = 0x1000;
        p->mUnk_bc.x = (s32) (((s64) p->mUnk_428.x * p->mUnk_41c.x) >> 12);
        p->mUnk_bc.y = (s32) (((s64) p->mUnk_428.y * p->mUnk_41c.y) >> 12);
        p->mUnk_bc.z = (s32) (((s64) p->mUnk_428.z * p->mUnk_41c.z) >> 12);
        p->mUnk_bc.y = (s32) (((s64) p->mUnk_434 * p->mUnk_bc.y) >> 12);
        return;
    }
    s->mUnk_0e--;
    if (s->mUnk_0e == 0x1c2) {
        p->mUnk_48 &= ~0x4000000;
        if (p->mUnk_7c & 1) {
            func_02074854();
        }
    }
    if (p->mUnk_48 & 0x4000000) {
        p->mUnk_2a8 = 0;
    }
    if ((float) p->mUnk_434 > 0.3f / 4096.0f) {
        p->mUnk_434 -= 0x4cd;
        if ((float) p->mUnk_434 < 0.3f / 4096.0f) {
            p->mUnk_434 = 0x4cd;
        }
    }
    p->mUnk_bc.x = (s32) (((s64) p->mUnk_428.x * p->mUnk_41c.x) >> 12);
    p->mUnk_bc.y = (s32) (((s64) p->mUnk_428.y * p->mUnk_41c.y) >> 12);
    p->mUnk_bc.z = (s32) (((s64) p->mUnk_428.z * p->mUnk_41c.z) >> 12);
    p->mUnk_bc.y = (s32) (((s64) p->mUnk_434 * p->mUnk_bc.y) >> 12);
}

void func_02069ea8(Kart *p) {
    p->mUnk_398 = 0x1000;
    p->mUnk_434 = 0x1000;
    p->mUnk_bc.y = 0x1000;
    p->mUnk_4c &= ~0x10000;
    if (p->mUnk_4c & 0x80) {
        p->mUnk_4c &= ~0x80;
        p->mUnk_428.x = 0x1000;
        p->mUnk_428.y = 0x1000;
        p->mUnk_428.z = 0x1000;
        if (p->mIndex == data_021759c0->mEntryIndex) {
            func_0210fa74(0);
        }
        func_0210a664(p);
    }
    p->mUnk_bc.x = 0x1000;
    p->mUnk_bc.y = 0x1000;
    p->mUnk_bc.z = 0x1000;
    p->mUnk_41c.x = 0x1000;
    p->mUnk_41c.y = 0x1000;
    p->mUnk_41c.z = 0x1000;
    if (!(p->mUnk_4c & 0x10080)) {
        p->mUnk_394 = 0x1000;
    }
    if (p->mUnk_7c & 1) {
        func_02074854();
    }
}

void func_02069e10(Kart *p) {
    u16 i;
    u32 w;

    i = 0;
    func_02061874();
    func_02082e4c(p->mIndex);
    w = p->mUnk_7c & 0x200;
    if (w != 0) {
        if (w != 0) {
            p->mUnk_514->mUnk_2c ^= 0x4000;
        }
        return;
    }
    for (; i < (u32) data_021759c0->mKartCount; i++) {
        if (i != p->mIndex) {
            func_0206a624(GetKart(i));
        }
    }
}

void func_02069db8(Kart *p) {
    func_0206d020(p, 0, 0x5a);
    p->mUnk_48 |= 0x100000;
    p->mUnk_538.mUnk_00 = 0x5a;
    if (data_021759c0->mMode != 2) {
        return;
    }
    func_020a1ddc(p->mIndex);
}

void func_02069c38(Kart *p) {
    Unk0206ceb4 *s;

    s = &p->mUnk_538;
    if (p->mUnk_4c & 0x10000000) {
        return;
    }
    if (p->mUnk_7c & 0x2000) {
        p->mUnk_7c &= ~0x2000;
        p->mUnk_7c &= ~0xc000;
        p->mUnk_29c = 0;
        if (!(p->mUnk_7c & 1)) {
            func_0208c4e8(func_0208c5b8(p->mIndex));
        } else {
            func_021090c4(&p->mUnk_00, 0xf9, 0x7f, 0);
        }
        func_0210fa40(0, (p->mUnk_7c & 1) ? 1 : 0);
    }
    if (p->mUnk_4c & 0x8000000) {
        p->mUnk_4c &= ~0x8020000;
        if (p->mUnk_4c & 0x2000) {
            func_0207b13c(p);
        }
        func_02079c0c(p->mKartModelsEntry);
    }
    func_02103840(p->mIndex);
    s->mUnk_06 = 0;
    p->mUnk_4c |= 0x40;
    p->mUnk_29c = 1;
    func_0207b284(p);
    func_02081a40(p->mIndex);
    if ((p->mUnk_7c & 1) && data_021759c0->mUnk_00c == 0) {
        func_02106e78();
    }
    if (data_021759c0->mMode == 2) {
        func_020a1e3c(p->mIndex);
    }
    if (p->mUnk_7c & 0x200) {
        p->mUnk_514->mUnk_2c ^= 0x2000;
    }
    func_02068a64(p, 2, 1);
}

void func_02069aa0(Kart *p) {
    Unk0206ceb4 *s;
    Unk0206ceb4 *t;
    u32 w;

    s = &p->mUnk_538;
    s->mUnk_10 = 0;
    if (p->mUnk_4c & 0x10000040) {
        p->mUnk_4c &= ~0x40;
        func_0207b1a8(p);
        p->mUnk_29c = 0;
        func_020817b8(p->mIndex);
        func_02068a64(p, 0, 1);
        if ((p->mUnk_7c & 1) && data_021759c0->mUnk_00c == 0) {
            func_02106dc8();
        }
        if (p->mUnk_4c & 0x2000) {
            func_0207b13c(p);
        }
    }
    p->mUnk_7c |= 0x2000;
    p->mUnk_29c = 2;
    func_02103840(p->mIndex);
    w = p->mUnk_4c;
    if (!(w & 0x20000) && (w & 0x8000000)) {
        t = &p->mUnk_538;
        if (t->mUnk_1c <= 0x190) {
            t->mUnk_1c = 0x190;
            p->mUnk_4c |= 0x20000;
            func_02079f70(p->mKartModelsEntry, func_0207a134(), func_0207a11c(), func_0207a104());
        }
    }
    func_0210fa40(1, (p->mUnk_7c & 1) ? 1 : 0);
    if (p->mUnk_7c & 1) {
        p->mUnk_7c |= 0x4000;
    } else {
        s->mUnk_12 = 2;
        s->mUnk_14 = 0;
        s->mUnk_18 = 10;
        s->mUnk_16 = 0;
        s->mUnk_1a = 1;
    }
    if (p->mUnk_7c & 0x200) {
        p->mUnk_514->mUnk_2c ^= 0x4000000;
    }
}

void func_0206988c(Kart *p) {
    Unk0206ceb4 *s;
    Vec3 a;
    Vec3 b;
    u32 w;
    s32 d;
    s32 e;
    s32 f;

    w = p->mUnk_7c;
    if (w & 0x400000) {
        return;
    }
    s = &p->mUnk_538;
    if (!(w & 1)) {
        if (s->mUnk_16 < 0x50) {
            s->mUnk_16++;
            s->mUnk_14++;
            if (s->mUnk_14 > s->mUnk_18) {
                s->mUnk_14 = 0;
                s->mUnk_12 = s->mUnk_12 + s->mUnk_1a;
                s->mUnk_18 = s->mUnk_18 + s->mUnk_1a * 5;
            }
            if (s->mUnk_16 % s->mUnk_12 == 0) {
                p->mUnk_7c &= ~0x8000;
            } else {
                p->mUnk_7c |= 0x8000;
            }
            if (s->mUnk_16 >= 0x50) {
                p->mUnk_7c |= 0x8000;
            }
        }
        if (s->mUnk_10 == 0x172) {
            s->mUnk_1a = -1;
            s->mUnk_16 = 0;
        }
        func_0208c504((u32) func_0208c5b8(p->mIndex));
    }
    s->mUnk_10++;
    if (s->mUnk_10 > 0x1c2 && (p->mUnk_7c & 0x2000)) {
        p->mUnk_7c &= ~0x2000;
        p->mUnk_7c &= ~0xc000;
        p->mUnk_29c = 0;
        if (!(p->mUnk_7c & 1)) {
            func_0208c4e8(func_0208c5b8(p->mIndex));
        } else {
            func_021090c4(&p->mUnk_00, 0xf9, 0x7f, 0);
        }
        func_0210fa40(0, (p->mUnk_7c & 1) ? 1 : 0);
    }
    if (p->mUnk_7c & 1) {
        return;
    }
    func_0207a948(&a, (u16) data_021759c0->mEntryIndex);
    func_0207a948(&b, p->mIndex);
    d = (a.x - b.x) >> 12;
    e = (a.y - b.y) >> 12;
    f = (a.z - b.z) >> 12;
    func_0207a2d4(d * d + e * e + f * f);
}

void func_020695c4(Kart *p) {
    Unk0206ceb4 *s;
    Unk0216557c w;
    Unk02165560 v;
    s32 i;
    u8 k;

    w = data_usa_0216557c;
    s = &p->mUnk_538;
    s->mUnk_1e = 0;
    s->mUnk_20 = 0;
    s->mUnk_24 = 0;
    func_0209086c(&s->mUnk_2c, p->mIndex);
    p->mUnk_4c |= 0x10000000;
    k = data_021759c0->mKartCount;
    s->mUnk_28 = func_0203c8dc(p->mIndex) - w.mUnk_00[k - 1];
    if (s->mUnk_28 <= 0) {
        s->mUnk_28 = 1;
    }
    p->mKartModelsEntry->mUnk_0a4 = 0;
    if (p->mUnk_7c & 0x2000) {
        p->mUnk_7c &= ~0x2000;
        p->mUnk_7c &= ~0xc000;
        p->mUnk_29c = 0;
        if (!(p->mUnk_7c & 1)) {
            func_0208c4e8(func_0208c5b8(p->mIndex));
        } else {
            func_021090c4(&p->mUnk_00, 0xf9, 0x7f, 0);
        }
        func_0210fa40(0, (p->mUnk_7c & 1) ? 1 : 0);
    }
    if (p->mUnk_4c & 0x8000000) {
        p->mUnk_4c &= ~0x8020000;
        if (p->mUnk_4c & 0x2000) {
            func_0207b13c(p);
        }
        func_02079c0c(p->mKartModelsEntry);
    }
    func_021035ac(p->mIndex);
    if (p->mUnk_4c & 0x40) {
        p->mUnk_4c &= ~0x40;
        func_0207b1a8(p);
        p->mUnk_29c = 0;
        func_020817b8(p->mIndex);
        func_02068a64(p, 0, 1);
        if ((p->mUnk_7c & 1) && data_021759c0->mUnk_00c == 0) {
            func_02106dc8();
        }
        if (p->mUnk_4c & 0x2000) {
            func_0207b13c(p);
        }
    }
    p->mUnk_29c = 3;
    if (p->mUnk_4c & 0x2000) {
        p->mUnk_4c &= ~0x2000;
        p->mUnk_d8 = 0x1000;
        if (!(p->mUnk_4c & 0x8000000)) {
            func_0207b0d0(p);
        }
        func_02080ee4(p);
    }
    if (p->mKartModelsEntry->mUnk_058 == 0) {
        v = data_usa_02165560;
        for (i = 0; i < 3; i++) {
            func_02081f10(func_0208b7bc(v.mUnk_00[i], &p->mUnk_80), p->mIndex, 0x14);
        }
    }
    func_02081724(p->mIndex);
    func_02069ea8(p);
    if (p->mUnk_7c & 0x200) {
        p->mUnk_514->mUnk_2c ^= 0x100000;
    }
    if (p->mUnk_7c & 1) {
        func_02074874(0x1d4c);
    }
}

void func_0206938c(Kart *p) {
    Unk0206ceb4 *s;
    Unk0206ceb4 *u;
    s32 i;
    BOOL r;
    BOOL t;
    Unk02165560 v;

    s = &p->mUnk_538;
    s->mUnk_1e++;
    if (!(p->mUnk_7c & 0x400)) {
        if (func_0209081c(&s->mUnk_2c) != 0) {
            u = &p->mUnk_538;
            if ((p->mUnk_4c & 0x10000000) && u->mUnk_24 == 0) {
                u->mUnk_24 = 1;
                if (p->mUnk_7c & 0x200) {
                    p->mUnk_514->mUnk_2c ^= 0x200000;
                }
            }
        }
    }
    func_02087b78((Unk02087d0c *) &p->mKartModelsEntry->mUnk_098);
    if (s->mUnk_24 != 0) {
        p->mUnk_4c8 -= 0x52;
        if (p->mUnk_4c8 > 0x1000) {
            return;
        }
        p->mUnk_4c &= ~0x10000000;
        func_0210515c(p->mIndex);
        if (p->mUnk_7c & 1) {
            func_02074854();
        }
        p->mUnk_4c8 = 0x1000;
        p->mUnk_3dc = -1;
        i = 0;
        p->mUnk_29c = 0;
        if (p->mKartModelsEntry->mUnk_058 == 0) {
            v = data_usa_02165560;
            for (i = 0; i < 3; i++) {
                func_02081f10(func_0208b7bc(v.mUnk_00[i], &p->mUnk_80), p->mIndex, 0x14);
            }
        }
        func_020815dc(p->mIndex);
        func_021090c4(&p->mUnk_00, 0xfd, 0x7f, 0);
        return;
    }
    p->mUnk_4c8 += 0x52;
    if (p->mUnk_4c8 > 0x1666) {
        p->mUnk_4c8 = 0x1666;
    }
    if (s->mUnk_24 != 0) {
        return;
    }
    r = FALSE;
    t = FALSE;
    if (!(p->mUnk_7c & 0x400)) {
        if (func_0203c8dc(p->mIndex) == 1) {
            r = TRUE;
        } else if ((s32) func_0203c8dc(p->mIndex) <= s->mUnk_28) {
            r = TRUE;
        }
        if (s->mUnk_1e > 0xb4 && r != FALSE) {
            t = TRUE;
        }
    }
    if (s->mUnk_1e <= 0x1e0 && t == FALSE) {
        return;
    }
    s->mUnk_24 = 1;
    if (p->mUnk_7c & 0x200) {
        p->mUnk_514->mUnk_2c ^= 0x200000;
    }
}

void func_0206924c(Kart *p, u32 a) {
    u32 w;

    if (p->mUnk_7c & 0x400) {
        return;
    }
    if (func_0203c880(p->mIndex) != 0) {
        return;
    }
    w = p->mUnk_7c;
    if (w & 0x60) {
        return;
    }
    if (p->mUnk_4c & 0x10000040) {
        return;
    }
    if (w & 0x2000) {
        return;
    }
    p->mUnk_538.mUnk_1c = 0;
    p->mUnk_4c |= 0x8000000;
    p->mUnk_4c &= ~0x20000;
    if (p->mUnk_4c & 0x2000) {
        func_0207b0d0(p);
    }
    func_02079f70(p->mKartModelsEntry, 0, 0x1084, 0);
    if (p->mUnk_7c & 0x10) {
        func_0207b054(p, 1, 0);
        func_0207b708(p->mKartModelsEntry, 1);
    }
    if (!(p->mUnk_48 & 0x840)) {
        func_0210af40(p, p->mUnk_3cc, 0);
    }
    func_021038f0(p->mIndex, a);
    if (p->mUnk_7c & 0x200) {
        p->mUnk_514->mUnk_2c ^= 0x80000;
    }
}

void func_02069134(Kart *p) {
    Unk0206ceb4 *s;
    u32 w;

    w = p->mUnk_4c;
    s = &p->mUnk_538;
    if (!(w & 0x40)) {
        if (s->mUnk_1c == 0x190 && !(w & 0x20000) && (w & 0x8000000) && s->mUnk_1c <= 0x190) {
            s->mUnk_1c = 0x190;
            p->mUnk_4c |= 0x20000;
            func_02079f70(p->mKartModelsEntry, func_0207a134(), func_0207a11c(), func_0207a104());
        }
        func_02079ce0(p->mKartModelsEntry, (p->mUnk_4c & 0x20000) ? 0x52 : 0x19a);
    }
    s->mUnk_1c++;
    if (s->mUnk_1c <= 0x1c2) {
        return;
    }
    if (!(p->mUnk_4c & 0x8000000)) {
        return;
    }
    p->mUnk_4c &= ~0x8020000;
    if (p->mUnk_4c & 0x2000) {
        func_0207b13c(p);
    }
    func_02079c0c(p->mKartModelsEntry);
}

void func_02069068(Kart *p) {
    Unk0206ceb4 *s;

    s = &p->mUnk_538;
    s->mUnk_0a = 0;
    s->mUnk_08 = 0;
    p->mUnk_d8 = data_usa_021654dc;
    p->mUnk_4c &= ~0x4000;
    if (!(p->mUnk_4c & 0x2000)) {
        p->mUnk_4c |= 0x2000;
        if (!(p->mUnk_4c & 0x8000000)) {
            func_0207b13c(p);
        }
    }
    if (p->mUnk_4c & 0x48000) {
        func_02080f44(p);
    }
    func_02081000(p);
    func_0210a53c(p);
    if (!(p->mUnk_7c & 1)) {
        func_021090c4(&p->mUnk_00, 0xa4, 0x7f, 0);
    }
    if (p->mUnk_7c & 0x200) {
        p->mUnk_514->mUnk_2c ^= 0x40000;
    }
}

void func_02069044(Kart *p) {
    func_02068ec0(p, 1);
    p->mUnk_7c |= 0x800000;
}

s32 func_02068ec0(Kart *p, s32 a) {
    BOOL r;
    u32 w;
    Unk0212c400 **h;

    r = FALSE;
    if (a != 0) {
        w = p->mUnk_7c;
        if (!(w & 0x800000)) {
            r = TRUE;
        }
    } else {
        w = p->mUnk_7c;
        if (!(w & 0x900020)) {
            r = TRUE;
        }
    }
    if (r != FALSE) {
        if (!(w & 0x4000000)) {
            func_020858ac(p->mIndex);
            p->mUnk_7c |= 0x4000000;
        }
        p->mUnk_7c |= 0x20;
        if (p->mUnk_2c8 != -1) {
            p->mUnk_2c8 = func_020d5344(p->mUnk_2c8);
        }
        if (p->mUnk_2ca != -1) {
            p->mUnk_2ca = func_020d5344(p->mUnk_2ca);
        }
        if (data_021759c0->mMode == 2 && a == 0) {
            func_021090c4(&p->mUnk_00, 0xd3, 0x7f, 0);
            if (data_021759c0->mUnk_18 == 0 && (data_0217c780 & 1)) {
                h = (Unk0212c400 **) func_0210e128((void *) func_02108ea0(0));
                if (data_0217d084.mUnk_0c != 0) {
                    if (h[0] != NULL) {
                        func_0212c6f0(h, 0);
                    }
                    if (h[0] != NULL) {
                        func_0212c6f0(h, 0);
                    }
                    func_0212ecc0(h, 0, 0x4c);
                }
            }
        }
        p->mUnk_3c8 = 0;
        func_02072930(p);
    }
    return r;
}

BOOL func_02068eac(Kart *p) {
    return (p->mUnk_7c & 0x60) != 0;
}
