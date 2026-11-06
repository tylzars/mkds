#include "Main/Unknown/code_021171a0.h"
#include "Main/Unknown/code_02036820.h"

#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"
#include "Main/Unknown/code_02117218.h"
#include "Main/Unknown/code_02117224.h"
#include "Main/Unknown/code_021172a8.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/code_0211732c.h"
#include "Main/Unknown/code_02047104.h"

#pragma thumb on

void LoadKartIconData(void) {
    void *v1;
    int v2;
    const char **v3;
    Ncgr *v4;
    Unk02021dc8 *v5;
    Nclr *v6[2];
    v4 = NULL;
    v5 = NULL;
    v6[0] = NULL;
    v1 = FindSceneFile(gKartIconNcgrName);
    LoadNcgrData(&v4, v1);
    v1 = FindSceneFile(gKartIconNcerName);
    LoadNcerData(&v5, v1);
    v2 = 0;
    v3 = gKartIconNclrNames;
    do {
        v1 = FindSceneFile(*v3);
        LoadNclrData(v6, v1);
        v3 = v3 + 1;
        v2 = v2 + 1;
    } while (v2 < 3);
}

void LoadCommonKartIconData(void) {
    void *v1;
    int v2;
    const char **v3;
    Ncgr *v4;
    Unk02021dc8 *v5;
    Nclr *v6[2];
    v4 = NULL;
    v5 = NULL;
    v6[0] = NULL;
    v1 = FindSceneFile(gCommonKartIconNcgrName);
    LoadNcgrData(&v4, v1);
    v1 = FindSceneFile(gCommonKartIconNcerName);
    LoadNcerData(&v5, v1);
    v2 = 0;
    v3 = gCommonKartIconNclrNames;
    do {
        v1 = FindSceneFile(*v3);
        LoadNclrData(v6, v1);
        v3 = v3 + 1;
        v2 = v2 + 1;
    } while (v2 < 3);
}

#pragma thumb off

#pragma thumb on

void CreateKartIcon(void *a) {
    int i;

    gKartIcon = HeapAlloc(a, 0x18);
    LocateNcgr2(&gKartIcon->mNcgr, FindSceneFile(gKartIconNcgrName));
    LocateNcer(&gKartIcon->mNcer, FindSceneFile(gKartIconNcerName));
    for (i = 0; i < 3; i++) {
        LocateNclr(&gKartIcon->mNclrs[i], FindSceneFile(gKartIconNclrNames[i]));
    }
    gKartIcon->mBncl = FindSceneFile(gKartIconBnclName);
}

#pragma thumb off

#pragma thumb on

void CreateCommonKartIcon(void *heap) {
    s32 i;

    gKartIcon = HeapAlloc(heap, 0x18);
    LocateNcgr2(&gKartIcon->mNcgr, FindSceneFile(gCommonKartIconNcgrName));
    LocateNcer(&gKartIcon->mNcer, FindSceneFile(gCommonKartIconNcerName));
    for (i = 0; i < 3; i++) {
        LocateNclr(&gKartIcon->mNclrs[i], FindSceneFile(gCommonKartIconNclrNames[i]));
    }
    gKartIcon->mBncl = FindSceneFile(gCommonKartIconBnclName);
}

#pragma thumb off

#pragma thumb on
void func_02117218(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &gKartIcon;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on

void QueueKartIcon(s32 a, Unk02021dc8 *b, Unk0201ea30 *c, u32 d, u16 e, s32 f) {
    int n;

    n = 0x12;
    switch (f) {
        case 0:
            n = 0xe;
            break;
        case 1:
            n = 0x1e;
            break;
    }
    func_02124748(gKartIconRows[a].mBnclIndex, gKartIcon->mNcer, gKartIcon->mNcgr, gKartIcon->mBncl, f, d, b, c);
    CallQueueAppend(n, e * 32, gKartIcon->mNclrs[gKartIconRows[a].mNclrIndex]->mData + gKartIconRows[a].mNclrStart * 16,
                    0x20);
}

#pragma thumb off
