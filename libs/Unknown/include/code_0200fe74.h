#pragma once

#include "types.h"

u32 OsCountZeroBits(u32 bitmap);

// Filled by OS_GetLowEntropyData.
typedef struct Unk0201000c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
} Unk0201000c;

// Top-level block: a count at 0x09 and, at 0x0e, the offset from 0x08 of a table of offsets to Unk020101e8.
typedef struct Unk02010168 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u8 mUnk_08[1];
    /* 09 */ u8 mUnk_09;
    /* 0a */ u8 mUnk_0a[4];
    /* 0e */ u16 mUnk_0e;
} Unk02010168;

// Object with, at 0x08, the offset from this object of an Unk020101e8_08.
typedef struct Unk020101e8 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08;
} Unk020101e8;

// Offsets (from this block) of two tables searched with func_020138b4 (mUnk_00 and mUnk_02), and at 0x0a the offset
// from 0x04 of a table of offsets to Unk020103c0_o and Unk020106c8_14.
typedef struct Unk020101e8_08 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[6];
    /* 0a */ u16 mUnk_0a;
} Unk020101e8_08;

// Table searched with func_020138b4: a count at 0x01 and at 0x06 the offset of a block holding the stride of the
// entries (0x00) and the offset of an array of 16-byte values (0x02); the entries start 4 bytes into that block.
typedef struct Unk02010294_t {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02[4];
    /* 06 */ u16 mUnk_06;
} Unk02010294_t;

// Block holding the stride of a table (0x00) and the offset of an array of 16-byte values (0x02).
typedef struct Unk02010310_d {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
} Unk02010310_d;

// Entry of a table: the offset of a byte list at 0x00, its length at 0x02 and a flag byte at 0x03 (bit 0 set by
// bindMdlPltt_Internal_ and bindMdlTex_Internal_, cleared by NNS_G3dReleaseMdlPlttEx, NNS_G3dReleaseMdlPltt and
// releaseMdlTex_Internal_).
typedef struct Unk020103c0_e {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk020103c0_e;

// Entry of the table of Unk02010294 at mUnk_34; bit 0 of mUnk_02 is tested.
typedef struct Unk020103c0_d {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
} Unk020103c0_d;

typedef struct Unk020103c0_o {
    /* 00 */ u8 mUnk_00[0x1c];
    /* 1c */ u16 mUnk_1c;
} Unk020103c0_o;

// Object with words at 0x08, 0x18 and 0x2c, at 0x34 the offset of a table searched with func_020138b4 and at 0x3c a
// table searched with it.
typedef struct Unk02010294 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c[0xc];
    /* 18 */ u32 mUnk_18;
    /* 1c */ u8 mUnk_1c[0x10];
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u8 mUnk_30[4];
    /* 34 */ u16 mUnk_34;
    /* 36 */ u8 mUnk_36[6];
    /* 3c */ u8 mUnk_3c[1];
} Unk02010294;

// Element of the table at Unk020101e8_08.mUnk_0a.
typedef struct Unk020106c8_14 {
    /* 00 */ u8 mUnk_00[0x14];
    /* 14 */ u32 mUnk_14;
    /* 18 */ u8 mUnk_18[8];
    /* 20 */ u16 mUnk_20;
    /* 22 */ u16 mUnk_22;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
} Unk020106c8_14;

// Fourth argument of bindMdlTex_Internal_: an entry found by func_020138b4.
typedef struct Unk020106c8_0c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk020106c8_0c;

// Bit k set: VRAM bank k (0 to 8) is locked.
extern u32 gVramBankLockedMask;
// Id that locked bank k; 0 when the bank is not locked.
extern u16 gVramBankLockIds[9];

// Under OS_DisableInterrupts: for each locked bank of bank & 0x1ff whose lock id equals lockId, clears the lock bit
// and the id. Other banks are left alone.
void OSi_UnlockVram(u32 bank, u16 lockId);
// Under OS_DisableInterrupts: returns 0 and changes nothing when a bank of bank is already locked with an id other
// than lockId. Otherwise locks every bank of bank & 0x1ff with lockId and returns 1.
u32 OSi_TryLockVram(u32 bank, u16 lockId);
// Sets the locked-bank mask and the nine bank lock ids to 0. Called once by the start-up function.
void OSi_InitVramExclusive(void);
void OS_GetLowEntropyData(Unk0201000c *buffer);
void NNS_G3dReleaseMdlSet(Unk02010168 *mdlSet);
u32 NNS_G3dBindMdlSet(Unk02010168 *mdlSet, Unk02010294 *tex);
u32 NNS_G3dReleaseMdlPlttEx(Unk020101e8 *mdl, const u32 *name);
void NNS_G3dReleaseMdlPltt(Unk020101e8 *mdl);
u32 NNS_G3dBindMdlPlttEx(Unk020101e8 *mdl, Unk02010294 *tex, const u32 *name);
u32 NNS_G3dBindMdlPltt(Unk020101e8 *mdl, Unk02010294 *tex);
void bindMdlPltt_Internal_(Unk020101e8_08 *mat, Unk020103c0_e *data, Unk02010294 *tex, Unk020103c0_d *plttData);
u32 NNS_G3dReleaseMdlTexEx(Unk020101e8 *mdl, const u32 *name);
void NNS_G3dReleaseMdlTex(Unk020101e8 *mdl);
int NNS_G3dBindMdlTexEx(Unk020101e8 *mdl, Unk02010294 *tex, const u32 *name);
int NNS_G3dBindMdlTex(Unk020101e8 *mdl, Unk02010294 *tex);
void releaseMdlTex_Internal_(Unk020101e8_08 *mat, Unk020103c0_e *data);
void bindMdlTex_Internal_(Unk020101e8_08 *mat, Unk020103c0_e *data, Unk02010294 *tex, Unk020106c8_0c *texData);
