#pragma once

#include "types.h"
#include "code_0201c528.h"

// Word at Unk020184e4_2c 0x0c and Unk020184e4_2c_00 0x04.
typedef struct Unk020184e4_2c_0c {
    /* 00 */ u32 mUnk_00_0 : 4;
    /* 00 */ u32 mUnk_00_4 : 4;
    /* 00 */ u32 mUnk_00_8 : 4;
    /* 00 */ u32 mUnk_00_12 : 2;
    /* 00 */ u32 mUnk_00_14 : 2;
    /* 00 */ u32 mUnk_00_16 : 1;
    /* 00 */ u32 mUnk_00_17 : 1;
    /* 00 */ u32 mUnk_00_18 : 8;
    /* 00 */ u32 mUnk_00_26 : 6;
} Unk020184e4_2c_0c;

// Header of an entry of the table at Unk020184e4 0x2c.
typedef struct Unk020184e4_2c_00 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Unk020184e4_2c_0c mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u8 mUnk_14[8];
    /* 1c */ s32 mUnk_1c;
} Unk020184e4_2c_00;

// Entries of the table at Unk020184e4 0x2c (0x14 bytes each, count at 0x32).
typedef struct Unk020184e4_2c {
    /* 00 */ Unk020184e4_2c_00 *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ Unk020184e4_2c_0c mUnk_0c;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
} Unk020184e4_2c;

// First bytes of the data SPLManager_LoadResources reads.
typedef struct Unk02018a1c {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
} Unk02018a1c;

typedef struct Unk020184e4 {
    /* 00 */ void *(*mUnk_00)(u32 a);
    /* 04 */ Unk0201e494 mUnk_04[3];
    /* 28 */ Unk0201ca6c_20 *mUnk_28;
    /* 2c */ Unk020184e4_2c *mUnk_2c;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u16 mUnk_32;
    /* 34 */ s16 mUnk_34;
    /* 36 */ s16 mUnk_36;
    /* 38 */ u32 mUnk_38_0 : 6;
    /* 38 */ u32 mUnk_38_6 : 6;
    /* 38 */ u32 mUnk_38_12 : 6;
    /* 38 */ u32 mUnk_38_18 : 6;
    /* 38 */ u32 mUnk_38_24 : 1;
    /* 38 */ u32 mUnk_38_25 : 7;
    /* 3c */ u32 mUnk_3c;
    /* 40 */ Unk0201ca6c *mUnk_40;
    /* 44 */ MtxFx43 *mUnk_44;
    /* 48 */ u16 mUnk_48;
} Unk020184e4;

// Entries of the two local call tables of SPLEmitter_Update.
typedef struct Unk020192e0_28 {
    /* 00 */ void (*mUnk_00)(Unk0201e3c8 *p, Unk0201ca6c_20 *q, s32 v);
    /* 04 */ u32 mUnk_04;
} Unk020192e0_28;

void SPLManager_DeleteEmitter(Unk020184e4 *mgr, Unk0201ca6c *emtr);
Unk0201ca6c *SPLManager_CreateEmitterWithCallbackEx(Unk020184e4 *mgr, s32 resourceId, Vec3 *pos, s32 param,
                                                    void (*initCallback)(Unk0201ca6c *emtr, s32 param));
Unk0201ca6c *SPLManager_CreateEmitter(Unk020184e4 *mgr, s32 resourceId, Vec3 *pos);
void SPLManager_Draw(Unk020184e4 *mgr, MtxFx43 *viewMatrix);
void SPLManager_Update(Unk020184e4 *mgr);
s32 SPLManager_UploadPalettes(Unk020184e4 *mgr);
s32 SPLManager_UploadTextures(Unk020184e4 *mgr);
s32 SPLManager_UploadPalettesEx(Unk020184e4 *mgr, u32 (*vramAlloc)(s32 size, s32 isSpecial));
s32 SPLManager_UploadTexturesEx(Unk020184e4 *mgr, u32 (*vramAlloc)(s32 size, s32 isSpecial));
void SPLManager_LoadResources(Unk020184e4 *mgr, Unk02018a1c *data);
Unk020184e4 *SPLManager_New(void *(*alloc)(u32 size), u16 maxEmitters, u16 maxParticles, s32 fixPolyId, u16 minPolyId,
                            u16 maxPolyId);
u32 SPLUtil_AllocPaletteVRAM(s32 size, s32 is4Pltt);
u32 SPLUtil_AllocTextureVRAM(s32 size, s32 is4x4);
void SPLUtil_SetCylinderEmitterDir(Unk0201ca6c *emtr, Vec3 *p1, Vec3 *p2);
void SPLManager_DoDraw(Unk020184e4 *mgr);
void SPLManager_DrawChildParticles(Unk020184e4 *mgr);
void SPLManager_DrawParticles(Unk020184e4 *mgr);
void SPLEmitter_Update(Unk020184e4 *mgr, Unk0201ca6c *b);
void SPLEmitter_Init(Unk0201ca6c *emtr, Unk0201ca6c_20 *res, Vec3 *pos);
void SPLUtil_SetTexture_Stub(Unk020184e4_2c *tex);
void SPLUtil_SetTexture(Unk020184e4_2c *tex);
void SPLDraw_Child_DirectionalPolygon(Unk020184e4 *mgr, Unk0201e3c8 *ptcl);
void SPLDraw_DirectionalPolygon(Unk020184e4 *mgr, Unk0201e3c8 *ptcl);
void SPLDraw_Child_Polygon(Unk020184e4 *mgr, Unk0201e3c8 *ptcl);
void SPLDraw_Polygon(Unk020184e4 *mgr, Unk0201e3c8 *ptcl);
void SPLDraw_Child_DirectionalBillboard(Unk020184e4 *mgr, Unk0201e3c8 *ptcl);
void SPLDraw_DirectionalBillboard(Unk020184e4 *mgr, Unk0201e3c8 *ptcl);
void SPLDraw_Child_Billboard(Unk020184e4 *mgr, Unk0201e3c8 *ptcl);
void SPLDraw_Billboard(Unk020184e4 *mgr, Unk0201e3c8 *ptcl);
