#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"
#include "registers.h"

const char *gBackScreenSNclrNames[1] = {"back_screen_s_b_00.nclr"};
const char *gBackScreenSNcgrNames[1] = {"back_screen_s_b_00.ncgr"};
const char *gBackScreenSNscrNames[1] = {"back_screen_s_bg_00.nscr"};
const char *gBackScreenMNscrNames[2] = {"back_screen_m_bg_00.nscr", "back_screen_m_bg_01.nscr"};
const char *gBackScreenMNcgrNames[2] = {"back_screen_m_b_00.ncgr", "back_screen_m_b_01.ncgr"};
const char *gBackScreenMNclrNames[2] = {"back_screen_m_b_00.nclr", "back_screen_m_b_01.nclr"};

#pragma thumb on

void LoadTxtSystemAndSelectChoisesAndSelectReturnData(void) {
    Unk02111684_v p;

    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        LoadNcgrData(&p.mNcgr, FindSceneFile("txt_system_b_00.ncgr"));
        LoadNscrData(&p.mNscr, FindSceneFile("txt_system_bg_00.nscr"));
        LoadNclrData(&p.mNclr, FindSceneFile("txt_system_b_00.nclr"));
    } else {
        LoadNcgrData(&p.mNcgr, func_02047a28("txt_system_b_00.ncgr"));
        LoadNcgrData(&p.mNcgr, func_02047a28("txt_system_b_01.ncgr"));
        LoadNscrData(&p.mNscr, func_02047a28("txt_system_bg_00.nscr"));
        LoadNscrData(&p.mNscr, func_02047a28("txt_system_bg_00_2.nscr"));
        LoadNscrData(&p.mNscr, func_02047a28("txt_system_bg_01.nscr"));
        LoadNscrData(&p.mNscr, func_02047a28("txt_system_bg_01_2.nscr"));
        LoadNscrData(&p.mNscr, func_02047a28("txt_system_bg_02.nscr"));
        LoadNscrData(&p.mNscr, func_02047a28("txt_system_bg_02_2.nscr"));
        LoadNscrData(&p.mNscr, func_02047a28("txt_system_bg_02_3.nscr"));
        LoadNclrData(&p.mNclr, func_02047a28("txt_system_b_00.nclr"));
        LoadNcgrData(&p.mNcgr, func_02047a28("select_choises_s_b.ncgr"));
        LoadNscrData(&p.mNscr, func_02047a28("select_choises_s_bg.nscr"));
        LoadNclrData(&p.mNclr, func_02047a28("select_choises_s_b.nclr"));
        LoadNcgrData(&p.mNcgr, func_02047a28("select_return_s_b_00.ncgr"));
        LoadNscrData(&p.mNscr, func_02047a28("select_return_s_bg_00.nscr"));
        LoadNclrData(&p.mNclr, func_02047a28("select_return_s_b_00.nclr"));
    }
}

void func_02125ba4(void) {
    u32 v;
    u32 w;

    v = (reg_GX_DISPCNT & 0x1f00) >> 8;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((v | 8) << 8);
    reg_G2_BG3CNT = (reg_G2_BG3CNT & ~3) | 3;
    reg_G2_BG3CNT = (reg_G2_BG3CNT & 0x43) | 0x1d18;
    w = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((w | 2) << 8);
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0xd00;
}

s32 func_02125960(s32 a) {
    s32 i;
    s32 nclrSOffset;
    s32 nclrSSize;
    Ncgr *ncgrM;
    Nscr *nscrM;
    Nclr *nclrM;
    Ncgr *ncgrS;
    Nscr *nscrS;
    Nclr *nclrS;
    s32 kind;
    u8 indexM;
    u8 indexS;
    s32 j;
    s32 nclrMOffset;
    s32 nclrMSize;

    kind = data_0217d3ec->mBackScreenKind;
    indexM = gBackScreenKindMIndices[kind * 2];
    indexS = gBackScreenKindSIndices[kind * 2];
    nclrMOffset = gBackScreenMNclrStarts[indexM] << 5;
    nclrMSize = (0xe - gBackScreenMNclrStarts[indexM]) << 5;
    nclrSOffset = gBackScreenSNclrStarts[indexS] << 5;
    nclrSSize = (0xc - gBackScreenSNclrStarts[indexS]) << 5;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        LocateNcgr(&ncgrM, FindSceneFile("common/select_race_rule_s_b.NCGR"));
        LoadNscrData(&nscrM, FindSceneFile("common/select_race_rule_download_bg_m.NSCR"));
        LocateNclr(&nclrM, FindSceneFile("common/select_race_rule_s_b.NCLR"));
        ncgrS = ncgrM;
        LoadNscrData(&nscrS, FindSceneFile("common/select_race_rule_download_bg_s.NSCR"));
        nclrS = nclrM;
    } else {
        if (data_0215d038[indexM] != 0) {
            LoadNcgrData(&ncgrM, func_02047a28(gBackScreenMNcgrNames[indexM]));
            LoadNscrData(&nscrM, func_02047a28(gBackScreenMNscrNames[indexM]));
            LoadNclrData(&nclrM, func_02047a28(gBackScreenMNclrNames[indexM]));
        } else {
            LoadNcgrData(&ncgrM, FindSceneFile(gBackScreenMNcgrNames[indexM]));
            LoadNscrData(&nscrM, FindSceneFile(gBackScreenMNscrNames[indexM]));
            LoadNclrData(&nclrM, FindSceneFile(gBackScreenMNclrNames[indexM]));
        }
        if (data_0215d038[indexS] != 0) {
            LoadNcgrData(&ncgrS, func_02047a28(gBackScreenSNcgrNames[indexS]));
            LoadNscrData(&nscrS, func_02047a28(gBackScreenSNscrNames[indexS]));
            LoadNclrData(&nclrS, func_02047a28(gBackScreenSNclrNames[indexS]));
        } else {
            LoadNcgrData(&ncgrS, FindSceneFile(gBackScreenSNcgrNames[indexS]));
            LoadNscrData(&nscrS, FindSceneFile(gBackScreenSNscrNames[indexS]));
            LoadNclrData(&nclrS, FindSceneFile(gBackScreenSNclrNames[indexS]));
        }
    }
    CallQueueAppend(7, 0, ncgrM->mData, ncgrM->mDataSize);
    CallQueueAppend(0xb, 0, nscrM->mData, nscrM->mDataSize);
    CallQueueAppend(0xf, nclrMOffset, (void *) ((u32) nclrM->mData + nclrMOffset), nclrMSize);
    a -= ncgrS->mDataSize;
    CallQueueAppend(0x15, a, ncgrS->mData, ncgrS->mDataSize);
    for (i = 0; i < 0x20; i++) {
        for (j = 0; j < 0x20; j++) {
            *(data_0217d3ec->mBackScreenSNscrCopy + i * 0x20 + j) = (a >> 5) + *((u16 *) nscrS->mData + i * 0x20 + j);
        }
    }
    CallQueueAppend(0x19, 0, data_0217d3ec->mBackScreenSNscrCopy, nscrS->mDataSize);
    CallQueueAppend(0x1f, nclrSOffset, (void *) ((u32) nclrS->mData + nclrSOffset), nclrSSize);
    return a;
}

#pragma thumb off
