#pragma once

#include "types.h"

char *BuildTeamEmblemNsbtxPath(s32 a);
char *BuildEmblemNsbtxPath(u16 a);
s8 *BuildPFaceanimNsbtpPath(void);
char *BuildCharacterDirPath(s32 a);
const char *LookupCharacterPOrEName(s32 a, s32 b);
char *BuildKartShadowNsbmdPath(u16 a);
char *BuildTireNsbtxPath(u16 a, const char *name);
char *BuildTireNsbmdPath(u16 a, const char *name);
char *BuildKartNsbtxPath(u16 a);
char *BuildKartNsbmdPath(u16 a);
char *BuildCharacterNsbtxPath(u16 a, s32 b);
char *BuildCharacterNsbmdPath(u16 a, s32 b);
void SetKartModelPathPrefix(int value);
