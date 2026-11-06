#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"

typedef struct Unk0209bef0 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ void *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
} Unk0209bef0;

#pragma thumb on
void *func_0209bf48(void *arg0, void *arg1, void *arg2) {
    Unk0209bef0 *p = HeapAlloc(GetHeap(func_020364e8()), 40);
    p->mUnk_08 = arg0;
    p->mUnk_0c = arg2;
    p->mUnk_10 = arg1;
    p->mUnk_14 = 0;
    return p;
}
#pragma thumb off

#pragma thumb on
void *func_0209bf1c(void *arg0, void *arg1, void *arg2) {
    Unk0209bef0 *p = HeapAlloc(GetHeap(func_020364e8()), 44);
    p->mUnk_18 = 1;
    p->mUnk_08 = arg0;
    p->mUnk_0c = arg2;
    p->mUnk_10 = arg1;
    p->mUnk_14 = 0;
    return p;
}
#pragma thumb off

#pragma thumb on
void *func_0209bef0(void *arg0, void *arg1, void *arg2) {
    Unk0209bef0 *p = HeapAlloc(GetHeap(func_020364e8()), 44);
    p->mUnk_18 = 2;
    p->mUnk_08 = arg0;
    p->mUnk_0c = arg2;
    p->mUnk_10 = arg1;
    p->mUnk_14 = 0;
    return p;
}
#pragma thumb off
