#include "Main/Unknown/code_020ab058.h"

#include "Main/Unknown/code_020ab088.h"
#include "Main/Unknown/code_020ab1a8.h"
#include "Main/Unknown/code_020ab5e4.h"
#include "Main/Unknown/code_020ab714.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/code_020ab194.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_0214d018.h"

#pragma thumb on
u32 func_020ab194(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (u32) &data_0217b234;
    *(u32 *) ((value2) + 0u) = value0;
    value0 = (u32) &data_0217b238;
    *(u32 *) ((value0) + 0u) = value1;
    return value0;
}
#pragma thumb off

#pragma thumb on

void func_020ab11c(s32 *a, s32 *b, s32 *c, s32 *d) {
    if (data_0217b278.mUnk_44 != NULL && a != NULL && b != NULL && c != NULL && d != NULL) {
        *a = data_0217b278.mUnk_44->mUnk_00;
        *b = data_0217b278.mUnk_44->mUnk_01;
        *c = data_0217b278.mUnk_44->mUnk_00 + data_0217b278.mUnk_44->mUnk_02;
        *d = data_0217b278.mUnk_44->mUnk_01 + data_0217b278.mUnk_44->mUnk_03;
        if (data_0217b278.mUnk_44->mUnk_06 <= 0xff) {
            *a = *a + data_0217b234;
            *b = *b + data_0217b238;
            *c = *c + data_0217b234;
            *d = *d + data_0217b238;
        }
    }
}

void func_020ab088(struct Unk02022aa8 *a, void *b, u16 *c, s32 d, s32 e, s32 f) {
    MemFill(&data_0217b278, 0, 0x54);
    data_0217b254.mUnk_00 = a;
    data_0217b254.mUnk_04 = b;
    data_0217b254.mUnk_08 = b;
    data_0217b254.mUnk_0c = c;
    data_0217b254.mUnk_10 = d;
    data_0217b254.mUnk_14 = e;
    data_0217b254.mUnk_1c = f;
    func_020ab714();
    func_020ab5e4(&data_0217b2ac, 0x28, 5);
    func_020ab580(data_021679fc[2] | (data_021679fc[0] | 0xf0 | data_021679fc[1]));
    data_0217b24c[0] = data_0217b244[0] = data_0217b23c[0] = data_02167a04[0];
    data_0217b24c[1] = data_02167a04[1];
    data_0217b244[1] = data_02167a04[2];
    data_0217b23c[1] = data_02167a04[3];
}

#pragma thumb off

#pragma thumb on
void func_020ab07c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &data_0217b254;
    *(u32 *) ((value1) + 24u) = value0;
}
#pragma thumb off

#pragma thumb on
void func_020ab070(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &data_0217b254;
    *(u32 *) ((value1) + 32u) = value0;
}
#pragma thumb off

#pragma thumb on
void func_020ab064(u16 (*arg0)(s32, u16)) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_0217b278;
    *(u32 *) ((value1) + 76u) = value0;
}
#pragma thumb off

#pragma thumb on
void func_020ab058(s32 (*arg0)(u32, s32)) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_0217b278;
    *(u32 *) ((value1) + 80u) = value0;
}
#pragma thumb off
