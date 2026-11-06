#pragma once

#include "types.h"
#include "code_0212bcac.h"
#include "code_0212d214.h"

typedef enum NNSSndArcLoadResult {
    NNS_SND_ARC_LOAD_SUCESS,
    NNS_SND_ARC_LOAD_ERROR_INVALID_GROUP_NO,
    NNS_SND_ARC_LOAD_ERROR_INVALID_SEQ_NO,
    NNS_SND_ARC_LOAD_ERROR_INVALID_SEQARC_NO,
    NNS_SND_ARC_LOAD_ERROR_INVALID_BANK_NO,
    NNS_SND_ARC_LOAD_ERROR_INVALID_WAVEARC_NO,
    NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_SEQ,
    NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_SEQARC,
    NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_BANK,
    NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_WAVE
} NNSSndArcLoadResult;

extern u8 data_0217dec8[0x3c];

void WaveArcTableDisposeCallback(void *mem, u32 size, void *data1, u32 data2);
void WaveArcDisposeCallback(void *mem, u32 size, void *data1, u32 data2);
void BankDisposeCallback(void *mem, u32 size, void *data1, u32 data2);
void SeqDisposeCallback(void *mem, u32 size, void *data1, u32 data2);
void DisposeCallback(void *mem, NNSSndArc *arc, u32 fileId);
Unk02021968 *LoadWaveArcTable(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr);
Unk02021968 *LoadWaveArc(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr);
Unk02021968 *LoadBank(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr);
Unk0212f788 *LoadSeqArc(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr);
Unk0212f788 *LoadSeq(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr);
void *NNSi_SndArcLoadFile(u32 fileId, NNSSndHeapDisposeCallback callback, void *data1, u32 data2, NNSSndHeap *heap);
NNSSndArcLoadResult NNSi_SndArcLoadWaveArc(s32 waveArcNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr,
                                           Unk02021968 **pData);
NNSSndArcLoadResult NNSi_SndArcLoadBank(s32 bankNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr, Unk02021968 **pData);
NNSSndArcLoadResult NNSi_SndArcLoadSeqArc(s32 seqArcNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr,
                                          Unk0212f788 **pData);
NNSSndArcLoadResult NNSi_SndArcLoadSeq(s32 seqNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr, Unk0212f788 **pData);
NNSSndArcLoadResult NNSi_SndArcLoadGroup(s32 groupNo, NNSSndHeap *heap);
BOOL NNS_SndArcLoadBankEx(s32 bankNo, u32 loadFlag, NNSSndHeap *heap);
BOOL NNS_SndArcLoadWaveArc(s32 waveArcNo, NNSSndHeap *heap);
BOOL NNS_SndArcLoadBank(s32 bankNo, NNSSndHeap *heap);
BOOL NNS_SndArcLoadSeqArc(s32 seqArcNo, NNSSndHeap *heap);
BOOL NNS_SndArcLoadSeq(s32 seqNo, NNSSndHeap *heap);
BOOL NNS_SndArcLoadGroup(s32 groupNo, NNSSndHeap *heap);
BOOL StartSeqArc(NNSSndSeqPlayer **handle, s32 playerNo, s32 bankNo, s32 playerPrio, NNSSndSeqArcSeqInfo *sound,
                 Unk0212f788 *seqArc, u32 seqArcNo, u32 index);
BOOL StartSeq(NNSSndSeqPlayer **handle, s32 playerNo, s32 bankNo, s32 playerPrio, NNSSndArcSeqInfo *info, s32 seqNo);
BOOL NNS_SndArcPlayerStartSeqArcEx(NNSSndSeqPlayer **handle, s32 playerNo, s32 bankNo, s32 playerPrio, s32 seqArcNo,
                                   s32 index);
BOOL NNS_SndArcPlayerStartSeqArc(NNSSndSeqPlayer **handle, u32 seqArcNo, u32 index);
BOOL NNS_SndArcPlayerStartSeq(NNSSndSeqPlayer **handle, s32 seqNo);
BOOL NNS_SndArcPlayerSetup(NNSSndHeap *heap);
