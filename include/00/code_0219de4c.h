#pragma once

#include "types.h"

// Matching object (the partner search), embedded in WiFiConnection at 0x33c (0x464 bytes = 0x7a0-0x33c), reached
// through gWiFiMatching; not WiFiVSMatching (the VS lobby screen). 82 members, only the participant list, mode, state,
// callbacks, socket and GP pointers and the game name are named. InitMatching sets it up per login; UpdateMatching
// steps it (the state machine only when its parameter is 1); results go to mResultCallback = WiFiMatchingCallback.
typedef struct WiFiMatching {
    /* 000 */ struct GpConnection *mGpConnection;
    // Address of WiFiConnection.mSocket (declared void **), so the object sees the socket made or cleared later; every
    // use except the NULL tests dereferences it first.
    /* 004 */ void **mConnectionSocket;
    // Address of the Gt2ConnectionCallbacks record at WiFiConnection.mResultCallback (declared u32): given to the Gt2
    // connect calls (code_0219dd4c.c:453, :509, code_0219dabc.c:50).
    /* 008 */ u32 mConnectionCallbacks;
    /* 00c */ u8 mUnk_0c;
    /* 00d */ u8 mUnk_0d;
    /* 00e */ u8 mUnk_0e;
    /* 00f */ u8 mUnk_0f;
    /* 010 */ struct Unk021a4a08 *mUnk_10;
    /* 014 */ u8 mUnk_14;
    // Set by func_ov000_021a10b0: 0 filter search (func_ov000_021a260c), 1 buddy list (func_ov000_021a2468); the
    // connection code also tests 2 and 3 (modes 2 and 3 have no writer: func_ov000_021a10b0 has two BL callers, both
    // the starts), so those branches are not reached; cleared by the reset (code_0219dd4c.c:939).
    /* 015 */ volatile u8 mMode;
    /* 016 */ u8 mUnk_16;
    /* 017 */ u8 mUnk_17;
    /* 018 */ u8 mUnk_18;
    /* 019 */ u8 mUnk_19;
    /* 01a */ u16 mUnk_1a;
    /* 01c */ void *mUnk_1c;
    /* 020 */ u32 mUnk_20;
    /* 024 */ u32 mUnk_24[32];
    /* 0a4 */ u16 mUnk_a4[32];
    /* 0e4 */ void *mUnk_e4;
    /* 0e8 */ u32 mUnk_e8;
    /* 0ec */ u64 mUnk_ec;
    // u32[32]: GP profile id of each participant by position (0..mUnk_0d); the connection finds its own position by
    // comparing WiFiConnection.mProfileId.
    /* 0f4 */ u32 mParticipantProfileIds[32];
    /* 174 */ u8 mUnk_174[2];
    /* 176 */ u16 mUnk_176;
    /* 178 */ u32 mUnk_178;
    /* 17c */ u64 mUnk_17c;
    /* 184 */ u64 mUnk_184;
    /* 18c */ u8 mUnk_18c[8];
    /* 194 */ u32 mUnk_194;
    // UpdateMatching switches on it (cases 2, 3, 4, 5, 7, 11, 13) when its parameter is 1; the object writes it in 47
    // places (values 0 to 0x13), the connection reads it (0 = no search running).
    /* 198 */ s32 mState;
    /* 19c */ u8 mUnk_19c;
    /* 19d */ u8 mUnk_19d;
    /* 19e */ u8 mUnk_19e;
    /* 19f */ u8 mUnk_19f;
    /* 1a0 */ u8 mUnk_1a0;
    /* 1a1 */ u8 mUnk_1a1;
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
    /* 1d0 */ u64 mUnk_1d0;
    /* 1d8 */ u64 mUnk_1d8;
    /* 1e0 */ u64 mUnk_1e0;
    /* 1e8 */ u32 mUnk_1e8;
    /* 1ec */ u32 mUnk_1ec;
    /* 1f0 */ u32 mUnk_1f0;
    /* 1f4 */ u32 mUnk_1f4;
    /* 1f8 */ u32 mUnk_1f8[32];
    /* 278 */ u16 mUnk_278[32];
    // u8[32] parallel to mParticipantProfileIds: the session index of each participant; the connection takes mOwnIndex
    // from it at its own position.
    /* 2b8 */ u8 mParticipantIndices[32];
    // One bit per participant index (bit i = index i, like mKartMask): built by WiFiMatchingCallback from
    // mParticipantIndices, a participant's bit is cleared when it leaves (code_0219dd4c.c:728-731), tested by
    // func_ov000_0219bac8 (code_0219b580.c:411, the participant test the message layer uses) and func_ov000_0219b27c
    // (code_0219b1f8.c:100). Needs the Mask line in VOCABULARY.
    /* 2d8 */ u32 mParticipantMask;
    // Declared u32 holding a char *: the game name buffer (same as WiFiConnection.mGameName), given to the query-report
    // init (which reports it under the key 'gamename', code_021a3a18.c:828-829) and twice to func_ov000_0218b668 (the
    // search object at mUnk_e4, code_0219dd4c.c:162, :197).
    /* 2dc */ u32 mGameName;
    // Declared u32 holding a char *: the key string data_ov000_021b4f84 (see WiFiConnection.mUnk_58), given after the
    // game name to the query-report init (it keys the answer to the master server's challenge packet,
    // code_021a3a18.c:419) and to func_ov000_0218b668 (code_0219dd4c.c:163, :198).
    /* 2e0 */ u32 mUnk_2e0;
    /* 2e4 */ u32 mUnk_2e4;
    /* 2e8 */ u32 mUnk_2e8;
    /* 2ec */ u8 mUnk_2ec[0x40];
    /* 32c */ s32 mUnk_32c;
    /* 330 */ u32 mUnk_330[0x21];
    /* 3b4 */ u8 mUnk_3b4;
    /* 3b5 */ u8 mUnk_3b5;
    /* 3b6 */ u16 mUnk_3b6;
    /* 3b8 */ u32 mUnk_3b8;
    /* 3bc */ u8 mUnk_3bc[0x80];
    /* 43c */ u32 mUnk_43c;
    /* 440 */ u32 mUnk_440;
    /* 444 */ u64 mUnk_444;
    // Set by func_ov000_021a10b0 (WiFiMatchingCallback from both starts), declared UnkFunc *. Called with (error kind
    // or 0, 0 or 1, ..., mResultCallbackArg) from ReportMatchingError's address func_ov000_021a1a38
    // (code_0219dd4c.c:581) and three more sites (:2031, :2156, :2194).
    /* 44c */ UnkFunc *mResultCallback;
    /* 450 */ u32 mResultCallbackArg;
    /* 454 */ void (*mUnk_454)(u32 a, u32 b);
    /* 458 */ u32 mUnk_458;
    /* 45c */ u32 mUnk_45c;
    /* 460 */ u32 mUnk_460;
} WiFiMatching;

// Points at WiFiConnection.mMatching: set by InitMatching, set to NULL by func_ov000_021a1430 (code_0219dd4c.c:848; the
// release path).
extern WiFiMatching *gWiFiMatching;

void func_ov000_0219de4c(void *value, u16 index);
