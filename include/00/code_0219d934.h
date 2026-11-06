#pragma once

#include "types.h"

typedef struct DWCAccFriendData DWCAccFriendData;

struct GpConnection;

// Buddy layer of the online link, embedded in WiFiConnection at 0x2e8 (gWiFiBuddySync). Given the GP connection and
// the saved list (mBuddies, mBuddyEntryCount entries of 12 bytes), it makes the GP buddy list and the saved list
// agree: GP buddies the list lacks are deleted, list entries GP lacks are added (AddBuddy), entries that hold only a
// name are looked up by a GP profile search, entries with the same profile id are merged; when a name is given it
// also talks to the stats server first. The end is reported through mResultCallback (mBuddiesChanged: the list was
// rewritten and must be saved). UpdateBuddySync also pumps GpUpdate every 300 ms in connection states 3 to 6, and the
// object answers the GP buddy request and buddy status callbacks.
typedef struct WiFiBuddySync {
    // 0 idle, 1 running, 2 finished; only compared (the per-frame step does not switch on it). mUnk_1e (0..3) is the
    // phase inside state 1 and stays address-based.
    /* 00 */ s32 mState;
    /* 04 */ struct GpConnection *mGpConnection;
    // GpUpdate calls since the last restart (func_ov000_0219d5bc, at login success); the list part starts after more
    // than 7.
    /* 08 */ u32 mPollCount;
    // OS_GetTick reading at the last GpUpdate; the next one is allowed after 300 ms.
    /* 0c */ u64 mLastPollTime;
    // Capacity of the list at mBuddies (0x3c entries), not the number of entries in use (func_ov000_0219d9b0 counts
    // those).
    /* 14 */ s32 mBuddyEntryCount;
    // The saved list (WiFiSession.mBuddies, 12-byte entries), mBuddyEntryCount long.
    /* 18 */ DWCAccFriendData *mBuddies;
    // Entry of the list the sync step is on; advanced by the step loop and by the profile-search reply
    // (func_ov000_0219ce48).
    /* 1c */ u8 mSyncIndex;
    // 1 when the sync rewrote or merged an entry; given to the result callback, whose receiver sets
    // WiFiSession.mUnk_1cfc so the list is saved (code_0211f6cc.c). Set early in the reply handler
    // func_ov000_0219ce48, so it can be 1 without a change.
    /* 1d */ u8 mBuddiesChanged;
    /* 1e */ u8 mUnk_1e;
    // Parts of the sync that ended; at 2 UpdateBuddySync calls FinishBuddySync (the finish step). Part 1 is the
    // name part (only run when a name was given: the one caller passes NULL, so it is counted at once); part 2 is the
    // list part.
    /* 1f */ u8 mCompletedParts;
    // Stats-server requests in flight (++ before a request, -- in its reply); an error when it would wrap or while it
    // is nonzero and the stats link is gone (UpdateBuddySync). Only live when a name was given to StartBuddySync (the
    // one caller passes NULL).
    /* 20 */ u32 mPendingStatsRequestCount;
    /* 24 */ s32 mUnk_24;
    /* 28 */ char *mUnk_28;
    // Set by StartBuddySync (the owner passes WiFiBuddySyncCallback); called with (code, mBuddiesChanged, arg) by the
    // finish step FinishBuddySync (code 0) and the error reporter ReportBuddySyncError (error).
    /* 2c */ void (*mResultCallback)(s32, u8, void *);
    /* 30 */ void *mResultCallbackArg;
    // Called with (list index, status, status text, arg) from WiFiGpBuddyStatusCallback and from the change notifier
    // func_ov000_0219d504.
    /* 34 */ void (*mBuddyStatusCallback)(s32, u8, void *, void *);
    /* 38 */ void *mBuddyStatusCallbackArg;
    // Set by StartBuddySync (seventh parameter; the owner passes func_0211f6e8). Called by func_ov000_0219d288 with
    // (index of the entry cleared, index of the entry kept, arg) when two entries of the saved list hold the same
    // profile id.
    /* 3c */ void (*mEntryMergedCallback)(s32, s32, void *);
    /* 40 */ void *mEntryMergedCallbackArg;
    // Set by SetBuddyChangedCallback (declared void *, called as void (*)(s32, void *)). Called by func_ov000_0219d504
    // with (list index, arg) after a GP reply set an entry's profile id, unless a sync is running (mState 1). The one
    // caller passes func_0211f6b0 (a C body exists: src/Main/Unknown/code_0211f6b0.c).
    /* 44 */ void *mBuddyChangedCallback;
    /* 48 */ void *mBuddyChangedCallbackArg;
    /* 4c */ void (*mUnk_4c)(s32 a, s32 b, u32 c);
    /* 50 */ u32 mUnk_50;
} WiFiBuddySync;

// Written by InitBuddySync and cleared by func_ov000_0219d4f8, the release half.
extern WiFiBuddySync *gWiFiBuddySync;

void SetBuddyChangedCallback(void *first, void *second);
