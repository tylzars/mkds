#include "Main/Unknown/code_02042410.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02042fd8.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma thumb on
s32 func_02042990(void *a, ...) {
    gCourseMap->mUnk_020 = func_020431a4(&a);
    gCourseMap->mUnk_01c = (s32) a;
    return 1;
}

s32 func_02042894(void *a, ...) {
    s32 i;
    s32 m;
    void *h;
    s32 n;
    s32 k;
    u16 t;
    Unk02175620_24 *p;

    h = func_020364e0(func_020364e8());
    gCourseMap->mUnk_028 = func_020431a4(&a);
    gCourseMap->mUnk_024 = a;
    if (data_021759c0->mUnk_08 == 2) {
        n = gCourseMap->mUnk_028;
        gCourseMap->mUnk_f8 = func_02036bec(h, n * 2);
        gCourseMap->mUnk_100 = 0;
        for (i = 0; i < n; i++) {
            gCourseMap->mUnk_f8[i] = i;
        }
    } else if (gCourseMap->mUnk_028 != 0) {
        m = 0;
        for (k = 0; k < gCourseMap->mUnk_028; k++) {
            p = &gCourseMap->mUnk_024[k];
            if (p->mUnk_1c > m) {
                m = p->mUnk_1c;
            }
        }
        gCourseMap->mUnk_f8 = func_02036bec(h, (m + 1) * 2);
        for (i = 0; i < m + 1; i++) {
            gCourseMap->mUnk_f8[i] = 0xffff;
        }
        for (i = 0; i < gCourseMap->mUnk_028; i++) {
            gCourseMap->mUnk_f8[gCourseMap->mUnk_024[i].mUnk_1c] = i;
        }
    }
    return 1;
}

static inline u16 func_020427d4_inline(Unk020f41c4_B *p, u16 n) {
    u32 t;
    if (n == 0) {
        t = 0;
    } else {
        p->mUnk_00 = (s64) p->mUnk_08 * (s64) p->mUnk_00 + p->mUnk_10;
        if (n == 0) {
            t = p->mUnk_00 >> 32;
        } else {
            t = ((s64) (p->mUnk_00 >> 32) * (u32) n) >> 32;
        }
    }
    return t;
}

void func_020427d4(Unk020f41c4_B *a) {
    s32 i;
    u16 n;
    u16 x;
    u16 y;
    u16 t;

    n = gCourseMap->mUnk_028;
    for (i = 0; i < 100; i++) {
        x = func_020427d4_inline(a, n);
        y = func_020427d4_inline(a, n);
        t = gCourseMap->mUnk_f8[y];
        gCourseMap->mUnk_f8[y] = gCourseMap->mUnk_f8[x];
        gCourseMap->mUnk_f8[x] = t;
    }
}

s32 func_020427ac(void *a, ...) {
    gCourseMap->mUnk_30 = func_020431a4(&a);
    gCourseMap->mUnk_2c = a;
    return 1;
}

void func_0204274c(void) {
    u16 n;
    u16 i;

    n = gCourseMap->mUnk_38;
    if (n == 0) {
        gCourseMap->mUnk_fc = NULL;
        return;
    }
    gCourseMap->mUnk_fc = func_02036bec(func_020364e0(func_020364e8()), n * 2);
    for (i = 0; i < n; i++) {
        gCourseMap->mUnk_fc[gCourseMap->mUnk_34[i].mUnk_1a] = i;
    }
}

s32 func_02042708(void *a, ...) {
    BOOL r = FALSE;

    if (gCourseMap->mUnk_10c < 0x1f) {
        gCourseMap->mUnk_38 = 0;
        gCourseMap->mUnk_34 = NULL;
    } else {
        gCourseMap->mUnk_38 = func_020431a4(&a);
        gCourseMap->mUnk_34 = a;
        r = TRUE;
    }
    func_0204274c();
    return r;
}

s32 func_020426ac(void *a, ...) {
    enum { K0 } r = 0;

    if (gCourseMap->mUnk_10c < 0x24) {
        gCourseMap->mUnk_40 = r;
        gCourseMap->mUnk_3c = NULL;
        return r;
    }
    gCourseMap->mUnk_40 = func_020431a4(&a);
    if (gCourseMap->mUnk_40 != 0) {
        gCourseMap->mUnk_3c = a;
    } else {
        gCourseMap->mUnk_3c = NULL;
    }
    return 1;
}

s32 func_02042628(void *a, ...) {
    u16 i;
    u16 j;

    gCourseMap->mUnk_48 = func_020431a4(&a);
    if (gCourseMap->mUnk_48 == 0) {
        gCourseMap->mUnk_44 = NULL;
        return 1;
    }
    gCourseMap->mUnk_44 = a;
    j = 0;
    for (i = 0; i < gCourseMap->mUnk_48; i++) {
        if (gCourseMap->mUnk_44[i].mUnk_20 != -1) {
            j++;
        }
    }
    gCourseMap->mUnk_98 = j;
    return 1;
}

s32 func_02042590(void *a, ...) {
    s32 i;
    Unk02175620_4c *t;
    Unk02175620_4c *e;
    s32 m;

    gCourseMap->mUnk_50 = func_020431a4(&a);
    if (gCourseMap->mUnk_50 == 0) {
        gCourseMap->mUnk_4c = NULL;
        gCourseMap->mUnk_9a = 0;
        return 1;
    }
    gCourseMap->mUnk_4c = a;
    for (i = 0; i < gCourseMap->mUnk_50; i++) {
        if (gCourseMap->mUnk_4c[(u16) i].mUnk_00 == 0) {
            t = gCourseMap->mUnk_4c;
            e = &t[(u16) (s8) t[(u16) i].mUnk_07];
            m = t[(u16) (s8) t[(u16) i].mUnk_07].mUnk_00;
            gCourseMap->mUnk_9a = m + e->mUnk_02 - 1;
            break;
        }
    }
    return 1;
}

s32 func_02042558(void *a, ...) {
    gCourseMap->mUnk_58 = func_020431a4(&a);
    if (gCourseMap->mUnk_58 == 0) {
        gCourseMap->mUnk_54 = NULL;
    } else {
        gCourseMap->mUnk_54 = a;
    }
    return 1;
}

s32 func_02042520(void *a, ...) {
    gCourseMap->mUnk_60 = func_020431a4(&a);
    if (gCourseMap->mUnk_60 == 0) {
        gCourseMap->mUnk_5c = NULL;
    } else {
        gCourseMap->mUnk_5c = a;
    }
    return 1;
}

s32 func_02042498(void *a, ...) {
    if (gCourseMap->mUnk_020 > 1) {
        gCourseMap->mUnk_88 = func_020431a4(&a);
        if (gCourseMap->mUnk_88 == 0) {
            gCourseMap->mUnk_84 = NULL;
        } else {
            gCourseMap->mUnk_84 = a;
            gCourseMap->mUnk_64 = NULL;
            gCourseMap->mUnk_68 = 0;
        }
    } else {
        gCourseMap->mUnk_68 = func_020431a4(&a);
        if (gCourseMap->mUnk_68 == 0) {
            gCourseMap->mUnk_64 = NULL;
        } else {
            gCourseMap->mUnk_64 = a;
            gCourseMap->mUnk_84 = NULL;
            gCourseMap->mUnk_88 = 0;
        }
    }
    return 1;
}

s32 func_02042410(void *a, ...) {
    if (gCourseMap->mUnk_020 > 1) {
        gCourseMap->mUnk_90 = func_020431a4(&a);
        if (gCourseMap->mUnk_90 == 0) {
            gCourseMap->mUnk_8c = NULL;
        } else {
            gCourseMap->mUnk_8c = a;
            gCourseMap->mUnk_6c = NULL;
            gCourseMap->mUnk_70 = 0;
        }
    } else {
        gCourseMap->mUnk_70 = func_020431a4(&a);
        if (gCourseMap->mUnk_70 == 0) {
            gCourseMap->mUnk_6c = NULL;
        } else {
            gCourseMap->mUnk_6c = a;
            gCourseMap->mUnk_8c = NULL;
            gCourseMap->mUnk_90 = 0;
        }
    }
    return 1;
}
#pragma thumb off
