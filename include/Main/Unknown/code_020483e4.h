#pragma once

#include "types.h"

typedef struct NNSiFndHeapHead NNSiFndHeapHead;

// 8-byte entries of two words: a string and a number.
typedef struct Unk02154228 {
    /* 00 */ const char *mUnk_00;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05[0x3];
} Unk02154228;

extern Unk02154228 data_usa_02154228[];
extern const char data_usa_02165164[];
extern const char data_usa_02165168[];
extern const char data_usa_0216516c[];
extern const char data_usa_02165170[];
extern const char data_usa_02165174[];

void BuildSceneArchivePath(char *path, const char *sceneName);
void BuildSceneArchivePathWithLanguage(char *path, const char *sceneName);
u32 GetMPLanguageCode(void);
u32 GetLanguageCode(void);
void BuildCourseArchivePath(char *path, s32 courseId, s32 useTexture);
void *LoadFileAligned(const char *path, s32 alignment);
u32 LoadFileIntoHeap(char *path, NNSiFndHeapHead *heap, void **outData);
u32 ReadFileBytes(void *path, void *buffer, u32 size);
int ReadWholeFile(const char *path, void *buffer, u32 maxSize);
void InitArchiveSlots(void *heap);
