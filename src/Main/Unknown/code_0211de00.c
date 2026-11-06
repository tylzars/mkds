#include "Main/Unknown/code_0211de00.h"

#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0211de34.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0216d000.h"
#include "code_02016468.h"
#include "Main/Unknown/code_0211df44.h"

#pragma thumb on

void LoadCupMarkData(void) {
    void *v1;
    Ncgr *v2;
    Unk02021dc8 *v3;
    Nclr *v4[1];
    v2 = NULL;
    v3 = NULL;
    v4[0] = NULL;
    v1 = FindSceneFile(gCupMarkNcgrName);
    LoadNcgrData(&v2, v1);
    v1 = FindSceneFile(gCupMarkNcerName);
    LoadNcerData(&v3, v1);
    v1 = FindSceneFile(gCupMarkNclrName);
    LoadNclrData(v4, v1);
}

void LoadCommonCupMarkData(void) {
    void *v1;
    Ncgr *v2;
    Unk02021dc8 *v3;
    Nclr *v4[1];
    v2 = NULL;
    v3 = NULL;
    v4[0] = NULL;
    v1 = FindSceneFile(gCommonCupMarkNcgrName);
    LoadNcgrData(&v2, v1);
    v1 = FindSceneFile(gCommonCupMarkNcerName);
    LoadNcerData(&v3, v1);
    v1 = FindSceneFile(gCommonCupMarkNclrName);
    LoadNclrData(v4, v1);
}

void CreateCupMark(void *a) {
    int v1;
    void *v2;
    v1 = ((u32) HeapAlloc(a, (u32) 0x10));
    *(s32 *) &gCupMark = v1;
    v2 = FindSceneFile(gCupMarkNcgrName);
    LocateNcgr2(&gCupMark->mNcgr, v2);
    v2 = FindSceneFile(gCupMarkNcerName);
    LocateNcer(&gCupMark->mNcer, v2);
    v2 = FindSceneFile(gCupMarkNclrName);
    LocateNclr(&gCupMark->mNclr, v2);
    v2 = FindSceneFile(gCupMarkBnclName);
    gCupMark->mBncl = v2;
}

void CreateCommonCupMark(void *a) {
    int v1;
    void *v2;
    v1 = ((u32) HeapAlloc(a, (u32) 0x10));
    *(s32 *) &gCupMark = v1;
    v2 = FindSceneFile(gCommonCupMarkNcgrName);
    LocateNcgr2(&gCupMark->mNcgr, v2);
    v2 = FindSceneFile(gCommonCupMarkNcerName);
    LocateNcer(&gCupMark->mNcer, v2);
    v2 = FindSceneFile(gCommonCupMarkNclrName);
    LocateNclr(&gCupMark->mNclr, v2);
    v2 = FindSceneFile(gCommonCupMarkBnclName);
    gCupMark->mBncl = v2;
}

#pragma thumb off

#pragma thumb on
void func_0211df38(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &gCupMark;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on

void QueueCupMark(u32 a, Unk02021dc8 *b, Unk0201ea30 *c, u32 d, u16 e, s32 f) {
    CupMark *p;
    u8 *dst;
    u32 v0 = 14;
    u32 id;
    u32 n;

    if (f != 0) {
        if (f == 1) {
            v0 = 30;
        }
    }
    id = ((u16 *) gCupMarkBnclIndices)[a];
    p = gCupMark;
    func_02124748(id, p->mNcer, p->mNcgr, p->mBncl, f, d, b, c);
    p = gCupMark;
    dst = (u8 *) p->mNclr->mData;
    n = func_02124a68(id, p->mNcer, p->mBncl);
    CallQueueAppend(v0, e << 5, dst + (n << 5), 32);
}

void func_0211de98(void) {
    void *v1;
    Ncgr *v2;
    Unk02021dc8 *v3[1];
    v2 = NULL;
    v3[0] = NULL;
    v1 = FindSceneFile(data_0216de54);
    LoadNcgrData2(&v2, v1);
    v1 = FindSceneFile(data_0216de58);
    LoadNcerData(v3, v1);
}

void func_0211de40(void *a) {
    int v1;
    void *v2;
    v1 = ((u32) HeapAlloc(a, (u32) 0xc));
    *(s32 *) &data_0217d36c = v1;
    v2 = FindSceneFile(data_0216de54);
    LocateNcgr2((Ncgr **) data_0217d36c, v2);
    v2 = FindSceneFile(data_0216de58);
    LocateNcer(&data_0217d36c->mUnk_04, v2);
    v2 = FindSceneFile(data_0216de50);
    data_0217d36c->mUnk_08 = v2;
}

#pragma thumb off

#pragma thumb on
void func_0211de34(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &data_0217d36c;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on

void func_0211de00(u32 a, Unk02021dc8 *b, Unk0201ea30 *c, u32 d, u32 e) {
    func_02124748(data_0215ced4[a], data_0217d36c->mUnk_04, data_0217d36c->mUnk_00, data_0217d36c->mUnk_08, e, d, b, c);
}

#pragma thumb off
