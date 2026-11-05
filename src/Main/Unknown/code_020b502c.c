#include "Main/Unknown/code_020b502c.h"
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

#include "code_02147cd8.h"
#include "Main/Unknown/code_020b4dc4.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02102674.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020b65f0.h"
#include "Main/Unknown/code_020b681c.h"
#include "Main/Unknown/code_020b6800.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02077bc0.h"

const Vec3 data_02156874 = {0, 0, 0};

void func_020b65f0(void) {
    UnkPair020b502c a;
    UnkPair020b502c b;
    UnkPair020b502c c;
    UnkPair020b502c d;
    UnkPair020b502c e;
    UnkPair020b502c f;

    data_0217b3c0 = HeapAlloc(func_020b6800(), 0x9c);
    data_0217b3c0->mUnk_00.mUnk_00 = 0;
    data_0217b3c0->mUnk_00.mUnk_04 = 0;
    data_0217b3c0->mUnk_10.mUnk_00 = 0;
    data_0217b3c0->mUnk_10.mUnk_04 = 0;
    data_0217b3c0->mUnk_18 = 0;
    data_0217b3c0->mUnk_1c = 0;
    data_0217b3c0->mUnk_1e = 0;
    data_0217b3c0->mUnk_20 = 0;
    data_0217b3c0->mUnk_24 = 0;
    func_020b6b54(&a, &b);
    data_0217b3c0->mUnk_2c = a;
    data_0217b3c0->mUnk_34 = b;
    data_0217b3c0->mUnk_3c = ReciprocalFixed12Raw(b.mUnk_00 - a.mUnk_00);
    data_0217b3c0->mUnk_44 = ReciprocalFixed12Raw(b.mUnk_04 - a.mUnk_04);
    func_020b6a98(&c, &d);
    data_0217b3c0->mUnk_4c = c;
    data_0217b3c0->mUnk_54 = d;
    data_0217b3c0->mUnk_5c = ReciprocalFixed12Raw(d.mUnk_00 - c.mUnk_00);
    data_0217b3c0->mUnk_64 = ReciprocalFixed12Raw(d.mUnk_04 - c.mUnk_04);
    data_0217b3c0->mUnk_28 = func_020b502c(DivFixed12(d.mUnk_00 - c.mUnk_00, 0x200000), 0xb0000);
    func_020b681c(&e, &f);
    data_0217b3c0->mUnk_6c = e;
    data_0217b3c0->mUnk_74 = f;
    data_0217b3c0->mUnk_7c = ReciprocalFixed12Raw(f.mUnk_00 - e.mUnk_00);
    data_0217b3c0->mUnk_84 = ReciprocalFixed12Raw(f.mUnk_04 - e.mUnk_04);
    data_0217b3c0->mUnk_8c = 0;
    data_0217b3c0->mUnk_90 = data_02156874;
}

u32 func_020b65dc(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b3c0;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

s32 func_020b64e8(void) {
    BOOL r = FALSE;

    switch (func_020b4e5c()) {
        case 1:
        case 11:
        case 14:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 30:
        case 33:
        case 34:
        case 38:
        case 40:
        case 48:
        case 50:
            r = TRUE;
            break;
    }
    return r;
}

s32 func_020b6430(void) {
    BOOL r = FALSE;

    switch (func_020b4e5c()) {
        case 1:
        case 11:
        case 16:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 34:
        case 40:
        case 48:
        case 50:
            r = TRUE;
            break;
    }
    return r;
}

u16 func_020b6368(void) {
    u16 r = 0;
    Unk020748a8 *p;
    s32 a;

    switch (GetRaceHudSubScreenState()) {
        case 1:
            if (func_020b4df8() == MODE_BATTLE) {
                p = GetCurrentCamera();
            } else {
                p = GetChaseCamera();
            }
            a = AngleFromPair(p->mViewMatrix[8], p->mViewMatrix[2]);
            r = (0x14000 - a) % 0x10000;
            data_0217b3c0->mUnk_8c = 0;
            break;
        case 2:
            r = 0;
            break;
        case 3:
            a = func_020b5250(func_020b57e4()->mUnk_10);
            r = (a << 16) / 360 + 0x8000;
            break;
        default:
            break;
    }
    return r;
}

u16 func_020b6338(s32 idx) {
    return (u16) ((0x18000 - func_0207a880(idx)) % 0x10000);
}

void func_020b6078(s32 idx, UnkPair020b502c *out) {
    UnkPair020b502c a = data_0217b3c0->mUnk_2c;
    Vec3 v;

    GetKartPos(&v, (u8) idx);
    switch (func_020b4e5c()) {
        case 0xb:
        case 0x14:
        case 0x26:
            if (func_020b523c() != 0) {
                out->mUnk_00 =
                    func_020b5250(func_020b502c(0x80000, func_020b57b4(a.mUnk_00 - v.z, data_0217b3c0->mUnk_3c))) +
                    0xf8;
            } else {
                out->mUnk_00 =
                    func_020b5250(func_020b502c(0x80000, func_020b57b4(v.z - a.mUnk_00, data_0217b3c0->mUnk_3c))) +
                    0x78;
            }
            out->mUnk_04 =
                func_020b5250(func_020b502c(0x98000, func_020b57b4(v.x - a.mUnk_04, data_0217b3c0->mUnk_44))) + 0x28;
            break;
        case 0x16:
            if (func_020b523c() != 0) {
                out->mUnk_00 =
                    func_020b5250(func_020b502c(0x80000, func_020b57b4(a.mUnk_00 - v.z, data_0217b3c0->mUnk_3c))) +
                    0xf8;
            } else {
                out->mUnk_00 =
                    func_020b5250(func_020b502c(0x80000, func_020b57b4(v.z - a.mUnk_00, data_0217b3c0->mUnk_3c))) +
                    0x78;
            }
            out->mUnk_04 =
                func_020b5250(func_020b502c(0x98000, func_020b57b4(v.x - a.mUnk_04, data_0217b3c0->mUnk_44))) + 0x28;
            break;
        default:
            if (func_020b523c() != 0) {
                out->mUnk_00 =
                    func_020b5250(func_020b502c(0x80000, func_020b57b4(a.mUnk_00 - v.x, data_0217b3c0->mUnk_3c))) +
                    0xf8;
            } else {
                out->mUnk_00 =
                    func_020b5250(func_020b502c(0x80000, func_020b57b4(v.x - a.mUnk_00, data_0217b3c0->mUnk_3c))) +
                    0x78;
            }
            out->mUnk_04 =
                func_020b5250(func_020b502c(0x98000, func_020b57b4(v.z - a.mUnk_04, data_0217b3c0->mUnk_44))) + 0x28;
            break;
    }
}

void func_020b5fe4(const Vec3 *pos, UnkPair020b502c *out) {
    UnkPair020b502c o = data_0217b3c0->mUnk_4c;

    out->mUnk_00 = func_020b5250(func_020b502c(0x200000, func_020b57b4(pos->x - o.mUnk_00, data_0217b3c0->mUnk_5c)));
    out->mUnk_04 = func_020b5250(func_020b502c(0x200000, func_020b57b4(pos->z - o.mUnk_04, data_0217b3c0->mUnk_64)));
}

BOOL func_020b5f68(const UnkPair020b502c *p) {
    UnkPair020b502c c = data_0217b3c0->mUnk_10;
    s32 r = data_0217b3c0->mUnk_18;

    if (p->mUnk_00 - r < c.mUnk_00 && c.mUnk_00 < p->mUnk_00 + r && p->mUnk_04 - r < c.mUnk_04 &&
        c.mUnk_04 < p->mUnk_04 + r) {
        return TRUE;
    }
    return FALSE;
}

void func_020b5dcc(s32 idx, UnkPair020b502c *out, s32 v1) {
    UnkPair020b502c a = data_0217b3c0->mUnk_00;
    s32 ay = a.mUnk_04;
    s32 v20 = data_0217b3c0->mUnk_20;
    s32 v24 = data_0217b3c0->mUnk_24;
    UnkPair020b502c o = data_0217b3c0->mUnk_4c;
    Vec3 v;
    s32 px;
    s32 py;
    s32 dx;
    s32 dy;

    GetKartPos(&v, (u8) idx);
    px = func_020b502c(0x200000, func_020b57b4(v.x - o.mUnk_00, data_0217b3c0->mUnk_5c));
    py = func_020b502c(0x200000, func_020b57b4(v.z - o.mUnk_04, data_0217b3c0->mUnk_64));
    if (func_020b523c() != 0) {
        dy = py - ay;
        dx = px - a.mUnk_00;
        out->mUnk_00 = func_020b5250(func_020b502c(-v20, dx) + func_020b502c(v24, dy)) + 0x80;
        out->mUnk_04 = func_020b5250(func_020b502c(v24, dx) + func_020b502c(v20, dy)) + 0x60;
    } else {
        dx = px - a.mUnk_00;
        dy = py - ay;
        out->mUnk_00 = func_020b5250(func_020b502c(v20, dx) - func_020b502c(v24, dy)) + 0x80;
        out->mUnk_04 = func_020b5250(func_020b502c(v24, dx) + func_020b502c(v20, dy)) + 0x60;
    }
}

static inline s32 func_020b5ae8_inline(s32 v) {
    float f;

    if (func_020b5250(v) > 0) {
        f = 0.5f + (float) (func_020b5250(v) << 12);
    } else {
        f = (float) (func_020b5250(v) << 12) - 0.5f;
    }
    return (s32) f;
}

BOOL func_020b5ae8(const Vec3 *pos, UnkPair020b502c *out, s32 unk, s32 flag, s32 flag2) {
    UnkPair020b502c a = data_0217b3c0->mUnk_00;
    s32 v20 = data_0217b3c0->mUnk_20;
    s32 v24 = data_0217b3c0->mUnk_24;
    UnkPair020b502c o = data_0217b3c0->mUnk_4c;
    s32 x;
    s32 y;
    s32 dx;
    s32 px;
    s32 py;
    s32 dy;
    s32 e;
    s32 ox;
    s32 oy;
    UnkPair020b502c c;
    s32 r;
    s32 tx;
    s32 ty;

    px = func_020b502c(0x200000, func_020b57b4(pos->x - o.mUnk_00, data_0217b3c0->mUnk_5c));
    py = func_020b502c(0x200000, func_020b57b4(pos->z - o.mUnk_04, data_0217b3c0->mUnk_64));
    if (flag != 0) {
        c = data_0217b3c0->mUnk_10;
        r = data_0217b3c0->mUnk_18;
        tx = func_020b5250(px);
        ty = func_020b5250(py);

        if (tx - r >= c.mUnk_00 || c.mUnk_00 >= tx + r || ty - r >= c.mUnk_04 || c.mUnk_04 >= ty + r) {
            return FALSE;
        }
    }
    if (flag2 != 0) {
        x = a.mUnk_00;
        y = a.mUnk_04;
    } else {
        x = func_020b5ae8_inline(a.mUnk_00);
        y = func_020b5ae8_inline(a.mUnk_04);
    }
    if (func_020b523c() != 0) {
        dx = px - x;
        dy = py - y;
        ox = func_020b5250(func_020b502c(-v20, dx) + func_020b502c(v24, dy)) + 0x80;
        oy = func_020b5250(func_020b502c(v24, dx) + func_020b502c(v20, dy)) + 0x60;
    } else {
        dx = px - x;
        e = py - y;
        ox = func_020b5250(func_020b502c(v20, dx) - func_020b502c(v24, e)) + 0x80;
        oy = func_020b5250(func_020b502c(v24, dx) + func_020b502c(v20, e)) + 0x60;
    }
    if (ox > -32 && ox < 0x120 && oy > -32 && oy < 0xe0) {
        out->mUnk_00 = ox;
        out->mUnk_04 = oy;
        return TRUE;
    }
    out->mUnk_00 = ox;
    out->mUnk_04 = oy;
    return FALSE;
}

void func_020b58f8(Unk020b503c *out) {
    UnkPair020b502c a = data_0217b3c0->mUnk_4c;
    Vec3 pos;
    float f;

    if (data_0217b3c0->mUnk_8c != 0) {
        pos = data_0217b3c0->mUnk_90;
    } else {
        func_0207a91c(&pos, func_020b4d9c());
    }
    if (GetRaceHudSubScreenState() == 3) {
        pos = func_020b57e4()->mUnk_00;
    }
    data_0217b3c0->mUnk_00.mUnk_00 = func_020b502c(0x200000, func_020b57b4(pos.x - a.mUnk_00, data_0217b3c0->mUnk_5c));
    data_0217b3c0->mUnk_00.mUnk_04 = func_020b502c(0x200000, func_020b57b4(pos.z - a.mUnk_04, data_0217b3c0->mUnk_64));
    data_0217b3c0->mUnk_10.mUnk_00 = func_020b5250(data_0217b3c0->mUnk_00.mUnk_00);
    out->mUnk_10 = data_0217b3c0->mUnk_10.mUnk_00;
    data_0217b3c0->mUnk_10.mUnk_04 = func_020b5250(data_0217b3c0->mUnk_00.mUnk_04);
    out->mUnk_14 = data_0217b3c0->mUnk_10.mUnk_04;
    out->mUnk_18 = out->mUnk_10 - 0x80;
    out->mUnk_1c = out->mUnk_14 - 0x60;
    if (data_0217b3c0->mUnk_10.mUnk_00 > 0) {
        f = 0.5f + (float) (data_0217b3c0->mUnk_10.mUnk_00 << 12);
    } else {
        f = (float) (data_0217b3c0->mUnk_10.mUnk_00 << 12) - 0.5f;
    }
    data_0217b3c0->mUnk_08 = data_0217b3c0->mUnk_00.mUnk_00 - (s32) f;
    if (data_0217b3c0->mUnk_10.mUnk_04 > 0) {
        f = 0.5f + (float) (data_0217b3c0->mUnk_10.mUnk_04 << 12);
    } else {
        f = (float) (data_0217b3c0->mUnk_10.mUnk_04 << 12) - 0.5f;
    }
    data_0217b3c0->mUnk_0c = data_0217b3c0->mUnk_00.mUnk_04 - (s32) f;
}

void func_020b57f8(Unk020b503c *out) {
    UnkPair020b502c a = data_0217b3c0->mUnk_6c;
    Vec3 pos;

    if (data_0217b3c0->mUnk_8c != 0) {
        pos = data_0217b3c0->mUnk_90;
    } else {
        func_0207a91c(&pos, func_020b4d9c());
    }
    if (GetRaceHudSubScreenState() == 3) {
        pos = func_020b57e4()->mUnk_00;
    }
    out->mUnk_10 = func_020b5250(func_020b502c(0x200000, func_020b57b4(pos.x - a.mUnk_00, data_0217b3c0->mUnk_7c)));
    out->mUnk_14 = func_020b5250(func_020b502c(0x200000, func_020b57b4(pos.z - a.mUnk_04, data_0217b3c0->mUnk_84)));
    out->mUnk_18 = out->mUnk_10 - 0x80;
    out->mUnk_1c = out->mUnk_14 - 0x60;
}

Unk020b57e4 *func_020b57e4(void) {
    return gCourseMap->mUnk_2c;
}

s32 func_020b57b4(s32 a, s64 k) {
    return (s32) ((k * a + 0x80000000) >> 32);
}

void func_020b5658(Unk020b503c *out) {
    UnkPair020b502c a = data_0217b3c0->mUnk_6c;
    UnkPair020b502c b = data_0217b3c0->mUnk_74;
    Vec3 pos;
    s32 n;
    s32 ex;
    s32 ez;
    s32 dx;
    s32 dz;

    if (data_0217b3c0->mUnk_8c != 0) {
        pos = data_0217b3c0->mUnk_90;
    } else {
        func_0207a91c(&pos, func_020b4d9c());
    }
    if (GetRaceHudSubScreenState() == 3) {
        pos = func_020b57e4()->mUnk_00;
    }
    ex = b.mUnk_00 - a.mUnk_00;
    ez = b.mUnk_04 - a.mUnk_04;
    n = GetRaceHudUpdateFrames() / 32;
    dx = ex * n;
    dz = ez * n;
    pos.x -= dx / 512;
    pos.z -= dz / 512;
    out->mUnk_10 = func_020b5250(func_020b502c(0x200000, func_020b57b4(pos.x - a.mUnk_00, data_0217b3c0->mUnk_7c)));
    out->mUnk_14 = func_020b5250(func_020b502c(0x200000, func_020b57b4(pos.z - a.mUnk_04, data_0217b3c0->mUnk_84)));
    out->mUnk_18 = out->mUnk_10 - 0x80;
    out->mUnk_1c = out->mUnk_14 - 0x60;
}

u16 func_020b5644(Unk02175628 *p, s32 mask) {
    return p->mBits & mask;
}

u16 func_020b5628(s32 idx, s32 mask) {
    return func_020b5644(&data_02175628[idx], mask);
}

void func_020b5290(void) {
    UnkPair020b502c lo;
    UnkPair020b502c hi;
    Vec3 target;
    Vec3 dir;

    func_020b6a18(&lo, &hi);
    if (func_020b5628(func_020435bc(), 0x20) != 0) {
        if (data_0217b3c0->mUnk_8c != 0) {
            data_0217b3c0->mUnk_90.x -= 0xa000;
            if (data_0217b3c0->mUnk_90.x < lo.mUnk_00) {
                data_0217b3c0->mUnk_90.x = lo.mUnk_00;
            }
        } else {
            func_0207a91c(&data_0217b3c0->mUnk_90, func_020b4d9c());
        }
        data_0217b3c0->mUnk_8c = 600;
    }
    if (func_020b5628(func_020435bc(), 0x10) != 0) {
        if (data_0217b3c0->mUnk_8c != 0) {
            data_0217b3c0->mUnk_90.x += 0xa000;
            if (data_0217b3c0->mUnk_90.x > hi.mUnk_00) {
                data_0217b3c0->mUnk_90.x = hi.mUnk_00;
            }
        } else {
            func_0207a91c(&data_0217b3c0->mUnk_90, func_020b4d9c());
        }
        data_0217b3c0->mUnk_8c = 600;
    }
    if (func_020b5628(func_020435bc(), 0x40) != 0) {
        if (data_0217b3c0->mUnk_8c != 0) {
            data_0217b3c0->mUnk_90.z -= 0xa000;
            if (data_0217b3c0->mUnk_90.z < lo.mUnk_04) {
                data_0217b3c0->mUnk_90.z = lo.mUnk_04;
            }
        } else {
            func_0207a91c(&data_0217b3c0->mUnk_90, func_020b4d9c());
        }
        data_0217b3c0->mUnk_8c = 600;
    }
    if (func_020b5628(func_020435bc(), 0x80) != 0) {
        if (data_0217b3c0->mUnk_8c != 0) {
            data_0217b3c0->mUnk_90.z += 0xa000;
            if (data_0217b3c0->mUnk_90.z > hi.mUnk_04) {
                data_0217b3c0->mUnk_90.z = hi.mUnk_04;
            }
        } else {
            func_0207a91c(&data_0217b3c0->mUnk_90, func_020b4d9c());
        }
        data_0217b3c0->mUnk_8c = 600;
    }
    if (data_0217b3c0->mUnk_8c != 0) {
        data_0217b3c0->mUnk_8c--;
        if (data_0217b3c0->mUnk_8c < 300) {
            func_0207a91c(&target, func_020b4d9c());
            data_0217b3c0->mUnk_8c = 300;
            Vec3Sub(&target, &data_0217b3c0->mUnk_90, &dir);
            Vec3NormalizeAndGetLengthUnchecked(&dir, &dir);
            Vec3AddScaled(0xa000, &dir, &data_0217b3c0->mUnk_90, &data_0217b3c0->mUnk_90);
            if (func_020b5250(target.x - data_0217b3c0->mUnk_90.x) *
                        func_020b5250(target.x - data_0217b3c0->mUnk_90.x) +
                    func_020b5250(target.z - data_0217b3c0->mUnk_90.z) *
                        func_020b5250(target.z - data_0217b3c0->mUnk_90.z) <
                func_020b5250(0xa000) * func_020b5250(0xa000)) {
                data_0217b3c0->mUnk_90 = target;
                data_0217b3c0->mUnk_8c = 0;
            }
        }
    }
    if (data_0217b3c0->mUnk_90.x < lo.mUnk_00) {
        data_0217b3c0->mUnk_90.x = lo.mUnk_00;
    }
    if (data_0217b3c0->mUnk_90.x > hi.mUnk_00) {
        data_0217b3c0->mUnk_90.x = hi.mUnk_00;
    }
    if (data_0217b3c0->mUnk_90.z < lo.mUnk_04) {
        data_0217b3c0->mUnk_90.z = lo.mUnk_04;
    }
    if (data_0217b3c0->mUnk_90.z > hi.mUnk_04) {
        data_0217b3c0->mUnk_90.z = hi.mUnk_04;
    }
}

s32 func_020b5270(s32 x) {
    return gPairsByAngle[(x >> 4) * 2 + 1];
}

s32 func_020b5258(s32 x) {
    return gPairsByAngle[(x >> 4) * 2];
}

s32 func_020b5250(s32 x) {
    return x >> 12;
}

s32 func_020b523c(void) {
    return data_021759c0->mUnk_57;
}

void func_020b503c(Unk020b503c *p, s32 scale) {
    s32 angle = func_020b6368();
    s32 a;
    s32 b;

    data_0217b3c0->mUnk_1c = func_020b5270(angle);
    data_0217b3c0->mUnk_1e = func_020b5258(angle);
    data_0217b3c0->mUnk_20 = func_020b502c(data_0217b3c0->mUnk_1c, scale);
    data_0217b3c0->mUnk_24 = func_020b502c(data_0217b3c0->mUnk_1e, scale);
    if (GetRaceHudSubScreenState() == 2) {
        func_020b5290();
    }
    data_0217b3c0->mUnk_18 = func_020b5250(DivFixed12(0xb0000, scale));
    scale = ReciprocalFixed12(scale);
    a = func_020b502c(data_0217b3c0->mUnk_1c, scale);
    b = func_020b502c(data_0217b3c0->mUnk_1e, scale);
    if (func_020b523c() != 0) {
        p[0].mUnk_00 = p[1].mUnk_00 = -a;
        p[0].mUnk_08 = p[1].mUnk_08 = b;
    } else {
        p[0].mUnk_00 = p[1].mUnk_00 = a;
        p[0].mUnk_08 = p[1].mUnk_08 = -b;
    }
    p[0].mUnk_04 = p[1].mUnk_04 = b;
    p[0].mUnk_0c = p[1].mUnk_0c = a;
    func_020b58f8(p);
    switch (func_020b4e5c()) {
        default:
            p[1] = p[0];
            break;
        case 0xe:
        case 0x12:
        case 0x14:
        case 0x1c:
        case 0x1e:
        case 0x21:
        case 0x26:
            func_020b57f8(&p[1]);
            break;
        case 0x30:
        case 0x32:
            func_020b5658(&p[1]);
            break;
    }
}

s32 func_020b502c(s32 a, s32 b) {
    return (s32) (((s64) a * b) >> 12);
}
