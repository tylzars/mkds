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

void DoTransfer3dTex(const void *pSrc, u32 offset, u32 szByte) {
    GX_BeginLoadTex();
    GX_LoadTex(pSrc, offset, szByte);
    GX_EndLoadTex();
}

void DoTransfer3dTexPltt(const void *pSrc, u32 offset, u32 szByte) {
    GX_BeginLoadTexPltt();
    GX_LoadTexPltt(pSrc, offset, szByte);
    GX_EndLoadTexPltt();
}

void DoTransfer3dClearImageColor(const void *pSrc, u32 offset, u32 szByte) {
    GX_BeginLoadClearImage();
    GX_LoadClearImageColor(pSrc, szByte);
    GX_EndLoadClearImage();
}

void DoTransfer3dClearImageDepth(const void *pSrc, u32 offset, u32 szByte) {
    GX_BeginLoadClearImage();
    GX_LoadClearImageDepth(pSrc, szByte);
    GX_EndLoadClearImage();
}

void DoTransfer2dBG0CharMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG0Char(pSrc, offset, szByte);
}

void DoTransfer2dBG1CharMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG1Char(pSrc, offset, szByte);
}

void DoTransfer2dBG2CharMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG2Char(pSrc, offset, szByte);
}

void DoTransfer2dBG3CharMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG3Char(pSrc, offset, szByte);
}

void DoTransfer2dBG0ScrMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG0Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG1ScrMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG1Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG2ScrMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG2Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG3ScrMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG3Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG2BmpMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG2Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG3BmpMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG3Scr(pSrc, offset, szByte);
}

void DoTransfer2dObjPlttMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadOBJPltt(pSrc, offset, szByte);
}

void DoTransfer2dBGPlttMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBGPltt(pSrc, offset, szByte);
}

void DoTransfer2dObjExtPlttMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_BeginLoadOBJExtPltt();
    GX_LoadOBJExtPltt(pSrc, offset, szByte);
    GX_EndLoadOBJExtPltt();
}

void DoTransfer2dBGExtPlttMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_BeginLoadBGExtPltt();
    GX_LoadBGExtPltt(pSrc, offset, szByte);
    GX_EndLoadBGExtPltt();
}

void DoTransfer2dObjOamMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadOAM(pSrc, offset, szByte);
}

void DoTransfer2dObjCharMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadOBJ(pSrc, offset, szByte);
}

void DoTransfer2dBG0CharSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG0Char(pSrc, offset, szByte);
}

void DoTransfer2dBG1CharSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG1Char(pSrc, offset, szByte);
}

void DoTransfer2dBG2CharSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG2Char(pSrc, offset, szByte);
}

void DoTransfer2dBG3CharSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG3Char(pSrc, offset, szByte);
}

void DoTransfer2dBG0ScrSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG0Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG1ScrSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG1Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG2ScrSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG2Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG3ScrSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG3Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG2BmpSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG2Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG3BmpSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG3Scr(pSrc, offset, szByte);
}

void DoTransfer2dObjPlttSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadOBJPltt(pSrc, offset, szByte);
}

void DoTransfer2dBGPlttSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBGPltt(pSrc, offset, szByte);
}

void DoTransfer2dObjExtPlttSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_BeginLoadOBJExtPltt();
    GXS_LoadOBJExtPltt(pSrc, offset, szByte);
    GXS_EndLoadOBJExtPltt();
}

void DoTransfer2dBGExtPlttSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_BeginLoadBGExtPltt();
    GXS_LoadBGExtPltt(pSrc, offset, szByte);
    GXS_EndLoadBGExtPltt();
}

void DoTransfer2dObjOamSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadOAM(pSrc, offset, szByte);
}

void DoTransfer2dObjCharSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadOBJ(pSrc, offset, szByte);
}

void CallQueueRunEntry(CallQueueEntry *p) {
    void (*f)(const void *, u32, u32);

    f = data_02152c54[p->mFuncIndex];
    DC_FlushRange(p->mSource, p->mSize);
    f(p->mSource, p->mUnk_08, p->mSize);
}
