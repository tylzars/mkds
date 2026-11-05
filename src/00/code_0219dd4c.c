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
#include "code_0200d118.h"
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

// Per login (called by InitWiFiConnection): stores gWiFiMatching and the given pointers (GP connection, socket address,
// callbacks record, game name, key) and two values, clears the fields and resets the search (func_ov000_021a1140). Pair
// of the release path func_ov000_021a1430.
void InitMatching(WiFiMatching *param_1, GpConnection *param_2, void **param_3, void *param_4, void *param_5,
                  void *param_6, void *param_7, u32 param_8) {
    gWiFiMatching = param_1;
    param_1->mGpConnection = param_2;
    gWiFiMatching->mConnectionSocket = param_3;
    gWiFiMatching->mConnectionCallbacks = param_4;
    gWiFiMatching->mUnk_10 = NULL;
    gWiFiMatching->mUnk_1c = NULL;
    gWiFiMatching->mUnk_1a = 0;
    gWiFiMatching->mUnk_e4 = NULL;
    gWiFiMatching->mState = 0;
    gWiFiMatching->mUnk_0f = 0;
    gWiFiMatching->mUnk_19 = 0;
    gWiFiMatching->mUnk_1a5 = 0;
    gWiFiMatching->mUnk_1e8 = 0;
    gWiFiMatching->mGameName = param_5;
    gWiFiMatching->mUnk_2e0 = param_6;
    gWiFiMatching->mUnk_2e4 = param_7;
    gWiFiMatching->mUnk_2e8 = param_8;
    MemFill(gWiFiMatching->mUnk_2ec, 0, 0x40);
    gWiFiMatching->mUnk_32c = 0;
    gWiFiMatching->mResultCallback = NULL;
    gWiFiMatching->mResultCallbackArg = 0;
    gWiFiMatching->mUnk_45c = 0;
    gWiFiMatching->mUnk_460 = 0;
    func_ov000_0219ea88();
    data_ov000_021b5668.mUnk_00 = 0;
    data_ov000_021b5668.mUnk_01 = 0;
    data_ov000_021b5668.mUnk_02 = 0;
    func_ov000_021a1140(0);
}

u32 func_ov000_021a2768(u32 param_1) {
    WiFiMatching *p;
    s32 i;
    u32 r;
    p = gWiFiMatching;
    if (p->mUnk_10 != NULL) {
        return 0;
    }
    p->mUnk_1e8 = param_1;
    i = 0;
    do {
        p = gWiFiMatching;
        r = func_ov000_021a4a08(&gWiFiMatching->mUnk_10, GetSocketDescriptor(*p->mConnectionSocket),
                                GetSocketPort(*p->mConnectionSocket), p->mGameName, p->mUnk_2e0, 1, 1,
                                (Unk021a4a08Func88) func_ov000_0219dee0, (Unk021a4a08Func8c) func_ov000_0219dedc,
                                (Unk021a4a08Func8c) func_ov000_0219ded8, (Unk021a4a08Func94) func_ov000_0219de68,
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
    gWiFiMatching->mUnk_1c = NULL;
    gWiFiMatching->mUnk_1a = 0;
    func_ov000_021a49cc(gWiFiMatching->mUnk_10, func_ov000_0219de4c);
    func_ov000_021a49f4(gWiFiMatching->mUnk_10, func_ov000_0219ddbc);
    func_ov000_021a49e0(gWiFiMatching->mUnk_10, func_ov000_0219dd4c);
    func_ov000_021a4818(gWiFiMatching->mUnk_10);
    return r;
}

// Mode 0 start: keeps the filter text in data_ov000_021b5674 when one is given (the old copy is freed first; allocation
// failure reports error 11), SetupMatching with mode 0, stores the second callback pair, mState 2, creates the search
// object at mUnk_e4 and starts the query. Only caller StartWiFiMatchingWithFilter; the filter comes from
// RegisterKartKeysAndStart (code_02120610.c:436).
void StartMatchingWithFilter(u32 param_1, const void *param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
    char v1[0x100];
    s32 n;
    if (data_ov000_021b5674 != NULL) {
        func_ov000_021a3704(4, (u32) data_ov000_021b5674, 0);
        data_ov000_021b5674 = NULL;
    }
    if (param_2 != NULL) {
        n = func_ov000_021a0ed8(v1, -1, 0x20, 3);
        n = 0x100 - n - strlen(data_ov000_021b41e8);
        data_ov000_021b5674 = func_ov000_021a372c(4, n);
        if (data_ov000_021b5674 == NULL) {
            func_ov000_021a1a38(11, -80001);
            return;
        }
        MemCopy(param_2, data_ov000_021b5674, n);
        *((u8 *) data_ov000_021b5674 + n - 1) = 0;
    }
    ((void (*)(u32, u32, u32, u32)) SetupMatching)(0, param_1, param_3, param_4);
    gWiFiMatching->mUnk_45c = param_5;
    gWiFiMatching->mUnk_460 = param_6;
    gWiFiMatching->mState = 2;
    if (gWiFiMatching->mUnk_e4 == NULL) {
        gWiFiMatching->mUnk_e4 = func_ov000_0218b668(gWiFiMatching->mGameName, gWiFiMatching->mGameName,
                                                     gWiFiMatching->mUnk_2e0, 0, 20, 1, 0, func_ov000_0219e138, 0);
    }
    if (gWiFiMatching->mUnk_e4 == NULL && func_ov000_0219e594(5) != 0) {
        return;
    }
    func_ov000_0219d558(3, data_ov000_021b4114, NULL);
    if (func_ov000_0219e594(func_ov000_021a0f20(gWiFiMatching->mUnk_1e8)) != 0) {
        return;
    }
    if (gWiFiMatching->mUnk_10 == NULL) {
        func_ov000_021a2768(gWiFiMatching->mUnk_1e8);
    }
    func_ov000_0219e8b8(0);
}

// Mode 1 start: copies the given u8 list (param_2 entries) to mUnk_2ec, SetupMatching with mode 1, stores the second
// callback pair; reports error 7 when the list is empty or too short for the wanted count (code_0219dd4c.c:200),
// else mState 4, creates the search object and starts. The one caller passes NULL, so the list is the one
// StartWiFiMatchingWithBuddies builds: buddy entry indices in random order (code_0219b580.c:331-345). Weak:
// that content rests on that single branch.
void StartMatchingWithBuddies(const void *param_1, s32 param_2, s32 param_3, s32 param_4, void *param_5, u32 param_6,
                              u32 param_7, u32 param_8) {
    char v1[12];
    u8 v2[0x24];
    ((void (*)(u32, u32, u32, u32)) SetupMatching)(1, param_3, (u32) param_5, param_6);
    gWiFiMatching->mUnk_19e = param_4 != 0 ? 1 : 0;
    gWiFiMatching->mUnk_45c = param_7;
    gWiFiMatching->mUnk_460 = param_8;
    MemCopy(param_1, gWiFiMatching->mUnk_2ec, param_2);
    gWiFiMatching->mUnk_32c = param_2;
    if (param_2 == 0 || (param_2 < param_3 && param_4 == 0 &&
                         (data_ov000_021b5670 == NULL || data_ov000_021b5670->mUnk_00 == 0 ||
                          param_2 < data_ov000_021b5670->mUnk_01 - 1))) {
        func_ov000_021a1a38(7, 0);
        return;
    }
    gWiFiMatching->mState = 4;
    if (gWiFiMatching->mUnk_e4 == NULL) {
        gWiFiMatching->mUnk_e4 = func_ov000_0218b668(gWiFiMatching->mGameName, gWiFiMatching->mGameName,
                                                     gWiFiMatching->mUnk_2e0, 0, 20, 1, 0, func_ov000_0219e138, 0);
    }
    if (gWiFiMatching->mUnk_e4 == NULL && func_ov000_0219e594(5) != 0) {
        return;
    }
    StringFormatBounded(v1, 12, data_ov000_021b40b8, param_3);
    func_ov000_021a363c(data_ov000_021b411c, v1, v2, 0x2f);
    func_ov000_021a360c(data_ov000_021b4120, param_4 != 0 ? data_ov000_021b41e0 : data_ov000_021b41e4, v2, 0x2f);
    StringFormatBounded(v1, 12, data_ov000_021b40b8, 3);
    func_ov000_021a360c(data_ov000_021b4118, v1, v2, 0x2f);
    if (func_ov000_0219e608(func_ov000_0219d558(4, v2, NULL)) != 0) {
        return;
    }
    if (func_ov000_0219fee4(func_ov000_0219fbec(0, 1)) != 0) {
        return;
    }
    if (gWiFiMatching->mUnk_10 == NULL) {
        func_ov000_021a2768(gWiFiMatching->mUnk_1e8);
    }
    func_ov000_0219e8b8(0);
}

// Called in connection states 3 to 6 every frame (UpdateWiFiConnection); returns when gWiFiMatching is NULL or an error
// is pending. With parameter 0 it only pumps the query-report and the socket; with 1 it also steps mState. Parameter: 0
// in states 3 and 4, 1 in state 5, in state 6 1 for modes 2 and 3 else 0 (only while the socket exists).
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
                            func_ov000_021a1a38(6, -80430);
                            return;
                        }
                        if (func_ov000_0219fee4(func_ov000_0219fdc8(p->mParticipantProfileIds[0], 0)) != 0) {
                            return;
                        }
                    } else if (func_ov000_0219fb48(param_1) == 0) {
                        return;
                    }
                }
            }
            p = gWiFiMatching;
            if (p->mUnk_1b0 != 0) {
                n = (u32) (p->mLastParticipantPos * 3000) + 3000;
                if ((OS_GetTick() - p->mUnk_1b4) * 64 / 0x82ea >= n) {
                    if (func_ov000_0219fee4(func_ov000_0219fdc8(p->mParticipantProfileIds[0], 0)) != 0) {
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
                    if (func_ov000_0219e594(func_ov000_021a0f20(p->mUnk_1ec)) != 0) {
                        return;
                    }
                    gWiFiMatching->mUnk_e8 = 0;
                }
            }
            break;
        case 7:
            if (p->mUnk_184 != 0) {
                if (func_ov000_021a350c() - p->mUnk_184 > 25000) {
                    gWiFiMatching->mUnk_184 = 0;
                    if (func_ov000_0219f938(gWiFiMatching->mParticipantProfileIds[0]) == 0) {
                        return;
                    }
                }
            } else if (p->mUnk_3b4 == 6) {
                if (func_ov000_021a350c() - p->mUnk_444 > 6000) {
                    p->mUnk_3b5++;
                    p = gWiFiMatching;
                    if (p->mUnk_3b5 > 5) {
                        func_ov000_021a1ac0();
                        if (func_ov000_0219f938(gWiFiMatching->mParticipantProfileIds[0]) == 0) {
                            return;
                        }
                    } else if (func_ov000_0219fee4(func_ov000_021a0ae8(6, p->mUnk_43c, p->mUnk_3b8, p->mUnk_3b6,
                                                                       p->mUnk_3bc, p->mUnk_440)) != 0) {
                        return;
                    }
                }
            }
            break;
        case 11:
            if (p->mUnk_3b4 == 2) {
                if ((p->mMode == 0 && func_ov000_021a350c() - gWiFiMatching->mUnk_444 > 6000) ||
                    func_ov000_021a350c() - gWiFiMatching->mUnk_444 > 19000) {
                    func_ov000_021a1ac0();
                    if (func_ov000_0219f9bc(
                            gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mLastParticipantPos + 1]) == 0) {
                        return;
                    }
                }
            }
            break;
        case 13:
            if (p->mUnk_3b4 == 8) {
                if (func_ov000_021a350c() - p->mUnk_444 > 30000) {
                    p->mUnk_3b5++;
                    p = gWiFiMatching;
                    if (p->mUnk_3b5 != 0) {
                        func_ov000_021a1ac0();
                        p = gWiFiMatching;
                        if (p->mMode == 2) {
                            if (func_ov000_0219f9bc(p->mParticipantProfileIds[p->mLastParticipantPos]) == 0) {
                                return;
                            }
                        } else {
                            func_ov000_0219f214();
                        }
                    } else if (func_ov000_0219fee4(func_ov000_021a0ae8(8, p->mUnk_43c, p->mUnk_3b8, p->mUnk_3b6,
                                                                       p->mUnk_3bc, p->mUnk_440)) != 0) {
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
    if (gWiFiMatching->mUnk_e4 != NULL) {
        func_ov000_0218b4bc(gWiFiMatching->mUnk_e4);
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
    if (func_ov000_0219ee14() != 0) {
        if (func_ov000_0219eaf4() != 0) {
            func_ov000_0219e668();
        }
    }
}

u32 func_ov000_021a1e40(u32 param_1, u32 param_2, u16 param_3, u8 *param_4, u32 param_5) {
    Unk021a1e40 a;
    volatile u32 v; // placeholder: value passed through a stack offset
    u32 c;
    if (param_5 == 0 || param_4 == NULL) {
        return 0;
    }
    v = 0;
    MemFillWords(v, &a, 8);
    a.mUnk_01 = 2;
    a.mUnk_04 = param_2;
    a.mUnk_02 = ((param_3 >> 8) & 0xff) | ((param_3 << 8) & 0xff00);
    c = param_4[0];
    if ((c == 0xfe && param_4[1] == 0xfd) || c == 0x5c) {
        if (gWiFiMatching->mUnk_10 != NULL) {
            func_ov000_021a3c14((Unk021a3a18 *) gWiFiMatching->mUnk_10, (s8 *) param_4, param_5, &a);
        }
    } else if (memcmp(param_4, data_ov000_021b400c, 6) == 0) {
        func_ov000_0219a7e4(param_4, param_5, &a);
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

void func_ov000_021a1ca8(u32 param_1, Unk0219887c *param_2, u32 param_3, u32 param_4, s32 param_5, char *param_6) {
    WiFiMatching *p;
    Unk021b5550 *e;
    void **q;
    s32 i;
    s32 j;
    s32 t;
    p = gWiFiMatching;
    if (p == NULL || p->mState != 7 || p->mUnk_1a1 != 0) {
        func_ov000_02198a74((Gt2Connection *) param_2, data_ov000_021b41b0, -1);
        return;
    }
    i = func_ov000_0219b998();
    if (i == -1) {
        func_ov000_02198a74((Gt2Connection *) param_2, data_ov000_021b41bc, -1);
        func_ov000_021a1a38(6, -87100);
        return;
    }
    if (param_3 != gWiFiMatching->mUnk_1f8[gWiFiMatching->mLastParticipantPos] ||
        param_4 != gWiFiMatching->mUnk_278[gWiFiMatching->mLastParticipantPos]) {
        j = gWiFiMatching->mLastParticipantPos;
        if (*param_6 != 0 &&
            (p = *(WiFiMatching **) &gWiFiMatching, p->mParticipantProfileIds[j] == strtoul(param_6, NULL, 10))) {
            gWiFiMatching->mUnk_1f8[j] = param_3;
            gWiFiMatching->mUnk_278[gWiFiMatching->mLastParticipantPos] = param_4;
        } else {
            func_ov000_02198a74((Gt2Connection *) param_2, data_ov000_021b41c8, -1);
            return;
        }
    }
    gWiFiMatching->mUnk_184 = 0;
    if (func_ov000_02198a7c((Gt2Connection *) param_2, gWiFiMatching->mConnectionCallbacks) == 0) {
        func_ov000_021a1a38(6, -80410);
        return;
    }
    func_ov000_021a1ac0();
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
    *q = param_2;
    gWiFiMatching->mLastParticipantPos++;
    e->mUnk_00 = i;
    e->mUnk_01 = gWiFiMatching->mParticipantIndices[gWiFiMatching->mLastParticipantPos - 1];
    e->mUnk_02 = 0;
    e->mUnk_04 = 0;
    func_ov000_021988a4(param_2, e);
    func_ov000_0219f544(2);
}

// Slot 0 of the record (Gt2SetResultAndCallResultCallback, code_02197e58.c:126): result of a Gt2 connect, handled
// only while the matching object is in mState 7 or 12; result 5 is ignored, 6 retries the connect up to 5 times
// (mUnk_0c counter), 2 goes to func_ov000_0219f9bc and other errors to func_ov000_0219e3e4, 0 appends the joining peer
// (mLastParticipantPos++) and goes on in func_ov000_0219f544. Weak: handles the matching connects only; the result
// numbers have no library name here.
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
            p->mUnk_0c++;
            p = gWiFiMatching;
            if (p->mUnk_0c > 5) {
                p->mUnk_0c = 0;
                func_ov000_0219f9bc(gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mLastParticipantPos + 1]);
                return;
            }
            StringFormatBounded(v1, 12, data_ov000_021b40b8, p->mUnk_1e8);
            p = gWiFiMatching;
            if (func_ov000_0219e3e4(func_ov000_02198968(
                    *gWiFiMatching->mConnectionSocket, NULL,
                    Gt2FormatAddress(p->mUnk_1f8[p->mUnk_14],
                                     ((const WiFiMatching *) p)->mUnk_278[((const WiFiMatching *) p)->mUnk_14], 0),
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
        func_ov000_0219e3e4(param_2);
        return;
    }
    i = func_ov000_0219b998();
    if (i == -1) {
        func_ov000_021a1a38(6, -87100);
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

void func_ov000_021a1ae0(GpConnection *param_1, u32 param_2, const char *param_3) {
    u32 v1[33];
    char v2[16];
    const char **e;
    s32 i;
    u32 *q;
    e = NULL;
    i = 0;
    q = v1;
    do {
        if (func_ov000_021a0958(v2, param_3 + 1, i) == -1) {
            break;
        }
        *q = strtoul(v2, e, 10);
        q++;
        i++;
    } while (i < 0x80);
    func_ov000_021a01dc(param_3[0], param_2, 0, 0, v1, i);
}

void func_ov000_021a1ac0(void) {
    gWiFiMatching->mUnk_3b4 = 0xff;
    gWiFiMatching->mUnk_3b5 = 0;
}

void func_ov000_021a1a38(s32 d, s32 e) {
    WiFiMatching *p;
    u32 a;
    u32 b;
    u32 c;
    if (gWiFiMatching != NULL && d != 0) {
        func_ov000_0219f0f4();
        func_ov000_0219c384(d, e);
        func_ov000_0219d558(0, data_ov000_021b4114, NULL);
        p = gWiFiMatching;
        a = p->mMode == 2 ? 1 : 0;
        c = gWiFiMatching->mUnk_1f4;
        b = c == 0 ? 1 : 0;
        gWiFiMatching->mResultCallback(d, 0, b, a, FindBuddyEntryIndex(c), p->mResultCallbackArg);
        func_ov000_021a104c();
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

void func_ov000_021a18e0(s32 a, s32 b, u8 *c) {
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
                gWiFiMatching->mParticipantProfileIds[i] = gWiFiMatching->mUnk_1e8;
                p = gWiFiMatching;
                if (p->mMode == 0 || p->mMode == 1) {
                    p = gWiFiMatching;
                    p->mUnk_16 = p->mLastParticipantPos;
                }
                gWiFiMatching->mState = 9;
            }
            func_ov000_0219ef68(a, 3);
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
                v = func_ov000_0219e8fc(0);
                if (gWiFiMatching->mUnk_1c8 == v) {
                    for (i = 1; i <= gWiFiMatching->mLastParticipantPos; i++) {
                        func_ov000_0219ef68(gWiFiMatching->mParticipantIndices[i], 4);
                    }
                    gWiFiMatching->mState = 17;
                }
            } else {
                func_ov000_0219ef68(a, 4);
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
        func_ov000_021a1a38(a, b - 80000);
        return 1;
    }
    p->mParticipantIndices[0] = 0;
    p = gWiFiMatching;
    if (p->mUnk_1a1 == 1 || p->mUnk_1a0 == 1 || p->mUnk_1a0 == 2) {
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
        func_ov000_021a1a38(6, -80430);
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

u32 func_ov000_021a1754(int a, int b) {
    int v1;
    int v2;
    v2 = *(s32 *) &gWiFiMatching;
    if (0 == v2) {
        return 0;
    }
    v1 = 0;
    if (0 < b) {
        do {
            if (a == *(s32 *) (v2 + 0xf4)) {
                func_ov000_021a1620(v1, b);
                return 1;
            }
            v2 = v2 + 4;
            v1 = v1 + 1;
        } while (v1 < b);
    }
    return 0;
}

u32 func_ov000_021a1620(s32 b, s32 c) {
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
    v1 = p->mParticipantProfileIds[b];
    m = &p->mParticipantMask;
    *m = *m & ~(1 << p->mParticipantIndices[b]);
    func_ov000_021a15b0();
    if (b < c - 1) {
        i = 0;
        n = c - b;
        if (n > 0) {
            do {
                s32 a = b + i;
                gWiFiMatching->mUnk_24[a] = gWiFiMatching->mUnk_24[a + 1];
                gWiFiMatching->mUnk_a4[a] = gWiFiMatching->mUnk_a4[a + 1];
                gWiFiMatching->mParticipantProfileIds[a] = gWiFiMatching->mParticipantProfileIds[a + 1];
                gWiFiMatching->mUnk_1f8[a] = gWiFiMatching->mUnk_1f8[a + 1];
                gWiFiMatching->mUnk_278[a] = gWiFiMatching->mUnk_278[a + 1];
                gWiFiMatching->mParticipantIndices[a] = gWiFiMatching->mParticipantIndices[a + 1];
                i++;
            } while (i < n);
        }
    }
    if (c > 0) {
        k = c - 1;
        gWiFiMatching->mUnk_24[k] = 0;
        gWiFiMatching->mUnk_a4[k] = 0;
        gWiFiMatching->mParticipantProfileIds[k] = 0;
        gWiFiMatching->mUnk_1f8[k] = 0;
        gWiFiMatching->mUnk_278[k] = 0;
        gWiFiMatching->mParticipantIndices[k] = 0;
    }
    return v1;
}

u8 func_ov000_021a160c(void) {
    if (gWiFiMatching != NULL) {
        return gWiFiMatching->mLastParticipantPos;
    }
    return 0;
}

u8 func_ov000_021a15f8(void) {
    if (gWiFiMatching != NULL) {
        return gWiFiMatching->mUnk_0e;
    }
    return 0;
}

void func_ov000_021a15b0(void) {
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
        p->mUnk_0e = 0;
    } else {
        p->mUnk_0e = n;
    }
}

u32 func_ov000_021a158c(void **output) {
    if (gWiFiMatching == NULL) {
        return 0;
    }
    *output = gWiFiMatching->mParticipantIndices;
    return gWiFiMatching->mLastParticipantPos + 1;
}

u32 func_ov000_021a1514(void **a) {
    s32 i;
    u8 *c;
    u8 *q;
    WiFiMatching *p;
    u8 b;
    if (gWiFiMatching == NULL) {
        return 0;
    }
    MemFill(data_ov000_021b5678, 0, 0x20);
    i = 0;
    c = (u8 *) gWiFiMatching;
    if (i <= ((WiFiMatching *) c)->mUnk_0e) {
        q = data_ov000_021b5678;
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
        } while (i <= p->mUnk_0e);
    }
    *a = data_ov000_021b5678;
    return gWiFiMatching->mUnk_0e + 1;
}

u32 func_ov000_021a1488(void) {
    char name[12];
    u8 buffer[32];
    if (gWiFiMatching->mMode != 2) {
        return 0;
    }
    StringFormatBounded(name, 0xc, data_ov000_021b40b8, gWiFiMatching->mUnk_16 + 1);
    func_ov000_021a363c(data_ov000_021b41a8, name, buffer, 0x2f);
    StringFormatBounded(name, 0xc, data_ov000_021b40b8, gWiFiMatching->mLastParticipantPos + 1);
    func_ov000_021a360c(data_ov000_021b41ac, name, buffer, 0x2f);
    StringFormatBounded(name, 0xc, data_ov000_021b40b8, 3);
    func_ov000_021a360c(data_ov000_021b4118, name, buffer, 0x2f);
    return func_ov000_0219d558(6, buffer, NULL);
}

void func_ov000_021a1430(void) {
    gWiFiMatching = NULL;
    if (data_ov000_021b5674 != NULL) {
        func_ov000_021a3704(4, (u32) data_ov000_021b5674, 0);
        data_ov000_021b5674 = NULL;
    }
    func_ov000_0219ea88();
    if (data_ov000_021b5670 != NULL) {
        func_ov000_021a3704(4, (u32) data_ov000_021b5670, 0);
        data_ov000_021b5670 = NULL;
    }
    data_ov000_021b5668.mUnk_00 = 0;
    data_ov000_021b5668.mUnk_01 = 0;
}

u32 func_ov000_021a141c(void) {
    if (gWiFiMatching == NULL) {
        return 1;
    }
    return 0;
}

void func_ov000_021a1140(s32 a) {
    vu16 h;
    vu16 g;

    gWiFiMatching->mUnk_0c = 0;
    gWiFiMatching->mUnk_174[0] = 0;
    gWiFiMatching->mUnk_176 = func_ov000_021a3448(0x10000);
    gWiFiMatching->mUnk_178 = 0;
    gWiFiMatching->mUnk_17c = 0;
    gWiFiMatching->mUnk_184 = 0;
    gWiFiMatching->mUnk_19c = 0;
    gWiFiMatching->mUnk_1a1 = 0;
    gWiFiMatching->mUnk_1a2 = 0;
    gWiFiMatching->mUnk_1a3[0] = 0;
    gWiFiMatching->mUnk_1a3[1] = 0;
    gWiFiMatching->mUnk_19f = 0;
    gWiFiMatching->mUnk_1a0 = 0;
    gWiFiMatching->mUnk_1a8 = 0;
    gWiFiMatching->mUnk_1aa = 0;
    gWiFiMatching->mUnk_1ac = 0;
    gWiFiMatching->mUnk_1d0 = 0;
    gWiFiMatching->mUnk_1e0 = 0;
    func_0214d018_inline(&gWiFiMatching->mUnk_3b4, 0x98);
    if (a == 2) {
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
        gWiFiMatching->mUnk_0e = 0;
        gWiFiMatching->mUnk_14 = 0;
        gWiFiMatching->mUnk_17 = 0;
        gWiFiMatching->mUnk_20 = 0;
        gWiFiMatching->mUnk_e8 = 0;
        gWiFiMatching->mUnk_19d = 0;
        gWiFiMatching->mUnk_1a6 = 0;
        gWiFiMatching->mUnk_1b0 = 0;
        gWiFiMatching->mUnk_1b4 = 0;
        gWiFiMatching->mUnk_1bc = 0;
        gWiFiMatching->mUnk_1c0 = 0;
        gWiFiMatching->mUnk_1c8 = 0;
        gWiFiMatching->mUnk_1ec = 0;
        gWiFiMatching->mUnk_1f0 = 0;
        gWiFiMatching->mParticipantMask = 0;
        func_0214d018_inline(gWiFiMatching->mUnk_24, 0x80);
        h = 0;
        MemFillHalfwords(h, gWiFiMatching->mUnk_a4, 0x40);
        func_0214d018_inline(gWiFiMatching->mParticipantProfileIds, 0x80);
        func_0214d018_inline(gWiFiMatching->mUnk_18c, 0xc);
        func_0214d018_inline(gWiFiMatching->mUnk_1f8, 0x80);
        g = 0;
        MemFillHalfwords(g, gWiFiMatching->mUnk_278, 0x40);
        MemFill(gWiFiMatching->mParticipantIndices, 0, 0x20);
        func_0214d018_inline(gWiFiMatching->mUnk_330, 0x84);
        if (a == 1) {
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

// (Re)configures the search for a start: resets (func_ov000_021a1140), stores the mode (mMode), the second value
// (mUnk_16) and the result callback pair, clears two per-search entries and registers the five query-report keys 0x32
// to 0x36 (func_ov000_021a4b84); called again for each new search by both starts (through casts, no C prototype).
void SetupMatching(u8 a, u8 b, UnkFunc *c, u32 d) {
    WiFiMatching **v1;
    func_ov000_021a1140(0);
    v1 = &gWiFiMatching;
    gWiFiMatching->mMode = a;
    (*v1)->mUnk_16 = b;
    (*v1)->mResultCallback = c;
    (*v1)->mResultCallbackArg = d;
    (*v1)->mUnk_174[1] = 0;
    (*v1)->mParticipantIndices[0] = 0;
    func_ov000_021a4b84(0x32, data_ov000_021b40c4);
    func_ov000_021a4b84(0x33, data_ov000_021b40f0);
    func_ov000_021a4b84(0x34, data_ov000_021b40fc);
    func_ov000_021a4b84(0x35, data_ov000_021b4108);
    func_ov000_021a4b84(0x36, data_ov000_021b40cc);
}

void func_ov000_021a104c(void) {
    if (gWiFiMatching != NULL) {
        if (gWiFiMatching->mUnk_e4 != NULL) {
            func_ov000_0218b64c(gWiFiMatching->mUnk_e4);
            gWiFiMatching->mUnk_e4 = NULL;
        }
        func_ov000_0219b110();
        gWiFiMatching->mState = 0;
        if (data_ov000_021b5674 != NULL) {
            func_ov000_021a3704(4, (u32) data_ov000_021b5674, 0);
            data_ov000_021b5674 = NULL;
        }
        func_ov000_0219ea88();
        gWiFiMatching->mUnk_18 = 1;
    }
}

u32 func_ov000_021a0f20(u32 a) {
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
        e = data_ov000_021b5698[0];
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
                func_ov000_021a0ed8(v1, gWiFiMatching->mUnk_1e8, gWiFiMatching->mUnk_16, gWiFiMatching->mMode);
                if (data_ov000_021b5674 != NULL) {
                    StringFormatBounded(v1, 0x100, data_ov000_021b4194, v1, data_ov000_021b5674);
                }
                break;
            }
        case 2:
        case 4:
        case 5:
            StringFormatBounded(v1, 0x100, data_ov000_021b41a0, data_ov000_021b40c4, a);
            gWiFiMatching->mUnk_1ec = a;
            break;
    }
    func_ov000_0218b48c(gWiFiMatching->mUnk_e4);
    for (i = 0; i < 5; i++) {
        r = func_ov000_0218b570(gWiFiMatching->mUnk_e4, 1, 0, (u32) v2, n, (u32) v1, 0x10);
        if (r == 0 || r != 2) {
            break;
        }
    }
    return r;
}

s32 func_ov000_021a0ed8(char *a, s32 b, s32 c, s32 d) {
    return StringFormatBounded(a, 0x100, data_ov000_021b413c, data_ov000_021b4108, 3, data_ov000_021b40c4, b, c, c,
                               data_ov000_021b40f0, d, data_ov000_021b40fc, data_ov000_021b40c4);
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
        b = (gWiFiMatching->mUnk_1e8 & 0xffff) | (gWiFiMatching->mUnk_176 << 16);
        if (func_ov000_0218b248(c) != 0) {
            if (func_ov000_0218b27c((u32 *) c) == func_ov000_0218b458(gWiFiMatching->mUnk_e4)) {
                gWiFiMatching->mUnk_1f8[k] = func_ov000_0218b244(c);
                gWiFiMatching->mUnk_278[k] = func_ov000_0218b228(c);
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
                gWiFiMatching->mUnk_1f8[k] = func_ov000_0218b27c((u32 *) c);
                gWiFiMatching->mUnk_278[k] = func_ov000_0218b260(c);
                x = FALSE;
            }
        }
        if (x != FALSE) {
            gWiFiMatching->mUnk_176 = func_ov000_021a3448(0x10000);
            gWiFiMatching->mUnk_194 = b;
        } else {
            t[0] = func_ov000_021a8ed4();
            t[1] = GetSocketPort(*gWiFiMatching->mConnectionSocket);
            r = func_ov000_021a0ae8(6, gWiFiMatching->mParticipantProfileIds[k], func_ov000_0218b27c((u32 *) c),
                                    func_ov000_0218b260(c), t, 2);
            gWiFiMatching->mUnk_3b5 = 0;
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
        gWiFiMatching->mUnk_184 = 0;
    }
    return v2;
}

u32 func_ov000_021a0c30(Unk021a0c30 *a) {
    u32 r;
    s32 i;

    if (a->mUnk_00 == 0) {
        if (func_ov000_0219e594(func_ov000_0218b4f8(gWiFiMatching->mUnk_e4, Gt2FormatAddress(a->mUnk_04, 0, 0),
                                                    a->mUnk_02, a->mUnk_08)) != 0) {
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

u32 func_ov000_021a0ae8(u32 a, u32 b, u32 c, u32 d, void *e, s32 f) {
    char v1[0x10];
    char v2[0x200];
    u32 *w;
    s32 n;
    s32 k;
    s32 j;

    n = 0;
    if (gWiFiMatching->mMode == 0 || ((gWiFiMatching->mMode == 3 || gWiFiMatching->mUnk_19e != 0) && a == 6)) {
        n = func_ov000_021a0a40(a, c, d, e, f);
    } else {
        if (e != NULL && f != 0) {
            w = e;
            n = StringFormatBounded(v2, 0x200, data_ov000_021b40b8, w[0]);
            for (k = 1; k < f; k++) {
                j = StringFormatBounded(v1, 0x10, data_ov000_021b4138, w[k]);
                MemCopy(v1, v2 + n, j);
                n += j;
            }
        }
        v2[n] = 0;
        n = func_ov000_021a09d0(gWiFiMatching->mGpConnection, a, b, v2);
    }
    if (a == 2 || a == 6 || (u8) (a + 0xf8) <= 1) {
        gWiFiMatching->mUnk_3b4 = a;
        gWiFiMatching->mUnk_3b6 = d;
        gWiFiMatching->mUnk_3b8 = c;
        gWiFiMatching->mUnk_43c = b;
        gWiFiMatching->mUnk_440 = f;
        gWiFiMatching->mUnk_444 = func_ov000_021a350c();
        if (e != NULL && f != 0) {
            MemCopyWords(e, gWiFiMatching->mUnk_3bc, f * 4);
        }
    }
    return n;
}

u32 func_ov000_021a0a40(u32 a, u32 b, u32 c, u32 *d, u32 e) {
    u32 v1[0x21];
    Unk021a0a40 s;
    u32 r;
    s32 i;

    if (d != NULL && e != 0) {
        MemCopyWords(d, v1, e * 4);
    } else {
        e = 0;
    }
    *(Unk021b40bc *) &s = *(Unk021b40bc *) data_ov000_021b40bc;
    s.mUnk_04 = 3;
    s.mUnk_08 = a;
    s.mUnk_09 = e * 4;
    s.mUnk_0a = gWiFiMatching->mUnk_1a;
    s.mUnk_0c = gWiFiMatching->mUnk_1c;
    s.mUnk_10 = gWiFiMatching->mUnk_1e8;
    for (i = 0; i < 5; i++) {
        r = func_ov000_0218b530(gWiFiMatching->mUnk_e4, Gt2FormatAddress(b, 0, 0), c, (u8 *) &s, s.mUnk_09 + 0x14);
        if (r == 0 || r != 2) {
            break;
        }
    }
    return r;
}

s32 func_ov000_021a09d0(struct GpConnection *a, u32 b, u32 c, const char *d) {
    char v1[0x200];
    char *e;
    char *g;
    s32 n;
    s32 i;

    i = StringFormatBounded(v1, 0x200, data_ov000_021b4124, data_ov000_021b412c, 3, data_ov000_021b4134);
    v1[i] = b;
    g = v1 + 1;
    e = g + i;
    g[i] = 0;
    if (d != NULL) {
        n = strlen(d);
        MemCopy(d, e, n);
        e[n] = 0;
    }
    return GpSendMessage(a, c, v1);
}

s32 func_ov000_021a0958(char *a, const char *b, s32 c) {
    const char *e;
    const char *p;
    s32 i;
    s32 n;

    e = strchr(b, 0);
    for (i = 0; i < c; i++) {
        p = strchr(b, 0x2f);
        if (p == NULL) {
            return -1;
        }
        b = p + 1;
    }
    p = strchr(b, 0x2f);
    if (p == NULL) {
        p = e;
    }
    if (b == p) {
        return -1;
    }
    n = p - b;
    MemCopy(b, a, n);
    a[n] = 0;
    return n;
}

s32 func_ov000_021a01dc(s32 a, u32 b, u32 c, u16 d, u32 *e, s32 f) {
    u32 *w;
    u32 z;
    Unk021a01dc s;
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
    switch (a) {
        case 1:
        case 11:
            t = func_ov000_021a0064(b, e[0], a == 11 ? 1 : 0);
            if (t == 2) {
                if (gWiFiMatching->mMode != 0) {
                    c = e[1];
                    d = (u16) e[2];
                }
                if (func_ov000_0219fee4(func_ov000_0219ff54(b, c, d)) != 0) {
                    return 0;
                }
                p = gWiFiMatching;
                if (p->mMode == 2 && p->mUnk_454 != NULL) {
                    gWiFiMatching->mUnk_454(FindBuddyEntryIndex(b), p->mUnk_458);
                }
                g[0] = gWiFiMatching->mUnk_14;
                for (i = 1; i <= gWiFiMatching->mUnk_14; i++) {
                    g[i] = gWiFiMatching->mParticipantProfileIds[i];
                }
                p = gWiFiMatching;
                g[i++] = (u32) p->mUnk_1c;
                g[i++] = p->mUnk_1a;
                p->mState = 11;
            }
            if (t == 0xff) {
                break;
            }
            if (func_ov000_0219fee4(func_ov000_021a0ae8(t, b, c, d, g, i)) == 0) {
                break;
            }
            return 0;
        case 2:
            if (o->mState != 4) {
                break;
            }
            if (b != o->mUnk_1ec) {
                break;
            }
            o->mUnk_1f0 = 0;
            gWiFiMatching->mUnk_19f = 0;
            gWiFiMatching->mUnk_1bc = 0;
            gWiFiMatching->mUnk_1b0 = 0;
            gWiFiMatching->mUnk_24[0] = (e + e[0])[1];
            gWiFiMatching->mUnk_a4[0] = (e + e[0])[2];
            gWiFiMatching->mUnk_1ac = (e + e[0])[1];
            gWiFiMatching->mUnk_1aa = (e + e[0])[2];
            if (gWiFiMatching->mMode == 1) {
                if (func_ov000_0219f4c4(e + 1, e[0]) != 0) {
                    if (gWiFiMatching->mLastParticipantPos != 0) {
                        func_ov000_0219ff0c(b, e);
                    }
                } else {
                    if (func_ov000_0219fee4(func_ov000_0219fb14(b)) != 0) {
                        return 0;
                    }
                    if (func_ov000_0219fee4(func_ov000_0219fbec(0, 0)) == 0) {
                        break;
                    }
                    return 0;
                }
            }
            if (gWiFiMatching->mMode == 0) {
                if (gWiFiMatching->mLastParticipantPos != 0) {
                    func_ov000_0219ff0c(b, e);
                    if (func_ov000_0219fee4(func_ov000_0219f8b0()) != 0) {
                        return 0;
                    }
                }
                gWiFiMatching->mState = 6;
                if (func_ov000_0219e4a0(func_ov000_021a0cac(0, 0, func_ov000_0218b480(gWiFiMatching->mUnk_e4, 0))) ==
                    0) {
                    break;
                }
                return 0;
            } else {
                gWiFiMatching->mState = 5;
                if (func_ov000_0219e594(func_ov000_021a0f20(b)) == 0) {
                    break;
                }
                return 0;
            }
        case 3:
            if (o->mState != 4) {
                break;
            }
            if (b != o->mUnk_1ec) {
                break;
            }
            return func_ov000_0219fb48();
        case 4:
            if (o->mState != 4) {
                break;
            }
            if (b != o->mUnk_1ec) {
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
            if (o->mUnk_17 == 0) {
                break;
            }
            if (b != o->mUnk_20) {
                break;
            }
            if (o->mMode == 2 && o->mLastParticipantPos == 1 && o->mParticipantProfileIds[1] == b) {
                func_ov000_021988e8(*o->mConnectionSocket);
            }
            if (func_ov000_0219f9bc(b) == 0) {
                return 0;
            }
            break;
        case 6:
            x = e[0];
            y = e[1];
            if (o->mState == 1) {
                o->mState = 6;
            } else {
                if (o->mState != 6 && o->mState != 11) {
                    break;
                }
                if (b != o->mUnk_20) {
                    break;
                }
            }
            gWiFiMatching->mUnk_3b4 = 0xff;
            p = gWiFiMatching;
            n = &p->mParticipantProfileIds[p->mLastParticipantPos + 1];
            if (b != *n) {
                *n = b;
            }
            s.mUnk_04 = x;
            s.mUnk_02 = ((y >> 8) & 0xff) | ((y << 8) & 0xff00);
            gWiFiMatching->mUnk_18c[0] = 1;
            p = gWiFiMatching;
            func_ov000_0219db18(0, GetSocketDescriptor(*p->mConnectionSocket), &s, p->mUnk_18c);
            gWiFiMatching->mUnk_184 = 0;
            break;
        case 7:
            z = e[0];
            u = e[1];
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
            x = e[0];
            z = x;
            if (x == 0) {
                u = e[1];
                o->mParticipantIndices[u] = e[2];
                gWiFiMatching->mParticipantProfileIds[u] = gWiFiMatching->mUnk_1e8;
                func_ov000_0219f544(3);
                break;
            }
            u = e[1];
            v = e[2];
            w = &o->mParticipantProfileIds[u];
            if (x == *w && u == o->mLastParticipantPos - 1) {
                if (func_ov000_0219fee4(func_ov000_021a0ae8(9, b, o->mUnk_24[0], o->mUnk_a4[0], &z, 1)) == 0) {
                    break;
                }
                return 0;
            }
            *w = x;
            gWiFiMatching->mParticipantIndices[u] = v;
            gWiFiMatching->mUnk_24[u] = e[3];
            gWiFiMatching->mUnk_a4[u] = e[4];
            gWiFiMatching->mUnk_1ac = e[3];
            gWiFiMatching->mUnk_1aa = e[4];
            gWiFiMatching->mState = 5;
            if (func_ov000_0219e594(func_ov000_021a0f20(z)) != 0) {
                return 0;
            }
            gWiFiMatching->mUnk_1bc = 0;
            gWiFiMatching->mUnk_1b0 = 0;
            break;
        case 9:
            if (o->mState != 13) {
                break;
            }
            if (e[0] != o->mParticipantProfileIds[o->mUnk_19c + 1]) {
                break;
            }
            o->mUnk_19c++;
            func_ov000_0219f544(0);
            break;
        case 10:
            if (o->mMode == 0 || func_ov000_0219f4c4(e + 1, e[0]) != 0) {
                gWiFiMatching->mUnk_1f0 = e[1];
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
                if (func_ov000_0219f938(b) != 0) {
                    break;
                }
                return 0;
            }
            if (o->mMode == 3) {
                if (e[0] == 0) {
                    o->mUnk_1f4 = b;
                    func_ov000_0219f0f4();
                    func_ov000_0219f23c(0);
                } else {
                    func_ov000_0219f124(e[0]);
                }
            }
            break;
        case 13:
        case 14:
        case 15:
            if (func_ov000_0219ec44(b, a, e[0]) != FALSE) {
                break;
            }
            return 0;
        case 16:
            if (b != o->mParticipantProfileIds[0]) {
                return 1;
            }
            for (i = 0; i < f; i++) {
                t = func_ov000_0219e948(e[i], 0);
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
            if (func_ov000_0219fee4(func_ov000_021a0ae8(0x12, b, c, d, g, 1)) == 0) {
                break;
            }
            return 0;
        case 18:
            if (o->mState != 0x13) {
                break;
            }
            t = func_ov000_0219e948(b, 0);
            if (t == 0xff) {
                break;
            }
            data_ov000_021b5670->mUnk_08 |= 1 << t;
            if (e[0] != 0) {
                data_ov000_021b5670->mUnk_0c |= 1 << t;
            }
            break;
        case 19:
            func_ov000_021a1a38(10, -80000);
            return 0;
    }
    return 1;
}

s32 func_ov000_021a0064(s32 a, u32 b, s32 c) {
    s32 r;

    switch (gWiFiMatching->mMode) {
        case 1:
            if (GpIsBuddy(gWiFiMatching->mGpConnection, a) == 0) {
                r = 0xff;
                break;
            }
        case 0:
            if (b != gWiFiMatching->mMode || gWiFiMatching->mUnk_1a1 != 0 ||
                gWiFiMatching->mUnk_14 == gWiFiMatching->mUnk_16 ||
                (gWiFiMatching->mUnk_17 != 0 && gWiFiMatching->mUnk_20 == gWiFiMatching->mUnk_1e8)) {
                r = 3;
                if (gWiFiMatching->mMode == 0 && gWiFiMatching->mUnk_10->mUnk_0b4 == FALSE &&
                    gWiFiMatching->mUnk_17 != 0 && gWiFiMatching->mUnk_20 == gWiFiMatching->mUnk_1e8) {
                    func_ov000_021a4818(gWiFiMatching->mUnk_10);
                }
            } else if ((gWiFiMatching->mState != 3 && gWiFiMatching->mState != 4) ||
                       (gWiFiMatching->mUnk_1c == NULL && gWiFiMatching->mUnk_1a == 0)) {
                r = 4;
            } else if (gWiFiMatching->mUnk_1ec != 0) {
                if (gWiFiMatching->mUnk_1ec == a) {
                    if (c != 0 || ((s32) gWiFiMatching->mUnk_1e8 < a && a != gWiFiMatching->mUnk_1f0)) {
                        r = 2;
                    } else {
                        r = 0xff;
                    }
                } else if (c != 0 || ((s32) gWiFiMatching->mUnk_1e8 < a && gWiFiMatching->mUnk_1f0 == 0)) {
                    if (func_ov000_0219fee4(func_ov000_0219fb14(gWiFiMatching->mUnk_1ec)) != 0) {
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
            if (GpIsBuddy(gWiFiMatching->mGpConnection, a) == 0) {
                r = 0xff;
            } else if (b != 3 || gWiFiMatching->mUnk_14 == gWiFiMatching->mUnk_16) {
                r = 3;
            } else if (data_ov000_021b5668.mUnk_00 == 1 && data_ov000_021b5668.mUnk_01 == 1) {
                r = 0x13;
            } else if (gWiFiMatching->mState != 10 || (gWiFiMatching->mUnk_1c == NULL && gWiFiMatching->mUnk_1a == 0)) {
                r = 4;
            } else {
                r = 2;
            }
            break;
    }
    return r;
}

u32 func_ov000_0219ff54(u32 a, u32 b, u16 c) {
    u32 s[2];
    s32 i;
    u32 r;

    if (gWiFiMatching->mUnk_17 != 0 && gWiFiMatching->mUnk_20 == a) {
        return 0;
    }
    gWiFiMatching->mUnk_17 = 1;
    gWiFiMatching->mUnk_20 = a;
    gWiFiMatching->mUnk_1b0 = 0;
    gWiFiMatching->mUnk_1bc = 0;
    func_ov000_021a4818(gWiFiMatching->mUnk_10);
    gWiFiMatching->mUnk_1ec = 0;
    gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mUnk_14 + 1] = a;
    gWiFiMatching->mUnk_24[gWiFiMatching->mUnk_14 + 1] = b;
    gWiFiMatching->mUnk_a4[gWiFiMatching->mUnk_14 + 1] = c;
    gWiFiMatching->mUnk_1ac = b;
    gWiFiMatching->mUnk_1aa = c;
    gWiFiMatching->mParticipantIndices[gWiFiMatching->mUnk_14 + 1] = func_ov000_0219ea48();
    s[0] = a;
    s[1] = gWiFiMatching->mParticipantIndices[gWiFiMatching->mUnk_14 + 1];
    for (i = 1; i <= gWiFiMatching->mUnk_14; i++) {
        r = func_ov000_021a0ae8(7, gWiFiMatching->mParticipantProfileIds[i], gWiFiMatching->mUnk_24[i],
                                gWiFiMatching->mUnk_a4[i], s, 2);
        if (r != 0) {
            return r;
        }
    }
    func_ov000_0219e8b8(1);
    return 0;
}

void func_ov000_0219ff0c(u32 a, u32 *b) {
    u32 n;

    n = b[0] + 2;
    if (n > 2) {
        MemCopyWords(b + 1, &gWiFiMatching->mUnk_330[2], (n - 2) * 4);
    }
    gWiFiMatching->mUnk_330[0] = n - 1;
    gWiFiMatching->mUnk_330[1] = a;
}

u32 func_ov000_0219fee4(u32 a) {
    if (gWiFiMatching->mMode == 0) {
        return func_ov000_0219e594(a);
    }
    return func_ov000_0219e608(a);
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
        t = func_ov000_0218b480(gWiFiMatching->mUnk_e4, 0);
        gWiFiMatching->mParticipantProfileIds[0] = SbServerGetInt((SbServer *) t, data_ov000_021b40c4, 0);
        gWiFiMatching->mUnk_24[0] = func_ov000_0218b27c((u32 *) t);
        gWiFiMatching->mUnk_a4[0] = func_ov000_0218b260(t);
        gWiFiMatching->mUnk_1ec = gWiFiMatching->mParticipantProfileIds[0];
        m = 1;
    } else {
        if (gWiFiMatching->mMode == 1) {
            gWiFiMatching->mParticipantProfileIds[0] = a;
        }
        gWiFiMatching->mUnk_1ec = a;
        s[1] = (u32) gWiFiMatching->mUnk_1c;
        s[2] = gWiFiMatching->mUnk_1a;
        m = 3;
    }
    gWiFiMatching->mUnk_1bc = 6000;
    gWiFiMatching->mUnk_1c0 = OS_GetTick();
    gWiFiMatching->mUnk_1b0 = 0;
    v = gWiFiMatching->mUnk_1f0 != 0 ? 11 : 1;
    s[0] = gWiFiMatching->mMode;
    return func_ov000_021a0ae8(v, a, gWiFiMatching->mUnk_24[0], gWiFiMatching->mUnk_a4[0], s, m);
}

u32 func_ov000_0219fbec(s32 a, s32 b) {
    BOOL d;
    s32 i;
    BOOL c;
    s32 e;
    char g[8];
    s32 q;
    char x[12];
    Unk0218ec44 h;
    WiFiMatching *p;
    s32 n;
    u32 r;
    s32 k;
    s32 t;
    s32 z;

    if (b != 0) {
        i = gWiFiMatching->mUnk_19d;
    } else if (gWiFiMatching->mUnk_19d < gWiFiMatching->mUnk_32c - 1) {
        i = gWiFiMatching->mUnk_19d + 1;
    } else {
        i = 0;
    }
    c = FALSE;
    d = b == 0;
    while (1) {
        if (d != FALSE || c != FALSE) {
            gWiFiMatching->mUnk_19d++;
            if (gWiFiMatching->mUnk_19d >= gWiFiMatching->mUnk_32c) {
                gWiFiMatching->mUnk_19d = 0;
            }
        }
        if (c != FALSE && gWiFiMatching->mUnk_19d == i) {
            gWiFiMatching->mUnk_1bc = 3000;
            gWiFiMatching->mUnk_1c0 = OS_GetTick();
            gWiFiMatching->mUnk_1b0 = 0;
            return 0;
        }
        c = TRUE;
        p = gWiFiMatching;
        n = func_02152520(func_ov000_0219c9c4(), p->mUnk_2e4 + p->mUnk_2ec[p->mUnk_19d] * 12);
        if (n == 0) {
            continue;
        }
        if (n == -1) {
            continue;
        }
        if (func_02152698(gWiFiMatching->mUnk_2e4 + gWiFiMatching->mUnk_2ec[gWiFiMatching->mUnk_19d] * 12) == 0) {
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
        t = func_ov000_021a3530(data_ov000_021b4118, x, h.mUnk_008, 0x2f);
        e = func_ov000_021a3530(data_ov000_021b411c, g + 2, h.mUnk_008, 0x2f);
        z = func_ov000_021a3530(data_ov000_021b4120, g, h.mUnk_008, 0x2f);
        if (t > 0 && e > 0 && z > 0) {
            if (strtoul(x, NULL, 10) == 3) {
                if (gWiFiMatching->mUnk_16 == strtoul(g + 2, NULL, 10)) {
                    return func_ov000_0219fdc8(n, a);
                }
            }
        }
    }
}

u32 func_ov000_0219fb48(void) {
    WiFiMatching *p;

    gWiFiMatching->mUnk_1f0 = 0;
    gWiFiMatching->mUnk_1ec = 0;
    gWiFiMatching->mUnk_19f = 0;
    p = gWiFiMatching;
    p->mUnk_1c0 = OS_GetTick();
    if (p->mMode == 0) {
        p->mState = 3;
        if (func_ov000_0219e594(func_ov000_021a0f20(0)) != 0) {
            return 0;
        }
    } else if (p->mMode == 1) {
        if (func_ov000_0219fee4(func_ov000_0219fbec(0, 0)) != 0) {
            return 0;
        }
    } else if (p->mMode == 3) {
        func_ov000_021a1a38(6, -80410);
        return 0;
    }
    return 1;
}

u32 func_ov000_0219fb14(u32 a) {
    u32 result;
    result = func_ov000_021a0ae8(5, a, gWiFiMatching->mUnk_24[0], gWiFiMatching->mUnk_a4[0], NULL, 0);
    gWiFiMatching->mUnk_1ec = 0;
    return result;
}

u32 func_ov000_0219f9bc(u32 a) {
    s32 i;
    u32 b;

    if (gWiFiMatching->mUnk_17 != 0 && gWiFiMatching->mUnk_20 == gWiFiMatching->mUnk_1e8) {
        b = 0;
    } else {
        b = 1;
    }
    if (b != 0) {
        gWiFiMatching->mUnk_17 = 0;
        gWiFiMatching->mUnk_20 = 0;
        func_ov000_021a4818(gWiFiMatching->mUnk_10);
    }
    if (gWiFiMatching->mLastParticipantPos < 0x1f) {
        gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mLastParticipantPos + 1] = 0;
    }
    gWiFiMatching->mUnk_3b4 = 0xff;
    if (gWiFiMatching->mUnk_194 != 0) {
        func_ov000_0219ac50(gWiFiMatching->mUnk_194);
        gWiFiMatching->mUnk_194 = 0;
    }
    gWiFiMatching->mUnk_14 = gWiFiMatching->mLastParticipantPos;
    gWiFiMatching->mUnk_1ec = 0;
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
            func_ov000_0219f0f4();
        }
        func_ov000_021a1a38(6, -80430);
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
        b = func_ov000_0219fb48();
    }
    return b;
}

u32 func_ov000_0219f8b0(void) {
    s32 i;
    u32 r;

    for (i = 1; i <= gWiFiMatching->mLastParticipantPos; i++) {
        r = func_ov000_021a0ae8(10, gWiFiMatching->mParticipantProfileIds[i], gWiFiMatching->mUnk_24[i],
                                gWiFiMatching->mUnk_a4[i], gWiFiMatching->mUnk_330, gWiFiMatching->mUnk_330[0] + 1);
        if (r != 0) {
            return r;
        }
    }
    gWiFiMatching->mUnk_17 = 0;
    gWiFiMatching->mUnk_20 = 0;
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
                v[3] = p->mUnk_24[p->mUnk_19c + 1];
                v[4] = p->mUnk_a4[p->mUnk_19c + 1];
                w = 5;
            } else {
                p->mUnk_17 = 0;
                gWiFiMatching->mUnk_20 = 0;
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
                        p->mParticipantProfileIds[0] = p->mUnk_1e8;
                    }
                    gWiFiMatching->mState = 16;
                    gWiFiMatching->mUnk_1c8 = 0;
                    for (n = 1; n <= gWiFiMatching->mLastParticipantPos; n++) {
                        func_ov000_0219ef68(gWiFiMatching->mParticipantIndices[n], 2);
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
            if (func_ov000_0219fee4(
                    func_ov000_021a0ae8(8, p->mParticipantProfileIds[n], p->mUnk_24[n], p->mUnk_a4[n], v, w)) != 0) {
                return;
            }
            gWiFiMatching->mUnk_3b5 = 0;
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
                p->mUnk_17 = 1;
                gWiFiMatching->mUnk_20 = gWiFiMatching->mUnk_1e8;
            }
            p = gWiFiMatching;
            if (p->mLastParticipantPos > 1) {
                if (func_ov000_0219fee4(
                        func_ov000_021a0ae8(9, p->mParticipantProfileIds[0], p->mUnk_24[0], p->mUnk_a4[0],
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
                func_ov000_0219d558(2, data_ov000_021b4114, (void *) f);
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
                func_ov000_021a104c();
            } else {
                if (p->mUnk_e4 != NULL) {
                    func_ov000_0218b64c(p->mUnk_e4);
                    gWiFiMatching->mUnk_e4 = NULL;
                }
                func_ov000_0219b110();
                p = gWiFiMatching;
                if (p->mMode == 2) {
                    if (func_ov000_0219e608(func_ov000_021a1488()) != 0) {
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
            gWiFiMatching->mUnk_1a1 = 0;
            break;
    }
    if (f != 0) {
        p = gWiFiMatching;
        if (p->mMode != 3) {
            func_ov000_0218b48c(p->mUnk_e4);
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
    p->mUnk_1a1 = 1;
    p = gWiFiMatching;
    s = p->mMode;
    if (s == 3) {
        p->mUnk_1a1 = 1;
        p = gWiFiMatching;
        if (p->mLastParticipantPos != 0) {
            func_ov000_021988e8(*p->mConnectionSocket);
        } else {
            if (func_ov000_0219fee4(func_ov000_0219fb14(p->mParticipantProfileIds[0])) != 0) {
                return;
            }
        }
        func_ov000_0219f344();
        return;
    }
    if (p->mState == 4 || p->mState == 5 || p->mState == 6 || p->mState == 7 || p->mState == 11 || p->mState == 12) {
        if (p->mUnk_1ec != 0) {
            if (func_ov000_0219fee4(func_ov000_0219fb14(p->mParticipantProfileIds[0])) != 0) {
                return;
            }
        }
        if (func_ov000_0219fee4(func_ov000_0219f2e4()) != 0) {
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
        p->mUnk_1a1 = 1;
        func_ov000_021988e8(*gWiFiMatching->mConnectionSocket);
    }
    func_ov000_0219f344();
}

void func_ov000_0219f344(void) {
    WiFiMatching *p;
    BOOL a;
    BOOL b;
    u32 c;
    if (func_ov000_0219e608(func_ov000_0219d558(1, data_ov000_021b4114, NULL)) == 0) {
        func_ov000_021a104c();
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
        gWiFiMatching->mUnk_1a1 = 0;
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
    if (p->mUnk_17 != 0 && p->mUnk_20 != 0 && p->mUnk_20 != p->mUnk_1e8) {
        n = p->mLastParticipantPos + 1;
        r = func_ov000_021a0ae8(12, p->mUnk_20, p->mUnk_24[n], p->mUnk_a4[n], &v, 1);
        gWiFiMatching->mUnk_17 = 0;
        gWiFiMatching->mUnk_20 = 0;
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
    func_ov000_021a1140(a);
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
            if (func_ov000_0219e594(func_ov000_021a0f20(0)) != 0) {
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
        func_ov000_0219f0f4();
        func_ov000_0219f23c(1);
    }
}

u32 func_ov000_0219f184(void) {
    u32 r;
    WiFiMatching *p;
    gWiFiMatching->mUnk_17 = 0;
    gWiFiMatching->mUnk_20 = 0;
    gWiFiMatching->mUnk_1a0 = 0;
    p = gWiFiMatching;
    if (p->mUnk_1f0 != 0) {
        if (p->mMode == 0) {
            p->mState = 3;
            r = func_ov000_021a0f20(0);
            if (func_ov000_0219e594(r) != 0) {
                return r;
            }
        } else if (p->mMode == 1) {
            p->mState = 4;
            r = func_ov000_0219fdc8(gWiFiMatching->mUnk_1f0, 0);
            if (func_ov000_0219fee4(r) != 0) {
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
    func_ov000_021a1754(a, gWiFiMatching->mLastParticipantPos + 1);
    return 0;
}

void func_ov000_0219f0f4(void) {
    gWiFiMatching->mUnk_1a0 = 2;
    func_ov000_021988e8(*gWiFiMatching->mConnectionSocket);
    gWiFiMatching->mUnk_1a0 = 0;
}

u32 func_ov000_0219f00c(u32 a) {
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
        if ((a & b) != 0) {
            e[k] = p->mParticipantProfileIds[n];
            k++;
        } else {
            d[m] = p->mParticipantProfileIds[n];
            m++;
        }
    }
    for (i = 0; i < k; i++) {
        if (func_ov000_0219fee4(func_ov000_021a0ae8(0x10, e[i], 0, 0, d, m)) != 0) {
            return 0;
        }
    }
    gWiFiMatching->mUnk_1a0 = 2;
    for (i = 0; i < m; i++) {
        s32 t;
        t = func_ov000_0219e948(d[i], 0);
        if (t != 0xff) {
            func_ov000_0219bbac(t);
        }
    }
    gWiFiMatching->mUnk_1a0 = 0;
    return 1;
}

void func_ov000_0219ef68(s32 a, u16 b) {
    u8 n;
    u8 v1[3];
    volatile WiFiMatching *p; // fields are read again on each use
    switch (b) {
        case 2:
            p = gWiFiMatching;
            if (a == p->mParticipantIndices[p->mLastParticipantPos]) {
                v1[0] = 1;
            } else {
                v1[0] = 0;
            }
            for (n = 1; n <= p->mLastParticipantPos; n++) {
                if (a == p->mParticipantIndices[n]) {
                    v1[1] = n;
                    v1[2] = a;
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
    StartPeerMessageSend(b, a, v1, 4);
    gWiFiMatching->mUnk_1d0 = func_ov000_021a350c();
}

u32 func_ov000_0219ee14(void) {
    WiFiMatching *p;
    u64 t;
    s32 n;
    u8 b;
    p = gWiFiMatching;
    if (p->mState == 9 || p->mState == 16 || p->mState == 17) {
        t = func_ov000_021a350c() - p->mUnk_1d0;
    } else {
        return 1;
    }
    switch (p->mState) {
        case 9:
            if (t > 6000) {
                func_ov000_0219ef68(p->mParticipantIndices[0], 3);
            }
            break;
        case 16:
            if (t > 6000) {
                p->mUnk_1a3[0]++;
                p = gWiFiMatching;
                if (p->mUnk_1a3[0] > 5) {
                    if (p->mMode == 0 || p->mMode == 1) {
                        func_ov000_0219f0f4();
                        func_ov000_0219f23c(1);
                        break;
                    }
                    if (func_ov000_0219f00c(p->mUnk_1c8) == 0) {
                        return 0;
                    }
                    p = gWiFiMatching;
                    if (p->mLastParticipantPos != 0) {
                        p->mUnk_1a3[0] = 0;
                        gWiFiMatching->mUnk_1d0 = func_ov000_021a350c();
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
                            func_ov000_0219ef68(b, 2);
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
    if (func_ov000_0219fee4(func_ov000_021a0ae8(b, a, 0, 0, &v, c)) != 0) {
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
                r = func_ov000_0219e948(a, 0);
                if (r != 0xff) {
                    gWiFiMatching->mUnk_1cc |= 1 << r;
                }
                m = func_ov000_0219e8fc(1);
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
                    if (func_ov000_0219f00c(p->mUnk_1cc) == 0) {
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

u8 func_ov000_0219eac8(void) {
    u8 i = 0;
    do {
        if (data_ov000_021b5698[i][0] == 0) {
            return i + 100;
        }
        i++;
    } while (i < 154);
    return 0;
}

void func_ov000_0219ea88(void) {
    s32 i;
    volatile u32 v; // read back from its stack offset
    u8(*e)[12];
    i = 0;
    e = data_ov000_021b5698;
    for (; i < 0x9a; i++) {
        if (*(u32 *) &e[0][4] != 0) {
            func_ov000_021a3704(4, *(u32 *) &e[0][4], 0);
        }
        e++;
    }
    v = 0;
    MemFillWords(v, data_ov000_021b5698, 0x738);
}

u8 func_ov000_0219ea48(void) {
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

s32 func_ov000_0219e994(u32 a) {
    if (SbServerGetInt((SbServer *) a, data_ov000_021b40d8, -1) == -1) {
        return 0;
    }
    if (SbServerGetInt((SbServer *) a, data_ov000_021b40e4, -1) == -1) {
        return 0;
    }
    if (SbServerGetInt((SbServer *) a, data_ov000_021b40f0, -1) == -1) {
        return 0;
    }
    if (SbServerGetInt((SbServer *) a, data_ov000_021b40fc, -1) == -1 &&
        SbServerGetInt((SbServer *) a, data_ov000_021b40fc, 0) == 0) {
        return 0;
    }
    if (SbServerGetInt((SbServer *) a, data_ov000_021b4108, -1) == -1) {
        return 0;
    }
    return SbServerGetInt((SbServer *) a, data_ov000_021b40c4, 0);
}

s32 func_ov000_0219e948(u32 a, s32 b) {
    if (b == 0) {
        b = 1;
    } else {
        b = 0;
    }
    for (; b <= gWiFiMatching->mLastParticipantPos; b++) {
        if (a == gWiFiMatching->mParticipantProfileIds[b]) {
            return gWiFiMatching->mParticipantIndices[b];
        }
    }
    return 0xff;
}

u32 func_ov000_0219e8fc(s32 a) {
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
        a = func_ov000_0219e8fc(0);
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
            func_ov000_0219f0f4();
            func_ov000_0219f23c(1);
            return;
        }
        for (n = 1; n <= (p = gWiFiMatching)->mLastParticipantPos; n++) {
            if ((data_ov000_021b5670->mUnk_08 & (1 << p->mParticipantIndices[n])) == 0) {
                p = gWiFiMatching;
                if (func_ov000_0219fee4(func_ov000_021a0ae8(0x11, p->mParticipantProfileIds[n], p->mUnk_24[n],
                                                            p->mUnk_a4[n], NULL, 0)) != 0) {
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
        if (p->mUnk_1ec != 0) {
            if (func_ov000_0219fee4(func_ov000_0219fb14(p->mUnk_1ec)) != 0) {
                return;
            }
        }
        p = gWiFiMatching;
        p->mState = 0x13;
        for (n = 1; n <= gWiFiMatching->mLastParticipantPos; n++) {
            p = gWiFiMatching;
            if (func_ov000_0219fee4(func_ov000_021a0ae8(0x11, p->mParticipantProfileIds[n], p->mUnk_24[n],
                                                        p->mUnk_a4[n], NULL, 0)) != 0) {
                return;
            }
        }
        q = data_ov000_021b5670;
        q->mUnk_18 = func_ov000_021a350c();
        q->mUnk_02 = 1;
    }
}

u32 func_ov000_0219e608(u32 a) {
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
    func_ov000_021a1a38(b, c - 0x13c68);
    return a;
}

u32 func_ov000_0219e594(u32 a) {
    s32 b;
    s32 c;
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
    func_ov000_021a1a38(b, c - 0x14c08);
    return a;
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
            func_ov000_021a1a38(b, c - 0x14820);
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
    func_ov000_021a1a38(b, c - 0x14ff0);
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
        func_ov000_021a1a38(b, c - 0x14ff0);
    }
    return a;
}

u32 func_ov000_0219e3e4(u32 a) {
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
        case 5:
            b = 0;
            c = 0;
            a = 0;
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
        func_ov000_021a1a38(b, c - 0x153d8);
    }
    return a;
}

void func_ov000_0219e138(Unk0218b668 *a, s32 b, s32 c) {
    s32 d;
    u32 e;
    WiFiMatching *f;
    switch (b) {
        case 0:
            func_ov000_0219e134(c);
            return;
        case 4:
            d = 0;
            if ((s32) func_ov000_0218b474(a) > 0) {
                do {
                    e = func_ov000_0218b480(a, d);
                    if (func_ov000_0219e994(e) == 0) {
                        func_ov000_0218b4d4(a, e);
                        d--;
                    }
                    d++;
                } while (d < (s32) func_ov000_0218b474(a));
            }
            switch (gWiFiMatching->mState) {
                case 2:
                    d = 0;
                    if ((s32) func_ov000_0218b474(a) > 0) {
                        do {
                            e = func_ov000_0218b480(a, d);
                            f = gWiFiMatching;
                            if (f->mUnk_1c != NULL && f->mUnk_1c == (void *) func_ov000_0218b27c((u32 *) e) &&
                                f->mUnk_1a != 0 && gWiFiMatching->mUnk_1a == func_ov000_0218b260(e)) {
                                break;
                            }
                            d++;
                        } while (d < (s32) func_ov000_0218b474(a));
                    }
                    if (d < (s32) func_ov000_0218b474(a)) {
                        gWiFiMatching->mState = 3;
                        gWiFiMatching->mUnk_1ec = 0;
                        if (func_ov000_0219e594(func_ov000_021a0f20(gWiFiMatching->mUnk_1ec)) != 0) {
                            return;
                        }
                        return;
                    }
                    gWiFiMatching->mUnk_e8 = 2;
                    gWiFiMatching->mUnk_ec = OS_GetTick();
                    return;
                case 3:
                    func_ov000_0219dfe4(1);
                    if (func_ov000_0218b474(a) != 0) {
                        if (func_ov000_0219fee4(func_ov000_0219fdc8(0, 0)) != 0) {
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
                    if (func_ov000_0218b474(a) != 0) {
                        do {
                            e = func_ov000_0218b480(a, 0);
                            if (gWiFiMatching->mUnk_1ac == func_ov000_0218b27c((u32 *) e) &&
                                gWiFiMatching->mUnk_1aa == func_ov000_0218b260(e)) {
                                break;
                            }
                            func_ov000_0218b4d4(a, e);
                        } while (func_ov000_0218b474(a) != 0);
                    }
                    if (func_ov000_0218b474(a) != 0) {
                        e = SbServerGetInt((SbServer *) func_ov000_0218b480(a, 0), data_ov000_021b40c4, 0);
                        f = gWiFiMatching;
                        if (f->mMode == 1 && e == f->mParticipantProfileIds[0]) {
                            if (func_ov000_0219dfe4(0) != FALSE) {
                                if (gWiFiMatching->mLastParticipantPos != 0) {
                                    if (func_ov000_0219fee4(func_ov000_0219f8b0()) != 0) {
                                        return;
                                    }
                                }
                            } else {
                                if (func_ov000_0219fee4(
                                        func_ov000_0219fb14(gWiFiMatching->mParticipantProfileIds[0])) != 0) {
                                    return;
                                }
                                gWiFiMatching->mState = 4;
                                if (func_ov000_0219fee4(func_ov000_0219fbec(0, 0)) != 0) {
                                    return;
                                }
                                return;
                            }
                        }
                        gWiFiMatching->mState = 6;
                        if (func_ov000_0219e4a0(func_ov000_021a0cac(0, 0, func_ov000_0218b480(a, 0))) != 0) {
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

void func_ov000_0219e134(s32 a) {
    return;
}

BOOL func_ov000_0219dfe4(s32 a) {
    BOOL c;
    BOOL d;
    s32 e;
    u32 f;
    u32 g;
    s32 h;
    c = FALSE;
    e = 0;
    for (; e < (s32) func_ov000_0218b474(gWiFiMatching->mUnk_e4); e++) {
        f = func_ov000_0218b480(gWiFiMatching->mUnk_e4, e);
        if (gWiFiMatching->mMode == 0) {
            g = SbServerGetInt((SbServer *) f, data_ov000_021b40c4, 0);
            d = FALSE;
            for (h = 1; h <= gWiFiMatching->mLastParticipantPos; h++) {
                if (g == gWiFiMatching->mParticipantProfileIds[h]) {
                    func_ov000_0218b4d4(gWiFiMatching->mUnk_e4, f);
                    e--;
                    d = TRUE;
                    break;
                }
            }
            if (d != FALSE) {
                continue;
            }
        }
        if (gWiFiMatching->mUnk_45c != 0) {
            g = ((s32(*)(s32, u32)) gWiFiMatching->mUnk_45c)(e, gWiFiMatching->mUnk_460);
            if ((s32) g > 0) {
                if ((s32) g > 0x7fffff) {
                    g = 0x7fffff;
                }
                SbServerSetInt((SbServer *) f, data_ov000_021b40cc, (g << 8) | func_ov000_021a3448(0x100));
            } else {
                func_ov000_0218b4d4(gWiFiMatching->mUnk_e4, f);
                e--;
                c = TRUE;
            }
        } else {
            SbServerSetInt((SbServer *) f, data_ov000_021b40cc, func_ov000_021a3448(0x80));
        }
    }
    if (a != 0 && func_ov000_0218b474(gWiFiMatching->mUnk_e4) != 0) {
        func_ov000_0218b464(gWiFiMatching->mUnk_e4, 0, data_ov000_021b40cc, 0);
    }
    if (c != FALSE && func_ov000_0218b474(gWiFiMatching->mUnk_e4) == 0) {
        return FALSE;
    }
    return TRUE;
}

void func_ov000_0219dee0(s32 a, Unk021a471c *b, void *c) {
    s32 d;
    switch (a) {
        case 8:
            func_ov000_021a4760(b, gWiFiMatching->mUnk_14);
            return;
        case 0xa:
            func_ov000_021a4760(b, gWiFiMatching->mUnk_16);
            return;
        case 0x32:
            func_ov000_021a4760(b, gWiFiMatching->mUnk_1e8);
            return;
        case 0x33:
            func_ov000_021a4760(b, gWiFiMatching->mMode);
            return;
        case 0x34:
            func_ov000_021a4760(b, gWiFiMatching->mUnk_20);
            return;
        case 0x35:
            func_ov000_021a4760(b, 3);
            return;
        case 0x36:
            func_ov000_021a4760(b, 1);
            return;
    }
    d = a - 100;
    if (data_ov000_021b5698[d][0] != 0) {
        if (data_ov000_021b5699[d * 12] != 0) {
            func_ov000_021a471c(b, *(const char **) &data_ov000_021b56a0[d * 12]);
        } else {
            func_ov000_021a4760(b, **(s32 **) &data_ov000_021b56a0[d * 12]);
        }
    }
}

void func_ov000_0219dedc(void) {}

void func_ov000_0219ded8(void) {}

void func_ov000_0219de68(s32 a, Unk021a3fc8 *b, void *c) {
    s32 i;
    u8 *d;
    switch (a) {
        case 0:
            func_ov000_021a4784(b, 8);
            func_ov000_021a4784(b, 0xa);
            func_ov000_021a4784(b, 0x32);
            func_ov000_021a4784(b, 0x33);
            func_ov000_021a4784(b, 0x34);
            func_ov000_021a4784(b, 0x35);
            func_ov000_021a4784(b, 0x36);
            i = 0;
            d = data_ov000_021b5698[0];
            for (; i < 0x9a; i++) {
                if (d[0] != 0) {
                    func_ov000_021a4784(b, d[0]);
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

void func_ov000_0219de4c(void *value, u16 index) {
    gWiFiMatching->mUnk_1c = value;
    gWiFiMatching->mUnk_1a = index;
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
        gWiFiMatching->mUnk_3b4 = 0xff;
    }
}

void func_ov000_0219dd4c(const void *a, u32 b) {
    Unk0219dd4c c;
    u8 d[0x80];
    u32 e;
    e = 0;
    if (b >= 0x14) {
        do {
            MemCopy(a, &c, 0x14);
            if (strncmp(c.mUnk_00, data_ov000_021b40bc, 4) != 0) {
                break;
            }
            if (c.mUnk_04 != 3) {
                break;
            }
            MemCopy(a + 0x14, d, c.mUnk_09);
            if (func_ov000_021a01dc(c.mUnk_08, c.mUnk_10, c.mUnk_0c, c.mUnk_0a, (u32 *) d, c.mUnk_09 >> 2) == 0) {
                break;
            }
            e += c.mUnk_09 + 0x14;
        } while (e + 0x14 <= b);
    }
}
