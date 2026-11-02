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

u32 func_ov000_02186a38(Unk021868d0 *a, Unk02186998 *b, int c) {
    if (c == 0) {
        return 0;
    }
    b->mUnk_00 = a->mUnk_014(data_ov000_021b1280, c);
    if (b->mUnk_00 == NULL) {
        return 0;
    }
    b->mUnk_04 = b->mUnk_00;
    b->mUnk_0c = c;
    b->mUnk_08 = b->mUnk_00 + b->mUnk_0c;
    return 1;
}

void func_ov000_02186a10(Unk021868d0 *a, Unk02186998 *b) {
    if (b->mUnk_00 != NULL) {
        a->mUnk_018(data_ov000_021b1280, b->mUnk_00, 0);
    }
    func_0214d168(b, 0, 0x10);
}

u32 func_ov000_02186998(Unk021868d0 *a, Unk02186998 *b, int c) {
    char *v1;
    if (c <= 0) {
        return 0;
    }
    v1 = a->mUnk_014(NULL, b->mUnk_0c + c);
    if (v1 == NULL) {
        return 0;
    }
    func_0214d1fc(b->mUnk_00, v1, b->mUnk_0c);
    a->mUnk_018(NULL, b->mUnk_00, 0);
    if (v1 == NULL) {
        return 0;
    }
    b->mUnk_04 = b->mUnk_04 + (v1 - b->mUnk_00);
    b->mUnk_0c = b->mUnk_0c + c;
    b->mUnk_00 = v1;
    b->mUnk_08 = v1 + b->mUnk_0c;
    return 1;
}

BOOL func_ov000_021868d0(Unk021868d0 *a, const u8 *b) {
    u8 *p;
    if (strlen(b) >= 0x80) {
        return FALSE;
    }
    strncpy(a->mUnk_028, b, 0x80);
    if (strlen(b) != strlen(a->mUnk_028)) {
        return FALSE;
    }
    p = (u8 *) strstr(a->mUnk_028, data_ov000_021b1268);
    if (p != NULL) {
        a->mUnk_0a8 = a->mUnk_028 + 7;
        a->mUnk_0b0 = 0;
    } else {
        p = (u8 *) strstr(a->mUnk_028, data_ov000_021b1270);
        if (p == NULL) {
            return FALSE;
        }
        a->mUnk_0a8 = p + 8;
        a->mUnk_0b0 = 1;
    }
    p = (u8 *) strstr(a->mUnk_0a8, data_ov000_021b127c);
    if (p == NULL) {
        a->mUnk_0ac = NULL;
    } else {
        *p = 0;
        a->mUnk_0ac = p + 1;
    }
    return TRUE;
}

BOOL func_ov000_021868a4(Unk021868a4 *list, void *first, void *second) {
    if (list->mCount > list->mCapacity) {
        return FALSE;
    }
    list->mEntries[list->mCount].mFirst = first;
    list->mEntries[list->mCount].mSecond = second;
    list->mCount++;
    return TRUE;
}

// differ only by that register choice
BOOL func_ov000_021866fc(Unk021868a4Entry *a, s32 b, s32 c, const u8 *d) {
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
    e = (u8 *) strstr(d, data_ov000_021b1230);
    if (e == NULL) {
        return FALSE;
    }
    f = e + 4 + strlen(e + 4);
    i = (s8 *) strstr(d, data_ov000_021b1238);
    if (i == NULL) {
        return FALSE;
    }
    k = i + 1;
    k[3] = 0;
    if (func_ov000_021868a4(&g, data_ov000_021b123c, k) != TRUE) {
        return FALSE;
    }
    if (c == 1 || strncmp((const u8 *) k, data_ov000_021b1248, 3) != 0) {
        if (func_ov000_021868a4(&g, data_ov000_021b124c, e + 4) != TRUE) {
            return FALSE;
        }
        return TRUE;
    }
    i = (s8 *) strstr((const u8 *) (k + 4), data_ov000_021b1258);
    if (i == NULL) {
        return FALSE;
    }
    h = i + 2;
    while (h[0] != 0xd && h[1] != 0xa) {
        i = (s8 *) strstr((const u8 *) h, data_ov000_021b125c);
        if (i == NULL) {
            break;
        }
        i[0] = i[1] = 0;
        j = (u8 *) (i + 2);
        i = (s8 *) strstr(j, data_ov000_021b1258);
        if (i == NULL) {
            break;
        }
        i[0] = i[1] = 0;
        if (func_ov000_021868a4(&g, h, j) != TRUE) {
            return FALSE;
        }
        h = (s8 *) (j + strlen(j) + 2);
    }
    j = e + 4;
    if (j < f) {
        do {
            i = (s8 *) strstr(j, data_ov000_021b1260);
            if (i == NULL) {
                break;
            }
            i[0] = 0;
            h = i + 1;
            i = (s8 *) strstr((const u8 *) h, data_ov000_021b1264);
            if (i == NULL) {
                i = (s8 *) strstr((const u8 *) h, data_ov000_021b1258);
            }
            if (i != NULL) {
                i[0] = 0;
            }
            if (func_ov000_021868a4(&g, j, h) != TRUE) {
                return FALSE;
            }
            j = (u8 *) h + strlen((const u8 *) h) + 1;
        } while (j < f);
    }
    return TRUE;
}

void *func_ov000_021866b8(Unk021868a4Entry *a, s32 b, const u8 *c) {
    s32 e;
    for (e = 0; e < b; e++) {
        if (a[e].mFirst == NULL) {
            break;
        }
        if (strcmp(c, a[e].mFirst) == 0) {
            return a[e].mSecond;
        }
    }
    return NULL;
}

s32 func_ov000_02186674(Unk021868a4Entry *a, s32 b, const u8 *c, char *d, s32 e) {
    const u8 *f = func_ov000_021866b8(a, b, c);
    u32 g;
    if (f == NULL) {
        return 0;
    }
    g = func_ov000_021881d0((const s8 *) f, strlen(f), (u8 *) d, e);
    if (g != -1 && g < e) {
        d[g] = 0;
    }
    return g;
}

BOOL func_ov000_02186634(Unk021868a4Entry *a, s32 b, const u8 *c, char *d, s32 e) {
    const u8 *f = func_ov000_021866b8(a, b, c);
    if (f == NULL) {
        return FALSE;
    }
    if ((s32) strlen(f) >= e) {
        return FALSE;
    }
    strcpy(d, f);
    return TRUE;
}

void func_ov000_02186628(const void *a) {
    *(const void **) &data_ov000_021b1040 = a;
    return;
}
