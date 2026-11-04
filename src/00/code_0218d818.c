#include "00/code_0218d818.h"

#include "code_02133048.h"
#include "string.h"
#include "code_02134398.h"
#include "00/unk_021b2000.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "Main/Unknown/code_02133000.h"
#include "code_021382a8.h"
#include "00/code_021a3668.h"

void DarrayCallElemCallback(void *b, s32 c) {
    Darray *a = b;
    if (a->mElemCallback != NULL) {
        a->mElemCallback(DarrayGetElement(a, c));
    }
}

void DarrayGrow(Darray *a) {
    a->mCapacity = a->mCapacity + a->mGrowCount;
    a->mList = func_ov000_021a3678(a->mList, a->mCapacity * a->mElemSize);
    if (a->mList == NULL) {
        AssertionFailed(data_ov000_021b2348, data_ov000_021b22dc, NULL, 0x41);
    }
}

void DarraySetElement(Darray *a, const void *b, s32 c) {
    memcpy(DarrayGetElement(a, c), b, a->mElemSize);
}

void *DarrayCreate(s32 elemSize, s32 c, void (*d)(void *)) {
    Darray *array = func_ov000_021a3690(0x18);
    if (array == NULL) {
        AssertionFailed(data_ov000_021b2334, data_ov000_021b22dc, NULL, 0x52);
    }
    if (elemSize == 0) {
        AssertionFailed(data_ov000_021b233c, data_ov000_021b22dc, NULL, 0x53);
    }
    if (c == 0) {
        c = 8;
    }
    array->mCount = 0;
    array->mCapacity = c;
    array->mElemSize = elemSize;
    array->mGrowCount = c;
    array->mElemCallback = d;
    if (array->mCapacity != 0) {
        array->mList = func_ov000_021a3690(array->mCapacity * array->mElemSize);
        if (array->mList == NULL) {
            AssertionFailed(data_ov000_021b2348, data_ov000_021b22dc, NULL, 0x5e);
        }
    } else {
        array->mList = NULL;
    }
    return array;
}

void DarrayDelete(void *c) {
    Darray *array = c;
    s32 b;
    if (array == NULL) {
        AssertionFailed(data_ov000_021b2334, data_ov000_021b22dc, NULL, 0x69);
    }
    b = 0;
    if (0 < array->mCount) {
        do {
            DarrayCallElemCallback(array, b);
            b = b + 1;
        } while (b < array->mCount);
    }
    func_ov000_021a3668(array->mList);
    func_ov000_021a3668(array);
    return;
}

s32 DarrayGetCount(void *b) {
    Darray *a = b;
    return a->mCount;
}

void *DarrayGetElement(void *param_1, s32 n) {
    Darray *array = param_1;
    if (n < 0 || n >= array->mCount) {
        AssertionFailed(data_ov000_021b22e8, data_ov000_021b22dc, NULL, 0x94);
    }
    if (n < 0 || n >= array->mCount) {
        return NULL;
    }
    return array->mList + array->mElemSize * n;
}

void DarrayAppend(void *param_1, void *param_2) {
    Darray *array = param_1;
    if (array == NULL) {
        AssertionFailed(data_ov000_021b2334, data_ov000_021b22dc, NULL, 0xa0);
    }
    if (array != NULL) {
        DarrayInsert(array, param_2, array->mCount);
    }
}

void DarrayInsert(void *param_1, void *param_2, s32 n) {
    Darray *array = param_1;
    s32 b;
    if (n < 0 || n > array->mCount) {
        AssertionFailed(data_ov000_021b2314, data_ov000_021b22dc, NULL, 0xa7);
    }
    if (array->mCount == array->mCapacity) {
        DarrayGrow(array);
    }
    array->mCount = array->mCount + 1;
    b = array->mCount - 1;
    if (n < b) {
        memmove(DarrayGetElement(array, n + 1), DarrayGetElement(array, n), array->mElemSize * (b - n));
    }
    DarraySetElement(array, param_2, n);
}

void DarrayInsertSorted(Darray *array, void *b, UnkCompare *comparator) {
    u8 *v1;
    u32 v2;
    s32 v3[2];
    if (comparator == NULL) {
        AssertionFailed(data_ov000_021b2308, data_ov000_021b22dc, NULL, 0xb7);
    }
    v1 = DarraySearchSorted(b, array->mList, array->mCount, array->mElemSize, comparator, v3);
    v2 = _s32_div_f(v1 - array->mList, array->mElemSize);
    DarrayInsert(array, b, v2);
    return;
}

void DarrayRemoveWithoutCallback(Darray *array, int n) {
    s32 v1;
    if (n < 0 || n >= array->mCount) {
        AssertionFailed(data_ov000_021b22e8, data_ov000_021b22dc, NULL, 0xc0);
    }
    v1 = array->mCount - 1;
    if (n < v1) {
        memmove(DarrayGetElement(array, n), DarrayGetElement(array, n + 1), array->mElemSize * (v1 - n));
    }
    array->mCount = array->mCount - 1;
}

void DarrayRemove(Darray *array, s32 n) {
    if ((n < 0) || (n >= array->mCount)) {
        AssertionFailed(data_ov000_021b22e8, data_ov000_021b22dc, NULL, 0xca);
    }
    DarrayCallElemCallback(array, n);
    DarrayRemoveWithoutCallback(array, n);
}

void DarrayReplace(Darray *array, const void *b, s32 n) {
    if ((n < 0) || (n >= array->mCount)) {
        AssertionFailed(data_ov000_021b22e8, data_ov000_021b22dc, NULL, 0xd3);
    }
    DarrayCallElemCallback(array, n);
    DarraySetElement(array, b, n);
}

void DarraySort(u32 p0, u32 p1) {
    u32 v2 = ((p0) + (0x0u));
    u32 v3 = ((p1) + (0x0u));
    u32 v4 = ((u32) * (u32 *) ((v2) + (20)));
    u32 v5 = ((u32) * (u32 *) ((v2) + (0)));
    u32 v6 = ((u32) * (u32 *) ((v2) + (8)));
    qsort((u8 *) v4, v5, v6, (int (*)(void *, void *))(v3));
}

s32 DarrayFindIndex(Darray *a, const void *b, UnkCompare *c, s32 d, s32 e) {
    s32 v1 = 1;
    s32 n;
    u8 *r;
    if (a == NULL || (n = a->mCount) == 0) {
        return -1;
    }
    if (e != 0) {
        r = DarraySearchSorted(b, DarrayGetElement(a, d), n - d, a->mElemSize, c, &v1);
    } else {
        r = DarraySearchLinear(b, DarrayGetElement(a, d), n - d, a->mElemSize, c);
    }
    if (r != NULL && v1 != 0) {
        return (r - a->mList) / a->mElemSize;
    }
    return -1;
}

void DarrayForEachReverse(Darray *array, UnkCompare *fn, const void *c) {
    s32 i;
    if (fn == NULL) {
        AssertionFailed(data_ov000_021b22d8, data_ov000_021b22dc, NULL, 0x104);
    }
    for (i = array->mCount - 1; i >= 0; i--) {
        fn(DarrayGetElement(array, i), c);
    }
}

void *DarrayFindByFnReverse(Darray *array, UnkCompare *fn, const void *c) {
    s32 i;
    void *e;
    if (fn == NULL) {
        AssertionFailed(data_ov000_021b22d8, data_ov000_021b22dc, NULL, 0x121);
    }
    for (i = array->mCount - 1; i >= 0; i--) {
        e = DarrayGetElement(array, i);
        if (fn(e, c) == 0) {
            return e;
        }
    }
    return NULL;
}

void DarrayRemoveAll(Darray *a) {
    s32 i;
    for (i = DarrayGetCount(a) - 1; i >= 0; i--) {
        DarrayRemove(a, i);
    }
}

void *DarraySearchLinear(const void *a, u8 *b, s32 c, s32 d, UnkCompare *e) {
    s32 i;
    s32 v1;
    i = 0;
    if (c > 0) {
        v1 = 0;
        do {
            if (e(a, b + v1) == 0) {
                return b + d * i;
            }
            v1 += d;
            i++;
        } while (i < c);
    }
    return NULL;
}

void *DarraySearchSorted(const void *a, u8 *b, s32 c, s32 d, UnkCompare *e, s32 *f) {
    s32 v1 = 0;
    s32 v2 = c - 1;
    s32 v3;
    s32 r;
    *f = 0;
    if (v2 >= 0) {
        do {
            v3 = (v1 + v2) >> 1;
            r = e(b + v3 * d, a);
            if (r == 0) {
                *f = 1;
            }
            if (r < 0) {
                v1 = v3 + 1;
            } else {
                v2 = v3 - 1;
            }
        } while (v1 <= v2);
    }
    return b + v1 * d;
}
