#include "Main/Unknown/code_0202a734.h"

#pragma thumb on

void func_0202a734(void) {
    void *v1;
    Unk020b4934 *v2;
    Unk020b4a44 *v3;
    Unk02021dc8 *v4;
    Unk020b47d8 *v5[1];
    v2 = 0;
    v3 = 0;
    v4 = 0;
    v5[0] = 0;
    v1 = FindSceneFile(data_021622f8);
    LoadNcgrData(&v2, v1);
    v1 = FindSceneFile(data_02162318);
    LoadNcgrData(&v2, v1);
    v1 = FindSceneFile(data_02162338);
    LoadNcgrData2(&v2, v1);
    v1 = FindSceneFile(data_0216235c);
    LoadNcgrData2(&v2, v1);
    v1 = FindSceneFile(data_02162380);
    LoadNcerData(&v4, v1);
    v1 = FindSceneFile(data_021623a4);
    LoadNcerData(&v4, v1);
    v1 = FindSceneFile(data_021623c8);
    LoadNclrData(&v3, v1);
    v1 = FindSceneFile(data_021623e8);
    LoadNclrData(&v3, v1);
    v1 = FindSceneFile(data_02162408);
    LoadNclrData(&v3, v1);
    v1 = FindSceneFile(data_02162428);
    LoadNclrData(&v3, v1);
    v1 = FindSceneFile(data_02162448);
    LoadNscrData(v5, v1);
    v1 = FindSceneFile(data_02162468);
    LoadNscrData(v5, v1);
}

#pragma thumb off
