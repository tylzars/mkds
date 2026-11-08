#include "Main/Unknown/code_0202a734.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_02162000.h"

#pragma thumb on

void LoadWiFiVSCourseSelectFiles(void) {
    void *file;
    Ncgr *chars;
    Nclr *palette;
    Unk02021dc8 *cells;
    Nscr *screenMaps[1];
    chars = NULL;
    palette = NULL;
    cells = NULL;
    screenMaps[0] = NULL;
    file = FindSceneFile(data_021622f8);
    LoadNcgrData(&chars, file);
    file = FindSceneFile(data_02162318);
    LoadNcgrData(&chars, file);
    file = FindSceneFile(data_02162338);
    LoadNcgrData2(&chars, file);
    file = FindSceneFile(data_0216235c);
    LoadNcgrData2(&chars, file);
    file = FindSceneFile(data_02162380);
    LoadNcerData(&cells, file);
    file = FindSceneFile(data_021623a4);
    LoadNcerData(&cells, file);
    file = FindSceneFile(data_021623c8);
    LoadNclrData(&palette, file);
    file = FindSceneFile(data_021623e8);
    LoadNclrData(&palette, file);
    file = FindSceneFile(data_02162408);
    LoadNclrData(&palette, file);
    file = FindSceneFile(data_02162428);
    LoadNclrData(&palette, file);
    file = FindSceneFile(data_02162448);
    LoadNscrData(screenMaps, file);
    file = FindSceneFile(data_02162468);
    LoadNscrData(screenMaps, file);
}

#pragma thumb off
