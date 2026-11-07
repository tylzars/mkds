#include "Main/Unknown/code_0202f554.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_02163000.h"

#pragma thumb on

void LoadMultiSelectFiles(void) {
    void *file;
    Ncgr *chars;
    Nclr *palette;
    Unk02021dc8 *cells;
    Nscr *screenMaps[1];
    chars = NULL;
    palette = NULL;
    cells = NULL;
    screenMaps[0] = NULL;
    file = FindSceneFile(data_02163280);
    LoadNcgrData(&chars, file);
    file = FindSceneFile(data_021632a0);
    LoadNcgrData2(&chars, file);
    file = FindSceneFile(data_021632c0);
    LoadNcgrData2(&chars, file);
    file = FindSceneFile(data_021632e8);
    LoadNcgrData2(&chars, file);
    file = FindSceneFile(data_02163310);
    LoadNcgrData2(&chars, file);
    file = FindSceneFile(data_0216332c);
    LoadNcerData(&cells, file);
    file = FindSceneFile(data_0216334c);
    LoadNcerData(&cells, file);
    file = FindSceneFile(data_02163374);
    LoadNcerData(&cells, file);
    file = FindSceneFile(data_0216339c);
    LoadNcerData(&cells, file);
    file = FindSceneFile(data_021633b8);
    LoadNclrData(&palette, file);
    file = FindSceneFile(data_021633d8);
    LoadNclrData(&palette, file);
    file = FindSceneFile(data_021633f8);
    LoadNclrData(&palette, file);
    file = FindSceneFile(data_0216341c);
    LoadNclrData(&palette, file);
    file = FindSceneFile(data_02163444);
    LoadNclrData(&palette, file);
    file = FindSceneFile(data_02163460);
    LoadNscrData(screenMaps, file);
    file = FindSceneFile(data_02163484);
    LoadNscrData(screenMaps, file);
}

#pragma thumb off
