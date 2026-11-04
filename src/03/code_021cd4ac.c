#include "03/code_021cd4ac.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd000.h"
#include "03/unk_021d7000.h"
#include "code_0200d118.h"
#include "code_0201ec30.h"
#include "Main/Unknown/code_02151718.h"

#include "03/code_021cd2e0.h"
#include "code_02134d30.h"
#include "code_021510a4.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214d000.h"
#include "03/unk_021da000.h"
#include "03/code_021cd2cc.h"
#include "03/code_021d3254.h"
#include "03/code_021d27d8.h"
#include "code_020205b0.h"

void func_ov003_021cdb90(void) {
    Unk021cd5e0 *v1;
    v1 = func_ov003_021d285c(0x6f8, 0x20);
    data_ov003_021da270 = v1;
    Crc16InitTable(&v1->mUnk_400.mUnk_f8, 0xa001);
    func_02151804((u32) data_ov003_021da270);
}

void func_ov003_021cdb80(void) {
    func_ov003_021d2808(&data_ov003_021da270);
}

int func_ov003_021cdb6c(void) {
    return (s32) data_ov003_021da270 + 0x400;
}

void func_ov003_021cdb58(u32 a) {
    data_ov003_021da270->mUnk_400.mUnk_f5 = a;
}

void func_ov003_021cdb44(u32 a) {
    data_ov003_021da270->mUnk_400.mUnk_f6 = a;
}

void func_ov003_021cdb14(const u8 *a) {
    MemCopy(a, data_ov003_021da270->mUnk_400.mUnk_00.mUnk_40, (u32) 0x20);
    data_ov003_021da270->mUnk_400.mUnk_00.mUnk_e7 = 0;
}

void func_ov003_021cd9dc(const u8 *a) {
    s32 i;
    s32 n;
    u8 *p;
    MemFill(data_ov003_021da270->mUnk_400.mUnk_00.mUnk_80[0], 0, 0x10);
    n = func_ov003_021d3254(a, 0x20);
    switch (n) {
        case 0:
        case 10:
        case 26:
        case 32:
            data_ov003_021da270->mUnk_400.mUnk_00.mUnk_e6_2 = 0;
            p = data_ov003_021da270->mUnk_400.mUnk_00.mUnk_80[0];
            i = 0;
            for (; i < n;) {
                *p = (func_ov003_021cd2cc(a[i]) << 4) + func_ov003_021cd2cc(a[i + 1]);
                i += 2;
                p++;
            }
            break;
        default:
            data_ov003_021da270->mUnk_400.mUnk_00.mUnk_e6_2 = 1;
            MemCopy(a, data_ov003_021da270->mUnk_400.mUnk_00.mUnk_80[0], 0x10);
            break;
    }
    switch (n) {
        case 0:
            data_ov003_021da270->mUnk_400.mUnk_00.mUnk_e6_0 = 0;
            break;
        case 5:
        case 10:
            data_ov003_021da270->mUnk_400.mUnk_00.mUnk_e6_0 = 1;
            break;
        case 13:
        case 26:
            data_ov003_021da270->mUnk_400.mUnk_00.mUnk_e6_0 = 2;
            break;
        default:
            data_ov003_021da270->mUnk_400.mUnk_00.mUnk_e6_0 = 3;
            break;
    }
}

void func_ov003_021cd9c4(const char *input) {
    func_ov003_021cd2e0(input, (u8 *) data_ov003_021da270 + 0x4c0);
}

void func_ov003_021cd9ac(const char *input) {
    func_ov003_021cd2e0(input, (u8 *) data_ov003_021da270 + 0x4f0);
}

void func_ov003_021cd994(const char *input) {
    func_ov003_021cd2e0(input, (u8 *) data_ov003_021da270 + 0x4c4);
}

void func_ov003_021cd97c(const char *input) {
    func_ov003_021cd2e0(input, (u8 *) data_ov003_021da270 + 0x4c8);
}

void func_ov003_021cd964(const char *input) {
    func_ov003_021cd2e0(input, (u8 *) data_ov003_021da270 + 0x4cc);
}

void func_ov003_021cd948(void *output) {
    MemCopy((u8 *) data_ov003_021da270 + 0x440, output, 0x20);
}

void func_ov003_021cd918(u32 p0) {
    u8 *v5 = data_ov003_021da270->mUnk_400.mUnk_00.mUnk_c0;
    u32 v6 = ((u32) v5[2]);
    u32 v8 = ((u32) v5[3]);
    const char *v10 = data_ov003_021d77c4;
    u32 v11 = ((u32) v5[0]);
    u32 v12 = ((u32) v5[1]);
    u32 v13 = StringFormat((char *) p0, v10, v11, v12, v6, v8);
}

void func_ov003_021cd8e8(u32 p0) {
    u8 *v5 = data_ov003_021da270->mUnk_400.mUnk_f0;
    u32 v6 = ((u32) v5[2]);
    u32 v8 = ((u32) v5[3]);
    const char *v10 = data_ov003_021d77c4;
    u32 v11 = ((u32) v5[0]);
    u32 v12 = ((u32) v5[1]);
    u32 v13 = StringFormat((char *) p0, v10, v11, v12, v6, v8);
}

void func_ov003_021cd8b8(u32 p0) {
    u8 *v5 = data_ov003_021da270->mUnk_400.mUnk_00.mUnk_c4;
    u32 v6 = ((u32) v5[2]);
    u32 v8 = ((u32) v5[3]);
    const char *v10 = data_ov003_021d77c4;
    u32 v11 = ((u32) v5[0]);
    u32 v12 = ((u32) v5[1]);
    u32 v13 = StringFormat((char *) p0, v10, v11, v12, v6, v8);
}

void func_ov003_021cd888(u32 p0) {
    u8 *v5 = data_ov003_021da270->mUnk_400.mUnk_00.mUnk_c8;
    u32 v6 = ((u32) v5[2]);
    u32 v8 = ((u32) v5[3]);
    const char *v10 = data_ov003_021d77c4;
    u32 v11 = ((u32) v5[0]);
    u32 v12 = ((u32) v5[1]);
    u32 v13 = StringFormat((char *) p0, v10, v11, v12, v6, v8);
}

void func_ov003_021cd858(u32 p0) {
    u8 *v5 = &data_ov003_021da270->mUnk_400.mUnk_00.mUnk_c8[4];
    u32 v6 = ((u32) v5[2]);
    u32 v8 = ((u32) v5[3]);
    const char *v10 = data_ov003_021d77c4;
    u32 v11 = ((u32) v5[0]);
    u32 v12 = ((u32) v5[1]);
    u32 v13 = StringFormat((char *) p0, v10, v11, v12, v6, v8);
}

u8 func_ov003_021cd844(int a) {
    return data_ov003_021da270->mUnk_000[a].mUnk_00.mUnk_e7;
}

void func_ov003_021cd790(s32 a) {
    Unk021cd5e0 *o = data_ov003_021da270;
    Unk021cd5e0_entry *q = &o->mUnk_000[a].mUnk_00;
    o->mUnk_400.mUnk_00 = *q;
    o->mUnk_400.mUnk_f4 = a;
    if (memcmp(q->mUnk_c0, data_ov003_021d6684, 4) != 0) {
        data_ov003_021da270->mUnk_400.mUnk_f5 = 0;
    } else {
        data_ov003_021da270->mUnk_400.mUnk_f5 = 1;
    }
    if (memcmp(q->mUnk_c8, data_ov003_021d6684, 4) != 0 || memcmp(q->mUnk_c8 + 4, data_ov003_021d6684, 4) != 0) {
        data_ov003_021da270->mUnk_400.mUnk_f6 = 0;
    } else {
        data_ov003_021da270->mUnk_400.mUnk_f6 = 1;
    }
    func_021516b0(q->mUnk_d0, data_ov003_021da270->mUnk_400.mUnk_f0);
}

void func_ov003_021cd6d0(void) {
    Unk021cd5e0_400 *p = &data_ov003_021da270->mUnk_400;
    Unk021cd5e0_entry *q = &data_ov003_021da270->mUnk_000[p->mUnk_f4].mUnk_00;
    *q = p->mUnk_00;
    if (p->mUnk_f5 != 0) {
        MemFill(q->mUnk_c0, 0, 4);
        MemFill(q->mUnk_c4, 0, 4);
        q->mUnk_d0 = 0;
    } else {
        MemCopy(p->mUnk_00.mUnk_c0, q->mUnk_c0, 4);
        MemCopy(p->mUnk_00.mUnk_c4, q->mUnk_c4, 4);
        q->mUnk_d0 = func_021516d8(p->mUnk_f0);
    }
    if (p->mUnk_f6 != 0) {
        MemFill(q->mUnk_c8, 0, 8);
    } else {
        MemCopy(p->mUnk_00.mUnk_c8, q->mUnk_c8, 8);
    }
    func_ov003_021cd338(p->mUnk_f4);
}

void func_ov003_021cd5e0(const Unk021cd5e0_arg *a) {
    Unk021cd5e0_400 *p;
    u32 n;
    s32 i;
    u8 *v1;
    u8 *v2;
    p = &data_ov003_021da270->mUnk_400;
    MemFill(p, 0, 0xef);
    MemCopy(a, p->mUnk_00.mUnk_40, 0x20);
    switch (a->mUnk_20) {
        case 1:
            p->mUnk_00.mUnk_e6_0 = 1;
            n = 5;
            break;
        case 2:
            p->mUnk_00.mUnk_e6_0 = 2;
            n = 0xd;
            break;
        case 3:
            p->mUnk_00.mUnk_e6_0 = 3;
            n = 0x10;
            break;
        default:
            p->mUnk_00.mUnk_e6_0 = 0;
            n = 0;
            break;
    }
    p->mUnk_00.mUnk_e6_2 = 0;
    i = 0;
    v2 = p->mUnk_00.mUnk_80[0];
    v1 = (u8 *) a->mUnk_28;
    for (; i < 4; i++) {
        MemCopy(v1, v2, n);
        v2 += 0x10;
        v1 += 0x20;
    }
    p->mUnk_00.mUnk_e7 = 2;
    MemFill(p->mUnk_f0, 0, 4);
    p->mUnk_f5 = 1;
    p->mUnk_f6 = 1;
    func_ov003_021cd6d0();
}

void func_ov003_021cd4e8(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value4;
    u32 value5;
    value5 = (value0) + (0u);
    value0 = (u32) &data_ov003_021da270;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 0x400u;
    value4 = (value1) + (value0);
    value0 = (value4) + (0u);
    value1 = 0u;
    value2 = 239u;
    MemFill((void *) value0, (u8) value1, value2);
    value0 = (value5) + (0u);
    value1 = (value4) + (0u);
    value1 = (value1) + 209u;
    value2 = 5u;
    MemCopy((const void *) value0, (void *) value1, value2);
    value0 = (value5) + (6u);
    value1 = (value4) + (0u);
    value1 = (value1) + 214u;
    value2 = 5u;
    MemCopy((const void *) value0, (void *) value1, value2);
    value0 = (value5) + (0u);
    value0 = (value0) + 12u;
    value1 = (value4) + (0u);
    value1 = (value1) + 219u;
    value2 = 5u;
    MemCopy((const void *) value0, (void *) value1, value2);
    value0 = (value5) + (0u);
    value0 = (value0) + 18u;
    value1 = (value4) + (0u);
    value1 = (value1) + 224u;
    value2 = 5u;
    MemCopy((const void *) value0, (void *) value1, value2);
    value0 = (value5) + (0u);
    value0 = (value0) + 24u;
    value1 = (value4) + (0u);
    value1 = (value1) + 96u;
    value2 = 32u;
    MemCopy((const void *) value0, (void *) value1, value2);
    value0 = (value5) + (0u);
    value0 = (value0) + 57u;
    value1 = (value4) + (0u);
    value1 = (value1) + 128u;
    value2 = 13u;
    MemCopy((const void *) value0, (void *) value1, value2);
    value0 = (value5) + (0u);
    value0 = (value0) + 71u;
    value1 = (value4) + (0u);
    value1 = (value1) + 144u;
    value2 = 13u;
    MemCopy((const void *) value0, (void *) value1, value2);
    value0 = (value5) + (0u);
    value0 = (value0) + 85u;
    value1 = (value4) + (0u);
    value1 = (value1) + 160u;
    value2 = 13u;
    MemCopy((const void *) value0, (void *) value1, value2);
    value0 = (value5) + (0u);
    value0 = (value0) + 99u;
    value1 = (value4) + (0u);
    value1 = (value1) + 176u;
    value2 = 13u;
    MemCopy((const void *) value0, (void *) value1, value2);
    value5 = (value5) + 113u;
    value0 = (value5) + (0u);
    value1 = (value4) + (0u);
    value1 = (value1) + 64u;
    value2 = 32u;
    MemCopy((const void *) value0, (void *) value1, value2);
    value0 = (value4) + (0u);
    value0 = (value0) + 230u;
    value1 = (u32) * (const u8 *) ((value0) + 0u);
    value0 = 3u;
    value1 = (value1) & ~(value0);
    value0 = 2u;
    value1 = (value1) | (value0);
    value0 = (value4) + (0u);
    value0 = (value0) + 230u;
    *(u8 *) ((value0) + 0u) = (u8) value1;
    value0 = (value4) + (0u);
    value0 = (value0) + 230u;
    value1 = (u32) * (const u8 *) ((value0) + 0u);
    value0 = 252u;
    value1 = (value1) & ~(value0);
    value0 = (value4) + (0u);
    value0 = (value0) + 230u;
    *(u8 *) ((value0) + 0u) = (u8) value1;
    value1 = 1u;
    value0 = (value4) + (0u);
    value0 = (value0) + 231u;
    *(u8 *) ((value0) + 0u) = (u8) value1;
    value0 = (value4) + (0u);
    value0 = (value0) + 240u;
    value1 = 0u;
    value2 = 4u;
    MemFill((void *) value0, (u8) value1, value2);
    value1 = 1u;
    value0 = (value4) + (0u);
    value0 = (value0) + 245u;
    *(u8 *) ((value0) + 0u) = (u8) value1;
    value4 = (value4) + 246u;
    *(u8 *) ((value4) + 0u) = (u8) value1;
    func_ov003_021cd6d0();
    return;
}

u32 func_ov003_021cd4dc(void) {
    return (u32) data_ov003_021da270;
}

void func_ov003_021cd4ac(int a) {
    Unk021cd5e0_entry *v1;
    v1 = &data_ov003_021da270->mUnk_000[a].mUnk_00;
    MemFill(v1, (u8) (0), 0xef);
    v1->mUnk_e7 = 0xff;
    func_ov003_021cd338((u32) (a));
    return;
}
