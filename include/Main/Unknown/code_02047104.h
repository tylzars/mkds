#pragma once

#include "types.h"

void *LoadKartModelFile(const char *path);
void *FindKartModelFile(const char *path);
void *FindCourseFile(const char *path);
void *FindSceneFile(const char *name);
void *FindMainRaceOrMainEffectFile(const char *path);
void *FindArchiveFile(u32 archiveName, const char *path);

// 0x18-byte entries.
typedef struct ArchiveSlotInfo {
    /* 00 */ const char *mPath;
    /* 04 */ s32 mNextSlot;
    /* 08 */ s8 mBufferIndex;
    /* 09 */ u8 mUnk_09[0x3];
    /* 0c */ s32 mUncompressSource;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
} ArchiveSlotInfo;

// 8-byte entries of a string and a number.
typedef struct SceneName {
    /* 00 */ const char *mName;
    /* 04 */ s32 mUnk_04;
} SceneName;

#include "Main/Unknown/unk_02175000.h"

// The scene-name table, 16 rows indexed by scene number like gSceneFuncs: 0 'Title', 1 'Menu', 2 'Race', 3 'Emblem',
// 4 'Menu', 5 'Test', 6 'WLMenu', 7 'Option', 8 'Record', 9 'Logo', 10 'Result', 11 'Nickname', 12 'WiFiMenu',
// 13 'Ghost', 14 'Keyboard', 15 'Ending'.
extern SceneName gSceneNames[];
extern ArchiveSlotInfo gArchiveSlotInfos[];
extern const char data_usa_02165008[];
extern const char data_usa_02165010[];
extern const char data_usa_02165018[];
extern const char data_usa_02165020[];
extern const char data_usa_02165028[];
extern const char data_usa_02165030[];
extern const char data_usa_02165038[];
extern const char data_usa_02165040[];
extern const char gStaffRollArchivePath[];
extern const char data_usa_021650e0[];
extern const char data_usa_021650e4[];
extern const char gResultLanguageArchivePathFormat[];
extern const char data_usa_02165100[];
extern const char data_usa_02165108[];
extern const char data_usa_0216510c[];
extern const char gResultArchivePathFormat[];
extern const char data_usa_02165124[];

void InitTouchMicInput(void *heap);
void InitTouchPanelAndSetCalibration(void);
void func_020471b0(void *heap);
void ResizeMainEffectArchiveBlock(u8 *a, u32 b);
s32 func_02047250(void);
void func_02047274(void);
void RequestResultDLArchives(void);
void RequestRaceArchives(void *courseId, void *b);
void RequestMenuDLArchives(void);
void func_020473e4(void);
void RequestArchiveLoadWithLanguage(const void *prefix, u32 bufferIndex);
void RequestArchiveLoad(const void *path, s32 bufferIndex);
void func_020474e4(void);
void InitArchiveBuffers(NNSiFndHeapHead *a, NNSiFndHeapHead *courseBufferHeap, NNSiFndHeapHead *c);
void InitArchiveBuffer(NNSiFndHeapHead *heap, s32 bufferIndex, s32 c, u32 uncompress, u32 e);
void func_020476ac(void);
void func_020476ec(void);
void func_02047728(void);
void func_0204775c(void);
void *func_02047950(const char *path);
void *FindFileInLoadedArchives(const char *name);
void SetHeapGroupId(u32 groupId);
void ReleaseArchiveSlots(void);
void LoadArchiveSlotsForScene(s32 sceneNumber);
void ReleaseArchiveSlot(int slotIndex);
void LoadArchiveSlotData(void);
void UncompressArchiveMemory(void);
void UncompressArchiveFile(void);
void LoadArchiveSlot(s32 slotIndex, const char *path, u32 *sourceData, void *data, s32 e, s32 uncompressSource, s32 g);
void LoadArchiveSlotForScene(int slotIndex, int sceneNumber);
void BuildArchivePathWithLanguage(const char *prefix, char *path);
void BuildSceneModeLanguageArchivePath(char *path, const char *sceneName, int mode);
void BuildSceneModeArchivePath(char *path, const char *sceneName, int mode);
void BuildStaffRollArchivePath(char *path);
void BuildResultArchivePathWithLanguage(char *path);
void BuildResultArchivePath(char *path);
