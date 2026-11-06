#include "code_0212d214.h"

#include "Main/Unknown/unk_0217d000.h"
#include "code_02003be0.h"
#include "code_0212f788.h"
#include "code_02004d80.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0212d968.h"
#include "code_02020eb0.h"
#include "code_0201750c.h"
#include "Main/Unknown/code_02017000.h"
#include "code_020172d0.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/code_02021000.h"
#include "code_02017f24.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0212da2c.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_020207ec.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0201ec30.h"
#include "code_020219b0.h"
#include "code_0212df7c.h"
#include "code_020219e8.h"
#include "code_0212bcac.h"
#include "code_0212c7a0.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_020218f4.h"

u8 data_0217dec8[0x3c];

// Sets each player's sequence count and channels and creates its heaps.
BOOL NNS_SndArcPlayerSetup(NNSSndHeap *heap) {
    s32 playerNo;
    NNSSndArcPlayerInfo *playerInfo;
    s32 i;

    NNS_SndArcGetCurrent();
    for (playerNo = 0; playerNo < 32; playerNo++) {
        playerInfo = NNS_SndArcGetPlayerInfo(playerNo);
        if (playerInfo == 0) {
            continue;
        }
        NNS_SndPlayerSetPlayableSeqCount(playerNo, playerInfo->mSeqMax);
        NNS_SndPlayerSetAllocatableChannel(playerNo, playerInfo->mAllocChBitFlag);
        if (playerInfo->mHeapSize == 0 || heap == 0) {
            continue;
        }
        for (i = 0; i < playerInfo->mSeqMax; i++) {
            if (NNS_SndPlayerCreateHeap(playerNo, heap, playerInfo->mHeapSize) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

BOOL NNS_SndArcPlayerStartSeq(NNSSndSeqPlayer **handle, s32 seqNo) {
    NNSSndArcSeqInfo *info;

    info = NNS_SndArcGetSeqInfo(seqNo);
    if (info == 0) {
        return 0;
    }
    return StartSeq(handle, info->mParam.mPlayerNo, info->mParam.mBankNo, info->mParam.mPlayerPrio, info, seqNo);
}

BOOL NNS_SndArcPlayerStartSeqArc(NNSSndSeqPlayer **handle, u32 seqArcNo, u32 index) {
    Unk0212f788 *seqArc;
    NNSSndSeqArcSeqInfo *sound;
    NNSSndArcSeqArcInfo *info;

    info = NNS_SndArcGetSeqArcInfo(seqArcNo);
    if (info == 0) {
        return 0;
    }
    seqArc = NNS_SndArcGetFileAddress(info->mFileId);
    if (seqArc == 0) {
        return 0;
    }
    sound = NNSi_SndSeqArcGetSeqInfo(seqArc, index);
    if (sound == 0) {
        return 0;
    }
    return StartSeqArc(handle, sound->mParam.mPlayerNo, sound->mParam.mBankNo, sound->mParam.mPlayerPrio, sound, seqArc,
                       seqArcNo, index);
}

// A negative player, bank or priority takes the value from the entry.
BOOL NNS_SndArcPlayerStartSeqArcEx(NNSSndSeqPlayer **handle, s32 playerNo, s32 bankNo, s32 playerPrio, s32 seqArcNo,
                                   s32 index) {
    Unk0212f788 *seqArc;
    NNSSndSeqArcSeqInfo *sound;
    NNSSndArcSeqArcInfo *info;

    info = NNS_SndArcGetSeqArcInfo(seqArcNo);
    if (info == 0) {
        return 0;
    }
    seqArc = NNS_SndArcGetFileAddress(info->mFileId);
    if (seqArc == 0) {
        return 0;
    }
    sound = NNSi_SndSeqArcGetSeqInfo(seqArc, index);
    if (sound == 0) {
        return 0;
    }
    if (playerPrio < 0) {
        playerPrio = sound->mParam.mPlayerPrio;
    }
    if (bankNo < 0) {
        bankNo = sound->mParam.mBankNo;
    }
    if (playerNo < 0) {
        playerNo = sound->mParam.mPlayerNo;
    }
    return StartSeqArc(handle, playerNo, bankNo, playerPrio, sound, seqArc, seqArcNo, index);
}

BOOL StartSeq(NNSSndSeqPlayer **handle, s32 playerNo, s32 bankNo, s32 playerPrio, NNSSndArcSeqInfo *info, s32 seqNo) {
    NNSSndSeqPlayer *player;
    Unk0212f788 *seq;
    Unk02021968 *bank;
    NNSSndHeap *heap;

    player = NNSi_SndPlayerAllocSeqPlayer(handle, playerNo, playerPrio);
    if (player == 0) {
        return 0;
    }
    heap = NNSi_SndPlayerAllocHeap(playerNo, player);
    if (NNSi_SndArcLoadBank(bankNo, 6, heap, 0, &bank) != 0) {
        NNSi_SndPlayerFreeSeqPlayer(player);
        return 0;
    }
    if (NNSi_SndArcLoadSeq(seqNo, 1, heap, 0, &seq) != 0) {
        NNSi_SndPlayerFreeSeqPlayer(player);
        return 0;
    }
    NNSi_SndPlayerStartSeq(player, (u8 *) seq + seq->mUnk_18, 0, bank);
    NNS_SndPlayerSetInitialVolume(handle, info->mParam.mVolume);
    NNS_SndPlayerSetChannelPriority(handle, info->mParam.mChannelPrio);
    NNS_SndPlayerSetSeqNo(handle, seqNo);
    return 1;
}

BOOL StartSeqArc(NNSSndSeqPlayer **handle, s32 playerNo, s32 bankNo, s32 playerPrio, NNSSndSeqArcSeqInfo *sound,
                 Unk0212f788 *seqArc, u32 seqArcNo, u32 index) {
    void *player;
    Unk02021968 *bank;
    NNSSndHeap *heap;

    player = NNSi_SndPlayerAllocSeqPlayer(handle, playerNo, playerPrio);
    if (player == 0) {
        return 0;
    }
    heap = NNSi_SndPlayerAllocHeap(playerNo, player);
    if (NNSi_SndArcLoadBank(bankNo, 6, heap, 0, &bank) != 0) {
        NNSi_SndPlayerFreeSeqPlayer(player);
        return 0;
    }
    NNSi_SndPlayerStartSeq(player, (u8 *) seqArc + seqArc->mUnk_18, sound->mOffset, bank);
    NNS_SndPlayerSetInitialVolume(handle, sound->mParam.mVolume);
    NNS_SndPlayerSetChannelPriority(handle, sound->mParam.mChannelPrio);
    NNS_SndPlayerSetSeqArcNo(handle, seqArcNo, index);
    return 1;
}

BOOL NNS_SndArcLoadGroup(s32 groupNo, NNSSndHeap *heap) {
    return NNSi_SndArcLoadGroup(groupNo, heap) == 0;
}

BOOL NNS_SndArcLoadSeq(s32 seqNo, NNSSndHeap *heap) {
    return NNSi_SndArcLoadSeq(seqNo, 0xff, heap, 1, 0) == 0;
}

BOOL NNS_SndArcLoadSeqArc(s32 seqArcNo, NNSSndHeap *heap) {
    return NNSi_SndArcLoadSeqArc(seqArcNo, 0xff, heap, 1, 0) == 0;
}

BOOL NNS_SndArcLoadBank(s32 bankNo, NNSSndHeap *heap) {
    return NNSi_SndArcLoadBank(bankNo, 0xff, heap, 1, 0) == 0;
}

BOOL NNS_SndArcLoadWaveArc(s32 waveArcNo, NNSSndHeap *heap) {
    return NNSi_SndArcLoadWaveArc(waveArcNo, 0xff, heap, 1, 0) == 0;
}

BOOL NNS_SndArcLoadBankEx(s32 bankNo, u32 loadFlag, NNSSndHeap *heap) {
    return NNSi_SndArcLoadBank(bankNo, loadFlag, heap, 1, 0) == 0;
}

NNSSndArcLoadResult NNSi_SndArcLoadGroup(s32 groupNo, NNSSndHeap *heap) {
    NNSSndArcGroupInfo *info;
    u32 i;
    NNSSndArcGroupItem *item;
    NNSSndArcLoadResult result;

    info = NNS_SndArcGetGroupInfo(groupNo);
    if (info == 0) {
        return NNS_SND_ARC_LOAD_ERROR_INVALID_GROUP_NO;
    }
    for (i = 0; i < info->mCount; i++) {
        item = &info->mItem[i];
        switch (item->mType) {
            case 0:
                result = NNSi_SndArcLoadSeq(item->mIndex, item->mLoadFlag, heap, 1, 0);
                if (result != NNS_SND_ARC_LOAD_SUCESS) {
                    return result;
                }
                break;
            case 3:
                result = NNSi_SndArcLoadSeqArc(item->mIndex, item->mLoadFlag, heap, 1, 0);
                if (result != NNS_SND_ARC_LOAD_SUCESS) {
                    return result;
                }
                break;
            case 1:
                result = NNSi_SndArcLoadBank(item->mIndex, item->mLoadFlag, heap, 1, 0);
                if (result != NNS_SND_ARC_LOAD_SUCESS) {
                    return result;
                }
                break;
            case 2:
                result = NNSi_SndArcLoadWaveArc(item->mIndex, item->mLoadFlag, heap, 1, 0);
                if (result != NNS_SND_ARC_LOAD_SUCESS) {
                    return result;
                }
                break;
        }
    }
    return NNS_SND_ARC_LOAD_SUCESS;
}

NNSSndArcLoadResult NNSi_SndArcLoadSeq(s32 seqNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr, Unk0212f788 **pData) {
    NNSSndArcSeqInfo *seqInfo;
    Unk0212f788 *seqData;
    NNSSndArcLoadResult result;

    seqInfo = NNS_SndArcGetSeqInfo(seqNo);
    if (seqInfo == 0) {
        return NNS_SND_ARC_LOAD_ERROR_INVALID_SEQ_NO;
    }
    result = NNSi_SndArcLoadBank(seqInfo->mParam.mBankNo, loadFlag, heap, bSetAddr, 0);
    if (result != NNS_SND_ARC_LOAD_SUCESS) {
        return result;
    }
    if (loadFlag & 1) {
        seqData = LoadSeq(seqInfo->mFileId, heap, bSetAddr);
        if (seqData == 0) {
            return NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_SEQ;
        }
    } else {
        seqData = NNS_SndArcGetFileAddress(seqInfo->mFileId);
    }
    if (pData != 0) {
        *pData = seqData;
    }
    return NNS_SND_ARC_LOAD_SUCESS;
}

NNSSndArcLoadResult NNSi_SndArcLoadSeqArc(s32 seqArcNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr,
                                          Unk0212f788 **pData) {
    NNSSndArcSeqArcInfo *seqArcInfo;
    Unk0212f788 *seqArc;

    seqArcInfo = NNS_SndArcGetSeqArcInfo(seqArcNo);
    if (seqArcInfo == 0) {
        return NNS_SND_ARC_LOAD_ERROR_INVALID_SEQARC_NO;
    }
    if (loadFlag & 8) {
        seqArc = LoadSeqArc(seqArcInfo->mFileId, heap, bSetAddr);
        if (seqArc == 0) {
            return NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_SEQARC;
        }
    } else {
        seqArc = NNS_SndArcGetFileAddress(seqArcInfo->mFileId);
    }
    if (pData != 0) {
        *pData = seqArc;
    }
    return NNS_SND_ARC_LOAD_SUCESS;
}

// Loads the bank and its wave archives, and assigns them to the bank.
NNSSndArcLoadResult NNSi_SndArcLoadBank(s32 bankNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr,
                                        Unk02021968 **pData) {
    NNSSndArcBankInfo *bankInfo;
    NNSSndArcWaveArcInfo *waveArcInfo;
    Unk02021968 *waveArc;
    Unk02021968 *bank;
    s32 i;
    u32 loadWave;
    NNSSndArcLoadResult result;

    bankInfo = NNS_SndArcGetBankInfo(bankNo);
    if (bankInfo == 0) {
        return NNS_SND_ARC_LOAD_ERROR_INVALID_BANK_NO;
    }
    if (loadFlag & 2) {
        bank = LoadBank(bankInfo->mFileId, heap, bSetAddr);
        if (bank == 0) {
            return NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_BANK;
        }
    } else {
        bank = NNS_SndArcGetFileAddress(bankInfo->mFileId);
    }
    loadWave = loadFlag & 4;
    for (i = 0; i < 4; i++) {
        if (bankInfo->mWaveArcNo[i] != 0xffff) {
            waveArcInfo = NNS_SndArcGetWaveArcInfo(bankInfo->mWaveArcNo[i]);
            if (waveArcInfo == 0) {
                return NNS_SND_ARC_LOAD_ERROR_INVALID_WAVEARC_NO;
            }
            result = NNSi_SndArcLoadWaveArc(bankInfo->mWaveArcNo[i], loadFlag, heap, bSetAddr, &waveArc);
            if (result != NNS_SND_ARC_LOAD_SUCESS) {
                return result;
            }
            if ((waveArcInfo->mFlags & 1) && loadWave) {
                if (LoadSingleWaves(waveArc, bank, i, waveArcInfo->mFileId, heap) == 0) {
                    return NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_WAVE;
                }
            }
            if (bank != 0 && waveArc != 0) {
                SND_AssignWaveArc(bank, i, waveArc);
            }
        }
    }
    if (pData != 0) {
        *pData = bank;
    }
    return NNS_SND_ARC_LOAD_SUCESS;
}

NNSSndArcLoadResult NNSi_SndArcLoadWaveArc(s32 waveArcNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr,
                                           Unk02021968 **pData) {
    NNSSndArcWaveArcInfo *waveArcInfo;
    Unk02021968 *waveArc;

    waveArcInfo = NNS_SndArcGetWaveArcInfo(waveArcNo);
    if (waveArcInfo == 0) {
        return NNS_SND_ARC_LOAD_ERROR_INVALID_WAVEARC_NO;
    }
    if (loadFlag & 4) {
        if (waveArcInfo->mFlags & 1) {
            waveArc = LoadWaveArcTable(waveArcInfo->mFileId, heap, bSetAddr);
        } else {
            waveArc = LoadWaveArc(waveArcInfo->mFileId, heap, bSetAddr);
        }
        if (waveArc == 0) {
            return NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_WAVE;
        }
    } else {
        waveArc = NNS_SndArcGetFileAddress(waveArcInfo->mFileId);
    }
    if (pData != 0) {
        *pData = waveArc;
    }
    return NNS_SND_ARC_LOAD_SUCESS;
}

void *NNSi_SndArcLoadFile(u32 fileId, NNSSndHeapDisposeCallback callback, void *data1, u32 data2, NNSSndHeap *heap) {
    u32 size;
    u8 *buffer;

    size = NNS_SndArcGetFileSize(fileId);
    if (size == 0) {
        return 0;
    }
    if (heap == 0) {
        return 0;
    }
    buffer = NNS_SndHeapAlloc(heap, size + 0x20, callback, data1, data2);
    if (buffer == 0) {
        return 0;
    }
    if (NNS_SndArcReadFile(fileId, buffer, size, 0) != size) {
        return 0;
    }
    DC_StoreRange(buffer, size);
    return buffer;
}

Unk0212f788 *LoadSeq(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr) {
    void *buffer;

    buffer = NNS_SndArcGetFileAddress(fileId);
    if (buffer == 0) {
        buffer = NNSi_SndArcLoadFile(fileId, SeqDisposeCallback, bSetAddr ? NNS_SndArcGetCurrent() : 0, fileId, heap);
        if (bSetAddr != 0 && buffer != 0) {
            NNS_SndArcSetFileAddress(fileId, buffer);
        }
    }
    return buffer;
}

Unk0212f788 *LoadSeqArc(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr) {
    void *buffer;

    buffer = NNS_SndArcGetFileAddress(fileId);
    if (buffer == 0) {
        buffer = NNSi_SndArcLoadFile(fileId, SeqDisposeCallback, bSetAddr ? NNS_SndArcGetCurrent() : 0, fileId, heap);
        if (bSetAddr != 0 && buffer != 0) {
            NNS_SndArcSetFileAddress(fileId, buffer);
        }
    }
    return buffer;
}

Unk02021968 *LoadBank(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr) {
    void *buffer;

    buffer = NNS_SndArcGetFileAddress(fileId);
    if (buffer == 0) {
        buffer = NNSi_SndArcLoadFile(fileId, BankDisposeCallback, bSetAddr ? NNS_SndArcGetCurrent() : 0, fileId, heap);
        if (bSetAddr != 0 && buffer != 0) {
            NNS_SndArcSetFileAddress(fileId, buffer);
        }
    }
    return buffer;
}

Unk02021968 *LoadWaveArc(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr) {
    Unk02021968 *waveArc;

    waveArc = NNS_SndArcGetFileAddress(fileId);
    if (waveArc == 0) {
        waveArc =
            NNSi_SndArcLoadFile(fileId, WaveArcDisposeCallback, bSetAddr ? NNS_SndArcGetCurrent() : 0, fileId, heap);
        if (bSetAddr != 0 && waveArc != 0) {
            NNS_SndArcSetFileAddress(fileId, waveArc);
        }
    }
    return waveArc;
}

// Loads the wave archive header and tables; the waves load one by one.
Unk02021968 *LoadWaveArcTable(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr) {
    Unk02021968 *waveArc;
    u32 len;
    u32 tableSize;
    s32 readSize;

    waveArc = NNS_SndArcGetFileAddress(fileId);
    if (waveArc == 0) {
        if (NNS_SndArcReadFile(fileId, data_0217dec8, 0x3c, 0) != 0x3c) {
            return 0;
        }
        tableSize = ((Unk02021968 *) data_0217dec8)->mUnk_38 * 4;
        len = tableSize * 2 + 0x3c;
        if (heap == 0) {
            return 0;
        }
        waveArc = NNS_SndHeapAlloc(heap, len + 0x20, WaveArcTableDisposeCallback, bSetAddr ? NNS_SndArcGetCurrent() : 0,
                                   fileId);
        if (waveArc == 0) {
            return 0;
        }
        readSize = NNS_SndArcReadFile(fileId, waveArc, tableSize + 0x3c, 0);
        if (readSize != tableSize + 0x3c) {
            return 0;
        }
        MI_CpuCopy8(waveArc->mUnk_3c, waveArc->mUnk_3c + waveArc->mUnk_38, tableSize);
        MI_CpuFill8(waveArc->mUnk_3c, 0, tableSize);
        DC_StoreRange(waveArc, len);
        if (bSetAddr != 0) {
            NNS_SndArcSetFileAddress(fileId, waveArc);
        }
    }
    return waveArc;
}

// Clears the file address when mem is still the loaded copy.
void DisposeCallback(void *mem, NNSSndArc *arc, u32 fileId) {
    NNSSndArc *oldArc;
    u32 enabled;

    if (arc == 0) {
        return;
    }
    enabled = OS_DisableInterrupts();
    oldArc = NNS_SndArcSetCurrent(arc);
    if (mem == NNS_SndArcGetFileAddress(fileId)) {
        NNS_SndArcSetFileAddress(fileId, 0);
    }
    NNS_SndArcSetCurrent(oldArc);
    OS_RestoreInterrupts(enabled);
}

void SeqDisposeCallback(void *mem, u32 size, void *data1, u32 data2) {
    DisposeCallback(mem, data1, data2);
    SND_InvalidateSeqData(mem, (u8 *) mem + size);
}

void BankDisposeCallback(void *mem, u32 size, void *data1, u32 data2) {
    DisposeCallback(mem, data1, data2);
    SND_InvalidateBankData(mem, (u8 *) mem + size);
    SND_DestroyBank(mem);
}

void WaveArcDisposeCallback(void *mem, u32 size, void *data1, u32 data2) {
    DisposeCallback(mem, data1, data2);
    SND_InvalidateWaveData(mem, (u8 *) mem + size);
    SND_DestroyWaveArc(mem);
}

void WaveArcTableDisposeCallback(void *mem, u32 size, void *data1, u32 data2) {
    DisposeCallback(mem, data1, data2);
    SND_DestroyWaveArc(mem);
}

void SingleWaveDisposeCallback(void *mem, u32 size, void *data1, u32 data2) {
    u8 *wave = mem;

    if (wave == SND_GetWaveDataAddress(data1, data2)) {
        SND_SetWaveDataAddress(data1, data2, 0);
    }
    SND_InvalidateWaveData(wave, wave + size);
}

BOOL LoadSingleWave(Unk02021968 *waveArc, s32 waveNo, u32 fileId, NNSSndHeap *heap) {
    u32 *entry;
    u32 waveCount;
    u32 end;
    u32 len;
    u32 begin;
    void *buffer;

    if (SND_GetWaveDataAddress(waveArc, waveNo) != 0) {
        return 1;
    }
    waveCount = SND_GetWaveDataCount(waveArc);
    entry = (u32 *) waveArc + (waveArc->mUnk_38 + waveNo);
    begin = entry[15];
    end = waveNo < waveCount - 1 ? entry[16] : waveArc->mUnk_08;
    len = end - begin;
    if (heap == 0) {
        return 0;
    }
    buffer = NNS_SndHeapAlloc(heap, len + 32, SingleWaveDisposeCallback, waveArc, waveNo);
    if (buffer == 0) {
        return 0;
    }
    if (NNS_SndArcReadFile(fileId, buffer, len, begin) != len) {
        return 0;
    }
    DC_StoreRange(buffer, len);
    SND_SetWaveDataAddress(waveArc, waveNo, buffer);
    return 1;
}

BOOL LoadSingleWaves(Unk02021968 *waveArc, Unk02021968 *bank, s32 waveArcNo, u32 fileId, NNSSndHeap *heap) {
    Unk02021bc8 pos;
    Unk02021bc8 firstPos;
    Unk020219f0 inst;

    SND_GetFirstInstDataPos(&firstPos);
    pos = firstPos;
    if (bank == 0) {
        return 0;
    }
    if (SND_GetNextInstData(bank, &inst, &pos) != 0) {
        do {
            if (inst.mUnk_00 == 1 && waveArcNo == inst.mUnk_04) {
                if (LoadSingleWave(waveArc, inst.mUnk_02, fileId, heap) == 0) {
                    return 0;
                }
            }
        } while (SND_GetNextInstData(bank, &inst, &pos) != 0);
    }
    return 1;
}

NNSSndHeap *NNS_SndHeapCreate(void *startAddress, u32 size) {
    NNSSndHeap *heap;
    void *handle;
    u32 end;
    u32 remaining;

    end = (u32) startAddress + size;
    heap = (NNSSndHeap *) (((u32) startAddress + 3) & ~3);
    if ((u32) heap > end) {
        return 0;
    }
    remaining = end - (u32) heap;
    if (remaining < 16) {
        return 0;
    }
    handle = NNS_FndCreateFrmHeapEx(heap + 1, remaining - 16, 0);
    if (handle == 0) {
        return 0;
    }
    if (InitHeap(heap, handle) != 0) {
        return heap;
    }
    NNS_FndDestroyFrmHeap(handle);
    return 0;
}

void NNS_SndHeapDestroy(NNSSndHeap *heap) {
    NNS_SndHeapClear(heap);
    NNS_FndDestroyFrmHeap(heap->mHandle);
}

void NNS_SndHeapClear(NNSSndHeap *heap) {
    NNSSndHeapSection *section;
    void *object;
    u32 calledBack = 0;

    for (section = NNS_FndGetPrevListObject(&heap->mSectionList, 0); section != 0;
         section = NNS_FndGetPrevListObject(&heap->mSectionList, 0)) {
        for (object = NNS_FndGetPrevListObject(&section->mBlockList, 0); object != 0;
             object = NNS_FndGetPrevListObject(&section->mBlockList, object)) {
            NNSSndHeapBlock *block = object;

            if (block->mCallback != 0) {
                block->mCallback(block + 1, block->mSize, block->mData1, block->mData2);
                calledBack = 1;
            }
        }
        NNS_FndRemoveListObject(&heap->mSectionList, section);
    }
    NNS_FndFreeToFrmHeap(heap->mHandle, 3);
    if (calledBack != 0) {
        EraseSync();
    }
    NewSection(heap);
}

// Allocates behind a 32-byte block header holding the dispose callback.
void *NNS_SndHeapAlloc(NNSSndHeap *heap, u32 size, NNSSndHeapDisposeCallback callback, void *data1, u32 data2) {
    NNSSndHeapBlock *block;
    NNSSndHeapSection *section;

    block = NNS_FndAllocFromFrmHeapEx(heap->mHandle, ((size + 31) & ~31) + 32, 32);
    if (block == 0) {
        return 0;
    }
    section = NNS_FndGetPrevListObject(&heap->mSectionList, 0);
    block->mSize = size;
    block->mCallback = callback;
    block->mData1 = data1;
    block->mData2 = data2;
    NNS_FndAppendListObject(&section->mBlockList, block);
    return block + 1;
}

// Returns the level for NNS_SndHeapLoadState, or -1.
s32 NNS_SndHeapSaveState(NNSSndHeap *heap) {
    if (NNS_FndRecordStateForFrmHeap(heap->mHandle, heap->mSectionList.mCount) == 0) {
        return -1;
    }
    if (NewSection(heap) != 0) {
        return heap->mSectionList.mCount - 1;
    }
    NNS_FndFreeByStateToFrmHeap(heap->mHandle, 0);
    return -1;
}

// Frees the sections above level; level 0 clears the heap.
void NNS_SndHeapLoadState(NNSSndHeap *heap, s32 level) {
    NNSSndHeapSection *section;
    void *object = 0;
    u32 calledBack = 0;

    if (level == 0) {
        NNS_SndHeapClear(heap);
        return;
    }
    if (level < heap->mSectionList.mCount) {
        do {
            section = NNS_FndGetPrevListObject(&heap->mSectionList, 0);
            for (object = NNS_FndGetPrevListObject(&section->mBlockList, object); object != 0;
                 object = NNS_FndGetPrevListObject(&section->mBlockList, object)) {
                NNSSndHeapBlock *block = object;

                if (block->mCallback != 0) {
                    block->mCallback(block + 1, block->mSize, block->mData1, block->mData2);
                    calledBack = 1;
                }
            }
            NNS_FndRemoveListObject(&heap->mSectionList, section);
        } while (level < heap->mSectionList.mCount);
    }
    NNS_FndFreeByStateToFrmHeap(heap->mHandle, level);
    if (calledBack != 0) {
        EraseSync();
    }
    NNS_FndRecordStateForFrmHeap(heap->mHandle, heap->mSectionList.mCount);
    NewSection(heap);
}

s32 NNS_SndHeapGetCurrentLevel(NNSSndHeap *heap) {
    return heap->mSectionList.mCount - 1;
}

void InitHeapSection(NNSSndHeapSection *section) {
    NNS_FndInitList(&section->mBlockList, 0);
}

BOOL InitHeap(NNSSndHeap *heap, void *handle) {
    NNS_FndInitList(&heap->mSectionList, 12);
    heap->mHandle = handle;
    return NewSection(heap) != 0;
}

BOOL NewSection(NNSSndHeap *heap) {
    NNSSndHeapSection *section;

    section = NNS_FndAllocFromFrmHeapEx(heap->mHandle, 0x14, 4);
    if (section == 0) {
        return 0;
    }
    InitHeapSection(section);
    NNS_FndAppendListObject(&heap->mSectionList, section);
    return 1;
}

void EraseSync(void) {
    u32 commandTag;

    commandTag = SND_GetCurrentCommandTag();
    SND_FlushCommand(1);
    SND_WaitForCommandProc(commandTag);
}

void NNS_SndArcInit(NNSSndArc *arc, const u8 *filePath, NNSSndHeap *heap, BOOL symbolLoadFlag) {
    arc->mInfo = 0;
    arc->mFat = 0;
    arc->mSymbol = 0;
    if (FS_ConvertPathToFileID(&arc->mFileId, filePath) == 0) {
        return;
    }
    FS_InitFile(&arc->mFile);
    if (FS_OpenFileFast(&arc->mFile, arc->mFileId) == 0) {
        return;
    }
    arc->mFileOpen = 1;
    if (NNS_SndArcSetup(arc, heap, symbolLoadFlag) != 0) {
        data_0217dec4 = arc;
    }
}

BOOL NNS_SndArcSetup(NNSSndArc *arc, NNSSndHeap *heap, BOOL symbolLoadFlag) {
    s32 readSize;

    if (FS_SeekFile(&arc->mFile, 0, 0) == 0) {
        return 0;
    }
    if (FS_ReadFile(&arc->mFile, &arc->mHeader, 0x30) != 0x30) {
        return 0;
    }
    if (heap != 0) {
        arc->mInfo = NNS_SndHeapAlloc(heap, arc->mHeader.mInfoSize, InfoDisposeCallback, arc, 0);
        if (arc->mInfo == 0) {
            return 0;
        }
        if (FS_SeekFile(&arc->mFile, arc->mHeader.mInfoOffset, 0) == 0) {
            return 0;
        }
        readSize = FS_ReadFile(&arc->mFile, arc->mInfo, arc->mHeader.mInfoSize);
        if (readSize != arc->mHeader.mInfoSize) {
            return 0;
        }
        arc->mFat = NNS_SndHeapAlloc(heap, arc->mHeader.mFatSize, FatDisposeCallback, arc, 0);
        if (arc->mFat == 0) {
            return 0;
        }
        if (FS_SeekFile(&arc->mFile, arc->mHeader.mFatOffset, 0) == 0) {
            return 0;
        }
        readSize = FS_ReadFile(&arc->mFile, arc->mFat, arc->mHeader.mFatSize);
        if (readSize != arc->mHeader.mFatSize) {
            return 0;
        }
        if (symbolLoadFlag != 0 && arc->mHeader.mSymbolDataSize != 0) {
            arc->mSymbol = NNS_SndHeapAlloc(heap, arc->mHeader.mSymbolDataSize, SymbolDisposeCallback, arc, 0);
            if (arc->mSymbol == 0) {
                return 0;
            }
            if (FS_SeekFile(&arc->mFile, arc->mHeader.mSymbolDataOffset, 0) == 0) {
                return 0;
            }
            readSize = FS_ReadFile(&arc->mFile, arc->mSymbol, arc->mHeader.mSymbolDataSize);
            if (readSize != arc->mHeader.mSymbolDataSize) {
                return 0;
            }
        }
    }
    return 1;
}

// Points the blocks and files into an archive already in memory.
void NNS_SndArcInitOnMemory(NNSSndArc *arc, void *data) {
    u32 i;

    MIi_CpuCopy32(data, &arc->mHeader, 0x30);
    arc->mInfo = arc->mHeader.mInfoOffset == 0 ? 0 : OFFSET_PTR(NNSSndArcInfo, data, arc->mHeader.mInfoOffset);
    arc->mFat = arc->mHeader.mFatOffset == 0 ? 0 : OFFSET_PTR(NNSSndArcFat, data, arc->mHeader.mFatOffset);
    arc->mSymbol =
        arc->mHeader.mSymbolDataOffset == 0 ? 0 : OFFSET_PTR(NNSSndArcSymbol, data, arc->mHeader.mSymbolDataOffset);
    for (i = 0; i < arc->mFat->mCount; i++) {
        NNSSndArcFileInfo *file = &arc->mFat->mFiles[i];

        file->mMem = file->mOffset == 0 ? 0 : (u8 *) data + file->mOffset;
    }
    arc->mFileOpen = 0;
    data_0217dec4 = arc;
}

NNSSndArc *NNS_SndArcSetCurrent(NNSSndArc *arc) {
    NNSSndArc *oldArc = data_0217dec4;

    data_0217dec4 = arc;
    return oldArc;
}

NNSSndArc *NNS_SndArcGetCurrent(void) {
    return data_0217dec4;
}

NNSSndSeqParam *NNS_SndArcGetSeqArcParam(s32 seqArcNo, s32 index) {
    NNSSndArcSeqArcInfo *info;
    Unk0212f788 *seqArc;
    NNSSndSeqArcSeqInfo *sound;

    info = NNS_SndArcGetSeqArcInfo(seqArcNo);
    if (info == 0) {
        return 0;
    }
    seqArc = NNS_SndArcGetFileAddress(info->mFileId);
    if (seqArc == 0) {
        return 0;
    }
    sound = NNSi_SndSeqArcGetSeqInfo(seqArc, index);
    if (sound == 0) {
        return 0;
    }
    return &sound->mParam;
}

NNSSndArcSeqInfo *NNS_SndArcGetSeqInfo(s32 seqNo) {
    NNSSndArc *arc = data_0217dec4;
    NNSSndArcOffsetTable *table;
    u32 offset;
    u8 *base;

    offset = arc->mInfo->mSeqOffset;
    table = offset == 0 ? 0 : OFFSET_PTR(NNSSndArcOffsetTable, arc->mInfo, offset);
    if (table == 0) {
        return 0;
    }
    if (seqNo < 0) {
        return 0;
    }
    if (seqNo >= table->mCount) {
        return 0;
    }
    offset = table->mOffset[seqNo];
    base = (u8 *) arc->mInfo;
    return offset == 0 ? 0 : (NNSSndArcSeqInfo *) (base + offset);
}

NNSSndArcSeqArcInfo *NNS_SndArcGetSeqArcInfo(s32 seqArcNo) {
    NNSSndArc *arc = data_0217dec4;
    NNSSndArcOffsetTable *table;
    u32 offset;
    u8 *base;

    offset = arc->mInfo->mSeqArcOffset;
    table = offset == 0 ? 0 : OFFSET_PTR(NNSSndArcOffsetTable, arc->mInfo, offset);
    if (table == 0) {
        return 0;
    }
    if (seqArcNo < 0) {
        return 0;
    }
    if (seqArcNo >= table->mCount) {
        return 0;
    }
    offset = table->mOffset[seqArcNo];
    base = (u8 *) arc->mInfo;
    return offset == 0 ? 0 : (NNSSndArcSeqArcInfo *) (base + offset);
}

NNSSndArcBankInfo *NNS_SndArcGetBankInfo(s32 bankNo) {
    NNSSndArc *arc = data_0217dec4;
    NNSSndArcOffsetTable *table;
    u32 offset;
    u8 *base;

    offset = arc->mInfo->mBankOffset;
    table = offset == 0 ? 0 : OFFSET_PTR(NNSSndArcOffsetTable, arc->mInfo, offset);
    if (table == 0) {
        return 0;
    }
    if (bankNo < 0) {
        return 0;
    }
    if (bankNo >= table->mCount) {
        return 0;
    }
    offset = table->mOffset[bankNo];
    base = (u8 *) arc->mInfo;
    return offset == 0 ? 0 : (NNSSndArcBankInfo *) (base + offset);
}

NNSSndArcWaveArcInfo *NNS_SndArcGetWaveArcInfo(s32 waveArcNo) {
    NNSSndArc *arc = data_0217dec4;
    NNSSndArcOffsetTable *table;
    u32 offset;
    u8 *base;

    offset = arc->mInfo->mWaveArcOffset;
    table = offset == 0 ? 0 : OFFSET_PTR(NNSSndArcOffsetTable, arc->mInfo, offset);
    if (table == 0) {
        return 0;
    }
    if (waveArcNo < 0) {
        return 0;
    }
    if (waveArcNo >= table->mCount) {
        return 0;
    }
    offset = table->mOffset[waveArcNo];
    base = (u8 *) arc->mInfo;
    return offset == 0 ? 0 : (NNSSndArcWaveArcInfo *) (base + offset);
}

NNSSndArcPlayerInfo *NNS_SndArcGetPlayerInfo(s32 playerNo) {
    NNSSndArc *arc = data_0217dec4;
    NNSSndArcOffsetTable *table;
    u32 offset;
    u8 *base;

    offset = arc->mInfo->mPlayerInfoOffset;
    table = offset == 0 ? 0 : OFFSET_PTR(NNSSndArcOffsetTable, arc->mInfo, offset);
    if (table == 0) {
        return 0;
    }
    if (playerNo < 0) {
        return 0;
    }
    if (playerNo >= table->mCount) {
        return 0;
    }
    offset = table->mOffset[playerNo];
    base = (u8 *) arc->mInfo;
    return offset == 0 ? 0 : (NNSSndArcPlayerInfo *) (base + offset);
}

NNSSndArcGroupInfo *NNS_SndArcGetGroupInfo(s32 groupNo) {
    NNSSndArc *arc = data_0217dec4;
    NNSSndArcOffsetTable *table;
    u32 offset;
    u8 *base;

    offset = arc->mInfo->mGroupInfoOffset;
    table = offset == 0 ? 0 : OFFSET_PTR(NNSSndArcOffsetTable, arc->mInfo, offset);
    if (table == 0) {
        return 0;
    }
    if (groupNo < 0) {
        return 0;
    }
    if (groupNo >= table->mCount) {
        return 0;
    }
    offset = table->mOffset[groupNo];
    base = (u8 *) arc->mInfo;
    return offset == 0 ? 0 : (NNSSndArcGroupInfo *) (base + offset);
}

u32 NNS_SndArcGetFileSize(u32 fileId) {
    NNSSndArcFat *fat = data_0217dec4->mFat;

    if (fileId >= fat->mCount) {
        return 0;
    }
    return fat->mFiles[fileId].mSize;
}

// Returns the number of bytes read, or -1.
s32 NNS_SndArcReadFile(u32 fileId, void *buffer, u32 size, u32 offset) {
    NNSSndArc *arc = data_0217dec4;
    NNSSndArcFat *fat;
    NNSSndArcFileInfo *file;
    u32 left;

    fat = arc->mFat;
    if (fileId >= fat->mCount) {
        return -1;
    }
    file = &fat->mFiles[fileId];
    left = file->mSize - offset;
    if (size > left) {
        size = left;
    }
    if (FS_SeekFile(&arc->mFile, file->mOffset + offset, 0) == 0) {
        return -1;
    }
    return FS_ReadFile(&arc->mFile, buffer, size);
}

void *NNS_SndArcGetFileAddress(u32 fileId) {
    NNSSndArcFat *fat = data_0217dec4->mFat;

    if (fileId >= fat->mCount) {
        return 0;
    }
    return fat->mFiles[fileId].mMem;
}

void NNS_SndArcSetFileAddress(u32 fileId, void *address) {
    data_0217dec4->mFat->mFiles[fileId].mMem = address;
}

void InfoDisposeCallback(void *mem, u32 size, void *data1, u32 data2) {
    NNSSndArc *arc = data1;

    arc->mInfo = 0;
}

void FatDisposeCallback(void *mem, u32 size, void *data1, u32 data2) {
    NNSSndArc *arc = data1;

    arc->mFat = 0;
}

void SymbolDisposeCallback(void *mem, u32 size, void *data1, u32 data2) {
    NNSSndArc *arc = data1;

    arc->mSymbol = 0;
}
