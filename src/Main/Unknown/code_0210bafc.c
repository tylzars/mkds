#include "Main/Unknown/code_0210bafc.h"

#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0210bbec.h"
#include "code_0212d214.h"
#include "code_020172d0.h"

u32 func_0210bc8c(void *a, void *b) {
    BOOL i;
    Unk0210bc54 *p;

    p = (Unk0210bc54 *) ((u8 *) b + ((NNSFndList *) a)->mLinkOffset);
    if (p->mUnk_08 != 0) {
        i = FALSE;
    } else {
        i = TRUE;
        p->mUnk_08 = a;
    }
    if (i != FALSE) {
        NNS_FndAppendListObject((NNSFndList *) a, b);
    } else {
        return 0;
    }
    return 1;
}

void func_0210bc54(NNSFndList *a, void *b) {
    Unk0210bc54 *p;

    NNS_FndRemoveListObject(a, b);
    p = (Unk0210bc54 *) ((u8 *) b + a->mLinkOffset);
    if (p->mUnk_08 != 0) {
        p->mUnk_08 = 0;
    }
}

void func_0210bc14(void) {
    __clear(data_0217cd30, 0x17 * sizeof(Unk0217cd30));
}

u32 func_0210bc00(u32 arg0, u32 arg1, void *arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = (u32) arg2;
    u32 value3;
    value3 = (u32) &data_0217cd30;
    value0 = (value3) + ((value0 << 5));
    *(u32 *) ((value0) + ((value1 << 2))) = value2;
    return value0;
}

u32 func_0210bbec(u32 arg0, u32 arg1, Unk0216c860 *arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = (u32) arg2;
    u32 value3;
    value3 = (u32) &data_0217cd30;
    value0 = (value3) + ((value0 << 5));
    *(u32 *) ((value0) + ((value1 << 2))) = value2;
    return value0;
}

u32 func_0210bb74(s32 a, s32 b, s32 c) {
    s32 p;
    s32 v;

    p = ((Unk0217cd30 *) data_0217cd30)[b].mUnk_00[c];
    v = p != 0 ? ((u32 *) p)[a] : 0xffff;
    if (v != 0xffff) {
        return (u16) v;
    }
    v = data_0215a6fc[b][c];
    if (v == 0x14) {
        v = 0xffff;
    }
    if (v == 0xffff) {
        return 0xffff;
    }
    return *(u16 *) (data_0216ca84 + a * 0x26 + v * 2);
}

u32 func_0210bafc(s32 a, s32 b, s32 c) {
    s32 p;
    s32 v;

    p = ((Unk0217cd30 *) data_0217cd30)[b].mUnk_00[c];
    v = p != 0 ? ((u32 *) p)[a] : 0xffff;
    if (v != 0xffff) {
        return (u16) v;
    }
    v = data_0215a6fc[b][c];
    if (v == 0xe) {
        v = 0xffff;
    }
    if (v == 0xffff) {
        return 0xffff;
    }
    return *(u16 *) (data_0216ca68 + a * 0x1a + v * 2);
}
