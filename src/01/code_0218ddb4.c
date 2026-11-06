#include "01/code_0218ddb4.h"
#include "01/code_02187d14.h"
#include "01/code_02188de0.h"

#include "01/code_02185ef4.h"
#include "01/code_0218d000.h"
#include "01/code_0218e000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_0218155c.h"
#include "01/code_02187cd4.h"
#include "01/code_02188158.h"
#include "01/code_02188484.h"
#include "01/code_0218f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_02110100.h"
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
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
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

void func_ov001_0218f850(Unk02188950 *a) {
    func_ov001_02188d64(a, a->mPrm->mUnk_198, a->mPrm->mUnk_19c);
    func_ov001_02188d1c(a, a->mPrm->mUnk_1a0, a->mPrm->mUnk_1a4);
    func_ov001_02188cec(a, 0);
    func_ov001_02188c90(a);
    func_ov001_021875c0(a, 0, 0, 0, 0x41e, 0);
    func_ov001_021875c0(a, 0, 0, 0, 0x41f, 0);
    func_ov001_021875c0(a, 0, 0, 0, 0x420, 0);
    StartMapObjectSound(&a->mUnk_000, 0x22d);
    a->mUnk_000.mFlags = a->mUnk_000.mFlags | data_ov001_021a65bc;
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
    Vec3Sub(data_021759c0->mMode == MODE_MISSION_RUN ? func_ov001_02181a94() : 0,
            data_021759c0->mMode == MODE_MISSION_RUN ? func_ov001_02181a88() : 0, &v1);
    v1.y = 0;
    a = 0;
    if (data_021759c0->mMode == MODE_MISSION_RUN) {
        a = func_ov001_02181a68();
    }
    a = (data_021759c0->mMode == MODE_MISSION_RUN ? func_ov001_02181a78() : 0) - a;
    Vec3Sub(&b->mUnk_000.mPos, data_021759c0->mMode == MODE_MISSION_RUN ? func_ov001_02181a94() : 0, &v2);
    for (i = 0; i < 1; i++) {
        c = gPairsByAngle[((u16) a >> 4) * 2 + 1];
        x = v2.x;
        s = gPairsByAngle[((u16) a >> 4) * 2];
        z = v2.z;
    }
    v1.x += (s32) (z * s >> 12) + (s32) (x * c >> 12) - v2.x;
    v1.z += (s32) (z * c >> 12) - (s32) (x * s >> 12) - v2.z;
    SetVelocity(b, &v1);
}

void func_ov001_0218f6d8(Unk02188950 *a) {
    Vec3 local;
    Vec3Sub(data_021759c0->mMode == MODE_MISSION_RUN ? func_ov001_02181a94() : 0,
            data_021759c0->mMode == MODE_MISSION_RUN ? func_ov001_02181a88() : 0, &local);
    local.y = 0;
    SetVelocity(a, &local);
}

s32 func_ov001_0218f688(Unk02188950 *a) {
    Kart *obj = GetKart((u16) data_021759c0->mEntryIndex);
    if ((obj->mUnk_48 & 0x200) == 0) {
        SetAnglePointAndMoveAnglePoint(a, &obj->mPos);
        func_ov001_02188d8c(a, (&obj->mPos));
    }
    func_ov001_0218f6d8(a);
    return 0;
}

s32 func_ov001_0218f634(Unk02188950 *a) {
    Kart *obj = GetKart((u16) data_021759c0->mEntryIndex);
    if ((obj->mUnk_48 & 0x200) == 0) {
        SetAnglePointAndMoveAnglePoint(a, &obj->mPos);
        func_ov001_02188d8c(a, (&obj->mPos));
    }
    func_ov001_0218f6d8(a);
    func_02061860();
    return 0;
}

void func_ov001_0218f57c(Unk02188950 *a) {
    Kart *p;

    p = GetKart((u16) data_021759c0->mEntryIndex);
    func_ov001_02187218(a, 5, func_ov001_0218f634);
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_1fc), (s32) (a->mPrm->mUnk_200));
    func_ov001_02188cd8(a, (s32) (a->mPrm->mUnk_204), (s32) (a->mPrm->mUnk_208));
    func_ov001_02188bc4(a, a->mPrm->mUnk_20c, a->mPrm->mUnk_210);
    SetAnglePointAndMoveAnglePoint(a, &p->mPos);
    func_ov001_021889c8(a);
    func_ov001_02188e24(a, (s32) (a->mPrm->mUnk_214), (UnkFunc *) (0));
    func_ov001_02188200(a, func_ov001_0218f9a8);
}

void func_ov001_0218f51c(Unk02188950 *a) {
    GetKart((u16) data_021759c0->mEntryIndex);
    func_ov001_02187218(a, 5, func_ov001_0218f634);
    func_ov001_02188d30(a, (s32) (a->mPrm->mUnk_1f4), (s32) (a->mPrm->mUnk_1f8), (UnkFunc *) (func_ov001_0218f57c));
    func_ov001_02188200(a, func_ov001_0218f9a8);
    func_ov001_021828f0();
}

void func_ov001_0218f454(Unk02188950 *a) {
    Kart *p;

    p = GetKart((u16) data_021759c0->mEntryIndex);
    func_ov001_02187218(a, 5, func_ov001_0218f634);
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_1d8), (s32) (a->mPrm->mUnk_1dc));
    func_ov001_02188cd8(a, (s32) (a->mPrm->mUnk_1e0), (s32) (a->mPrm->mUnk_1e4));
    func_ov001_02188c48(a, a->mPrm->mUnk_1e8, a->mPrm->mUnk_1ec);
    SetAnglePointAndMoveAnglePoint(a, &p->mPos);
    func_ov001_021889c8(a);
    func_ov001_02188e24(a, (s32) (a->mPrm->mUnk_1f0), (UnkFunc *) func_ov001_0218f51c);
    func_ov001_02188200(a, func_ov001_0218f9a8);
    StartMapObjectSound(&a->mUnk_000, (u32) (0x229));
}

s32 func_ov001_0218f3ec(Unk02188950 *a) {
    Kart *p;
    Vec3 v;

    p = GetKart((u16) data_021759c0->mEntryIndex);
    if ((p->mUnk_48 & 0x200) == 0) {
        Vec3AddScaled(a->mPrm->mUnk_21c, &p->mUnk_68, &p->mPos, &v);
        SetAnglePointAndMoveAnglePoint(a, &v);
        func_ov001_02188d8c(a, (&v));
    }
    func_ov001_0218f6d8(a);
    func_02061860();
    return 0;
}

s32 func_ov001_0218f3ac(Unk02188950 *a) {
    Kart *p;

    p = GetKart((u16) data_021759c0->mEntryIndex);
    if ((p->mUnk_48 & 0x200) == 0) {
        SetAnglePointAndMoveAnglePoint(a, &p->mPos);
    }
    func_ov001_0218f6d8(a);
    return 0;
}

void func_ov001_0218f2a8(Unk02188950 *a) {
    Kart *p;
    Vec3 v;

    p = GetKart((u16) data_021759c0->mEntryIndex);
    Vec3AddScaled(a->mPrm->mUnk_21c, &p->mUnk_68, &p->mPos, &v);
    func_ov001_02187218(a, 5, func_ov001_0218f3ac);
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_0ec), (s32) (a->mPrm->mUnk_0f0));
    func_ov001_02188d1c(a, (s32) (a->mPrm->mUnk_0f4), (s32) (a->mPrm->mUnk_0f8));
    func_ov001_02188cd8(a, (s32) (a->mPrm->mUnk_0fc), (s32) (a->mPrm->mUnk_100));
    func_ov001_02188c48(a, a->mPrm->mUnk_104, a->mPrm->mUnk_108);
    func_ov001_02188de0(a, (s32) (a->mPrm->mUnk_218), 0, (&v), (UnkFunc *) (func_ov001_0218f454));
    if (data_0217d20c != 2) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 2;
    func_ov001_02188200(a, func_ov001_0218e298);
    a->mUnk_000.mFlags |= data_ov001_021a65b0;
}

s32 func_ov001_0218f244(Unk02188950 *a) {
    Kart *p;
    Vec3 v;

    p = GetKart((u16) data_021759c0->mEntryIndex);
    if ((p->mUnk_48 & 0x200) == 0) {
        Vec3AddScaled(-a->mPrm->mUnk_0e8, &p->mUnk_68, &p->mPos, &v);
        SetAnglePointAndMoveAnglePoint(a, &v);
        func_ov001_02188d8c(a, (&v));
    }
    func_ov001_0218f6d8(a);
    return 0;
}

void func_ov001_0218f16c(Unk02188950 *a) {
    Kart *p;
    Vec3 v;

    p = GetKart((u16) data_021759c0->mEntryIndex);
    Vec3AddScaled(-a->mPrm->mUnk_0e8, &p->mUnk_68, &p->mPos, &v);
    func_ov001_02187218(a, 3, func_ov001_0218f244);
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_0c4), (s32) (a->mPrm->mUnk_0c8));
    func_ov001_02188d1c(a, (s32) (a->mPrm->mUnk_0cc), (s32) (a->mPrm->mUnk_0d0));
    func_ov001_02188cd8(a, (s32) (a->mPrm->mUnk_0d4), (s32) (a->mPrm->mUnk_0d8));
    func_ov001_02188c48(a, a->mPrm->mUnk_0dc, a->mPrm->mUnk_0e0);
    func_ov001_02188de0(a, (s32) (a->mPrm->mUnk_0e4), 0, (&v), (UnkFunc *) (func_ov001_0218f2a8));
    if (data_0217d20c != 1) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 1;
}

s32 func_ov001_0218efc4(Unk02188950 *a) {
    Kart *p;
    float f;

    p = GetKart((u16) data_021759c0->mEntryIndex);
    if ((p->mUnk_48 & 0x200) == 0) {
        SetAnglePointAndMoveAnglePoint(a, &p->mPos);
        func_ov001_02188d8c(a, (&p->mPos));
    }
    func_ov001_0218f724(a);
    if (func_ov001_02188104(a, (s32) (a->mPrm->mUnk_0b8), 0) == NULL) {
        a->mUnk_1c4 = a->mPrm->mUnk_0c0;
    } else {
        a->mUnk_1c4 = 0;
    }
    a->mUnk_170 = a->mPrm->mUnk_09c;
    if (a->mPrm->mUnk_1cc - (data_021759c0->mMode == MODE_MISSION_RUN ? (s32) func_ov001_02181838() : 0) > 0) {
        f = 0.5f +
            (float) ((a->mPrm->mUnk_1cc - (data_021759c0->mMode == MODE_MISSION_RUN ? (s32) func_ov001_02181838() : 0))
                     << 12);
    } else {
        f = (float) ((a->mPrm->mUnk_1cc - (data_021759c0->mMode == MODE_MISSION_RUN ? (s32) func_ov001_02181838() : 0))
                     << 12) -
            0.5f;
    }
    a->mUnk_16c = (s32) f / a->mPrm->mUnk_1d4;
    if ((data_021759c0->mMode == MODE_MISSION_RUN ? (s32) func_ov001_02181838() : 0) <= a->mPrm->mUnk_1d0 &&
        func_ov001_02188000(a, 0, (s32) (a->mPrm->mUnk_0bc)) != NULL) {
        func_ov001_02188200(a, func_ov001_0218f9a8);
        a->mUnk_000.mFlags |= data_ov001_021a65b0;
        func_ov001_0218f16c(a);
    } else if ((data_021759c0->mMode == MODE_MISSION_RUN ? (s32) func_ov001_02181838() : 0) > a->mPrm->mUnk_1cc) {
        func_ov001_02188e88(a);
    }
    return 0;
}

void func_ov001_0218ef30(Unk02188950 *a) {
    GetKart((u16) data_021759c0->mEntryIndex);
    func_ov001_02187218(a, 3, func_ov001_0218efc4);
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_090), (s32) (a->mPrm->mUnk_094));
    func_ov001_02188cec(a, (s32) (a->mPrm->mUnk_0a0));
    func_ov001_02188adc(a, a->mPrm->mUnk_0b0, 0x270f000, a->mPrm->mUnk_0a8, 0x270f000, 0);
    if (data_0217d20c != 0) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 0;
}

void func_ov001_0218ee88(Unk02188950 *a) {
    Kart *p;
    Vec3 v;

    p = GetKart((u16) data_021759c0->mEntryIndex);
    Vec3AddScaled(-a->mPrm->mUnk_0e8, &p->mUnk_68, &p->mPos, &v);
    a->mUnk_000.mPos.x = v.x;
    a->mUnk_000.mPos.y = a->mUnk_000.mCourseMapRow->mUnk_00.y + a->mPrm->mUnk_080;
    a->mUnk_000.mPos.z = v.z;
    a->mMoveAngle = (u16) (AngleFromPair(p->mPos.x - a->mUnk_000.mPos.x, p->mPos.z - a->mUnk_000.mPos.z) + 0x4000);
    a->mAngle = a->mMoveAngle;
    func_ov001_0218ef30(a);
    func_ov001_02182a3c(0);
    a->mUnk_000.mFlags &= ~1;
}

void func_ov001_0218edc8(Unk02188950 *a) {
    Kart *p;

    p = GetKart((u16) data_021759c0->mEntryIndex);
    func_ov001_02187218(a, 3, func_ov001_0218f634);
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_144), (s32) (a->mPrm->mUnk_148));
    func_ov001_02188d1c(a, (s32) (a->mPrm->mUnk_14c), (s32) (a->mPrm->mUnk_150));
    func_ov001_02188cd8(a, (s32) (a->mPrm->mUnk_154), (s32) (a->mPrm->mUnk_158));
    func_ov001_02188c48(a, a->mPrm->mUnk_15c, a->mPrm->mUnk_160);
    SetAnglePointAndMoveAnglePoint(a, &p->mPos);
    func_ov001_02188e24(a, (s32) (a->mPrm->mUnk_164), (UnkFunc *) (0));
}

u32 func_ov001_0218edb8(void) {
    func_02061860();
    return 0;
}

void func_ov001_0218ec40(Unk02188950 *a) {
    GetKart((u16) data_021759c0->mEntryIndex);
    func_ov001_02187218(a, 1, (s32(*)(Unk02188950 *)) func_ov001_0218edb8);
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_118), (s32) (a->mPrm->mUnk_11c));
    func_ov001_02188d1c(a, (s32) (a->mPrm->mUnk_120), (s32) (a->mPrm->mUnk_124));
    if (a->mUnk_0a8 == 1) {
        func_ov001_02188cd8(a, (s32) (a->mPrm->mUnk_128), (s32) (a->mPrm->mUnk_12c));
        func_ov001_02188c48(a, a->mPrm->mUnk_130, a->mPrm->mUnk_134);
    } else if (a->mUnk_0a8 == 2) {
        func_ov001_02188cd8(a, (s32) (a->mPrm->mUnk_220), (s32) (a->mPrm->mUnk_224));
        func_ov001_02188c48(a, a->mPrm->mUnk_228, a->mPrm->mUnk_22c);
    } else if (a->mUnk_0a8 == 3) {
        func_ov001_02188cd8(a, (s32) (a->mPrm->mUnk_230), (s32) (a->mPrm->mUnk_234));
        func_ov001_02188c48(a, a->mPrm->mUnk_238, a->mPrm->mUnk_23c);
    }
    SetAnglePointAndMoveAnglePoint(a, ((Vec3 *) func_ov001_02187fc0(a)));
    func_ov001_02188de0(a, (s32) (a->mPrm->mUnk_138), (s32) (a->mPrm->mUnk_13c), (((Vec3 *) func_ov001_02187fc0(a))),
                        (UnkFunc *) (0));
    if (data_0217d20c != 5) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 5;
}

void func_ov001_0218eb94(Unk02188950 *a) {
    Unk020f41c4_B *rng;
    GetKart((u16) data_021759c0->mEntryIndex);
    rng = func_020d22d0();
    rng->mUnk_00 = (s64) rng->mUnk_08 * (s64) rng->mUnk_00 + rng->mUnk_10;
    a->mUnk_000.mPos.x = ((Vec3 *) func_ov001_02187fc0(a))->x;
    a->mUnk_000.mPos.y = a->mPrm->mUnk_080 + ((Vec3 *) func_ov001_02187fc0(a))->y;
    a->mUnk_000.mPos.z = ((Vec3 *) func_ov001_02187fc0(a))->z;
    func_ov001_02187218(a, 5, (s32(*)(Unk02188950 *)) func_ov001_0218edb8);
    func_ov001_0218f900(a);
    func_ov001_02188e24(a, a->mPrm->mUnk_1b4, NULL);
    if (data_0217d20c != 5) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 5;
}

void func_ov001_0218ead0(Unk02188950 *a) {
    int v1;
    u32 v2;

    func_ov001_02187218(a, 5, (s32(*)(Unk02188950 *)) func_ov001_0218edb8);
    func_ov001_0218f850(a);
    func_ov001_02188e24(a, a->mPrm->mUnk_1a8, (UnkFunc *) func_ov001_0218eb94);
    func_ov001_02182a3c(0);
    func_ov001_02187e48(a, a->mPrm->mUnk_140);
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
    a->mUnk_270 = a->mPrm->mUnk_00c;
    a->mUnk_264 = a->mUnk_270;
    a->mUnk_268 = a->mUnk_264;
    a->mUnk_25c = a->mUnk_268;
}

u32 func_ov001_0218ea98(Unk02188950 *a) {
    int v1;
    int v2;
    v2 = a->mUnk_000.mCourseMapRow->mUnk_00.y + a->mPrm->mUnk_084;
    v1 = a->mUnk_000.mPos.y - a->mPrm->mUnk_088;
    if (v1 <= v2) {
        v1 = v2;
    }
    a->mUnk_000.mPos.y = v1;
    func_02061860();
    return 0;
}

void func_ov001_0218e92c(Unk02188950 *p) {
    func_ov001_02187218(p, 5, (s32(*)(Unk02188950 *)) func_ov001_0218ea98);
    func_ov001_02188d64(p, p->mPrm->mUnk_170, p->mPrm->mUnk_174);
    func_ov001_02188d1c(p, p->mPrm->mUnk_178, p->mPrm->mUnk_17c);
    func_ov001_02188c90(p);
    func_ov001_02188cec(p, 0);
    func_ov001_02188e24(p, p->mPrm->mUnk_194, func_ov001_0218ead0);
    func_ov001_021875c0(p, 0, 0, 0, 0x431, 0);
    func_ov001_021875c0(p, 0, 0, 0, 0x430, 0);
    func_ov001_021875c0(p, 0, 0, 0, 0x432, 0);
    if (data_0217d20c != 4) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 4;
    func_ov001_02188200(p, func_ov001_0218e38c);
    p->mUnk_000.mFlags |= data_ov001_021a65b0;
    func_ov001_02182a3c(p->mPrm->mUnk_18c < (data_021759c0->mMode == MODE_MISSION_RUN ? (s32) func_ov001_02181800() : 0)
                            ? p->mPrm->mUnk_18c
                            : (data_021759c0->mMode == MODE_MISSION_RUN ? (s32) func_ov001_02181800() : 0));
    p->mUnk_25c = p->mUnk_268 = p->mUnk_264 = p->mUnk_270 = p->mPrm->mUnk_00c / 2;
}

void func_ov001_0218e8d8(Unk02188950 *a) {
    func_ov001_02187218(a, 5, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(a, (s32) (a->mPrm->mUnk_168), (s32) (a->mPrm->mUnk_16c), (UnkFunc *) &func_ov001_0218e92c);
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
    func_ov001_02182a3c(0);
    StartMapObjectSound(&a->mUnk_000, (u32) (((u32) 0x00000230u)));
}

void func_ov001_0218e8b0(Unk02188950 *a) {
    func_ov001_02187218(a, 1, (s32(*)(Unk02188950 *))(0));
    func_ov001_021888a4(a, 0, 0x19000);
    func_0206184c();
    func_ov001_021827f0();
}

void func_ov001_0218e860(Unk02188950 *a) {
    func_ov001_02187218(a, 5, (s32(*)(Unk02188950 *)) func_ov001_0218f688);
    func_ov001_0218f850(a);
    func_ov001_02188e24(a, a->mPrm->mUnk_1a8, (UnkFunc *) func_ov001_0218e8b0);
    if (data_0217d20c != 3) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 3;
}

void func_ov001_0218e7d0(Unk02188950 *p) {
    func_ov001_02187218(p, 1, NULL);
    func_ov001_021888a4(p, 0, 0x19000);
    func_ov001_02188d64(p, p->mPrm->mUnk_198, p->mPrm->mUnk_19c);
    func_ov001_02188d1c(p, p->mPrm->mUnk_1a0, p->mPrm->mUnk_1a4);
    func_ov001_02188cec(p, 0);
    func_ov001_02188c90(p);
    if (data_0217d20c != 3) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 3;
    p->mUnk_000.mFlags |= data_ov001_021a65bc;
}

void func_ov001_0218e7b0(Unk02188950 *a) {
    func_ov001_02187218(a, 1, (s32(*)(Unk02188950 *))(0));
    func_ov001_021888a4(a, 0, 0x19000);
}

void func_ov001_0218e760(Unk02188950 *p) {
    func_ov001_02187218(p, 5, func_ov001_0218f688);
    func_ov001_0218f850(p);
    func_ov001_02188e24(p, p->mPrm->mUnk_1a8, func_ov001_0218e7b0);
    if (data_0217d20c != 3) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 3;
}

void func_ov001_0218e710(Unk02188950 *p) {
    func_ov001_02187218(p, 8, NULL);
    func_ov001_02188d64(p, p->mPrm->mUnk_078, p->mPrm->mUnk_07c);
    func_ov001_02188c90(p);
    func_ov001_02188cec(p, 0);
    if (data_0217d20c != 6) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 6;
    func_0206184c();
}

void func_ov001_0218e690(Unk02188950 *p) {
    func_ov001_02187218(p, 8, NULL);
    func_ov001_02188d64(p, p->mPrm->mUnk_070, p->mPrm->mUnk_074);
    StartEffect(0x3fe, &p->mUnk_000.mPos);
    StartEffect(0x3fd, &p->mUnk_000.mPos);
    if (data_0217d20c != 7) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 7;
    p->mUnk_000.mFlags |= data_ov001_021a65b4;
    p->mUnk_000.mFlags |= data_ov001_021a65b8;
    p->mUnk_000.mFlags |= data_ov001_021a65bc;
}

s32 func_ov001_0218e650(Unk02188950 *a) {
    if (a->mUnk_0b0 == 50) {
        Unk021a7c08 local = {0x22f, 0, 0xe, 0};
        local.mUnk_04 = &a->mUnk_000.mPos;
        local.mUnk_0c = func_020d4ef4(&a->mUnk_000.mPos);
        func_0210b734(&local, func_02108e7c());
    }
    return 0;
}

void func_ov001_0218e5c4(Unk02188950 *a) {
    a->mUnk_000.mPos.y += a->mPrm->mUnk_080;
    a->mUnk_168 = a->mUnk_16c = 0x1f000;
    a->mUnk_170 = 0;
    func_ov001_02187218(a, 8, func_ov001_0218e650);
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_070), (s32) (a->mPrm->mUnk_074));
    func_ov001_02188e24(a, 0x3c, func_ov001_0218e690);
    if (data_0217d20c != 7) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 7;
    a->mUnk_000.mFlags &= ~1;
}

void func_ov001_0218e594(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_070), (s32) (a->mPrm->mUnk_074));
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
    return;
}

void func_ov001_0218e58c(void) {
    func_ov001_021882b8();
}

void func_ov001_0218e564(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(a, a->mPrm->mUnk_058, a->mPrm->mUnk_05c, func_ov001_0218e760);
}

void func_ov001_0218e520(Unk02188950 *a) {
    a->mUnk_000.mPos.y += a->mPrm->mUnk_080;
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, a->mPrm->mUnk_04c, a->mPrm->mUnk_050);
    func_ov001_02188e24(a, a->mPrm->mUnk_054, func_ov001_0218e564);
}

void func_ov001_0218e508(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_0218f900(a);
}

void func_ov001_0218e4ac(Unk02188950 *a) {
    a->mUnk_000.mPos.y += a->mPrm->mUnk_080;
    a->mUnk_16c = 0;
    a->mUnk_168 = a->mUnk_16c;
    a->mUnk_168 = 0;
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, a->mPrm->mUnk_034, a->mPrm->mUnk_038);
    func_ov001_02188e24(a, a->mPrm->mUnk_03c, func_ov001_0218e508);
}

void func_ov001_0218e474(Unk02188950 *a) {
    a->mUnk_000.mSound = HeapAlloc(GetHeap(func_020364e8()), 0x44);
    InitSoundSource((SoundSource *) (a->mUnk_000.mSound), (u32) (0xe), (&a->mUnk_000.mPos));
    a->mUnk_000.mFarDistanceSquared = data_0217cc6c[6];
}

void func_ov001_0218e38c(Unk02188950 *a, Kart *b) {
    a->mUnk_000.mUnk_10.x = ((s64) -a->mPrm->mUnk_024 * gPairsByAngle[(b->mHeadingAngle >> 4) * 2]) >> 12;
    a->mUnk_000.mUnk_10.y = 0;
    a->mUnk_000.mUnk_10.z = ((s64) -a->mPrm->mUnk_024 * gPairsByAngle[(b->mHeadingAngle >> 4) * 2 + 1]) >> 12;
    func_ov001_021829ac(a->mPrm->mUnk_190);
    func_ov001_0218ead0(a);
    a->mUnk_2d8 = 0;
    func_ov001_02188200(a, func_ov001_0218f9a8);
    func_ov001_0218e860(a);
    a->mUnk_0a8 = 0;
    StartMapObjectSound(&a->mUnk_000, (u32) (0x22c));
    a->mUnk_25c = a->mUnk_268 = a->mUnk_264 = a->mUnk_270 = a->mPrm->mUnk_00c;
}

void func_ov001_0218e344(Unk02188950 *a) {
    int v1;
    v1 = func_ov001_021871f8(a, 5);
    if (v1 != 0) {
        func_ov001_0218edc8(a);
    }
    a->mUnk_2d8 = 0xd;
    func_ov001_02188200(a, func_ov001_0218e344);
    if (a->mTimer == 0) {
        StartMapObjectSound(&a->mUnk_000, (u32) (((u32) 0x00000234u)));
    }
}

void func_ov001_0218e298(Unk02188950 *a, Kart *b) {
    func_ov001_02182bbc((u16) a->mPrm->mUnk_110);
    a->mUnk_000.mUnk_10.x = 0;
    a->mUnk_000.mUnk_10.y = a->mPrm->mUnk_114;
    a->mUnk_000.mUnk_10.z = 0;
    a->mUnk_2d8 = 0xc;
    a->mUnk_158 = func_ov001_0218f3ec;
    func_ov001_02188200(a, func_ov001_0218f9a8);
    func_02073fb0(a->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
    func_02068a10(b);
    func_ov001_021888a4(a, 0, 0x32000);
    a->mUnk_0a8 = 1;
    if (!(data_021759c0->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0)) {
        func_02061874();
    }
}

void func_ov001_0218e208(Unk0218d87c *a) {
    s32 i;
    Unk02188950 *obj;
    Unk02188950_a0 *a0;

    if (a != NULL) {
        for (i = 0; i < a->mUnk_04 && (obj = a->mUnk_00[i]) != NULL; i++) {
            if (func_02062ec4() != 0) {
                func_ov001_0218e4ac(obj);
            } else {
                func_ov001_0218e520(obj);
            }
            if (data_021759c0->mMode == MODE_MISSION_RUN) {
                a0 = obj->mPrm;
                func_ov001_02181844(a0->mUnk_1b8, a0->mUnk_1bc, a0->mUnk_1c0, a0->mUnk_1c4);
            }
        }
    }
    SetStandingsEndCallback((void (*)(void)) func_ov001_0218e58c);
}

void func_ov001_0218df20(u32 a, Unk02188950 *b) {
    Kart *p;

    if (data_021759c0->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) {
        if (func_ov001_021871f8(b, 5) != 0) {
            if (data_021759c0->mMode == MODE_MISSION_RUN ? IsKartEliminated((u16) data_021759c0->mEntryIndex) : 0) {
                func_ov001_0218e710(b);
            } else if (data_021759c0->mMode == MODE_MISSION_RUN ? func_020a128c() : 0) {
                func_ov001_0218e5c4(b);
            } else {
                func_ov001_0218e594(b);
            }
        }
    } else {
        if (b->mUnk_0a8 != 0) {
            if (func_ov001_021871f8(b, 5) != 0) {
                p = GetKart((u16) data_021759c0->mEntryIndex);
                if (p->mState == 0 && (p->mUnk_48 & 0x200) == 0 &&
                    func_ov001_02188104(b, 0, b->mPrm->mUnk_184) != NULL &&
                    func_ov001_02188000(b, 0, b->mPrm->mUnk_180) != NULL &&
                    func_ov001_02188104(b, b->mPrm->mUnk_188, 0) != NULL) {
                    func_ov001_0218e8d8(b);
                }
            }
            if (func_ov001_021871f8(b, 3) != 0) {
                if (func_ov001_021881a8(b, (Vec3 *) func_ov001_02187fc0(b), (s32) (b->mPrm->mUnk_138), 0) != 0) {
                    func_ov001_02187e78(b);
                }
                func_ov001_02188200(b, func_ov001_0218e344);
                b->mUnk_000.mFlags &= ~0x40;
                func_ov001_02182a3c(0);
                func_ov001_0218ec40(b);
            }
        } else {
            p = GetKart((u16) data_021759c0->mEntryIndex);
            if (p->mUnk_48 & 0x200) {
                if (data_021759c0->mMode == MODE_MISSION_RUN ? func_ov001_02181820() : 0) {
                    if (data_021759c0->mMode == MODE_MISSION_RUN) {
                        func_ov001_0218182c((u16) b->mPrm->mUnk_1bc);
                    }
                } else {
                    if (data_021759c0->mMode == MODE_MISSION_RUN) {
                        func_ov001_0218182c(0);
                    }
                }
                if ((b->mUnk_000.mFlags & 1) == 0) {
                    func_ov001_02188200(b, func_ov001_0218f9a8);
                    b->mUnk_000.mFlags |= data_ov001_021a65b0;
                    func_ov001_0218e7d0(b);
                }
            }
            if (data_021759c0->mMode == MODE_MISSION_RUN ? func_ov001_02181838() : 0) {
                if (func_ov001_021871f8(b, 3) != 0) {
                    if ((s32) (data_021759c0->mMode == MODE_MISSION_RUN ? func_ov001_02181838() : 0) <
                        b->mPrm->mUnk_1c8) {
                        if (b->mUnk_000.mFlags & 1) {
                            func_ov001_02188200(b, func_ov001_0218f9a8);
                            b->mUnk_000.mFlags |= data_ov001_021a65b0;
                            func_ov001_0218ee88(b);
                        } else {
                            func_ov001_02188200(b, func_ov001_0218f9a8);
                            b->mUnk_000.mFlags |= data_ov001_021a65b0;
                            func_ov001_0218ef30(b);
                        }
                    } else if ((b->mUnk_000.mFlags & 1) == 0) {
                        func_ov001_02188200(b, func_ov001_0218f9a8);
                        b->mUnk_000.mFlags |= data_ov001_021a65b0;
                        func_ov001_0218e7d0(b);
                    }
                }
            }
        }
        if (data_0217d20c == 0) {
            func_02110350(b->mUnk_000.mSound);
        } else if (func_02110324() != 0) {
            StartMapObjectSoundWhileRequested(&b->mUnk_000, (u32) (0x22a));
        } else if (data_0217d20c == 4) {
            StartMapObjectSoundWhileRequested(&b->mUnk_000, (u32) (0x22b));
        }
    }
    func_ov001_021864ac(a, b);
}

void func_ov001_0218de50(Unk0218d87c *a) {
    int i;
    Unk02188950 *p;
    Unk02188950_a0 *a0;

    if (a != NULL) {
        for (i = 0; i < a->mUnk_04 && (p = a->mUnk_00[i]) != NULL; i++) {
            if (data_021759c0->mMode == MODE_MISSION_RUN) {
                func_ov001_02181b8c(p);
            }
            func_ov001_021870e4(a, p, data_ov001_021a7da0, data_ov001_021a7db4, data_ov001_021a7dc8);
            func_ov001_021870b0(a, p, data_ov001_021a7dd8);
            a0 = p->mPrm;
            func_ov001_0218875c(p, a0->mUnk_008, a0->mUnk_00c, a0->mUnk_240);
            func_ov001_021888a4(p, 0, 0x19000);
            func_ov001_02188200(p, func_ov001_0218f9a8);
            func_ov001_02187cd4(p, 0);
            p->mUnk_000.mFlags |= data_ov001_021a65b0;
            p->mUnk_2b8 = 3;
        }
    }
}

void func_ov001_0218de14(void *a, Unk02188950 *b) {
    func_ov001_02186368(a, b);
    if (b->mUnk_0a8 == 0) {
        func_ov001_021861f4(a, b, 0);
        return;
    }
    func_ov001_021861f4(a, b, 1);
}

void func_ov001_0218dde8(void) {
    void *v6 = &func_ov001_02185fb0;
    void *v7 = &func_ov001_02185f04;
    void *v8 = &func_ov001_021860cc;
    void *v10 = func_ov001_0219b510(v6, v7, v8, (u32) 0x2u, (u16) ((u32) 0x0u), (u16) ((u32) 0x0u), (u16) ((u32) 0x0u));
}

void *func_ov001_0218ddcc(void) {
    return (void *) func_0209bf1c(func_ov001_0218de50, func_ov001_0218de14, func_ov001_02187098);
}

void *func_ov001_0218ddb4(void) {
    return (void *) func_0209bf48(func_ov001_0218e208, func_ov001_0218df20, NULL);
}
