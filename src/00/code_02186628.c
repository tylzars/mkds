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

u32 InitHttpBuffer(Http *a, HttpBuffer *b, int c) {
    if (c == 0) {
        return 0;
    }
    b->mStart = a->mAllocate(data_ov000_021b1280, c);
    if (b->mStart == NULL) {
        return 0;
    }
    b->mCursor = b->mStart;
    b->mSize = c;
    b->mEnd = b->mStart + b->mSize;
    return 1;
}

void FreeHttpBuffer(Http *a, HttpBuffer *b) {
    if (b->mStart != NULL) {
        a->mFree(data_ov000_021b1280, b->mStart, 0);
    }
    MemFill(b, 0, 0x10);
}

u32 GrowHttpBuffer(Http *a, HttpBuffer *b, int c) {
    char *v1;
    if (c <= 0) {
        return 0;
    }
    v1 = a->mAllocate(NULL, b->mSize + c);
    if (v1 == NULL) {
        return 0;
    }
    MemCopy(b->mStart, v1, b->mSize);
    a->mFree(NULL, b->mStart, 0);
    if (v1 == NULL) {
        return 0;
    }
    b->mCursor = b->mCursor + (v1 - b->mStart);
    b->mSize = b->mSize + c;
    b->mStart = v1;
    b->mEnd = v1 + b->mSize;
    return 1;
}

BOOL func_ov000_021868d0(Http *a, const char *b) {
    char *p;
    if (strlen(b) >= 0x80) {
        return FALSE;
    }
    strncpy(a->mUnk_028, b, 0x80);
    if (strlen(b) != strlen(a->mUnk_028)) {
        return FALSE;
    }
    p = strstr(a->mUnk_028, data_ov000_021b1268);
    if (p != NULL) {
        a->mHost = a->mUnk_028 + 7;
        a->mUseHttps = 0;
    } else {
        p = strstr(a->mUnk_028, data_ov000_021b1270);
        if (p == NULL) {
            return FALSE;
        }
        a->mHost = p + 8;
        a->mUseHttps = 1;
    }
    p = strstr(a->mHost, data_ov000_021b127c);
    if (p == NULL) {
        a->mPath = NULL;
    } else {
        *p = 0;
        a->mPath = p + 1;
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
BOOL func_ov000_021866fc(Unk021868a4Entry *a, s32 b, s32 c, const char *d) {
    char *e;
    char *f;
    Unk021868a4 g;
    s8 *k;
    s8 *h;
    char *j;
    s8 *i;
    g.mEntries = a;
    g.mCapacity = b;
    g.mCount = 0;
    MemFill(a, 0, b * 8);
    e = strstr(d, data_ov000_021b1230);
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
    if (c == 1 || strncmp((const char *) k, data_ov000_021b1248, 3) != 0) {
        if (func_ov000_021868a4(&g, data_ov000_021b124c, e + 4) != TRUE) {
            return FALSE;
        }
        return TRUE;
    }
    i = (s8 *) strstr((const char *) (k + 4), data_ov000_021b1258);
    if (i == NULL) {
        return FALSE;
    }
    h = i + 2;
    while (h[0] != 0xd && h[1] != 0xa) {
        i = (s8 *) strstr((const char *) h, data_ov000_021b125c);
        if (i == NULL) {
            break;
        }
        i[0] = i[1] = 0;
        j = (char *) (i + 2);
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
            i = (s8 *) strstr((const char *) h, data_ov000_021b1264);
            if (i == NULL) {
                i = (s8 *) strstr((const char *) h, data_ov000_021b1258);
            }
            if (i != NULL) {
                i[0] = 0;
            }
            if (func_ov000_021868a4(&g, j, h) != TRUE) {
                return FALSE;
            }
            j = (char *) h + strlen((const char *) h) + 1;
        } while (j < f);
    }
    return TRUE;
}

void *func_ov000_021866b8(Unk021868a4Entry *a, s32 b, const char *c) {
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

s32 func_ov000_02186674(Unk021868a4Entry *a, s32 b, const char *c, char *d, s32 e) {
    const char *f = func_ov000_021866b8(a, b, c);
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

BOOL func_ov000_02186634(Unk021868a4Entry *a, s32 b, const char *c, char *d, s32 e) {
    const char *f = func_ov000_021866b8(a, b, c);
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
