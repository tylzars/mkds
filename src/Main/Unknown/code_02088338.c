#include "Main/Unknown/code_02088338.h"

#include "code_02134398.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"

void SetKartModelPathPrefix(int value) {
    if (value) {
        gKartModelPathPrefix = gKartModelMenuPrefix;
    } else {
        gKartModelPathPrefix = gKartModelSlashPrefix;
    }
}

char *BuildCharacterNsbmdPath(u16 a, s32 b) {
    const char *ext = "nsbmd";
    const char *name;
    if (b != 0) {
        name = gCharacterPNames[a].mUnk_00;
    } else {
        name = gCharacterENames[a].mUnk_00;
    }
    snprintf(gKartModelPathBuffer, 0x100, "%s%s%s", gKartModelPathPrefix, gCharacterDirName, gCharacterSubDirNames[a]);
    snprintf(gKartModelPathBuffer, 0x100, "%s%s.%s", gKartModelPathBuffer, name, ext);
    return gKartModelPathBuffer;
}

char *BuildCharacterNsbtxPath(u16 a, s32 b) {
    const char *ext = "nsbtx";
    const char *name;
    if (b != 0) {
        name = gCharacterPNames[a].mUnk_00;
    } else {
        name = gCharacterENames[a].mUnk_00;
    }
    snprintf(gKartModelPathBuffer, 0x100, "%s%s%s", gKartModelPathPrefix, gCharacterDirName, gCharacterSubDirNames[a]);
    snprintf(gKartModelPathBuffer, 0x100, "%s%s.%s", gKartModelPathBuffer, name, ext);
    return gKartModelPathBuffer;
}

char *BuildKartNsbmdPath(u16 a) {
    const char *ext = "nsbmd";
    snprintf(gKartModelPathBuffer, 0x100, "%s%s%skart_%s.%s", gKartModelPathPrefix, gKartDirName,
             a % 3 == 0 ? "mario/" : gCharacterSubDirNames[a / 3], gKartNames[a].mUnk_00, ext);
    return gKartModelPathBuffer;
}

char *BuildKartNsbtxPath(u16 a) {
    const char *ext = "nsbtx";
    snprintf(gKartModelPathBuffer, 0x100, "%s%s%skart_%s.%s", gKartModelPathPrefix, gKartDirName,
             a % 3 == 0 ? "mario/" : gCharacterSubDirNames[a / 3], gKartNames[a].mUnk_00, ext);
    return gKartModelPathBuffer;
}

char *BuildTireNsbmdPath(u16 a, const char *name) {
    const char *ext = "nsbmd";
    snprintf(gKartModelPathBuffer, 0x100, "%s%stire/%s.%s", gKartModelPathPrefix, gKartDirName, name, ext);
    return gKartModelPathBuffer;
}

char *BuildTireNsbtxPath(u16 a, const char *name) {
    const char *ext = "nsbtx";
    snprintf(gKartModelPathBuffer, 0x100, "%s%stire/%s.%s", gKartModelPathPrefix, gKartDirName, name, ext);
    return gKartModelPathBuffer;
}

char *BuildKartShadowNsbmdPath(u16 a) {
    snprintf(gKartModelPathBuffer, 0x100, "%s%sshadow/sh_%s.nsbmd", gKartModelPathPrefix, gKartDirName,
             gKartShadowNames[a].mUnk_00);
    return gKartModelPathBuffer;
}

const char *LookupCharacterPOrEName(s32 a, s32 b) {
    if (b != 0) {
        return gCharacterPNames[a].mUnk_00;
    } else {
        return gCharacterENames[a].mUnk_00;
    }
}

char *BuildCharacterDirPath(s32 a) {
    snprintf(gKartModelPathBuffer, 0x100, "%s%s%s", gKartModelPathPrefix, gCharacterDirName, gCharacterSubDirNames[a]);
    return gKartModelPathBuffer;
}

s8 *BuildPFaceanimNsbtpPath(void) {
    snprintf((char *) &gKartModelPathBuffer, 0x100, gCommonPFaceanimNsbtpFormat, *(u32 *) &gKartModelPathPrefix,
             *(u32 *) &gCharacterDirName);
    return (s8 *) &gKartModelPathBuffer;
}

char *BuildEmblemNsbtxPath(u16 a) {
    snprintf(gKartModelPathBuffer, 0x100, gEmblemNsbtxFormat, gKartModelPathPrefix, gCharacterEmblemNames[a].mUnk_00);
    return gKartModelPathBuffer;
}

char *BuildTeamEmblemNsbtxPath(s32 a) {
    snprintf(gKartModelPathBuffer, 0x100, gTeamEmblemNsbtxFormat, gKartModelPathPrefix, gTeamEmblemNames[a == 0]);
    return gKartModelPathBuffer;
}
