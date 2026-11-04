#include "00/code_0218dd8c.h"
#include "00/code_0218d000.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"

#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_021a3000.h"
#include "00/code_0218d818.h"
#include "code_021382a8.h"
#include "00/code_021a3668.h"

Hashtable *HashtableCreate(s32 elemSize, s32 nBuckets, s32 e, s32 (*hashFn)(void *, s32), s32 (*compFn)(void *, void *),
                           void (*h)(void *)) {
    Hashtable *table;
    s32 b;
    if (hashFn == NULL) {
        AssertionFailed(data_ov000_021b236c, data_ov000_021b2358, NULL, 0x38);
    }
    if (compFn == NULL) {
        AssertionFailed(data_ov000_021b2374, data_ov000_021b2358, NULL, 0x39);
    }
    if (elemSize == 0) {
        AssertionFailed(data_ov000_021b237c, data_ov000_021b2358, NULL, 0x3a);
    }
    if (nBuckets == 0) {
        AssertionFailed(data_ov000_021b2388, data_ov000_021b2358, NULL, 0x3b);
    }
    table = func_ov000_021a3690(0x14);
    if (table == NULL) {
        AssertionFailed(data_ov000_021b2364, data_ov000_021b2358, NULL, 0x3e);
    }
    table->mBuckets = func_ov000_021a3690(nBuckets * 4);
    if (table->mBuckets == NULL) {
        AssertionFailed(data_ov000_021b2394, data_ov000_021b2358, NULL, 0x41);
    }
    for (b = 0; b < nBuckets; b++) {
        table->mBuckets[b] = DarrayCreate(elemSize, e, h);
    }
    table->mBucketCount = nBuckets;
    table->mElemCallback = h;
    table->mCompFn = compFn;
    table->mHashFn = hashFn;
    return table;
}

void HashtableDelete(void *c) {
    Hashtable *table = c;
    s32 b;
    if (table == NULL) {
        AssertionFailed(data_ov000_021b2364, data_ov000_021b2358, NULL, 0x51);
    }
    if (table != NULL) {
        for (b = 0; b < table->mBucketCount; b++) {
            DarrayDelete(table->mBuckets[b]);
        }
        func_ov000_021a3668(table->mBuckets);
        func_ov000_021a3668(table);
    }
}

s32 HashtableGetCount(Hashtable *table) {
    s32 a = 0;
    s32 b;
    if (table == NULL) {
        AssertionFailed(data_ov000_021b2364, data_ov000_021b2358, NULL, 0x61);
    }
    if (table == NULL) {
        return 0;
    }
    for (b = 0; b < table->mBucketCount; b++) {
        a += DarrayGetCount(table->mBuckets[b]);
    }
    return a;
}

void HashtableSet(Hashtable *table, void *d) {
    s32 a;
    s32 b;
    if (table == NULL) {
        AssertionFailed(data_ov000_021b2364, data_ov000_021b2358, NULL, 0x71);
    }
    if (table != NULL) {
        a = table->mHashFn(d, table->mBucketCount);
        b = DarrayFindIndex(table->mBuckets[a], d, (UnkCompare *) table->mCompFn, 0, 0);
        if (b == -1) {
            DarrayAppend(table->mBuckets[a], d);
            return;
        }
        DarrayReplace(table->mBuckets[a], d, b);
    }
}

BOOL HashtableRemove(Hashtable *table, void *d) {
    s32 a;
    s32 b;
    if (table == NULL) {
        AssertionFailed(data_ov000_021b2364, data_ov000_021b2358, NULL, 0x82);
    }
    if (table == NULL) {
        return FALSE;
    }
    a = table->mHashFn(d, table->mBucketCount);
    b = DarrayFindIndex(table->mBuckets[a], d, (UnkCompare *) table->mCompFn, 0, 0);
    if (b != -1) {
        DarrayRemove(table->mBuckets[a], b);
        return TRUE;
    }
    return FALSE;
}

void *HashtableFind(Hashtable *table, void *d) {
    s32 a;
    s32 b;
    if (table == NULL) {
        AssertionFailed(data_ov000_021b2364, data_ov000_021b2358, NULL, 0x94);
    }
    if (table == NULL) {
        return NULL;
    }
    a = table->mHashFn(d, table->mBucketCount);
    b = DarrayFindIndex(table->mBuckets[a], d, (UnkCompare *) table->mCompFn, 0, 0);
    if (b != -1) {
        return DarrayGetElement(table->mBuckets[a], b);
    }
    return NULL;
}

void HashtableForEach(Hashtable *table, void (*fn)(void *, void *), void *d) {
    s32 a;
    if (fn == NULL) {
        AssertionFailed(data_ov000_021b2354, data_ov000_021b2358, NULL, 0xb6);
    }
    for (a = 0; a < table->mBucketCount; a++) {
        DarrayForEachReverse(table->mBuckets[a], (UnkCompare *) fn, d);
    }
}

void *HashtableFindByFn(Hashtable *table, int fn, u32 c) {
    void *v1;
    int v3;
    if (fn == 0) {
        AssertionFailed(data_ov000_021b2354, data_ov000_021b2358, NULL, 0xd3);
    }
    v3 = 0;
    if (0 < table->mBucketCount) {
        do {
            v1 = DarrayFindByFnReverse(table->mBuckets[v3], (UnkCompare *) fn, (void *) c);
            if (v1 != NULL) {
                return v1;
            }
            v3 = v3 + 1;
        } while (v3 < table->mBucketCount);
    }
    return NULL;
}
