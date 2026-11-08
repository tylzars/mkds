#pragma once

#include "types.h"

extern u32 data_021653e4;

s32 AddBuddyFromFriendKey(const void *keyString, void *name);
s32 AddOrUpdateBuddyRecord(u8 *friendDataList, void *name, u8 *friendData, s32 notYetBuddy, s32 e, s32 allowAdd);
s32 FindBuddyIndexByFriendData(const void *friendData);
s32 CheckFriendKeyString(const void *keyString);
void FormatUserDataFriendKey(u32 buffer);
s32 func_02061250(void);
s32 CheckUserDataValidConsole(void);
void func_020612b0(void);
void StartReadGhostFileRecords(void *records);
void ReadGhostFileRecords(void);
