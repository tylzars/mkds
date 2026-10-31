#include "Main/Unknown/code_0203003c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02163000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0202f764.h"
#include "Main/Unknown/code_0203038c.h"
#include "Main/Unknown/code_0203033c.h"

#pragma thumb on

// non-matching: 81%, the original keeps the table pointer and the zero constants in stack words and loads the first entry values in another order; size 4 bytes over
void func_0203003c(s32 a) {
    Unk02174e50_24 *p;
    Unk02153c58 *q;
    u32 t[2];
    s32 i;
    s32 j;
    s32 k;
    s32 r4;
    s32 v;
    s32 w;
    s32 x;
    s32 y;
    s32 z;

    p = &data_02174e50->mUnk_24;
    t[0] = data_021634a8[0];
    t[1] = data_021634a8[1];
    r4 = 0;
    i = 0;
    q = data_02153c58;
    do {
        v = 0;
        if (data_02174e50->mUnk_48 == i && a != 0) {
            v = 1;
        }
        x = *(s32 *) ((u8 *) data_02174e50 + r4 + 0x58);
        p->mUnk_18[q->mUnk_00[0]].mUnk_00 = v;
        if (v == 0) {
            w = 1;
        } else {
            w = 0;
        }
        p->mUnk_18[q->mUnk_00[0x18 / 2]].mUnk_00 = w;
        for (j = 1; j < 12; j++) {
            p->mUnk_18[q->mUnk_00[j]].mUnk_00 = v & x;
            *(s32 *) ((u8 *) p->mUnk_18 + (q->mUnk_00[j + 12] << 6)) = w & x;
        }
        p->mUnk_18[q->mUnk_00[1]].mUnk_00 &= *(s32 *) ((u8 *) data_02174e50 + r4 + 0x5c);
        p->mUnk_18[q->mUnk_00[13]].mUnk_00 &= *(s32 *) ((u8 *) data_02174e50 + r4 + 0x5c);
        if (*(s32 *) ((u8 *) data_02174e50 + r4 + 0x5c) == 0) {
            y = 1;
        } else {
            y = 0;
        }
        p->mUnk_18[q->mUnk_00[2]].mUnk_00 &= y;
        if (*(s32 *) ((u8 *) data_02174e50 + r4 + 0x5c) == 0) {
            y = 1;
        } else {
            y = 0;
        }
        p->mUnk_18[q->mUnk_00[14]].mUnk_00 &= y;
        for (k = 0; k < 8; k++) {
            if (k == *(s32 *) ((u8 *) data_02174e50 + r4 + 0x60)) {
                z = 1;
            } else {
                z = 0;
            }
            *(s32 *) ((u8 *) p->mUnk_18 + (q->mUnk_00[4 + k] << 6)) &= z;
            *(s32 *) ((u8 *) p->mUnk_18 + (q->mUnk_00[16 + k] << 6)) &= z;
        }
        func_02124100(q->mUnk_30, (u8) t[v], p->mUnk_14, p->mUnk_18, p->mUnk_0c);
        r4 += 0xc;
        q = (Unk02153c58 *) ((u8 *) q + 0x32);
        i++;
    } while (i < 4);
    if (data_02174e50->mUnk_48 == i && a != 0) {
        v = 1;
    } else {
        v = 0;
    }
    p->mUnk_18[89].mUnk_00 = v;
    if (v == 0) {
        w = 1;
    } else {
        w = 0;
    }
    p->mUnk_18[88].mUnk_00 = w;
    func_02124100(4, (u8) t[v], p->mUnk_14, p->mUnk_18, p->mUnk_0c);
}

void func_02030200(void) {
    s32 i;
    s32 n;
    Unk02174e50_24 *p;

    p = &data_02174e50->mUnk_24;
    n = *(u16 *) ((u8 *) p->mUnk_0c + 6) + *(u16 *) ((u8 *) p->mUnk_14 + 6);
    for (i = 0; i < n; i++) {
        p->mUnk_18[i].mUnk_06 = data_02174e50->mUnk_90;
    }
}

s32 func_0203023c(void) {
    s32 r;
    s32 i;
    s32 f;

    r = 1;
    i = data_02174e50->mUnk_48;
    if (i != 4) {
        f = 0;
        if (data_02174e50->mUnk_58[i].mUnk_00 != 0 && data_02174e50->mUnk_58[i].mUnk_08 < 7) {
            f = 1;
        }
        if (f == 0) {
            r = 0;
        }
    }
    return r;
}

s32 func_02030274(s32 a, s32 b) {
    s32 i;
    s32 f;

    f = 0;
    for (i = 0; i < 3; i++) {
        if (a == data_02153c04[b][i]) {
            f = 1;
            break;
        }
    }
    return f;
}

// non-matching: the then-arm ends with `b` to the shared epilogue in the original; here it gets its own copy of the epilogue (add sp, pop, bx; 4 bytes over), all other instructions match
void func_020302a0(void) {
    Unk02174e54 *o;

    func_020303a8(0x16);
    o = data_02174e54;
    if (o->mUnk_38 != 0) {
        func_0203038c(1);
        func_02030364(0x1f, 1);
        func_0203033c(7, 1);
        func_020302f0(0, 0, 0xff, data_02174e54->mUnk_38 + 0xc0);
    } else {
        func_0203038c(0);
    }
}

#pragma thumb off

void func_020302f0(u32 a, u32 b, u32 c, u32 d) {
    *(u16 *) 0x4001040 = ((a << 8) & 0xff00) | (c & 0xff);
    *(u16 *) 0x4001044 = ((b << 8) & 0xff00) | (d & 0xff);
}
