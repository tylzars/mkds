#include "Main/Unknown/code_020b4048.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b41d4.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void LoadFontAndPlayerCharacterData(void) {
    if (func_020b41d4(1) != 0) {
        func_020b478c(&gLCFontS, FindFileInLoadedArchives("LC_Font_s.NFTR"));
        func_020b478c(&gLCFontM, FindFileInLoadedArchives("LC_Font_m.NFTR"));
        func_020b478c(&gMarioFont, FindFileInLoadedArchives("marioFont.NFTR"));
        gFontTable[0] = &gLCFontS;
        gFontTable[1] = &gLCFontM;
        gFontTable[2] = &gMarioFont;
        LoadNclrData(gPlayerCharacterNclr, FindFileInLoadedArchives("player_character_M_o.NCLR"));
        LoadNclrData(gPlayerCharacterShyguyNclr, FindFileInLoadedArchives("player_character_M_shyguy_o.NCLR"));
        LoadNcgrData2(gPlayerCharacterNcgr, FindFileInLoadedArchives("player_character_M.nce.ncgr"));
        LoadNcerData(gPlayerCharacterNcer, FindFileInLoadedArchives("player_character_M.nce.ncer"));
        gPlayerCharacterBncl[0] = FindFileInLoadedArchives("player_character_M.bncl");
        LoadNclrData(&gPlayerCharacterLNclr, FindFileInLoadedArchives("player_character_L_o.NCLR"));
        LoadNclrData(&gPlayerCharacterLShyguyNclr, FindFileInLoadedArchives("player_character_L_shyguy_o.NCLR"));
        LoadNcgrData2(&gPlayerCharacterLNcgr, FindFileInLoadedArchives("player_character_L.nce.ncgr"));
        LoadNcerData(&gPlayerCharacterLNcer, FindFileInLoadedArchives("player_character_L.nce.ncer"));
        gPlayerCharacterBncl[1] = FindFileInLoadedArchives("player_character_L.bncl");
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
