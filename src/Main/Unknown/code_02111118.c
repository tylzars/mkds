#include "Main/Unknown/code_0202a360.h"
#include "Main/Unknown/code_02111118.h"

#include "Main/Unknown/code_02111158.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212da38.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0211127c.h"
#include "Main/Unknown/code_021112fc.h"

void func_021112fc(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &data_0217d32c;
    *(u32 *) ((value1) + (12)) = value0;
}

u32 func_0211127c(void) {
    u32 v1;
    u32 v2;
    v2 = 0xffffffff;
    v1 = func_0202a360();
    switch (v1) {
        case 0:
            v2 = 0x43;
            break;
        case 1:
            v2 = 0x44;
            break;
        case 2:
            v2 = 0x3f;
            break;
        case 3:
            v2 = 0x41;
            break;
        case 4:
            v2 = 0x40;
            break;
        case 5:
            v2 = 0x3f;
            break;
        case 6:
            v2 = 0x41;
            break;
        case 7:
            v2 = 0x40;
    }
    return v2;
}

void func_02111250(void *a, u32 b) {
    data_0217d32c.mUnk_04 = HeapStackCreate(a, b);
    data_0217d32c.mUnk_08 = NULL;
}

u32 func_02111158(s32 a) {
    Unk0217d32c *p;
    u32 *b;
    HeapStack *n;
    s32 i;
    n = data_0217d130;
    p = &data_0217d32c;
    if (a == 4 && (data_021759c0->mUnk_08 == 4 ? data_021759c0->mMissionTableColumn : -1) == 9) {
        b = data_0216cbc0;
    } else {
        b = data_0216cbd8[a];
    }
    if (p->mUnk_08 == b) {
        return 1;
    }
    data_0217d130 = data_0217d32c.mUnk_04;
    HeapStackReset(p->mUnk_04);
    for (i = 0; i < 6; i++) {
        if (b[i] != 0xff) {
            if (func_0212e9cc(b[i], data_0217d130) == 0) {
                data_0217d130 = n;
                return 0;
            }
        }
    }
    p->mUnk_00 = a;
    p->mUnk_08 = b;
    data_0217d130 = n;
    return 1;
}

u32 func_02111144(void) {
    u32 value0;
    value0 = (u32) &data_0217d32c;
    value0 = (u32) * (const u32 *) ((value0) + (8));
    value0 = (u32) * (const u32 *) ((value0) + (20));
    return value0;
}

u32 func_02111118(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    value2 = (u32) &data_0217d328;
    value3 = 0u;
    value1 = (u32) &data_0217d324;
    value0 = (u32) &data_0217d320;
    *(u32 *) ((value2) + (0)) = value3;
    *(u32 *) ((value1) + (0)) = value3;
    *(u32 *) ((value0) + (0)) = value3;
    return value0;
}
