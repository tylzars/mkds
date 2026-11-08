#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02036000.h"

#include "Main/Unknown/code_0202bb80.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_0202a820.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b47d8.h"
#include "code_02148950.h"
#include "Main/Unknown/code_02025ebc.h"
#include "registers.h"

#pragma thumb on

void ReleasePlayerEntryList(void) {
    HeapDestroy(gPlayerEntryList->mHeap);
    *&gPlayerEntryList = NULL;
}

#pragma thumb off

#pragma thumb on

void WritePlayerEntryListRegisters(void) {
    u32 displayBits = 0x19;
    BOOL b;
    s16 interpolatedValue;

    interpolatedValue = GetInterpolatedValue(&gPlayerEntryList->mInterpolations[2]);
    if (gPlayerEntryList->mScreenKind == PLAYER_ENTRY_LIST_RACE_RULE) {
        b = FALSE;
        displayBits |= 2;
        reg_G2_BG0OFS = interpolatedValue & 0x1ff;
        reg_G2_BG1OFS = -interpolatedValue & 0x1ff;
        reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 3;
        reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    } else {
        b = TRUE;
    }
    if (gPlayerEntryList->mMode == 2) {
        displayBits |= 2;
    }
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (displayBits << 8);
    GX_SetGraphicsMode(1, 0, b);
    if (gPlayerEntryList->mScreenKind == PLAYER_ENTRY_LIST_RACE_RULE) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x6000;
        reg_G2_WININ = (u32) ((reg_G2_WININ & ~0x3f) | 0x1d) | 0x20;
        reg_G2_WININ = (u32) ((reg_G2_WININ & 0xffffc0ff) | 0x1e00) | 0x2000;
        reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0x1c) | 0x20;
        reg_G2_WIN0H = 0x80;
        reg_G2_WIN0V = 0xc0;
        reg_G2_WIN1H = 0x8000;
        reg_G2_WIN1V = 0xc0;
    } else {
        reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
    }
}

void LoadPlayerEntryListFiles(void) {
    Ncgr *chars;
    Nclr *palette;
    Unk02021dc8 *cells;
    Nscr *screenMap;

    if (*(vu16 *) 0x27ffc40 == 2) {
        LoadNcgrData(&chars, FindSceneFile(gSelectMenuEtcDownloadMBNcgrName));
        LoadNcgrData2(&chars, FindSceneFile(gSelectMenuEtcDownloadMNcgrName));
        LoadNcerData(&cells, FindSceneFile(gSelectMenuEtcDownloadMNcerName));
        LoadNclrData(&palette, FindSceneFile(gSelectMenuEtcDownloadMONclrName));
        LoadNclrData(&palette, FindSceneFile(gSelectMenuEtcDownloadMBNclrName));
        LoadNscrData(&screenMap, FindSceneFile(gSelectMenuEtcDownloadMBg00NscrName));
        LoadNscrData(&screenMap, FindSceneFile(gSelectMenuEtcDownloadMBg01NscrName));
    } else {
        LoadNcgrData(&chars, FindFileInLoadedArchives(gSelectMenuEtcMBNcgrName));
        LoadNcgrData2(&chars, FindFileInLoadedArchives(gSelectMenuEtcMNcgrName));
        LoadNcgrData2(&chars, FindFileInLoadedArchives(gSelectMenuEtcTitleMNcgrName));
        LoadNcerData(&cells, FindFileInLoadedArchives(gSelectMenuEtcMNcerName));
        LoadNcerData(&cells, FindFileInLoadedArchives(gSelectMenuEtcTitleMNcerName));
        LoadNclrData(&palette, FindFileInLoadedArchives(gSelectMenuEtcMONclrName));
        LoadNclrData(&palette, FindFileInLoadedArchives(gSelectMenuEtcMBNclrName));
        LoadNscrData(&screenMap, FindFileInLoadedArchives(gSelectMenuEtcMBg00NscrName));
        LoadNscrData(&screenMap, FindFileInLoadedArchives(gSelectMenuEtcMBg01NscrName));
    }
}

#pragma thumb off

#pragma thumb on

u32 IsPlayerEntryListTimerZero(void) {
    if (gPlayerEntryList->mTimer == 0) {
        return 1;
    }
    return 0;
}

u32 IsEveryPlayerKartStored(void) {
    u32 allKartsStored;
    int index;
    int offset;
    int setupCopy;
    allKartsStored = 1;
    index = 0;
    if (0 < gPlayerEntryList->mPlayerCount) {
        offset = 0;
        do {
            setupCopy = ((u32) GetRaceSetupCopy());
            allKartsStored = allKartsStored & ((RaceSetupCopy *) setupCopy)->mEntries[index].mUnk_14;
            offset = offset + 0x18;
            index = index + 1;
        } while (index < *(s32 *) (*(s32 *) &gPlayerEntryList + 0x48));
    }
    return allKartsStored;
}

#pragma thumb off

#pragma thumb on

void func_0202b7c0(s32 kind) {
    s32 i;

    func_02025f14(&gPlayerEntryList->mInterpolations[0], 2);
    func_02025f14(&gPlayerEntryList->mInterpolations[3], 2);
    func_02025f14(&gPlayerEntryList->mInterpolations[2], 2);
    switch (kind) {
        case 0:
        case 1:
            for (i = 0; i < 8; i++) {
                if (i < gPlayerEntryList->mPlayerCount || gPlayerEntryList->mUnk_208 != 0) {
                    SetEntryTargetSlot(i, 1);
                }
            }
            break;
        case 2:
            func_02025f14(&gPlayerEntryList->mInterpolations[1], 2);
            break;
        case 3:
            for (i = 0; i < 8; i++) {
                func_0202cb2c(i);
            }
            gPlayerEntryList->mUnk_20c = TRUE;
            break;
    }
}

void SetPlayerEntryListUseTeams(s32 useTeams) {
    s32 i;
    s32 slot;

    if (gPlayerEntryList->mUseTeams != useTeams) {
        if (useTeams != 0) {
            for (i = 0; i < 8; i++) {
                if (i < gPlayerEntryList->mPlayerCount || gPlayerEntryList->mUnk_208 != 0) {
                    if (gPlayerEntryList->mEntries[i].mTeamIndex == 0) {
                        slot = 1;
                    } else if (gPlayerEntryList->mEntries[i].mTeamIndex == 1) {
                        slot = 2;
                    }
                    SetEntryTargetSlot(i, slot);
                }
            }
            func_02025f14(&gPlayerEntryList->mInterpolations[2], 0);
            func_02025f14(&gPlayerEntryList->mInterpolations[0], 2);
        } else {
            for (i = 0; i < 8; i++) {
                if (i < gPlayerEntryList->mPlayerCount || gPlayerEntryList->mUnk_208 != 0) {
                    SetEntryTargetSlot(i, 1);
                }
            }
            func_02025f14(&gPlayerEntryList->mInterpolations[2], 2);
            func_02025f14(&gPlayerEntryList->mInterpolations[0], 0);
        }
    }
    gPlayerEntryList->mUseTeams = useTeams;
}

#pragma thumb off

#pragma thumb on

void SetEntryTeamIndex(int entryIndex, int teamIndex) {
    u32 slot;
    if ((gPlayerEntryList->mUseTeams != 0) && (teamIndex != gPlayerEntryList->mEntries[entryIndex].mTeamIndex)) {
        if (teamIndex == 1) {
            slot = 2;
        } else {
            slot = 1;
        }
        SetEntryTargetSlot(entryIndex, slot);
    }
    gPlayerEntryList->mEntries[entryIndex].mTeamIndex = teamIndex;
}

#pragma thumb off

#pragma thumb on

void func_0202b618(s32 a) {
    s32 i;
    s32 slot;
    if (gPlayerEntryList->mUnk_208 != a) {
        if (a != 0) {
            for (i = gPlayerEntryList->mPlayerCount; i < 8; i++) {
                if (gPlayerEntryList->mUseTeams != 0) {
                    if (gPlayerEntryList->mEntries[i].mTeamIndex == 1) {
                        slot = 3;
                    } else {
                        slot = 0;
                    }
                } else {
                    slot = 0;
                }
                SetEntrySlot(i, slot);
                func_0202cb68(i);
            }
        } else {
            for (i = gPlayerEntryList->mPlayerCount; i < 8; i++) {
                func_0202cb2c(i);
            }
        }
    }
    gPlayerEntryList->mUnk_208 = a;
}

#pragma thumb off

#pragma thumb on
void RequestPlayerEntryListSetup(void) {
    u32 value0;
    u32 entryList;
    u32 requested;
    requested = 1u;
    value0 = (u32) &gPlayerEntryList;
    entryList = *(const u32 *) ((value0) + 0u);
    value0 = 0x1fcu;
    *(u32 *) ((entryList) + (value0)) = requested;
}
#pragma thumb off
