#pragma once

#include "types.h"

unsigned int func_02057fe4(unsigned int value);
void UpdateMPState14(void);
u32 EnterMPState14(void);
void UpdateMPState13(void);
void EnterMPState13(void);
void UpdateMPState12(void);
void EnterMPState12(void);
void UpdateMPState11(void);
void EnterMPState11(void);
void UpdateMPState10(void);
void EnterMPState10(void);
void UpdateMPState9(void);
void EnterMPState9(void);
void UpdateMPState8(void);
BOOL GetEntryChunk(u8 *entry, s32 chunkIndex, s32 chunkSize, u8 **outChunk, u16 *outSize);
BOOL QueueMPChunk(u8 chunkNumber, u8 *data, u16 size, u8 playerIndex, u8 destBitmap);
u32 func_02058754(void);
void EnterMPState8(void);
void UpdateMPState7(void);
void EnterMPState7(void);
void UpdateMPState4(void);
void EnterMPState4(void);
void UpdateMPState2(void);
void EnterMPState2(void);
void UpdateMPState1(void);
void UpdateMPState3(void);
void EnterMPState3(void);
void UpdateMPState6(void);
void UpdateMPState5(void);
void func_02058b10(void);
