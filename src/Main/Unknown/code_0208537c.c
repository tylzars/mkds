#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_0203c5ac.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"

void func_020858ac(u32 a) {
    Unk021759c0 *p;
    BOOL f;
    s16 j;
    p = data_021759c0;
    f = FALSE;
    if ((u32) p->mUnk_68[a].mUnk_08.mUnk_00 <= 3 && ((1 << p->mUnk_68[a].mUnk_08.mUnk_00) & 0xd)) {
        f = TRUE;
    }
    if (f == FALSE) {
        return;
    }
    if (p->mUnk_58 != 0) {
        for (j = 0; j < 2; j++) {
            if (j == p->mUnk_68[a].mUnk_08.mUnk_04) {
                if (data_0217aebc->mUnk_13e[j] > 0) {
                    data_0217aebc->mUnk_13e[j]--;
                }
                break;
            }
        }
    } else {
        if (data_0217aebc->mUnk_13c > 0) {
            data_0217aebc->mUnk_13c--;
        }
    }
}

s16 func_02085824(u32 a) {
    s16 r;
    u16 j;
    r = 0;
    if (data_021759c0->mUnk_58 != 0) {
        for (j = 0; (u32) j < 2; j++) {
            if (j != data_021759c0->mUnk_68[a].mUnk_08.mUnk_04) {
                r = r + data_0217aebc->mUnk_13e[j];
            }
        }
    } else {
        r = data_0217aebc->mUnk_13c;
    }
    return r;
}

void func_02085778(void) {
    u32 m;
    u16 i;
    u32 v;
    if (data_0217aec0 == NULL) {
        return;
    }
    func_0208552c();
    m = 1;
    for (i = 0; (u32) i < data_021759c0->mUnk_3d0; i++) {
        v = func_0203c8dc(i);
        if (data_021759c0->mUnk_68[i].mUnk_08.mUnk_00 != 1) {
            if (v == 1) {
                data_0217aebc->mUnk_088 = i;
            }
            if (v >= m) {
                m = v;
                data_0217aebc->mUnk_084 = i;
            }
        }
    }
}

void func_0208552c(void) {
    s32 m;
    u16 i;
    s32 v;
    s32 w;
    s32 n;
    s32 k;
    s32 x;
    s32 y;
    u16 q;
    BOOL f;
    m = 1;
    for (i = 0; (u32) i < data_021759c0->mUnk_3d0; i++) {
        w = gCourseMap->mUnk_108;
        x = func_0203c5c8(i);
        w = ((s64) x * w + 0x800) >> 12;
        v = func_0203c8dc(i);
        data_0217aebc->mUnk_000[i] = w;
        if (v > 0) {
            q = v - 1;
            if (data_021759c0->mUnk_68[i].mUnk_08.mUnk_00 == 1) {
                if (v > m) {
                    m = v;
                    data_0217aebc->mUnk_080 = i;
                }
            }
            data_0217aebc->mUnk_020[q] = i;
        }
        if (v == 1) {
            if (w >= 0) {
                data_0217aebc->mUnk_08c = func_02147f34(data_0217aebc->mUnk_000[i], 0x4ce);
                if (data_0217aebc->mUnk_08c < 0x19a) {
                    data_0217aebc->mUnk_08c = 0x19a;
                } else if (data_0217aebc->mUnk_08c > 0x1000) {
                    data_0217aebc->mUnk_08c = 0x1000;
                }
            } else {
                data_0217aebc->mUnk_08c = 0;
            }
        }
    }
    n = 0;
    for (k = 0; k < data_021759c0->mUnk_3d0; k++) {
        x = data_0217aebc->mUnk_020[k];
        if (x >= 0) {
            q = x;
            if (data_021759c0->mUnk_68[q].mUnk_08.mUnk_00 == 1) {
                data_0217aebc->mUnk_040[n] = x;
                n++;
            }
        }
    }
    if (data_0217aebc->mUnk_120 == 0) {
        return;
    }
    n = 0;
    for (k = 0; k < data_021759c0->mUnk_3d0; k++) {
        y = data_0217aebc->mUnk_020[k];
        if (y >= 0) {
            q = y;
            f = FALSE;
            if ((u32) data_021759c0->mUnk_68[q].mUnk_08.mUnk_00 <= 3 &&
                ((1 << data_021759c0->mUnk_68[q].mUnk_08.mUnk_00) & 0xd)) {
                f = TRUE;
            }
            if (f != FALSE) {
                data_0217aebc->mUnk_060[n] = y;
                n++;
            }
        }
    }
}

s32 func_020854c0(u16 a) {
    s32 r;
    u16 i;
    r = -1;
    for (i = 0; (u32) i < data_021759c0->mUnk_3d0; i++) {
        if (a == (u16) data_0217aebc->mUnk_040[i]) {
            r = i + 1;
            break;
        }
    }
    return r;
}

s32 func_020854a0(u32 p0, u32 p1) {
    return ((u32) data_0217aebc->mUnk_040[(((p1) + (p0))) - (0x1u)]);
}

s32 func_0208548c(void) {
    return ((u32) data_0217aebc->mUnk_08c);
}

s32 func_02085478(void) {
    return ((u32) data_0217aebc->mUnk_040[0]);
}

s32 func_02085458(s32 a) {
    s32 i = a - 2;
    s32 r = -1;

    if (i >= 0) {
        r = data_0217aebc->mUnk_040[i];
    }
    return r;
}

s32 func_02085434(void) {
    return ((u32) data_0217aebc->mUnk_060[(((u32) data_0217aebc->mUnk_124)) - (0x1u)]);
}

Unk0217aec0 *func_02085424(void) {
    return data_0217aec0;
}

s32 func_02085408(u32 p0) {
    return ((u32) data_0217aebc->mUnk_020[(p0) - (0x1u)]);
}

u32 func_020853f0(u32 p0) {
    return ((u32) data_0217aebc->mUnk_090[p0]);
}

u32 func_020853dc(void) {
    return ((u32) data_0217aebc->mUnk_138);
}

s32 func_020853a4(u32 a) {
    s32 m;
    s32 v;
    m = gCourseMap->mUnk_108;
    v = func_0203c5c8(a);
    return ((s64) v * m + 0x800) >> 12;
}

u32 func_02085390(void) {
    return ((u32) data_0217aebc->mUnk_120);
}

Unk0217aebc_128 *func_0208537c(void) {
    return data_0217aebc->mUnk_128;
}
