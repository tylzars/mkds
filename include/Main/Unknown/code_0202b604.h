#pragma once

#include "types.h"

extern char gSelectMenuEtcDownloadMBNcgrName[];
extern char gSelectMenuEtcDownloadMNcgrName[];
extern char gSelectMenuEtcDownloadMNcerName[];
extern char gSelectMenuEtcDownloadMONclrName[];
extern char gSelectMenuEtcDownloadMBNclrName[];
extern char gSelectMenuEtcDownloadMBg00NscrName[];
extern char gSelectMenuEtcDownloadMBg01NscrName[];
extern char gSelectMenuEtcMBNcgrName[];
extern char gSelectMenuEtcMNcgrName[];
extern char gSelectMenuEtcTitleMNcgrName[];
extern char gSelectMenuEtcMNcerName[];
extern char gSelectMenuEtcTitleMNcerName[];
extern char gSelectMenuEtcMONclrName[];
extern char gSelectMenuEtcMBNclrName[];
extern char gSelectMenuEtcMBg00NscrName[];
extern char gSelectMenuEtcMBg01NscrName[];

void RequestPlayerEntryListSetup(void);
void func_0202b618(s32 a);
void SetEntryTeamIndex(int entryIndex, int teamIndex);
void SetPlayerEntryListUseTeams(s32 useTeams);
void func_0202b7c0(s32 kind);
u32 IsEveryPlayerKartStored(void);
u32 IsPlayerEntryListTimerZero(void);
void LoadPlayerEntryListFiles(void);
void WritePlayerEntryListRegisters(void);
void ReleasePlayerEntryList(void);
