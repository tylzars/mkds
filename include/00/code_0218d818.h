#pragma once

#include "types.h"

typedef struct Darray Darray;

typedef s32 UnkCompare(const void *a, const void *b);

// 0x18 bytes. Growable array: count, capacity, element size, growth step, per-element callback, element data.
typedef struct Darray {
    /* 00 */ s32 mCount;
    /* 04 */ s32 mCapacity;
    /* 08 */ s32 mElemSize;
    /* 0c */ s32 mGrowCount;
    /* 10 */ void (*mElemCallback)(void *);
    /* 14 */ u8 *mList;
} Darray;

void *DarraySearchSorted(const void *a, u8 *b, s32 c, s32 d, UnkCompare *e, s32 *f);
void *DarraySearchLinear(const void *a, u8 *b, s32 c, s32 d, UnkCompare *e);
void DarrayRemoveAll(Darray *a);
void *DarrayFindByFnReverse(Darray *array, UnkCompare *fn, const void *c);
void DarrayForEachReverse(Darray *array, UnkCompare *fn, const void *c);
s32 DarrayFindIndex(Darray *a, const void *b, UnkCompare *c, s32 d, s32 e);
void DarraySort(Darray *p0, unsigned int p1);
void DarrayReplace(Darray *array, const void *b, s32 n);
void DarrayRemove(Darray *array, s32 n);
void DarrayRemoveWithoutCallback(Darray *array, int n);
void DarrayInsertSorted(Darray *array, void *b, UnkCompare *comparator);
void DarrayInsert(void *param_1, void *param_2, s32 n);
void DarrayAppend(void *param_1, void *param_2);
void *DarrayGetElement(void *param_1, s32 n);
s32 DarrayGetCount(void *b);
void DarrayDelete(void *c);
void *DarrayCreate(s32 elemSize, s32 c, void (*d)(void *));
void DarraySetElement(Darray *a, const void *b, s32 c);
void DarrayGrow(Darray *a);
void DarrayCallElemCallback(void *b, s32 c);
