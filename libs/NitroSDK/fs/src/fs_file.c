#include "fs_file.h"
#include "code_02004dc0.h"

// Returns whether FS_Init has run.
u32 FS_IsAvailable(void) {
    return data_0216f350;
}

// Clears a file record so it is idle and not linked to an archive.
void FS_InitFile(FSFile *file) {
    file->mLink.mPrev = 0;
    file->mLink.mNext = file->mLink.mPrev;
    file->mQueue.mTail = 0;
    file->mQueue.mHead = file->mQueue.mTail;
    file->mArc = 0;
    file->mCommand = 0xe;
    file->mStat = 0;
}
