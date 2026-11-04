#include "Main/Unknown/code_0202a734.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_02162000.h"

#pragma thumb on

void func_0202a734(void) {
    void *v1;
    Ncgr *v2;
    Nclr *v3;
    Unk02021dc8 *v4;
    Nscr *v5[1];
    v2 = NULL;
    v3 = NULL;
    v4 = NULL;
    v5[0] = NULL;
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
