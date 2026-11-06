#include "Main/Unknown/code_0202e274.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0211732c.h"
#include "Main/Unknown/unk_02162000.h"
#include "Main/Unknown/unk_02163000.h"

#pragma thumb on

void func_0202e274(void) {
    void *v1;
    Ncgr *v2;
    Nclr *v3;
    Unk02021dc8 *v4;
    Nscr *v5[1];
    v2 = NULL;
    v3 = NULL;
    v4 = NULL;
    v5[0] = NULL;
    v1 = FindSceneFile(data_02162f58);
    LoadNcgrData(&v2, v1);
    v1 = FindSceneFile(data_02162f78);
    LoadNcgrData(&v2, v1);
    v1 = FindSceneFile(data_02162f98);
    LoadNcgrData(&v2, v1);
    v1 = FindSceneFile(data_02162fb8);
    LoadNcgrData(&v2, v1);
    v1 = FindSceneFile(data_02162fd8);
    LoadNcgrData2(&v2, v1);
    v1 = FindSceneFile(data_02162ff8);
    LoadNcgrData2(&v2, v1);
    v1 = FindSceneFile(data_02163018);
    LoadNcgrData2(&v2, v1);
    v1 = FindSceneFile(data_0216303c);
    LoadNcgrData2(&v2, v1);
    v1 = FindSceneFile(data_02163060);
    LoadNcerData(&v4, v1);
    v1 = FindSceneFile(data_02163080);
    LoadNcerData(&v4, v1);
    v1 = FindSceneFile(data_021630a0);
    LoadNcerData(&v4, v1);
    v1 = FindSceneFile(data_021630c4);
    LoadNcerData(&v4, v1);
    v1 = FindSceneFile(data_021630e8);
    LoadNclrData(&v3, v1);
    v1 = FindSceneFile(data_02163108);
    LoadNclrData(&v3, v1);
    v1 = FindSceneFile(data_02163128);
    LoadNclrData(&v3, v1);
    v1 = FindSceneFile(data_02163148);
    LoadNclrData(&v3, v1);
    v1 = FindSceneFile(data_02163168);
    LoadNclrData(&v3, v1);
    v1 = FindSceneFile(data_02163188);
    LoadNclrData(&v3, v1);
    v1 = FindSceneFile(data_021631a8);
    LoadNclrData(&v3, v1);
    v1 = FindSceneFile(data_021631c8);
    LoadNclrData(&v3, v1);
    v1 = FindSceneFile(data_021631e8);
    LoadNscrData(v5, v1);
    v1 = FindSceneFile(data_02163204);
    LoadNscrData(v5, v1);
    v1 = FindSceneFile(data_02163220);
    LoadNscrData(v5, v1);
    v1 = FindSceneFile(data_02163240);
    LoadNscrData(v5, v1);
    LoadKartIconData();
}

#pragma thumb off
