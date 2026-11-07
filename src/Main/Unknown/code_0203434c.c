#include "Main/Unknown/code_0203434c.h"
#include "Main/Unknown/code_0202d990.h"
#include "Main/Unknown/code_02034bf4.h"
#include "Main/Unknown/code_020351c8.h"
#include "Main/Unknown/code_02036000.h"

#include "00/code_02181f98.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_0202d000.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_02034000.h"
#include "Main/Unknown/code_02035000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0204ece0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0204ed04.h"
#include "Main/Unknown/code_0204f5e4.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_020566a8.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020b3f7c.h"
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
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02125ed0.h"
#include "Main/Unknown/code_02125f2c.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_021262f0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0201ea58.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "code_0214d018.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02025edc.h"

#pragma thumb on

static inline s32 func_02034370_inline(void) {
    Unk021759d4 *p = data_021759d4;
    if (p->mUnk_0c != 0) {
        return p->mUnk_10;
    }
    return 0;
}

static inline s32 func_02034370_inline_2(void) {
    if (data_0217aa08->mUnk_28 == 0) {
        return func_02034370_inline();
    }
    return 1;
}

s32 func_02034370(Unk02034370 *a) {
    Unk02174e14_00 *q;
    Unk02174e14_00 *t;
    s32 o;
    u16 k;
    s32 r;
    s32 z;
    s32 m;
    s32 i;
    s32 j;
    s32 v;
    BOOL b1;
    BOOL a1;
    u16 w;
    s32 x;
    s32 y;
    void *e;
    void *f;
    void *g;
    u8 c[3];
    Unk02174e64_9c_00 s;
    u16 h[0x100];

    o = data_02174e64->mUnk_080;
    k = func_020435bc();
    z = 0;
    r = -1;
    m = -1;
    q = &data_02174e64->mUnk_02c[1];
    func_02025edc(&data_02174e64->mUnk_194);
    switch (data_02174e64->mState) {
        case 0:
            if (AreBrightnessFadesClear() == 0) {
                RequestSelectReturnState1();
                func_02035378();
                func_02025f14(&data_02174e64->mUnk_194, 0);
                data_02174e64->mState = 1;
            }
            break;
        case 1:
            if (data_02174e64->mUnk_194.mUnk_00 == 1) {
                data_02174e64->mState = 2;
            } else {
                func_02034fec();
            }
            break;
        case 2:
            switch (func_02054c98(0, NULL)) {
                case 1:
                    SetupTxtSystemSubText(GetBmgEntry(data_02174e64->mGhostMessages, 0xf));
                    NNS_SndArcSetCurrent(&data_0217c868);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 9);
                    NNS_SndArcSetCurrent(&data_0217d0a0);
                    data_02174e64->mState = 5;
                    break;
                case 0:
                    if (data_02174e64->mUnk_18c != FALSE) {
                        break;
                    }
                    if (func_02125f88() != 0) {
                        func_02035378();
                    }
                    data_02174e64->mUnk_190 = 0;
                    for (i = 0; i < 4; i++) {
                        j = i + 4;
                        if (func_0204ebb8(i, &s, &c[0], &c[1], &c[2], &s.mUnk_26, &s.mUnk_27, &s.mUnk_24)) {
                            s.mUnk_18[1] = c[0];
                            s.mUnk_18[0] = c[1];
                            s.mUnk_18[2] = c[2];
                            data_02174e64->mUnk_190++;
                            if (data_02174e64->mUnk_09c[i].mUnk_28 == FALSE ||
                                func_02034e68(&data_02174e64->mUnk_09c[i].mUnk_00, &s) != FALSE) {
                                v = func_02025d74(s.mUnk_18[2]);
                                s.mUnk_00[10] = 0;
                                func_0212426c(1, data_02164254[i][0], q->mUnk_14, &s, q->mUnk_0c, q->mUnk_18);
                                func_0212426c(1, data_02164254[j][0], q->mUnk_14,
                                              GetBmgEntry(data_02174e64->mGhostMessages, v), q->mUnk_0c, q->mUnk_18);
                                MIi_CpuCopyFast(&s, &data_02174e64->mUnk_09c[i].mUnk_00, 0x28);
                                data_02174e64->mUnk_09c[i].mUnk_28 = TRUE;
                                func_02025f14(&data_02174e64->mUnk_09c[i].mUnk_2c, 0);
                                if (data_02174e64->mUnk_080 == i) {
                                    func_02034f60();
                                }
                                NNS_SndArcSetCurrent(&data_0217c868);
                                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 7);
                                NNS_SndArcSetCurrent(&data_0217d0a0);
                            }
                        } else {
                            func_02025f14(&data_02174e64->mUnk_09c[i].mUnk_2c, 2);
                            data_02174e64->mUnk_09c[i].mUnk_28 = FALSE;
                        }
                    }
                    func_02035114();
                    b1 = FALSE;
                    a1 = FALSE;
                    w = data_02175674[k].mUnk_00;
                    if (w == 0 && data_02175680[k].mUnk_00 < 5) {
                        a1 = TRUE;
                    }
                    if (a1 == FALSE && data_0217567c[k].mUnk_00 == 0 && w != 0) {
                        b1 = TRUE;
                    }
                    if (b1 != FALSE) {
                        x = data_02175670[k].mUnk_00;
                        y = data_02175672[k].mUnk_00;
                        z = IsSelectReturnState2NoState3Or4RequestAndInRect(x, y);
                        m = RectTableFindContaining(q->mUnk_10, x, y);
                    }
                    if (m >= 0 && data_02174e64->mUnk_09c[m].mUnk_28 != FALSE) {
                        func_020351c8();
                        func_02035228(data_02174e64->mUnk_080 != m ? 1 : 0);
                        data_02174e64->mUnk_080 = m;
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                        RequestSelectReturnState4();
                        data_02174e64->mUnk_18c = TRUE;
                        data_02174e64->mUnk_090 = 0;
                        data_02174e64->mState = 3;
                    } else if ((u16) (data_02175628[k].mUnk_00 & 1) != 0 && data_02174e64->mUnk_080 >= 0) {
                        func_020351c8();
                        func_02035228(0);
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                        RequestSelectReturnState4();
                        data_02174e64->mUnk_18c = TRUE;
                        data_02174e64->mUnk_090 = 0;
                        data_02174e64->mState = 3;
                    } else if ((u16) (data_02175628[k].mUnk_00 & 2) != 0 || z != 0) {
                        data_02174e64->mState = 12;
                        RequestSelectReturnState3WithSound(0);
                    } else if (GetNewOrRepeatBits(k, 0x40)) {
                        if (data_02174e64->mUnk_190 == 2) {
                            func_020352fc(0);
                        } else if (data_02174e64->mUnk_190 > 2) {
                            func_020352fc(1);
                        }
                    } else if (GetNewOrRepeatBits(k, 0x80)) {
                        if (data_02174e64->mUnk_190 == 2) {
                            func_02035280(0);
                        } else if (data_02174e64->mUnk_190 > 2) {
                            func_02035280(1);
                        }
                    }
                    break;
                case 2:
                    break;
            }
            if (o != data_02174e64->mUnk_080) {
                func_02034f60();
                func_02034ef0();
            }
            break;
        case 3:
            data_02174e64->mUnk_090++;
            if (data_02174e64->mUnk_090 > 5) {
                func_02035228(1);
                data_02174e64->mUnk_090 = 0;
                data_02174e64->mState = 4;
            }
            break;
        case 4:
            if (func_02125f54() != 0) {
                if (GetTxtSystemSelectedIndex() == 0) {
                    func_0204ece0(data_02174e64->mUnk_080);
                } else {
                    RequestSelectReturnState1();
                    data_02174e64->mUnk_18c = FALSE;
                }
                RequestTxtSystemClose();
                data_02174e64->mState = 2;
            }
            break;
        case 5:
            switch (func_02054b44()) {
                case 1:
                    func_0204f5e4();
                    func_0204ee4c(0, func_0202ddd8());
                    data_02174e64->mState = 6;
                    break;
                case 2:
                    func_020353a4();
                    break;
            }
            break;
        case 6:
            switch (func_02054938()) {
                case 1:
                    data_02174e64->mState = 7;
                    break;
                case 2:
                    func_020353a4();
                    break;
            }
            break;
        case 7:
            if (func_02054f58() == 1) {
                func_0204f804();
                data_02174e64->mState = 8;
            }
            break;
        case 12:
            if (func_02054f58() == 1) {
                func_0204f804();
                data_0217b488->mUnk_08 = 5;
                if (a != NULL) {
                    a->mUnk_04 = 1;
                }
                data_02174e64->mState = 16;
            }
            break;
        case 8:
            if (func_0202da44(data_02174e64->mUnk_09c[data_02174e64->mUnk_080].mUnk_00.mUnk_18[2]) != 0) {
                v = func_02025d74(data_02174e64->mUnk_09c[data_02174e64->mUnk_080].mUnk_00.mUnk_18[2]);
                e = GetBmgEntry(data_02174e64->mGhostMessages, 0x55);
                f = GetBmgEntry(data_02174e64->mCommonMessages, 0);
                g = GetBmgEntry(data_02174e64->mCommonMessages, 1);
                func_0212513c(GetBmgEntry(data_02174e64->mGhostMessages, v), e, h, 0x100);
                SetTxtSystemSoundId(0, -1);
                func_02125fd4(h, f, g, 1, 0, 1, 1, 0);
                data_02174e64->mState = 9;
            } else if (func_0202dd9c() == 10) {
                RequestTxtSystemClose();
                data_02174e64->mUnk_098 = 2;
                data_02174e64->mState = 13;
                func_02025f14(&data_02174e64->mUnk_194, 2);
            } else {
                data_02174e64->mUnk_08c = func_0202d9fc();
                ((Unk0202ddd8 *) func_0202ddd8())->mUnk_08_0 = 1;
                func_020566a8((u8) data_02174e64->mUnk_08c, func_0202ddd8());
                NNS_SndArcSetCurrent(&data_0217c868);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 10);
                NNS_SndArcSetCurrent(&data_0217d0a0);
                data_02174e64->mState = 11;
            }
            break;
        case 9:
            if (func_02125f40() != 0 && GetTxtSystemSelectedIndex() == 0) {
                NNS_SndArcSetCurrent(&data_0217c868);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 10);
                NNS_SndArcSetCurrent(&data_0217d0a0);
            }
            if (func_02125f54() != 0) {
                RequestTxtSystemClose();
                if (GetTxtSystemSelectedIndex() == 0) {
                    data_02174e64->mUnk_08c =
                        func_0202d990(data_02174e64->mUnk_09c[data_02174e64->mUnk_080].mUnk_00.mUnk_18[2]);
                    ((Unk0202ddd8 *) func_0202ddd8())->mUnk_08_0 = 1;
                    func_020566a8((u8) data_02174e64->mUnk_08c, func_0202ddd8());
                    data_02174e64->mState = 11;
                } else {
                    data_02174e64->mState = 10;
                }
            }
            break;
        case 10:
            if (func_02125f88() != 0) {
                e = GetBmgEntry(data_02174e64->mGhostMessages, 0x54);
                f = GetBmgEntry(data_02174e64->mCommonMessages, 4);
                SetTxtSystemSoundId(0, 5);
                func_02126230(e, f);
                data_02174e64->mState = 14;
            }
            break;
        case 11:
            if (func_02034370_inline_2() != 0) {
                e = GetBmgEntry(data_02174e64->mGhostMessages, 0x10);
                f = GetBmgEntry(data_02174e64->mCommonMessages, 4);
                SetTxtSystemSoundId(0, 5);
                func_02126230(e, f);
                data_02174e64->mState = 14;
            }
            break;
        case 15:
            if (func_02125f6c() != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x15);
            }
            if (func_02125f54() != 0) {
                data_02174e64->mUnk_090 = 0;
                data_02174e64->mState = 12;
                RequestTxtSystemClose();
            }
            break;
        case 14:
            if (func_02125f54() != 0) {
                data_0217b488->mUnk_08 = 5;
                if (a != NULL) {
                    a->mUnk_04 = 1;
                }
                data_02174e64->mState = 16;
            }
            break;
        case 13:
            if (data_02174e64->mUnk_194.mUnk_00 == 3) {
                r = data_02174e64->mUnk_098;
                data_02174e64->mState = 16;
            } else {
                func_02034fec();
            }
            break;
    }
    func_02035060();
    func_02054aa0();
    for (i = 0; i < 2; i++) {
        t = &data_02174e64->mUnk_02c[i];
        func_02124c30(t->mUnk_0c, t->mUnk_08, t->mUnk_14, data_02174e64->mUnk_024[i], t->mUnk_18);
    }
    return r;
}

#pragma thumb off

#pragma thumb on

void func_0203434c(void) {
    HeapDestroy((void *) ((u32) data_02174e64->mHeap));
    *&data_02174e64 = NULL;
}

#pragma thumb off
