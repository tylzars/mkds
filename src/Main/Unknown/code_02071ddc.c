#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02071ddc.h"

#include "code_0201750c.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020172d0.h"

void func_02071fb8(Unk0206bcb0 *p, void *a) {
    Unk0206bcb0_514 *q;
    Vec3 v;
    u16 i;
    u8 *b;

    q = p->mUnk_514;
    if (q == NULL) {
        return;
    }
    q->mUnk_00 = p->mUnk_80;
    q->mUnk_10 = q->mUnk_00;
    q->mUnk_0e = p->mUnk_236;
    q->mUnk_0c = q->mUnk_0e;
    q->mUnk_1c = 0;
    q->mUnk_20 = 0;
    q->mUnk_24 = 0;
    q->mUnk_28 = 0;
    q->mUnk_30 = 0;
    q->mUnk_2c = q->mUnk_30;
    v = data_02154f94;
    q->mUnk_34 = v;
    q->mUnk_44 = 0;
    q->mUnk_48 = 0;
    q->mUnk_40 = 0;
    q->mUnk_5c = 0;
    q->mUnk_60 = 0;
    q->mUnk_64 = 0;
    q->mUnk_98 = v;
    q->mUnk_a8 = v;
    q->mUnk_b4 = 0;
    ListInit(&q->mUnk_80, 0);
    ListInit(&q->mUnk_8c, 0);
    b = HeapAlloc(a, 0x438);
    for (i = 0; i < 0x1e; i++) {
        ListAppend(&q->mUnk_8c, b + i * 0x24);
    }
}

void func_02071f44(Unk0206bcb0 *p) {
    Unk0206bcb0_514 *q;

    if (!(p->mUnk_7c & 0x400)) {
        return;
    }
    q = p->mUnk_514;
    q->mUnk_00 = p->mUnk_80;
    q->mUnk_10 = q->mUnk_00;
    q->mUnk_4c = *(Vec4 *) &p->mUnk_108.z;
    q->mUnk_a8 = data_02154f94;
    q->mUnk_b4 = 0;
}

void func_02071e28(Unk0206bcb0 *p) {
    p->mUnk_7c = 0;
    if (p->mIndex == data_021759c0->mUnk_62) {
        p->mUnk_7c |= 1;
        if (data_021759c0->mUnk_08 == 5) {
            p->mUnk_7c |= 0x200;
            if (func_0203c5e4() != 0) {
                p->mUnk_7c &= ~0x200;
                p->mUnk_7c |= 0x400;
            }
        }
    } else if (data_021759c0->mUnk_08 == 5) {
        p->mUnk_7c |= 0x400;
    }
    if (data_021759c0->mUnk_68[p->mIndex].mUnk_08.mUnk_00 == 2) {
        p->mUnk_7c |= 4;
        p->mUnk_384 = 0;
    }
    if (p->mKartModelsEntry->mUnk_008 != NULL) {
        p->mUnk_7c |= 0x10;
    }
    if (data_021759c0->mUnk_08 == 1 || func_02062eb0() != 0) {
        p->mUnk_7c |= 0x8000000;
    }
}

void func_02071ddc(void *p0) {
    *(u16 *) ((u8 *) (u32) p0 + 0) = (u16) 0x0u;
    *(u16 *) ((u8 *) (u32) p0 + 2) = (u16) 0x0u;
    *(u16 *) ((u8 *) (u32) p0 + 4) = (u16) 0x0u;
    *(u16 *) ((u8 *) (u32) p0 + 6) = (u16) 0x0u;
    *(u16 *) ((u8 *) (u32) p0 + 8) = (u16) 0x0u;
    *(u16 *) ((u8 *) (u32) p0 + 10) = (u16) 0x0u;
    *(u16 *) ((u8 *) (u32) p0 + 12) = (u16) 0x0u;
    *(u16 *) ((u8 *) (u32) p0 + 14) = (u16) 0x0u;
    *(u16 *) ((u8 *) (u32) p0 + 18) = (u16) 0x0u;
    *(u16 *) ((u8 *) (u32) p0 + 20) = (u16) 0x0u;
    *(u16 *) ((u8 *) (u32) p0 + 22) = (u16) 0x0u;
    *(u16 *) ((u8 *) (u32) p0 + 24) = (u16) 0x0u;
    *(u16 *) ((u8 *) (u32) p0 + 28) = (u16) 0x0u;
    *(u16 *) ((u8 *) (u32) p0 + 30) = (u16) 0x0u;
    *(u16 *) ((u8 *) (u32) p0 + 32) = (u16) 0x0u;
    *(u32 *) ((u8 *) (u32) p0 + 36) = (u32) 0x0u;
    *(u16 *) ((u8 *) (u32) p0 + 40) = (u16) 0x0u;
}
