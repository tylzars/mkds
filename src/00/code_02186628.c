#include "00/code_02186628.h"
#include "00/unk_021b1000.h"
#include "00/code_02188008.h"
#include "03/code_021b94b8.h"

#include "code_0214d018.h"
#include "code_02139f70.h"

u32 func_ov000_02186a84(u32 value) {
    if (value & 0x8000) {
        value &= 0xffff7fff;
    }
    return value;
}

u32 func_ov000_02186a38(Unk021868d0 *param_1, Unk02186998 *param_2, int param_3) {
    if (param_3 == 0) {
        return 0;
    }
    param_2->mUnk_00 = param_1->mUnk_014(data_ov000_021b1280, param_3);
    if (param_2->mUnk_00 == 0) {
        return 0;
    }
    param_2->mUnk_04 = param_2->mUnk_00;
    param_2->mUnk_0c = param_3;
    param_2->mUnk_08 = param_2->mUnk_00 + param_2->mUnk_0c;
    return 1;
}

void func_ov000_02186a10(Unk021868d0 *a, Unk02186998 *b) {
    if (b->mUnk_00 != 0) {
        a->mUnk_018(data_ov000_021b1280, b->mUnk_00, 0);
    }
    func_0214d168(b, 0, 0x10);
}

u32 func_ov000_02186998(Unk021868d0 *param_1, Unk02186998 *param_2, int param_3) {
    char *v1;
    if (param_3 <= 0) {
        return 0;
    }
    v1 = param_1->mUnk_014(0, param_2->mUnk_0c + param_3);
    if (v1 == 0) {
        return 0;
    }
    func_0214d1fc(param_2->mUnk_00, v1, param_2->mUnk_0c);
    param_1->mUnk_018(0, param_2->mUnk_00, 0);
    if (v1 == 0) {
        return 0;
    }
    param_2->mUnk_04 = param_2->mUnk_04 + (v1 - param_2->mUnk_00);
    param_2->mUnk_0c = param_2->mUnk_0c + param_3;
    param_2->mUnk_00 = v1;
    param_2->mUnk_08 = v1 + param_2->mUnk_0c;
    return 1;
}

s32 func_ov000_021868d0(Unk021868d0 *a, const u8 *b) {
    u8 *p;
    if (func_0213a434(b) >= 0x80) {
        return 0;
    }
    func_0213a228(a->mUnk_028, b, 0x80);
    if (func_0213a434(b) != func_0213a434(a->mUnk_028)) {
        return 0;
    }
    p = (u8 *) func_02139f70(a->mUnk_028, data_ov000_021b1268);
    if (p != 0) {
        a->mUnk_0a8 = a->mUnk_028 + 7;
        a->mUnk_0b0 = 0;
    } else {
        p = (u8 *) func_02139f70(a->mUnk_028, data_ov000_021b1270);
        if (p == 0) {
            return 0;
        }
        a->mUnk_0a8 = p + 8;
        a->mUnk_0b0 = 1;
    }
    p = (u8 *) func_02139f70(a->mUnk_0a8, data_ov000_021b127c);
    if (p == 0) {
        a->mUnk_0ac = 0;
    } else {
        *p = 0;
        a->mUnk_0ac = p + 1;
    }
    return 1;
}

s32 func_ov000_021868a4(Unk021868a4 *list, void *first, void *second) {
    if (list->mCount > list->mCapacity) {
        return 0;
    }
    list->mEntries[list->mCount].mFirst = first;
    list->mEntries[list->mCount].mSecond = second;
    list->mCount++;
    return 1;
}

// differ only by that register choice
s32 func_ov000_021866fc(Unk021868a4Entry *a, s32 b, s32 c, const u8 *d) {
    u8 *e;
    u8 *f;
    Unk021868a4 g;
    s8 *k;
    s8 *h;
    u8 *j;
    s8 *i;
    g.mEntries = a;
    g.mCapacity = b;
    g.mCount = 0;
    func_0214d168(a, 0, b * 8);
    e = (u8 *) func_02139f70(d, data_ov000_021b1230);
    if (e == 0) {
        return 0;
    }
    f = e + 4 + func_0213a434(e + 4);
    i = (s8 *) func_02139f70(d, data_ov000_021b1238);
    if (i == 0) {
        return 0;
    }
    k = i + 1;
    k[3] = 0;
    if (func_ov000_021868a4(&g, data_ov000_021b123c, k) != 1) {
        return 0;
    }
    if (c == 1 || func_0213a038((const u8 *) k, data_ov000_021b1248, 3) != 0) {
        if (func_ov000_021868a4(&g, data_ov000_021b124c, e + 4) != 1) {
            return 0;
        }
        return 1;
    }
    i = (s8 *) func_02139f70((const u8 *) (k + 4), data_ov000_021b1258);
    if (i == 0) {
        return 0;
    }
    h = i + 2;
    while (h[0] != 0xd && h[1] != 0xa) {
        i = (s8 *) func_02139f70((const u8 *) h, data_ov000_021b125c);
        if (i == 0) {
            break;
        }
        i[0] = i[1] = 0;
        j = (u8 *) (i + 2);
        i = (s8 *) func_02139f70(j, data_ov000_021b1258);
        if (i == 0) {
            break;
        }
        i[0] = i[1] = 0;
        if (func_ov000_021868a4(&g, h, j) != 1) {
            return 0;
        }
        h = (s8 *) (j + func_0213a434(j) + 2);
    }
    j = e + 4;
    if (j < f) {
        do {
            i = (s8 *) func_02139f70(j, data_ov000_021b1260);
            if (i == 0) {
                break;
            }
            i[0] = 0;
            h = i + 1;
            i = (s8 *) func_02139f70((const u8 *) h, data_ov000_021b1264);
            if (i == 0) {
                i = (s8 *) func_02139f70((const u8 *) h, data_ov000_021b1258);
            }
            if (i != 0) {
                i[0] = 0;
            }
            if (func_ov000_021868a4(&g, j, h) != 1) {
                return 0;
            }
            j = (u8 *) h + func_0213a434((const u8 *) h) + 1;
        } while (j < f);
    }
    return 1;
}

void *func_ov000_021866b8(Unk021868a4Entry *a, s32 b, const u8 *c) {
    s32 e;
    for (e = 0; e < b; e++) {
        if (a[e].mFirst == 0) {
            break;
        }
        if (func_0213a074(c, a[e].mFirst) == 0) {
            return a[e].mSecond;
        }
    }
    return 0;
}

s32 func_ov000_02186674(Unk021868a4Entry *a, s32 b, const u8 *c, char *d, s32 e) {
    const u8 *f = func_ov000_021866b8(a, b, c);
    u32 g;
    if (f == 0) {
        return 0;
    }
    g = func_ov000_021881d0((const s8 *) f, func_0213a434(f), (u8 *) d, e);
    if (g != -1 && g < e) {
        d[g] = 0;
    }
    return g;
}

s32 func_ov000_02186634(Unk021868a4Entry *a, s32 b, const u8 *c, char *d, s32 e) {
    const u8 *f = func_ov000_021866b8(a, b, c);
    if (f == 0) {
        return 0;
    }
    if ((s32) func_0213a434(f) >= e) {
        return 0;
    }
    func_0213a2d0(d, f);
    return 1;
}

void func_ov000_02186628(const void *param_1) {
    *(const void **) &data_ov000_021b1040 = param_1;
    return;
}
