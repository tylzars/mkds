#include "code_0212ee54.h"

#include "code_0200fc8c.h"
#include "code_020172d0.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02003be0.h"
#include "code_0200e77c.h"
#include "code_0212f788.h"
#include "code_0212c7f0.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/unk_0217e000.h"
#include "Main/Unknown/unk_02152000.h"

// Steps the four stream players: start, volume and fade-out.
void NNSi_SndArcStrmMain(void) {
    s32 i;
    s32 initVolume;
    s32 volume;
    Unk0212c7f0 *player;

    player = data_0217e404;
    for (i = 0; i < 4; i++, player++) {
        if (!player->mUnk_110_0) {
            continue;
        }
        if (player->mUnk_114 == 0) {
            ForceStopStrm_(player);
            continue;
        }
        if (player->mUnk_110_2 && player->mUnk_118 != 0) {
            NNS_SndStrmStart(&player->mStream);
            player->mUnk_110_1 = 1;
            player->mUnk_110_2 = 0;
        }
        if (player->mUnk_110_1) {
            NNSi_SndFaderUpdate(&player->mUnk_e8);
            initVolume = data_02152ce4[player->mUnk_154];
            volume = data_02152ce4[NNSi_SndFaderGet(&player->mUnk_e8) >> 8];
            volume += initVolume;
            if (volume != player->mUnk_158) {
                NNS_SndStrmSetVolume(&player->mStream, volume);
                player->mUnk_158 = volume;
            }
            if (player->mUnk_110_3) {
                if (NNSi_SndFaderIsFinished(&player->mUnk_e8) != 0) {
                    ForceStopStrm_(player);
                }
            }
        }
    }
}

void FreePlayer(Unk0212c7f0 *player) {
    if (player->mUnk_14c != 0) {
        *player->mUnk_14c = 0;
        player->mUnk_14c = 0;
    }
    player->mUnk_110_0 = 0;
    player->mUnk_110_2 = 0;
    player->mUnk_110_1 = 0;
}

// Stops the player with the thread mutexes held.
void ForceStopStrm_(Unk0212c7f0 *player) {
    OS_LockMutex(&data_0217e3e0);
    if (data_0217df04 != 0) {
        OS_LockMutex(&data_0217df04->mMutex);
    }
    if (player->mUnk_110_1) {
        NNS_SndStrmStop(&player->mStream);
    }
    if (player->mUnk_110_0) {
        FS_CancelFile(&player->mFile);
    }
    ShutdownPlayer_(player);
    OS_UnlockMutex(&data_0217e3e0);
    if (data_0217df04 != 0) {
        OS_UnlockMutex(&data_0217df04->mMutex);
    }
}

// Frees the channels and file and drops the player's load commands.
void ShutdownPlayer_(Unk0212c7f0 *player) {
    if (!player->mUnk_110_0) {
        return;
    }
    FreeChannel(player);
    FS_CloseFile(&player->mFile);
    RemoveCommandByPlayer(&data_0217e3f8, player);
    if (data_0217df04 != 0) {
        RemoveCommandByPlayer(&data_0217df04->mCommandList, player);
    }
    FreePlayer(player);
}

// Frees the stream channel when the count reaches 0.
void FreeChannel(Unk0212c7f0 *player) {
    if (player->mUnk_120 == 0) {
        return;
    }
    player->mUnk_120 = player->mUnk_120 - 1;
    if (player->mUnk_120 != 0) {
        return;
    }
    NNS_SndStrmFreeChannel(&player->mStream);
}

void RemoveCommandByPlayer(NNSFndList *commandList, Unk0212c7f0 *player) {
    u32 enabled;
    LoadCommand *command;
    LoadCommand *next;

    enabled = OS_DisableInterrupts();
    command = NNS_FndGetNextListObject(commandList, 0);
    if (command != 0) {
        do {
            next = NNS_FndGetNextListObject(commandList, command);
            if (command->mPlayer == player) {
                NNS_FndRemoveListObject(commandList, command);
                FreeCommandBuffer(command);
            }
            command = next;
        } while (command != 0);
    }
    OS_RestoreInterrupts(enabled);
}

void FreeCommandBuffer(LoadCommand *command) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    NNS_FndAppendListObject((NNSFndList *) data_0217df08, command);
    OS_RestoreInterrupts(enabled);
}
