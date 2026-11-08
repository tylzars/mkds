#include "00/code_0219dd4c.h"

#include "00/code_021a0958.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "00/code_0219e4e8.h"
#include "00/code_0219e134.h"
#include "00/code_021a01dc.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "00/code_0219de4c.h"
#include "00/code_0219de5c.h"
#include "00/code_0219eac8.h"
#include "00/code_0218e2dc.h"
#include "00/code_021a3a18.h"
#include "00/code_0218aea4.h"
#include "00/code_0219dee0.h"
#include "00/code_0218b000.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/code_0218d818.h"
#include "00/code_021a3264.h"
#include "00/code_021a2950.h"
#include "00/code_0219fb48.h"
#include "00/code_0219f000.h"
#include "00/code_021a0000.h"
#include "00/code_0219f4c4.h"
#include "code_0200f5ac.h"
#include "00/code_0219c954.h"
#include "00/code_0219eaf4.h"
#include "00/code_0219b580.h"
#include "00/code_0219c000.h"
#include "00/code_0219c384.h"
#include "00/code_021a17bc.h"
#include "03/code_021b94b8.h"
#include "00/code_021a369c.h"
#include "00/code_0219d000.h"
#include "00/code_0219e000.h"
#include "00/code_0219a654.h"
#include "00/code_0219d128.h"
#include "00/code_021988e8.h"
#include "00/code_0219a000.h"
#include "00/code_0219b000.h"
#include "00/code_0219f9bc.h"
#include "00/code_021a1000.h"
#include "os_printf.h"
#include "00/code_021a10b0.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_0218a000.h"
#include "00/code_0218c000.h"
#include "Main/Unknown/code_02152698.h"
#include "code_0213a460.h"
#include "code_02152500.h"
#include "00/code_0219dabc.h"
#include "00/code_0219887c.h"
#include "00/code_0219dd48.h"
#include "00/code_021a8878.h"
#include "00/code_021a8aa8.h"
#include "00/code_021a4000.h"
#include "00/code_021a4b84.h"
#include "00/code_02188720.h"
#include "code_0214cfe4.h"
#include "00/code_021a1ac0.h"
#include "00/code_02198a8c.h"
#include "00/code_021a1ae0.h"

// Per login: stores the GP connection, socket and callbacks and resets the search.
void InitMatching(WiFiMatching *param_1, GpConnection *param_2, void **param_3, void *param_4, void *param_5,
                  void *param_6, void *param_7, u32 param_8) {
    gWiFiMatching = param_1;
    param_1->mGpConnection = param_2;
    gWiFiMatching->mConnectionSocket = param_3;
    gWiFiMatching->mConnectionCallbacks = param_4;
    gWiFiMatching->mUnk_10 = NULL;
    gWiFiMatching->mOwnAddress = NULL;
    gWiFiMatching->mOwnPort = 0;
    gWiFiMatching->mServerList = NULL;
    gWiFiMatching->mState = 0;
    gWiFiMatching->mUnk_0f = 0;
    gWiFiMatching->mUnk_19 = 0;
    gWiFiMatching->mUnk_1a5 = 0;
    gWiFiMatching->mOwnProfileId = 0;
    gWiFiMatching->mGameName = param_5;
    gWiFiMatching->mUnk_2e0 = param_6;
    gWiFiMatching->mBuddies = param_7;
    gWiFiMatching->mBuddyEntryCount = param_8;
    MI_CpuFill8(gWiFiMatching->mBuddyEntryIndices, 0, 0x40);
    gWiFiMatching->mBuddyEntryIndexCount = 0;
    gWiFiMatching->mResultCallback = NULL;
    gWiFiMatching->mResultCallbackArg = 0;
    gWiFiMatching->mEvalCallback = 0;
    gWiFiMatching->mEvalCallbackArg = 0;
    ReleaseMatchingKeys();
    data_ov000_021b5668.mUnk_00 = 0;
    data_ov000_021b5668.mUnk_01 = 0;
    data_ov000_021b5668.mUnk_02 = 0;
    ResetMatching(0);
}

u32 func_ov000_021a2768(u32 param_1) {
    WiFiMatching *p;
    s32 i;
    u32 r;
    p = gWiFiMatching;
    if (p->mUnk_10 != NULL) {
        return 0;
    }
    p->mOwnProfileId = param_1;
    i = 0;
    do {
        p = gWiFiMatching;
        r = func_ov000_021a4a08(&gWiFiMatching->mUnk_10, GetSocketDescriptor(*p->mConnectionSocket),
                                GetSocketPort(*p->mConnectionSocket), p->mGameName, p->mUnk_2e0, 1, 1,
                                (Unk021a4a08Func88) WriteMatchingKeyValue, (Unk021a4a08Func8c) func_ov000_0219dedc,
                                (Unk021a4a08Func8c) func_ov000_0219ded8, (Unk021a4a08Func94) AddMatchingKeyIds,
                                (Unk021a4a08Func98) func_ov000_0219de64, (Unk021a4a08Func9c) func_ov000_0219de5c, NULL);
        if (r == 0) {
            break;
        }
        if (r != 3 || i == 4) {
            func_ov000_0219e4e8(r);
            return r;
        }
        i++;
    } while (i < 5);
    gWiFiMatching->mOwnAddress = NULL;
    gWiFiMatching->mOwnPort = 0;
    func_ov000_021a49cc(gWiFiMatching->mUnk_10, SetMatchingOwnAddress);
    func_ov000_021a49f4(gWiFiMatching->mUnk_10, func_ov000_0219ddbc);
    func_ov000_021a49e0(gWiFiMatching->mUnk_10, ParseMatchingRecords);
    func_ov000_021a4818(gWiFiMatching->mUnk_10);
    return r;
}

// Starts a filter search (mode 0) and keeps the caller's filter text for the server list filter.
void StartMatchingWithFilter(u32 param_1, const void *param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
    char v1[0x100];
    s32 n;
    if (gMatchingFilterText != NULL) {
        func_ov000_021a3704(4, (u32) gMatchingFilterText, 0);
        gMatchingFilterText = NULL;
    }
    if (param_2 != NULL) {
        n = BuildMatchingFilter(v1, -1, 0x20, 3);
        n = 0x100 - n - strlen(gAndEmptyParensString);
        gMatchingFilterText = func_ov000_021a372c(4, n);
        if (gMatchingFilterText == NULL) {
            ReportMatchingError(11, -80001);
            return;
        }
        MI_CpuCopy8(param_2, gMatchingFilterText, n);
        *((u8 *) gMatchingFilterText + n - 1) = 0;
    }
    ((void (*)(u32, u32, u32, u32)) SetupMatching)(0, param_1, param_3, param_4);
    gWiFiMatching->mEvalCallback = param_5;
    gWiFiMatching->mEvalCallbackArg = param_6;
    gWiFiMatching->mState = 2;
    if (gWiFiMatching->mServerList == NULL) {
        gWiFiMatching->mServerList =
            func_ov000_0218b668(gWiFiMatching->mGameName, gWiFiMatching->mGameName, gWiFiMatching->mUnk_2e0, 0, 20, 1,
                                0, WiFiMatchingServerListCallback, 0);
    }
    if (gWiFiMatching->mServerList == NULL && ReportMatchingServerListResult(5) != 0) {
        return;
    }
    func_ov000_0219d558(3, gEmptyString, NULL);
    if (ReportMatchingServerListResult(StartMatchingServerList(gWiFiMatching->mOwnProfileId)) != 0) {
        return;
    }
    if (gWiFiMatching->mUnk_10 == NULL) {
        func_ov000_021a2768(gWiFiMatching->mOwnProfileId);
    }
    func_ov000_0219e8b8(0);
}

// Starts a buddy search (mode 1) over a list of buddy entry indices.
void StartMatchingWithBuddies(const void *param_1, s32 param_2, s32 param_3, s32 param_4, void *param_5, u32 param_6,
                              u32 param_7, u32 param_8) {
    char v1[12];
    u8 v2[0x24];
    ((void (*)(u32, u32, u32, u32)) SetupMatching)(1, param_3, (u32) param_5, param_6);
    gWiFiMatching->mUnk_19e = param_4 != 0 ? 1 : 0;
    gWiFiMatching->mEvalCallback = param_7;
    gWiFiMatching->mEvalCallbackArg = param_8;
    MI_CpuCopy8(param_1, gWiFiMatching->mBuddyEntryIndices, param_2);
    gWiFiMatching->mBuddyEntryIndexCount = param_2;
    if (param_2 == 0 || (param_2 < param_3 && param_4 == 0 &&
                         (data_ov000_021b5670 == NULL || data_ov000_021b5670->mUnk_00 == 0 ||
                          param_2 < data_ov000_021b5670->mUnk_01 - 1))) {
        ReportMatchingError(7, 0);
        return;
    }
    gWiFiMatching->mState = 4;
    if (gWiFiMatching->mServerList == NULL) {
        gWiFiMatching->mServerList =
            func_ov000_0218b668(gWiFiMatching->mGameName, gWiFiMatching->mGameName, gWiFiMatching->mUnk_2e0, 0, 20, 1,
                                0, WiFiMatchingServerListCallback, 0);
    }
    if (gWiFiMatching->mServerList == NULL && ReportMatchingServerListResult(5) != 0) {
        return;
    }
    OS_SNPrintf(v1, 12, gUnsignedFormat, param_3);
    func_ov000_021a363c(gFmeKey, v1, v2, 0x2f);
    func_ov000_021a360c(gMdfKey, param_4 != 0 ? gYString : gNString, v2, 0x2f);
    OS_SNPrintf(v1, 12, gUnsignedFormat, 3);
    func_ov000_021a360c(gVerKey, v1, v2, 0x2f);
    if (ReportMatchingGpResult(func_ov000_0219d558(4, v2, NULL)) != 0) {
        return;
    }
    if (ReportMatchingSendResult(func_ov000_0219fbec(0, 1)) != 0) {
        return;
    }
    if (gWiFiMatching->mUnk_10 == NULL) {
        func_ov000_021a2768(gWiFiMatching->mOwnProfileId);
    }
    func_ov000_0219e8b8(0);
}

// Per-frame step; the state machine runs only when the parameter is 1.
void UpdateMatching(s32 param_1) {
    WiFiMatching *p;
    u32 n;
    Unk021a4a08 *q;
    if (gWiFiMatching == NULL) {
        return;
    }
    if (func_ov000_0219c39c() != 0) {
        return;
    }
    if (param_1 == 0) {
        if (gWiFiMatching->mUnk_10 != NULL) {
            func_ov000_021a49a0(gWiFiMatching->mUnk_10);
        }
        if (gWiFiMatching->mConnectionSocket != NULL) {
            func_ov000_02198a8c(*gWiFiMatching->mConnectionSocket);
        }
        return;
    }
    p = gWiFiMatching;
    if (p->mState == 0) {
        return;
    }
    switch (p->mState) {
        case 4:
            if (p->mUnk_1bc != 0) {
                if ((OS_GetTick() - p->mUnk_1c0) * 64 / 0x82ea > p->mUnk_1bc) {
                    p->mUnk_1bc = 0;
                    p = gWiFiMatching;
                    param_1 = p->mMode;
                    if (param_1 == 3) {
                        p->mUnk_1a2++;
                        p = gWiFiMatching;
                        if (p->mUnk_1a2 > 5) {
                            ReportMatchingError(6, -80430);
                            return;
                        }
                        if (ReportMatchingSendResult(func_ov000_0219fdc8(p->mParticipantProfileIds[0], 0)) != 0) {
                            return;
                        }
                    } else if (RestartMatching(param_1) == 0) {
                        return;
                    }
                }
            }
            p = gWiFiMatching;
            if (p->mUnk_1b0 != 0) {
                n = (u32) (p->mLastParticipantPos * 3000) + 3000;
                if ((OS_GetTick() - p->mUnk_1b4) * 64 / 0x82ea >= n) {
                    if (ReportMatchingSendResult(func_ov000_0219fdc8(p->mParticipantProfileIds[0], 0)) != 0) {
                        return;
                    }
                }
            }
            break;
        case 2:
        case 3:
        case 5:
            if ((s32) p->mUnk_e8 > 0) {
                if (p->mState == 3) {
                    n = (u32) (p->mLastParticipantPos * 3000) + 3000;
                } else if (p->mUnk_e8 == 1) {
                    n = 1000;
                } else {
                    n = 3000;
                }
                if ((OS_GetTick() - p->mUnk_ec) * 64 / 0x82ea > n) {
                    if (ReportMatchingServerListResult(StartMatchingServerList(p->mReplyProfileId)) != 0) {
                        return;
                    }
                    gWiFiMatching->mUnk_e8 = 0;
                }
            }
            break;
        case 7:
            if (p->mIncomingWaitStartTime != 0) {
                if (func_ov000_021a350c() - p->mIncomingWaitStartTime > 25000) {
                    gWiFiMatching->mIncomingWaitStartTime = 0;
                    if (func_ov000_0219f938(gWiFiMatching->mParticipantProfileIds[0]) == 0) {
                        return;
                    }
                }
            } else if (p->mLastCommand == 6) {
                if (func_ov000_021a350c() - p->mLastCommandTime > 6000) {
                    p->mResendCount++;
                    p = gWiFiMatching;
                    if (p->mResendCount > 5) {
                        ResetMatchingResend();
                        if (func_ov000_0219f938(gWiFiMatching->mParticipantProfileIds[0]) == 0) {
                            return;
                        }
                    } else if (ReportMatchingSendResult(SendMatchingCommand(
                                   6, p->mLastCommandProfileId, p->mLastCommandAddress, p->mLastCommandPort,
                                   p->mLastCommandValues, p->mLastCommandValueCount)) != 0) {
                        return;
                    }
                }
            }
            break;
        case 11:
            if (p->mLastCommand == 2) {
                if ((p->mMode == 0 && func_ov000_021a350c() - gWiFiMatching->mLastCommandTime > 6000) ||
                    func_ov000_021a350c() - gWiFiMatching->mLastCommandTime > 19000) {
                    ResetMatchingResend();
                    if (func_ov000_0219f9bc(
                            gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mLastParticipantPos + 1]) == 0) {
                        return;
                    }
                }
            }
            break;
        case 13:
            if (p->mLastCommand == 8) {
                if (func_ov000_021a350c() - p->mLastCommandTime > 30000) {
                    p->mResendCount++;
                    p = gWiFiMatching;
                    if (p->mResendCount != 0) {
                        ResetMatchingResend();
                        p = gWiFiMatching;
                        if (p->mMode == 2) {
                            if (func_ov000_0219f9bc(p->mParticipantProfileIds[p->mLastParticipantPos]) == 0) {
                                return;
                            }
                        } else {
                            func_ov000_0219f214();
                        }
                    } else if (ReportMatchingSendResult(SendMatchingCommand(
                                   8, p->mLastCommandProfileId, p->mLastCommandAddress, p->mLastCommandPort,
                                   p->mLastCommandValues, p->mLastCommandValueCount)) != 0) {
                        return;
                    }
                }
            }
            break;
    }
    p = gWiFiMatching;
    if (p->mState == 11 || p->mState == 6) {
        if (p->mUnk_17c != 0) {
            if (func_ov000_021a350c() - p->mUnk_17c > 10000) {
                func_ov000_0219db18(1, 0, 0, p->mUnk_18c);
            }
        }
    }
    if (gWiFiMatching->mServerList != NULL) {
        func_ov000_0218b4bc(gWiFiMatching->mServerList);
    }
    if (gWiFiMatching->mUnk_10 != NULL) {
        func_ov000_021a49a0(gWiFiMatching->mUnk_10);
        p = gWiFiMatching;
        q = p->mUnk_10;
        if ((q->mUnk_0b4 == FALSE && (p->mMode == 0 || p->mMode == 1) &&
             (p->mState == 1 || p->mState == 2 || p->mState == 3 || p->mState == 4 || p->mState == 6 ||
              p->mState == 11)) ||
            (p->mMode == 2 && p->mState == 11)) {
            func_ov000_021a4818(q);
        }
    }
    func_ov000_0219aaec();
    if (gWiFiMatching->mConnectionSocket != NULL) {
        func_ov000_02198a8c(*gWiFiMatching->mConnectionSocket);
    }
    if (gWiFiMatching->mState == 18) {
        if (func_ov000_021a350c() - gWiFiMatching->mUnk_1e0 > 3000) {
            if (func_ov000_0219f184() != 0) {
                return;
            }
        }
    }
    if (UpdateMatchingPeerMessageTimeouts() != 0) {
        if (func_ov000_0219eaf4() != 0) {
            func_ov000_0219e668();
        }
    }
}

u32 WiFiUnmatchedDataCallback(u32 param_1, u32 address, u16 port, u8 *data, u32 size) {
    UnmatchedDataAddress a;
    volatile u32 v; // placeholder: value passed through a stack offset
    u32 c;
    if (size == 0 || data == NULL) {
        return 0;
    }
    v = 0;
    MIi_CpuClear32(v, &a, 8);
    a.mUnk_01 = 2;
    a.mAddress = address;
    a.mPort = ((port >> 8) & 0xff) | ((port << 8) & 0xff00);
    c = data[0];
    if ((c == 0xfe && data[1] == 0xfd) || c == 0x5c) {
        if (gWiFiMatching->mUnk_10 != NULL) {
            func_ov000_021a3c14((Unk021a3a18 *) gWiFiMatching->mUnk_10, (s8 *) data, size, &a);
        }
    } else if (memcmp(data, data_ov000_021b400c, 6) == 0) {
        func_ov000_0219a7e4(data, size, &a);
    } else {
        switch (c) {
            case 0xfe:
                return 0;
            default:
                return 0;
        }
    }
    return 1;
}

// Accepts an incoming connection in state 7 from the expected participant, otherwise refuses it with a reason text.
void WiFiIncomingConnectionCallback(u32 param_1, Unk0219887c *connection, u32 address, u32 port, s32 param_5,
                                    char *text) {
    WiFiMatching *p;
    Unk021b5550 *e;
    void **q;
    s32 i;
    s32 j;
    s32 t;
    p = gWiFiMatching;
    if (p == NULL || p->mState != 7 || p->mStopPending != 0) {
        func_ov000_02198a74((Gt2Connection *) connection, gInitStateString, -1);
        return;
    }
    i = func_ov000_0219b998();
    if (i == -1) {
        func_ov000_02198a74((Gt2Connection *) connection, gServerFullString, -1);
        ReportMatchingError(6, -87100);
        return;
    }
    if (address != gWiFiMatching->mParticipantConnectAddresses[gWiFiMatching->mLastParticipantPos] ||
        port != gWiFiMatching->mParticipantConnectPorts[gWiFiMatching->mLastParticipantPos]) {
        j = gWiFiMatching->mLastParticipantPos;
        if (*text != 0 &&
            (p = *(WiFiMatching **) &gWiFiMatching, p->mParticipantProfileIds[j] == strtoul(text, NULL, 10))) {
            gWiFiMatching->mParticipantConnectAddresses[j] = address;
            gWiFiMatching->mParticipantConnectPorts[gWiFiMatching->mLastParticipantPos] = port;
        } else {
            func_ov000_02198a74((Gt2Connection *) connection, gUnexpectedConnectAttemptString, -1);
            return;
        }
    }
    gWiFiMatching->mIncomingWaitStartTime = 0;
    if (func_ov000_02198a7c((Gt2Connection *) connection, gWiFiMatching->mConnectionCallbacks) == 0) {
        ReportMatchingError(6, -80410);
        return;
    }
    ResetMatchingResend();
    p = gWiFiMatching;
    if (p->mLastParticipantPos == 0) {
        t = param_5 >> 1;
        if (t >= 0xffff) {
            t = 0xffff;
        }
        p->mUnk_1a6 = t;
    }
    q = func_ov000_0219b958(i);
    e = func_ov000_0219b8f0(i);
    *q = connection;
    gWiFiMatching->mLastParticipantPos++;
    e->mUnk_00 = i;
    e->mUnk_01 = gWiFiMatching->mParticipantIndices[gWiFiMatching->mLastParticipantPos - 1];
    e->mUnk_02 = 0;
    e->mUnk_04 = 0;
    func_ov000_021988a4(connection, e);
    func_ov000_0219f544(2);
}

// Result of a connect to a peer: 0 adds the peer, 6 retries the connect up to 5 times, 5 is ignored, 2 ends the
// attempt, other results are reported.
void WiFiGt2ResultCallback(Unk0219887c *param_1, s32 param_2) {
    WiFiMatching *p;
    s32 i;
    void **q;
    Unk021b5550 *e;
    char v1[12];
    p = gWiFiMatching;
    if (p == NULL) {
        return;
    }
    if (p->mState != 7 && p->mState != 12) {
        return;
    }
    if (param_2 != 0) {
        if (param_2 == 5) {
            return;
        }
        if (param_2 == 6) {
            p->mConnectRetryCount++;
            p = gWiFiMatching;
            if (p->mConnectRetryCount > 5) {
                p->mConnectRetryCount = 0;
                func_ov000_0219f9bc(gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mLastParticipantPos + 1]);
                return;
            }
            OS_SNPrintf(v1, 12, gUnsignedFormat, p->mOwnProfileId);
            p = gWiFiMatching;
            if (ReportMatchingConnectResult(func_ov000_02198968(
                    *gWiFiMatching->mConnectionSocket, NULL,
                    Gt2FormatAddress(
                        p->mParticipantConnectAddresses[p->mUnk_14],
                        ((const WiFiMatching *) p)->mParticipantConnectPorts[((const WiFiMatching *) p)->mUnk_14], 0),
                    v1, -1, 5000, p->mConnectionCallbacks, 0)) == 0) {
                return;
            }
            return;
        }
        if (param_2 == 2) {
            if (func_ov000_0219f9bc(gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mLastParticipantPos + 1]) ==
                0) {
                return;
            }
            return;
        }
        ReportMatchingConnectResult(param_2);
        return;
    }
    i = func_ov000_0219b998();
    if (i == -1) {
        ReportMatchingError(6, -87100);
    }
    q = func_ov000_0219b958(i);
    e = func_ov000_0219b8f0(i);
    *q = param_1;
    gWiFiMatching->mLastParticipantPos++;
    e->mUnk_00 = i;
    e->mUnk_02 = 0;
    e->mUnk_04 = 0;
    e->mUnk_01 = gWiFiMatching->mParticipantIndices[gWiFiMatching->mLastParticipantPos];
    func_ov000_021988a4(param_1, e);
    if (gWiFiMatching->mState == 12) {
        func_ov000_0219f544(0);
        return;
    }
    func_ov000_0219f544(1);
}

void ParseMatchingGpMessage(GpConnection *param_1, u32 param_2, const char *param_3) {
    u32 v1[33];
    char v2[16];
    const char **e;
    s32 i;
    u32 *q;
    e = NULL;
    i = 0;
    q = v1;
    do {
        if (CopyNthSlashField(v2, param_3 + 1, i) == -1) {
            break;
        }
        *q = strtoul(v2, e, 10);
        q++;
        i++;
    } while (i < 0x80);
    ReceiveMatchingCommand(param_3[0], param_2, 0, 0, v1, i);
}

void ResetMatchingResend(void) {
    gWiFiMatching->mLastCommand = 0xff;
    gWiFiMatching->mResendCount = 0;
}

void ReportMatchingError(s32 kind, s32 code) {
    WiFiMatching *p;
    u32 a;
    u32 b;
    u32 c;
    if (gWiFiMatching != NULL && kind != 0) {
        CloseAllMatchingConnections();
        func_ov000_0219c384(kind, code);
        func_ov000_0219d558(0, gEmptyString, NULL);
        p = gWiFiMatching;
        a = p->mMode == 2 ? 1 : 0;
        c = gWiFiMatching->mUnk_1f4;
        b = c == 0 ? 1 : 0;
        gWiFiMatching->mResultCallback(kind, 0, b, a, FindBuddyEntryIndex(c), p->mResultCallbackArg);
        StopMatching();
    }
}

void func_ov000_021a1a10(void) {
    WiFiMatching *p;
    p = gWiFiMatching;
    if (p->mMode != 2) {
        p->mUnk_14 = 0;
        gWiFiMatching->mUnk_16 = 0;
        func_ov000_021a4818(gWiFiMatching->mUnk_10);
    }
}

void ReceiveMatchingPeerMessage(s32 a, s32 b, u8 *c) {
    WiFiMatching *p;
    s32 i;
    u32 *q;
    s32 v;
    switch (b) {
        case 2:
            p = gWiFiMatching;
            if (p->mState == 1) {
                if (c[0] == 1) {
                    p->mUnk_1f4 = 0;
                }
                i = c[1];
                gWiFiMatching->mParticipantIndices[i] = c[2];
                gWiFiMatching->mParticipantProfileIds[i] = gWiFiMatching->mOwnProfileId;
                p = gWiFiMatching;
                if (p->mMode == 0 || p->mMode == 1) {
                    p = gWiFiMatching;
                    p->mUnk_16 = p->mLastParticipantPos;
                }
                gWiFiMatching->mState = 9;
            }
            SendMatchingPeerMessage(a, 3);
            break;
        case 3:
            p = gWiFiMatching;
            if (p->mState == 16) {
                q = &p->mUnk_1c8;
                *q = *q | (1 << a);
                v = c[0] | (c[1] << 8);
                if (v > gWiFiMatching->mUnk_1a6) {
                    gWiFiMatching->mUnk_1a6 = v;
                }
                v = GetMatchingParticipantMaskExceptFirst(0);
                if (gWiFiMatching->mUnk_1c8 == v) {
                    for (i = 1; i <= gWiFiMatching->mLastParticipantPos; i++) {
                        SendMatchingPeerMessage(gWiFiMatching->mParticipantIndices[i], 4);
                    }
                    gWiFiMatching->mState = 17;
                }
            } else {
                SendMatchingPeerMessage(a, 4);
            }
            break;
        case 4:
            if (gWiFiMatching->mState == 9) {
                func_ov000_0219f544(4);
            }
            break;
    }
}

u32 func_ov000_021a17bc(s32 a, s32 b, s32 c) {
    WiFiMatching *p;
    if (GetWiFiConnectionState() != 5) {
        return 0;
    }
    p = gWiFiMatching;
    if (p->mMode == 2) {
        return 1;
    }
    if (a != 0) {
        ReportMatchingError(a, b - 80000);
        return 1;
    }
    p->mParticipantIndices[0] = 0;
    p = gWiFiMatching;
    if (p->mStopPending == 1 || p->mUnk_1a0 == 1 || p->mUnk_1a0 == 2) {
        return 1;
    }
    if (p->mUnk_194 != 0) {
        func_ov000_0219ac50(p->mUnk_194);
        gWiFiMatching->mUnk_194 = 0;
    }
    p = gWiFiMatching;
    if (p->mLastParticipantPos != 0) {
        if (p->mUnk_1a0 == 0) {
            p->mUnk_1a0 = 3;
            func_ov000_021988e8(*gWiFiMatching->mConnectionSocket);
        }
    } else if (p->mMode == 3) {
        ReportMatchingError(6, -80430);
    } else if (p->mUnk_1f0 != 0) {
        func_ov000_0219f184();
    } else if (p->mState == 1) {
        p->mState = 18;
        gWiFiMatching->mUnk_1e0 = func_ov000_021a350c();
    } else {
        func_ov000_0219f23c(1);
    }
    return 1;
}

void func_ov000_021a1798(u32 value) {
    if (gWiFiMatching->mUnk_1a0 != 2) {
        func_ov000_0219f9bc(value);
    }
}

u32 RemoveMatchingParticipantByProfileId(int profileId, int count) {
    int v1;
    int v2;
    v2 = *(s32 *) &gWiFiMatching;
    if (0 == v2) {
        return 0;
    }
    v1 = 0;
    if (0 < count) {
        do {
            if (profileId == *(s32 *) (v2 + 0xf4)) {
                RemoveMatchingParticipant(v1, count);
                return 1;
            }
            v2 = v2 + 4;
            v1 = v1 + 1;
        } while (v1 < count);
    }
    return 0;
}

u32 RemoveMatchingParticipant(s32 position, s32 count) {
    WiFiMatching *p;
    u32 v1;
    u32 *m;
    s32 i;
    s32 n;
    s32 k;
    p = gWiFiMatching;
    if (p == NULL) {
        return 0;
    }
    v1 = p->mParticipantProfileIds[position];
    m = &p->mParticipantMask;
    *m = *m & ~(1 << p->mParticipantIndices[position]);
    RefreshMatchingLastMaskedParticipantPos();
    if (position < count - 1) {
        i = 0;
        n = count - position;
        if (n > 0) {
            do {
                s32 a = position + i;
                gWiFiMatching->mParticipantCommandAddresses[a] = gWiFiMatching->mParticipantCommandAddresses[a + 1];
                gWiFiMatching->mParticipantCommandPorts[a] = gWiFiMatching->mParticipantCommandPorts[a + 1];
                gWiFiMatching->mParticipantProfileIds[a] = gWiFiMatching->mParticipantProfileIds[a + 1];
                gWiFiMatching->mParticipantConnectAddresses[a] = gWiFiMatching->mParticipantConnectAddresses[a + 1];
                gWiFiMatching->mParticipantConnectPorts[a] = gWiFiMatching->mParticipantConnectPorts[a + 1];
                gWiFiMatching->mParticipantIndices[a] = gWiFiMatching->mParticipantIndices[a + 1];
                i++;
            } while (i < n);
        }
    }
    if (count > 0) {
        k = count - 1;
        gWiFiMatching->mParticipantCommandAddresses[k] = 0;
        gWiFiMatching->mParticipantCommandPorts[k] = 0;
        gWiFiMatching->mParticipantProfileIds[k] = 0;
        gWiFiMatching->mParticipantConnectAddresses[k] = 0;
        gWiFiMatching->mParticipantConnectPorts[k] = 0;
        gWiFiMatching->mParticipantIndices[k] = 0;
    }
    return v1;
}

u8 GetMatchingLastParticipantPos(void) {
    if (gWiFiMatching != NULL) {
        return gWiFiMatching->mLastParticipantPos;
    }
    return 0;
}

u8 GetMatchingLastMaskedParticipantPos(void) {
    if (gWiFiMatching != NULL) {
        return gWiFiMatching->mLastMaskedParticipantPos;
    }
    return 0;
}

void RefreshMatchingLastMaskedParticipantPos(void) {
    WiFiMatching *p;
    s32 n;
    s32 i;
    u32 m;
    i = 0;
    n = -1;
    p = gWiFiMatching;
    m = p->mParticipantMask;
    for (; i < 32; i++) {
        if ((m & (1 << i)) != 0) {
            n++;
        }
    }
    if (n == -1) {
        p->mLastMaskedParticipantPos = 0;
    } else {
        p->mLastMaskedParticipantPos = n;
    }
}

u32 GetMatchingParticipantIndices(void **output) {
    if (gWiFiMatching == NULL) {
        return 0;
    }
    *output = gWiFiMatching->mParticipantIndices;
    return gWiFiMatching->mLastParticipantPos + 1;
}

u32 GetMatchingMaskedParticipantIndices(void **a) {
    s32 i;
    u8 *c;
    u8 *q;
    WiFiMatching *p;
    u8 b;
    if (gWiFiMatching == NULL) {
        return 0;
    }
    MI_CpuFill8(gMatchingMaskedParticipantIndices, 0, 0x20);
    i = 0;
    c = (u8 *) gWiFiMatching;
    if (i <= ((WiFiMatching *) c)->mLastMaskedParticipantPos) {
        q = gMatchingMaskedParticipantIndices;
        p = (WiFiMatching *) c;
        do {
            b = c[0x2b8];
            if ((p->mParticipantMask & (1 << b)) == 0) {
                break;
            }
            *q = b;
            c++;
            q++;
            i++;
        } while (i <= p->mLastMaskedParticipantPos);
    }
    *a = gMatchingMaskedParticipantIndices;
    return gWiFiMatching->mLastMaskedParticipantPos + 1;
}

u32 func_ov000_021a1488(void) {
    char name[12];
    u8 buffer[32];
    if (gWiFiMatching->mMode != 2) {
        return 0;
    }
    OS_SNPrintf(name, 0xc, gUnsignedFormat, gWiFiMatching->mUnk_16 + 1);
    func_ov000_021a363c(gScmKey, name, buffer, 0x2f);
    OS_SNPrintf(name, 0xc, gUnsignedFormat, gWiFiMatching->mLastParticipantPos + 1);
    func_ov000_021a360c(gScnKey, name, buffer, 0x2f);
    OS_SNPrintf(name, 0xc, gUnsignedFormat, 3);
    func_ov000_021a360c(gVerKey, name, buffer, 0x2f);
    return func_ov000_0219d558(6, buffer, NULL);
}

void ReleaseMatching(void) {
    gWiFiMatching = NULL;
    if (gMatchingFilterText != NULL) {
        func_ov000_021a3704(4, (u32) gMatchingFilterText, 0);
        gMatchingFilterText = NULL;
    }
    ReleaseMatchingKeys();
    if (data_ov000_021b5670 != NULL) {
        func_ov000_021a3704(4, (u32) data_ov000_021b5670, 0);
        data_ov000_021b5670 = NULL;
    }
    data_ov000_021b5668.mUnk_00 = 0;
    data_ov000_021b5668.mUnk_01 = 0;
}

u32 IsMatchingPointerNull(void) {
    if (gWiFiMatching == NULL) {
        return 1;
    }
    return 0;
}

// Resets the per-search fields; level 2 keeps the participant list, 1 clears it, 0 also resets the mode and callbacks.
void ResetMatching(s32 level) {
    vu16 h;
    vu16 g;

    gWiFiMatching->mConnectRetryCount = 0;
    gWiFiMatching->mUnk_174[0] = 0;
    gWiFiMatching->mUnk_176 = func_ov000_021a3448(0x10000);
    gWiFiMatching->mUnk_178 = 0;
    gWiFiMatching->mUnk_17c = 0;
    gWiFiMatching->mIncomingWaitStartTime = 0;
    gWiFiMatching->mUnk_19c = 0;
    gWiFiMatching->mStopPending = 0;
    gWiFiMatching->mUnk_1a2 = 0;
    gWiFiMatching->mUnk_1a3[0] = 0;
    gWiFiMatching->mUnk_1a3[1] = 0;
    gWiFiMatching->mUnk_19f = 0;
    gWiFiMatching->mUnk_1a0 = 0;
    gWiFiMatching->mUnk_1a8 = 0;
    gWiFiMatching->mUnk_1aa = 0;
    gWiFiMatching->mUnk_1ac = 0;
    gWiFiMatching->mLastPeerMessageSendTime = 0;
    gWiFiMatching->mUnk_1e0 = 0;
    func_0214d018_inline(&gWiFiMatching->mLastCommand, 0x98);
    if (level == 2) {
        gWiFiMatching->mUnk_14 = gWiFiMatching->mLastParticipantPos;
        if (gWiFiMatching->mMode == 3) {
            gWiFiMatching->mState = 1;
            return;
        }
        if (gWiFiMatching->mMode == 2) {
            gWiFiMatching->mState = 10;
            return;
        }
    } else {
        gWiFiMatching->mLastParticipantPos = 0;
        gWiFiMatching->mLastMaskedParticipantPos = 0;
        gWiFiMatching->mUnk_14 = 0;
        gWiFiMatching->mMresvPresent = 0;
        gWiFiMatching->mMresvProfileId = 0;
        gWiFiMatching->mUnk_e8 = 0;
        gWiFiMatching->mBuddyEntryIndexPos = 0;
        gWiFiMatching->mUnk_1a6 = 0;
        gWiFiMatching->mUnk_1b0 = 0;
        gWiFiMatching->mUnk_1b4 = 0;
        gWiFiMatching->mUnk_1bc = 0;
        gWiFiMatching->mUnk_1c0 = 0;
        gWiFiMatching->mUnk_1c8 = 0;
        gWiFiMatching->mReplyProfileId = 0;
        gWiFiMatching->mUnk_1f0 = 0;
        gWiFiMatching->mParticipantMask = 0;
        func_0214d018_inline(gWiFiMatching->mParticipantCommandAddresses, 0x80);
        h = 0;
        MIi_CpuClear16(h, gWiFiMatching->mParticipantCommandPorts, 0x40);
        func_0214d018_inline(gWiFiMatching->mParticipantProfileIds, 0x80);
        func_0214d018_inline(gWiFiMatching->mUnk_18c, 0xc);
        func_0214d018_inline(gWiFiMatching->mParticipantConnectAddresses, 0x80);
        g = 0;
        MIi_CpuClear16(g, gWiFiMatching->mParticipantConnectPorts, 0x40);
        MI_CpuFill8(gWiFiMatching->mParticipantIndices, 0, 0x20);
        func_0214d018_inline(gWiFiMatching->mReceivedList, 0x84);
        if (level == 1) {
            if (gWiFiMatching->mMode == 0) {
                gWiFiMatching->mState = 3;
                return;
            }
            if (gWiFiMatching->mMode == 1) {
                gWiFiMatching->mState = 4;
                return;
            }
        } else {
            gWiFiMatching->mMode = 0;
            gWiFiMatching->mUnk_16 = 0;
            gWiFiMatching->mUnk_18 = 0;
            gWiFiMatching->mUnk_1f4 = 0;
            gWiFiMatching->mUnk_19e = 0;
            gWiFiMatching->mUnk_454 = NULL;
            gWiFiMatching->mUnk_458 = 0;
        }
    }
}

// Sets mode, second value and result callback for a new search and registers the key names 0x32 to 0x36.
void SetupMatching(u8 a, u8 b, UnkFunc *c, u32 d) {
    WiFiMatching **v1;
    ResetMatching(0);
    v1 = &gWiFiMatching;
    gWiFiMatching->mMode = a;
    (*v1)->mUnk_16 = b;
    (*v1)->mResultCallback = c;
    (*v1)->mResultCallbackArg = d;
    (*v1)->mUnk_174[1] = 0;
    (*v1)->mParticipantIndices[0] = 0;
    func_ov000_021a4b84(0x32, gDwcPidKey);
    func_ov000_021a4b84(0x33, gDwcMtypeKey);
    func_ov000_021a4b84(0x34, gDwcMresvKey);
    func_ov000_021a4b84(0x35, gDwcMverKey);
    func_ov000_021a4b84(0x36, gDwcEvalKey);
}

void StopMatching(void) {
    if (gWiFiMatching != NULL) {
        if (gWiFiMatching->mServerList != NULL) {
            func_ov000_0218b64c(gWiFiMatching->mServerList);
            gWiFiMatching->mServerList = NULL;
        }
        func_ov000_0219b110();
        gWiFiMatching->mState = 0;
        if (gMatchingFilterText != NULL) {
            func_ov000_021a3704(4, (u32) gMatchingFilterText, 0);
            gMatchingFilterText = NULL;
        }
        ReleaseMatchingKeys();
        gWiFiMatching->mUnk_18 = 1;
    }
}

u32 StartMatchingServerList(u32 a) {
    char v1[0x100];
    u8 v2[0xa8];
    s32 i;
    u8 *e;
    u8 *w;
    u32 n;
    u32 r;

    n = 7;
    v2[0] = 8;
    v2[1] = 0xa;
    v2[2] = 0x32;
    v2[3] = 0x33;
    v2[4] = 0x34;
    v2[5] = 0x35;
    v2[6] = 0x36;
    if (gWiFiMatching->mMode == 0 || gWiFiMatching->mMode == 1) {
        i = 0;
        e = gMatchingKeys[0];
        w = v2 + 7;
        for (; i < 0x9a; i++) {
            if (e[0] != 0) {
                *w = e[0];
                w++;
                n++;
            }
            e += 12;
        }
    }
    switch (gWiFiMatching->mState) {
        case 3:
            a = gWiFiMatching->mUnk_1f0;
            if (a == 0) {
                BuildMatchingFilter(v1, gWiFiMatching->mOwnProfileId, gWiFiMatching->mUnk_16, gWiFiMatching->mMode);
                if (gMatchingFilterText != NULL) {
                    OS_SNPrintf(v1, 0x100, gAndParenFormat, v1, gMatchingFilterText);
                }
                break;
            }
        case 2:
        case 4:
        case 5:
            OS_SNPrintf(v1, 0x100, gKeyEqualsUnsignedFormat, gDwcPidKey, a);
            gWiFiMatching->mReplyProfileId = a;
            break;
    }
    func_ov000_0218b48c(gWiFiMatching->mServerList);
    for (i = 0; i < 5; i++) {
        r = func_ov000_0218b570(gWiFiMatching->mServerList, 1, 0, v2, n, (u32) v1, 0x10);
        if (r == 0 || r != 2) {
            break;
        }
    }
    return r;
}

s32 BuildMatchingFilter(char *buffer, s32 profileId, s32 c, s32 mode) {
    return OS_SNPrintf(buffer, 0x100, gMatchingFilterFormat, gDwcMverKey, 3, gDwcPidKey, profileId, c, c, gDwcMtypeKey,
                       mode, gDwcMresvKey, gDwcPidKey);
}

u32 func_ov000_021a0cac(s32 a, s32 b, u32 c) {
    u32 t[2];
    u16 v1;
    u32 k;
    BOOL x;
    u32 v2;
    u32 r;

    k = gWiFiMatching->mUnk_14;
    v2 = 0;
    if (a == 0) {
        b = (gWiFiMatching->mOwnProfileId & 0xffff) | (gWiFiMatching->mUnk_176 << 16);
        if (func_ov000_0218b248(c) != 0) {
            if (func_ov000_0218b27c((u32 *) c) == func_ov000_0218b458(gWiFiMatching->mServerList)) {
                gWiFiMatching->mParticipantConnectAddresses[k] = func_ov000_0218b244(c);
                gWiFiMatching->mParticipantConnectPorts[k] = func_ov000_0218b228(c);
                x = FALSE;
            } else {
                x = TRUE;
            }
        } else {
            v1 = func_ov000_021a8ed4();
            if ((v1 & 0xffff) == 0xa8c0 ||
                ((v1 & 0xff) == 0xac && (v1 & 0xff00u) >= 0x1000 && (v1 & 0xff00u) <= 0x1f00) || (v1 & 0xff) == 0x10) {
                x = TRUE;
            } else {
                gWiFiMatching->mParticipantConnectAddresses[k] = func_ov000_0218b27c((u32 *) c);
                gWiFiMatching->mParticipantConnectPorts[k] = func_ov000_0218b260(c);
                x = FALSE;
            }
        }
        if (x != FALSE) {
            gWiFiMatching->mUnk_176 = func_ov000_021a3448(0x10000);
            gWiFiMatching->mUnk_194 = b;
        } else {
            t[0] = func_ov000_021a8ed4();
            t[1] = GetSocketPort(*gWiFiMatching->mConnectionSocket);
            r = SendMatchingCommand(6, gWiFiMatching->mParticipantProfileIds[k], func_ov000_0218b27c((u32 *) c),
                                    func_ov000_0218b260(c), t, 2);
            gWiFiMatching->mResendCount = 0;
            if (r != 0) {
                return 2;
            }
            gWiFiMatching->mUnk_194 = 0;
        }
        gWiFiMatching->mUnk_18c[0] = 0;
        gWiFiMatching->mUnk_18c[1] = 0;
        *(u16 *) &gWiFiMatching->mUnk_18c[2] = func_ov000_0218b260(c);
        *(u32 *) &gWiFiMatching->mUnk_18c[4] = func_ov000_0218b27c((u32 *) c);
    } else {
        x = TRUE;
        gWiFiMatching->mUnk_18c[0] = 1;
        gWiFiMatching->mUnk_18c[1] = v2;
        *(u16 *) &gWiFiMatching->mUnk_18c[2] = v2;
        *(u32 *) &gWiFiMatching->mUnk_18c[4] = v2;
        gWiFiMatching->mUnk_194 = b;
    }
    if (x != FALSE) {
        v2 = func_ov000_021a0c30((Unk021a0c30 *) gWiFiMatching->mUnk_18c);
    } else {
        func_ov000_0219db18(0, GetSocketDescriptor(*gWiFiMatching->mConnectionSocket), 0, gWiFiMatching->mUnk_18c);
        gWiFiMatching->mIncomingWaitStartTime = 0;
    }
    return v2;
}

u32 func_ov000_021a0c30(Unk021a0c30 *a) {
    u32 r;
    s32 i;

    if (a->mUnk_00 == 0) {
        if (ReportMatchingServerListResult(func_ov000_0218b4f8(
                gWiFiMatching->mServerList, Gt2FormatAddress(a->mAddress, 0, 0), a->mPort, a->mUnk_08)) != 0) {
            return 2;
        }
    }
    for (i = 0; i < 5; i++) {
        r = func_ov000_0219ac7c(GetSocketDescriptor(*gWiFiMatching->mConnectionSocket), a->mUnk_08, a->mUnk_00,
                                (void (*)(s32, void *)) func_ov000_0219dd48,
                                (void (*)(s32, s32, void *, void *)) func_ov000_0219db18, a);
        if (r == 0 || r != 3) {
            break;
        }
    }
    return r;
}

// Sends a command straight to an address in mode 0 and by GP text otherwise (command 6 can also go to an address);
// commands 2, 6, 8 and 9 are remembered to be sent again.
u32 SendMatchingCommand(u32 command, u32 profileId, u32 address, u32 port, void *values, s32 valueCount) {
    char v1[0x10];
    char v2[0x200];
    u32 *w;
    s32 n;
    s32 k;
    s32 j;

    n = 0;
    if (gWiFiMatching->mMode == 0 || ((gWiFiMatching->mMode == 3 || gWiFiMatching->mUnk_19e != 0) && command == 6)) {
        n = SendMatchingCommandToAddress(command, address, port, values, valueCount);
    } else {
        if (values != NULL && valueCount != 0) {
            w = values;
            n = OS_SNPrintf(v2, 0x200, gUnsignedFormat, w[0]);
            for (k = 1; k < valueCount; k++) {
                j = OS_SNPrintf(v1, 0x10, gSlashUnsignedFormat, w[k]);
                MI_CpuCopy8(v1, v2 + n, j);
                n += j;
            }
        }
        v2[n] = 0;
        n = SendMatchingCommandToProfile(gWiFiMatching->mGpConnection, command, profileId, v2);
    }
    if (command == 2 || command == 6 || (u8) (command + 0xf8) <= 1) {
        gWiFiMatching->mLastCommand = command;
        gWiFiMatching->mLastCommandPort = port;
        gWiFiMatching->mLastCommandAddress = address;
        gWiFiMatching->mLastCommandProfileId = profileId;
        gWiFiMatching->mLastCommandValueCount = valueCount;
        gWiFiMatching->mLastCommandTime = func_ov000_021a350c();
        if (values != NULL && valueCount != 0) {
            MIi_CpuCopy32(values, gWiFiMatching->mLastCommandValues, valueCount * 4);
        }
    }
    return n;
}

u32 SendMatchingCommandToAddress(u32 command, u32 address, u32 port, u32 *values, u32 valueCount) {
    u32 v1[0x21];
    MatchingSendHeader s;
    u32 r;
    s32 i;

    if (values != NULL && valueCount != 0) {
        MIi_CpuCopy32(values, v1, valueCount * 4);
    } else {
        valueCount = 0;
    }
    *(MatchingSignatureText *) &s = *(MatchingSignatureText *) gMatchingSignature;
    s.mUnk_04 = 3;
    s.mCommand = command;
    s.mValuesSize = valueCount * 4;
    s.mPort = gWiFiMatching->mOwnPort;
    s.mAddress = gWiFiMatching->mOwnAddress;
    s.mProfileId = gWiFiMatching->mOwnProfileId;
    for (i = 0; i < 5; i++) {
        r = func_ov000_0218b530(gWiFiMatching->mServerList, Gt2FormatAddress(address, 0, 0), port, (u8 *) &s,
                                s.mValuesSize + 0x14);
        if (r == 0 || r != 2) {
            break;
        }
    }
    return r;
}

s32 SendMatchingCommandToProfile(struct GpConnection *gpConnection, u32 command, u32 profileId, const char *text) {
    char v1[0x200];
    char *e;
    char *g;
    s32 n;
    s32 i;

    i = OS_SNPrintf(v1, 0x200, gGpMessagePrefixFormat, gGpcmPrefix, 3, gMatTag);
    v1[i] = command;
    g = v1 + 1;
    e = g + i;
    g[i] = 0;
    if (text != NULL) {
        n = strlen(text);
        MI_CpuCopy8(text, e, n);
        e[n] = 0;
    }
    return GpSendMessage(gpConnection, profileId, v1);
}

s32 CopyNthSlashField(char *out, const char *text, s32 index) {
    const char *e;
    const char *p;
    s32 i;
    s32 n;

    e = strchr(text, 0);
    for (i = 0; i < index; i++) {
        p = strchr(text, 0x2f);
        if (p == NULL) {
            return -1;
        }
        text = p + 1;
    }
    p = strchr(text, 0x2f);
    if (p == NULL) {
        p = e;
    }
    if (text == p) {
        return -1;
    }
    n = p - text;
    MI_CpuCopy8(text, out, n);
    out[n] = 0;
    return n;
}

// One case per command of a received matching message; returns 0 after an error was reported.
s32 ReceiveMatchingCommand(s32 command, u32 profileId, u32 c, u16 d, u32 *values, s32 valueCount) {
    u32 *w;
    u32 z;
    PeerAddress s;
    u32 g[0x41];
    s32 i;
    s32 t;
    u16 y;
    s32 x;
    u32 u;
    u8 v;
    WiFiMatching *o;
    WiFiMatching *p;
    Unk021b5670 *q;
    u32 *n;

    i = 0;
    o = gWiFiMatching;
    if (o == NULL || o->mState == 0) {
        return 1;
    }
    switch (command) {
        case 1:
        case 11:
            t = func_ov000_021a0064(profileId, values[0], command == 11 ? 1 : 0);
            if (t == 2) {
                if (gWiFiMatching->mMode != 0) {
                    c = values[1];
                    d = values[2];
                }
                if (ReportMatchingSendResult(func_ov000_0219ff54(profileId, c, d)) != 0) {
                    return 0;
                }
                p = gWiFiMatching;
                if (p->mMode == 2 && p->mUnk_454 != NULL) {
                    gWiFiMatching->mUnk_454(FindBuddyEntryIndex(profileId), p->mUnk_458);
                }
                g[0] = gWiFiMatching->mUnk_14;
                for (i = 1; i <= gWiFiMatching->mUnk_14; i++) {
                    g[i] = gWiFiMatching->mParticipantProfileIds[i];
                }
                p = gWiFiMatching;
                g[i++] = (u32) p->mOwnAddress;
                g[i++] = p->mOwnPort;
                p->mState = 11;
            }
            if (t == 0xff) {
                break;
            }
            if (ReportMatchingSendResult(SendMatchingCommand(t, profileId, c, d, g, i)) == 0) {
                break;
            }
            return 0;
        case 2:
            if (o->mState != 4) {
                break;
            }
            if (profileId != o->mReplyProfileId) {
                break;
            }
            o->mUnk_1f0 = 0;
            gWiFiMatching->mUnk_19f = 0;
            gWiFiMatching->mUnk_1bc = 0;
            gWiFiMatching->mUnk_1b0 = 0;
            gWiFiMatching->mParticipantCommandAddresses[0] = (values + values[0])[1];
            gWiFiMatching->mParticipantCommandPorts[0] = (values + values[0])[2];
            gWiFiMatching->mUnk_1ac = (values + values[0])[1];
            gWiFiMatching->mUnk_1aa = (values + values[0])[2];
            if (gWiFiMatching->mMode == 1) {
                if (func_ov000_0219f4c4(values + 1, values[0]) != 0) {
                    if (gWiFiMatching->mLastParticipantPos != 0) {
                        StoreMatchingReceivedList(profileId, values);
                    }
                } else {
                    if (ReportMatchingSendResult(func_ov000_0219fb14(profileId)) != 0) {
                        return 0;
                    }
                    if (ReportMatchingSendResult(func_ov000_0219fbec(0, 0)) == 0) {
                        break;
                    }
                    return 0;
                }
            }
            if (gWiFiMatching->mMode == 0) {
                if (gWiFiMatching->mLastParticipantPos != 0) {
                    StoreMatchingReceivedList(profileId, values);
                    if (ReportMatchingSendResult(SendMatchingListAndCloseConnections()) != 0) {
                        return 0;
                    }
                }
                gWiFiMatching->mState = 6;
                if (func_ov000_0219e4a0(
                        func_ov000_021a0cac(0, 0, func_ov000_0218b480(gWiFiMatching->mServerList, 0))) == 0) {
                    break;
                }
                return 0;
            } else {
                gWiFiMatching->mState = 5;
                if (ReportMatchingServerListResult(StartMatchingServerList(profileId)) == 0) {
                    break;
                }
                return 0;
            }
        case 3:
            if (o->mState != 4) {
                break;
            }
            if (profileId != o->mReplyProfileId) {
                break;
            }
            return RestartMatching();
        case 4:
            if (o->mState != 4) {
                break;
            }
            if (profileId != o->mReplyProfileId) {
                break;
            }
            o->mUnk_1c0 = OS_GetTick();
            if ((o->mUnk_1f0 != 0 && o->mUnk_19f < 0x10) || o->mMode == 3) {
                o->mUnk_1b0 = 1;
                p = gWiFiMatching;
                p->mUnk_1b4 = OS_GetTick();
                if (p->mMode == 3) {
                    break;
                }
                p->mUnk_19f++;
                break;
            }
            o->mUnk_1f0 = 0;
            gWiFiMatching->mUnk_19f = 0;
            p = gWiFiMatching;
            if (p->mMode == 0) {
                p->mState = 3;
                gWiFiMatching->mUnk_e8 = 1;
                gWiFiMatching->mUnk_ec = OS_GetTick();
            } else if (p->mMode == 1) {
                func_ov000_0219fbec(1, 0);
            }
            break;
        case 5:
            if (o->mMresvPresent == 0) {
                break;
            }
            if (profileId != o->mMresvProfileId) {
                break;
            }
            if (o->mMode == 2 && o->mLastParticipantPos == 1 && o->mParticipantProfileIds[1] == profileId) {
                func_ov000_021988e8(*o->mConnectionSocket);
            }
            if (func_ov000_0219f9bc(profileId) == 0) {
                return 0;
            }
            break;
        case 6:
            x = values[0];
            y = values[1];
            if (o->mState == 1) {
                o->mState = 6;
            } else {
                if (o->mState != 6 && o->mState != 11) {
                    break;
                }
                if (profileId != o->mMresvProfileId) {
                    break;
                }
            }
            gWiFiMatching->mLastCommand = 0xff;
            p = gWiFiMatching;
            n = &p->mParticipantProfileIds[p->mLastParticipantPos + 1];
            if (profileId != *n) {
                *n = profileId;
            }
            s.mAddress = x;
            s.mPort = ((y >> 8) & 0xff) | ((y << 8) & 0xff00);
            gWiFiMatching->mUnk_18c[0] = 1;
            p = gWiFiMatching;
            func_ov000_0219db18(0, GetSocketDescriptor(*p->mConnectionSocket), &s, p->mUnk_18c);
            gWiFiMatching->mIncomingWaitStartTime = 0;
            break;
        case 7:
            z = values[0];
            u = values[1];
            o->mParticipantProfileIds[o->mUnk_14 + 1] = z;
            gWiFiMatching->mParticipantIndices[gWiFiMatching->mUnk_14 + 1] = u;
            func_ov000_021a4818(gWiFiMatching->mUnk_10);
            p = gWiFiMatching;
            if (p->mUnk_454 == NULL) {
                break;
            }
            gWiFiMatching->mUnk_454(FindBuddyEntryIndex(z), p->mUnk_458);
            break;
        case 8:
            x = values[0];
            z = x;
            if (x == 0) {
                u = values[1];
                o->mParticipantIndices[u] = values[2];
                gWiFiMatching->mParticipantProfileIds[u] = gWiFiMatching->mOwnProfileId;
                func_ov000_0219f544(3);
                break;
            }
            u = values[1];
            v = values[2];
            w = &o->mParticipantProfileIds[u];
            if (x == *w && u == o->mLastParticipantPos - 1) {
                if (ReportMatchingSendResult(SendMatchingCommand(9, profileId, o->mParticipantCommandAddresses[0],
                                                                 o->mParticipantCommandPorts[0], &z, 1)) == 0) {
                    break;
                }
                return 0;
            }
            *w = x;
            gWiFiMatching->mParticipantIndices[u] = v;
            gWiFiMatching->mParticipantCommandAddresses[u] = values[3];
            gWiFiMatching->mParticipantCommandPorts[u] = values[4];
            gWiFiMatching->mUnk_1ac = values[3];
            gWiFiMatching->mUnk_1aa = values[4];
            gWiFiMatching->mState = 5;
            if (ReportMatchingServerListResult(StartMatchingServerList(z)) != 0) {
                return 0;
            }
            gWiFiMatching->mUnk_1bc = 0;
            gWiFiMatching->mUnk_1b0 = 0;
            break;
        case 9:
            if (o->mState != 13) {
                break;
            }
            if (values[0] != o->mParticipantProfileIds[o->mUnk_19c + 1]) {
                break;
            }
            o->mUnk_19c++;
            func_ov000_0219f544(0);
            break;
        case 10:
            if (o->mMode == 0 || func_ov000_0219f4c4(values + 1, values[0]) != 0) {
                gWiFiMatching->mUnk_1f0 = values[1];
                gWiFiMatching->mUnk_19f = 0;
            } else {
                gWiFiMatching->mUnk_1f0 = 0;
            }
            p = gWiFiMatching;
            if (p->mLastParticipantPos != 0) {
                func_ov000_021988e8(*p->mConnectionSocket);
                break;
            }
            if (func_ov000_0219f184() == 0) {
                break;
            }
            return 0;
        case 12:
            if (o->mMode == 0 || o->mMode == 1) {
                if (func_ov000_0219f938(profileId) != 0) {
                    break;
                }
                return 0;
            }
            if (o->mMode == 3) {
                if (values[0] == 0) {
                    o->mUnk_1f4 = profileId;
                    CloseAllMatchingConnections();
                    func_ov000_0219f23c(0);
                } else {
                    func_ov000_0219f124(values[0]);
                }
            }
            break;
        case 13:
        case 14:
        case 15:
            if (func_ov000_0219ec44(profileId, command, values[0]) != FALSE) {
                break;
            }
            return 0;
        case 16:
            if (profileId != o->mParticipantProfileIds[0]) {
                return 1;
            }
            for (i = 0; i < valueCount; i++) {
                t = GetMatchingParticipantIndexByProfileId(values[i], 0);
                if (t != 0xff) {
                    func_ov000_0219bbac(t);
                }
            }
            break;
        case 17:
            q = data_ov000_021b5670;
            if (q != NULL && q->mUnk_00 != 0 && func_ov000_021a350c() - q->mUnk_10 >= q->mUnk_04) {
                g[0] = 1;
            } else {
                g[0] = 0;
            }
            if (ReportMatchingSendResult(SendMatchingCommand(0x12, profileId, c, d, g, 1)) == 0) {
                break;
            }
            return 0;
        case 18:
            if (o->mState != 0x13) {
                break;
            }
            t = GetMatchingParticipantIndexByProfileId(profileId, 0);
            if (t == 0xff) {
                break;
            }
            data_ov000_021b5670->mUnk_08 |= 1 << t;
            if (values[0] != 0) {
                data_ov000_021b5670->mUnk_0c |= 1 << t;
            }
            break;
        case 19:
            ReportMatchingError(10, -80000);
            return 0;
    }
    return 1;
}

s32 func_ov000_021a0064(s32 profileId, u32 senderMode, s32 c) {
    s32 r;

    switch (gWiFiMatching->mMode) {
        case 1:
            if (GpIsBuddy(gWiFiMatching->mGpConnection, profileId) == 0) {
                r = 0xff;
                break;
            }
        case 0:
            if (senderMode != gWiFiMatching->mMode || gWiFiMatching->mStopPending != 0 ||
                gWiFiMatching->mUnk_14 == gWiFiMatching->mUnk_16 ||
                (gWiFiMatching->mMresvPresent != 0 && gWiFiMatching->mMresvProfileId == gWiFiMatching->mOwnProfileId)) {
                r = 3;
                if (gWiFiMatching->mMode == 0 && gWiFiMatching->mUnk_10->mUnk_0b4 == FALSE &&
                    gWiFiMatching->mMresvPresent != 0 &&
                    gWiFiMatching->mMresvProfileId == gWiFiMatching->mOwnProfileId) {
                    func_ov000_021a4818(gWiFiMatching->mUnk_10);
                }
            } else if ((gWiFiMatching->mState != 3 && gWiFiMatching->mState != 4) ||
                       (gWiFiMatching->mOwnAddress == NULL && gWiFiMatching->mOwnPort == 0)) {
                r = 4;
            } else if (gWiFiMatching->mReplyProfileId != 0) {
                if (gWiFiMatching->mReplyProfileId == profileId) {
                    if (c != 0 ||
                        ((s32) gWiFiMatching->mOwnProfileId < profileId && profileId != gWiFiMatching->mUnk_1f0)) {
                        r = 2;
                    } else {
                        r = 0xff;
                    }
                } else if (c != 0 || ((s32) gWiFiMatching->mOwnProfileId < profileId && gWiFiMatching->mUnk_1f0 == 0)) {
                    if (ReportMatchingSendResult(func_ov000_0219fb14(gWiFiMatching->mReplyProfileId)) != 0) {
                        return 0xff;
                    }
                    r = 2;
                } else {
                    r = 3;
                }
            } else {
                r = 2;
            }
            break;
        case 2:
            if (GpIsBuddy(gWiFiMatching->mGpConnection, profileId) == 0) {
                r = 0xff;
            } else if (senderMode != 3 || gWiFiMatching->mUnk_14 == gWiFiMatching->mUnk_16) {
                r = 3;
            } else if (data_ov000_021b5668.mUnk_00 == 1 && data_ov000_021b5668.mUnk_01 == 1) {
                r = 0x13;
            } else if (gWiFiMatching->mState != 10 ||
                       (gWiFiMatching->mOwnAddress == NULL && gWiFiMatching->mOwnPort == 0)) {
                r = 4;
            } else {
                r = 2;
            }
            break;
    }
    return r;
}

u32 func_ov000_0219ff54(u32 profileId, u32 address, u16 port) {
    u32 s[2];
    s32 i;
    u32 r;

    if (gWiFiMatching->mMresvPresent != 0 && gWiFiMatching->mMresvProfileId == profileId) {
        return 0;
    }
    gWiFiMatching->mMresvPresent = 1;
    gWiFiMatching->mMresvProfileId = profileId;
    gWiFiMatching->mUnk_1b0 = 0;
    gWiFiMatching->mUnk_1bc = 0;
    func_ov000_021a4818(gWiFiMatching->mUnk_10);
    gWiFiMatching->mReplyProfileId = 0;
    gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mUnk_14 + 1] = profileId;
    gWiFiMatching->mParticipantCommandAddresses[gWiFiMatching->mUnk_14 + 1] = address;
    gWiFiMatching->mParticipantCommandPorts[gWiFiMatching->mUnk_14 + 1] = port;
    gWiFiMatching->mUnk_1ac = address;
    gWiFiMatching->mUnk_1aa = port;
    gWiFiMatching->mParticipantIndices[gWiFiMatching->mUnk_14 + 1] = FindFreeMatchingParticipantIndex();
    s[0] = profileId;
    s[1] = gWiFiMatching->mParticipantIndices[gWiFiMatching->mUnk_14 + 1];
    for (i = 1; i <= gWiFiMatching->mUnk_14; i++) {
        r = SendMatchingCommand(7, gWiFiMatching->mParticipantProfileIds[i],
                                gWiFiMatching->mParticipantCommandAddresses[i],
                                gWiFiMatching->mParticipantCommandPorts[i], s, 2);
        if (r != 0) {
            return r;
        }
    }
    func_ov000_0219e8b8(1);
    return 0;
}

void StoreMatchingReceivedList(u32 senderProfileId, u32 *values) {
    u32 n;

    n = values[0] + 2;
    if (n > 2) {
        MIi_CpuCopy32(values + 1, &gWiFiMatching->mReceivedList[2], (n - 2) * 4);
    }
    gWiFiMatching->mReceivedList[0] = n - 1;
    gWiFiMatching->mReceivedList[1] = senderProfileId;
}

u32 ReportMatchingSendResult(u32 result) {
    if (gWiFiMatching->mMode == 0) {
        return ReportMatchingServerListResult(result);
    }
    return ReportMatchingGpResult(result);
}

u32 func_ov000_0219fdc8(u32 a, s32 b) {
    u32 s[3];
    u32 t;
    u32 m;
    u32 v;

    if (b != 0) {
        gWiFiMatching->mUnk_1b0 = 1;
        gWiFiMatching->mUnk_1b4 = OS_GetTick();
        gWiFiMatching->mParticipantProfileIds[0] = a;
        return 0;
    }
    if (gWiFiMatching->mMode == 0) {
        t = func_ov000_0218b480(gWiFiMatching->mServerList, 0);
        gWiFiMatching->mParticipantProfileIds[0] = SbServerGetInt((SbServer *) t, gDwcPidKey, 0);
        gWiFiMatching->mParticipantCommandAddresses[0] = func_ov000_0218b27c((u32 *) t);
        gWiFiMatching->mParticipantCommandPorts[0] = func_ov000_0218b260(t);
        gWiFiMatching->mReplyProfileId = gWiFiMatching->mParticipantProfileIds[0];
        m = 1;
    } else {
        if (gWiFiMatching->mMode == 1) {
            gWiFiMatching->mParticipantProfileIds[0] = a;
        }
        gWiFiMatching->mReplyProfileId = a;
        s[1] = (u32) gWiFiMatching->mOwnAddress;
        s[2] = gWiFiMatching->mOwnPort;
        m = 3;
    }
    gWiFiMatching->mUnk_1bc = 6000;
    gWiFiMatching->mUnk_1c0 = OS_GetTick();
    gWiFiMatching->mUnk_1b0 = 0;
    v = gWiFiMatching->mUnk_1f0 != 0 ? 11 : 1;
    s[0] = gWiFiMatching->mMode;
    return SendMatchingCommand(v, a, gWiFiMatching->mParticipantCommandAddresses[0],
                               gWiFiMatching->mParticipantCommandPorts[0], s, m);
}

u32 func_ov000_0219fbec(s32 a, s32 b) {
    BOOL d;
    s32 i;
    BOOL c;
    s32 e;
    char g[8];
    s32 q;
    char x[12];
    GpBuddyStatus h;
    WiFiMatching *p;
    s32 n;
    u32 r;
    s32 k;
    s32 t;
    s32 z;

    if (b != 0) {
        i = gWiFiMatching->mBuddyEntryIndexPos;
    } else if (gWiFiMatching->mBuddyEntryIndexPos < gWiFiMatching->mBuddyEntryIndexCount - 1) {
        i = gWiFiMatching->mBuddyEntryIndexPos + 1;
    } else {
        i = 0;
    }
    c = FALSE;
    d = b == 0;
    while (1) {
        if (d != FALSE || c != FALSE) {
            gWiFiMatching->mBuddyEntryIndexPos++;
            if (gWiFiMatching->mBuddyEntryIndexPos >= gWiFiMatching->mBuddyEntryIndexCount) {
                gWiFiMatching->mBuddyEntryIndexPos = 0;
            }
        }
        if (c != FALSE && gWiFiMatching->mBuddyEntryIndexPos == i) {
            gWiFiMatching->mUnk_1bc = 3000;
            gWiFiMatching->mUnk_1c0 = OS_GetTick();
            gWiFiMatching->mUnk_1b0 = 0;
            return 0;
        }
        c = TRUE;
        p = gWiFiMatching;
        n = DWC_GetGsProfileId(func_ov000_0219c9c4(),
                               (DWCAccFriendData *) (p->mBuddies + p->mBuddyEntryIndices[p->mBuddyEntryIndexPos] * 12));
        if (n == 0) {
            continue;
        }
        if (n == -1) {
            continue;
        }
        if (func_02152698(gWiFiMatching->mBuddies +
                          gWiFiMatching->mBuddyEntryIndices[gWiFiMatching->mBuddyEntryIndexPos] * 12) == 0) {
            continue;
        }
        for (k = 1; k <= gWiFiMatching->mLastParticipantPos; k++) {
            if (n == gWiFiMatching->mParticipantProfileIds[k]) {
                break;
            }
        }
        if (k <= gWiFiMatching->mLastParticipantPos) {
            continue;
        }
        r = GpGetBuddyIndex(gWiFiMatching->mGpConnection, n, &q);
        r |= GpGetBuddyStatus(gWiFiMatching->mGpConnection, q, &h);
        if (r != 0) {
            continue;
        }
        if (h.mUnk_004 != 4) {
            continue;
        }
        t = func_ov000_021a3530(gVerKey, x, h.mUnk_008, 0x2f);
        e = func_ov000_021a3530(gFmeKey, g + 2, h.mUnk_008, 0x2f);
        z = func_ov000_021a3530(gMdfKey, g, h.mUnk_008, 0x2f);
        if (t > 0 && e > 0 && z > 0) {
            if (strtoul(x, NULL, 10) == 3) {
                if (gWiFiMatching->mUnk_16 == strtoul(g + 2, NULL, 10)) {
                    return func_ov000_0219fdc8(n, a);
                }
            }
        }
    }
}

// Starts the search again: the server list in mode 0, the next buddy in mode 1.
u32 RestartMatching(void) {
    WiFiMatching *p;

    gWiFiMatching->mUnk_1f0 = 0;
    gWiFiMatching->mReplyProfileId = 0;
    gWiFiMatching->mUnk_19f = 0;
    p = gWiFiMatching;
    p->mUnk_1c0 = OS_GetTick();
    if (p->mMode == 0) {
        p->mState = 3;
        if (ReportMatchingServerListResult(StartMatchingServerList(0)) != 0) {
            return 0;
        }
    } else if (p->mMode == 1) {
        if (ReportMatchingSendResult(func_ov000_0219fbec(0, 0)) != 0) {
            return 0;
        }
    } else if (p->mMode == 3) {
        ReportMatchingError(6, -80410);
        return 0;
    }
    return 1;
}

u32 func_ov000_0219fb14(u32 a) {
    u32 result;
    result = SendMatchingCommand(5, a, gWiFiMatching->mParticipantCommandAddresses[0],
                                 gWiFiMatching->mParticipantCommandPorts[0], NULL, 0);
    gWiFiMatching->mReplyProfileId = 0;
    return result;
}

u32 func_ov000_0219f9bc(u32 a) {
    s32 i;
    u32 b;

    if (gWiFiMatching->mMresvPresent != 0 && gWiFiMatching->mMresvProfileId == gWiFiMatching->mOwnProfileId) {
        b = 0;
    } else {
        b = 1;
    }
    if (b != 0) {
        gWiFiMatching->mMresvPresent = 0;
        gWiFiMatching->mMresvProfileId = 0;
        func_ov000_021a4818(gWiFiMatching->mUnk_10);
    }
    if (gWiFiMatching->mLastParticipantPos < 0x1f) {
        gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mLastParticipantPos + 1] = 0;
    }
    gWiFiMatching->mLastCommand = 0xff;
    if (gWiFiMatching->mUnk_194 != 0) {
        func_ov000_0219ac50(gWiFiMatching->mUnk_194);
        gWiFiMatching->mUnk_194 = 0;
    }
    gWiFiMatching->mUnk_14 = gWiFiMatching->mLastParticipantPos;
    gWiFiMatching->mReplyProfileId = 0;
    if (b == 0) {
        if (gWiFiMatching->mMode != 3) {
            func_ov000_0219f214();
        }
    } else if (gWiFiMatching->mMode == 0) {
        gWiFiMatching->mState = 3;
        gWiFiMatching->mUnk_e8 = 2;
        gWiFiMatching->mUnk_ec = OS_GetTick();
    } else if (gWiFiMatching->mMode == 1) {
        gWiFiMatching->mState = 4;
        func_ov000_0219fbec(1, 0);
    } else if (gWiFiMatching->mMode == 2) {
        gWiFiMatching->mState = 14;
        gWiFiMatching->mUnk_1cc = 0;
        gWiFiMatching->mUnk_1a8 = 0;
        func_ov000_0219f124(a);
        for (i = 1; i <= gWiFiMatching->mLastParticipantPos; i++) {
            if (func_ov000_0219edb0(gWiFiMatching->mParticipantProfileIds[i], 0xd) == 0) {
                return 0;
            }
        }
        if (gWiFiMatching->mLastParticipantPos == 0) {
            func_ov000_0219f23c(2);
        }
    }
    return 1;
}

u32 func_ov000_0219f938(u32 a) {
    u32 b;

    b = 1;
    if (gWiFiMatching->mMode == 3) {
        if (gWiFiMatching->mLastParticipantPos != 0) {
            CloseAllMatchingConnections();
        }
        ReportMatchingError(6, -80430);
        return 0;
    }
    gWiFiMatching->mUnk_14 = gWiFiMatching->mLastParticipantPos;
    gWiFiMatching->mUnk_1f0 = 0;
    if (gWiFiMatching->mUnk_194 != 0) {
        func_ov000_0219ac50(gWiFiMatching->mUnk_194);
        gWiFiMatching->mUnk_194 = 0;
    }
    if (gWiFiMatching->mLastParticipantPos != 0) {
        func_ov000_0219f214();
    } else {
        gWiFiMatching->mState = 4;
        b = RestartMatching();
    }
    return b;
}

u32 SendMatchingListAndCloseConnections(void) {
    s32 i;
    u32 r;

    for (i = 1; i <= gWiFiMatching->mLastParticipantPos; i++) {
        r = SendMatchingCommand(10, gWiFiMatching->mParticipantProfileIds[i],
                                gWiFiMatching->mParticipantCommandAddresses[i],
                                gWiFiMatching->mParticipantCommandPorts[i], gWiFiMatching->mReceivedList,
                                gWiFiMatching->mReceivedList[0] + 1);
        if (r != 0) {
            return r;
        }
    }
    gWiFiMatching->mMresvPresent = 0;
    gWiFiMatching->mMresvProfileId = 0;
    gWiFiMatching->mUnk_1a0 = 1;
    func_ov000_021988e8(*gWiFiMatching->mConnectionSocket);
    gWiFiMatching->mUnk_1a0 = 0;
    return 0;
}

void func_ov000_0219f544(s32 a) {
    WiFiMatching *p;
    u32 v[4]; // the original also writes v[4], one word past the end
    s32 w;
    s32 f;
    s32 n;
    BOOL c;
    w = 3;
    f = 0;
    switch (a) {
        case 0:
            p = gWiFiMatching;
            if (p->mUnk_19c < p->mLastParticipantPos - 1) {
                p->mState = 13;
                p = gWiFiMatching;
                v[0] = p->mParticipantProfileIds[p->mUnk_19c + 1];
                v[1] = p->mUnk_19c + 1;
                v[2] = p->mParticipantIndices[p->mUnk_19c + 1];
                v[3] = p->mParticipantCommandAddresses[p->mUnk_19c + 1];
                v[4] = p->mParticipantCommandPorts[p->mUnk_19c + 1];
                w = 5;
            } else {
                p->mMresvPresent = 0;
                gWiFiMatching->mMresvProfileId = 0;
                func_ov000_021a4818(gWiFiMatching->mUnk_10);
                p = gWiFiMatching;
                if (p->mMode == 0) {
                    p->mState = 3;
                } else if (p->mMode == 1) {
                    p->mState = 4;
                } else {
                    p->mState = 10;
                }
                gWiFiMatching->mUnk_19c = 0;
                p = gWiFiMatching;
                if (p->mMode == 2 || p->mLastParticipantPos == p->mUnk_16) {
                    if (p->mMode == 2) {
                        p = gWiFiMatching;
                        p->mUnk_1f4 = p->mParticipantProfileIds[p->mLastParticipantPos];
                    } else {
                        p->mUnk_1f4 = 0;
                        p = gWiFiMatching;
                        p->mParticipantProfileIds[0] = p->mOwnProfileId;
                    }
                    gWiFiMatching->mState = 16;
                    gWiFiMatching->mUnk_1c8 = 0;
                    for (n = 1; n <= gWiFiMatching->mLastParticipantPos; n++) {
                        SendMatchingPeerMessage(gWiFiMatching->mParticipantIndices[n], 2);
                    }
                } else {
                    v[0] = 0;
                    v[1] = p->mLastParticipantPos;
                    v[2] = p->mParticipantIndices[p->mLastParticipantPos];
                    if (p->mMode == 0) {
                        p->mUnk_e8 = 2;
                        gWiFiMatching->mUnk_ec = OS_GetTick();
                    } else if (p->mMode == 1) {
                        func_ov000_0219fbec(1, 0);
                    }
                }
                if (gWiFiMatching->mMode != 2) {
                    f = 1;
                }
            }
            if (gWiFiMatching->mState == 16) {
                break;
            }
            p = gWiFiMatching;
            n = p->mLastParticipantPos;
            if (ReportMatchingSendResult(SendMatchingCommand(8, p->mParticipantProfileIds[n],
                                                             p->mParticipantCommandAddresses[n],
                                                             p->mParticipantCommandPorts[n], v, w)) != 0) {
                return;
            }
            gWiFiMatching->mResendCount = 0;
            break;
        case 1:
            gWiFiMatching->mState = 1;
            p = gWiFiMatching;
            if (p->mMode == 3) {
                p->mUnk_1f4 = p->mParticipantProfileIds[p->mLastParticipantPos];
            }
            f = 1;
            break;
        case 2:
            gWiFiMatching->mState = 1;
            p = gWiFiMatching;
            if (p->mMode == 0 || p->mMode == 1) {
                p->mMresvPresent = 1;
                gWiFiMatching->mMresvProfileId = gWiFiMatching->mOwnProfileId;
            }
            p = gWiFiMatching;
            if (p->mLastParticipantPos > 1) {
                if (ReportMatchingSendResult(
                        SendMatchingCommand(9, p->mParticipantProfileIds[0], p->mParticipantCommandAddresses[0],
                                            p->mParticipantCommandPorts[0],
                                            &p->mParticipantProfileIds[p->mLastParticipantPos - 1], 1)) != 0) {
                    return;
                }
            }
            break;
        case 3:
            gWiFiMatching->mState = 1;
            gWiFiMatching->mUnk_1f4 = f;
            f = 1;
            break;
        case 4:
            if (gWiFiMatching->mMode != 2) {
                func_ov000_0219d558(2, gEmptyString, (void *) f);
            }
            p = gWiFiMatching;
            if (p->mUnk_1f4 == 0) {
                c = TRUE;
            } else {
                c = FALSE;
            }
            gWiFiMatching->mResultCallback(0, 0, c, 0, FindBuddyEntryIndex(gWiFiMatching->mUnk_1f4),
                                           p->mResultCallbackArg);
            p = gWiFiMatching;
            if (p->mMode == 0 || p->mMode == 1) {
                StopMatching();
            } else {
                if (p->mServerList != NULL) {
                    func_ov000_0218b64c(p->mServerList);
                    gWiFiMatching->mServerList = NULL;
                }
                func_ov000_0219b110();
                p = gWiFiMatching;
                if (p->mMode == 2) {
                    if (ReportMatchingGpResult(func_ov000_021a1488()) != 0) {
                        return;
                    }
                    if (data_ov000_021b5668.mUnk_00 == 1) {
                        data_ov000_021b5668.mUnk_01 = 1;
                    }
                    gWiFiMatching->mState = 10;
                } else {
                    p->mState = 1;
                }
                gWiFiMatching->mUnk_1f4 = 0;
            }
            gWiFiMatching->mStopPending = 0;
            break;
    }
    if (f != 0) {
        p = gWiFiMatching;
        if (p->mMode != 3) {
            func_ov000_0218b48c(p->mServerList);
        }
    }
}

u32 func_ov000_0219f4c4(u32 *a, u32 b) {
    WiFiMatching *p;
    u32 i;
    p = gWiFiMatching;
    if (p->mUnk_19e != 0 && p->mState == 4) {
        return 1;
    }
    for (i = 0; i < b; i++) {
        if (GpIsBuddy(p->mGpConnection, *a) == 0) {
            return 0;
        }
        p = gWiFiMatching;
        if (p->mUnk_19e != 0 && p->mState == 1) {
            return 1;
        }
        a++;
    }
    return 1;
}

void func_ov000_0219f3cc(void) {
    WiFiMatching *p;
    u32 s;
    gWiFiMatching->mUnk_1f4 = 0;
    p = gWiFiMatching;
    if (p->mState == 2) {
        func_ov000_0219f344();
        return;
    }
    p->mStopPending = 1;
    p = gWiFiMatching;
    s = p->mMode;
    if (s == 3) {
        p->mStopPending = 1;
        p = gWiFiMatching;
        if (p->mLastParticipantPos != 0) {
            func_ov000_021988e8(*p->mConnectionSocket);
        } else {
            if (ReportMatchingSendResult(func_ov000_0219fb14(p->mParticipantProfileIds[0])) != 0) {
                return;
            }
        }
        func_ov000_0219f344();
        return;
    }
    if (p->mState == 4 || p->mState == 5 || p->mState == 6 || p->mState == 7 || p->mState == 11 || p->mState == 12) {
        if (p->mReplyProfileId != 0) {
            if (ReportMatchingSendResult(func_ov000_0219fb14(p->mParticipantProfileIds[0])) != 0) {
                return;
            }
        }
        if (ReportMatchingSendResult(func_ov000_0219f2e4()) != 0) {
            return;
        }
    }
    p = gWiFiMatching;
    if (p->mUnk_194 != 0) {
        func_ov000_0219ac50(p->mUnk_194);
        gWiFiMatching->mUnk_194 = 0;
    }
    p = gWiFiMatching;
    if (p->mLastParticipantPos != 0) {
        p->mStopPending = 1;
        func_ov000_021988e8(*gWiFiMatching->mConnectionSocket);
    }
    func_ov000_0219f344();
}

void func_ov000_0219f344(void) {
    WiFiMatching *p;
    BOOL a;
    BOOL b;
    u32 c;
    if (ReportMatchingGpResult(func_ov000_0219d558(1, gEmptyString, NULL)) == 0) {
        StopMatching();
        p = gWiFiMatching;
        c = p->mUnk_1f4;
        if (c != 0) {
            a = TRUE;
        } else if (p->mMode == 2) {
            a = TRUE;
        } else {
            a = FALSE;
        }
        if (c == 0) {
            b = TRUE;
        } else {
            b = FALSE;
        }
        gWiFiMatching->mResultCallback(0, 1, b, a, FindBuddyEntryIndex(c), p->mResultCallbackArg);
        gWiFiMatching->mStopPending = 0;
    }
}

u32 func_ov000_0219f2e4(void) {
    u32 r;
    u32 v;
    s32 n;
    volatile WiFiMatching *p; // fields are read again on each use
    r = 0;
    v = 0;
    p = gWiFiMatching;
    if (p->mMresvPresent != 0 && p->mMresvProfileId != 0 && p->mMresvProfileId != p->mOwnProfileId) {
        n = p->mLastParticipantPos + 1;
        r = SendMatchingCommand(12, p->mMresvProfileId, p->mParticipantCommandAddresses[n],
                                p->mParticipantCommandPorts[n], &v, 1);
        gWiFiMatching->mMresvPresent = 0;
        gWiFiMatching->mMresvProfileId = 0;
    }
    return r;
}

void func_ov000_0219f23c(s32 a) {
    WiFiMatching *p;
    s32 b;
    BOOL c;
    if (a == 0) {
        func_ov000_0219f344();
        return;
    }
    ResetMatching(a);
    p = gWiFiMatching;
    if (p->mMode == 2 || p->mMode == 3) {
        if (p->mUnk_1f4 == 0) {
            c = TRUE;
        } else {
            c = FALSE;
        }
        gWiFiMatching->mResultCallback(0, 1, c, 0, FindBuddyEntryIndex(p->mUnk_1f4), p->mResultCallbackArg);
    } else if (p->mMode == 0) {
        if (a == 1) {
            if (ReportMatchingServerListResult(StartMatchingServerList(0)) != 0) {
                return;
            }
        }
    } else if (p->mMode == 1) {
        if (a == 1) {
            func_ov000_0219fbec(0, 0);
        }
    }
}

void func_ov000_0219f214(void) {
    WiFiMatching *p;
    p = gWiFiMatching;
    if (p->mMode != 2 && p->mMode != 3) {
        CloseAllMatchingConnections();
        func_ov000_0219f23c(1);
    }
}

u32 func_ov000_0219f184(void) {
    u32 r;
    WiFiMatching *p;
    gWiFiMatching->mMresvPresent = 0;
    gWiFiMatching->mMresvProfileId = 0;
    gWiFiMatching->mUnk_1a0 = 0;
    p = gWiFiMatching;
    if (p->mUnk_1f0 != 0) {
        if (p->mMode == 0) {
            p->mState = 3;
            r = StartMatchingServerList(0);
            if (ReportMatchingServerListResult(r) != 0) {
                return r;
            }
        } else if (p->mMode == 1) {
            p->mState = 4;
            r = func_ov000_0219fdc8(gWiFiMatching->mUnk_1f0, 0);
            if (ReportMatchingSendResult(r) != 0) {
                return r;
            }
        }
    } else {
        func_ov000_0219f23c(1);
    }
    return 0;
}

u32 func_ov000_0219f124(u32 a) {
    void **r;
    gWiFiMatching->mUnk_1f4 = a;
    r = func_ov000_0219b8fc(a, gWiFiMatching->mLastParticipantPos + 1);
    if (r != NULL) {
        gWiFiMatching->mUnk_1a0 = 2;
        func_ov000_02198908(*r);
        gWiFiMatching->mUnk_1a0 = 0;
        return 1;
    }
    RemoveMatchingParticipantByProfileId(a, gWiFiMatching->mLastParticipantPos + 1);
    return 0;
}

void CloseAllMatchingConnections(void) {
    gWiFiMatching->mUnk_1a0 = 2;
    func_ov000_021988e8(*gWiFiMatching->mConnectionSocket);
    gWiFiMatching->mUnk_1a0 = 0;
}

// Tells the participants in the mask to drop the others, then closes the connections to those not in the mask.
u32 DropParticipantsNotInMask(u32 mask) {
    u32 d[32];
    u32 e[32];
    s32 k;
    s32 m;
    s32 n;
    s32 i;
    u32 b;
    WiFiMatching *p;
    m = 0;
    k = 0;
    n = 1;
    p = gWiFiMatching;
    for (; n <= p->mLastParticipantPos; n++) {
        b = 1 << gWiFiMatching->mParticipantIndices[n];
        if ((mask & b) != 0) {
            e[k] = p->mParticipantProfileIds[n];
            k++;
        } else {
            d[m] = p->mParticipantProfileIds[n];
            m++;
        }
    }
    for (i = 0; i < k; i++) {
        if (ReportMatchingSendResult(SendMatchingCommand(0x10, e[i], 0, 0, d, m)) != 0) {
            return 0;
        }
    }
    gWiFiMatching->mUnk_1a0 = 2;
    for (i = 0; i < m; i++) {
        s32 t;
        t = GetMatchingParticipantIndexByProfileId(d[i], 0);
        if (t != 0xff) {
            func_ov000_0219bbac(t);
        }
    }
    gWiFiMatching->mUnk_1a0 = 0;
    return 1;
}

void SendMatchingPeerMessage(s32 peerIndex, u16 kind) {
    u8 n;
    u8 v1[3];
    volatile WiFiMatching *p; // fields are read again on each use
    switch (kind) {
        case 2:
            p = gWiFiMatching;
            if (peerIndex == p->mParticipantIndices[p->mLastParticipantPos]) {
                v1[0] = 1;
            } else {
                v1[0] = 0;
            }
            for (n = 1; n <= p->mLastParticipantPos; n++) {
                if (peerIndex == p->mParticipantIndices[n]) {
                    v1[1] = n;
                    v1[2] = peerIndex;
                    break;
                }
            }
            break;
        case 3:
            p = gWiFiMatching;
            v1[0] = p->mUnk_1a6;
            v1[1] = p->mUnk_1a6 >> 8;
            break;
    }
    StartPeerMessageSend(kind, peerIndex, v1, 4);
    gWiFiMatching->mLastPeerMessageSendTime = func_ov000_021a350c();
}

u32 UpdateMatchingPeerMessageTimeouts(void) {
    WiFiMatching *p;
    u64 t;
    s32 n;
    u8 b;
    p = gWiFiMatching;
    if (p->mState == 9 || p->mState == 16 || p->mState == 17) {
        t = func_ov000_021a350c() - p->mLastPeerMessageSendTime;
    } else {
        return 1;
    }
    switch (p->mState) {
        case 9:
            if (t > 6000) {
                SendMatchingPeerMessage(p->mParticipantIndices[0], 3);
            }
            break;
        case 16:
            if (t > 6000) {
                p->mUnk_1a3[0]++;
                p = gWiFiMatching;
                if (p->mUnk_1a3[0] > 5) {
                    if (p->mMode == 0 || p->mMode == 1) {
                        CloseAllMatchingConnections();
                        func_ov000_0219f23c(1);
                        break;
                    }
                    if (DropParticipantsNotInMask(p->mUnk_1c8) == 0) {
                        return 0;
                    }
                    p = gWiFiMatching;
                    if (p->mLastParticipantPos != 0) {
                        p->mUnk_1a3[0] = 0;
                        gWiFiMatching->mLastPeerMessageSendTime = func_ov000_021a350c();
                    } else {
                        if (func_ov000_0219f9bc(p->mUnk_1f4) == 0) {
                            return 0;
                        }
                    }
                } else {
                    for (n = 1; n <= p->mLastParticipantPos; n++, p = gWiFiMatching) {
                        p = gWiFiMatching;
                        b = p->mParticipantIndices[n];
                        if ((p->mUnk_1c8 & (1 << b)) == 0) {
                            SendMatchingPeerMessage(b, 2);
                        }
                    }
                }
            }
            break;
        case 17:
            if (p->mUnk_1a6 < t) {
                func_ov000_0219f544(4);
            }
            break;
    }
    return 1;
}

u32 func_ov000_0219edb0(u32 a, u32 b) {
    u32 v;
    u32 c;
    if (b == 13) {
        v = gWiFiMatching->mUnk_1f4;
        c = 1;
    } else {
        c = 0;
    }
    if (ReportMatchingSendResult(SendMatchingCommand(b, a, 0, 0, &v, c)) != 0) {
        return 0;
    }
    gWiFiMatching->mUnk_1d8 = func_ov000_021a350c();
    return 1;
}

BOOL func_ov000_0219ec44(u32 a, s32 b, u32 c) {
    WiFiMatching *p;
    u64 t;
    u64 x;
    u64 d;
    u32 m;
    s32 n;
    u32 r;
    if (GetWiFiConnectionState() != 6) {
        return TRUE;
    }
    switch (b) {
        case 13:
            if (gWiFiMatching->mState != 8) {
                gWiFiMatching->mState = 8;
                func_ov000_0219f124(c);
            }
            if (func_ov000_0219edb0(a, 14) == 0) {
                return FALSE;
            }
            break;
        case 14:
            if (gWiFiMatching->mState == 14) {
                t = func_ov000_021a350c();
                p = gWiFiMatching;
                x = p->mUnk_1d8;
                if (x + 600 < t) {
                    d = ((t - x) >> 1) - 300;
                    if (p->mUnk_1a8 < d) {
                        p->mUnk_1a8 = d;
                    }
                }
                r = GetMatchingParticipantIndexByProfileId(a, 0);
                if (r != 0xff) {
                    gWiFiMatching->mUnk_1cc |= 1 << r;
                }
                m = GetMatchingParticipantMaskExceptFirst(1);
                p = gWiFiMatching;
                if (p->mUnk_1cc == m) {
                    for (n = 1; n <= p->mLastParticipantPos; n++, p = gWiFiMatching) {
                        if (func_ov000_0219edb0(p->mParticipantProfileIds[n], 15) == 0) {
                            return FALSE;
                        }
                    }
                    p->mState = 15;
                }
            } else {
                if (func_ov000_0219edb0(a, 15) == 0) {
                    return FALSE;
                }
            }
            break;
        case 15:
            if (gWiFiMatching->mState == 8) {
                func_ov000_0219f23c(2);
            }
            break;
    }
    return TRUE;
}

u32 func_ov000_0219eaf4(void) {
    WiFiMatching *p;
    u64 t;
    s32 n;
    p = gWiFiMatching;
    if (p->mState == 8 || p->mState == 14 || p->mState == 15) {
        t = func_ov000_021a350c() - p->mUnk_1d8;
    } else {
        return 1;
    }
    switch (p->mState) {
        case 8:
            if (t > 6000) {
                if (func_ov000_0219edb0(p->mParticipantProfileIds[0], 14) == 0) {
                    return 0;
                }
            }
            break;
        case 14:
            if (t > 6000) {
                p->mUnk_1a3[1]++;
                p = gWiFiMatching;
                if (p->mUnk_1a3[1] > 5) {
                    if (DropParticipantsNotInMask(p->mUnk_1cc) == 0) {
                        return 0;
                    }
                    p = gWiFiMatching;
                    if (p->mLastParticipantPos != 0) {
                        p->mUnk_1a3[1] = 0;
                        gWiFiMatching->mUnk_1d8 = func_ov000_021a350c();
                    } else {
                        func_ov000_0219f23c(2);
                    }
                } else {
                    for (n = 1; n <= p->mLastParticipantPos; n++, p = gWiFiMatching) {
                        if ((gWiFiMatching->mUnk_1cc & (1 << gWiFiMatching->mParticipantIndices[n])) == 0) {
                            if (func_ov000_0219edb0(p->mParticipantProfileIds[n], 13) == 0) {
                                return 0;
                            }
                        }
                    }
                }
            }
            break;
        case 15:
            if (p->mUnk_1a8 < t) {
                func_ov000_0219f23c(2);
            }
            break;
    }
    return 1;
}

u8 FindFreeMatchingKeyId(void) {
    u8 i = 0;
    do {
        if (gMatchingKeys[i][0] == 0) {
            return i + 100;
        }
        i++;
    } while (i < 154);
    return 0;
}

void ReleaseMatchingKeys(void) {
    s32 i;
    volatile u32 v; // read back from its stack offset
    u8(*e)[12];
    i = 0;
    e = gMatchingKeys;
    for (; i < 0x9a; i++) {
        if (*(u32 *) &e[0][4] != 0) {
            func_ov000_021a3704(4, *(u32 *) &e[0][4], 0);
        }
        e++;
    }
    v = 0;
    MIi_CpuClear32(v, gMatchingKeys, 0x738);
}

u8 FindFreeMatchingParticipantIndex(void) {
    u8 i;
    s32 j;
    volatile WiFiMatching *p; // fields are read again on each use
    i = 0;
    p = gWiFiMatching;
    for (; i < 0x20; i++) {
        for (j = 0; j <= p->mUnk_14; j++) {
            if (i == p->mParticipantIndices[j]) {
                break;
            }
        }
        if (j > p->mUnk_14) {
            break;
        }
    }
    return i;
}

s32 GetSbServerProfileIdIfComplete(u32 server) {
    if (SbServerGetInt((SbServer *) server, gNumPlayersKey, -1) == -1) {
        return 0;
    }
    if (SbServerGetInt((SbServer *) server, gMaxPlayersKey, -1) == -1) {
        return 0;
    }
    if (SbServerGetInt((SbServer *) server, gDwcMtypeKey, -1) == -1) {
        return 0;
    }
    if (SbServerGetInt((SbServer *) server, gDwcMresvKey, -1) == -1 &&
        SbServerGetInt((SbServer *) server, gDwcMresvKey, 0) == 0) {
        return 0;
    }
    if (SbServerGetInt((SbServer *) server, gDwcMverKey, -1) == -1) {
        return 0;
    }
    return SbServerGetInt((SbServer *) server, gDwcPidKey, 0);
}

s32 GetMatchingParticipantIndexByProfileId(u32 profileId, s32 b) {
    if (b == 0) {
        b = 1;
    } else {
        b = 0;
    }
    for (; b <= gWiFiMatching->mLastParticipantPos; b++) {
        if (profileId == gWiFiMatching->mParticipantProfileIds[b]) {
            return gWiFiMatching->mParticipantIndices[b];
        }
    }
    return 0xff;
}

u32 GetMatchingParticipantMaskExceptFirst(s32 a) {
    s32 i;
    u32 r = 0;

    if (a != 0) {
        return gWiFiMatching->mParticipantMask & ~1;
    }
    for (i = 1; i <= gWiFiMatching->mLastParticipantPos; i++) {
        r |= 1 << gWiFiMatching->mParticipantIndices[i];
    }
    return r;
}

void func_ov000_0219e8b8(s32 a) {
    Unk021b5670 *q;
    q = data_ov000_021b5670;
    if (q != NULL && q->mUnk_00 != 0) {
        q->mUnk_08 = 0;
        data_ov000_021b5670->mUnk_0c = 0;
        data_ov000_021b5670->mUnk_02 = 0;
        data_ov000_021b5670->mUnk_18 = func_ov000_021a350c();
        if (a == 0) {
            data_ov000_021b5670->mUnk_10 = func_ov000_021a350c();
        }
    }
}

void func_ov000_0219e668(void) {
    Unk021b5670 *q;
    WiFiMatching *p;
    u32 a;
    u8 b;
    s32 n;
    q = data_ov000_021b5670;
    if (q == NULL) {
        return;
    }
    if (q->mUnk_00 == 0) {
        return;
    }
    p = gWiFiMatching;
    if (p->mMode == 2) {
        return;
    }
    if (p->mMode == 3) {
        return;
    }
    if (p->mState == 0x13) {
        a = GetMatchingParticipantMaskExceptFirst(0);
        q = data_ov000_021b5670;
        if (q->mUnk_08 == a) {
            if (q->mUnk_0c == a) {
                gWiFiMatching->mUnk_16 = gWiFiMatching->mLastParticipantPos;
                gWiFiMatching->mUnk_19c = gWiFiMatching->mLastParticipantPos - 1;
                func_ov000_0219f544(0);
                return;
            }
            q->mUnk_18 = func_ov000_021a350c();
            q->mUnk_08 = 0;
            p = gWiFiMatching;
            if (p->mMode == 0) {
                p->mState = 3;
                gWiFiMatching->mUnk_e8 = 2;
                gWiFiMatching->mUnk_ec = OS_GetTick();
                return;
            }
            p->mState = 4;
            func_ov000_0219fbec(1, 0);
            return;
        }
        b = q->mUnk_02;
        if (func_ov000_021a350c() - q->mUnk_18 < b * 0x1770) {
            return;
        }
        if (b > 5) {
            func_ov000_0219e8b8(1);
            CloseAllMatchingConnections();
            func_ov000_0219f23c(1);
            return;
        }
        for (n = 1; n <= (p = gWiFiMatching)->mLastParticipantPos; n++) {
            if ((data_ov000_021b5670->mUnk_08 & (1 << p->mParticipantIndices[n])) == 0) {
                p = gWiFiMatching;
                if (ReportMatchingSendResult(SendMatchingCommand(0x11, p->mParticipantProfileIds[n],
                                                                 p->mParticipantCommandAddresses[n],
                                                                 p->mParticipantCommandPorts[n], NULL, 0)) != 0) {
                    return;
                }
            }
        }
        data_ov000_021b5670->mUnk_02++;
    } else if (p->mState == 3 || p->mState == 4) {
        if (p->mLastParticipantPos < q->mUnk_01 - 1) {
            return;
        }
        if (q->mUnk_02 != 0 || func_ov000_021a350c() - q->mUnk_10 < q->mUnk_04) {
            if (q->mUnk_02 == 0) {
                return;
            }
            q = data_ov000_021b5670;
            if (func_ov000_021a350c() - q->mUnk_18 < (q->mUnk_04 >> 2)) {
                return;
            }
        }
        p = gWiFiMatching;
        if (p->mReplyProfileId != 0) {
            if (ReportMatchingSendResult(func_ov000_0219fb14(p->mReplyProfileId)) != 0) {
                return;
            }
        }
        p = gWiFiMatching;
        p->mState = 0x13;
        for (n = 1; n <= gWiFiMatching->mLastParticipantPos; n++) {
            p = gWiFiMatching;
            if (ReportMatchingSendResult(SendMatchingCommand(0x11, p->mParticipantProfileIds[n],
                                                             p->mParticipantCommandAddresses[n],
                                                             p->mParticipantCommandPorts[n], NULL, 0)) != 0) {
                return;
            }
        }
        q = data_ov000_021b5670;
        q->mUnk_18 = func_ov000_021a350c();
        q->mUnk_02 = 1;
    }
}

u32 ReportMatchingGpResult(u32 result) {
    s32 b;
    s32 c;
    if (result == 0) {
        return 0;
    }
    switch (result) {
        case 1:
            b = 11;
            c = -1;
            break;
        case 2:
            b = 11;
            c = -2;
            break;
        case 3:
            b = 6;
            c = -10;
            break;
        case 4:
            b = 6;
            c = -20;
            break;
    }
    ReportMatchingError(b, c - 0x13c68);
    return result;
}

u32 ReportMatchingServerListResult(u32 result) {
    s32 b;
    s32 c;
    if (result == 0) {
        return 0;
    }
    switch (result) {
        case 1:
            b = 6;
            c = -50;
            break;
        case 2:
            b = 6;
            c = -30;
            break;
        case 3:
            b = 6;
            c = -20;
            break;
        case 4:
            b = 6;
            c = -40;
            break;
        case 5:
            b = 11;
            c = -1;
            break;
        case 6:
            b = 11;
            c = -2;
            break;
    }
    ReportMatchingError(b, c - 0x14c08);
    return result;
}

u32 func_ov000_0219e4e8(u32 a) {
    s32 c;
    s32 b;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            b = 6;
            c = -50;
            break;
        case 2:
            b = 6;
            c = -60;
            break;
        case 3:
            b = 6;
            c = -30;
            break;
        case 4:
            b = 6;
            c = -80;
            break;
        case 5:
            b = 6;
            c = -20;
            break;
    }
    switch (GetWiFiConnectionState()) {
        case 2:
            ReportWiFiLoginError(b, c - 0xfa00);
            break;
        case 4:
            ReportBuddySyncError(b, c - 0x12110);
            break;
        case 5:
            ReportMatchingError(b, c - 0x14820);
            break;
        default:
            func_ov000_0219c384(b, c - 0x16f30);
            break;
    }
    return a;
}

s32 func_ov000_0219e4a0(s32 a) {
    s32 b;
    s32 c;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            b = 11;
            c = -1;
            break;
        case 2:
            b = 6;
            c = -50;
            break;
        case 3:
            b = 6;
            c = -30;
            break;
    }
    ReportMatchingError(b, c - 0x14ff0);
    return a;
}

s32 func_ov000_0219e45c(s32 a) {
    enum { K6 = 6 } b;
    s32 c;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            b = K6;
            c = -9;
            break;
    }
    if (b != 0) {
        ReportMatchingError(b, c - 0x14ff0);
    }
    return a;
}

u32 ReportMatchingConnectResult(u32 result) {
    s32 b;
    s32 c;
    if (result == 0) {
        return 0;
    }
    switch (result) {
        case 1:
            b = 11;
            c = -1;
            break;
        case 2:
        case 5:
            b = 0;
            c = 0;
            result = 0;
            break;
        case 3:
            b = 6;
            c = -10;
            break;
        case 4:
            b = 6;
            c = -30;
            break;
        case 6:
            b = 6;
            c = -70;
            break;
        case 7:
            b = 6;
            c = -80;
            break;
    }
    if (b != 0) {
        ReportMatchingError(b, c - 0x153d8);
    }
    return result;
}

void WiFiMatchingServerListCallback(Unk0218b668 *list, s32 event, s32 c) {
    s32 d;
    u32 e;
    WiFiMatching *f;
    switch (event) {
        case 0:
            func_ov000_0219e134(c);
            return;
        case 4:
            d = 0;
            if ((s32) func_ov000_0218b474(list) > 0) {
                do {
                    e = func_ov000_0218b480(list, d);
                    if (GetSbServerProfileIdIfComplete(e) == 0) {
                        func_ov000_0218b4d4(list, e);
                        d--;
                    }
                    d++;
                } while (d < (s32) func_ov000_0218b474(list));
            }
            switch (gWiFiMatching->mState) {
                case 2:
                    d = 0;
                    if ((s32) func_ov000_0218b474(list) > 0) {
                        do {
                            e = func_ov000_0218b480(list, d);
                            f = gWiFiMatching;
                            if (f->mOwnAddress != NULL && f->mOwnAddress == (void *) func_ov000_0218b27c((u32 *) e) &&
                                f->mOwnPort != 0 && gWiFiMatching->mOwnPort == func_ov000_0218b260(e)) {
                                break;
                            }
                            d++;
                        } while (d < (s32) func_ov000_0218b474(list));
                    }
                    if (d < (s32) func_ov000_0218b474(list)) {
                        gWiFiMatching->mState = 3;
                        gWiFiMatching->mReplyProfileId = 0;
                        if (ReportMatchingServerListResult(StartMatchingServerList(gWiFiMatching->mReplyProfileId)) !=
                            0) {
                            return;
                        }
                        return;
                    }
                    gWiFiMatching->mUnk_e8 = 2;
                    gWiFiMatching->mUnk_ec = OS_GetTick();
                    return;
                case 3:
                    FilterAndEvalMatchingServerList(1);
                    if (func_ov000_0218b474(list) != 0) {
                        if (ReportMatchingSendResult(func_ov000_0219fdc8(0, 0)) != 0) {
                            return;
                        }
                        gWiFiMatching->mState = 4;
                        gWiFiMatching->mUnk_e8 = 0;
                        return;
                    }
                    gWiFiMatching->mUnk_e8 = 2;
                    gWiFiMatching->mUnk_ec = OS_GetTick();
                    return;
                case 5:
                    if (func_ov000_0218b474(list) != 0) {
                        do {
                            e = func_ov000_0218b480(list, 0);
                            if (gWiFiMatching->mUnk_1ac == func_ov000_0218b27c((u32 *) e) &&
                                gWiFiMatching->mUnk_1aa == func_ov000_0218b260(e)) {
                                break;
                            }
                            func_ov000_0218b4d4(list, e);
                        } while (func_ov000_0218b474(list) != 0);
                    }
                    if (func_ov000_0218b474(list) != 0) {
                        e = SbServerGetInt((SbServer *) func_ov000_0218b480(list, 0), gDwcPidKey, 0);
                        f = gWiFiMatching;
                        if (f->mMode == 1 && e == f->mParticipantProfileIds[0]) {
                            if (FilterAndEvalMatchingServerList(0) != FALSE) {
                                if (gWiFiMatching->mLastParticipantPos != 0) {
                                    if (ReportMatchingSendResult(SendMatchingListAndCloseConnections()) != 0) {
                                        return;
                                    }
                                }
                            } else {
                                if (ReportMatchingSendResult(
                                        func_ov000_0219fb14(gWiFiMatching->mParticipantProfileIds[0])) != 0) {
                                    return;
                                }
                                gWiFiMatching->mState = 4;
                                if (ReportMatchingSendResult(func_ov000_0219fbec(0, 0)) != 0) {
                                    return;
                                }
                                return;
                            }
                        }
                        gWiFiMatching->mState = 6;
                        if (func_ov000_0219e4a0(func_ov000_021a0cac(0, 0, func_ov000_0218b480(list, 0))) != 0) {
                            return;
                        }
                        return;
                    }
                    gWiFiMatching->mUnk_e8 = 2;
                    gWiFiMatching->mUnk_ec = OS_GetTick();
                    return;
            }
            return;
        case 5:
            break;
    }
}

void func_ov000_0219e134(s32 a) {}

// Removes servers already in the list or refused by mEvalCallback and stores the callback's value for each remaining
// one under dwc_eval.
BOOL FilterAndEvalMatchingServerList(s32 a) {
    BOOL c;
    BOOL d;
    s32 e;
    u32 f;
    u32 g;
    s32 h;
    c = FALSE;
    e = 0;
    for (; e < (s32) func_ov000_0218b474(gWiFiMatching->mServerList); e++) {
        f = func_ov000_0218b480(gWiFiMatching->mServerList, e);
        if (gWiFiMatching->mMode == 0) {
            g = SbServerGetInt((SbServer *) f, gDwcPidKey, 0);
            d = FALSE;
            for (h = 1; h <= gWiFiMatching->mLastParticipantPos; h++) {
                if (g == gWiFiMatching->mParticipantProfileIds[h]) {
                    func_ov000_0218b4d4(gWiFiMatching->mServerList, f);
                    e--;
                    d = TRUE;
                    break;
                }
            }
            if (d != FALSE) {
                continue;
            }
        }
        if (gWiFiMatching->mEvalCallback != 0) {
            g = ((s32(*)(s32, u32)) gWiFiMatching->mEvalCallback)(e, gWiFiMatching->mEvalCallbackArg);
            if ((s32) g > 0) {
                if ((s32) g > 0x7fffff) {
                    g = 0x7fffff;
                }
                SbServerSetInt((SbServer *) f, gDwcEvalKey, (g << 8) | func_ov000_021a3448(0x100));
            } else {
                func_ov000_0218b4d4(gWiFiMatching->mServerList, f);
                e--;
                c = TRUE;
            }
        } else {
            SbServerSetInt((SbServer *) f, gDwcEvalKey, func_ov000_021a3448(0x80));
        }
    }
    if (a != 0 && func_ov000_0218b474(gWiFiMatching->mServerList) != 0) {
        func_ov000_0218b464(gWiFiMatching->mServerList, 0, gDwcEvalKey, 0);
    }
    if (c != FALSE && func_ov000_0218b474(gWiFiMatching->mServerList) == 0) {
        return FALSE;
    }
    return TRUE;
}

void WriteMatchingKeyValue(s32 keyId, Unk021a471c *buffer, void *c) {
    s32 d;
    switch (keyId) {
        case 8:
            func_ov000_021a4760(buffer, gWiFiMatching->mUnk_14);
            return;
        case 0xa:
            func_ov000_021a4760(buffer, gWiFiMatching->mUnk_16);
            return;
        case 0x32:
            func_ov000_021a4760(buffer, gWiFiMatching->mOwnProfileId);
            return;
        case 0x33:
            func_ov000_021a4760(buffer, gWiFiMatching->mMode);
            return;
        case 0x34:
            func_ov000_021a4760(buffer, gWiFiMatching->mMresvProfileId);
            return;
        case 0x35:
            func_ov000_021a4760(buffer, 3);
            return;
        case 0x36:
            func_ov000_021a4760(buffer, 1);
            return;
    }
    d = keyId - 100;
    if (gMatchingKeys[d][0] != 0) {
        if (data_ov000_021b5699[d * 12] != 0) {
            func_ov000_021a471c(buffer, *(const char **) &data_ov000_021b56a0[d * 12]);
        } else {
            func_ov000_021a4760(buffer, **(s32 **) &data_ov000_021b56a0[d * 12]);
        }
    }
}

void func_ov000_0219dedc(void) {}

void func_ov000_0219ded8(void) {}

void AddMatchingKeyIds(s32 event, MatchingKeyIds *keyIds, void *c) {
    s32 i;
    u8 *d;
    switch (event) {
        case 0:
            func_ov000_021a4784(keyIds, 8);
            func_ov000_021a4784(keyIds, 0xa);
            func_ov000_021a4784(keyIds, 0x32);
            func_ov000_021a4784(keyIds, 0x33);
            func_ov000_021a4784(keyIds, 0x34);
            func_ov000_021a4784(keyIds, 0x35);
            func_ov000_021a4784(keyIds, 0x36);
            i = 0;
            d = gMatchingKeys[0];
            for (; i < 0x9a; i++) {
                if (d[0] != 0) {
                    func_ov000_021a4784(keyIds, d[0]);
                }
                d += 12;
            }
            break;
        case 1:
            break;
        case 2:
            break;
    }
}

s32 func_ov000_0219de64(void) {
    return 0;
}

u32 func_ov000_0219de5c(u32 kind) {
    return func_ov000_0219e4e8(kind);
}

void SetMatchingOwnAddress(void *address, u16 port) {
    gWiFiMatching->mOwnAddress = address;
    gWiFiMatching->mOwnPort = port;
}

void func_ov000_0219ddbc(u32 a) {
    if (gWiFiMatching->mState == 1) {
        gWiFiMatching->mState = 6;
    } else if (gWiFiMatching->mState != 6 && gWiFiMatching->mState != 0xb) {
        return;
    }
    if (gWiFiMatching->mUnk_178 == a) {
        gWiFiMatching->mUnk_174[0]++;
    } else {
        gWiFiMatching->mUnk_174[0] = 0;
        gWiFiMatching->mUnk_178 = a;
    }
    gWiFiMatching->mUnk_17c = 0;
    if (func_ov000_0219e4a0(func_ov000_021a0cac(1, a, 0)) == 0) {
        gWiFiMatching->mLastCommand = 0xff;
    }
}

void ParseMatchingRecords(const void *a, u32 b) {
    MatchingReceiveHeader c;
    u8 d[0x80];
    u32 e;
    e = 0;
    if (b >= 0x14) {
        do {
            MI_CpuCopy8(a, &c, 0x14);
            if (strncmp(c.mSignature, gMatchingSignature, 4) != 0) {
                break;
            }
            if (c.mUnk_04 != 3) {
                break;
            }
            MI_CpuCopy8(a + 0x14, d, c.mValuesSize);
            if (ReceiveMatchingCommand(c.mCommand, c.mProfileId, c.mAddress, c.mPort, (u32 *) d, c.mValuesSize >> 2) ==
                0) {
                break;
            }
            e += c.mValuesSize + 0x14;
        } while (e + 0x14 <= b);
    }
}
