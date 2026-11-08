#pragma once

#include "types.h"

void LoadKartAndCharacterFiles(void);

#include "Main/Unknown/code_020b4000.h" // Nclr

typedef struct HeyhoPalette HeyhoPalette;
typedef struct KartModelMenuFiles KartModelMenuFiles;

typedef struct KartModelMenuSlot KartModelMenuSlot;

typedef struct KartModelMenuSlot KartModelMenuSlot;
typedef struct KartModelMenuView KartModelMenuView;

typedef struct NNSG3dResFileHeader NNSG3dResFileHeader;

typedef struct KartModelMenuView KartModelMenuView;

void InitKartModels(void *heap, u32 kartCount);

#include "Main/Unknown/code_020ed5c0.h" // KartModelsEntry

void LoadKartModelMenuFile(void *heap, const void *fileName, void **file);
void CreateKillerItem(void *heap);
void CreateKartShadow(KartModelsEntry *kartModelsEntry, void *heap);
void CreateTire(KartModelsEntry *kartModelsEntry, void *heap);
u16 *LoadKartAPaletteFromKartModelMenu(void *heap);
u16 *LoadKartAPaletteFromKartModelFile(void);
void CreateKart(KartModelsEntry *kartModelsEntry, void *heap, s32 pNameUsed);
void CreateCharacter(KartModelsEntry *kartModelsEntry, void *heap, s32 pNameUsed);
void InitKartModels(void *heap, u32 kartCount);

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

void InitLnkVramManagers(void *heap);
void AdvanceKartModelMenuLoad(void);
void InitKartModelMenuFiles(void *heap, KartModelMenuFiles *files);
Nclr *GetEmblemSBNclr(void);
void AdvanceAngleToward(u16 *angle, int targetAngle, u32 easeFactor);
void func_02077f48(unsigned int flag);
void func_02077f5c(void);
HeyhoPalette *GetHeyhoPalette(int kartIndex);
void UploadHeyhoPalette(int kartIndex, struct KartModelsEntry *kartModelsEntry, HeyhoPalette *palette);
void SetupHeyhoPalettes(void);
void CopyHeyhoPaletteIndices(void);
void DrawKartModelMenuUnmirrored(void);
void DrawKartModelMenu(void);
void AdvanceKartModelMenuInput(void);
void AdvanceShownSlotAndQueueEmblem(void);
void AdvanceKartModelMenu(s32 mirrorMode);
void SetupKartModelEmblemTex(KartModelMenuSlot *slot);
void DrawKartModelMenuSlot(KartModelMenuSlot *slot, KartModelMenuView *view, s32 mirrored);
void SetupLightFrustumAndLookAt(s32 param_1, s32 yOffset);
void SetFrustumProjection(s32 mirrored);
void StartKartModelMenuBg0Decrease(void);
void StartKartModelMenuBg0Increase(void);
void AdvanceKartModelMenuBg0Offset(void);
void RequestKartModelMenuKart(s32 kartIndex);
void RequestKartModelMenuCharacter(s32 characterIndex);
s16 *ComputeKartMenuParams(s32 kartIndex, s32 characterIndex);
void InitKartModelMenu(void *heap);
void func_02078c58(void *heap);
void func_02078d64(void *heap);
void QueueKartEmblemTexture(void *emblemData, void *emblemPalette);
void InitKartModelMenuView(KartModelMenuView *view, int b);
void InitKartModelMenuSlot(void *heap, KartModelMenuSlot *slot);
void LoadKartModelMenuEmblemTexData(NNSG3dResFileHeader *file);
void LoadKartModelMenuSelectModel(void *heap);
void *CreateKartModelMenuShadow(void *shadowModel, NNSG3dResFileHeader *modelFile);
void CreateKartModelMenuTire(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile);
void CreateKartModelMenuKart(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile);
void CreateKartModelMenuCharacter(void *heap, Nsbmd *nsbmd, void *animation, NNSG3dResFileHeader *modelFile,
                                  NNSG3dResFileHeader *textureFile, void *animationFile);
void func_020790e0(void *heap, s32 createKartAppear);
void UploadKartModelsEntryPalettes(KartModelsEntry *kartModelsEntry, s32 pNameUsed);
void UploadKartAPaletteSlice(Nsbmd *nsbmd, s32 kartIndex, void *kartAPalette);
void func_02079678(void *heap, s32 firstPass);
void SetKartModelsEntryVariant(KartModelsEntry *kartModelsEntry, int kartIndex);
void DrawKarts(void);
Kart *GetKart(s32 idx);
void GetKartPrevPos(Vec3 *dst, s32 idx);
void InitKarts(u32 kartCount);
void UpdateKarts(void);
void SetMinKartDistanceSquared(s32 distanceSquared);
BOOL func_0207a4fc(void);
BOOL func_0207a538(void);
BOOL func_0207a574(void);
void SetKartModelsFogEnable(s32 fogEnableFlag);
// Returns the event counters of the selected entry's Kart.
EntryKartCounters *GetEntryKartCounters(void);
void func_0207a6c0(Kart *kart);
void func_0207a70c(s32 kartIndex);
BOOL func_0207a7fc(s32 kartIndex);
s32 func_0207a84c(s32 kartIndex);
// Copies mScale of Kart b to a.
void GetKartScale(Vec3 *scale, s32 kartIndex);
void func_0207a91c(Vec3 *dst, u8 idx);
// Copies the position of Kart idx to dst, read through mPosSource (which points to mPos, or for a kind-3 entry in mode
// 5 to a Vec3 of the received record).
void GetKartPos(Vec3 *dst, s32 idx);
void func_0207a990(void);
// Runs slot 2 of Kart.mSlotFunctions for every Kart each time UpdateRace runs; the slot stores the Kart's squared
// distance in its sound source.
void UpdateKartSoundDistancesSquared(void);
