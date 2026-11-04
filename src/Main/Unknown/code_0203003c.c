#include "Main/Unknown/code_0203003c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02163000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0202f764.h"
#include "Main/Unknown/code_0203033c.h"

#pragma thumb on

void func_0203003c(s32 a) {
    Unk02174e50_24 *p;
    Unk021634a8 t;
    s32 i;
    s32 j;
    s32 r4;
    s32 v;
    s32 w;
    s32 x;
    BOOL y;
    BOOL z;
    Unk02153c58 *q;

    p = &data_02174e50->mUnk_24;
    t = data_021634a8;
    i = 0;
    r4 = 0;
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
            p->mUnk_18[(q->mUnk_00 + 12)[j]].mUnk_00 = w & x;
        }
        p->mUnk_18[q->mUnk_00[1]].mUnk_00 &= *(s32 *) ((u8 *) data_02174e50 + r4 + 0x5c);
        p->mUnk_18[q->mUnk_00[13]].mUnk_00 &= *(s32 *) ((u8 *) data_02174e50 + r4 + 0x5c);
        if (*(s32 *) ((u8 *) data_02174e50 + r4 + 0x5c) == 0) {
            y = TRUE;
        } else {
            y = FALSE;
        }
        p->mUnk_18[q->mUnk_00[2]].mUnk_00 &= y;
        if (*(s32 *) ((u8 *) data_02174e50 + r4 + 0x5c) == 0) {
            y = TRUE;
        } else {
            y = FALSE;
        }
        p->mUnk_18[q->mUnk_00[14]].mUnk_00 &= y;
        for (j = 0; j < 8; j++) {
            if (j == *(s32 *) (r4 + (s32) data_02174e50 + 0x60)) {
                z = TRUE;
            } else {
                z = FALSE;
            }
            p->mUnk_18[(q->mUnk_00 + 4)[j]].mUnk_00 &= z;
            p->mUnk_18[(q->mUnk_00 + 16)[j]].mUnk_00 &= z;
        }
        func_02124100(q->mUnk_30, (u8) t.mUnk_00[v], p->mUnk_14, p->mUnk_18, p->mUnk_0c);
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
    func_02124100(4, (u8) t.mUnk_00[v], p->mUnk_14, p->mUnk_18, p->mUnk_0c);
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
    BOOL r;
    s32 i;
    BOOL f;

    r = TRUE;
    i = data_02174e50->mUnk_48;
    if (i != 4) {
        f = FALSE;
        if (data_02174e50->mUnk_58[i].mUnk_00 != 0 && data_02174e50->mUnk_58[i].mUnk_08 < 7) {
            f = TRUE;
        }
        if (f == FALSE) {
            r = FALSE;
        }
    }
    return r;
}

s32 func_02030274(s32 a, s32 b) {
    s32 i;
    BOOL f;

    f = FALSE;
    for (i = 0; i < 3; i++) {
        if (a == data_02153c04[b][i]) {
            f = TRUE;
            break;
        }
    }
    return f;
}
