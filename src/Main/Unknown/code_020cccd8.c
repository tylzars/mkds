#include "Main/Unknown/code_020cccd8.h"

#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020b4000.h"
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
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020cce10.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020ade08.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_02095f30.h"
#include "Main/Unknown/code_02095f38.h"
#include "Main/Unknown/code_02095000.h"
#include "Main/Unknown/code_020931ac.h"
#include "Main/Unknown/code_02092194.h"
#include "Main/Unknown/code_021000d0.h"

void func_020ce694(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b480;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020ce580(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b480->mUnk_08; i++) {
        e = data_0217b480->mUnk_00[i];
        v = &e->mUnk_04;
        if (func_020b5ae8(v, &data_0217b480->mUnk_10[a].mUnk_00, n, 1, 1) != FALSE) {
            data_0217b480->mUnk_10[a].mUnk_08 = GetRaceSNcerEntry(0xb3);
            data_0217b480->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
            data_0217b480->mUnk_10[a].mUnk_0e = 0;
            data_0217b480->mUnk_10[a].mUnk_10 = e->mUnk_7e;
            a++;
        }
    }
    data_0217b480->mUnk_04 = a;
}

void func_020ce564(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b480, 1);
}

s32 func_020ce548(void) {
    return func_020c0c2c(&data_0217b47c, MAP_OBJECT_KIND_BASABASA);
}

void func_020ce534(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b47c;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020ce414(void) {
    s32 i;
    s32 a;
    u32 n;
    u32 m;
    Unk0217b498_00 *e;
    Vec3 *v;
    void *w;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b47c->mUnk_08; i++) {
        e = data_0217b47c->mUnk_00[i];
        if ((e->mUnk_02 & 1) == 0) {
            m = func_02092194(e);
            if (m != 0) {
                v = &e->mUnk_04;
                if (func_020b5ae8(v, &data_0217b47c->mUnk_10[a].mUnk_00, n, 1, 1) != FALSE) {
                    if (m == 2) {
                        w = GetRaceSNcerEntry(0xb5);
                    } else {
                        w = GetRaceSNcerEntry(0xb4);
                    }
                    data_0217b47c->mUnk_10[a].mUnk_08 = w;
                    data_0217b47c->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    a++;
                }
            }
        }
    }
    data_0217b47c->mUnk_04 = a;
}

void func_020ce3f8(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b47c, 0);
}

s32 func_020ce3e0(void) {
    return func_020c0c2c(&data_0217b478, 0x198);
}

void func_020ce3cc(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b478;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020ce298(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    s32 d;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b478->mUnk_08; i++) {
        if (func_020b5f68(&data_0217b478->mUnk_0c[i]) != FALSE) {
            e = data_0217b478->mUnk_00[i];
            d = e->mUnk_04.y - e->mUnk_ac;
            if (d >= 0) {
                v = &e->mUnk_04;
                if (func_020b5ae8(v, &data_0217b478->mUnk_10[a].mUnk_00, n, 0, 1) != FALSE) {
                    data_0217b478->mUnk_10[a].mUnk_00.mUnk_04 -= d >> 14;
                    data_0217b478->mUnk_10[a].mUnk_08 = GetRaceSNcerEntry(0xb1);
                    data_0217b478->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    a++;
                }
            }
        }
    }
    data_0217b478->mUnk_04 = a;
}

void func_020ce27c(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b478, 0);
}

s32 func_020ce264(void) {
    return func_020c0c2c(&data_0217b474, 0x1a8);
}

void func_020ce250(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b474;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020ce134(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b474->mUnk_08; i++) {
        e = data_0217b474->mUnk_00[i];
        v = &e->mUnk_04;
        if (func_020b5ae8(v, &data_0217b474->mUnk_10[a].mUnk_00, n, 1, 1) != FALSE) {
            data_0217b474->mUnk_10[a].mUnk_08 = GetRaceSNcerEntry(0x91);
            data_0217b474->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
            data_0217b474->mUnk_10[a].mUnk_10 = e->mUnk_7e;
            data_0217b474->mUnk_0c[a].mUnk_00 = e->mUnk_1c / 6;
            a++;
        }
    }
    data_0217b474->mUnk_04 = a;
}

void func_020ce118(Unk020c06c4 *a) {
    func_020c06c4(a, data_0217b474, 1);
}

s32 func_020ce100(void) {
    return func_020c0c2c(&data_0217b470, MAP_OBJECT_KIND_MKD_EF_BURNER);
}

void func_020ce0ec(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b470;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020cdf50(void) {
    s32 i;
    s32 a;
    s32 b;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    data_0217b470->mUnk_0c[0].mUnk_04++;
    if (data_0217b470->mUnk_0c[0].mUnk_04 < 0 || data_0217b470->mUnk_0c[0].mUnk_04 >= 8) {
        data_0217b470->mUnk_0c[0].mUnk_04 = 0;
    }
    b = data_0217b470->mUnk_0c[0].mUnk_04 < 4 ? 1 : 0;
    for (i = 0; i < data_0217b470->mUnk_08; i++) {
        e = data_0217b470->mUnk_00[i];
        if ((e->mUnk_02 & 1) == 0 && func_020931ac(e) != 0) {
            v = &e->mUnk_04;
            if (func_020b5ae8(v, &data_0217b470->mUnk_10[a].mUnk_00, n, 0, 0) != FALSE) {
                data_0217b470->mUnk_10[a].mUnk_08 = GetRaceSNcerEntry(data_021759c0->mCourseId == 0x13 ? 0xae : 0xb2);
                data_0217b470->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                data_0217b470->mUnk_0c[a].mUnk_00 = b != 0 ? 0x1000 : 0xccd;
                a++;
            }
        }
    }
    data_0217b470->mUnk_04 = a;
}

void func_020cdf34(Unk020c06c4 *a) {
    func_020c06c4(a, data_0217b470, 0);
}

s32 func_020cdf18(void) {
    return func_020c0c2c(&data_0217b46c, 0x1ae);
}

void func_020cdf04(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b46c;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020cde18(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b46c->mUnk_08; i++) {
        e = data_0217b46c->mUnk_00[i];
        if ((e->mUnk_02 & 1) == 0) {
            v = &e->mUnk_04;
            if (func_020b5ae8(v, &data_0217b46c->mUnk_10[a].mUnk_00, n, 1, 1) != FALSE) {
                data_0217b46c->mUnk_10[a].mUnk_08 = GetRaceSNcerEntry(0x8d);
                data_0217b46c->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                a++;
            }
        }
    }
    data_0217b46c->mUnk_04 = a;
}

void func_020cddfc(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b46c, 0);
}

s32 func_020cdde4(void) {
    return func_020c0c2c(&data_0217b468, MAP_OBJECT_KIND_IRON_BALL);
}

void func_020cddd0(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b468;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020cdcc8(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b468->mUnk_08; i++) {
        e = data_0217b468->mUnk_00[i];
        if ((e->mUnk_02 & 2) == 0) {
            v = &e->mUnk_04;
            if (func_020b5ae8(v, &data_0217b468->mUnk_10[a].mUnk_00, n, 1, 1) != FALSE) {
                data_0217b468->mUnk_10[a].mUnk_08 = GetRaceSNcerEntry(0x92);
                data_0217b468->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                data_0217b468->mUnk_10[a].mUnk_0e = e->mUnk_02 & 0x20;
                a++;
            }
        }
    }
    data_0217b468->mUnk_04 = a;
}

void func_020cdcac(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b468, 0);
}

s32 func_020cdc90(void) {
    return func_020c0c2c(&data_0217b464, MAP_OBJECT_KIND_KURIBO);
}

void func_020cdc7c(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b464;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020cdb8c(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b464->mUnk_08; i++) {
        e = data_0217b464->mUnk_00[i];
        v = &e->mUnk_04;
        if ((e->mUnk_02 & 2) == 0) {
            if (func_020b5ae8(v, &data_0217b464->mUnk_10[a].mUnk_00, n, 0, 1) != FALSE) {
                data_0217b464->mUnk_10[a].mUnk_08 = GetRaceSNcerEntry(0xa3);
                data_0217b464->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                a++;
            }
        }
    }
    data_0217b464->mUnk_04 = a;
}

void func_020cdb70(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b464, 0);
}

s32 func_020cdb54(void) {
    return func_020c0c2c(&data_0217b460, 0x1a6);
}

void func_020cdb40(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b460;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020cda14(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b460->mUnk_08; i++) {
        if (func_020b5f68(&data_0217b460->mUnk_0c[i]) != FALSE) {
            e = data_0217b460->mUnk_00[i];
            if ((e->mUnk_02 & 1) == 0) {
                v = &e->mUnk_04;
                if (func_020b5ae8(v, &data_0217b460->mUnk_10[a].mUnk_00, n, 0, 0) != FALSE) {
                    data_0217b460->mUnk_10[a].mUnk_08 =
                        GetRaceSNcerEntry(((e->mUnk_b8 & 0x10) >> 4) != 0 ? 0xa2 : 0xa1);
                    data_0217b460->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    a++;
                }
            }
        }
    }
    data_0217b460->mUnk_04 = a;
}

void func_020cd9f8(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b460, 0);
}

s32 func_020cd9dc(void) {
    return func_020c0c2c(&data_0217b45c, 0x1a7);
}

void func_020cd9c8(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b45c;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020cd87c(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b45c->mUnk_08; i++) {
        if (func_020b5f68(&data_0217b45c->mUnk_0c[i]) != FALSE) {
            e = data_0217b45c->mUnk_00[i];
            if ((e->mUnk_02 & 1) == 0) {
                v = &e->mUnk_04;
                if (func_020b5ae8(v, &data_0217b45c->mUnk_10[a].mUnk_00, n, 0, 0) != FALSE) {
                    data_0217b45c->mUnk_10[a].mUnk_00.mUnk_04 -= func_02095f30(e) >> 14;
                    data_0217b45c->mUnk_10[a].mUnk_08 = GetRaceSNcerEntry(func_02095f38(e) != FALSE ? 0xab : 0xaa);
                    data_0217b45c->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    a++;
                }
            }
        }
    }
    data_0217b45c->mUnk_04 = a;
}

void func_020cd860(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b45c, 0);
}

s32 func_020cd844(void) {
    return func_020c0c2c(&data_0217b458, 0x1b1);
}

void func_020cd830(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b458;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020cd72c(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b458->mUnk_08; i++) {
        e = data_0217b458->mUnk_00[i];
        if ((e->mUnk_02 & 2) == 0) {
            v = &e->mUnk_04;
            if (func_020b5ae8(v, &data_0217b458->mUnk_10[a].mUnk_00, n, 1, 1) != FALSE) {
                data_0217b458->mUnk_10[a].mUnk_08 = GetRaceSNcerEntry(0x8f);
                data_0217b458->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                data_0217b458->mUnk_10[a].mUnk_10 += 0x400;
                a++;
            }
        }
    }
    data_0217b458->mUnk_04 = a;
}

void func_020cd710(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b458, 1);
}

s32 func_020cd6f4(void) {
    return func_020c0c2c(&data_0217b454, MAP_OBJECT_KIND_SANBO);
}

void func_020cd6e0(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b454;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020cd5d0(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b454->mUnk_08; i++) {
        if (func_020b5f68(&data_0217b454->mUnk_0c[i]) != FALSE) {
            e = data_0217b454->mUnk_00[i];
            if ((e->mUnk_02 & 1) == 0) {
                v = &e->mUnk_04;
                if (func_020b5ae8(v, &data_0217b454->mUnk_10[a].mUnk_00, n, 0, 0) != FALSE) {
                    data_0217b454->mUnk_10[a].mUnk_08 = GetRaceSNcerEntry(0x8e);
                    data_0217b454->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    a++;
                }
            }
        }
    }
    data_0217b454->mUnk_04 = a;
}

void func_020cd5b4(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b454, 0);
}

s32 func_020cd598(void) {
    return func_020c0c2c(&data_0217b450, 0x192);
}

void func_020cd584(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b450;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020cd480(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b450->mUnk_08; i++) {
        e = data_0217b450->mUnk_00[i];
        if ((e->mUnk_02 & 2) == 0) {
            v = &e->mUnk_04;
            if (func_020b5ae8(v, &data_0217b450->mUnk_10[a].mUnk_00, n, 1, 1) != FALSE) {
                data_0217b450->mUnk_10[a].mUnk_08 = GetRaceSNcerEntry(0x99);
                data_0217b450->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                data_0217b450->mUnk_10[a].mUnk_10 += 0x400;
                a++;
            }
        }
    }
    data_0217b450->mUnk_04 = a;
}

void func_020cd464(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b450, 1);
}

s32 func_020cd44c(void) {
    return func_020c0c2c(&data_0217b44c, 0x67);
}

void func_020cd438(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b44c;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020cd328(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b44c->mUnk_08; i++) {
        if (func_020b5f68(&data_0217b44c->mUnk_0c[i]) != FALSE) {
            e = data_0217b44c->mUnk_00[i];
            if ((e->mUnk_02 & 1) == 0) {
                v = &e->mUnk_04;
                if (func_020b5ae8(v, &data_0217b44c->mUnk_10[a].mUnk_00, n, 0, 0) != FALSE) {
                    data_0217b44c->mUnk_10[a].mUnk_08 = GetRaceSNcerEntry(0x5c);
                    data_0217b44c->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    a++;
                }
            }
        }
    }
    data_0217b44c->mUnk_04 = a;
}

void func_020cd30c(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b44c, 0);
}

s32 func_020cd2f0(void) {
    return func_020c0c2c(&data_0217b448, MAP_OBJECT_KIND_FLIPPER);
}

void func_020cd2dc(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b448;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020cd1c0(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b448->mUnk_08; i++) {
        e = data_0217b448->mUnk_00[i];
        if ((e->mUnk_02 & 2) == 0) {
            v = &e->mUnk_04;
            if (func_020b5ae8(v, &data_0217b448->mUnk_10[a].mUnk_00, n, 1, 1) != FALSE) {
                data_0217b448->mUnk_10[a].mUnk_08 = GetRaceSNcerEntry(0x90);
                data_0217b448->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                data_0217b448->mUnk_10[a].mUnk_0e = e->mUnk_02 & 0x400;
                data_0217b448->mUnk_10[a].mUnk_10 = e->mUnk_7e;
                a++;
            }
        }
    }
    data_0217b448->mUnk_04 = a;
}

void func_020ccf88(Unk020c06c4 *a) {
    s32 i;
    s32 c;
    u16 d;
    u16 h;
    s32 w;
    u16 k;
    Unk0217b498_10 *x;
    s32 v1[4];
    s32 z[2];
    s32 x0;
    struct Unk020224e0_c *x8;
    s32 x4;

    c = func_020c0dc4();
    d = func_020b6368();
    for (i = 0; i < data_0217b448->mUnk_04; i++) {
        h = data_0217b448->mUnk_10[i].mUnk_0c;
        if (c <= h) {
            if (data_0217b448->mUnk_10[i].mUnk_0e != 0) {
                if (data_021759c0->mUnk_57 != 0) {
                    func_020b4c74(v1, (u16) (d + (data_0217b448->mUnk_10[i].mUnk_10 + 0x4000)));
                } else {
                    func_020b4c74(v1, (u16) (0x4000 - data_0217b448->mUnk_10[i].mUnk_10 - d));
                }
            } else {
                if (data_021759c0->mUnk_57 != 0) {
                    func_020b4cb0(v1, (u16) (data_0217b448->mUnk_10[i].mUnk_10 + 0x4000 - d));
                } else {
                    func_020b4cb0(v1, (u16) (d + (0x4000 - data_0217b448->mUnk_10[i].mUnk_10)));
                }
            }
            k = func_020ae5c4(a);
            a->mUnk_000.mUnk_20[k].mUnk_06 = v1[0] >> 4;
            a->mUnk_000.mUnk_20[k].mUnk_0e = v1[1] >> 4;
            a->mUnk_000.mUnk_20[k].mUnk_16 = v1[2] >> 4;
            a->mUnk_000.mUnk_20[k].mUnk_1e = v1[3] >> 4;
            w = a->mUnk_400;
            x = &data_0217b448->mUnk_10[i];
            x0 = x->mUnk_00.mUnk_00;
            x8 = x->mUnk_08;
            x4 = x->mUnk_00.mUnk_04;
            z[0] = x0 << 12;
            z[1] = x4 << 12;
            a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[w], 0x80 - w, x8, v1, z, k, 1);
            for (; w < a->mUnk_400; w++) {
                if (h != -1) {
                    a->mUnk_000.mUnk_00[w].mUnk_0e = h;
                }
            }
        }
    }
}

s32 func_020ccf6c(void) {
    return func_020c0c2c(&data_0217b444, MAP_OBJECT_KIND_NS_KILLER2);
}

void func_020ccf58(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b444;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020cce58(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b444->mUnk_08; i++) {
        e = data_0217b444->mUnk_00[i];
        if ((e->mUnk_02 & 1) == 0 && (e->mUnk_02 & 2) == 0) {
            if (func_020b5ae8(&e->mUnk_04, &data_0217b444->mUnk_10[a].mUnk_00, n, 1, 1) != FALSE) {
                data_0217b444->mUnk_10[a].mUnk_08 = GetRaceSNcerEntry(0xad);
                data_0217b444->mUnk_10[a].mUnk_0c = 3;
                data_0217b444->mUnk_10[a].mUnk_0e = 0;
                data_0217b444->mUnk_10[a].mUnk_10 = e->mUnk_7e;
                a++;
            }
        }
    }
    data_0217b444->mUnk_04 = a;
}

void func_020cce3c(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b444, 1);
}

s32 func_020cce24(void) {
    return func_020c0c2c(&data_0217b440, 0xcf);
}

void func_020cce10(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b440;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020cccf4(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b440->mUnk_08; i++) {
        e = data_0217b440->mUnk_00[i];
        if ((e->mUnk_02 & 2) == 0) {
            v = &e->mUnk_04;
            if (func_020b5ae8(v, &data_0217b440->mUnk_10[a].mUnk_00, n, 1, 1) != FALSE) {
                data_0217b440->mUnk_10[a].mUnk_08 = GetRaceSNcerEntry(0xa0);
                data_0217b440->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                data_0217b440->mUnk_10[a].mUnk_0e = 0;
                data_0217b440->mUnk_10[a].mUnk_10 = e->mUnk_7e;
                a++;
            }
        }
    }
    data_0217b440->mUnk_04 = a;
}

void func_020cccd8(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b440, 1);
}
