#include "Main/Unknown/code_02028130.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025eb0.h"
#include "Main/Unknown/code_02028774.h"
#include "Main/Unknown/code_0202881c.h"
#include "Main/Unknown/code_02028724.h"
#include "Main/Unknown/code_02028000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_02028d9c.h"
#include "Main/Unknown/code_02028f20.h"
#include "Main/Unknown/code_02029008.h"
#include "Main/Unknown/code_020291f0.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_02027e78.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_021105a0.h"
#include "Main/Unknown/code_021106a8.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_0211f378.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_0202bb80.h"

#pragma optimize_for_size on

u16 func_02028710(Unk02175628 *a, u32 b) {
    return a->mUnk_00 & b;
}

u16 func_020286f4(u32 a, u32 b) {
    return func_02028710(&data_02175628[a], b);
}

#pragma thumb on

int AdvanceSelectKart(void) {
    SelectKart *d;
    Unk02174e50_24 *p;
    s32 e;
    s32 r;
    s32 t;
    s32 x;
    Unk02174e50_24 *q;
    u32 v;
    d = gSelectKart;
    e = d->mKartIndex;
    x = 0;
    r = 0;
    q = &d->mSelectCharacterGpMParts;
    p = &d->mSelectKartSParts;
    t = func_020435bc();
    func_02025edc(&gSelectKart->mUnk_0ac[0]);
    func_02025edc(&gSelectKart->mUnk_0ac[1]);
    func_02025edc(&gSelectKart->mUnk_0ac[2]);
    func_02025edc(&gSelectKart->mUnk_0ac[3]);
    func_02025edc(&gSelectKart->mUnk_0ac[4]);
    func_02029008();
    if (func_020280dc() == 0) {
        AdvancePaletteBlend();
    }
    if (func_020280dc() == 0) {
        gSelectKart->mUnk_110 = func_020290fc();
    } else {
        gSelectKart->mUnk_110 = -1;
    }
    d = gSelectKart;
    switch (d->mState) {
        case 0:
            if (d->mUnk_0ac[4].mUnk_00 == 1) {
                d->mStateFrames = 0;
                if (func_020280dc() != 0) {
                    v = 1;
                } else {
                    v = 2;
                }
                gSelectKart->mState = v;
            }
            func_02028fac();
            break;
        case 1:
            func_02028824(d->mKartIndex | 0x80);
            gSelectKart->mResult = 1;
            gSelectKart->mState = 5;
            break;
        case 2:
            if (func_02028774(t) != 0) {
                x = IsSelectReturnState2NoState3Or4RequestAndInRect(func_0202874c(t), func_02028724(t));
            }
            if (func_020286f4(t, 1) != 0 || gSelectKart->mUnk_110 == 2 || func_02028f84() != 0) {
                gSelectKart->mStateFrames = 0;
                gSelectKart->mResult = 1;
                gSelectKart->mState = 4;
                p->mUnk_18[18].mUnk_00 = 0;
                func_02124100(data_usa_02153834[4], 0, p->mUnk_14, p->mUnk_18, p->mUnk_0c);
                func_021106a8(func_02025eb0(gSelectKart->mCharacterIndex), 1);
                func_02077f48(1);
                StopPaletteBlend();
            } else if (func_020286f4(t, 2) != 0 || x != 0) {
                gSelectKart->mStateFrames = 0;
                gSelectKart->mResult = 2;
                func_0202941c(0);
                func_02025f14(&gSelectKart->mUnk_0ac[1], 2);
                func_02025f14(&gSelectKart->mUnk_0ac[3], 2);
                func_02025f14(&gSelectKart->mUnk_0ac[4], 2);
                gSelectKart->mState = 7;
                if (gSelectKart->mMode != 0) {
                    v = 1;
                } else {
                    v = 0;
                }
                RequestSelectReturnState3WithSound(v);
            } else if (func_020ae408(t, 0x10) != 0 || func_020290ac(1) != 0) {
                func_020292bc();
                gSelectKart->mUnk_114 = 3;
                p->mUnk_18[1].mUnk_00 = 0;
                p->mUnk_18[3].mUnk_00 = 1;
            } else if (func_020ae408(t, 0x20) != 0 || func_020290ac(0) != 0) {
                func_02029248();
                gSelectKart->mUnk_114 = 2;
                p->mUnk_18[0].mUnk_00 = 0;
                p->mUnk_18[2].mUnk_00 = 1;
            }
            if (e != gSelectKart->mKartIndex) {
                func_02110698();
                func_02028f20();
                func_02028e38();
                gSelectKart->mState = 3;
                gSelectKart->mStateFrames = 0;
            }
            break;
        case 3:
            d->mStateFrames = d->mStateFrames + 1;
            if (gSelectKart->mStateFrames > 6) {
                gSelectKart->mStateFrames = 0;
                gSelectKart->mState = 2;
                p->mUnk_18[gSelectKart->mUnk_114].mUnk_04 = 0;
                p->mUnk_18[1].mUnk_00 = 1;
                p->mUnk_18[0].mUnk_00 = 1;
                p->mUnk_18[3].mUnk_00 = 0;
                p->mUnk_18[2].mUnk_00 = 0;
            } else {
                v = func_020adc64(gSelectKart->mStateFrames);
                if (gSelectKart->mUnk_114 == 2) {
                    v = -v;
                }
                p->mUnk_18[gSelectKart->mUnk_114].mUnk_04 = v;
            }
            break;
        case 4:
            d->mStateFrames = d->mStateFrames + 1;
            d = gSelectKart;
            if (d->mStateFrames >= 5) {
                switch (d->mMode) {
                    case 0:
                        GetRaceSetupCopy()->mEntries[gSelectKart->mEntryIndex].mKartIndex = d->mKartIndex;
                        GetRaceSetupCopy()->mEntries[gSelectKart->mEntryIndex].mUnk_14 = 1;
                        func_02116ef8();
                        gSelectKart->mState = 6;
                        break;
                    case 1:
                        RequestSelectReturnState4();
                        func_02028824(gSelectKart->mKartIndex | 0x80);
                        gSelectKart->mState = 5;
                        break;
                    case 2:
                        RequestSelectReturnState4();
                        SetWiFiSessionOwnKartIndex(gSelectKart->mKartIndex);
                        gSelectKart->mState = 5;
                        break;
                }
                gSelectKart->mStateFrames = 0;
                p->mUnk_18[18].mUnk_00 = 1;
                func_02124100(data_usa_02153834[4], 1, p->mUnk_14, p->mUnk_18, p->mUnk_0c);
            }
            break;
        case 5:
            if (d->mMode == 1 && func_0202b888() != 0 || gSelectKart->mMode == 2 && func_02121d0c() != 0) {
                gSelectKart->mStateFrames = 0;
                gSelectKart->mState = 6;
            }
            break;
        case 6:
            d->mStateFrames = d->mStateFrames + 1;
            if (gSelectKart->mStateFrames > 0x3c) {
                func_02025f14(&gSelectKart->mUnk_0ac[0], 2);
                func_02025f14(&gSelectKart->mUnk_0ac[1], 2);
                func_02025f14(&gSelectKart->mUnk_0ac[2], 2);
                func_02025f14(&gSelectKart->mUnk_0ac[3], 2);
                func_02025f14(&gSelectKart->mUnk_0ac[4], 2);
                if (gSelectKart->mMode == 2) {
                    func_021219cc();
                    func_0202941c(3);
                } else {
                    func_0202941c(2);
                }
                if (func_020280dc() == 0) {
                    StartKartModelMenuBg0Decrease();
                } else {
                    func_0211f378();
                }
                gSelectKart->mStateFrames = 0;
                gSelectKart->mState = 7;
            }
            break;
        case 7:
            if (d->mUnk_0ac[4].mUnk_00 == 3) {
                GetRaceSetupCopy()->mEntries[gSelectKart->mEntryIndex].mUnk_14 = d->mResult == 1;
                gSelectKart->mState = 8;
            }
            func_02028fac();
            break;
        case 8:
            r = d->mResult;
            break;
    }
    if (func_020280dc() == 0) {
        RequestKartModelMenuCharacter(gSelectKart->mCharacterIndex);
        RequestKartModelMenuKart(gSelectKart->mKartIndex);
        AdvanceKartModelMenu(GetRaceSetupCopy()->mMirrorMode);
        DrawKartModelMenu();
    }
    d = gSelectKart;
    if (d->mUnk_104 != FALSE) {
        func_0202bb80();
    } else {
        func_02124c30(q->mUnk_0c, q->mUnk_08, NULL, d->mUnk_080, q->mUnk_18);
    }
    if (func_020280dc() == 0) {
        d = gSelectKart;
        if (d->mState != 8) {
            func_02124c30(p->mUnk_0c, p->mUnk_08, p->mUnk_14, d->mUnk_084, p->mUnk_18);
        }
    } else {
        func_0211f39c();
    }
    switch (r) {
        case 1:
            GetRaceSetupCopy()->mUnk_108 = 0;
            break;
        case 2:
            GetRaceSetupCopy()->mUnk_108 = 2;
            break;
    }
    return r;
}
