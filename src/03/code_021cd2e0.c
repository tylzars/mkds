#include "03/code_021cd2e0.h"
#include "03/code_021cd4ac.h"
#include "03/code_021d27d8.h"
#include "03/unk_021da000.h"
#include "code_020205b0.h"
#include "code_021510a4.h"
#include "code_0213a460.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "code_02151fc4.h"
#include "Main/Unknown/code_02151718.h"

void func_ov003_021cd2e0(const char *v1, u8 *v2) {
    u8 a[4];
    s32 i;
    s32 j;
    u8 *p;
    MemFill(a, 0, 4);
    for (i = 0; i < 4; i++) {
        MemCopy(v1 + i * 3, a, 3);
        j = 0;
        p = a;
        for (; j < 3; j++) {
            if (*p != 0) {
                break;
            }
            *p = ' ';
            p++;
        }
        v2[i] = StrtolBase10((const char *) a);
    }
}

void func_ov003_021cd338(s32 param_1) {
    u32 a = data_ov003_021da270->mUnk_000[param_1].mUnk_00.mUnk_e7;
    u32 b = 1 << param_1;
    BOOL c = FALSE;
    s32 d[4];
    void *e;
    Unk021cd5e0 *p;
    s32 i;
    MemFill(d, 0, 0x10);
    d[param_1] = 1;
    if (param_1 <= 2) {
        p = data_ov003_021da270;
        if ((p->mUnk_000[0].mUnk_00.mUnk_e8[7] & b) != 0) {
            c = TRUE;
        }
        if (a == 0xff && c != FALSE) {
            p->mUnk_000[0].mUnk_00.mUnk_e8[7] = p->mUnk_000[0].mUnk_00.mUnk_e8[7] & ~b;
            data_ov003_021da270->mUnk_000[1].mUnk_00.mUnk_e8[7] =
                data_ov003_021da270->mUnk_000[1].mUnk_00.mUnk_e8[7] & ~b;
            d[1] = 1;
            d[0] = 1;
        } else if (a != 0xff && c == FALSE) {
            p->mUnk_000[0].mUnk_00.mUnk_e8[7] = p->mUnk_000[0].mUnk_00.mUnk_e8[7] | b;
            data_ov003_021da270->mUnk_000[1].mUnk_00.mUnk_e8[7] =
                data_ov003_021da270->mUnk_000[1].mUnk_00.mUnk_e8[7] | b;
            d[1] = 1;
            d[0] = 1;
        }
    }
    for (i = 0; i < 4; i++) {
        if (d[i] != 0) {
            data_ov003_021da270->mUnk_000[i].mUnk_fe =
                Crc16(&data_ov003_021da270->mUnk_400.mUnk_f8, data_ov003_021da270->mUnk_000[i].mUnk_00.mUnk_00, 0xfe);
        }
    }
    e = func_ov003_021d285c(0x100, 0x20);
    func_02151794((s32) data_ov003_021da270, d, e);
    func_ov003_021d2808(&e);
}

void func_ov003_021cd42c(void) {
    volatile u16 a = 0;
    Unk021510a4 b;
    u8 *c;
    s32 i;
    MemFillHalfwords(a, data_ov003_021da270, 0x400);
    for (i = 0; i < 3; i++) {
        data_ov003_021da270->mUnk_000[i].mUnk_00.mUnk_e7 = 0xff;
    }
    func_02151fc4(&b);
    c = func_021510a4(&b);
    for (i = 0; i < 2; i++) {
        MemCopy(c, data_ov003_021da270->mUnk_000[i].mUnk_f0, 0xe);
    }
    for (i = 0; i < 4; i++) {
        func_ov003_021cd338(i);
    }
}
