#include "03/code_021d3298.h"
#include "03/unk_021da000.h"
#include "code_0214d018.h"
#include "pm.h"
#include "code_02148950.h"
#include "registers.h"

void SaveBankSettingsAndClearVram(void) {
    gSavedBankSettings[0] = GX_DisableBankForBG();
    gSavedBankSettings[1] = GX_DisableBankForOBJ();
    gSavedBankSettings[2] = GX_DisableBankForBGExtPltt();
    gSavedBankSettings[3] = GX_DisableBankForOBJExtPltt();
    gSavedBankSettings[4] = GX_DisableBankForTex();
    gSavedBankSettings[5] = GX_DisableBankForTexPltt();
    gSavedBankSettings[6] = GX_DisableBankForClearImage();
    gSavedBankSettings[7] = GX_DisableBankForSubBG();
    gSavedBankSettings[8] = GX_DisableBankForSubOBJ();
    gSavedBankSettings[9] = GX_DisableBankForSubBGExtPltt();
    gSavedBankSettings[10] = GX_DisableBankForSubOBJExtPltt();
    gSavedBankSettings[11] = GX_DisableBankForARM7();
    gSavedBankSettings[12] = GX_DisableBankForLCDC();
    GX_SetBankForARM7(gSavedBankSettings[11]);
    ResetVramOamAndPalettes();
}

void RestoreBankSettingsAndResetDisplay(void) {
    GX_DisableBankForBG();
    GX_DisableBankForOBJ();
    GX_DisableBankForSubBG();
    GX_DisableBankForSubOBJ();
    ResetVramOamAndPalettes();
    GX_SetBankForBG(gSavedBankSettings[0]);
    GX_SetBankForOBJ(gSavedBankSettings[1]);
    GX_SetBankForBGExtPltt(gSavedBankSettings[2]);
    GX_SetBankForOBJExtPltt(gSavedBankSettings[3]);
    GX_SetBankForTex(gSavedBankSettings[4]);
    GX_SetBankForTexPltt(gSavedBankSettings[5]);
    GX_SetBankForClearImage(gSavedBankSettings[6]);
    GX_SetBankForSubBG(gSavedBankSettings[7]);
    GX_SetBankForSubOBJ(gSavedBankSettings[8]);
    GX_SetBankForSubBGExtPltt(gSavedBankSettings[9]);
    GX_SetBankForSubOBJExtPltt(gSavedBankSettings[10]);
    GX_SetBankForLCDC(gSavedBankSettings[12]);
    reg_G2_BLDCNT = 0;
    reg_G2S_DB_BLDCNT = 0;
    reg_G2_BG0OFS = 0;
    reg_G2_BG1OFS = 0;
    reg_G2_BG2OFS = 0;
    reg_G2_BG3OFS = 0;
    reg_G2S_DB_BG0OFS = 0;
    reg_G2S_DB_BG1OFS = 0;
    reg_G2S_DB_BG2OFS = 0;
    reg_G2S_DB_BG3OFS = 0;
    PM_SetLCDPower(1);
}

void ResetVramOamAndPalettes(void) {
    vu32 mainOamFill;
    vu32 subOamFill;
    vu32 lcdcLowFill;
    vu32 lcdcHighFill;
    vu32 mainPaletteFill;
    vu32 subPaletteFill;

    GX_SetBankForLCDC(0x1f3);
    lcdcLowFill = 0;
    MIi_CpuClearFast(lcdcLowFill, (void *) 0x6800000, 0x40000);
    lcdcHighFill = 0;
    MIi_CpuClearFast(lcdcHighFill, (void *) 0x6880000, 0x24000);
    GX_DisableBankForLCDC();
    mainOamFill = 0x200;
    MIi_CpuClearFast(mainOamFill, (void *) 0x7000000, 0x400);
    mainPaletteFill = 0;
    MIi_CpuClearFast(mainPaletteFill, (void *) 0x5000000, 0x400);
    subOamFill = 0x200;
    MIi_CpuClearFast(subOamFill, (void *) 0x7000400, 0x400);
    subPaletteFill = 0;
    MIi_CpuClearFast(subPaletteFill, (void *) 0x5000400, 0x400);
}
