#include "code_02016638.h"

#include "code_0200eddc.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/unk_02152000.h"
#include "code_0214b824.h"
#include "code_0214b338.h"
#include "code_0214c1bc.h"

u16 CallQueueNextIndex(CallQueue *p, u32 v) {
    return (v + 1) % p->mCapacity;
}

s32 CallQueueIsFull(CallQueue *p) {
    return p->mCount == p->mCapacity;
}

s32 CallQueueIsEmpty(CallQueue *p) {
    return p->mCount == 0;
}

void func_0201691c(const void *a, u32 b, u32 c) {
    GX_BeginLoadTex();
    GX_LoadTex(a, b, c);
    GX_EndLoadTex();
}

void func_020168ec(const void *a, u32 b, u32 c) {
    GX_BeginLoadTexPltt();
    GX_LoadTexPltt(a, b, c);
    GX_EndLoadTexPltt();
}

void func_020168bc(const void *a, u32 b, u32 c) {
    GX_BeginLoadClearImage();
    GX_LoadClearImageColor(a, c);
    GX_EndLoadClearImage();
}

void func_0201688c(const void *a, u32 b, u32 c) {
    GX_BeginLoadClearImage();
    GX_LoadClearImageDepth(a, c);
    GX_EndLoadClearImage();
}

void func_02016880(const void *a, u32 b, u32 c) {
    GX_LoadBG0Char(a, b, c);
}

void func_02016874(const void *a, u32 b, u32 c) {
    GX_LoadBG1Char(a, b, c);
}

void func_02016868(const void *a, u32 b, u32 c) {
    GX_LoadBG2Char(a, b, c);
}

void func_0201685c(const void *a, u32 b, u32 c) {
    GX_LoadBG3Char(a, b, c);
}

void func_02016850(const void *a, u32 b, u32 c) {
    GX_LoadBG0Scr(a, b, c);
}

void func_02016844(const void *a, u32 b, u32 c) {
    GX_LoadBG1Scr(a, b, c);
}

void func_02016838(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value12;
    GX_LoadBG2Scr((const void *) value0, (int) value1, value2);
}

void func_0201682c(const void *a, u32 b, u32 c) {
    GX_LoadBG3Scr(a, b, c);
}

void func_02016820(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value12;
    GX_LoadBG2Scr((const void *) value0, (int) value1, value2);
}

void func_02016814(const void *a, u32 b, u32 c) {
    GX_LoadBG3Scr(a, b, c);
}

void func_02016808(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value12;
    GX_LoadOBJPltt((const void *) value0, (int) value1, value2);
}

void func_020167fc(const void *a, u32 b, u32 c) {
    GX_LoadBGPltt(a, b, c);
}

void func_020167cc(const void *a, u32 b, u32 c) {
    GX_BeginLoadOBJExtPltt();
    GX_LoadOBJExtPltt(a, b, c);
    GX_EndLoadOBJExtPltt();
}

void func_0201679c(const void *a, u32 b, u32 c) {
    GX_BeginLoadBGExtPltt();
    GX_LoadBGExtPltt(a, b, c);
    GX_EndLoadBGExtPltt();
}

void func_02016790(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value12;
    GX_LoadOAM((const void *) value0, (int) value1, value2);
}

void func_02016784(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value12;
    GX_LoadOBJ((const void *) value0, (int) value1, value2);
}

void func_02016778(const void *a, u32 b, u32 c) {
    GXS_LoadBG0Char(a, b, c);
}

void func_0201676c(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value12;
    GXS_LoadBG1Char((const void *) value0, (int) value1, value2);
}

void func_02016760(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value12;
    GXS_LoadBG2Char((const void *) value0, (int) value1, value2);
}

void func_02016754(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value12;
    GXS_LoadBG3Char((const void *) value0, (int) value1, value2);
}

void func_02016748(const void *a, u32 b, u32 c) {
    GXS_LoadBG0Scr(a, b, c);
}

void func_0201673c(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value12;
    GXS_LoadBG1Scr((const void *) value0, (int) value1, value2);
}

void func_02016730(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value12;
    GXS_LoadBG2Scr((const void *) value0, (int) value1, value2);
}

void func_02016724(const void *a, u32 b, u32 c) {
    GXS_LoadBG3Scr(a, b, c);
}

void func_02016718(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value12;
    GXS_LoadBG2Scr((const void *) value0, (int) value1, value2);
}

void func_0201670c(const void *a, u32 b, u32 c) {
    GXS_LoadBG3Scr(a, b, c);
}

void func_02016700(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value12;
    GXS_LoadOBJPltt((const void *) value0, (int) value1, value2);
}

void func_020166f4(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value12;
    GXS_LoadBGPltt((const void *) value0, (int) value1, value2);
}

void func_020166c4(const void *a, u32 b, u32 c) {
    GXS_BeginLoadOBJExtPltt();
    GXS_LoadOBJExtPltt(a, b, c);
    GXS_EndLoadOBJExtPltt();
}

void func_02016694(const void *a, u32 b, u32 c) {
    GXS_BeginLoadBGExtPltt();
    GXS_LoadBGExtPltt(a, b, c);
    GXS_EndLoadBGExtPltt();
}

void func_02016688(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value12;
    GXS_LoadOAM((const void *) value0, (int) value1, value2);
}

void func_0201667c(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value12;
    GXS_LoadOBJ((const void *) value0, (int) value1, value2);
}

void CallQueueRunEntry(CallQueueEntry *p) {
    void (*f)(const void *, u32, u32);

    f = data_02152c54[p->mFuncIndex];
    DC_FlushRange(p->mSource, p->mSize);
    f(p->mSource, p->mUnk_08, p->mSize);
}
