#include "Main/Unknown/code_0210e33c.h"
#include "Main/Unknown/code_0202511c.h"
#include "Main/Unknown/code_021053e4.h"

#include "Main/Unknown/code_02111158.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02111000.h"
#include "code_020219e8.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02108950.h"
#include "Main/Unknown/code_0210d960.h"
#include "Main/Unknown/code_0210ef68.h"
#include "Main/Unknown/code_0211127c.h"
#include "Main/Unknown/code_0212da2c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"

const SoundSet data_0215c38c = {0xff, 0xff, 0xff};
const SoundSet data_0215c380 = {0xff, 0xff, 0xff};
const SoundSet data_0215c398 = {0xff, 0xff, 0xff};

void ReleaseLoadedSoundSet(void) {
    ReleaseSoundSet(GetLoadedSoundSet());
}

// Loads wave archives 0 and 0x50 (taken from archives 0x61 and 0x62 when b is set), assigns bank 0's wave archives to
// it, then loads group a.
u32 func_0210ed20(u32 groupId, u32 moveWaveArcs) {
    NNSSndArcBankInfo *bankInfo;
    NNSSndArcWaveArcInfo *waveArcInfo;
    Unk02021968 *r;
    u32 v;
    u32 fileId;
    Unk02021968 *bankFile;
    u32 loaded;
    u32 listCount;
    s32 i;

    if (moveWaveArcs != 0) {
        if (NNS_SndArcLoadWaveArc(0x61, data_0217d130) == 0) {
            loaded = 0;
        } else {
            NNSSndArcWaveArcInfo *waveArcInfo;
            NNSSndArcWaveArcInfo *r;
            u32 v;
            u32 fileId;

            waveArcInfo = NNS_SndArcGetWaveArcInfo(0x61);
            r = NNS_SndArcGetWaveArcInfo(0);
            fileId = (r)->mFileId;
            v = waveArcInfo->mFileId;
            NNS_SndArcSetFileAddress(fileId, NNS_SndArcGetFileAddress(v));
            NNS_SndArcSetFileAddress(v, NULL);
            loaded = 1;
            listCount = data_0217d178.mCount;
            data_0217d178.mCount = listCount + 1;
            data_0217d178.mFileIds[listCount] = fileId;
        }
        if (loaded == 0) {
            return 0;
        }
        if (NNS_SndArcLoadWaveArc(0x62, data_0217d130) == 0) {
            loaded = 0;
        } else {
            NNSSndArcWaveArcInfo *waveArcInfo;
            NNSSndArcWaveArcInfo *r;
            u32 v;
            u32 fileId;

            waveArcInfo = NNS_SndArcGetWaveArcInfo(0x62);
            r = NNS_SndArcGetWaveArcInfo(0x50);
            fileId = (r)->mFileId;
            v = waveArcInfo->mFileId;
            NNS_SndArcSetFileAddress(fileId, NNS_SndArcGetFileAddress(v));
            NNS_SndArcSetFileAddress(v, NULL);
            loaded = 1;
            listCount = data_0217d178.mCount;
            data_0217d178.mCount = listCount + 1;
            data_0217d178.mFileIds[listCount] = fileId;
        }
        if (loaded == 0) {
            return 0;
        }
    } else {
        if (NNS_SndArcLoadWaveArc(0, data_0217d130) == 0) {
            return 0;
        }
        if (NNS_SndArcLoadWaveArc(0x50, data_0217d130) == 0) {
            return 0;
        }
    }
    bankInfo = NNS_SndArcGetBankInfo(0);
    bankFile = NNS_SndArcGetFileAddress(bankInfo->mFileId);
    for (i = 0; i < 4; i++) {
        v = bankInfo->mWaveArcNo[i];
        if (v == 0xffff) {
            continue;
        }
        waveArcInfo = NNS_SndArcGetWaveArcInfo(v);
        if (waveArcInfo == NULL) {
            break;
        }
        fileId = waveArcInfo->mFileId;
        r = NNS_SndArcGetFileAddress(fileId);
        if (bankFile == NULL) {
            continue;
        }
        if (r == NULL) {
            continue;
        }
        SND_AssignWaveArc(bankFile, i, r);
    }
    if (LoadSndGroup(groupId) == 0) {
        return 0;
    }
    return 1;
}

// Releases the loaded set and loads v unless it is empty or already loaded; d adds extra wave archives for some sets.
u32 LoadSoundSetIfChanged(SoundSet soundSet, u32 loadExtras) {
    SndFileIdList *p;
    u32 loaded;
    u32 listCount;
    s32 i;
    SndFileIdList *list;

    if (soundSet.mSeqId == 0xff && soundSet.mUnk_04 == 0xff && soundSet.mUnk_08 == 0xff) {
        return 1;
    }
    if (IsSoundSetLoaded(GetLoadedSoundSet(), soundSet) != 0) {
        return 1;
    }
    ReleaseSoundSet(GetLoadedSoundSet());
    p = &data_0217d134;
    for (i = 0; i < p->mCount; i++) {
        NNS_SndArcSetFileAddress(p->mFileIds[i], NULL);
    }
    list = &data_0217d134;
    for (i = 0; i < 16; i++) {
        list->mFileIds[i] = 0;
    }
    list->mCount = 0;
    if (loadExtras != 0) {
        switch (soundSet.mSeqId) {
            case 0x4a:
                if (NNS_SndArcLoadWaveArc(0x63, data_0217d130) == 0) {
                    loaded = 0;
                } else {
                    NNSSndArcWaveArcInfo *p;
                    NNSSndArcWaveArcInfo *destWaveArc;
                    u32 sourceFileId;
                    u32 destFileId;

                    p = NNS_SndArcGetWaveArcInfo(0x63);
                    destWaveArc = NNS_SndArcGetWaveArcInfo(0x31);
                    destFileId = destWaveArc->mFileId;
                    sourceFileId = p->mFileId;
                    NNS_SndArcSetFileAddress(destFileId, NNS_SndArcGetFileAddress(sourceFileId));
                    NNS_SndArcSetFileAddress(sourceFileId, NULL);
                    loaded = 1;
                    listCount = data_0217d134.mCount;
                    data_0217d134.mCount = listCount + 1;
                    data_0217d134.mFileIds[listCount] = destFileId;
                }
                if (loaded == 0) {
                    return 0;
                }
                break;
            case 0x2b:
                if (NNS_SndArcLoadWaveArc(0x64, data_0217d130) == 0) {
                    loaded = 0;
                } else {
                    NNSSndArcWaveArcInfo *p;
                    NNSSndArcWaveArcInfo *destWaveArc;
                    u32 sourceFileId;
                    u32 destFileId;

                    p = NNS_SndArcGetWaveArcInfo(0x64);
                    destWaveArc = NNS_SndArcGetWaveArcInfo(0x58);
                    destFileId = destWaveArc->mFileId;
                    sourceFileId = p->mFileId;
                    NNS_SndArcSetFileAddress(destFileId, NNS_SndArcGetFileAddress(sourceFileId));
                    NNS_SndArcSetFileAddress(sourceFileId, NULL);
                    loaded = 1;
                    listCount = data_0217d134.mCount;
                    data_0217d134.mCount = listCount + 1;
                    data_0217d134.mFileIds[listCount] = destFileId;
                }
                if (loaded == 0) {
                    return 0;
                }
                break;
            case 0xf:
                if (NNS_SndArcLoadWaveArc(0x34, data_0217d130) == 0) {
                    loaded = 0;
                } else {
                    NNSSndArcWaveArcInfo *p;
                    NNSSndArcWaveArcInfo *destWaveArc;
                    u32 sourceFileId;
                    u32 destFileId;

                    p = NNS_SndArcGetWaveArcInfo(0x34);
                    destWaveArc = NNS_SndArcGetWaveArcInfo(0x33);
                    destFileId = destWaveArc->mFileId;
                    sourceFileId = p->mFileId;
                    NNS_SndArcSetFileAddress(destFileId, NNS_SndArcGetFileAddress(sourceFileId));
                    NNS_SndArcSetFileAddress(sourceFileId, NULL);
                    loaded = 1;
                    listCount = data_0217d134.mCount;
                    data_0217d134.mCount = listCount + 1;
                    data_0217d134.mFileIds[listCount] = destFileId;
                }
                if (loaded == 0) {
                    return 0;
                }
                break;
        }
        if (soundSet.mUnk_04 == 0x10) {
            if (NNS_SndArcLoadWaveArc(0x13, data_0217d130) == 0) {
                loaded = 0;
            } else {
                NNSSndArcWaveArcInfo *p;
                NNSSndArcWaveArcInfo *destWaveArc;
                u32 sourceFileId;
                u32 destFileId;

                p = NNS_SndArcGetWaveArcInfo(0x13);
                destWaveArc = NNS_SndArcGetWaveArcInfo(0x12);
                destFileId = destWaveArc->mFileId;
                sourceFileId = p->mFileId;
                NNS_SndArcSetFileAddress(destFileId, NNS_SndArcGetFileAddress(sourceFileId));
                NNS_SndArcSetFileAddress(sourceFileId, NULL);
                loaded = 1;
                listCount = data_0217d134.mCount;
                data_0217d134.mCount = listCount + 1;
                data_0217d134.mFileIds[listCount] = destFileId;
            }
            if (loaded == 0) {
                return 0;
            }
        }
    }
    return LoadSoundSet(GetLoadedSoundSet(), soundSet) != 0;
}

void func_0210e920(void) {
    if (NNS_SndArcLoadWaveArc(1, data_0217d130) == 0) {
        return;
    }
    if (NNS_SndArcLoadBankEx(0, 2, data_0217d130) == 0) {
        return;
    }
    NNS_SndArcLoadSeqArc(0, data_0217d130);
}

void func_0210e8f8(u32 moveWaveArcs) {
    func_0210ed20(0, moveWaveArcs);
    SaveSndHeapState(GetLoadedSoundSet());
}

void LoadSceneSoundSet(SoundRow soundRow, u32 loadExtras) {
    SoundSet soundSet;

    soundSet.mSeqId = soundRow.mUnk_00[1];
    soundSet.mUnk_04 = soundRow.mUnk_00[2];
    soundSet.mUnk_08 = soundRow.mUnk_00[3];
    LoadSoundSetIfChanged(soundSet, loadExtras);
    if (func_02105504() == 0) {
        return;
    }
    LoadSeqRowIfChanged(gRaceSetup->mMode);
}

u32 LoadSndDataFromFile(void) {
    NNSSndArcSeqArcInfo *sourceSeqArc;
    NNSSndArcSeqArcInfo *destSeqArc;
    NNSSndArcWaveArcInfo *sourceWaveArc;
    NNSSndArcWaveArcInfo *destWaveArc;
    u32 loadResult;
    u32 sourceFileId;
    u32 destFileId;
    u32 loaded;
    u32 listCount;

    NNS_SndArcSetCurrent(&data_0217c868);
    loadResult = SetupSndArcFromFile(&data_0217d0a0, data_0216cb30, data_0217d130, 0);
    func_0210d990(1);
    if (loadResult == 0) {
        return 0;
    }
    if (NNS_SndArcLoadSeqArc(1, data_0217d130) == 0) {
        return 0;
    }
    sourceSeqArc = NNS_SndArcGetSeqArcInfo(1);
    destSeqArc = NNS_SndArcGetSeqArcInfo(0);
    sourceFileId = sourceSeqArc->mFileId;
    destFileId = destSeqArc->mFileId;
    NNS_SndArcSetFileAddress(destFileId, NNS_SndArcGetFileAddress(sourceFileId));
    NNS_SndArcSetFileAddress(sourceFileId, NULL);
    listCount = data_0217d178.mCount;
    data_0217d178.mCount = listCount + 1;
    data_0217d178.mFileIds[listCount] = destFileId;
    if (NNS_SndArcLoadWaveArc(0x3e, data_0217d130) != 0) {
        sourceWaveArc = NNS_SndArcGetWaveArcInfo(0x3e);
        destWaveArc = NNS_SndArcGetWaveArcInfo(0x3d);
        destFileId = destWaveArc->mFileId;
        sourceFileId = sourceWaveArc->mFileId;
        NNS_SndArcSetFileAddress(destFileId, NNS_SndArcGetFileAddress(sourceFileId));
        NNS_SndArcSetFileAddress(sourceFileId, NULL);
        loaded = 1;
        listCount = data_0217d178.mCount;
        data_0217d178.mCount = listCount + 1;
        data_0217d178.mFileIds[listCount] = destFileId;
    } else {
        loaded = 0;
    }
    if (loaded == 0) {
        return 0;
    }
    if (NNS_SndArcLoadWaveArc(1, data_0217d130) == 0) {
        loaded = 0;
    } else if (NNS_SndArcLoadBankEx(0, 2, data_0217d130) == 0) {
        loaded = 0;
    } else if (NNS_SndArcLoadSeqArc(0, data_0217d130) == 0) {
        loaded = 0;
    } else {
        loaded = 1;
    }
    if (loaded == 0) {
        return 0;
    }
    if (func_0210ed20(1, 1) == 0) {
        return 0;
    }
    SaveSndHeapState(GetLoadedSoundSet());
    return 1;
}

u32 LoadCourseSoundSet(u32 a, u32 b) {
    SoundRow row, rowCopy;
    SoundSet soundSet;
    u32 loaded;

    GetCourseSoundRowIndex(b, &row);
    rowCopy = row;
    soundSet.mSeqId = rowCopy.mUnk_00[1];
    soundSet.mUnk_04 = rowCopy.mUnk_00[2];
    soundSet.mUnk_08 = rowCopy.mUnk_00[3];
    NNS_SndArcSetCurrent(&data_0217d0a0);
    loaded = LoadSoundSetIfChanged(soundSet, 1) != 0;
    if (loaded != 0) {
        loaded = LoadSeqRowIfChanged(a);
    }
    return loaded;
}

u32 func_0210e524(void) {
    SoundRow row, rowCopy;
    SoundSet soundSet;

    row = GetSoundRow(0x29);
    row.mUnk_00[1] = func_0211127c();
    rowCopy = row;
    soundSet.mSeqId = rowCopy.mUnk_00[1];
    soundSet.mUnk_04 = rowCopy.mUnk_00[2];
    soundSet.mUnk_08 = rowCopy.mUnk_00[3];
    NNS_SndArcSetCurrent(&data_0217d0a0);
    return LoadSoundSetIfChanged(soundSet, 1) != 0;
}

u32 LoadSndGroup(s32 groupId) {
    return NNS_SndArcLoadGroup(groupId, data_0217d130);
}

void ResetLoadedSoundSet(LoadedSoundSet *loadedSet) {
    loadedSet->mSoundSet = data_0215c398;
    loadedSet->mHeapState = 0xff00;
}

void SaveSndHeapState(LoadedSoundSet *loadedSet) {
    loadedSet->mHeapState = NNS_SndHeapSaveState(data_0217d130);
}

// Restores the heap to the state saved before the set was loaded.
void ReleaseSoundSet(LoadedSoundSet *loadedSet) {
    SoundSet emptySet = data_0215c380;

    if (emptySet.mSeqId == loadedSet->mSoundSet.mSeqId && emptySet.mUnk_04 == loadedSet->mSoundSet.mUnk_04 &&
        emptySet.mUnk_08 == loadedSet->mSoundSet.mUnk_08) {
        return;
    }
    NNS_SndHeapLoadState(data_0217d130, loadedSet->mHeapState);
    NNS_SndHeapGetCurrentLevel(data_0217d130);
    loadedSet->mSoundSet = data_0215c38c;
}

u32 IsSoundSetLoaded(LoadedSoundSet *loadedSet, SoundSet soundSet) {
    if (soundSet.mSeqId == loadedSet->mSoundSet.mSeqId && soundSet.mUnk_04 == loadedSet->mSoundSet.mUnk_04 &&
        soundSet.mUnk_08 == loadedSet->mSoundSet.mUnk_08) {
        return 1;
    }
    return 0;
}

u32 LoadSoundSet(LoadedSoundSet *loadedSet, SoundSet soundSet) {
    if (soundSet.mSeqId != 0xff && NNS_SndArcLoadSeq(soundSet.mSeqId, data_0217d130) == 0) {
        return 0;
    }
    if (soundSet.mUnk_04 != 0xff && NNS_SndArcLoadBank(soundSet.mUnk_04, data_0217d130) == 0) {
        return 0;
    }
    if (soundSet.mUnk_08 != 0xff && NNS_SndArcLoadBank(soundSet.mUnk_08, data_0217d130) == 0) {
        return 0;
    }
    loadedSet->mSoundSet = soundSet;
    return 1;
}
