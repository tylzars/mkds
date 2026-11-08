#include "01/code_0219b250.h"

#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_0209b634.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_02048000.h"
#include "01/unk_021a9000.h"
#include "code_02013740.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "code_02134398.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020ea514.h"

void *func_ov001_0219b510(void *p0, void *p1, void *p2, u32 p3, u16 p4, u16 p5, u16 p6) {
    Unk0209bf70 *r = CreateMapObjectKindData(p0, p1, p2, p3, p4);
    r->mUnk_24 = p5;
    r->mUnk_28 = p6;
    r->mUnk_38 = 0x270f000;
    r->mUnk_3c = 0xfd8f1000;
    return r;
}

void *LoadMissionRunFile(const char *p0) {
    char buf[0x100];
    void *out = NULL;
    snprintf(buf, 0x100, "data/MissionRun/%s", p0);
    LoadFileIntoHeap(buf, GetHeap(GetCurrentHeapCall()), &out);
    return out;
}

// Overlay-1 version of CreateMapObjectModelAnimated; the file comes from LoadMissionRunFile.
Unk0219b250 *LoadMapObjectModelAnimated(Unk0219b478 *p0, const char *p1) {
    Unk0219b250 *o = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    if (p0 != NULL) {
        p0->mUnk_18 = 1;
    }
    o->mNsbmdFile = LoadMissionRunFile((p1));
    o->mAnimatedModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x6c);
    InitNsbmd(o->mAnimatedModel, o->mNsbmdFile);
    SetMapObjectModelFogEnabled(o, 0);
    o->mScale = data_ov001_021a6b2c;
    return o;
}

// Overlay-1 version of CreateMapObjectModelShadow; the file comes from LoadMissionRunFile.
Unk0219b250 *LoadMapObjectModelShadow(Unk0219b478 *p0, const char *p1) {
    Unk0219b250 *o = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    void *r = LoadMissionRunFile((p1));
    if (p0 != NULL) {
        p0->mUnk_18 = 1;
    }
    o->mShadowModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x74);
    InitShadowModel(o->mShadowModel, r, 0x3f);
    SetMapObjectModelFogEnabled(o, 0);
    o->mScale = data_ov001_021a6b20;
    return o;
}

void LoadMapObjectModelNsbcaAnimation(Unk0219b250 *p0, const char *p1) {
    void *r = LoadMissionRunFile((p1));
    u8 v;
    p0->mNsbcaAnimation = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    v = NNS_G3dGetJntAnmSet(r)->mDict.mNumEntry;
    InitModelAnimation(0, p0->mNsbcaAnimation, p0->mAnimatedModel, v, GetHeap(GetCurrentHeapCall()), p0->mNsbmdFile);
    InitModelAnimationEntries(p0->mNsbcaAnimation, r, GetHeap(GetCurrentHeapCall()));
    SetModelAnimation(p0->mNsbcaAnimation, 0);
}

void LoadMapObjectModelNsbmaAnimation(Unk0219b250 *p0, const char *p1) {
    void *r = LoadMissionRunFile((p1));
    p0->mNsbmaAnimation = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    InitModelAnimationWithEntries(4, (p0->mAnimatedModel), (p0->mNsbmaAnimation), (p0->mNsbmdFile), (r));
}

void LoadMapObjectModelNsbtaAnimation(Unk0219b250 *p0, const char *p1) {
    void *r = LoadMissionRunFile((p1));
    u8 v;
    p0->mNsbtaAnimation = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    v = NNS_G3dGetTexSRTAnmSet(r)->mDict.mNumEntry;
    InitModelAnimation(1, p0->mNsbtaAnimation, p0->mAnimatedModel, v, GetHeap(GetCurrentHeapCall()), p0->mNsbmdFile);
    InitModelAnimationEntries(p0->mNsbtaAnimation, r, GetHeap(GetCurrentHeapCall()));
    SetModelAnimation(p0->mNsbtaAnimation, 0);
}

void LoadMapObjectModelNsbtpAnimation(Unk0219b250 *p0, const char *p1) {
    void *r = LoadMissionRunFile((p1));
    p0->mNsbtpAnimation = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    InitModelAnimationWithEntries(2, (p0->mAnimatedModel), (p0->mNsbtpAnimation), (p0->mNsbmdFile), (r));
}

void func_ov001_0219b28c(Unk0219b250 *p0, void *p1) {
    u8 v;
    p0->mNsbcaAnimation = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    v = NNS_G3dGetJntAnmSet(p1)->mDict.mNumEntry;
    InitModelAnimation(0, p0->mNsbcaAnimation, p0->mAnimatedModel, v, GetHeap(GetCurrentHeapCall()), p0->mNsbmdFile);
    InitModelAnimationEntries(p0->mNsbcaAnimation, p1, GetHeap(GetCurrentHeapCall()));
    SetModelAnimation(p0->mNsbcaAnimation, 0);
}

void func_ov001_0219b25c(Unk0219b250 *p0, void *p1) {
    p0->mNsbtpAnimation = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    InitModelAnimationWithEntries(2, (p0->mAnimatedModel), (p0->mNsbtpAnimation), (p0->mNsbmdFile), (p1));
}

void func_ov001_0219b250(Unk0219b250 *p0) {
    AdvanceModelAnimation(p0->mNsbcaAnimation);
}
