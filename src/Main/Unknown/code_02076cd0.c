#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02076cd0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020738f4.h"
#include "Main/Unknown/code_02073904.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_020d4a20.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "code_02133048.h"
#include "code_02147cd8.h"
#include "code_0214a748.h"

#pragma thumb on

void func_02077b3c(void) {
    if (data_0217ad08->mUnk_25c != 0 || data_0217ad08->mUnk_260 != 0) {
        data_0217ad08->mUnk_1f4[data_0217ad08->mUnk_266].mUnk_2c = 1;
        data_0217ad08->mUnk_020->mUnk_00 = data_0217ad08->mUnk_024.mUnk_00;
        data_0217ad08->mUnk_020->mUnk_04 = data_0217ad08->mUnk_024.mUnk_04;
        data_0217ad08->mUnk_020->mUnk_20 = data_0217ad08->mUnk_1c8 + data_0217ad08->mUnk_024.mUnk_04;
        func_02057df0(LoadKartAndCharacterFiles);
        data_0217aa0c->mUnk_f8 = 1;
    }
}

void func_02077b1c(void) {
    data_0217ad08->mUnk_260 = 0;
    data_0217ad08->mUnk_25c = data_0217ad08->mUnk_260;
}

u32 func_02077a70(s32 *a, u32 b) {
    u32 n;
    enum { K0 } i;

    *a = (s32) _s32_div_f((u16) b, 3);
    if (*a >= 8) {
        switch (*a) {
            case 8:
                n = 0x14;
                break;
            case 9:
                n = 0x15;
                break;
            case 10:
                n = 0x16;
                break;
            case 11:
                n = 0x17;
                break;
        }
        if (func_02056dec(n) == 0) {
            *a = -1;
            for (i = 0; i < 8; i++) {
                if (func_0205fd2c(data_0217ad08->mUnk_268, i, b) != 0) {
                    *a = i;
                    break;
                }
            }
            if (*a != -1) {
                return 1;
            }
            return 0;
        }
    }
    return func_0205fd2c(data_0217ad08->mUnk_268, *a, b);
}

u16 func_02077a5c(void) {
    return data_0217ad08->mUnk_004 + 1;
}

u16 func_02077a4c(void) {
    return data_0217ad08->mUnk_008;
}

void func_02077a28(void *a) {
    void *v;

    LoadKartModelMenuFile(a, data_usa_02165714, &v);
    LoadNclrData(&data_usa_0217ace4, v);
}

void func_02077998(void) {
    u32 i;

    *(u32 *) 0x4000580 = 0xbfff0000;
    data_0217aca8 = 1;
    i = data_0217acac = 0;
    if (data_021759c0->mMode == 4) {
        i = data_021759c0->mUnk_036;
        i = (u16) i;
    } else {
        i = (u16) i;
        i = (u16) i;
    }
    data_usa_0217ac90 = data_usa_02154fa0[i][0];
    data_usa_0217ac7c = data_usa_02154fa4[i][0];
    data_usa_0217ac78 = data_usa_02154fa8[i][0];
    if (data_021759c0->mCourseId == 0x13) {
        data_usa_021656b4 = 0xa000;
    } else {
        data_usa_021656b4 = 0x5000;
    }
}

void func_02077944(void) {
    Kart *a = GetKart(data_021759c0->mEntryIndex);

    data_0217ac94 = HeapAlloc(GetHeap(func_020364e8()), 0x270);
    func_02076a5c();
    func_02063b10(a, &data_0217ac94->mUnk_260);
    func_02077060(data_0217ac94);
}

void func_020777ac(u32 a) {
    void *h = GetHeap(func_020364e8());
    u16 i;
    u16 n;
    Unk020748b8_218 *e;
    u16 m;
    u16 j;
    s32 k;

    data_0217acbc = HeapAlloc(h, 0x270);
    func_0207729c(data_0217acbc);
    data_0217acbc->mUnk_210 = a;
    data_0217acbc->mUnk_218 = NULL;
    data_0217acbc->mUnk_24c = 0;
    data_0217acbc->mUnk_250 = 1;
    if (data_021759c0->mUnk_00c == 6) {
        data_0217acbc->mUnk_218 = gCourseMap->mUnk_7c;
    }
    if (data_021759c0->mMode == 2) {
        data_0217acbc->mUnk_218 = gCourseMap->mUnk_d0;
        if (data_0217acbc->mUnk_218 != NULL) {
            n = 0;
            k = -1;
            for (i = 0; i < gCourseMap->mUnk_80; i++) {
                if (gCourseMap->mUnk_7c[i].mUnk_3e == 7) {
                    n++;
                }
            }
            data_usa_0217ac70 = n;
            data_0217acbc->mUnk_21c = HeapAlloc(h, n * 0x88);
            e = data_0217acbc->mUnk_218;
            m = 0;
            j = 0;
            for (; m < gCourseMap->mUnk_80; m++) {
                if (k != -1) {
                    e = &gCourseMap->mUnk_7c[(u16) k];
                    if (e == data_0217acbc->mUnk_218) {
                        break;
                    }
                }
                if (e->mUnk_3e == 7) {
                    func_02077750(&data_0217acbc->mUnk_21c[j], e);
                    j++;
                    k = e->mUnk_48;
                }
            }
            data_0217acbc->mUnk_220 = data_0217acbc->mUnk_21c;
            data_0217acbc->mUnk_224 = 0;
            data_0217acbc->mUnk_250 = 3;
            data_0217aca8 = 1;
        }
    }
}

void func_02077750(Unk02077750 *a, Unk020748b8_218 *b) {
    CourseMapEntryGroup *v1 = &gCourseMap->mEntryGroups[b->mUnk_40];

    a->mUnk_7c = b->mUnk_42;
    a->mUnk_7e = 2;
    a->mUnk_00 = b;
    a->mUnk_80 = 0;
    a->mUnk_84 = 0;
    if (v1->mEntryCount >= 4) {
        func_0207be40(&a->mUnk_04, b);
        func_0207bd6c(&a->mUnk_40, b);
    }
}

void func_0207767c(void) {
    void *h = GetHeap(func_020364e8());

    data_usa_0217ac98 = HeapAlloc(h, 0x270);
    data_usa_0217ac84 = HeapAlloc(h, 0x270);
    func_0207729c(data_usa_0217ac98);
    func_0207729c(data_usa_0217ac84);
    data_usa_0217ac98->mUnk_218 = gCourseMap->mUnk_c4;
    data_usa_0217ac84->mUnk_218 = gCourseMap->mUnk_c8;
    data_usa_0217ac98->mUnk_250 = 2;
    data_usa_0217ac84->mUnk_250 = 2;
    if (data_usa_0217ac98->mUnk_218 == NULL) {
        data_0217561c->mUnk_4d0 = 1;
        return;
    }
    if ((s16) data_usa_0217ac98->mUnk_218->mUnk_40 != -1) {
        func_0207be40(&data_usa_0217ac98->mUnk_194, data_usa_0217ac98->mUnk_218);
    }
    if ((s16) data_usa_0217ac84->mUnk_218->mUnk_40 != -1) {
        func_0207be40(&data_usa_0217ac84->mUnk_194, data_usa_0217ac84->mUnk_218);
    }
}

void func_020775e4(void) {
    data_usa_0217ac98 = HeapAlloc(GetHeap(func_020364e8()), 0x270);
    data_usa_0217ac84 = NULL;
    func_0207729c(data_usa_0217ac98);
    data_usa_0217ac98->mUnk_218 = gCourseMap->mUnk_c4;
    data_usa_0217ac98->mUnk_250 = 2;
    data_usa_0217ac98->mUnk_24c = 0;
    if (data_usa_0217ac98->mUnk_218 == NULL) {
        data_0217561c->mUnk_4d0 = 1;
        return;
    }
    if ((s16) data_usa_0217ac98->mUnk_218->mUnk_40 != -1) {
        func_0207be40(&data_usa_0217ac98->mUnk_194, data_usa_0217ac98->mUnk_218);
    }
}

#pragma thumb off

void func_0207729c(Unk02061808 *p) {
    Vec3 b;
    Vec3 a;
    Vec3 c;

    p->mUnk_024.x = 0x1e3000;
    p->mUnk_024.y = 0x4bd000;
    p->mUnk_024.z = 0xc6b000;
    a = *(volatile Vec3 *) &data_usa_02154fdc;
    p->mUnk_018 = a;
    b = *(volatile Vec3 *) &data_usa_02154fc4;
    p->mUnk_000 = data_usa_02154fc4;
    p->mUnk_00c = data_usa_02154fd0;
    Matrix4x3Identity(&p->mUnk_030);
    p->mUnk_15c = data_usa_02154fb8;
    p->mUnk_168 = 0;
    p->mUnk_064 = data_0216569c;
    p->mUnk_060 = data_0216569c + 5;
    p->mUnk_068 = gPairsByAngle[((u16) p->mUnk_060 >> 4) * 2];
    p->mUnk_06a = gPairsByAngle[((u16) p->mUnk_060 >> 4) * 2 + 1];
    p->mUnk_06c = 0x1555;
    p->mUnk_070 = 0x400;
    p->mUnk_08c = 0x640000;
    p->mUnk_074 = gCourseMap->mUnk_018->mUnk_24;
    if (p->mUnk_074 < 0x1000) {
        p->mUnk_074 = 0x640000;
    }
    p->mUnk_078 = 0;
    p->mUnk_07c = 0;
    p->mUnk_080 = 0;
    p->mUnk_084 = 0;
    c = data_usa_02154fdc;
    p->mUnk_09c = c;
    p->mUnk_090 = c;
    p->mUnk_0c0 = b;
    p->mUnk_0cc = 0;
    p->mUnk_0d4 = data_usa_0217ac78;
    p->mUnk_0d8 = 1;
    p->mUnk_0dc = data_usa_0217ac90;
    p->mUnk_0e0 = p->mUnk_0dc;
    p->mUnk_0e4 = 0;
    p->mUnk_0e8 = 0x1000;
    p->mUnk_0ec = 0;
    p->mUnk_0f0 = 0x1000;
    p->mUnk_0f4 = c;
    p->mUnk_100 = c;
    p->mUnk_10c = c;
    p->mUnk_118 = c;
    p->mUnk_130 = 0;
    p->mUnk_124 = c;
    p->mUnk_240 = 0;
    p->mUnk_244 = 0;
    p->mUnk_248 = 0;
    p->mUnk_16c = 0;
    p->mUnk_170 = 0;
    p->mUnk_174 = 0;
    p->mUnk_178 = 0;
    p->mUnk_140 = 0;
    p->mUnk_144 = 0;
    p->mUnk_14c = 0;
    p->mUnk_150 = 1;
    p->mUnk_154 = 0;
    p->mUnk_158 = 0;
    p->mUnk_148 = 0;
    p->mUnk_210 = 0;
    p->mUnk_214 = -1;
    p->mUnk_23c = 0;
    p->mUnk_228 = 0;
    p->mUnk_22c = 0;
    p->mUnk_230 = 0;
    p->mUnk_234 = 0;
    p->mUnk_238 = 0;
    p->mUnk_24c = 0;
    p->mUnk_250 = 0;
    p->mUnk_188 = c;
    p->mUnk_17c = c;
    p->mUnk_254 = 3;
    p->mUnk_258 = 0;
    p->mUnk_25c = 0;
    p->mUnk_260 = c;
    p->mUnk_0a8 = c;
    p->mUnk_0b4 = c;
    p->mUnk_26c = data_021759c0->mUnk_57 ? -1 : 1;
    p->mUnk_21c = NULL;
    p->mUnk_220 = NULL;
    p->mUnk_20c = 0;
    p->mUnk_20e = 0;
    p->mUnk_224 = 0;
    p->mUnk_088 = 0x1000;
}

void func_02077060(Unk02061808 *p) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    if (p == data_0217ac94) {
        if (p->mUnk_060 == p->mUnk_064 && data_0217acac == 0) {
            return;
        }
        if (func_020738f8(p->mUnk_060 - p->mUnk_064) < 10) {
            p->mUnk_060 = p->mUnk_064;
        }
    }
    p->mUnk_078 = (s32) (((s64) p->mUnk_070 * DivFixed12(p->mUnk_068, p->mUnk_06a)) >> 12);
    p->mUnk_07c = -p->mUnk_078;
    p->mUnk_080 = (s32) (((s64) -p->mUnk_078 * p->mUnk_06c) >> 12);
    a = p->mUnk_078;
    b = p->mUnk_07c;
    switch (p->mUnk_24c) {
        case 1:
            a <<= 1;
            b = -a;
            p->mUnk_078 = (s32) (((s64) a * (data_usa_021656b8 + 0x1000)) >> 12);
            p->mUnk_07c = (s32) (((s64) a * data_usa_021656b8) >> 12);
            break;
        case 2:
            b <<= 1;
            a = -b;
            p->mUnk_07c = (s32) (((s64) b * (data_usa_021656b8 + 0x1000)) >> 12);
            p->mUnk_078 = (s32) (((s64) b * data_usa_021656b8) >> 12);
            break;
    }
    if (data_021759c0->mUnk_57 != 0) {
        p->mUnk_080 = -p->mUnk_080;
    }
    p->mUnk_084 = -p->mUnk_080;
    if (data_021759c0->mUnk_00c == 6 && p->mUnk_218 != NULL) {
        c = (s32) (((s64) p->mUnk_078 * p->mUnk_218->mUnk_00.y + 0x800) >> 12);
        p->mUnk_07c += c;
        p->mUnk_078 += c;
    }
    func_020d4a20(a, b, p->mUnk_080, p->mUnk_084, p->mUnk_070, p->mUnk_074);
    *(u32 *) 0x4000440 = 0;
    func_0214b048(p->mUnk_078, p->mUnk_07c, p->mUnk_080, p->mUnk_084, p->mUnk_070, p->mUnk_074, 0x1000, 1,
                  (Unk0214ad4c *) data_0217acc0);
}

void func_02076ed4(Unk02061808 *p) {
    Vec3 c;
    Vec3 b;
    Vec3 a;
    Vec3 d;
    Vec3 e;

    a = data_usa_02154fc4;
    Vec3Sub(&p->mUnk_018, &p->mUnk_024, &b);
    if ((s64) b.x * b.x + (s64) b.y * b.y + (s64) b.z * b.z >= 0x10) {
        func_02039860(&b, &b);
    }
    p->mUnk_15c = b;
    func_020397a8(&a, &b, &c);
    func_020397a8(&b, &c, &p->mUnk_000);
    if (p->mUnk_000.x == 0 && p->mUnk_000.y == 0 && p->mUnk_000.z == 0) {
        p->mUnk_000.x = 0x1000;
        p->mUnk_000.y = 0x1000;
        p->mUnk_000.z = 0x1000;
        if ((s64) p->mUnk_000.x * p->mUnk_000.x + (s64) p->mUnk_000.y * p->mUnk_000.y +
                (s64) p->mUnk_000.z * p->mUnk_000.z >=
            0x10) {
            func_02039860(&p->mUnk_000, &p->mUnk_000);
        }
    }
    *(u32 *) 0x4000440 = 2;
    d.x = p->mUnk_024.x >> 4;
    d.y = (p->mUnk_024.y + p->mUnk_178) >> 4;
    d.z = p->mUnk_024.z >> 4;
    e.x = p->mUnk_018.x >> 4;
    e.y = p->mUnk_018.y >> 4;
    e.z = p->mUnk_018.z >> 4;
    func_0214abb4(&d, &p->mUnk_000, &e, 1, &p->mUnk_030);
}

void func_02076cd0(Unk02061808 *p) {
    Vec3 a;
    Vec3 b;
    Vec3 c;
    Vec3 d;

    b = p->mUnk_0c0;
    c = p->mUnk_024;
    d = p->mUnk_018;
    d.y += p->mUnk_158;
    Vec3Sub(&d, &c, &a);
    if ((s64) a.x * a.x + (s64) a.y * a.y + (s64) a.z * a.z >= 0x10) {
        func_02039860(&a, &a);
    }
    p->mUnk_15c = a;
    func_020397a8(&b, &a, &p->mUnk_00c);
    func_020397a8(&a, &p->mUnk_00c, &p->mUnk_000);
    if (p->mUnk_000.x == 0 && p->mUnk_000.y == 0 && p->mUnk_000.z == 0) {
        p->mUnk_000.x = 0x1000;
        p->mUnk_000.y = 0x1000;
        p->mUnk_000.z = 0x1000;
        if ((s64) p->mUnk_000.x * p->mUnk_000.x + (s64) p->mUnk_000.y * p->mUnk_000.y +
                (s64) p->mUnk_000.z * p->mUnk_000.z >=
            0x10) {
            func_02039860(&p->mUnk_000, &p->mUnk_000);
        }
    }
    if (p->mUnk_130 != 0) {
        func_02073904(p);
        Vec3Add(&c, &p->mUnk_118, &c);
        Vec3Add(&d, &p->mUnk_10c, &d);
        Vec3Add(&p->mUnk_124, &d, &d);
    }
    p->mUnk_09c.x = c.x >> 4;
    p->mUnk_09c.y = c.y >> 4;
    p->mUnk_09c.z = c.z >> 4;
    p->mUnk_09c.y += p->mUnk_178 >> 4;
    p->mUnk_090.x = d.x >> 4;
    p->mUnk_090.y = d.y >> 4;
    p->mUnk_090.z = d.z >> 4;
    *(u32 *) 0x4000440 = 2;
    func_0214abb4(&p->mUnk_09c, &p->mUnk_000, &p->mUnk_090, 1, &p->mUnk_030);
}
