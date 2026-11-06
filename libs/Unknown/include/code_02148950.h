#pragma once

#include "types.h"

// Stores a in gSavedDispMode and replaces bits 0-3 and 16-19 of the main display word by (a << 16) | b | (c << 3); a is
// taken as 0 while gDispOn is 0, and gDispOn is cleared when a is 0.
void GX_SetGraphicsMode(u16 a, u32 b, s32 c);
// Main screen only: sets gDispOn; sets bit 16 of the main display word when gSavedDispMode is 0, otherwise writes
// gSavedDispMode into bits 16-17.
void GX_DispOn(void);
// Main screen only: saves bits 16-17 of the main display word in gSavedDispMode, clears gDispOn and clears those two
// bits.
void GX_DispOff(void);
// Sets (a != 0) or clears bit 3 of 0x4000004 and returns the previous value of that bit (0 or 8).
u32 GX_VBlankIntr(s32 a);
// Start-up, called once: sets bits 15, 1, 2, 3, 9 and 0 of 0x4000304, calls ClearVramBankState, then calls OS_GetLockID
// until gVramLockId is nonzero (halts in OS_Terminate when it returns -3), zeroes the registers 0x4000004,
// 0x4000000, 0x4000008-0x4000067, 0x400006c and 0x4001000-0x400106f (through MI_DmaFill32 when data_0216f074[0] is not
// -1, else MemFillWords) and stores 0x100 in the halfwords at offsets 0x20, 0x26, 0x30 and 0x36 of both display
// register blocks.
void GX_Init(void);
// Zeroes the 13 mask halfwords of gVramBankGroups and the bank control bytes 0x4000240-0x4000246, 0x4000248 and
// 0x4000249.
void ClearVramBankState(void);
// Returns the byte size of the sub sprite group's banks.
u32 GX_GetSizeOfSubOBJ(void);
// Returns the byte size of the sprite group's banks.
u32 GX_GetSizeOfOBJ(void);
// First clears bit 31 of the sub display word. Empties the SubOBJExtPltt group: its banks' control bytes are written 0
// and their lock-table entries owned by gVramLockId are cleared; returns the former mask.
u32 GX_DisableBankForSubOBJExtPltt(void);
// First clears bit 30 of the sub display word. Empties the SubBGExtPltt group: its banks' control bytes are written 0
// and their lock-table entries owned by gVramLockId are cleared; returns the former mask.
u32 GX_DisableBankForSubBGExtPltt(void);
// Empties the SubOBJ group: its banks' control bytes are written 0 and their lock-table entries owned by gVramLockId
// are cleared; returns the former mask.
u32 GX_DisableBankForSubOBJ(void);
// Empties the SubBG group: its banks' control bytes are written 0 and their lock-table entries owned by gVramLockId are
// cleared; returns the former mask.
u32 GX_DisableBankForSubBG(void);
// Empties the direct list: its banks' control bytes are written 0 and their lock-table entries owned by gVramLockId are
// cleared; returns the former mask.
u32 GX_DisableBankForLCDC(void);
// Empties the ARM7 group: its banks' control bytes are written 0 and their lock-table entries owned by gVramLockId are
// cleared; returns the former mask.
u32 GX_DisableBankForARM7(void);
// Empties the ClearImage group: its banks' control bytes are written 0 and their lock-table entries owned by
// gVramLockId are cleared; returns the former mask.
u32 GX_DisableBankForClearImage(void);
// Empties the TexPltt group: its banks' control bytes are written 0 and their lock-table entries owned by gVramLockId
// are cleared; returns the former mask.
u32 GX_DisableBankForTexPltt(void);
// Empties the Tex group: its banks' control bytes are written 0 and their lock-table entries owned by gVramLockId are
// cleared; returns the former mask.
u32 GX_DisableBankForTex(void);
// First clears bit 31 of the main display word. Empties the OBJExtPltt group: its banks' control bytes are written 0
// and their lock-table entries owned by gVramLockId are cleared; returns the former mask.
u32 GX_DisableBankForOBJExtPltt(void);
// First clears bit 30 of the main display word. Empties the BGExtPltt group: its banks' control bytes are written 0 and
// their lock-table entries owned by gVramLockId are cleared; returns the former mask.
u32 GX_DisableBankForBGExtPltt(void);
// Empties the OBJ group: its banks' control bytes are written 0 and their lock-table entries owned by gVramLockId are
// cleared; returns the former mask.
u32 GX_DisableBankForOBJ(void);
// Empties the BG group: its banks' control bytes are written 0 and their lock-table entries owned by gVramLockId are
// cleared; returns the former mask.
u32 GX_DisableBankForBG(void);
// Takes the bank mask stored at p, stores 0 there, writes 0 to the control byte of each of its banks, clears the
// lock-table entries of those banks that belong to the id in gVramLockId and returns the mask.
u32 ReleaseVramBankGroup(u16 *p);
// First clears bit 31 of the sub display word. Empties the SubOBJExtPltt group: its banks go to the direct list and are
// enabled in mode 0; returns the former mask.
u16 GX_ResetBankForSubOBJExtPltt(void);
// First clears bit 30 of the sub display word. Empties the SubBGExtPltt group: its banks go to the direct list and are
// enabled in mode 0; returns the former mask.
u16 GX_ResetBankForSubBGExtPltt(void);
// Empties the SubOBJ group: its banks go to the direct list and are enabled in mode 0; returns the former mask.
u16 GX_ResetBankForSubOBJ(void);
// Empties the SubBG group: its banks go to the direct list and are enabled in mode 0; returns the former mask.
u16 GX_ResetBankForSubBG(void);
// Empties the ClearImage group: its banks go to the direct list and are enabled in mode 0; returns the former mask.
u16 GX_ResetBankForClearImage(void);
// Empties the TexPltt group: its banks go to the direct list and are enabled in mode 0; returns the former mask.
u16 GX_ResetBankForTexPltt(void);
// Empties the Tex group: its banks go to the direct list and are enabled in mode 0; returns the former mask.
u16 GX_ResetBankForTex(void);
// First clears bit 31 of the main display word. Empties the OBJExtPltt group: its banks go to the direct list and are
// enabled in mode 0; returns the former mask.
u16 GX_ResetBankForOBJExtPltt(void);
// First clears bit 30 of the main display word. Empties the BGExtPltt group: its banks go to the direct list and are
// enabled in mode 0; returns the former mask.
u16 GX_ResetBankForBGExtPltt(void);
// Takes the bank mask stored at p, stores 0 there, adds the mask to the direct list (halfword 0 of the group table),
// writes the direct control bytes for it and returns the mask.
u16 SetVramBankGroupDirect(u16 *p);
// Same for the sub sprite extended-palette group: sets bit 31 of 0x4001000 and writes bank 8 in mode 3 (a = 0x100); a =
// 0 clears the bit.
void GX_SetBankForSubOBJExtPltt(u32 a);
// Same for the sub background extended-palette group: sets bit 30 of 0x4001000 and writes bank 7 in mode 2 (a = 0x80);
// a = 0 clears the bit.
void GX_SetBankForSubBGExtPltt(u32 a);
// Same for the sub sprite group: bank 3 in mode 4 (a = 8), bank 8 in mode 2 (a = 0x100).
void GX_SetBankForSubOBJ(u32 a);
// Same for the sub background group: bank 2 in mode 4 (a = 4), banks 7 (and 8) in mode 1 (a = 0x80, 0x180).
void GX_SetBankForSubBG(s32 a);
// Adds the banks of a to the direct list and writes the direct control byte for each. The game writes the banks through
// 0x6800000 afterwards.
void GX_SetBankForLCDC(u32 a);
// Same for the second-processor group: banks 2 and 3 in mode 2 (a = 4, 8, 12).
void GX_SetBankForARM7(s32 a);
// Same for the clear-image group: banks 0-3 in mode 3, sets bit 14 of 0x4000060 (cleared for a = 0).
void GX_SetBankForClearImage(u32 a);
// Same for the texture-palette group: banks 4-6 in mode 3.
void GX_SetBankForTexPltt(s32 a);
// Same for the texture group: banks 0-3 in mode 3, one texture slot per bank; sets bit 0 and clears bits 12-13 of
// 0x4000060; a = 0 clears those bits (mask 0xcffe).
void GX_SetBankForTex(u32 a);
// Same for the sprite extended-palette group: sets bit 31 of the main display word and writes bank 5 or 6 in mode 5; a
// = 0 clears the bit.
void GX_SetBankForOBJExtPltt(u32 a);
// Same for the background extended-palette group: sets bit 30 of the main display word and writes banks 4-6 in mode 4
// (a = 0x10, 0x20, 0x40, 0x60); a = 0 clears the bit.
void GX_SetBankForBGExtPltt(s32 a);
// Same for the sprite group: banks 0, 1, 4, 5, 6 in mode 2; a = 0 writes nothing.
void GX_SetBankForOBJ(s32 a);
// a is a set of banks (bit n = bank n, banks 0-6 allowed in the combinations the code lists). Moves the old background
// banks back to the direct list, removes a from it, stores a as the background group and writes the control bytes for a
// in mode 1.
void GX_SetBankForBG(s32 a);
// Writes 0x80 (on, mode 0) to the control byte of every bank whose bit (0 to 8) is set in a; the bytes are
// 0x4000240-0x4000246, 0x4000248 and 0x4000249.
void WriteVramControlDirect(u32 a);
