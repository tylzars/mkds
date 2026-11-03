#include "Main/Unknown/code_0202f554.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_02163000.h"

#pragma thumb on

void func_0202f554(void) {
    void *v1;
    Unk020b4934 *v2;
    Unk020b4a44 *v3;
    Unk02021dc8 *v4;
    Unk020b47d8 *v5[1];
    v2 = NULL;
    v3 = NULL;
    v4 = NULL;
    v5[0] = NULL;
    v1 = FindSceneFile(data_02163280);
    LoadNcgrData(&v2, v1);
    v1 = FindSceneFile(data_021632a0);
    LoadNcgrData2(&v2, v1);
    v1 = FindSceneFile(data_021632c0);
    LoadNcgrData2(&v2, v1);
    v1 = FindSceneFile(data_021632e8);
    LoadNcgrData2(&v2, v1);
    v1 = FindSceneFile(data_02163310);
    LoadNcgrData2(&v2, v1);
    v1 = FindSceneFile(data_0216332c);
    LoadNcerData(&v4, v1);
    v1 = FindSceneFile(data_0216334c);
    LoadNcerData(&v4, v1);
    v1 = FindSceneFile(data_02163374);
    LoadNcerData(&v4, v1);
    v1 = FindSceneFile(data_0216339c);
    LoadNcerData(&v4, v1);
    v1 = FindSceneFile(data_021633b8);
    LoadNclrData(&v3, v1);
    v1 = FindSceneFile(data_021633d8);
    LoadNclrData(&v3, v1);
    v1 = FindSceneFile(data_021633f8);
    LoadNclrData(&v3, v1);
    v1 = FindSceneFile(data_0216341c);
    LoadNclrData(&v3, v1);
    v1 = FindSceneFile(data_02163444);
    LoadNclrData(&v3, v1);
    v1 = FindSceneFile(data_02163460);
    LoadNscrData(v5, v1);
    v1 = FindSceneFile(data_02163484);
    LoadNscrData(v5, v1);
}

#pragma thumb off
