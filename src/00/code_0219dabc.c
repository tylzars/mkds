#include "00/code_0219dabc.h"
#include "00/code_0219a654.h"
#include "00/code_0219f4c4.h"
#include "00/code_021a0958.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "00/code_021988e8.h"
#include "00/code_0219a000.h"
#include "00/code_0219e4e8.h"
#include "00/code_0219e134.h"
#include "00/code_0219f000.h"
#include "00/code_0219f9bc.h"
#include "00/code_021a01dc.h"
#include "00/code_021a17bc.h"
#include "code_0200d118.h"
#include "00/code_0219dd4c.h"
#include "00/code_021a3264.h"

void func_ov000_0219db18(s32 a, s32 b, Unk021a01dc *c, void *d) {
    s32 e;
    s32 f;
    u32 g;
    u32 h;
    char i[12];
    if (gWiFiMatching->mState != 6 && gWiFiMatching->mState != 0xb) {
        return;
    }
    if (d == NULL) {
        return;
    }
    if (a == 0) {
        ((Unk0219db18 *) d)->mUnk_08 = 0;
        gWiFiMatching->mUnk_14++;
        e = gWiFiMatching->mUnk_14;
        if (((Unk0219db18 *) d)->mUnk_00 != 0) {
            gWiFiMatching->mUnk_1f8[e] = c->mUnk_04;
            gWiFiMatching->mUnk_278[e] = (c->mUnk_02 >> 8) & 0xff | (c->mUnk_02 << 8) & 0xff00;
            gWiFiMatching->mUnk_174[0] = 0;
            gWiFiMatching->mUnk_178 = 0;
            gWiFiMatching->mUnk_17c = 0;
            if (gWiFiMatching->mState == 0xb) {
                gWiFiMatching->mState = 0xc;
            } else {
                gWiFiMatching->mState = 7;
            }
            gWiFiMatching->mUnk_0c = 0;
            OS_SNPrintf(i, 12, data_ov000_021b40b8, gWiFiMatching->mUnk_1e8);
            if (func_ov000_0219e3e4(
                    func_ov000_02198968(*gWiFiMatching->mConnectionSocket, NULL,
                                        Gt2FormatAddress(gWiFiMatching->mUnk_1f8[e], gWiFiMatching->mUnk_278[e], 0), i,
                                        -1, 0x1388, gWiFiMatching->mConnectionCallbacks, 0)) != 0) {
                return;
            }
            return;
        }
        if (c != 0) {
            gWiFiMatching->mUnk_1f8[e - 1] = c->mUnk_04;
            gWiFiMatching->mUnk_278[e - 1] = (c->mUnk_02 >> 8) & 0xff | (c->mUnk_02 << 8) & 0xff00;
        }
        gWiFiMatching->mUnk_184 = func_ov000_021a350c();
        gWiFiMatching->mState = 7;
        return;
    }
    if (((Unk0219db18 *) d)->mUnk_08 == 0) {
        return;
    }
    f = func_ov000_0219e45c(a);
    if (f != 2 && f != 1) {
        return;
    }
    if (((Unk0219db18 *) d)->mUnk_00 == 0) {
        if (f == 1 || (f == 2 && ((Unk0219db18 *) d)->mUnk_01 >= 1)) {
            ((Unk0219db18 *) d)->mUnk_08 = 0;
            if (func_ov000_0219dabc() != 0) {
                if (func_ov000_0219f938(gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mLastParticipantPos]) !=
                    0) {
                    return;
                }
            }
            return;
        }
        ((Unk0219db18 *) d)->mUnk_01++;
        if (func_ov000_0219e4a0(func_ov000_021a0c30(d)) != 0) {
            return;
        }
        return;
    }
    gWiFiMatching->mUnk_17c = func_ov000_021a350c();
    if (f == 1 || (f == 2 && gWiFiMatching->mUnk_174[0] >= 1)) {
        ((Unk0219db18 *) d)->mUnk_08 = 0;
        if (func_ov000_0219dabc() != 0) {
            gWiFiMatching->mUnk_174[0] = 0;
            gWiFiMatching->mUnk_178 = 0;
            gWiFiMatching->mUnk_17c = 0;
            if (func_ov000_0219f9bc(gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mLastParticipantPos + 1]) !=
                0) {
                return;
            }
        }
    }
}

u32 func_ov000_0219dabc(void) {
    if (gWiFiMatching->mMode == 2) {
        return 1;
    }
    if (gWiFiMatching->mMode != 3) {
        gWiFiMatching->mUnk_174[1]++;
    }
    if (gWiFiMatching->mMode == 3 || gWiFiMatching->mUnk_174[1] >= 5) {
        func_ov000_021a1a38(6, -0x15194);
        return 0;
    }
    return 1;
}
