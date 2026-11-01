#include "Main/Unknown/code_02039774.h"
#include "code_0201e5a8.h"
#include "code_0200fd1c.h"
#include "code_02148d34.h"
#include "code_0214d018.h"

static inline u32 func_020399a8_inline(void) {
    return data_02175614.mUnk_00 == 2;
}

void func_02039c7c(void) {
    data_02175614.mUnk_00 = 1;
    data_02175614.mUnk_04 = 0;
}

void func_02039bd4(void) {
    switch (data_02175614.mUnk_00) {
        case 0:
            func_021492d8(0x1f7);
            func_0214d05c_inline((void *) 0x6800000, 0x60000);
            func_0214d05c_inline((void *) 0x6880000, 0x24000);
            break;
        case 2:
            break;
        case 1:
        case 3:
            func_021492d8(0x1ff);
            func_0214d05c_inline((void *) 0x6800000, 0xa4000);
            break;
    }
    func_02148dac();
}

void func_02039b94(u32 a) {
    switch (data_02175614.mUnk_00) {
        case 0:
        case 2:
            break;
        case 1:
        case 3:
            func_021492f8(a);
            break;
    }
}

void func_02039b24(void) {
    func_02148e6c();
    func_02148e58();
    func_02148e34();
    func_02148e10();
    func_02148dfc();
    func_02148de8();
    func_02148dd4();
    func_02148d98();
    func_02148d84();
    func_02148d5c();
    func_02148d34();
    func_02148dac();
    switch (data_02175614.mUnk_00) {
        case 0:
        case 2:
            break;
        case 1:
        case 3:
            func_02148dc0();
            break;
    }
}

void func_02039abc(u32 a, s32 b) {
    if (b != 0) {
        func_0200fd1c();
    }
    data_02175614.mUnk_00 = a;
    if (data_02175614.mUnk_04 == 0) {
        return;
    }
    switch (a) {
        case 0:
            data_02175614.mUnk_04(0);
            break;
        case 1:
            data_02175614.mUnk_04(1);
            break;
    }
}

void func_02039a1c(void) {
    if (data_02175614.mUnk_00 != 0 && data_02175614.mUnk_00 != 3) {
        data_02175614.mUnk_00 = 2;
        func_021492d8(8);
        func_0214d05c_inline((void *) 0x6860000, 0x20000);
        func_02148dac();
        if (func_0201e7a8(8, func_02039abc, 0) != 1) {
            func_0200fd1c();
        }
    }
    while (func_020399a8_inline() != 0) {
    }
}

void func_020399a8(void) {
    if (data_02175614.mUnk_00 != 1 && data_02175614.mUnk_00 != 3) {
        data_02175614.mUnk_00 = 2;
        if (func_0201e6b8(func_02039abc, 1) != 1) {
            func_0200fd1c();
        }
    }
    while (func_020399a8_inline() != 0) {
    }
}

s32 func_02039860(const Vec3 *v, Vec3 *v1) {
    s64 w;
    s32 r;
    s64 q;
    s64 t;
    w = (s64) v->x * v->x;
    w += (s64) v->y * v->y;
    w += (s64) v->z * v->z;
    *(vu16 *) 0x4000280 = 2;
    *(vu64 *) 0x4000290 = 0x1000000000000LL << 8;
    *(vu64 *) 0x4000298 = w;
    *(vu16 *) 0x40002b0 = 1;
    *(vu64 *) 0x40002b8 = w << 2;
    while (*(vu16 *) 0x40002b0 & 0x8000) {
    }
    r = *(vu32 *) 0x40002b4;
    while (*(vu16 *) 0x4000280 & 0x8000) {
    }
    q = *(vu64 *) 0x40002a0;
    t = q * r;
    v1->x = (s32) ((t * v->x + 0x100000000000LL) >> 45);
    v1->y = (s32) ((t * v->y + 0x100000000000LL) >> 45);
    v1->z = (s32) ((t * v->z + 0x100000000000LL) >> 45);
    return (r + 1) >> 1;
}

s32 func_02039828(const Vec3 *a, const Vec3 *b) {
    return (s32) (((s64) a->x * b->x + (s64) a->y * b->y + (s64) a->z * b->z) >> 12);
}

void func_020397a8(const Vec3 *a, const Vec3 *b, Vec3 *v1) {
    s64 x;
    s64 y;
    s64 z;
    x = (s64) a->y * b->z - (s64) a->z * b->y;
    y = (s64) a->z * b->x - (s64) a->x * b->z;
    z = (s64) a->x * b->y - (s64) a->y * b->x;
    v1->x = (s32) (x >> 12);
    v1->y = (s32) (y >> 12);
    v1->z = (s32) (z >> 12);
}

void func_02039774(void) {
    data_usa_021755e4.mUnk_08 = 0;
    data_usa_021755e4.mUnk_0a = 0;
    data_usa_021755e4.mUnk_0c = 0;
    data_usa_021755e4.mUnk_0e = 3;
    data_usa_021755e4.mUnk_00 = 0;
    data_usa_021755e4.mUnk_02 = 0;
    data_usa_021755e4.mUnk_04 = 0;
    data_usa_021755e4.mUnk_06 = 3;
}
