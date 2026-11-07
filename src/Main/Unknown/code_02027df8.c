#include "Main/Unknown/code_02027df8.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_02161000.h"

#pragma thumb on

void func_02027df8(void) {
    void *fileData;
    Ncgr *chars;
    Nclr *palette;
    Unk02021dc8 *cells;
    Nscr *screenMap[1];
    chars = NULL;
    palette = NULL;
    cells = NULL;
    screenMap[0] = NULL;
    fileData = FindFileInLoadedArchives(data_02161e64);
    LoadNcgrData(&chars, fileData);
    fileData = FindFileInLoadedArchives(data_02161e7c);
    LoadNcgrData2(&chars, fileData);
    fileData = FindFileInLoadedArchives(data_02161e94);
    LoadNcerData(&cells, fileData);
    fileData = FindFileInLoadedArchives(data_02161eac);
    LoadNclrData(&palette, fileData);
    fileData = FindFileInLoadedArchives(data_02161ec4);
    LoadNclrData(&palette, fileData);
    fileData = FindFileInLoadedArchives(data_02161edc);
    LoadNscrData(screenMap, fileData);
}

#pragma thumb off
