#include "code_0212bcac.h"

#include "code_020172d0.h"
#include "code_020207ec.h"
#include "code_02020eb0.h"
#include "code_02021764.h"
#include "code_0212c7a0.h"
#include "code_0212d214.h"
#include "code_0212f788.h"
#include "code_0201750c.h"
#include "Main/Unknown/code_02017000.h"
#include "code_0201ec30.h"
#include "Main/Unknown/code_02021000.h"
#include "code_0212f864.h"
#include "Main/Unknown/unk_02152000.h"
#include "Main/Unknown/unk_0217d000.h"

// Allocates a player heap of size bytes from heap, sets up its own heap on it and adds it to the heap list of player
// index.
BOOL NNS_SndPlayerCreateHeap(int index, NNSSndHeap *heap, u32 size) {
    NNSSndPlayerHeap *block;
    NNSSndHeap *inner;

    block = NNS_SndHeapAlloc(heap, size + 0x14, PlayerHeapDisposeCallback, 0, 0);
    if (block == 0) {
        return 0;
    }
    block->mPlayer = 0;
    block->mPlayerNo = index;
    block->mHandle = 0;
    inner = NNS_SndHeapCreate(block->mUnk_14, size);
    if (inner == 0) {
        return 0;
    }
    block->mHandle = inner;
    NNS_FndAppendListObject(&data_0217d89c[index].mHeapList, block);
    return 1;
}

// Stops the sequence of handle, with a fade of fadeSteps steps.
u32 NNS_SndPlayerStopSeq(NNSSndSeqPlayer **handle, u32 fadeSteps) {
    NNSi_SndPlayerStopSeq(*handle, fadeSteps);
}

// Stops every sequence player that is in use.
void NNS_SndPlayerStopSeqAll(u32 fadeSteps) {
    s32 i;
    NNSSndSeqPlayer *seq;

    for (i = 0, seq = data_0217d45c; i < 16; i++) {
        if (seq->mStatus != 0) {
            NNSi_SndPlayerStopSeq(seq, fadeSteps);
        }
        seq++;
    }
}

// Clears handle.
void NNS_SndHandleInit(NNSSndSeqPlayer **handle) {
    *handle = 0;
}

// Detaches handle from its sequence player.
void NNS_SndHandleReleaseSeq(NNSSndSeqPlayer **handle) {
    NNSSndSeqPlayer *seq = *handle;

    if (seq != 0) {
        seq->mHandle = 0;
        *handle = 0;
    }
}

// Sets NNSSndSeqPlayer.mExtVolume.
NNSSndSeqPlayer *NNS_SndPlayerSetVolume(NNSSndSeqPlayer **handle, int volume) {
    NNSSndSeqPlayer *seq = *handle;

    if (seq != 0) {
        seq->mExtVolume = volume;
    }
    return seq;
}

// Sets NNSSndSeqPlayer.mInitVolume.
void NNS_SndPlayerSetInitialVolume(NNSSndSeqPlayer **handle, int volume) {
    if (*handle != 0) {
        (*handle)->mInitVolume = volume;
    }
}

// Fades the volume of handle to target over a number of steps, unless the sequence is already fading out.
void NNS_SndPlayerMoveVolume(NNSSndSeqPlayer **handle, int target, int steps) {
    NNSSndSeqPlayer *seq = *handle;

    if (seq == 0) {
        return;
    }
    if (seq->mStatus == 2) {
        return;
    }
    NNSi_SndFaderSet(&seq->mFader, target << 8, steps);
}

// Sets the priority of the sequence player of handle.
void NNS_SndPlayerSetPlayerPriority(NNSSndSeqPlayer **handle, int priority) {
    if (*handle == 0) {
        return;
    }
    SetPlayerPriority(*handle, priority);
}

// Sets the channel priority of the sequence player of handle.
void NNS_SndPlayerSetChannelPriority(NNSSndSeqPlayer **handle, int priority) {
    NNSSndSeqPlayer *seq = *handle;

    if (seq == 0) {
        return;
    }
    SND_SetPlayerChannelPriority(seq->mPlayerNo, priority);
}

// Mutes the tracks selected by tracks of handle.
void NNS_SndPlayerSetTrackMuteEx(NNSSndSeqPlayer **handle, u32 tracks, int mute) {
    NNSSndSeqPlayer *seq = *handle;

    if (seq == 0) {
        return;
    }
    SND_SetTrackMuteEx(seq->mPlayerNo, tracks, mute);
}

// Sets the volume of the tracks selected by tracks, converted to a decibel value.
void NNS_SndPlayerSetTrackVolume(NNSSndSeqPlayer **handle, u32 tracks, int volume) {
    NNSSndSeqPlayer *seq = *handle;

    if (seq == 0) {
        return;
    }
    SND_SetTrackVolume(seq->mPlayerNo, tracks, data_02152ce4[volume]);
}

// Sets the pitch of the tracks selected by tracks.
void NNS_SndPlayerSetTrackPitch(NNSSndSeqPlayer **handle, u32 tracks, int pitch) {
    NNSSndSeqPlayer *seq = *handle;

    if (seq == 0) {
        return;
    }
    SND_SetTrackPitch(seq->mPlayerNo, tracks, pitch);
}

// Sets the pan of the tracks selected by tracks.
u32 NNS_SndPlayerSetTrackPan(NNSSndSeqPlayer **handle, u32 tracks, int pan) {
    NNSSndSeqPlayer *seq = *handle;

    if (seq == 0) {
        return (u32) seq;
    }
    SND_SetTrackPan(seq->mPlayerNo, tracks, pan);
}

// Sets the modulation speed of the tracks selected by tracks.
void NNS_SndPlayerSetTrackModSpeed(NNSSndSeqPlayer **handle, u32 tracks, int speed) {
    NNSSndSeqPlayer *seq = *handle;

    if (seq == 0) {
        return;
    }
    SND_SetTrackModSpeed(seq->mPlayerNo, tracks, speed);
}

// Sets the tempo ratio of the sequence of handle.
void NNS_SndPlayerSetTempoRatio(NNSSndSeqPlayer **handle, int ratio) {
    NNSSndSeqPlayer *seq = *handle;

    if (seq == 0) {
        return;
    }
    SND_SetPlayerTempoRatio(seq->mPlayerNo, ratio);
}

// Marks the sequence of handle as a plain sequence number: NNSSndSeqPlayer.mSeqType 1 and NNSSndSeqPlayer.mSeqNo.
void NNS_SndPlayerSetSeqNo(NNSSndSeqPlayer **handle, int number) {
    NNSSndSeqPlayer *seq = *handle;

    if (seq != 0) {
        seq->mSeqType = 1;
        (*handle)->mSeqNo = number;
    }
}

// Marks the sequence of handle as a sequence archive entry: NNSSndSeqPlayer.mSeqType 2, NNSSndSeqPlayer.mSeqNo and
// NNSSndSeqPlayer.mSeqArcIndex.
void NNS_SndPlayerSetSeqArcNo(NNSSndSeqPlayer **handle, int archive, int index) {
    if (*handle == 0) {
        return;
    }
    (*handle)->mSeqType = 2;
    (*handle)->mSeqNo = archive;
    (*handle)->mSeqArcIndex = index;
}

NNSFndList data_0217d450;
NNSFndList data_0217d444;

// Reads the sequence variable number variable of the sequence of handle into value; 0 for a handle without a sequence
// player, -1 until the sequence has started.
BOOL NNS_SndPlayerReadVariable(NNSSndSeqPlayer **handle, int variable, s16 *value) {
    NNSSndSeqPlayer *seq = *handle;

    if (seq == 0) {
        return 0;
    }
    if (seq->mStartFlag == 0) {
        *value = -1;
        return 1;
    }
    *value = SND_GetPlayerLocalVariable(seq->mPlayerNo, variable);
    return 1;
}

// Writes value to the sequence variable number variable of the sequence of handle.
BOOL NNS_SndPlayerWriteVariable(NNSSndSeqPlayer **handle, int variable, s16 value) {
    if (*handle == 0) {
        return 0;
    }
    SND_SetPlayerLocalVariable((*handle)->mPlayerNo, variable, value);
    return 1;
}

// Sets up the lists of busy and free sequence players, and the player objects.
void NNSi_SndPlayerInit(void) {
    s32 i;
    NNSSndSeqPlayer *seq;
    NNSSndPlayer *player;

    NNS_FndInitList(&data_0217d450, 0x14);
    NNS_FndInitList(&data_0217d444, 0x14);
    for (i = 0, seq = data_0217d45c; i < 16; i++, seq++) {
        seq->mStatus = 0;
        seq->mPlayerNo = i;
        NNS_FndAppendListObject(&data_0217d444, seq);
    }
    for (i = 0, player = data_0217d89c; i < 32; i++, player++) {
        NNS_FndInitList(&player->mPlayerList, 0xc);
        NNS_FndInitList(&player->mHeapList, 0);
        player->mVolume = 0x7f;
        player->mPlayableSeqCount = 1;
        player->mAllocChBitFlag = 0;
    }
}

// Updates every busy sequence player: marks the started ones, shuts down the finished ones, steps the fader and
// sets the player volume from the volume factors.
void NNSi_SndPlayerMain(void) {
    u32 status;
    NNSSndSeqPlayer *seq;
    NNSSndSeqPlayer *next;
    s32 extDecibel;
    s32 initDecibel;
    s32 playerDecibel;
    s32 volume;

    status = SND_GetPlayerStatus();
    for (seq = NNS_FndGetNextListObject(&data_0217d450, 0); seq != 0; seq = next) {
        next = NNS_FndGetNextListObject(&data_0217d450, seq);
        if (seq->mStartFlag == 0 && SND_IsFinishedCommandTag(seq->mCommandTag) != 0) {
            seq->mStartFlag = 1;
        }
        if (seq->mStartFlag != 0 && (status & (1 << seq->mPlayerNo)) == 0) {
            ShutdownPlayer(seq);
            continue;
        }
        NNSi_SndFaderUpdate(&seq->mFader);
        extDecibel = data_02152ce4[seq->mExtVolume];
        initDecibel = data_02152ce4[seq->mInitVolume];
        playerDecibel = data_02152ce4[seq->mPlayer->mVolume];
        volume = data_02152ce4[NNSi_SndFaderGet(&seq->mFader) >> 8];
        volume += playerDecibel + (initDecibel + extDecibel);
        if (volume < -723) {
            volume = -723;
        } else if (volume > 0) {
            volume = 0;
        }
        if (volume != seq->mVolume) {
            SND_SetPlayerVolume(seq->mPlayerNo, volume);
            seq->mVolume = volume;
        }
        if (seq->mStatus == 2 && NNSi_SndFaderIsFinished(&seq->mFader) != 0) {
            ForceStopSeq(seq);
        }
        if (seq->mPrepareFlag != 0) {
            SND_StartPreparedSeq(seq->mPlayerNo);
            seq->mPrepareFlag = 0;
        }
    }
}

// Attaches a sequence player of player index to handle after letting go of the one it held. A full player or a
// full set of sequence players gives up its lowest priority sequence when priority is not lower than it. Returns 0
// when none could be taken.
NNSSndSeqPlayer *NNSi_SndPlayerAllocSeqPlayer(NNSSndSeqPlayer **handle, int index, int priority) {
    NNSSndSeqPlayer *seq = *handle;
    NNSSndPlayer *player = &data_0217d89c[index];

    if (seq != 0) {
        NNS_SndHandleReleaseSeq(handle);
    }
    if (player->mPlayerList.mCount >= player->mPlayableSeqCount) {
        seq = NNS_FndGetNextListObject(&player->mPlayerList, 0);
        if (seq == 0) {
            return 0;
        }
        if (priority < seq->mPrio) {
            return 0;
        }
        ForceStopSeq(seq);
    }
    seq = AllocSeqPlayer(priority);
    if (seq == 0) {
        return 0;
    }
    InsertPlayerList(player, seq);
    seq->mHandle = handle;
    *handle = seq;
    return seq;
}

// Gives a sequence player back.
void NNSi_SndPlayerFreeSeqPlayer(NNSSndSeqPlayer *seq) {
    ShutdownPlayer(seq);
}

// Prepares the sequence at offset of data on the sequence player, restricts its tracks to the channels
// of the player when it has any, and marks it as playing.
void NNSi_SndPlayerStartSeq(NNSSndSeqPlayer *seq, void *data, u32 offset, Unk02021968 *bank) {
    NNSSndPlayer *player = seq->mPlayer;

    SND_PrepareSeq(seq->mPlayerNo, data, offset, bank);
    if (player->mAllocChBitFlag != 0) {
        SND_SetTrackAllocatableChannel(seq->mPlayerNo, 0xffff, player->mAllocChBitFlag);
    }
    InitPlayer(seq);
    seq->mCommandTag = SND_GetCurrentCommandTag();
    seq->mPrepareFlag = 1;
    seq->mStatus = 1;
}

// Stops a playing sequence player at once for a fade of 0; otherwise starts the fade out and lowers its priority.
void NNSi_SndPlayerStopSeq(NNSSndSeqPlayer *seq, int fadeSteps) {
    if (seq == 0) {
        return;
    }
    if (seq->mStatus == 0) {
        return;
    }
    if (fadeSteps == 0) {
        ForceStopSeq(seq);
        return;
    }
    NNSi_SndFaderSet(&seq->mFader, 0, fadeSteps);
    SetPlayerPriority(seq, 0);
    seq->mStatus = 2;
}

// Takes a free player heap of index for seq, empties it and returns its heap.
NNSSndHeap *NNSi_SndPlayerAllocHeap(int index, NNSSndSeqPlayer *seq) {
    NNSSndPlayer *player = &data_0217d89c[index];
    NNSSndPlayerHeap *heap;

    heap = NNS_FndGetNextListObject(&player->mHeapList, 0);
    if (heap == 0) {
        return 0;
    }
    NNS_FndRemoveListObject(&player->mHeapList, heap);
    heap->mPlayer = seq;
    seq->mHeap = heap;
    NNS_SndHeapClear(heap->mHandle);
    return heap->mHandle;
}

// Resets the state of seq for a new sequence and starts its fader at full volume.
void InitPlayer(NNSSndSeqPlayer *seq) {
    seq->mPauseFlag = 0;
    seq->mStartFlag = 0;
    seq->mPrepareFlag = 0;
    seq->mSeqType = 0;
    seq->mVolume = 0;
    seq->mInitVolume = 0x7f;
    seq->mExtVolume = 0x7f;
    InterpolatorInit(&seq->mFader);
    NNSi_SndFaderSet(&seq->mFader, 0x7f00, 1);
}

// Inserts seq into the sequence player list of player, ordered by priority.
void InsertPlayerList(NNSSndPlayer *player, NNSSndSeqPlayer *seq) {
    NNSSndSeqPlayer *next;

    for (next = NNS_FndGetNextListObject(&player->mPlayerList, 0); next != 0;
         next = NNS_FndGetNextListObject(&player->mPlayerList, next)) {
        if (seq->mPrio < next->mPrio) {
            break;
        }
    }
    NNS_FndInsertListObject(&player->mPlayerList, next, seq);
    seq->mPlayer = player;
}

// Inserts seq into the list of all busy sequence players, ordered by priority.
void InsertPrioList(NNSSndSeqPlayer *seq) {
    NNSSndSeqPlayer *next;

    for (next = NNS_FndGetNextListObject(&data_0217d450, 0); next != 0;
         next = NNS_FndGetNextListObject(&data_0217d450, next)) {
        if (seq->mPrio < next->mPrio) {
            break;
        }
    }
    NNS_FndInsertListObject(&data_0217d450, next, seq);
}

// Stops the sequence of seq at once and shuts the player down.
void ForceStopSeq(NNSSndSeqPlayer *seq) {
    if (seq->mStatus == 2) {
        SND_SetPlayerVolume(seq->mPlayerNo, -723);
    }
    SND_StopSeq(seq->mPlayerNo);
    ShutdownPlayer(seq);
}

// Takes the first free sequence player, or stops the lowest priority busy one when priority is not lower than its
// priority, and puts it into the busy list with priority priority. Returns 0 when none could be taken.
NNSSndSeqPlayer *AllocSeqPlayer(int priority) {
    NNSSndSeqPlayer *seq = NNS_FndGetNextListObject(&data_0217d444, 0);

    if (seq == 0) {
        seq = NNS_FndGetNextListObject(&data_0217d450, 0);
        if (priority < seq->mPrio) {
            return 0;
        }
        ForceStopSeq(seq);
    }
    NNS_FndRemoveListObject(&data_0217d444, seq);
    seq->mPrio = priority;
    InsertPrioList(seq);
    return seq;
}

// Detaches seq from its handle, player and player heap, and moves it from the busy list to the free list.
void ShutdownPlayer(NNSSndSeqPlayer *seq) {
    NNSSndPlayer *player;

    if (seq->mHandle != 0) {
        *seq->mHandle = 0;
        seq->mHandle = 0;
    }
    player = seq->mPlayer;
    NNS_FndRemoveListObject(&player->mPlayerList, seq);
    seq->mPlayer = 0;
    if (seq->mHeap != 0) {
        NNS_FndAppendListObject(&player->mHeapList, seq->mHeap);
        seq->mHeap->mPlayer = 0;
        seq->mHeap = 0;
    }
    NNS_FndRemoveListObject(&data_0217d450, seq);
    NNS_FndAppendListObject(&data_0217d444, seq);
    seq->mStatus = 0;
}

// Frees the heap of a player heap, and unlinks the player heap from the sequence player or from the heap list.
void PlayerHeapDisposeCallback(void *mem, u32 size, void *data1, u32 data2) {
    NNSSndPlayerHeap *heap = mem;

    if (heap->mHandle == 0) {
        return;
    }
    NNS_SndHeapDestroy(heap->mHandle);
    if (heap->mPlayer != 0) {
        heap->mPlayer->mHeap = 0;
        return;
    }
    NNS_FndRemoveListObject(&data_0217d89c[heap->mPlayerNo].mHeapList, heap);
}

// Moves seq to the place of priority in its player list and in the busy list.
void SetPlayerPriority(NNSSndSeqPlayer *seq, int priority) {
    NNSSndPlayer *player = seq->mPlayer;

    if (player != 0) {
        NNS_FndRemoveListObject(&player->mPlayerList, seq);
        seq->mPlayer = 0;
    }
    NNS_FndRemoveListObject(&data_0217d450, seq);
    seq->mPrio = priority;
    if (player != 0) {
        InsertPlayerList(player, seq);
    }
    InsertPrioList(seq);
}
