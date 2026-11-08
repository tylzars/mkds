#include "Main/Unknown/code_020e516c.h"

#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_020ea588.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020e55b4.h"
#include "code_02146cbc.h"

void func_020e55b4(void) {
    u32 value;
    value = data_0217b814->mUnk_01c;
    func_01ff9048(0x2b, &value, 1);
    func_01ff9048(0x2a, &data_0217b814->mUnk_014, 1);
    func_01ff9048(0x30, &data_0217b814->mUnk_004, 1);
    func_01ff9048(0x31, &data_0217b814->mUnk_008, 1);
}

void func_020e54e4(void *shadowData, void *wordPointer, u32 unused, u32 alpha) {
    u32 word;
    u32 b;
    u32 threeWords[3];
    Unk020e516c *shadow = shadowData;

    b = 0x1e;
    func_01ff9048(0x14, &b, 1);
    func_01ff9048(0x19, shadowData, 0xc);
    if (wordPointer != NULL) {
        u32 firstWord;
        firstWord = *(u32 *) wordPointer;
        threeWords[0] = firstWord;
        threeWords[1] = firstWord;
        threeWords[2] = firstWord;
        func_01ff9048(0x1b, threeWords, 3);
    }
    word = data_0217b814->mUnk_00c;
    alpha = alpha < shadow->mUnk_030 ? alpha : shadow->mUnk_030;
    word = word & ~0x1f0000;
    word = word | (alpha << 16);
    func_01ff9048(0x29, &word, 1);
    func_01ff9144(&data_0217b818->mUnk_000[data_0217b818->mUnk_008], data_0217b818->mUnk_00c);
}

void func_020e53ac(Unk020e516c *shadow, void *wordPointer, u32 unused, u32 alpha) {
    u32 x;
    u32 word;
    u32 b;
    u32 threeWords[3];

    x = data_0217b814->mUnk_01c;
    func_01ff9048(0x2b, &x, 1);
    func_01ff9048(0x2a, &data_0217b814->mUnk_014, 1);
    func_01ff9048(0x30, &data_0217b814->mUnk_004, 1);
    func_01ff9048(0x31, &data_0217b814->mUnk_008, 1);
    b = 0x1e;
    func_01ff9048(0x14, &b, 1);
    func_01ff9048(0x19, shadow, 0xc);
    if (wordPointer != NULL) {
        u32 wordCopy;
        wordCopy = *(u32 *) wordPointer;
        threeWords[0] = wordCopy;
        threeWords[1] = wordCopy;
        threeWords[2] = wordCopy;
        func_01ff9048(0x1b, threeWords, 3);
    }
    word = data_0217b814->mUnk_00c;
    alpha = alpha < shadow->mUnk_030 ? alpha : shadow->mUnk_030;
    word = word & ~0x1f0000;
    word = word | (alpha << 16);
    func_01ff9048(0x29, &word, 1);
    func_01ff9144(&data_0217b818->mUnk_000[data_0217b818->mUnk_008], data_0217b818->mUnk_00c);
}

void DrawJgShadowWithMatrix(Vec3 *scale, MtxFx43 *matrix, u32 c, u32 d) {
    gJgShadow->mUnk_06e = c < d ? c : d;
    DrawShadowWithMatrix(gJgShadow, matrix, scale);
}

void func_020e5348(u32 a, u32 b) {
    gJgShadow->mUnk_06e = a < b ? a : b;
    func_0207ad88(gJgShadow);
}

#pragma thumb on

void CreateObjShadowAndJgShadow(void) {
    Unk020e52bc_4 *a;
    Unk020e52bc_8 *b;
    Unk020e52bc_c *c;

    CreateNsbmd((void **) &gObjShadow, FindMainRaceOrMainEffectMapObjFile(gObjShadowNsbmdName), NULL);
    SetNsbmdPolygonIdAll(gObjShadow, 0x3f);
    SetNsbmdLightEnableFlagAll(gObjShadow, 0);
    a = gObjShadow->mUnk_004;
    b = (Unk020e52bc_8 *) &a->mUnk_000[a->mUnk_008];
    data_0217b814 = (Unk020e53ac *) &b->mUnk_000[((u32 *) &b->mUnk_000[b->mUnk_00a])[2]];
    a = gObjShadow->mUnk_004;
    c = (Unk020e52bc_c *) &a->mUnk_000[a->mUnk_00c];
    data_0217b818 = (Unk020e54e4 *) &c->mUnk_000[((u32 *) &c->mUnk_000[c->mUnk_006])[1]];
    if (gRaceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
        CreateShadowModel((void **) &gJgShadow, FindSceneFile(gJgShadowNsbmdName), 0x3f);
    }
}

s32 RefreshShadowMatrix(void *shadow, Vec3 *position, s32 scale, u32 alphaCap) {
    Quaternion rotation;
    Vec3 direction;
    Vec3 raisedPosition;
    s32 scaleTenth;
    BOOL hit;
    Unk020e516c *shadowCopy = shadow;

    raisedPosition = *position;
    hit = FALSE;
    raisedPosition.y = raisedPosition.y + 0x1999;
    if (func_01ffdee4(&raisedPosition, NULL, 0, 0xa000, 8, -2, NULL, &direction, NULL, NULL, NULL, NULL, NULL, NULL) !=
        0) {
        hit = TRUE;
        QuaternionFromYAxisToVec3(&direction, &rotation);
        Matrix3x3FromQuaternion(shadow, &rotation);
        scaleTenth = scale / 10;
        shadowCopy->mUnk_000[0] = ((s64) shadowCopy->mUnk_000[0] * scaleTenth) >> 12;
        shadowCopy->mUnk_000[1] = ((s64) shadowCopy->mUnk_000[1] * scaleTenth) >> 12;
        shadowCopy->mUnk_000[2] = ((s64) shadowCopy->mUnk_000[2] * scaleTenth) >> 12;
        shadowCopy->mUnk_000[3] = ((s64) shadowCopy->mUnk_000[3] * scaleTenth) >> 12;
        shadowCopy->mUnk_000[4] = ((s64) shadowCopy->mUnk_000[4] * scaleTenth) >> 12;
        shadowCopy->mUnk_000[5] = ((s64) shadowCopy->mUnk_000[5] * scaleTenth) >> 12;
        shadowCopy->mUnk_000[6] = ((s64) shadowCopy->mUnk_000[6] * scaleTenth) >> 12;
        shadowCopy->mUnk_000[7] = ((s64) shadowCopy->mUnk_000[7] * scaleTenth) >> 12;
        shadowCopy->mUnk_000[8] = ((s64) shadowCopy->mUnk_000[8] * scaleTenth) >> 12;
    } else {
        MTX_Identity33_(shadow);
    }
    shadowCopy->mUnk_000[9] = raisedPosition.x >> 4;
    shadowCopy->mUnk_000[10] = raisedPosition.y >> 4;
    shadowCopy->mUnk_000[11] = raisedPosition.z >> 4;
    shadowCopy->mUnk_030 = alphaCap;
    return hit;
}

#pragma thumb off
