#include "Main/Unknown/code_0210ef68.h"

#include "code_02003024.h"
#include "code_02003be0.h"
#include "code_0212d214.h"
#include "fs_file.h"
#include "Main/Unknown/code_0210e33c.h"

u32 func_0210efcc(NNSSndArc *a, const u8 *b, NNSSndHeap *c, u32 d) {
    a->mInfo = NULL;
    a->mFat = NULL;
    a->mSymbol = NULL;
    if (FS_ConvertPathToFileID(&a->mFileId, b) == 0) {
        return 0;
    }
    FS_InitFile(&a->mFile);
    if (FS_OpenFileFast(&a->mFile, a->mFileId) == 0) {
        return 0;
    }
    a->mFileOpen = 1;
    if (NNS_SndArcSetup(a, c, d) == 0) {
        return 0;
    }
    NNS_SndArcSetCurrent(a);
    return 1;
}

void func_0210efac(Unk0217d178 *p) {
    s32 i;

    for (i = 0; i < 16; i++) {
        p->mFileIds[i] = 0;
    }
    p->mCount = 0;
}

void func_0210ef68(Unk0217d178 *p) {
    s32 i;

    for (i = 0; i < p->mCount; i++) {
        NNS_SndArcSetFileAddress(p->mFileIds[i], NULL);
    }
}
