#include "Main/Unknown/code_0209bc74.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_020d2090.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020ea514.h"

#pragma thumb on
void *CreateMapObjectModelAnimated(void *a, const char *b) {
    MapObjectModel *o;

    o = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    if (a != NULL) {
        ((Unk0209bc74_a *) a)->mUnk_18 = 1;
    }
    o->mNsbmdFile = FindCourseMapObjFile(b);
    o->mAnimatedModel = HeapAlloc(GetHeap(func_020364e8()), 0x6c);
    InitNsbmd(o->mAnimatedModel, o->mNsbmdFile);
    SetNsbmdEmiAll(o->mAnimatedModel, 0x294a);
    SetNsbmdLightEnableFlagAll(o->mAnimatedModel, 2);
    o->mScale = data_021565c4;
    return o;
}
#pragma thumb off

#pragma thumb on
void CreateMapObjectModelNsbcaAnimation(MapObjectModel *a, const char *b) {
    void *x;

    x = FindCourseMapObjFile(b);
    a->mAnimations[0] = HeapAlloc(GetHeap(func_020364e8()), 0x38);
    func_020ea514(0, a->mAnimatedModel, a->mAnimations[0], a->mNsbmdFile, x);
}
#pragma thumb off

#pragma thumb on
void CreateMapObjectModelNsbtaAnimation(MapObjectModel *a, const char *b) {
    void *x;

    x = FindCourseMapObjFile(b);
    a->mAnimations[3] = HeapAlloc(GetHeap(func_020364e8()), 0x38);
    func_020ea514(1, a->mAnimatedModel, a->mAnimations[3], a->mNsbmdFile, x);
}
#pragma thumb off

#pragma thumb on
void CreateMapObjectModelNsbtpAnimation(MapObjectModel *a, const char *b) {
    void *x;

    x = FindCourseMapObjFile(b);
    a->mAnimations[1] = HeapAlloc(GetHeap(func_020364e8()), 0x38);
    func_020ea514(2, a->mAnimatedModel, a->mAnimations[1], a->mNsbmdFile, x);
}
#pragma thumb off

#pragma thumb on
void *CreateMapObjectModelShadow(void *a, const char *b) {
    MapObjectModel *o;
    void *x;

    o = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    x = FindCourseMapObjFile(b);
    if (a != NULL) {
        ((Unk0209bc74_a *) a)->mUnk_18 = 1;
    }
    o->mShadowModel = HeapAlloc(GetHeap(func_020364e8()), 0x74);
    func_0207afa8(o->mShadowModel, x, 0x3f);
    o->mScale = data_021565b8;
    return o;
}
#pragma thumb off

#pragma thumb on
void *CreateMapObjectModelNsbmd(void *a, const char *b) {
    MapObjectModel *o;
    void *x;
    Unk020e6488 *m;

    o = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    x = FindCourseMapObjFile(b);
    if (a != NULL) {
        ((Unk0209bc74_a *) a)->mUnk_18 = 2;
    }
    o->mNsbmdModel = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    func_020e64b8(o->mNsbmdModel, x, NULL, 0);
    m = o->mNsbmdModel;
    m->mUnk_10 &= 0x8000ffff;
    m->mUnk_10 |= 0x294a0000;
    m = o->mNsbmdModel;
    m->mUnk_14 &= ~0xf;
    m->mUnk_14 |= 2;
    o->mScale = data_021565ac;
    return o;
}
#pragma thumb off

#pragma thumb on
// Like CreateMapObjectModelNsbmd with a second file, the .nsbtp (named like Init<Kind><Kind>).
void *CreateMapObjectModelNsbmdNsbtp(void *a, const char *b, const char *c) {
    MapObjectModel *o;
    void *x;
    void *y;
    Unk020e6488 *m;

    o = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    x = FindCourseMapObjFile(b);
    y = FindCourseMapObjFile(c);
    if (a != NULL) {
        ((Unk0209bc74_a *) a)->mUnk_18 = 2;
    }
    o->mNsbmdModel = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    func_020e64b8(o->mNsbmdModel, x, y, 0);
    m = o->mNsbmdModel;
    m->mUnk_10 &= 0x8000ffff;
    m->mUnk_10 |= 0x294a0000;
    m = o->mNsbmdModel;
    m->mUnk_14 &= ~0xf;
    m->mUnk_14 |= 2;
    o->mScale = data_021565a0;
    return o;
}
#pragma thumb off
