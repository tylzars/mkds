#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02116dc8.h"

#include "Main/Unknown/code_02116dd4.h"
#include "Main/Unknown/unk_0216d000.h"

#pragma thumb on

void func_02116e70(void) {
    void *v1;
    Unk02021dc8 *v2;
    Ncgr *v3;
    Nclr *v4[1];
    v2 = NULL;
    v3 = NULL;
    v4[0] = NULL;
    v1 = FindSceneFile(data_0216d4c4);
    LoadNcerData(&v2, v1);
    v1 = FindSceneFile(data_0216d4bc);
    LoadNcgrData2(&v3, v1);
    v1 = FindSceneFile(data_0216d4c0);
    LoadNclrData(v4, v1);
}

void func_02116dd4(void *a, void *b, void *c, u32 d, u16 e, u32 f) {
    int *v1;
    int v2;
    void *v3;
    v2 = ((u32) HeapAlloc(a, (u32) 0x2c));
    *(s32 *) &data_0217d354 = v2;
    v3 = FindSceneFile(data_0216d4c4);
    LocateNcer(&data_0217d354->mUnk_00, v3);
    v3 = FindSceneFile(data_0216d4bc);
    LocateNcgr2((Ncgr **) &data_0217d354->mUnk_04, v3);
    v3 = FindSceneFile(data_0216d4c0);
    LocateNclr((Nclr **) (((s32) data_0217d354 + 8)), v3);
    v3 = FindSceneFile(data_0216d4c8);
    v1 = (s32 *) &data_0217d354;
    data_0217d354->mUnk_0c = v3;
    *(void **) (*v1 + 0x10) = b;
    *(void **) (*v1 + 0x14) = c;
    *(u32 *) (*v1 + 0x18) = d;
    *(u16 *) (*v1 + 0x1c) = e;
    *(u32 *) (*v1 + 0x20) = f;
    *(u16 *) (*v1 + 0x24) = 2;
    *(u32 *) (*v1 + 0x28) = 3;
}

#pragma thumb off

#pragma thumb on
void func_02116dc8(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &data_0217d354;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off
