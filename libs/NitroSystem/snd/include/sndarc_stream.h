#pragma once

#include "types.h"
#include "code_0212d214.h"
#include "code_0200e77c.h"

// Element of a command list (links at 0): the stream player the command belongs to.
typedef struct LoadCommand {
    /* 00 */ u8 mLink[8];
    /* 08 */ void *mPlayer;
} LoadCommand;

// Stream thread: its mutex and the list of load commands.
typedef struct NNSSndStrmThread {
    /* 000 */ u8 mThread[0x4cc];
    /* 4cc */ OSMutex mMutex;
    /* 4e4 */ NNSFndList mCommandList;
} NNSSndStrmThread;

#include "stream.h" // Unk0212c7f0

void FreeCommandBuffer(LoadCommand *command);
void RemoveCommandByPlayer(NNSFndList *commandList, Unk0212c7f0 *player);
void FreeChannel(Unk0212c7f0 *player);
void ShutdownPlayer_(Unk0212c7f0 *player);
void ForceStopStrm_(Unk0212c7f0 *player);
void FreePlayer(Unk0212c7f0 *player);
void NNSi_SndArcStrmMain(void);
