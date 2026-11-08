#pragma once

#include "types.h"

typedef struct Bg1Files Bg1Files;

// Object whose halfword at 0x04 UpdateLogoScene clears.
typedef struct SceneNumbersView {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mNextScene;
} SceneNumbersView;

extern const char data_usa_ov001_021a768c[];
extern const char data_usa_ov001_021a76a8[];
extern const char data_usa_ov001_021a76c4[];
extern const char data_usa_ov001_021a76dc[];
extern const char data_usa_ov001_021a76f4[];
extern const char data_usa_ov001_021a770c[];
extern const char data_usa_ov001_021a7720[];

void UpdateLogoState0(void);
void EnterLogoState0(void);
void UpdateLogoScene(SceneNumbersView *sceneNumbers);
void WriteLogoSceneRegisters(void);
void ApplySavedSoundMode(void);
void InitLogoScene(void *heap);
void LoadBg1FromSceneFiles(Bg1Files *files, s32 mainScreen, const char *paletteFileName, const char *charsFileName,
                           const char *screenMapFileName);
