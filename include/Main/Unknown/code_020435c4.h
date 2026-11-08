#pragma once

#include "types.h"

// The pair of input bits the item code tests to use the held item.
#define ITEM_BITS 0x600
// Item input bit held while the item is used: the held item is thrown in front of the kart.
#define ITEM_THROW_FORWARD_BIT 0x40

typedef struct MissionFileRow MissionFileRow;

u32 func_020435c4(void);
void SetInputOpenDuringRace(u32 openDuringRace);
void RequestBits(s32 slotIndex, u32 bits);
void func_02043648(void);
unsigned int GetPadKeys(void);
void func_02043a34(void);
void SetLeftRightKeysSwapped(u32 mirrorMode);
void func_02043ad4(void);
void func_02043ae0(void);
void func_02043b04(void);
void func_02043b3c(void);
void func_02043b48(void);
void ResetInputSlots(void);
void func_02043d10(void *heap);
void func_02043f28(u32 a);
void func_02043fb0(u32 courseId);
void func_02044060(u32 courseId);
void func_0204419c(u32 courseId, u32 b);
void func_020442d0(u32 courseId);
void func_02044380(MissionFileRow *missionFileRow, u32 tableRow, u32 tableColumn);
void func_0204451c(u32 entryIndex);
