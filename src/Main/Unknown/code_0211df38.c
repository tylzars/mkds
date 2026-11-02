#include "Main/Unknown/code_0211df38.h"

#include "Main/Unknown/code_0211df44.h"

#pragma thumb on

void func_0211e074(void) {
    void *v1;
    Unk020b4934 *v2;
    Unk02021dc8 *v3;
    Unk020b4a44 *v4[1];
    v2 = NULL;
    v3 = NULL;
    v4[0] = NULL;
    v1 = FindSceneFile(data_0216ded4);
    LoadNcgrData(&v2, v1);
    v1 = FindSceneFile(data_0216ded8);
    LoadNcerData(&v3, v1);
    v1 = FindSceneFile(data_0216dec4);
    LoadNclrData(v4, v1);
}

void func_0211e024(void) {
    void *v1;
    Unk020b4934 *v2;
    Unk02021dc8 *v3;
    Unk020b4a44 *v4[1];
    v2 = NULL;
    v3 = NULL;
    v4[0] = NULL;
    v1 = FindSceneFile(data_0216dedc);
    LoadNcgrData(&v2, v1);
    v1 = FindSceneFile(data_0216decc);
    LoadNcerData(&v3, v1);
    v1 = FindSceneFile(data_0216dee0);
    LoadNclrData(v4, v1);
}

void func_0211dfb4(u32 a) {
    int v1;
    void *v2;
    v1 = ((u32) func_02036bec((void *) a, (u32) 0x10));
    *(s32 *) &data_0217d370 = v1;
    v2 = FindSceneFile(data_0216ded4);
    LocateNcgr2(&data_0217d370->mUnk_00, v2);
    v2 = FindSceneFile(data_0216ded8);
    LocateNcer(&data_0217d370->mUnk_04, v2);
    v2 = FindSceneFile(data_0216dec4);
    LocateNclr(&data_0217d370->mUnk_08, v2);
    v2 = FindSceneFile(data_0216dec8);
    data_0217d370->mUnk_0c = v2;
}

void func_0211df44(void *a) {
    int v1;
    void *v2;
    v1 = ((u32) func_02036bec(a, (u32) 0x10));
    *(s32 *) &data_0217d370 = v1;
    v2 = FindSceneFile(data_0216dedc);
    LocateNcgr2(&data_0217d370->mUnk_00, v2);
    v2 = FindSceneFile(data_0216decc);
    LocateNcer(&data_0217d370->mUnk_04, v2);
    v2 = FindSceneFile(data_0216dee0);
    LocateNclr(&data_0217d370->mUnk_08, v2);
    v2 = FindSceneFile(data_0216ded0);
    data_0217d370->mUnk_0c = v2;
}

#pragma thumb off

#pragma thumb on
void func_0211df38(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &data_0217d370;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off
