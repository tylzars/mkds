#include "00/code_02185954.h"

#include "00/code_02181f98.h"
#include "code_0200e77c.h"
#include "00/code_021857b8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "00/unk_021b1000.h"
#include "00/code_02186a9c.h"
#include "00/code_021acef8.h"
#include "00/code_021ad734.h"
#include "03/code_021b94b8.h"
#include "00/code_02186d04.h"
#include "00/code_02188008.h"
#include "00/code_02186628.h"
#include "00/code_02187000.h"
#include "00/code_021a6000.h"
#include "code_0200d118.h"
#include "code_0200db4c.h"
#include "code_0200f5ac.h"
#include "code_0200fc8c.h"
#include "code_0200fd1c.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "code_0214d018.h"
#include "code_0214d954.h"
#include "code_0200edc0.h"
#include "Main/Unknown/code_02151f88.h"

s32 func_ov000_02186560(Unk02186560 *a, Http *b) {
    void *c;
    if (data_ov000_021b4c90 != NULL) {
        return 2;
    }
    c = a->mUnk_24(data_ov000_021b11fc, 0x13e0);
    if (c == NULL) {
        return 2;
    }
    data_ov000_021b4c90 = c;
    MemFill(c, 0, 0x13e0);
    data_ov000_021b4c90->mUnk_2f8 = b;
    MemFill(&data_ov000_021b4c90->mUnk_008, 0, 0x1c4);
    data_ov000_021b4c90->mUnk_008 = -1;
    data_ov000_021b4c90->mUnk_1cc = *a;
    data_ov000_021b4c90->mUnk_1cc.mUnk_00[0x14] = 0;
    data_ov000_021b4c90->mUnk_1cc.mUnk_15[0xb] = 0;
    ((void **) data_ov000_021b1040)[4] = a->mUnk_24;
    ((void **) data_ov000_021b1040)[5] = a->mUnk_28;
    data_ov000_021b4c90->mUnk_004 = func_ov000_02186298(1);
    if (data_ov000_021b4c90->mUnk_004 == 0) {
        func_ov000_021864e0();
        return 0;
    }
    return data_ov000_021b4c90->mUnk_004;
}

void func_ov000_021864e0(void) {
    ThreadLockInit(&data_ov000_021b4c90->mUnk_3bc);
    data_ov000_021b4c90->mUnk_3d4 = 0;
    if (data_ov000_021b4c90->mUnk_2fc.mUnk_6c == 0 || ThreadHasEnded(&data_ov000_021b4c90->mUnk_2fc) != 0) {
        ThreadInit(&data_ov000_021b4c90->mUnk_2fc, func_ov000_021860ac, &data_ov000_021b4c90,
                   data_ov000_021b4c90->mUnk_3e0 + 0x1000, 0x1000, 0x10);
        ThreadSetRunnable(&data_ov000_021b4c90->mUnk_2fc);
    }
}

void func_ov000_02186474(void) {
    if (data_ov000_021b4c90 != NULL) {
        ThreadLockWait(&data_ov000_021b4c90->mUnk_3bc);
        data_ov000_021b4c90->mUnk_3d4 = 1;
        ThreadLockUnlock(&data_ov000_021b4c90->mUnk_3bc);
        if (data_ov000_021b4c90->mUnk_2f8 != NULL) {
            func_ov000_02187274((Unk02186d7c *) data_ov000_021b4c90->mUnk_2f8);
        }
        if (data_ov000_021b4c90->mUnk_2fc.mUnk_6c != 0) {
            ThreadWaitForEnd(&data_ov000_021b4c90->mUnk_2fc);
        }
    }
}

void func_ov000_02186430(void) {
    if (data_ov000_021b4c90 != NULL) {
        if (data_ov000_021b4c90->mUnk_2f8 != NULL) {
            ReleaseHttp(data_ov000_021b4c90->mUnk_2f8);
        }
        data_ov000_021b4c90->mUnk_1cc.mUnk_28(data_ov000_021b11f4, data_ov000_021b4c90, 0);
        data_ov000_021b4c90 = NULL;
    }
}

void func_ov000_02186404(void) {
    if (data_ov000_021b4c90->mUnk_2fc.mUnk_6c != 0) {
        ThreadWaitForEnd(&data_ov000_021b4c90->mUnk_2fc);
    }
}

s32 func_ov000_021863cc(void) {
    s32 a;
    if (data_ov000_021b4c90 == NULL) {
        return 0x15;
    }
    ThreadLockWait(&data_ov000_021b4c90->mUnk_3bc);
    a = data_ov000_021b4c90->mUnk_004;
    ThreadLockUnlock(&data_ov000_021b4c90->mUnk_3bc);
    return a;
}

void func_ov000_0218635c(s32 *a) {
    s32 b;
    if (data_ov000_021b4c90 == NULL) {
        MemFill(a, 0, 0x1c4);
    }
    MemCopy(&data_ov000_021b4c90->mUnk_008, a, 0x1c4);
    b = *a;
    if (b >= 0) {
        if (b < 0x4e20 || b >= 0x7530) {
            *a = -0x5206;
        }
    } else if (b > -0x4e20 || b <= -0x7530) {
        *a = -0x5206;
    }
}

s32 func_ov000_02186298(s32 a) {
    if (strcmp(*(const char **) data_ov000_021b1040, data_ov000_021b1020) != 0) {
        *(s32 *) (data_ov000_021b1040 + 0x18) = 1;
    }
    if (func_ov000_021873d4((Unk02186d7c *) data_ov000_021b4c90->mUnk_2f8, (const Unk021873d4 *) data_ov000_021b1040) !=
        0) {
        return 4;
    }
    if (a == 1) {
        func_02151910((Unk021510a4 *) &data_ov000_021b4c94);
    }
    data_ov000_021b4c90->mUnk_004 =
        func_ov000_02185984(data_ov000_021b4c90->mUnk_2f8, data_ov000_021b4c90->mUnk_1cc.mUnk_15,
                            data_ov000_021b4c90->mUnk_1cc.mUnk_00, data_ov000_021b4c90->mUnk_1f8, 0x20, 0);
    if (data_ov000_021b4c90->mUnk_004 != 0) {
        return 4;
    }
    if (func_ov000_0218735c((Unk02186d7c *) data_ov000_021b4c90->mUnk_2f8) != 0) {
        return 4;
    }
    func_ov000_021872bc((Unk02186d7c *) data_ov000_021b4c90->mUnk_2f8);
    return 0;
}

void func_ov000_021860ac(void *param_1) {
    s32 a = 0;
    s32 b;
    BOOL c = FALSE;
    BOOL d = FALSE;
    BOOL e = FALSE;
    s32 f;
    u64 g;
    u64 h;
    Unk02185984 *i;
    while (1) {
        i = data_ov000_021b4c90;
        if (i->mUnk_2f8->mThread.mUnk_6c != 0) {
            ThreadWaitForEnd(&i->mUnk_2f8->mThread);
        }
        if (data_ov000_021b4c90->mUnk_2f8->mResult != 8) {
            data_ov000_021b4c90->mUnk_008 = -0x4e84;
            if (data_ov000_021b4c90->mUnk_2f8->mResult == 7) {
                func_ov000_02185954(0x13);
                return;
            }
            if (a > 2) {
                if (data_ov000_021b4c90->mUnk_2f8->mResult == 2) {
                    func_ov000_02185954(9);
                    return;
                }
                func_ov000_02185954(0xc);
                return;
            }
            a++;
            b = 1;
        } else {
            f = func_ov000_02185ef4();
            switch (f) {
                case 0x14:
                    func_ov000_02185954(0x14);
                    return;
                case 0xf:
                    if (a >= 2) {
                        func_ov000_02185954(0xf);
                        data_ov000_021b4c90->mUnk_008 = -data_ov000_021b4c90->mUnk_008;
                        return;
                    }
                    a++;
                    b = c;
                    break;
                default:
                    if (a >= 2) {
                        data_ov000_021b4c90->mUnk_008 = -data_ov000_021b4c90->mUnk_008;
                        func_ov000_02185954(f);
                        return;
                    }
                    a++;
                    b = 1;
                    break;
            }
        }
        g = func_0200f5ac();
        h = ((func_0200f5ac() - g) * 64) / 0x82ea;
        while (h < 5000) {
            ThreadLockWait(&data_ov000_021b4c90->mUnk_3bc);
            if (data_ov000_021b4c90->mUnk_3d4 == 1) {
                data_ov000_021b4c90->mUnk_008 = -0x4e84;
                ThreadLockUnlock(&data_ov000_021b4c90->mUnk_3bc);
                func_ov000_02185954(0x13);
                return;
            }
            ThreadLockUnlock(&data_ov000_021b4c90->mUnk_3bc);
            func_0200dc3c(5000);
            h = ((func_0200f5ac() - g) * 64) / 0x82ea;
        }
        ReleaseHttp(data_ov000_021b4c90->mUnk_2f8);
        ThreadLockWait(&data_ov000_021b4c90->mUnk_3bc);
        data_ov000_021b4c90->mUnk_004 = func_ov000_02186298(b);
        if (data_ov000_021b4c90->mUnk_004 != 0) {
            data_ov000_021b4c90->mUnk_008 = -0x4e84;
            ThreadLockUnlock(&data_ov000_021b4c90->mUnk_3bc);
            return;
        }
        ThreadLockUnlock(&data_ov000_021b4c90->mUnk_3bc);
    }
}

s32 func_ov000_02185ef4(void) {
    Unk02185984 *a;
    const char *b;
    void *c;
    if (func_ov000_021866fc(data_ov000_021b4c90->mUnk_1f8, 0x20, 0,
                            data_ov000_021b4c90->mUnk_2f8->mReceiveBuffer.mStart) != 1) {
        data_ov000_021b4c90->mUnk_008 = 0x4e84;
        return 0xd;
    }
    if (func_ov000_02185d54() != 0) {
        return 0xd;
    }
    a = data_ov000_021b4c90;
    if (a->mUnk_008 < 0x4e84) {
        if (a->mUnk_008 == 0x4e22) {
            b = data_ov000_021b11ec;
            c = a->mUnk_1cc.mUnk_24(b, 0x71f);
            if (c == NULL) {
                data_ov000_021b4c90->mUnk_008 = 0x4e84;
                return 2;
            }
            if (func_02151f48((Unk021510a4 *) &data_ov000_021b4c94, (u8 *) (((u32) c + 0x1f) & ~0x1f)) != 1) {
                data_ov000_021b4c90->mUnk_1cc.mUnk_28(b, c, 0);
                data_ov000_021b4c90->mUnk_008 = 0x4e84;
                return 0xe;
            }
            data_ov000_021b4c90->mUnk_1cc.mUnk_28(b, c, 0);
        }
        return 0x14;
    }
    switch (a->mUnk_008) {
        case 0x4e88:
            if (func_02151e20((Unk021510a4 *) &data_ov000_021b4c94) == 0) {
                data_ov000_021b4c90->mUnk_008 = 0x4e88;
                return 0xe;
            }
            data_ov000_021b4c90->mUnk_008 = 0x4e88;
            return 0xf;
        case 0x4e8c:
            b = data_ov000_021b11ec;
            c = a->mUnk_1cc.mUnk_24(b, 0x71f);
            if (c == NULL) {
                data_ov000_021b4c90->mUnk_008 = 0x4e8c;
                return 2;
            }
            if (func_02151f88(((u32) c + 0x1f) & ~0x1f) != 1) {
                data_ov000_021b4c90->mUnk_1cc.mUnk_28(b, c, 0);
                data_ov000_021b4c90->mUnk_008 = 0x4e8c;
                return 0xe;
            }
            data_ov000_021b4c90->mUnk_1cc.mUnk_28(b, c, 0);
            data_ov000_021b4c90->mUnk_008 = 0x4e8c;
            return 0x10;
    }
    return 0x11;
}

s32 func_ov000_02185d54(void) {
    s32 b;
    const char *c;
    Unk02185984 *d;
    c = NULL;
    b = StrtolBase10(func_ov000_021866b8(data_ov000_021b4c90->mUnk_1f8, 0x20, data_ov000_021b11a0));
    if (gLibErrorCode == 0x22) {
        data_ov000_021b4c90->mUnk_008 = 0x4e85;
        return 0xb;
    }
    if (b != 200) {
        data_ov000_021b4c90->mUnk_008 = b + 0x59d8;
        return 0x11;
    }
    d = data_ov000_021b4c90;
    if (func_ov000_02186674(d->mUnk_1f8, 0x20, data_ov000_021b11ac, d->mUnk_00c, 4) <= 0) {
        data_ov000_021b4c90->mUnk_008 = 0x4e85;
        return 0xd;
    }
    b = strtol(data_ov000_021b4c90->mUnk_00c, &c, 10);
    d = data_ov000_021b4c90;
    if (c != d->mUnk_00c + strlen(d->mUnk_00c)) {
        d->mUnk_008 = 0x4e85;
        return 0xb;
    }
    d->mUnk_008 = b + 0x4e20;
    if (b < 100) {
        data_ov000_021b4c90->mUnk_052[0] = 0;
        data_ov000_021b4c90->mUnk_01f[0] = 0;
        data_ov000_021b4c90->mUnk_17f[0] = 0;
        data_ov000_021b4c90->mUnk_010[0] = 0;
        data_ov000_021b4c90->mUnk_188[0] = 0;
        func_ov000_02186674(data_ov000_021b4c90->mUnk_1f8, 0x20, data_ov000_021b11b8, data_ov000_021b4c90->mUnk_052,
                            0x12d);
        func_ov000_02186674(data_ov000_021b4c90->mUnk_1f8, 0x20, data_ov000_021b11c0, data_ov000_021b4c90->mUnk_01f,
                            0x33);
        func_ov000_02186674(data_ov000_021b4c90->mUnk_1f8, 0x20, data_ov000_021b11c8, data_ov000_021b4c90->mUnk_17f, 9);
        func_ov000_02186674(data_ov000_021b4c90->mUnk_1f8, 0x20, data_ov000_021b11d4, data_ov000_021b4c90->mUnk_010,
                            0xf);
        func_ov000_02186634(data_ov000_021b4c90->mUnk_1f8, 0x20, data_ov000_021b11e0, data_ov000_021b4c90->mUnk_188,
                            0x41);
        data_ov000_021b4c90->mUnk_188[0x2b] = 0;
    }
    return 0;
}

u32 func_ov000_02185984(Http *a, const char *b, const char *c, Unk021868a4Entry *d, s32 e, s32 f) {
    Unk02185984Data g;
    u32 o[4];
    u32 p[3];
    Unk021868a4 q;
    char r[13];
    char s[13];
    u8 t[0x15];
    char u[13];
    u8 v[0x21];
    char w[14];
    char x[0xe];
    Unk0200fddc y;
    u8 *l;
    u32 h;
    u8 *i;
    u8 *j;
    s32 k;
    s32 m;
    char *n;
    func_0200fe58(g.mUnk_02);
    func_0200fddc(&y);
    if (func_0214e038(o) != 0 || func_0214df78(p) != 0) {
        return 5;
    }
    h = IrqDisable();
    i = func_ov000_021a6b10();
    if (i == NULL) {
        IrqRestore(h);
        return 3;
    }
    MemCopy(i, g.mUnk_08, 6);
    MemFill(v, 0, 0x21);
    j = func_ov000_021a6abc((u16 *) &g);
    if (j == NULL) {
        IrqRestore(h);
        return 3;
    }
    MemCopy(j, v, g.mUnk_00);
    IrqRestore(h);
    MemCopy((const void *) 0x27ffe0c, g.mUnk_0e, 4);
    g.mUnk_0e[4] = 0;
    MemCopy((const void *) 0x27ffe10, g.mUnk_13, 2);
    g.mUnk_13[2] = 0;
    l = g.mUnk_02;
    for (k = 0; k < 6; l++, k++) {
        StringFormat(&r[k * 2], data_ov000_021b1060, *l);
    }
    r[12] = 0;
    if (y.mUnk_00 > 6) {
        y.mUnk_00 = 1;
    }
    StringFormatBounded(g.mUnk_16, 5, data_ov000_021b1068, y.mUnk_02, y.mUnk_03);
    StringFormatBounded(s, 0xd, data_ov000_021b1074, o[0], o[1], o[2], p[0], p[1], p[2]);
    MemCopy(y.mUnk_04, t, 0x14);
    t[0x14] = 0;
    MemFill(&q, 0, 0xc);
    q.mEntries = d;
    q.mCapacity = e;
    if (f != 1) {
        if (data_ov000_021b4c94.mUnk_00 == 0) {
            func_ov000_021868a4(&q, data_ov000_021b1090, data_ov000_021b1098);
        } else {
            if (strlen(b) == 0) {
                return 6;
            }
            func_ov000_021868a4(&q, data_ov000_021b1090, data_ov000_021b10a4);
            func_ov000_021868a4(&q, data_ov000_021b10ac, b);
            if (strlen(c) != 0) {
                func_ov000_021868a4(&q, data_ov000_021b10b4, c);
            }
        }
    } else {
        func_02151910((Unk021510a4 *) &data_ov000_021b4c94);
    }
    func_ov000_021868a4(&q, data_ov000_021b10c0, data_ov000_021b10c8);
    if (data_ov000_021b4c94.mUnk_00 != 0) {
        StringFormatBounded(x, 0xe, data_ov000_021b10d0, data_ov000_021b4c94.mUnk_00);
    } else {
        StringFormatBounded(x, 0xe, data_ov000_021b10d0, data_ov000_021b4c94.mUnk_08);
    }
    func_ov000_021868a4(&q, data_ov000_021b10d8, x);
    StringFormatBounded(g.mUnk_1b, 4, data_ov000_021b10e0, data_ov000_021b4c94.mUnk_10);
    func_ov000_021868a4(&q, data_ov000_021b10e8, g.mUnk_1b);
    StringFormatBounded(u, 0xd, data_ov000_021b10f0, g.mUnk_08[0], g.mUnk_08[1], g.mUnk_08[2], g.mUnk_08[3],
                        g.mUnk_08[4], g.mUnk_08[5]);
    StringFormatBounded(w, 0xd, data_ov000_021b110c, 0);
    func_ov000_0218a67c(v, &w[3]);
    func_ov000_021868a4(&q, data_ov000_021b111c, g.mUnk_0e);
    func_ov000_021868a4(&q, data_ov000_021b1124, g.mUnk_13);
    func_ov000_021868a4(&q, data_ov000_021b112c, data_ov000_021b1134);
    func_ov000_021868a4(&q, data_ov000_021b1138, r);
    func_ov000_021868a4(&q, data_ov000_021b1140, data_ov000_021b1004[y.mUnk_00]);
    func_ov000_021868a4(&q, data_ov000_021b1148, g.mUnk_16);
    func_ov000_021868a4(&q, data_ov000_021b1150, s);
    func_ov000_021868a4(&q, data_ov000_021b1158, u);
    func_ov000_021868a4(&q, data_ov000_021b1160, w);
    if (func_ov000_02186bd4(a, data_ov000_021b1168, data_ov000_021b1174) != 0) {
        return 7;
    }
    if (func_ov000_02186bd4(a, data_ov000_021b1188, g.mUnk_0e) != 0) {
        return 7;
    }
    for (m = 0; d->mFirst != NULL; d++, m++) {
        n = d->mSecond;
        if (func_ov000_02186b0c(a, d->mFirst, n, strlen(n)) != 0) {
            return 8;
        }
    }
    if (func_ov000_02186b0c(a, data_ov000_021b1198, t, 0x14) != 0) {
        return 8;
    }
    return 0;
}

void func_ov000_02185954(s32 a) {
    ThreadLockWait(((Unk021b4c90 *) data_ov000_021b4c90)->mUnk_3bc);
    ((Unk021b4c90 *) data_ov000_021b4c90)->mUnk_004 = a;
    ThreadLockUnlock(((Unk021b4c90 *) data_ov000_021b4c90)->mUnk_3bc);
}
