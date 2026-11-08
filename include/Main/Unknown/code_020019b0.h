#pragma once

#include "types.h"

typedef struct Unk02001d30 Unk02001d30;

// Object whose halfword at 0x04 UpdateLogoScene clears.
typedef struct Unk02001a74 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mNextScene;
} Unk02001a74;

extern const char data_usa_ov001_021a768c[];
extern const char data_usa_ov001_021a76a8[];
extern const char data_usa_ov001_021a76c4[];
extern const char data_usa_ov001_021a76dc[];
extern const char data_usa_ov001_021a76f4[];
extern const char data_usa_ov001_021a770c[];
extern const char data_usa_ov001_021a7720[];

void UpdateLogoState0(void);
void EnterLogoState0(void);
void UpdateLogoScene(Unk02001a74 *sceneNumbers);
void WriteLogoSceneRegisters(void);
void ApplySavedSoundMode(void);
void InitLogoScene(void *heap);
void LoadBg1FromSceneFiles(Unk02001d30 *files, s32 mainScreen, const char *paletteFileName, const char *charsFileName,
                           const char *screenMapFileName);
