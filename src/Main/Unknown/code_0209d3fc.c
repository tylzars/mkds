#include "Main/Unknown/code_0209d3fc.h"

#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_0209d5e8.h"
#include "Main/Unknown/code_0209d5ec.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_0209d650.h"

void func_0209d650(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value4;
    value4 = value0;
    value1 = (u32) * (const u32 *) ((value4) + (156));
    value0 = (value4) + (0xb8u);
    value2 = 0u;
    func_020d7da8((Unk020e0144 *) value0, (Unk020fa294 *) value1, (s32) value2);
    value0 = 0x1aeu;
    value2 = value4;
    value1 = 0x1eu;
    func_020ac588(value0, value1, (void *) value2);
    value0 = 0u;
    *(u32 *) ((value4) + (16)) = value0;
    *(u32 *) ((value4) + (20)) = value0;
    *(u32 *) ((value4) + (24)) = value0;
}

void CreateSunAndSunLOD(void *a) {
    gSun = func_0209be84(a, gSunNsbmdName);
    func_0209be50(gSun, gSunNsbcaName);
    gSunLOD = func_0209be84(a, gSunLODNsbmdName);
    func_0209b940(gSun, func_020d3c2c());
}

u32 func_0209d5e8(u32 p0) {
    return p0;
}

void func_0209d3fc(void *a, Unk0209d3fc *b) {
    s32 s;
    s32 t;
    s32 k;
    Vec3 v;

    s = 0x1e;
    func_01ff9048(0x14, &s, 1);
    func_01ff9048(0x19, func_020e6cf8(&b->mUnk_00.mUnk_04), 0xc);
    if (b->mUnk_dc == 3 || b->mUnk_dc == 4) {
        t = (s32) (((s64) data_0215d4b4[((u16) b->mUnk_ac >> 4) * 2 + 1] * -0x14000) >> 12) + 0x14000;
        k = (b->mUnk_b0 >> 4) * 2;
        v.x = (s32) (((s64) t * data_0215d4b4[k + 1]) >> 12) >> 4;
        v.y = (s32) (((s64) t * data_0215d4b4[k]) >> 12) >> 4;
        v.z = 0;
        func_01ff9048(0x1c, &v, 3);
    }
    func_01ff9048(0x1b, &b->mUnk_00.mUnk_1c, 3);
    if (func_02061818() == 2) {
        func_0209bbd0(a, gSun);
        func_0209b77c(gSun, b->mUnk_b2);
        func_0209bb2c(a, gSun, b);
    } else if ((s32) (b->mUnk_00.mUnk_78 & 0x3fffffe0) < 0x3d0900) {
        func_0209bbd0(a, gSun);
        func_0209b77c(gSun, b->mUnk_b2);
        func_0209bb2c(a, gSun, b);
    } else {
        func_0209bbd0(a, gSunLOD);
        func_0209ba58(a, gSunLOD, b);
    }
}
