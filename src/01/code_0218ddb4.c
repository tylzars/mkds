#include "01/code_0218ddb4.h"

#include "01/code_02185ef4.h"
#include "01/code_0218d000.h"
#include "01/code_0218e000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_0218155c.h"
#include "01/code_02187cd4.h"
#include "01/code_02188158.h"
#include "01/code_02188484.h"
#include "01/code_0218f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_02188000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_0209b000.h"
#include "01/code_02181bd0.h"
#include "01/code_02187e78.h"
#include "01/code_02187eb0.h"
#include "01/code_0218f900.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2300.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "01/code_02181000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_02110000.h"
#include "Main/Unknown/code_020a128c.h"
#include "01/code_021882b8.h"
#include "01/code_02188cd8.h"
#include "01/code_02188e24.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_0210b708.h"
#include "01/code_02187000.h"
#include "Main/Unknown/code_020d22c0.h"
#include "01/code_02182000.h"
#include "01/code_02188950.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"

void func_ov001_0218f850(int a) {
    func_ov001_02188d64((Unk02188950 *) a, *(u32 *) (*(s32 *) (a + 0xa0) + 0x198),
                        *(u32 *) (*(s32 *) (a + 0xa0) + 0x19c));
    func_ov001_02188d1c((Unk02188950 *) a, *(u32 *) (*(s32 *) (a + 0xa0) + 0x1a0),
                        *(u32 *) (*(s32 *) (a + 0xa0) + 0x1a4));
    func_ov001_02188cec((Unk02188950 *) a, 0);
    func_ov001_02188c90((Unk02188950 *) a);
    func_ov001_021875c0((Unk02188950 *) a, (u32) 0, (u32) 0, (u32) 0, (u32) (((u32) 0x0000041eu)), (u32) 0);
    func_ov001_021875c0((Unk02188950 *) a, (u32) 0, (u32) 0, (u32) 0, (u32) (((u32) 0x0000041fu)), (u32) 0);
    func_ov001_021875c0((Unk02188950 *) a, (u32) 0, (u32) 0, (u32) 0, (u32) (((u32) 0x00000420u)), (u32) 0);
    func_020d2774((Unk020e71a0 *) (a), (u32) (((u32) 0x0000022du)));
    *(u16 *) (a + 2) = *(u16 *) (a + 2) | (*(u16 *) &data_ov001_021a65bc);
}

void func_ov001_0218f724(Unk02188950 *b) {
    Vec3 v1;
    Vec3 v2;
    u32 a;
    s32 i;
    s32 s;
    s32 c;
    s64 z;
    s64 x;
    func_021484d0(data_021759c0->mUnk_08 == 4 ? func_ov001_02181a94() : 0,
                  data_021759c0->mUnk_08 == 4 ? func_ov001_02181a88() : 0, &v1);
    v1.y = 0;
    a = 0;
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181a68();
    }
    a = (data_021759c0->mUnk_08 == 4 ? func_ov001_02181a78() : 0) - a;
    func_021484d0(&b->mUnk_000.mUnk_04, data_021759c0->mUnk_08 == 4 ? func_ov001_02181a94() : 0, &v2);
    for (i = 0; i < 1; i++) {
        c = data_0215d4b4[((u16) a >> 4) * 2 + 1];
        x = v2.x;
        s = data_0215d4b4[((u16) a >> 4) * 2];
        z = v2.z;
    }
    v1.x += (s32) (z * s >> 12) + (s32) (x * c >> 12) - v2.x;
    v1.z += (s32) (z * c >> 12) - (s32) (x * s >> 12) - v2.z;
    func_ov001_02188950(b, &v1);
}

void func_ov001_0218f6d8(Unk02188950 *a) {
    Vec3 local;
    func_021484d0(data_021759c0->mUnk_08 == 4 ? func_ov001_02181a94() : 0,
                  data_021759c0->mUnk_08 == 4 ? func_ov001_02181a88() : 0, &local);
    local.y = 0;
    func_ov001_02188950(a, &local);
}

s32 func_ov001_0218f688(Unk02188950 *a) {
    Unk0206bcb0 *obj = func_0207a974((u16) data_021759c0->mUnk_62);
    if ((obj->mUnk_48 & 0x200) == 0) {
        func_ov001_02188998(a, &obj->mUnk_80);
        func_ov001_02188d8c(a, (Vec3 *) (&obj->mUnk_80));
    }
    func_ov001_0218f6d8(a);
    return 0;
}

s32 func_ov001_0218f634(Unk02188950 *a) {
    Unk0206bcb0 *obj = func_0207a974((u16) data_021759c0->mUnk_62);
    if ((obj->mUnk_48 & 0x200) == 0) {
        func_ov001_02188998(a, &obj->mUnk_80);
        func_ov001_02188d8c(a, (Vec3 *) (&obj->mUnk_80));
    }
    func_ov001_0218f6d8(a);
    func_02061860();
    return 0;
}

void func_ov001_0218f57c(Unk02188950 *a) {
    Unk0206bcb0 *p;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(a, 5, func_ov001_0218f634);
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_1fc), (s32) (a->mUnk_0a0->mUnk_200));
    func_ov001_02188cd8(a, (s32) (a->mUnk_0a0->mUnk_204), (s32) (a->mUnk_0a0->mUnk_208));
    func_ov001_02188bc4(a, a->mUnk_0a0->mUnk_20c, a->mUnk_0a0->mUnk_210);
    func_ov001_02188998(a, &p->mUnk_80);
    func_ov001_021889c8(a);
    func_ov001_02188e24(a, (s32) (a->mUnk_0a0->mUnk_214), (UnkFunc *) (0));
    func_ov001_02188200(a, func_ov001_0218f9a8);
}

void func_ov001_0218f51c(Unk02188950 *a) {
    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(a, 5, func_ov001_0218f634);
    func_ov001_02188d30(a, (s32) (a->mUnk_0a0->mUnk_1f4), (s32) (a->mUnk_0a0->mUnk_1f8),
                        (UnkFunc *) (func_ov001_0218f57c));
    func_ov001_02188200(a, func_ov001_0218f9a8);
    func_ov001_021828f0();
}

void func_ov001_0218f454(Unk02188950 *a) {
    Unk0206bcb0 *p;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(a, 5, func_ov001_0218f634);
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_1d8), (s32) (a->mUnk_0a0->mUnk_1dc));
    func_ov001_02188cd8(a, (s32) (a->mUnk_0a0->mUnk_1e0), (s32) (a->mUnk_0a0->mUnk_1e4));
    func_ov001_02188c48(a, a->mUnk_0a0->mUnk_1e8, a->mUnk_0a0->mUnk_1ec);
    func_ov001_02188998(a, &p->mUnk_80);
    func_ov001_021889c8(a);
    func_ov001_02188e24(a, (s32) (a->mUnk_0a0->mUnk_1f0), (UnkFunc *) func_ov001_0218f51c);
    func_ov001_02188200(a, func_ov001_0218f9a8);
    func_020d2774(&a->mUnk_000, (u32) (0x229));
}

s32 func_ov001_0218f3ec(Unk02188950 *a) {
    Unk0206bcb0 *p;
    Vec3 v;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    if ((p->mUnk_48 & 0x200) == 0) {
        func_02147fd8(a->mUnk_0a0->mUnk_21c, &p->mUnk_68, &p->mUnk_80, &v);
        func_ov001_02188998(a, &v);
        func_ov001_02188d8c(a, (Vec3 *) (&v));
    }
    func_ov001_0218f6d8(a);
    func_02061860();
    return 0;
}

s32 func_ov001_0218f3ac(Unk02188950 *a) {
    Unk0206bcb0 *p;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    if ((p->mUnk_48 & 0x200) == 0) {
        func_ov001_02188998(a, &p->mUnk_80);
    }
    func_ov001_0218f6d8(a);
    return 0;
}

void func_ov001_0218f2a8(Unk02188950 *a) {
    Unk0206bcb0 *p;
    Vec3 v;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    func_02147fd8(a->mUnk_0a0->mUnk_21c, &p->mUnk_68, &p->mUnk_80, &v);
    func_ov001_02187218(a, 5, func_ov001_0218f3ac);
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_0ec), (s32) (a->mUnk_0a0->mUnk_0f0));
    func_ov001_02188d1c(a, (s32) (a->mUnk_0a0->mUnk_0f4), (s32) (a->mUnk_0a0->mUnk_0f8));
    func_ov001_02188cd8(a, (s32) (a->mUnk_0a0->mUnk_0fc), (s32) (a->mUnk_0a0->mUnk_100));
    func_ov001_02188c48(a, a->mUnk_0a0->mUnk_104, a->mUnk_0a0->mUnk_108);
    func_ov001_02188de0(a, (s32) (a->mUnk_0a0->mUnk_218), 0, (Vec3 *) (&v), (UnkFunc *) (func_ov001_0218f454));
    if (data_0217d20c != 2) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 2;
    func_ov001_02188200(a, func_ov001_0218e298);
    a->mUnk_000.mUnk_02 |= data_ov001_021a65b0;
}

s32 func_ov001_0218f244(Unk02188950 *a) {
    Unk0206bcb0 *p;
    Vec3 v;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    if ((p->mUnk_48 & 0x200) == 0) {
        func_02147fd8(-a->mUnk_0a0->mUnk_0e8, &p->mUnk_68, &p->mUnk_80, &v);
        func_ov001_02188998(a, &v);
        func_ov001_02188d8c(a, (Vec3 *) (&v));
    }
    func_ov001_0218f6d8(a);
    return 0;
}

void func_ov001_0218f16c(Unk02188950 *a) {
    Unk0206bcb0 *p;
    Vec3 v;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    func_02147fd8(-a->mUnk_0a0->mUnk_0e8, &p->mUnk_68, &p->mUnk_80, &v);
    func_ov001_02187218(a, 3, func_ov001_0218f244);
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_0c4), (s32) (a->mUnk_0a0->mUnk_0c8));
    func_ov001_02188d1c(a, (s32) (a->mUnk_0a0->mUnk_0cc), (s32) (a->mUnk_0a0->mUnk_0d0));
    func_ov001_02188cd8(a, (s32) (a->mUnk_0a0->mUnk_0d4), (s32) (a->mUnk_0a0->mUnk_0d8));
    func_ov001_02188c48(a, a->mUnk_0a0->mUnk_0dc, a->mUnk_0a0->mUnk_0e0);
    func_ov001_02188de0(a, (s32) (a->mUnk_0a0->mUnk_0e4), 0, (Vec3 *) (&v), (UnkFunc *) (func_ov001_0218f2a8));
    if (data_0217d20c != 1) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 1;
}

s32 func_ov001_0218efc4(Unk02188950 *a) {
    Unk0206bcb0 *p;
    float f;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    if ((p->mUnk_48 & 0x200) == 0) {
        func_ov001_02188998(a, &p->mUnk_80);
        func_ov001_02188d8c(a, (Vec3 *) (&p->mUnk_80));
    }
    func_ov001_0218f724(a);
    if (func_ov001_02188104(a, (s32) (a->mUnk_0a0->mUnk_0b8), 0) == 0) {
        a->mUnk_1c4 = a->mUnk_0a0->mUnk_0c0;
    } else {
        a->mUnk_1c4 = 0;
    }
    a->mUnk_170 = a->mUnk_0a0->mUnk_09c;
    if (a->mUnk_0a0->mUnk_1cc - (data_021759c0->mUnk_08 == 4 ? (s32) func_ov001_02181838() : 0) > 0) {
        f = 0.5f +
            (float) ((a->mUnk_0a0->mUnk_1cc - (data_021759c0->mUnk_08 == 4 ? (s32) func_ov001_02181838() : 0)) << 12);
    } else {
        f = (float) ((a->mUnk_0a0->mUnk_1cc - (data_021759c0->mUnk_08 == 4 ? (s32) func_ov001_02181838() : 0)) << 12) -
            0.5f;
    }
    a->mUnk_16c = (s32) f / a->mUnk_0a0->mUnk_1d4;
    if ((data_021759c0->mUnk_08 == 4 ? (s32) func_ov001_02181838() : 0) <= a->mUnk_0a0->mUnk_1d0 &&
        func_ov001_02188000(a, 0, (s32) (a->mUnk_0a0->mUnk_0bc)) != 0) {
        func_ov001_02188200(a, func_ov001_0218f9a8);
        a->mUnk_000.mUnk_02 |= data_ov001_021a65b0;
        func_ov001_0218f16c(a);
    } else if ((data_021759c0->mUnk_08 == 4 ? (s32) func_ov001_02181838() : 0) > a->mUnk_0a0->mUnk_1cc) {
        func_ov001_02188e88(a);
    }
    return 0;
}

void func_ov001_0218ef30(Unk02188950 *a) {
    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(a, 3, func_ov001_0218efc4);
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_090), (s32) (a->mUnk_0a0->mUnk_094));
    func_ov001_02188cec(a, (s32) (a->mUnk_0a0->mUnk_0a0));
    func_ov001_02188adc(a, a->mUnk_0a0->mUnk_0b0, 0x270f000, a->mUnk_0a0->mUnk_0a8, 0x270f000, 0);
    if (data_0217d20c != 0) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 0;
}

void func_ov001_0218ee88(Unk02188950 *a) {
    Unk0206bcb0 *p;
    Vec3 v;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    func_02147fd8(-a->mUnk_0a0->mUnk_0e8, &p->mUnk_68, &p->mUnk_80, &v);
    a->mUnk_000.mUnk_04.x = v.x;
    a->mUnk_000.mUnk_04.y = a->mUnk_000.mUnk_9c->mUnk_00.y + a->mUnk_0a0->mUnk_080;
    a->mUnk_000.mUnk_04.z = v.z;
    a->mUnk_1a8 =
        (u16) (func_02148714(p->mUnk_80.x - a->mUnk_000.mUnk_04.x, p->mUnk_80.z - a->mUnk_000.mUnk_04.z) + 0x4000);
    a->mUnk_184 = a->mUnk_1a8;
    func_ov001_0218ef30(a);
    func_ov001_02182a3c(0);
    a->mUnk_000.mUnk_02 &= ~1;
}

void func_ov001_0218edc8(Unk02188950 *a) {
    Unk0206bcb0 *p;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(a, 3, func_ov001_0218f634);
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_144), (s32) (a->mUnk_0a0->mUnk_148));
    func_ov001_02188d1c(a, (s32) (a->mUnk_0a0->mUnk_14c), (s32) (a->mUnk_0a0->mUnk_150));
    func_ov001_02188cd8(a, (s32) (a->mUnk_0a0->mUnk_154), (s32) (a->mUnk_0a0->mUnk_158));
    func_ov001_02188c48(a, a->mUnk_0a0->mUnk_15c, a->mUnk_0a0->mUnk_160);
    func_ov001_02188998(a, &p->mUnk_80);
    func_ov001_02188e24(a, (s32) (a->mUnk_0a0->mUnk_164), (UnkFunc *) (0));
}

u32 func_ov001_0218edb8(void) {
    func_02061860();
    return 0;
}

void func_ov001_0218ec40(Unk02188950 *a) {
    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(a, 1, (s32(*)(Unk02188950 *)) func_ov001_0218edb8);
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_118), (s32) (a->mUnk_0a0->mUnk_11c));
    func_ov001_02188d1c(a, (s32) (a->mUnk_0a0->mUnk_120), (s32) (a->mUnk_0a0->mUnk_124));
    if (a->mUnk_0a8 == 1) {
        func_ov001_02188cd8(a, (s32) (a->mUnk_0a0->mUnk_128), (s32) (a->mUnk_0a0->mUnk_12c));
        func_ov001_02188c48(a, a->mUnk_0a0->mUnk_130, a->mUnk_0a0->mUnk_134);
    } else if (a->mUnk_0a8 == 2) {
        func_ov001_02188cd8(a, (s32) (a->mUnk_0a0->mUnk_220), (s32) (a->mUnk_0a0->mUnk_224));
        func_ov001_02188c48(a, a->mUnk_0a0->mUnk_228, a->mUnk_0a0->mUnk_22c);
    } else if (a->mUnk_0a8 == 3) {
        func_ov001_02188cd8(a, (s32) (a->mUnk_0a0->mUnk_230), (s32) (a->mUnk_0a0->mUnk_234));
        func_ov001_02188c48(a, a->mUnk_0a0->mUnk_238, a->mUnk_0a0->mUnk_23c);
    }
    func_ov001_02188998(a, ((Vec3 *) func_ov001_02187fc0(a)));
    func_ov001_02188de0(a, (s32) (a->mUnk_0a0->mUnk_138), (s32) (a->mUnk_0a0->mUnk_13c),
                        (Vec3 *) (((Vec3 *) func_ov001_02187fc0(a))), (UnkFunc *) (0));
    if (data_0217d20c != 5) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 5;
}

void func_ov001_0218eb94(Unk02188950 *a) {
    Unk020f41c4_B *rng;
    func_0207a974((u16) data_021759c0->mUnk_62);
    rng = func_020d22d0();
    rng->mUnk_00 = (s64) rng->mUnk_08 * (s64) rng->mUnk_00 + rng->mUnk_10;
    a->mUnk_000.mUnk_04.x = ((Vec3 *) func_ov001_02187fc0(a))->x;
    a->mUnk_000.mUnk_04.y = a->mUnk_0a0->mUnk_080 + ((Vec3 *) func_ov001_02187fc0(a))->y;
    a->mUnk_000.mUnk_04.z = ((Vec3 *) func_ov001_02187fc0(a))->z;
    func_ov001_02187218(a, 5, (s32(*)(Unk02188950 *)) func_ov001_0218edb8);
    func_ov001_0218f900(a);
    func_ov001_02188e24(a, a->mUnk_0a0->mUnk_1b4, 0);
    if (data_0217d20c != 5) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 5;
}

void func_ov001_0218ead0(Unk02188950 *a) {
    int v1;
    u32 v2;

    func_ov001_02187218(a, 5, (s32(*)(Unk02188950 *)) func_ov001_0218edb8);
    func_ov001_0218f850((s32) a);
    func_ov001_02188e24(a, a->mUnk_0a0->mUnk_1a8, (UnkFunc *) func_ov001_0218eb94);
    func_ov001_02182a3c(0);
    func_ov001_02187e48(a, a->mUnk_0a0->mUnk_140);
    v1 = a->mUnk_0a8;
    if (v1 == 1) {
        v2 = 2;
    } else if (v1 == 2) {
        v2 = 3;
    } else if (v1 == 3) {
        v2 = 3;
    } else {
        v2 = 1;
    }
    a->mUnk_0a8 = v2;
    if (data_0217d20c != 3) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 3;
    a->mUnk_270 = a->mUnk_0a0->mUnk_00c;
    a->mUnk_264 = a->mUnk_270;
    a->mUnk_268 = a->mUnk_264;
    a->mUnk_25c = a->mUnk_268;
}

u32 func_ov001_0218ea98(int a) {
    int v1;
    int v2;
    v2 = *(s32 *) (*(s32 *) (a + 0x9c) + 4) + *(s32 *) (*(s32 *) (a + 0xa0) + 0x84);
    v1 = *(s32 *) (a + 8) - *(s32 *) (*(s32 *) (a + 0xa0) + 0x88);
    if (v1 <= v2) {
        v1 = v2;
    }
    *(s32 *) (a + 8) = v1;
    func_02061860();
    return 0;
}

void func_ov001_0218e92c(Unk02188950 *p) {
    func_ov001_02187218(p, 5, (s32(*)(Unk02188950 *)) func_ov001_0218ea98);
    func_ov001_02188d64(p, p->mUnk_0a0->mUnk_170, p->mUnk_0a0->mUnk_174);
    func_ov001_02188d1c(p, p->mUnk_0a0->mUnk_178, p->mUnk_0a0->mUnk_17c);
    func_ov001_02188c90(p);
    func_ov001_02188cec(p, 0);
    func_ov001_02188e24(p, p->mUnk_0a0->mUnk_194, func_ov001_0218ead0);
    func_ov001_021875c0(p, 0, 0, 0, 0x431, 0);
    func_ov001_021875c0(p, 0, 0, 0, 0x430, 0);
    func_ov001_021875c0(p, 0, 0, 0, 0x432, 0);
    if (data_0217d20c != 4) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 4;
    func_ov001_02188200(p, func_ov001_0218e38c);
    p->mUnk_000.mUnk_02 |= data_ov001_021a65b0;
    func_ov001_02182a3c(p->mUnk_0a0->mUnk_18c < (data_021759c0->mUnk_08 == 4 ? (s32) func_ov001_02181800() : 0)
                            ? p->mUnk_0a0->mUnk_18c
                            : (data_021759c0->mUnk_08 == 4 ? (s32) func_ov001_02181800() : 0));
    p->mUnk_25c = p->mUnk_268 = p->mUnk_264 = p->mUnk_270 = (s32) p->mUnk_0a0->mUnk_00c / 2;
}

void func_ov001_0218e8d8(Unk02188950 *a) {
    func_ov001_02187218(a, 5, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(a, (s32) (a->mUnk_0a0->mUnk_168), (s32) (a->mUnk_0a0->mUnk_16c),
                        (UnkFunc *) &func_ov001_0218e92c);
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
    func_ov001_02182a3c(0);
    func_020d2774(&a->mUnk_000, (u32) (((u32) 0x00000230u)));
}

void func_ov001_0218e8b0(Unk02188950 *a) {
    func_ov001_02187218(a, 1, (s32(*)(Unk02188950 *))(0));
    func_ov001_021888a4(a, 0, (s32) (((u32) 0x00019000u)));
    func_0206184c();
    func_ov001_021827f0();
}

void func_ov001_0218e860(Unk02188950 *a) {
    func_ov001_02187218(a, 5, (s32(*)(Unk02188950 *)) func_ov001_0218f688);
    func_ov001_0218f850((s32) a);
    func_ov001_02188e24(a, a->mUnk_0a0->mUnk_1a8, (UnkFunc *) func_ov001_0218e8b0);
    if (data_0217d20c != 3) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 3;
}

void func_ov001_0218e7d0(Unk02188950 *p) {
    func_ov001_02187218(p, 1, 0);
    func_ov001_021888a4(p, 0, 0x19000);
    func_ov001_02188d64(p, p->mUnk_0a0->mUnk_198, p->mUnk_0a0->mUnk_19c);
    func_ov001_02188d1c(p, p->mUnk_0a0->mUnk_1a0, p->mUnk_0a0->mUnk_1a4);
    func_ov001_02188cec(p, 0);
    func_ov001_02188c90(p);
    if (data_0217d20c != 3) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 3;
    p->mUnk_000.mUnk_02 |= data_ov001_021a65bc;
}

void func_ov001_0218e7b0(Unk02188950 *a) {
    func_ov001_02187218(a, 1, (s32(*)(Unk02188950 *))(0));
    func_ov001_021888a4(a, 0, (s32) (((u32) 0x00019000u)));
}

void func_ov001_0218e760(Unk02188950 *p) {
    func_ov001_02187218(p, 5, func_ov001_0218f688);
    func_ov001_0218f850((s32) p);
    func_ov001_02188e24(p, p->mUnk_0a0->mUnk_1a8, func_ov001_0218e7b0);
    if (data_0217d20c != 3) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 3;
}

void func_ov001_0218e710(Unk02188950 *p) {
    func_ov001_02187218(p, 8, 0);
    func_ov001_02188d64(p, p->mUnk_0a0->mUnk_078, p->mUnk_0a0->mUnk_07c);
    func_ov001_02188c90(p);
    func_ov001_02188cec(p, 0);
    if (data_0217d20c != 6) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 6;
    func_0206184c();
}

void func_ov001_0218e690(Unk02188950 *p) {
    func_ov001_02187218(p, 8, 0);
    func_ov001_02188d64(p, p->mUnk_0a0->mUnk_070, p->mUnk_0a0->mUnk_074);
    func_0208b7bc(0x3fe, &p->mUnk_000.mUnk_04);
    func_0208b7bc(0x3fd, &p->mUnk_000.mUnk_04);
    if (data_0217d20c != 7) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 7;
    p->mUnk_000.mUnk_02 |= data_ov001_021a65b4;
    p->mUnk_000.mUnk_02 |= data_ov001_021a65b8;
    p->mUnk_000.mUnk_02 |= data_ov001_021a65bc;
}

s32 func_ov001_0218e650(Unk02188950 *a) {
    if (a->mUnk_0b0 == 50) {
        Unk021a7c08 local = {0x22f, 0, 0xe, 0};
        local.mUnk_04 = &a->mUnk_000.mUnk_04;
        local.mUnk_0c = func_020d4ef4(&a->mUnk_000.mUnk_04);
        func_0210b734(&local, func_02108e7c());
    }
    return 0;
}

void func_ov001_0218e5c4(Unk02188950 *a) {
    a->mUnk_000.mUnk_04.y += a->mUnk_0a0->mUnk_080;
    a->mUnk_168 = a->mUnk_16c = 0x1f000;
    a->mUnk_170 = 0;
    func_ov001_02187218(a, 8, func_ov001_0218e650);
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_070), (s32) (a->mUnk_0a0->mUnk_074));
    func_ov001_02188e24(a, 0x3c, func_ov001_0218e690);
    if (data_0217d20c != 7) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 7;
    a->mUnk_000.mUnk_02 &= ~1;
}

void func_ov001_0218e594(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_070), (s32) (a->mUnk_0a0->mUnk_074));
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
    return;
}

void func_ov001_0218e58c(void) {
    func_ov001_021882b8();
}

void func_ov001_0218e564(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(a, a->mUnk_0a0->mUnk_058, a->mUnk_0a0->mUnk_05c, func_ov001_0218e760);
}

void func_ov001_0218e520(Unk02188950 *a) {
    a->mUnk_000.mUnk_04.y += a->mUnk_0a0->mUnk_080;
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, a->mUnk_0a0->mUnk_04c, a->mUnk_0a0->mUnk_050);
    func_ov001_02188e24(a, a->mUnk_0a0->mUnk_054, func_ov001_0218e564);
}

void func_ov001_0218e508(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_0218f900(a);
}

void func_ov001_0218e4ac(Unk02188950 *a) {
    a->mUnk_000.mUnk_04.y += a->mUnk_0a0->mUnk_080;
    a->mUnk_16c = 0;
    a->mUnk_168 = a->mUnk_16c;
    a->mUnk_168 = 0;
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, a->mUnk_0a0->mUnk_034, a->mUnk_0a0->mUnk_038);
    func_ov001_02188e24(a, a->mUnk_0a0->mUnk_03c, func_ov001_0218e508);
}

void func_ov001_0218e474(Unk02188950 *a) {
    a->mUnk_000.mUnk_94 = func_02036bec((void *) func_020364e0(func_020364e8()), 0x44);
    func_02109110((Unk0210bfbc *) (a->mUnk_000.mUnk_94), (u32) (0xe), (Vec3 *) (&a->mUnk_000.mUnk_04));
    a->mUnk_000.mUnk_70 = data_0217cc6c[6];
}

void func_ov001_0218e38c(Unk02188950 *a, Unk0206bcb0 *b) {
    a->mUnk_000.mUnk_10.x = ((s64) -a->mUnk_0a0->mUnk_024 * data_0215d4b4[(b->mUnk_236 >> 4) * 2]) >> 12;
    a->mUnk_000.mUnk_10.y = 0;
    a->mUnk_000.mUnk_10.z = ((s64) -a->mUnk_0a0->mUnk_024 * data_0215d4b4[(b->mUnk_236 >> 4) * 2 + 1]) >> 12;
    func_ov001_021829ac(a->mUnk_0a0->mUnk_190);
    func_ov001_0218ead0(a);
    a->mUnk_2d8 = 0;
    func_ov001_02188200(a, func_ov001_0218f9a8);
    func_ov001_0218e860(a);
    a->mUnk_0a8 = 0;
    func_020d2774(&a->mUnk_000, (u32) (0x22c));
    a->mUnk_25c = a->mUnk_268 = a->mUnk_264 = a->mUnk_270 = a->mUnk_0a0->mUnk_00c;
}

void func_ov001_0218e344(Unk02188950 *a) {
    int v1;
    v1 = func_ov001_021871f8(a, 5);
    if (v1 != 0) {
        func_ov001_0218edc8(a);
    }
    a->mUnk_2d8 = 0xd;
    func_ov001_02188200(a, func_ov001_0218e344);
    if (a->mUnk_2d0 == 0) {
        func_020d2774(&a->mUnk_000, (u32) (((u32) 0x00000234u)));
    }
}

void func_ov001_0218e298(Unk02188950 *a, Unk0206bcb0 *b) {
    func_ov001_02182bbc((u16) a->mUnk_0a0->mUnk_110);
    a->mUnk_000.mUnk_10.x = 0;
    a->mUnk_000.mUnk_10.y = a->mUnk_0a0->mUnk_114;
    a->mUnk_000.mUnk_10.z = 0;
    a->mUnk_2d8 = 0xc;
    a->mUnk_158 = func_ov001_0218f3ec;
    func_ov001_02188200(a, func_ov001_0218f9a8);
    func_02073fb0(a->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
    func_02068a10(b);
    func_ov001_021888a4(a, 0, 0x32000);
    a->mUnk_0a8 = 1;
    if (!(data_021759c0->mUnk_08 == 4 ? func_020a126c() : 0)) {
        func_02061874();
    }
}

void func_ov001_0218e208(Unk0218d87c *a) {
    s32 i;
    Unk02188950 *obj;
    Unk02188950_a0 *a0;

    if (a != 0) {
        for (i = 0; i < a->mUnk_04 && (obj = a->mUnk_00[i]) != 0; i++) {
            if (func_02062ec4() != 0) {
                func_ov001_0218e4ac(obj);
            } else {
                func_ov001_0218e520(obj);
            }
            if (data_021759c0->mUnk_08 == 4) {
                a0 = obj->mUnk_0a0;
                func_ov001_02181844(a0->mUnk_1b8, a0->mUnk_1bc, a0->mUnk_1c0, a0->mUnk_1c4);
            }
        }
    }
    func_020a2314((void (*)(void)) func_ov001_0218e58c);
}

void func_ov001_0218df20(u32 a, Unk02188950 *b) {
    Unk0206bcb0 *p;

    if (data_021759c0->mUnk_08 == 4 ? func_020a126c() : 0) {
        if (func_ov001_021871f8(b, 5) != 0) {
            if (data_021759c0->mUnk_08 == 4 ? func_020a1084((u16) data_021759c0->mUnk_62) : 0) {
                func_ov001_0218e710(b);
            } else if (data_021759c0->mUnk_08 == 4 ? func_020a128c() : 0) {
                func_ov001_0218e5c4(b);
            } else {
                func_ov001_0218e594(b);
            }
        }
    } else {
        if (b->mUnk_0a8 != 0) {
            if (func_ov001_021871f8(b, 5) != 0) {
                p = func_0207a974((u16) data_021759c0->mUnk_62);
                if (p->mUnk_180 == 0 && (p->mUnk_48 & 0x200) == 0 &&
                    func_ov001_02188104(b, 0, b->mUnk_0a0->mUnk_184) != 0 &&
                    func_ov001_02188000(b, 0, b->mUnk_0a0->mUnk_180) != 0 &&
                    func_ov001_02188104(b, b->mUnk_0a0->mUnk_188, 0) != 0) {
                    func_ov001_0218e8d8(b);
                }
            }
            if (func_ov001_021871f8(b, 3) != 0) {
                if (func_ov001_021881a8(b, (Vec3 *) func_ov001_02187fc0(b), (s32) (b->mUnk_0a0->mUnk_138), 0) != 0) {
                    func_ov001_02187e78(b);
                }
                func_ov001_02188200(b, func_ov001_0218e344);
                b->mUnk_000.mUnk_02 &= ~0x40;
                func_ov001_02182a3c(0);
                func_ov001_0218ec40(b);
            }
        } else {
            p = func_0207a974((u16) data_021759c0->mUnk_62);
            if (p->mUnk_48 & 0x200) {
                if (data_021759c0->mUnk_08 == 4 ? func_ov001_02181820() : 0) {
                    if (data_021759c0->mUnk_08 == 4) {
                        func_ov001_0218182c((u16) b->mUnk_0a0->mUnk_1bc);
                    }
                } else {
                    if (data_021759c0->mUnk_08 == 4) {
                        func_ov001_0218182c(0);
                    }
                }
                if ((b->mUnk_000.mUnk_02 & 1) == 0) {
                    func_ov001_02188200(b, func_ov001_0218f9a8);
                    b->mUnk_000.mUnk_02 |= data_ov001_021a65b0;
                    func_ov001_0218e7d0(b);
                }
            }
            if (data_021759c0->mUnk_08 == 4 ? func_ov001_02181838() : 0) {
                if (func_ov001_021871f8(b, 3) != 0) {
                    if ((s32) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181838() : 0) < b->mUnk_0a0->mUnk_1c8) {
                        if (b->mUnk_000.mUnk_02 & 1) {
                            func_ov001_02188200(b, func_ov001_0218f9a8);
                            b->mUnk_000.mUnk_02 |= data_ov001_021a65b0;
                            func_ov001_0218ee88(b);
                        } else {
                            func_ov001_02188200(b, func_ov001_0218f9a8);
                            b->mUnk_000.mUnk_02 |= data_ov001_021a65b0;
                            func_ov001_0218ef30(b);
                        }
                    } else if ((b->mUnk_000.mUnk_02 & 1) == 0) {
                        func_ov001_02188200(b, func_ov001_0218f9a8);
                        b->mUnk_000.mUnk_02 |= data_ov001_021a65b0;
                        func_ov001_0218e7d0(b);
                    }
                }
            }
        }
        if (data_0217d20c == 0) {
            func_02110350(b->mUnk_000.mUnk_94);
        } else if (func_02110324() != 0) {
            func_020d275c(&b->mUnk_000, (u32) (0x22a));
        } else if (data_0217d20c == 4) {
            func_020d275c(&b->mUnk_000, (u32) (0x22b));
        }
    }
    func_ov001_021864ac(a, b);
}

void func_ov001_0218de50(Unk0218d87c *a) {
    int i;
    Unk02188950 *p;
    Unk02188950_a0 *a0;

    if (a != 0) {
        for (i = 0; i < a->mUnk_04 && (p = a->mUnk_00[i]) != 0; i++) {
            if (data_021759c0->mUnk_08 == 4) {
                func_ov001_02181b8c(p);
            }
            func_ov001_021870e4(a, p, data_ov001_021a7da0, data_ov001_021a7db4,
                                data_ov001_021a7dc8);
            func_ov001_021870b0(a, p, data_ov001_021a7dd8);
            a0 = p->mUnk_0a0;
            func_ov001_0218875c(p, (s32) (a0->mUnk_008), (s32) (a0->mUnk_00c), (s32) (a0->mUnk_240));
            func_ov001_021888a4(p, 0, 0x19000);
            func_ov001_02188200(p, func_ov001_0218f9a8);
            func_ov001_02187cd4((s32) p, 0);
            p->mUnk_000.mUnk_02 |= data_ov001_021a65b0;
            p->mUnk_2b8 = 3;
        }
    }
}

void func_ov001_0218de14(u32 a, int b) {
    func_ov001_02186368((void *) a, (Unk02188950 *) b);
    if (*(s32 *) (b + 0xa8) == 0) {
        func_ov001_021861f4((void *) a, (Unk02188950 *) b, 0);
        return;
    }
    func_ov001_021861f4((void *) a, (Unk02188950 *) b, 1);
}

void func_ov001_0218dde8(void) {
    void *v6 = &func_ov001_02185fb0;
    void *v7 = &func_ov001_02185f04;
    void *v8 = &func_ov001_021860cc;
    u32 v10 =
        (u32) func_ov001_0219b510(v6, v7, v8, (u32) 0x2u, (u16) ((u32) 0x0u), (u16) ((u32) 0x0u), (u16) ((u32) 0x0u));
}

void *func_ov001_0218ddcc(void) {
    return (void *) func_0209bf1c(func_ov001_0218de50, func_ov001_0218de14, func_ov001_02187098);
}

void *func_ov001_0218ddb4(void) {
    return (void *) func_0209bf48(func_ov001_0218e208, func_ov001_0218df20, 0);
}
