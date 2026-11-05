#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020e3618.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e7a84.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ea588.h"

#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020f9c6c.h"

#pragma thumb off

BOOL func_020e3af0(u32 a) {
    switch (a) {
        case 0xcc:
            return TRUE;
        default:
            return FALSE;
    }
}

#pragma thumb on

void CreateBridge(void) {
    void *p;

    p = (void *) FindCourseMapObjFile(gBridgeNsbmdName);
    func_020ea588(&gBridge, p, NULL);
    func_020ea4bc(0, gBridge, &gBridgeNsbca, p, (void *) FindCourseMapObjFile(gBridgeNsbcaName));
    ((Unk020e1dc0 *) *(void **) data_0217b7c4)->mUnk_2c = func_02087d0c(gBridgeNsbca);
    func_02084968(gBridge, 0x3f, 2, 0x294a);
    func_020e1dc0(*(void **) data_0217b7c4, gBridge);
}

void InitBridge(Bridge *a, struct CourseMapRow *b) {
    a->mUnk_0e8 = a->mUnk_000.mPos;
    a->mUnk_0a0 = *(Unk020e38a0_28 *) &a->mUnk_000.mMatrix;
    a->mUnk_0c4 = *(Unk020e38a0_28 *) &a->mUnk_000.mMatrix;
    a->mUnk_124.x = 0;
    a->mUnk_124.y = 0;
    a->mUnk_124.z = 0;
    a->mUnk_130 = 1;
    a->mUnk_144 = ((b->mUnk_28 * 0x10000) / 0x168) >> 1;
    a->mUnk_146 = (0x10000 / b->mUnk_2a) >> 1;
    a->mUnk_14c = b->mUnk_2c;
    a->mUnk_14e = b->mUnk_2e;
    a->mUnk_150 = 0;
    a->mUnk_148 = 0;
    if (data_021759c0->mMode == 5) {
        a->mUnk_146 = 0;
        a->mUnk_148 = ((b->mUnk_30 * 0x10000) / 0x168) >> 1;
    }
    a->mUnk_100 = (s32) (((s64) a->mUnk_000.mScale.x * 0x5a000) >> 12);
    a->mUnk_104 = (s32) (((s64) a->mUnk_000.mScale.y * 0x1e000) >> 12) >> 1;
    a->mUnk_108 = (s32) (((s64) a->mUnk_000.mScale.z * 0x15e000) >> 12);
    a->mUnk_10c = (s32) (((s64) a->mUnk_000.mScale.z * 0x32000) >> 12);
    a->mUnk_110 = 0;
    a->mUnk_114.x = 1;
    a->mUnk_114.y = 0;
    a->mUnk_114.z = 1;
    a->mUnk_120 = 0x800;
    a->mUnk_134 = 0;
    a->mUnk_138 = 0;
    a->mUnk_000.mFlags |= data_02158c88;
    a->mUnk_000.mFlags &= ~2;
    a->mUnk_000.mFlags &= ~8;
    a->mUnk_000.mUnk_66 = 0x1f;
    if (b->mUnk_0c.y < 0) {
        func_020d278c(&a->mUnk_000);
    }
}

#pragma thumb off

void *func_020e3850(void) {
    Unk020e03f8 *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x40);
    *p = *(const Unk020e03f8 *) data_02158c3c;
    return p;
}

void *func_020e37f4(void) {
    void *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    data_0217b7bc = p;
    *(Unk020e039c *) p = *(const Unk020e039c *) data_02158c10;
    func_020d49d8(&data_0217b7bc);
    return data_0217b7bc;
}

void *func_020e3798(void) {
    void *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    data_0217b7c0 = p;
    *(Unk020e039c *) p = *(const Unk020e039c *) data_02158be4;
    func_020d49d8(&data_0217b7c0);
    return data_0217b7c0;
}

void *func_020e373c(void) {
    void *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x28);
    data_0217b7b4 = p;
    *(Unk020e0340 *) p = *(const Unk020e0340 *) data_02158bbc;
    func_020e6f50(&data_0217b7b4);
    return data_0217b7b4;
}

void func_020e3724(void) {
    func_020e6a18(gChoropu);
}

void func_020e3618(s32 a, Unk020e1e98 *b, s32 c, u16 d) {
    Unk02012f58 *p;

    switch (b->mUnk_000.mUnk_80.mState) {
        case 4:
            gChoropu->mUnk_18 = 1;
            p = func_020e6cf8(&b->mUnk_000.mPos);
            func_020e67c4(gChoropu, p, &b->mUnk_000.mScale, 0, d);
            break;
        case 5:
            break;
        case 6:
        case 7:
            gChoropu->mUnk_18 = 1;
            p = func_020e6cf8(&b->mUnk_000.mPos);
            func_020e66e4(gChoropu, p, b->mUnk_0b4.mUnk_04, &b->mUnk_000.mScale, 0, d);
            break;
        default:
            gChoropu->mUnk_18 = 0;
            p = func_020e6cf8(&b->mUnk_000.mPos);
            func_020e67c4(gChoropu, p, &b->mUnk_000.mScale, 0, d);
    }
}
