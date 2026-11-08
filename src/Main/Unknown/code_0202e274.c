#include "Main/Unknown/code_0202e274.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0211732c.h"
#include "Main/Unknown/unk_02162000.h"
#include "Main/Unknown/unk_02163000.h"

#pragma thumb on

// Unpacks the Chars, Cells, Palette and ScreenMap files of the ghost scene in place; nothing is kept.
void LoadGhostSceneFiles(void) {
    void *file;
    Ncgr *chars;
    Nclr *palette;
    Unk02021dc8 *cells;
    Nscr *screenMaps[1];
    chars = NULL;
    palette = NULL;
    cells = NULL;
    screenMaps[0] = NULL;
    file = FindSceneFile(gTimeAttackGhostGetMBNcgrName);
    LoadNcgrData(&chars, file);
    file = FindSceneFile(gTimeAttackGhostGetSBNcgrName);
    LoadNcgrData(&chars, file);
    file = FindSceneFile(data_02162f98);
    LoadNcgrData(&chars, file);
    file = FindSceneFile(data_02162fb8);
    LoadNcgrData(&chars, file);
    file = FindSceneFile(gTimeAttackGhostGetMNcgrName);
    LoadNcgrData2(&chars, file);
    file = FindSceneFile(gTimeAttackGhostGetSNcgrName);
    LoadNcgrData2(&chars, file);
    file = FindSceneFile(data_02163018);
    LoadNcgrData2(&chars, file);
    file = FindSceneFile(data_0216303c);
    LoadNcgrData2(&chars, file);
    file = FindSceneFile(gTimeAttackGhostGetMNcerName);
    LoadNcerData(&cells, file);
    file = FindSceneFile(gTimeAttackGhostGetSNcerName);
    LoadNcerData(&cells, file);
    file = FindSceneFile(data_021630a0);
    LoadNcerData(&cells, file);
    file = FindSceneFile(data_021630c4);
    LoadNcerData(&cells, file);
    file = FindSceneFile(gTimeAttackGhostGetMBNclrName);
    LoadNclrData(&palette, file);
    file = FindSceneFile(gTimeAttackGhostGetMONclrName);
    LoadNclrData(&palette, file);
    file = FindSceneFile(gTimeAttackGhostGetSBNclrName);
    LoadNclrData(&palette, file);
    file = FindSceneFile(gTimeAttackGhostGetSONclrName);
    LoadNclrData(&palette, file);
    file = FindSceneFile(data_02163168);
    LoadNclrData(&palette, file);
    file = FindSceneFile(data_02163188);
    LoadNclrData(&palette, file);
    file = FindSceneFile(data_021631a8);
    LoadNclrData(&palette, file);
    file = FindSceneFile(data_021631c8);
    LoadNclrData(&palette, file);
    file = FindSceneFile(gTimeAttackGhostGetMNscrName);
    LoadNscrData(screenMaps, file);
    file = FindSceneFile(gTimeAttackGhostGetSNscrName);
    LoadNscrData(screenMaps, file);
    file = FindSceneFile(data_02163220);
    LoadNscrData(screenMaps, file);
    file = FindSceneFile(data_02163240);
    LoadNscrData(screenMaps, file);
    LoadKartIconData();
}

#pragma thumb off
