#include "Main/Unknown/code_020b4048.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020b41d4.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void LoadFontAndPlayerCharacterData(void) {
    if (func_020b41d4(1) != 0) {
        func_020b478c(&gLCFontS, func_02047a28("LC_Font_s.NFTR"));
        func_020b478c(&gLCFontM, func_02047a28("LC_Font_m.NFTR"));
        func_020b478c(&gMarioFont, func_02047a28("marioFont.NFTR"));
        gFontTable[0] = &gLCFontS;
        gFontTable[1] = &gLCFontM;
        gFontTable[2] = &gMarioFont;
        LoadNclrData(gPlayerCharacterNclr, func_02047a28("player_character_M_o.NCLR"));
        LoadNclrData(gPlayerCharacterShyguyNclr, func_02047a28("player_character_M_shyguy_o.NCLR"));
        LoadNcgrData2(gPlayerCharacterNcgr, func_02047a28("player_character_M.nce.ncgr"));
        LoadNcerData(gPlayerCharacterNcer, func_02047a28("player_character_M.nce.ncer"));
        gPlayerCharacterBncl[0] = func_02047a28("player_character_M.bncl");
        LoadNclrData(&gPlayerCharacterLNclr, func_02047a28("player_character_L_o.NCLR"));
        LoadNclrData(&gPlayerCharacterLShyguyNclr, func_02047a28("player_character_L_shyguy_o.NCLR"));
        LoadNcgrData2(&gPlayerCharacterLNcgr, func_02047a28("player_character_L.nce.ncgr"));
        LoadNcerData(&gPlayerCharacterLNcer, func_02047a28("player_character_L.nce.ncer"));
        gPlayerCharacterBncl[1] = func_02047a28("player_character_L.bncl");
    }
}

void ClearFontAndPlayerCharacterTables(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 3; i++) {
        gFontTable[i] = NULL;
    }
    for (j = 0; j < 2; j++) {
        gPlayerCharacterNclr[j] = NULL;
        gPlayerCharacterShyguyNclr[j] = NULL;
        gPlayerCharacterNcgr[j] = NULL;
        gPlayerCharacterNcer[j] = NULL;
        gPlayerCharacterBncl[j] = NULL;
    }
}
#pragma thumb off
