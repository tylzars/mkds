#include "Main/Unknown/code_020a9cd4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0209b634.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020aa81c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/code_020d2090.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_020ab000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02146cbc.h"

#pragma opt_propagation off

#pragma thumb on

void func_020a9ea0(u16 a) {
    Unk0217b278_10 *p;
    u16 v;

    p = func_020ab338(a);
    if (p != NULL) {
        data_0217b278.mUnk_44 = p;
        if (data_0217b278.mUnk_4c != NULL) {
            v = data_0217b278.mUnk_4c(func_020ab2a4(p), 0);
            if (v != 0) {
                data_0217b278.mUnk_44 = func_020ab338(v);
            }
        }
    }
}

s32 func_020a9e90(void) {
    return func_020ab2a4(data_0217b278.mUnk_44);
}

s32 func_020a9e80(void) {
    return func_020ab1d0(data_0217b2b8[0]);
}

#pragma thumb off

void InitIronBall(IronBall *p) {
    Vec3 v = data_02167974;

    SetMapObjectScale(&p->mUnk_000, &v);
    p->mUnk_000.mUnk_94 = HeapAlloc(GetHeap(func_020364e8()), 0x44);
    InitSoundSource(&p->mUnk_000.mUnk_94->mSoundSource, 10, &p->mUnk_000.mPos);
    p->mUnk_000.mUnk_70 = gSoundFalloffs[10].mUnk_20;
    p->mUnk_128 = DecimalNonZeroDigitsToBitMask(p->mUnk_000.mCourseMapRow->mUnk_34);
}

u32 func_020a9de4(Unk020a9224 *p, void *a, u8 *b, u8 *c) {
    u32 x = *b;
    u32 y = *c;

    if (x == 1) {
        p->mUnk_c0 = 0xa000;
        return 0;
    }
    return (u8) y;
}

void CreateIronBall(void *a) {
    gIronBall = CreateMapObjectModelNsbmd(a, gIronBallNsbmdName);
    SetMapObjectModelPolygonId(gIronBall, 0x3f);
}

void func_020a9d98(void *a) {
    func_0209bbd0(a, gIronBall);
}

void DrawIronBall(void *a, IronBall *p) {
    u32 v;
    u8 v1[0x28];
    s32 i;

    v = 0x1e;
    func_01ff9048(0x14, &v, 1);
    func_01ff9048(0x19, func_020e6cf8(&p->mUnk_000.mPos), 0xc);
    if (p->mUnk_0a0 != 0) {
        i = (u16) p->mUnk_0a0 >> 4;
        Matrix3x3FromPairZ((s32 *) v1, gPairsByAngle[i * 2], gPairsByAngle[i * 2 + 1]);
        func_01ff9048(0x1a, v1, 9);
    }
    func_01ff9048(0x1b, &p->mUnk_000.mScale, 3);
    DrawMapObjectModel(a, gIronBall, p);
}
