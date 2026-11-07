#pragma once

#include "types.h"

void LoadKartAndCharacterFiles(void);

#include "Main/Unknown/code_020b4000.h" // Nclr

typedef struct Unk0217ad00_014 Unk0217ad00_014;
typedef struct KartModelMenuFiles KartModelMenuFiles;

typedef struct KartModelMenuSlot KartModelMenuSlot;

typedef struct KartModelMenuSlot KartModelMenuSlot;
typedef struct KartModelMenuView KartModelMenuView;

typedef struct NNSG3dResFileHeader NNSG3dResFileHeader;

typedef struct KartModelMenuView KartModelMenuView;

void InitKartModels(void *a, u32 b);

#include "Main/Unknown/code_020ed5c0.h" // KartModelsEntry

void LoadKartModelMenuFile(void *a, const void *b, void **c);
void CreateKillerItem(void *a);
void CreateKartShadow(KartModelsEntry *a, void *b);
void CreateTire(KartModelsEntry *a, void *b);
u16 *LoadKartAPaletteFromKartModelMenu(void *a);
u16 *LoadKartAPaletteFromKartModelFile(void);
void CreateKart(KartModelsEntry *a, void *b, s32 c);
void CreateCharacter(KartModelsEntry *a, void *b, s32 c);
void InitKartModels(void *a, u32 b);

// Declared here until the code that defines them is decompiled.

#include "Main/Unknown/code_020846c0.h" // Nsbmd

extern u8 data_usa_02154fe8[];
extern u32 data_usa_02155008[];
extern u32 data_usa_02155028[];
extern u32 data_usa_02155038[];
extern u32 data_usa_02155058[];
extern u32 data_usa_02155078[];
extern u32 data_usa_02155088[];
extern u32 data_usa_021550b8[];
extern u8 data_usa_021550c8[];
extern u8 data_usa_021550e8[];
extern u8 data_usa_02155108[];
extern u8 data_usa_02155128[];
extern u8 data_usa_02155148[];
extern Nclr *gEmblemSBNclr;
extern u8 *data_usa_0217acec;

void InitLnkVramManagers(void *a);
void AdvanceKartModelMenuLoad(void);
void InitKartModelMenuFiles(void *a, KartModelMenuFiles *b);
Nclr *GetEmblemSBNclr(void);
void AdvanceAngleToward(u16 *a, int b, u32 c);
void func_02077f48(unsigned int p0);
void func_02077f5c(void);
Unk0217ad00_014 *func_02077f7c(int param_1);
void func_02077f9c(int param_1, struct KartModelsEntry *param_2, Unk0217ad00_014 *param_3);
void func_0207800c(void);
void func_02078078(void);
void DrawKartModelMenuUnmirrored(void);
void DrawKartModelMenu(void);
void AdvanceKartModelMenuInput(void);
void func_020783c8(void);
void AdvanceKartModelMenu(s32 param_1);
void SetupKartModelEmblemTex(KartModelMenuSlot *a);
void DrawKartModelMenuSlot(KartModelMenuSlot *param_1, KartModelMenuView *param_2, s32 param_3);
void SetupLightFrustumAndLookAt(s32 param_1, s32 param_2);
void SetFrustumProjection(s32 param_1);
void StartKartModelMenuBg0Decrease(void);
void StartKartModelMenuBg0Increase(void);
void AdvanceKartModelMenuBg0Offset(void);
void RequestKartModelMenuKart(s32 param_1);
void RequestKartModelMenuCharacter(s32 param_1);
s16 *ComputeKartMenuParams(s32 param_1, s32 param_2);
void InitKartModelMenu(void *param_1);
void func_02078c58(void *param_1);
void func_02078d64(void *param_1);
void QueueKartEmblemTexture(void *param_1, void *param_2);
void InitKartModelMenuView(KartModelMenuView *a, int b);
void InitKartModelMenuSlot(void *a, KartModelMenuSlot *b);
void LoadKartModelMenuEmblemTexData(NNSG3dResFileHeader *a);
void LoadKartModelMenuSelectModel(void *c);
void *CreateKartModelMenuShadow(void *a, NNSG3dResFileHeader *b);
void CreateKartModelMenuTire(Nsbmd *a, NNSG3dResFileHeader *b, NNSG3dResFileHeader *c);
void CreateKartModelMenuKart(Nsbmd *a, NNSG3dResFileHeader *b, NNSG3dResFileHeader *c);
void CreateKartModelMenuCharacter(void *a, Nsbmd *b, void *c, NNSG3dResFileHeader *d, NNSG3dResFileHeader *e, void *f);
void func_020790e0(void *a, s32 b);
void UploadKartModelsEntryPalettes(KartModelsEntry *a, s32 b);
void UploadKartAPaletteSlice(Nsbmd *a, s32 b, void *c);
void func_02079678(void *a, s32 b);
void SetKartModelsEntryVariant(KartModelsEntry *a, int b);
void DrawKarts(void);
Kart *GetKart(s32 idx);
void GetKartPrevPos(Vec3 *dst, s32 idx);
void InitKarts(u32 a);
void UpdateKarts(void);
void SetMinKartDistanceSquared(s32 a);
s32 func_0207a4fc(void);
s32 func_0207a538(void);
BOOL func_0207a574(void);
void SetKartModelsFogEnable(s32 a);
// Returns the event counters of the selected entry's Kart.
EntryKartCounters *GetEntryKartCounters(void);
void func_0207a6c0(Kart *a);
void func_0207a70c(s32 a);
u32 func_0207a7fc(s32 a);
s32 func_0207a84c(s32 a);
// Copies mScale of Kart b to a.
void GetKartScale(Vec3 *a, s32 b);
void func_0207a91c(Vec3 *dst, u8 idx);
// Copies the position of Kart idx to dst, read through mPosSource (which points to mPos, or for a kind-3 entry in mode
// 5 to a Vec3 of the received record).
void GetKartPos(Vec3 *dst, s32 idx);
void func_0207a990(void);
// Runs slot 2 of Kart.mSlotFunctions for every Kart each time UpdateRace runs; the slot stores the Kart's squared
// distance in its sound source.
void UpdateKartSoundDistancesSquared(void);
