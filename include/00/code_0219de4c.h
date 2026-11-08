#pragma once

#include "types.h"

// The matching state embedded in WiFiConnection at 0x33c (0x464 bytes), reached through gWiFiMatching; not
// WiFiVSMatching, the VS screen.
typedef struct WiFiMatching {
    /* 000 */ struct GpConnection *mGpConnection;
    // Address of WiFiConnection.mSocket, so a socket made or cleared later is seen; every use except the NULL tests
    // dereferences it.
    /* 004 */ void **mConnectionSocket;
    // Address of the Gt2ConnectionCallbacks record in WiFiConnection, given to the connect calls.
    /* 008 */ struct Gt2ConnectionCallbacks *mConnectionCallbacks;
    /* 00c */ u8 mConnectRetryCount;
    // Position of the last participant: the lists hold mLastParticipantPos + 1 entries and 0 means nobody else.
    /* 00d */ u8 mLastParticipantPos;
    // One less than the number of bits set in mParticipantMask, 0 when none; used in place of mLastParticipantPos in
    // modes 2 and 3.
    /* 00e */ u8 mLastMaskedParticipantPos;
    /* 00f */ u8 mUnk_0f;
    /* 010 */ struct Unk021a4a08 *mUnk_10;
    /* 014 */ u8 mUnk_14;
    // 0 filter search, 1 buddy list (set by SetupMatching); the code also tests 2 and 3, which nothing sets.
    /* 015 */ volatile u8 mMode;
    /* 016 */ u8 mUnk_16;
    /* 017 */ u8 mMresvPresent;
    /* 018 */ u8 mUnk_18;
    /* 019 */ u8 mUnk_19;
    /* 01a */ u16 mOwnPort;
    /* 01c */ void *mOwnAddress;
    /* 020 */ u32 mMresvProfileId;
    // Address each participant's commands are sent to; mParticipantCommandPorts holds the matching ports.
    /* 024 */ u32 mParticipantCommandAddresses[32];
    /* 0a4 */ u16 mParticipantCommandPorts[32];
    /* 0e4 */ struct MatchingServerList *mServerList;
    /* 0e8 */ u32 mUnk_e8;
    /* 0ec */ u64 mUnk_ec;
    // GP profile id of each participant by position; the connection finds its own position by comparing
    // WiFiConnection.mProfileId.
    /* 0f4 */ u32 mParticipantProfileIds[32];
    /* 174 */ u8 mUnk_174[2];
    /* 176 */ u16 mUnk_176;
    /* 178 */ u32 mUnk_178;
    /* 17c */ u64 mUnk_17c;
    /* 184 */ u64 mIncomingWaitStartTime;
    /* 18c */ u8 mUnk_18c[8];
    /* 194 */ u32 mUnk_194;
    // Switched on by UpdateMatching when its parameter is 1; 0 means no search is running.
    /* 198 */ s32 mState;
    /* 19c */ u8 mUnk_19c;
    /* 19d */ u8 mBuddyEntryIndexPos;
    /* 19e */ u8 mUnk_19e;
    /* 19f */ u8 mUnk_19f;
    /* 1a0 */ u8 mUnk_1a0;
    /* 1a1 */ u8 mStopPending;
    /* 1a2 */ u8 mUnk_1a2;
    /* 1a3 */ u8 mUnk_1a3[2];
    /* 1a5 */ u8 mUnk_1a5;
    /* 1a6 */ u16 mUnk_1a6;
    /* 1a8 */ u16 mUnk_1a8;
    /* 1aa */ u16 mUnk_1aa;
    /* 1ac */ u32 mUnk_1ac;
    /* 1b0 */ u32 mUnk_1b0;
    /* 1b4 */ u64 mUnk_1b4;
    /* 1bc */ u32 mUnk_1bc;
    /* 1c0 */ u64 mUnk_1c0;
    /* 1c8 */ u32 mUnk_1c8;
    /* 1cc */ u32 mUnk_1cc;
    /* 1d0 */ u64 mLastPeerMessageSendTime;
    /* 1d8 */ u64 mUnk_1d8;
    /* 1e0 */ u64 mUnk_1e0;
    /* 1e8 */ u32 mOwnProfileId;
    /* 1ec */ u32 mReplyProfileId;
    /* 1f0 */ u32 mUnk_1f0;
    /* 1f4 */ u32 mUnk_1f4;
    // Address each participant is connected to; mParticipantConnectPorts holds the matching ports.
    /* 1f8 */ u32 mParticipantConnectAddresses[32];
    /* 278 */ u16 mParticipantConnectPorts[32];
    // u8[32] parallel to mParticipantProfileIds: the session index of each participant; the connection takes mOwnIndex
    // from it at its own position.
    /* 2b8 */ u8 mParticipantIndices[32];
    // One bit per participant index, rebuilt from mParticipantIndices; a bit is cleared when its participant leaves.
    /* 2d8 */ u32 mParticipantMask;
    // The game name buffer WiFiConnection.mGameName points to, given to the server list.
    /* 2dc */ const char *mGameName;
    // The key string data_ov000_021b4f84, given after the game name when the server list is created.
    /* 2e0 */ const char *mUnk_2e0;
    /* 2e4 */ u8 *mBuddies;
    /* 2e8 */ u32 mBuddyEntryCount;
    /* 2ec */ u8 mBuddyEntryIndices[0x40];
    /* 32c */ s32 mBuddyEntryIndexCount;
    /* 330 */ u32 mReceivedList[0x21];
    /* 3b4 */ u8 mLastCommand;
    /* 3b5 */ u8 mResendCount;
    /* 3b6 */ u16 mLastCommandPort;
    /* 3b8 */ u32 mLastCommandAddress;
    /* 3bc */ u8 mLastCommandValues[0x80];
    /* 43c */ u32 mLastCommandProfileId;
    /* 440 */ u32 mLastCommandValueCount;
    /* 444 */ u64 mLastCommandTime;
    // Set by SetupMatching; called with (error kind or 0, 0 or 1, ..., mResultCallbackArg), among others by
    // ReportMatchingError.
    /* 44c */ UnkFunc *mResultCallback;
    /* 450 */ u32 mResultCallbackArg;
    /* 454 */ void (*mUnk_454)(u32 a, u32 b);
    /* 458 */ u32 mUnk_458;
    /* 45c */ u32 mEvalCallback;
    /* 460 */ u32 mEvalCallbackArg;
} WiFiMatching;

// Points at WiFiConnection.mMatching: set by InitMatching, set to NULL by ReleaseMatching.
extern WiFiMatching *gWiFiMatching;

void SetMatchingOwnAddress(void *address, u16 port);
