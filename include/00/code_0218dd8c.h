#pragma once

#include "types.h"

typedef struct Darray Darray;

// 0x14 bytes. Table of Darray arrays: the array of buckets, its length, the per-element callback and the
// functions that pick a bucket and compare two elements.
typedef struct Hashtable {
    /* 00 */ Darray **mBuckets;
    /* 04 */ s32 mBucketCount;
    /* 08 */ void (*mElemCallback)(void *);
    /* 0c */ s32 (*mHashFn)(void *, s32);
    /* 10 */ s32 (*mCompFn)(void *, void *);
} Hashtable;

Hashtable *HashtableCreate(s32 elemSize, s32 nBuckets, s32 e, s32 (*hashFn)(void *, s32), s32 (*compFn)(void *, void *),
                           void (*h)(void *));

void *HashtableFindByFn(Hashtable *table, int fn, u32 c);
void HashtableForEach(Hashtable *table, void (*fn)(void *, void *), void *d);
void *HashtableFind(Hashtable *table, void *d);
BOOL HashtableRemove(Hashtable *table, void *d);
void HashtableSet(Hashtable *table, void *d);
s32 HashtableGetCount(Hashtable *table);
void HashtableDelete(void *c);
