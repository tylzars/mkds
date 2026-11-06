#include "Main/Unknown/code_02105550.h"
#include "Main/Unknown/code_0202511c.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_0204984c.h"

#include "code_0212bcac.h"
#include "Main/Unknown/code_021055b0.h"
#include "Main/Unknown/code_0210d120.h"
#include "Main/Unknown/code_0210d590.h"
#include "Main/Unknown/code_0210d740.h"
#include "Main/Unknown/code_0210d894.h"
#include "Main/Unknown/code_0210d9a0.h"
#include "Main/Unknown/code_0210dc50.h"
#include "Main/Unknown/code_0210ef68.h"
#include "Main/Unknown/code_0210f230.h"
#include "Main/Unknown/code_0210f744.h"
#include "Main/Unknown/code_0210f868.h"
#include "Main/Unknown/code_0210fad4.h"
#include "Main/Unknown/code_02110100.h"
#include "Main/Unknown/code_02110534.h"
#include "Main/Unknown/code_021105a0.h"
#include "Main/Unknown/code_02110720.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/code_02111158.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_0210d000.h"
#include "Main/Unknown/code_0212da2c.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02105980.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_0210d960.h"
#include "Main/Unknown/code_02105e98.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_0204a000.h"
#include "Main/Unknown/code_0210a000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/code_0210f000.h"
#include "Main/Unknown/code_02110000.h"
#include "Main/Unknown/code_02111000.h"
#include "code_0212ba68.h"
#include "code_0212c7a0.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_0206bcb0.h"
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
#include "Main/Unknown/code_0210912c.h"
#include "Main/Unknown/code_02109178.h"
#include "Main/Unknown/code_0210b6a0.h"
#include "Main/Unknown/code_0210b870.h"
#include "Main/Unknown/code_0210bbec.h"
#include "Main/Unknown/code_0210d570.h"
#include "Main/Unknown/code_0210dc48.h"
#include "Main/Unknown/code_0210ef50.h"
#include "Main/Unknown/code_0210f858.h"
#include "Main/Unknown/code_0210fa28.h"
#include "Main/Unknown/code_0210faac.h"
#include "Main/Unknown/code_0210fb54.h"
#include "Main/Unknown/code_02110484.h"
#include "Main/Unknown/code_02111118.h"
#include "code_0212ba34.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02108950.h"
#include "Main/Unknown/code_0210895c.h"
#include "Main/Unknown/code_021089f4.h"
#include "Main/Unknown/code_02108a40.h"
#include "Main/Unknown/code_02108b78.h"
#include "Main/Unknown/code_02108c04.h"
#include "Main/Unknown/code_02108c1c.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02024974.h"

const Vec3 data_0215a6c0 = {0x1000, 0x1000, 0x1000};
const Vec3 data_0215a6cc = {0, 0, 0};

void func_02108ddc(void) {
    NNS_SndArcSetCurrent(&data_0217c868);
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    data_0217c7a4 = 1;
    NNS_SndArcSetCurrent(&data_0217d0a0);
}

void func_02108d80(void) {
    NNS_SndArcSetCurrent(&data_0217c868);
    NNS_SndPlayerStopSeq(&data_0217c788, 0xd);
    data_0217c7a4 = 0;
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    NNS_SndArcSetCurrent(&data_0217d0a0);
}

void func_02108d00(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    data_0217c7a4 = 0;
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    NNS_SndArcSetCurrent(&data_0217c868);
    NNS_SndArcSetCurrent(&data_0217c868);
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 1);
    NNS_SndArcSetCurrent(&data_0217d0a0);
    NNS_SndArcSetCurrent(&data_0217d0a0);
}

void func_02108c80(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    data_0217c7a4 = 0;
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    NNS_SndArcSetCurrent(&data_0217c868);
    NNS_SndArcSetCurrent(&data_0217c868);
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 1);
    NNS_SndArcSetCurrent(&data_0217d0a0);
    NNS_SndArcSetCurrent(&data_0217d0a0);
}

void func_02108c1c(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    NNS_SndArcSetCurrent(&data_0217c868);
    if (data_0217c788 != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c788, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c788, 0, 8);
    NNS_SndArcSetCurrent(&data_0217d0a0);
}

void func_02108c04(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
}

void func_02108bb4(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    if (data_0217c788 != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c788, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c788, 0, 0x202);
}

void func_02108b78(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x203);
}

void func_02108b2c(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    if (data_0217c788 != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c788, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c788, 0, 0x204);
}

void func_02108adc(void) {
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    if (data_0217c778 != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c778, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c778, 0, 0x205);
}

void func_02108a8c(void) {
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    if (data_0217c778 != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c778, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c778, 0, 0x206);
}

void func_02108a40(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x207);
}

void func_021089f4(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, (0x0000020au));
}

void func_02108990(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x20a);
}

void func_0210895c(void) {
    NNS_SndPlayerStopSeq(&data_0217c788, 1);
    NNS_SndPlayerStopSeq(&data_0217c778, 1);
}

Unk0217c7b4 *func_02108950(void) {
    return &data_0217c7b4;
}

BOOL func_0210887c(s32 a) {
    s32 i;
    NNSSndHeap *p;

    p = data_0217d130;
    data_0217d130 = data_0217c77c;
    if (data_0216c7d4 != 2) {
        NNS_SndArcLoadBank(1, data_0217c77c);
    }
    for (i = 0; i < 0xd; i++) {
        if (((a >> i) & 1) != 0) {
            if (NNS_SndArcLoadBankEx(data_0216c7f8[i], 2, data_0217c77c) == 0) {
                data_0217d130 = p;
                return FALSE;
            }
            if (NNS_SndArcLoadWaveArc(data_0216c82c[i], data_0217c77c) == 0) {
                data_0217d130 = p;
                return FALSE;
            }
        }
    }
    data_0217d130 = p;
    return TRUE;
}

BOOL func_021087f4(s32 a) {
    if (a == 0) {
        return TRUE;
    }
    if (data_0216c7d8.mUnk_04 != 0xff00 && data_0216c7d8.mUnk_00 == a) {
        return TRUE;
    }
    NNS_SndHeapClear(data_0217c77c);
    data_0216c7d8.mUnk_04 = 0xff00;
    data_0216c7d8.mUnk_00 = 0;
    data_0216c7d8.mUnk_00 = a;
    data_0216c7d8.mUnk_04 = 0xfe00;
    if (func_0210887c(a) == FALSE) {
        return FALSE;
    }
    return TRUE;
}

int func_021087d4(int a) {
    return (a == 0 ? 0xc8000 : 0xaf000) - (a == 2 ? 0xaf000 : 0xc400);
}

int func_021087c4(int a) {
    return a == 2 ? 0xaf000 : 0xc400;
}

void func_02108720(void) {
    NNS_SndHeapDestroy(data_0217d130);
    data_0217d130 = NULL;
    NNS_SndHeapDestroy(data_0217c77c);
    data_0217c77c = NULL;
    NNS_SndHeapDestroy(data_0217c790);
    data_0217c790 = NULL;
    func_0210ef68(func_0210ef50());
    func_0210efac(func_0210ef50());
    ((u32 *) &data_0216c7d8)[0] = data_0215a6f4[0];
    ((u32 *) &data_0216c7d8)[1] = data_0215a6f4[1];
    func_0210e4ec(&data_0217c7b4);
}

void func_02108598(u32 a, u32 b) {
    u32 c;
    u32 d;
    u32 e;
    u32 v;
    u32 w;
    u32 x;

    data_0216c7d4 = a;
    switch (a) {
        case 0:
            c = 0x36f3c;
            break;
        case 1:
            c = 0x26a08;
            break;
        case 2:
            c = 0x25a5c;
            break;
    }
    ((u32 *) &data_0216c7d8)[0] = data_0215a6ec[0];
    ((u32 *) &data_0216c7d8)[1] = data_0215a6ec[1];
    func_0210e4ec(&data_0217c7b4);
    data_0217c77c = NNS_SndHeapCreate((void *) b, c);
    d = 0;
    data_0217d130 = NULL;
    b = b + c;
    switch (a) {
        case 0:
            d = 0x6580;
            break;
        case 1:
            d = 0x35a0;
            break;
        case 2:
            d = 0x35a0;
            break;
    }
    func_02111250((void *) b, d);
    data_0217c790 = (NNSSndHeap *) b;
    x = b + d;
    w = (a == 0 ? 0xc8000 : 0xaf000) - (a == 2 ? 0xaf000 : 0xc400);
    switch (a) {
        case 0:
            e = 0x36f3c;
            break;
        case 1:
            e = 0x26a08;
            break;
        case 2:
            e = 0x25a5c;
            break;
    }
    v = 0;
    switch (a) {
        case 0:
            v = 0x6580;
            break;
        case 1:
            v = 0x35a0;
            break;
        case 2:
            v = 0x35a0;
            break;
    }
    w = w - e - v;
    data_0217d130 = NNS_SndHeapCreate((void *) x, w);
    x = 0;
    if (a == 1) {
        x = 1;
    }
    func_0210e8f8(x);
}

void func_02108344(void *a, u32 b, u32 c) {
    u32 v;
    u32 w;
    Unk02108344 n;
    s32 i;

    data_0217c7a4 = 0;
    if (c == 0) {
        n = E2;
        switch (n) {
            case E0:
                v = 0x36f3c;
                break;
            case E1:
                v = 0x26a08;
                break;
            case E2:
                v = 0x25a5c;
                break;
        }
        w = 0;
        switch (n) {
            case E0:
                w = 0x6580;
                break;
            case E1:
                w = 0x35a0;
                break;
            case E2:
                w = 0x35a0;
                break;
        }
        b = b - v;
        data_0216c7d4 = 2;
        b = b - w;
    }
    func_0210d894(a, b, c != 0 ? data_0216c8d0 : 0);
    func_021105d8();
    NNS_SndArcInitOnMemory(&data_0217c868, data_0215a880);
    NNS_SndArcSetCurrent(&data_0217d0a0);
    if (c != 0) {
        func_0210e920();
    } else {
        ((u32 *) &data_0216c7d8)[0] = data_0215a6e4[0];
        ((u32 *) &data_0216c7d8)[1] = data_0215a6e4[1];
        data_0217c77c = NNS_SndHeapCreate((a + b), 0x25a5c);
        func_02111250((a + b + 0x25a5c), 0x35a0);
    }
    data_0216cb28 = 0x69;
    func_0210d854(1);
    func_020250a8();
    func_0210efac(func_0210ef50());
    func_0210efac(func_0210ef5c());
    for (i = 0; i < 12; i++) {
        NNS_SndHandleInit(&data_0217c838[i]);
    }
    func_0210e2c4(&data_0217c7c4, data_0217c7d8, 3, 8);
    NNS_SndHandleInit(&data_0217c7ac);
    NNS_SndHandleInit(&data_0217c788);
    NNS_SndHandleInit(&data_0217c778);
    NNS_SndSetMasterVolume(0x7f);
    NNS_SndSetMonoFlag(0);
    func_0210d970(0x1e);
    data_0217c7f0.mUnk_1c = FX_Div(0x7f000, 0x46000);
    data_0217c7f0.mUnk_20 = FX_Div(0x7f000, 0x3c000);
    data_0217c7f0.mUnk_14 = 0xff;
    data_0217c7f0.mUnk_18 = 0x7f;
    data_0217c7f0.mUnk_00 = data_0217c7f0.mUnk_1c;
    data_0217c7f0.mUnk_04 = 0;
    func_0210912c();
    data_0217c780 = 0;
    func_0210b6a0();
}

void func_0210823c(void) {
    s32 i;
    BOOL v;
    NNSSndSeqPlayer *p;

    if (data_0217d070.mUnk_00 != 0) {
        func_021060dc();
    }
    func_0210fa28();
    func_0210bac0();
    for (i = 0; i < 7; i++) {
        func_0210dd44((Unk0217d26c *) ((u8 *) data_0217d26c + i * sizeof(Unk0217d26c)));
    }
    func_0210e280(&data_0217c7c4);
    func_0210d2cc();
    if (data_0217c7a4 == 1) {
        p = data_0217c788;
        v = p != NULL && p->mSeqArcIndex == 0 && p->mSeqNo == 0;
        if (v == FALSE) {
            NNS_SndArcSetCurrent(&data_0217c868);
            if (data_0217c788 != NULL) {
                NNS_SndPlayerStopSeq(&data_0217c788, 0);
            }
            NNS_SndArcPlayerStartSeqArc(&data_0217c788, 0, 0);
            NNS_SndArcSetCurrent(&data_0217d0a0);
        }
    }
    func_0210d7ac();
    data_0217c794 = 0;
}

void func_021074ac(s32 e) {
    s32 c;
    s32 a;
    s32 v;
    BOOL b;
    u32 d;
    NNSSndHeap *p;
    Unk0210e524 buf;
    Unk021073ec s;

    if (*(vu16 *) 0x027ffc40 == 2 && GetCurrentSceneNumber() == 6) {
        return;
    }
    func_0210bc14();
    a = GetCurrentSceneNumber();
    v = 0x69;
    b = FALSE;
    if (GetCurrentSceneNumber() == 2) {
        d = data_021759c0->mUnk_00c == 0 || data_021759c0->mUnk_00c == 2;
        if (d != 0) {
            b = TRUE;
        }
    }
    if (b != FALSE) {
        switch (data_021759c0->mCourseId) {
            case COURSE_ID_BEACH:
                v = v + 0x17;
                break;
            case COURSE_ID_OLD_MOMO_64:
                v = v + 5;
                break;
            case COURSE_ID_OLD_MARIO_SFC:
                v = v + 1;
                break;
            case COURSE_ID_OLD_PEACH_AGB:
            case COURSE_ID_OLD_LUIGI_AGB:
                v = v + 0xd;
                break;
            case COURSE_ID_OLD_DONUT_SFC:
                v = v + 5;
                break;
        }
    }
    if (v > 0x7f) {
        v = 0x7f;
    }
    data_0216cb28 = v;
    c = func_0202511c(a, &buf);
    if (data_0217d060 == NULL) {
        func_0210f808();
        func_0210f868(0, 0);
        func_0210f868(1, 0);
    }
    func_02110a60();
    func_02110838();
    func_021104dc(0);
    func_0210d970(func_0204a4e4());
    func_02110484();
    func_021103c0();
    switch (a) {
        case 2:
            v = data_021759c0->mCourseId;
            switch (v) {
                case COURSE_ID_TOWN:
                    func_0210f868(0, 1);
                    func_0210f868(1, 1);
                    break;
                case COURSE_ID_MANSION:
                    func_0210bbec(0x15, data_0216c860[0].mUnk_04, &data_0216c860[0]);
                    func_0210bbec(0x8, data_0216c860[0].mUnk_04, &data_0216c860[0]);
                    func_0210bbec(0x9, data_0216c860[0].mUnk_04, &data_0216c860[0]);
                    func_0210bbec(0xd, data_0216c860[0].mUnk_04, &data_0216c860[0]);
                    func_0210bbec(0xe, data_0216c860[0].mUnk_04, &data_0216c860[0]);
                    func_0210bbec(0x10, data_0216c860[0].mUnk_04, &data_0216c860[0]);
                    break;
                case COURSE_ID_PINBALL:
                    func_0210bbec(0x15, data_0216c860[1].mUnk_04, &data_0216c860[1]);
                    func_0210bbec(0x8, data_0216c860[1].mUnk_04, &data_0216c860[1]);
                    func_0210bbec(0x9, data_0216c860[1].mUnk_04, &data_0216c860[1]);
                    func_0210bbec(0xd, data_0216c860[1].mUnk_04, &data_0216c860[1]);
                    func_0210bbec(0xe, data_0216c860[1].mUnk_04, &data_0216c860[1]);
                    func_0210bbec(0x10, data_0216c860[1].mUnk_04, &data_0216c860[1]);
                    break;
                case COURSE_ID_RIDGE:
                    func_0210bbec(0x15, data_0216c860[2].mUnk_04, &data_0216c860[2]);
                    func_0210bbec(0x8, data_0216c860[2].mUnk_04, &data_0216c860[2]);
                    func_0210bbec(0x9, data_0216c860[2].mUnk_04, &data_0216c860[2]);
                    func_0210bbec(0xd, data_0216c860[2].mUnk_04, &data_0216c860[2]);
                    func_0210bbec(0xe, data_0216c860[2].mUnk_04, &data_0216c860[2]);
                    func_0210bbec(0x10, data_0216c860[2].mUnk_04, &data_0216c860[2]);
                    break;
                case COURSE_ID_SNOW:
                    func_0210bbec(0x15, data_0216c860[3].mUnk_04, &data_0216c860[3]);
                    func_0210bbec(0x8, data_0216c860[3].mUnk_04, &data_0216c860[3]);
                    func_0210bbec(0x9, data_0216c860[3].mUnk_04, &data_0216c860[3]);
                    func_0210bbec(0xd, data_0216c860[3].mUnk_04, &data_0216c860[3]);
                    func_0210bbec(0xe, data_0216c860[3].mUnk_04, &data_0216c860[3]);
                    func_0210bbec(0x10, data_0216c860[3].mUnk_04, &data_0216c860[3]);
                    break;
                case COURSE_ID_CLOCK:
                    func_0210bbec(0x15, data_0216c860[4].mUnk_04, &data_0216c860[4]);
                    func_0210bbec(0x8, data_0216c860[4].mUnk_04, &data_0216c860[4]);
                    func_0210bbec(0x9, data_0216c860[4].mUnk_04, &data_0216c860[4]);
                    func_0210bbec(0xd, data_0216c860[4].mUnk_04, &data_0216c860[4]);
                    func_0210bbec(0xe, data_0216c860[4].mUnk_04, &data_0216c860[4]);
                    func_0210bbec(0x10, data_0216c860[4].mUnk_04, &data_0216c860[4]);
                    break;
                case COURSE_ID_AIRSHIP:
                    func_0210bbec(0x15, data_0216c860[5].mUnk_04, &data_0216c860[5]);
                    func_0210bbec(0x8, data_0216c860[5].mUnk_04, &data_0216c860[5]);
                    func_0210bbec(0x9, data_0216c860[5].mUnk_04, &data_0216c860[5]);
                    func_0210bbec(0xd, data_0216c860[5].mUnk_04, &data_0216c860[5]);
                    func_0210bbec(0xe, data_0216c860[5].mUnk_04, &data_0216c860[5]);
                    func_0210bbec(0x10, data_0216c860[5].mUnk_04, &data_0216c860[5]);
                    break;
                case COURSE_ID_STADIUM:
                    func_0210bbec(0x15, data_0216c860[6].mUnk_04, &data_0216c860[6]);
                    func_0210bbec(0x8, data_0216c860[6].mUnk_04, &data_0216c860[6]);
                    func_0210bbec(0x9, data_0216c860[6].mUnk_04, &data_0216c860[6]);
                    func_0210bbec(0xd, data_0216c860[6].mUnk_04, &data_0216c860[6]);
                    func_0210bbec(0xe, data_0216c860[6].mUnk_04, &data_0216c860[6]);
                    func_0210bbec(0x10, data_0216c860[6].mUnk_04, &data_0216c860[6]);
                    break;
                case COURSE_ID_GARDEN:
                    func_0210bbec(0x15, data_0216c860[7].mUnk_04, &data_0216c860[7]);
                    func_0210bbec(0x8, data_0216c860[7].mUnk_04, &data_0216c860[7]);
                    func_0210bbec(0x9, data_0216c860[7].mUnk_04, &data_0216c860[7]);
                    func_0210bbec(0xd, data_0216c860[7].mUnk_04, &data_0216c860[7]);
                    func_0210bbec(0xe, data_0216c860[7].mUnk_04, &data_0216c860[7]);
                    func_0210bbec(0x10, data_0216c860[7].mUnk_04, &data_0216c860[7]);
                    break;
                case COURSE_ID_KOOPA:
                    func_0210bbec(0x15, data_0216c860[8].mUnk_04, &data_0216c860[8]);
                    func_0210bbec(0x8, data_0216c860[8].mUnk_04, &data_0216c860[8]);
                    func_0210bbec(0x9, data_0216c860[8].mUnk_04, &data_0216c860[8]);
                    func_0210bbec(0xd, data_0216c860[8].mUnk_04, &data_0216c860[8]);
                    func_0210bbec(0xe, data_0216c860[8].mUnk_04, &data_0216c860[8]);
                    func_0210bbec(0x10, data_0216c860[8].mUnk_04, &data_0216c860[8]);
                    break;
                case COURSE_ID_OLD_BABY_GC:
                    func_0210bbec(0x15, data_0216c860[9].mUnk_04, &data_0216c860[9]);
                    func_0210bbec(0x8, data_0216c860[9].mUnk_04, &data_0216c860[9]);
                    func_0210bbec(0x9, data_0216c860[9].mUnk_04, &data_0216c860[9]);
                    func_0210bbec(0xd, data_0216c860[9].mUnk_04, &data_0216c860[9]);
                    func_0210bbec(0xe, data_0216c860[9].mUnk_04, &data_0216c860[9]);
                    func_0210bbec(0x10, data_0216c860[9].mUnk_04, &data_0216c860[9]);
                    break;
                case COURSE_ID_OLD_KINOKO_GC:
                    func_0210bbec(0x15, data_0216c860[10].mUnk_04, &data_0216c860[10]);
                    func_0210bbec(0x8, data_0216c860[10].mUnk_04, &data_0216c860[10]);
                    func_0210bbec(0x9, data_0216c860[10].mUnk_04, &data_0216c860[10]);
                    func_0210bbec(0xd, data_0216c860[10].mUnk_04, &data_0216c860[10]);
                    func_0210bbec(0xe, data_0216c860[10].mUnk_04, &data_0216c860[10]);
                    func_0210bbec(0x10, data_0216c860[10].mUnk_04, &data_0216c860[10]);
                    break;
                case COURSE_ID_OLD_HYUDORO_64:
                    func_0210bbec(0x15, data_0216c860[11].mUnk_04, &data_0216c860[11]);
                    func_0210bbec(0x8, data_0216c860[11].mUnk_04, &data_0216c860[11]);
                    func_0210bbec(0x9, data_0216c860[11].mUnk_04, &data_0216c860[11]);
                    func_0210bbec(0xd, data_0216c860[11].mUnk_04, &data_0216c860[11]);
                    func_0210bbec(0xe, data_0216c860[11].mUnk_04, &data_0216c860[11]);
                    func_0210bbec(0x10, data_0216c860[11].mUnk_04, &data_0216c860[11]);
                    break;
                case COURSE_ID_MINI_STAGE4:
                    func_0210bbec(0x15, data_0216c860[12].mUnk_04, &data_0216c860[12]);
                    func_0210bbec(0x8, data_0216c860[12].mUnk_04, &data_0216c860[12]);
                    func_0210bbec(0x9, data_0216c860[12].mUnk_04, &data_0216c860[12]);
                    func_0210bbec(0xd, data_0216c860[12].mUnk_04, &data_0216c860[12]);
                    func_0210bbec(0xe, data_0216c860[12].mUnk_04, &data_0216c860[12]);
                    func_0210bbec(0x10, data_0216c860[12].mUnk_04, &data_0216c860[12]);
                    break;
                case COURSE_ID_OLD_LUIGI_AGB:
                    func_0210bc00(data_0216c7e0.mUnk_10, data_0216c7e0.mUnk_14, &data_0216c7e0);
                    break;
                case COURSE_ID_MR_STAGE3:
                    func_0210bbec(0x15, data_0216c860[13].mUnk_04, &data_0216c860[13]);
                    func_0210bbec(0x8, data_0216c860[13].mUnk_04, &data_0216c860[13]);
                    func_0210bbec(0x9, data_0216c860[13].mUnk_04, &data_0216c860[13]);
                    func_0210bbec(0xd, data_0216c860[13].mUnk_04, &data_0216c860[13]);
                    func_0210bbec(0xe, data_0216c860[13].mUnk_04, &data_0216c860[13]);
                    func_0210bbec(0x10, data_0216c860[13].mUnk_04, &data_0216c860[13]);
                    if (data_021759c0->mUnk_00c == 0) {
                        func_021104dc(1);
                    }
                    break;
            }
            func_0210f5d4(v);
            if (data_021759c0->mMode == MODE_MISSION_RUN) {
                u8 *w = (u8 *) data_021759c0 + 0x28;
                switch (data_021759c0->mUnk_2f) {
                    case 1:
                        data_0217c770[0] = 0x1d7;
                        data_0217c76c[0] = 0x1d7;
                        break;
                    case 7:
                        data_0217c770[0] = 0x1e0;
                        data_0217c76c[0] = 0x1e1;
                        switch (w[6]) {
                            case 9:
                            case 0xa:
                                data_0217c76c[0] = 0xff;
                                break;
                        }
                        break;
                    case 0:
                        data_0217c770[0] = 0x1db;
                        data_0217c76c[0] = 0x1dc;
                        break;
                    case 2:
                    case 6:
                        data_0217c770[0] = 0xff;
                        data_0217c76c[0] = 0xff;
                        break;
                    case 4:
                        data_0217c770[0] = 0x1dd;
                        data_0217c76c[0] = 0x1de;
                        break;
                    case 3:
                        data_0217c770[0] = 0x1dd;
                        data_0217c76c[0] = 0x1de;
                        break;
                    case 8:
                    case 9:
                    case 10:
                        break;
                }
            }
            { break; }
        case 1:
            if (*(vu16 *) 0x027ffc40 != 2) {
                p = data_0217d130;
                if (data_0216c7d8.mUnk_04 == 0xff00 || data_0216c7d8.mUnk_00 != 0xffff) {
                    NNS_SndHeapClear(data_0217c77c);
                    data_0216c7d8.mUnk_04 = 0xff00;
                    data_0216c7d8.mUnk_00 = 0;
                    data_0217d130 = data_0217c77c;
                    if (NNS_SndArcLoadBank(0x2c, data_0217c77c) != 0) {
                        if (NNS_SndArcLoadSeqArc(3, data_0217d130) != 0) {
                            data_0217d130 = p;
                            data_0216c7d8.mUnk_00 = 0xffff;
                            data_0216c7d8.mUnk_04 = 0xfe00;
                        }
                    }
                }
            }
            { break; }
        case 0xc:
            p = data_0217d130;
            if (data_0216c7d8.mUnk_04 == 0xff00 || data_0216c7d8.mUnk_00 != 0xffff) {
                NNS_SndHeapClear(data_0217c77c);
                data_0216c7d8.mUnk_04 = 0xff00;
                data_0216c7d8.mUnk_00 = 0;
                data_0217d130 = data_0217c77c;
                if (NNS_SndArcLoadBank(0x2c, data_0217c77c) != 0) {
                    if (NNS_SndArcLoadSeqArc(3, data_0217d130) != 0) {
                        data_0217d130 = p;
                        data_0216c7d8.mUnk_00 = 0xffff;
                        data_0216c7d8.mUnk_04 = 0xfe00;
                    }
                }
            }
            { break; }
        case 0:
            break;
    }
    s.mUnk_00 = 0xff;
    s.mUnk_01 = buf.mUnk_00;
    s.mUnk_02 = buf.mUnk_01;
    func_021103c0();
    func_021073ec(c & 0xff, s, &data_0217c814);
    func_0210912c();
    func_0210b870();
    func_0210aefc();
    func_021105a0();
    func_0210fb68();
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_0210e888(buf, 0);
    }
    if (a != 1) {
        return;
    }
    if (*(vu16 *) 0x027ffc40 != 2) {
        NNS_SndArcLoadBank(2, data_0217d130);
    }
    if (*(vu16 *) 0x027ffc40 == 2) {
        return;
    }
    data_0217c798[0] = NNS_SndHeapSaveState(data_0217d130);
    if (GetCurrentSceneNumber() != 1) {
        return;
    }
    if (data_0217b488->mUnk_08 == 3) {
        data_0217d070.mUnk_0a = 0xff;
    }
}

void func_021073ec(u32 a, Unk021073ec b, Unk0217c814 *c) {
    c->mUnk_15 = 0;
    NNS_SndHandleInit(&c->mUnk_08);
    c->mUnk_16 = 0;
    c->mUnk_10 = 0;
    c->mUnk_17 = 0;
    c->mUnk_00 = 0;
    c->mUnk_04 = 0;
    c->mUnk_0c = 0;
    c->mUnk_18 = 0xff;
    c->mUnk_19 = 0xff;
    c->mUnk_1c = -1;
    c->mUnk_20 = 0;
    func_0210d740(&data_0217d070, c, a, b);
    data_0217d084.mUnk_18 = &data_0217c81c;
    func_0210d9a0(&data_0217d084, 0);
}

void func_02107010(void) {
    s32 b;
    u32 c;
    s32 v;
    s32 i;
    NNSSndArc *n;
    NNSSndSeqPlayer **p;
    s32 j;

    if (*(u16 *) 0x27ffc40 == 2) {
        if (GetCurrentSceneNumber() == 6) {
            return;
        }
    }
    func_02111118();
    data_0217c780 = 0;
    func_02109178((u32) &data_0217c780);
    b = 0;
    data_0217c7f0.mUnk_04 = 0;
    data_0217c7f0.mUnk_0c = 0x7f;
    data_0217c7f0.mUnk_10 = 0x7f;
    data_0217c7f0.mUnk_08 = 0;
    if (GetCurrentSceneNumber() == 2) {
        c = data_021759c0->mUnk_00c == 0 || data_021759c0->mUnk_00c == 2;
        if (c != 0) {
            b = 1;
        }
    }
    if (b != 0) {
        func_0210d9a0(&data_0217d084, 2);
        data_0217c780 = 1;
        func_0210d614(&data_0217d070, func_02111144(), NULL);
        data_0217c7b0 = 0;
        v = 0xffff;
        if (data_021759c0->mMode == MODE_MISSION_RUN) {
            switch (data_021759c0->mUnk_2e) {
                case 9:
                    v = 0x20e;
                    break;
                case 0x11:
                    v = 0x235;
                    break;
                case 0x31:
                    v = 0x246;
                    break;
                case 0x33:
                    v = 0x228;
                    break;
            }
        }
        if (v == 0xffff) {
            switch (data_021759c0->mCourseId) {
                case COURSE_ID_AIRSHIP:
                    v = 0x1d2;
                    break;
                case COURSE_ID_STADIUM:
                    v = 0x1bf;
                    break;
                case COURSE_ID_OLD_LUIGI_AGB:
                    v = 0x1d6;
                    break;
            }
        }
        if (v != 0xffff) {
            NNS_SndPlayerStopSeq(&data_0217c854, 0);
            p = &data_0217c854;
            if ((data_0217c780 & 1) != 0) {
                if (data_0217d084.mUnk_0c != 0) {
                    if (*p != NULL) {
                        NNS_SndPlayerStopSeq(p, 0);
                    }
                    if (*p != NULL) {
                        NNS_SndPlayerStopSeq(p, 0);
                    }
                    NNS_SndArcPlayerStartSeqArc(p, 0, v);
                }
            }
            data_0217c7b0 = 1;
        }
        if (data_021759c0->mMode != MODE_BATTLE) {
            func_02110534(gCourseMap->mUnk_104);
            data_0217c814.mUnk_14 = func_02044618();
        }
    } else {
        if (GetCurrentSceneNumber() == 2) {
            if (data_021759c0->mUnk_00c - 3 <= 1) {
                func_0210d9a0(&data_0217d084, 2);
                data_0217c780 = 2;
            } else {
                if (func_0210d980() != 0) {
                    n = NNS_SndArcGetCurrent();
                    NNS_SndArcSetCurrent(&data_0217d0a0);
                    v = 0xffff;
                    b = 0x7f;
                    for (i = 1; i <= 7; i++) {
                        if (NNS_SndArcGetPlayerInfo(i) != NULL) {
                            if (((v >> i) & 1) != 0) {
                                NNS_SndPlayerSetPlayerVolume(i, b);
                            }
                        }
                    }
                    NNS_SndArcSetCurrent(n);
                }
                data_0217c7f0.mUnk_04 = 0x7f000;
                func_0210d9a0(&data_0217d084, 3);
                data_0217c780 = 0;
            }
        } else {
            if (func_0210d980() != 0) {
                n = NNS_SndArcGetCurrent();
                NNS_SndArcSetCurrent(&data_0217d0a0);
                v = 0xffff;
                b = 0x7f;
                for (j = 1; j <= 7; j++) {
                    if (NNS_SndArcGetPlayerInfo(j) != NULL) {
                        if (((v >> j) & 1) != 0) {
                            NNS_SndPlayerSetPlayerVolume(j, b);
                        }
                    }
                }
                NNS_SndArcSetCurrent(n);
            }
            data_0217c7f0.mUnk_04 = 0x7f000;
            func_0210d9a0(&data_0217d084, 2);
            data_0217c780 = 0;
        }
    }
    func_0210d6cc(&data_0217d070);
}

void func_02106efc(void) {
    s32 i;
    NNSSndSeqPlayer **p;

    data_0217c814.mUnk_0c = 1;
    func_0210d65c(&data_0217d070);
    data_0217c7f0.mUnk_08 = 1;
    if (data_0217c7b0 != 0) {
        NNS_SndPlayerStopSeq(&data_0217c854, 0x14);
    }
    if (data_021759c0->mCourseId != COURSE_ID_STADIUM) {
        return;
    }
    for (i = 7; i < 12; i++) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) ((u8 *) data_0217c838 + i * sizeof(NNSSndSeqPlayer *)), 0);
    }
    p = &data_0217c854;
    if ((data_0217c780 & 1) == 0) {
        return;
    }
    if (data_0217d084.mUnk_0c == 0) {
        return;
    }
    if (*p != NULL) {
        NNS_SndPlayerStopSeq(p, 0);
    }
    if (*p != NULL) {
        NNS_SndPlayerStopSeq(p, 0);
    }
    NNS_SndArcPlayerStartSeqArc(p, 0, 0x1c0);
}

void func_02106e78(void) {
    if (data_0217c814.mUnk_0c != 1) {
        return;
    }
    data_0217c814.mUnk_17 = 1;
    if ((data_0217c814.mUnk_16 & 1) != 0) {
        data_0217c7a8 = 1;
        return;
    }
    NNS_SndPlayerSetTrackMuteEx(&data_0217d07c, 0xffff, 1);
    func_0210d614(&data_0217d070, 0x49, &data_0217c81c);
}

void func_02106dc8(void) {
    NNS_SndPlayerSetTrackMuteEx(&data_0217d07c, 0xffff, 0);
    NNS_SndPlayerStopSeq(&data_0217c81c, 0);
    if (data_0217c78c != 0) {
        if (data_0217c814.mUnk_0c == 1) {
            func_0210d5c0(&data_0217d070);
            NNS_SndPlayerSetVolume(&data_0217d07c, data_0217d234.mUnk_04 >> 12);
            NNS_SndPlayerSetTempoRatio(&data_0217d07c, 0x12c);
            func_0210faac();
        }
        data_0217c78c = 0;
    }
    data_0217c814.mUnk_17 = 0;
}

void func_02106c64(void) {
    u32 v;
    s32 i;
    s32 j;
    u8 *q;

    data_0217c814.mUnk_0c = 2;
    func_0210d590(&data_0217d070, func_0210dc48());
    NNS_SndPlayerSetTrackMuteEx(&data_0217d07c, 0xffff, 0);
    NNS_SndPlayerStopSeq(&data_0217c81c, 0);
    if (data_0217c78c != 0) {
        if (data_0217c814.mUnk_0c == 1) {
            func_0210d5c0(&data_0217d070);
            NNS_SndPlayerSetVolume(&data_0217d07c, data_0217d234.mUnk_04 >> 12);
            NNS_SndPlayerSetTempoRatio(&data_0217d07c, 0x12c);
            func_0210faac();
        }
        data_0217c78c = 0;
    }
    data_0217c814.mUnk_17 = 0;
    if (data_0217d084.mUnk_04 == 2) {
        func_0210d9a0(&data_0217d084, 3);
    }
    for (i = 0; i < 12; i++) {
        NNS_SndPlayerStopSeq(data_0217c838 + i, func_0210dc48());
    }
    v = func_0210dc48();
    for (j = 0, q = (&data_0217c7c4)->mUnk_0c; j < (&data_0217c7c4)->mUnk_00; j++) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) q, v);
        q += (&data_0217c7c4)->mUnk_10;
    }
}

void func_02106ab8(void) {
    BOOL b;
    s32 i;
    NNSSndSeqPlayer **p;

    b = FALSE;
    if (GetCurrentSceneNumber() == 2) {
        if (data_021759c0->mUnk_00c == 1) {
            return;
        }
    }
    if (data_021759c0->mMode == MODE_BATTLE) {
        return;
    }
    data_0217c814.mUnk_15 = data_0217c814.mUnk_15 + 1;
    if (data_0217c814.mUnk_15 == data_0217c814.mUnk_14) {
        b = TRUE;
    } else if (data_0217c814.mUnk_15 == data_0217c814.mUnk_14 - 1) {
        data_0217c814.mUnk_16 = 1;
        data_0217c814.mUnk_10 = 1;
        func_0210d590(&data_0217d070, 0);
        if (data_0217c814.mUnk_08 != NULL) {
            NNS_SndPlayerSetTrackMuteEx(&data_0217c81c, 0xffff, 1);
        }
        func_0210d614(&data_0217d070, 0x3e, NULL);
        data_0217c814.mUnk_16 = 1;
    }
    if (data_021759c0->mCourseId != COURSE_ID_STADIUM) {
        return;
    }
    if (b != FALSE) {
        return;
    }
    for (i = 7; i < 12; i++) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) ((u8 *) data_0217c838 + i * sizeof(NNSSndSeqPlayer *)), 0);
    }
    p = &data_0217c854;
    if ((data_0217c780 & 1) == 0) {
        return;
    }
    if (data_0217d084.mUnk_0c == 0) {
        return;
    }
    if (*p != NULL) {
        NNS_SndPlayerStopSeq(p, 0);
    }
    if (*p != NULL) {
        NNS_SndPlayerStopSeq(p, 0);
    }
    NNS_SndArcPlayerStartSeqArc(p, 0, 0x1c1);
}

void func_0210689c(u32 a) {
    BOOL b;
    BOOL c;
    u32 d;
    u32 e;
    u32 v;
    s32 i;
    NNSSndSeqPlayer *p;
    NNSSndSeqPlayer **q;

    b = FALSE;
    if (GetCurrentSceneNumber() == 2) {
        c = data_021759c0->mUnk_00c == 0 || data_021759c0->mUnk_00c == 2;
        if (c != FALSE) {
            b = TRUE;
        }
    }
    if (b == FALSE) {
        return;
    }
    if ((u32) data_021759c0->mMode - 1 <= 1) {
        return;
    }
    v = -1;
    b = FALSE;
    if (data_0217c814.mUnk_00 <= 0xf0) {
        data_0217c814.mUnk_18 = a;
        return;
    }
    switch (data_021759c0->mCourseId) {
        case COURSE_ID_STADIUM:
            if (data_0217c814.mUnk_10 != 0) {
                v = 0x1c2;
                for (i = 7; i < 12; i++) {
                    NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) ((u8 *) data_0217c838 + i * sizeof(NNSSndSeqPlayer *)),
                                         b);
                }
                b = TRUE;
            }
            { break; }
        case COURSE_ID_PINBALL:
            v = a == 0 ? 0x1cb : 0x1ca;
            b = TRUE;
            p = data_0217c838[7];
            d = p != NULL && p->mSeqArcIndex == 0x1cc && p->mSeqNo == 0;
            if (d != 0) {
                b = FALSE;
            }
            break;
    }
    if (b != FALSE) {
        if (a < data_0217c814.mUnk_18) {
            e = 0;
            if (data_0217c814.mUnk_1c != -1) {
                if (data_0217c814.mUnk_19 > a) {
                    e = 1;
                }
            } else {
                e = 1;
            }
            if (e != 0) {
                NNS_SndPlayerStopSeq(&data_0217c854, 0);
                q = &data_0217c854;
                if (data_0217c780 & 1) {
                    if (data_0217d084.mUnk_0c != 0) {
                        if (*q != NULL) {
                            NNS_SndPlayerStopSeq(q, 0);
                        }
                        if (*q != NULL) {
                            NNS_SndPlayerStopSeq(q, 0);
                        }
                        NNS_SndArcPlayerStartSeqArc(q, 0, (u16) v);
                    }
                }
                data_0217c814.mUnk_19 = a;
                data_0217c814.mUnk_1c = 0;
            }
        }
    }
    data_0217c814.mUnk_18 = a;
}

void func_02106580(void) {
    Unk0217c7f0 *q;
    NNSSndSeqPlayer **v;
    u32 a;
    s32 i;
    s32 b;
    s32 n;
    struct NNSSndArc *p;

    switch (data_0217c814.mUnk_0c) {
        case 1:
            data_0217c814.mUnk_00++;
            if (data_0217c814.mUnk_00 == 0x28) {
                func_0210d5c0(&data_0217d070);
                NNS_SndPlayerSetVolume(&data_0217d07c, data_0217d234.mUnk_04 >> 12);
            }
            q = &data_0217c7f0;
            i = q->mUnk_08;
            if (i == 1) {
                q->mUnk_00 = data_0217c80c[i];
                a = func_02110640(q, data_0217c7fc[i]);
                if (a != -1) {
                    b = data_0217c804[i];
                    if (func_0210d980() != 0) {
                        p = NNS_SndArcGetCurrent();
                        NNS_SndArcSetCurrent(&data_0217d0a0);
                        for (n = 1; n <= 7; n++) {
                            if (NNS_SndArcGetPlayerInfo(n) != NULL && ((b >> n) & 1) != 0) {
                                NNS_SndPlayerSetPlayerVolume(n, a);
                            }
                        }
                        NNS_SndArcSetCurrent(p);
                    }
                }
            }
            func_0210faf4();
            func_0210b610();
            break;
        case 2:
            func_02111024();
            break;
    }
    if (data_021759c0->mMode != MODE_BATTLE) {
        v = &data_0217d07c;
        if (func_0210f858() != 0) {
            func_0210f780(v);
            if (data_021759c0->mCourseId == COURSE_ID_TOWN) {
                if (func_0210f75c(0) != 0 || func_0210f75c(1) != 0) {
                    func_0210f35c(0, 0x1a9);
                }
            }
        }
        if (data_021759c0->mCourseId == COURSE_ID_KOOPA) {
            func_0210f230(0, 0x16b);
        }
        if (data_0217c814.mUnk_1c != -1) {
            if (++data_0217c814.mUnk_1c >= 0x3c) {
                data_0217c814.mUnk_1c = -1;
            }
        }
        if (data_0217c814.mUnk_16 == 1 && v[0] == NULL) {
            data_0217c814.mUnk_16 = 0;
            if (data_0217c7a8 != 0 && data_0217c814.mUnk_17 == 1) {
                if (data_0217c814.mUnk_0c == 1) {
                    data_0217c814.mUnk_17 = 1;
                    if ((data_0217c814.mUnk_16 & 1) == 0) {
                        NNS_SndPlayerSetTrackMuteEx(&data_0217d07c, 0xffff, 1);
                        func_0210d614(&data_0217d070, 0x49, &data_0217c81c);
                    }
                }
                data_0217c7a8 = 0;
                data_0217c78c = 1;
            } else if (data_0217c814.mUnk_08 != NULL) {
                NNS_SndPlayerSetTrackMuteEx(&data_0217c81c, 0xffff, 0);
                data_0217c78c = 1;
            } else if (data_0217c814.mUnk_0c == 1) {
                func_0210d5c0(&data_0217d070);
                NNS_SndPlayerSetVolume(&data_0217d07c, data_0217d234.mUnk_04 >> 12);
                NNS_SndPlayerSetTempoRatio(&data_0217d07c, 0x12c);
                func_0210faac();
            }
        }
    } else {
        func_0210add4();
    }
    data_0217d1f8 = data_0217d20c;
}

void func_021062a8(void) {
    u32 v;
    NNSSndSeqPlayer **p;

    v = 0xffff;
    switch (data_021759c0->mCourseId) {
        case COURSE_ID_STADIUM:
            if (data_0217c814.mUnk_04 == 0xa) {
                v = 0x1bc;
            }
            break;
        case COURSE_ID_RIDGE:
            if (data_0217c814.mUnk_04 == 0xa) {
                v = 0x1a6;
            }
            break;
        case COURSE_ID_GARDEN:
            if (data_0217c814.mUnk_04 == 0xa) {
                v = 0x1a5;
            }
            break;
        case COURSE_ID_MANSION:
            if (data_0217c814.mUnk_04 == 0xa) {
                v = 0x126;
            }
            break;
        case COURSE_ID_AIRSHIP:
            switch (data_0217c814.mUnk_04) {
                case 0xa:
                    v = 0x1d2;
                    break;
                case 0xa0:
                    NNS_SndPlayerStopSeq(&data_0217c854, 0x3c);
                    break;
                case 0x122:
                    v = 0x1d2;
                    break;
            }
            { break; }
        case COURSE_ID_KOOPA:
            if (data_0217c814.mUnk_04 == 0xa) {
                v = 0x1aa;
            }
            break;
        case COURSE_ID_CLOCK:
            if (data_0217c814.mUnk_04 == 0xa) {
                v = 0x192;
            }
            break;
        case COURSE_ID_MARIO:
            if (data_0217c814.mUnk_04 == 0xa) {
                v = 0x19b;
            }
            break;
        case COURSE_ID_OLD_NOKO_SFC:
            if (data_0217c814.mUnk_04 == 0xa) {
                v = 0x112;
            }
            break;
        case COURSE_ID_BEACH:
            if (data_0217c814.mUnk_04 == 0xa) {
                v = 0x112;
            }
            break;
        case COURSE_ID_OLD_MOMO_64:
            if (data_0217c814.mUnk_04 == 0xa) {
                v = 0x12b;
            }
            break;
        case COURSE_ID_OLD_HYUDORO_64:
            if (data_0217c814.mUnk_04 == 0xa) {
                v = 0x19a;
            }
            break;
        case COURSE_ID_OLD_LUIGI_AGB:
            if (data_0217c814.mUnk_04 == 0xa) {
                v = 0x1d5;
            }
            break;
        case COURSE_ID_RAINBOW:
            if (data_0217c814.mUnk_04 == 0x28) {
                v = 0x1ba;
            }
            break;
        case COURSE_ID_TOWN:
            if (data_0217c814.mUnk_04 == 0x28) {
                v = 0x199;
            }
            break;
    }
    if (v == 0xffff) {
        return;
    }
    NNS_SndPlayerStopSeq(&data_0217c854, 0);
    p = &data_0217c854;
    if ((data_0217c780 & 2) == 0) {
        return;
    }
    if (data_0217d084.mUnk_0c == 0) {
        return;
    }
    if (*p != NULL) {
        NNS_SndPlayerStopSeq(p, 0);
    }
    if (*p != NULL) {
        NNS_SndPlayerStopSeq(p, 0);
    }
    NNS_SndArcPlayerStartSeqArc(p, 0, v);
}

void func_021060dc(void) {
    Unk0217c7f0 *q;
    s32 i;
    s32 a;
    s32 b;
    s32 n;
    struct NNSSndArc *p;

    q = &data_0217c7f0;
    i = q->mUnk_08;
    if (i == 0) {
        q->mUnk_00 = data_0217c80c[i];
        a = func_02110640(q, data_0217c7fc[i]);
        if (a != -1) {
            b = data_0217c804[i];
            if (func_0210d980() != 0) {
                p = NNS_SndArcGetCurrent();
                NNS_SndArcSetCurrent(&data_0217d0a0);
                for (n = 1; n <= 7; n++) {
                    if (NNS_SndArcGetPlayerInfo(n) != NULL && ((b >> n) & 1) != 0) {
                        NNS_SndPlayerSetPlayerVolume(n, a);
                    }
                }
                NNS_SndArcSetCurrent(p);
            }
        }
    }
    if (GetCurrentSceneNumber() == 2) {
        switch (data_021759c0->mUnk_00c) {
            case 0:
            case 2:
                func_02106580();
                break;
            case 3:
            case 4:
                func_021062a8();
                break;
        }
    } else if (GetCurrentSceneNumber() == 9) {
        if (data_0217c814.mUnk_04 == 0x5d) {
            NNS_SndPlayerStopSeq(&data_0217d07c, 0x1b);
        }
    } else if (GetCurrentSceneNumber() == 1 || GetCurrentSceneNumber() == 0xc) {
        if (*(vu16 *) 0x027ffc40 != 2) {
            func_02110754();
        }
    } else if (GetCurrentSceneNumber() == 3) {
        func_02110874();
    }
    if (data_0217d060 != NULL && data_0217d060->mUnk_00.mUnk_00 == 0 && data_0217d060->mUnk_0c != NULL) {
        func_0210f780(&data_0217d060->mUnk_0c);
    }
    data_0217c814.mUnk_04++;
}

void func_02105fcc(void) {
    u32 v;
    s32 i;
    s32 j;
    u8 *q;

    if (*(vu16 *) 0x027ffc40 == 2 && GetCurrentSceneNumber() == 6) {
        return;
    }
    data_0217c7f0.mUnk_0c = 0;
    data_0217c7f0.mUnk_08 = 0;
    func_0210d58c(&data_0217d070);
    func_0210d9a0(&data_0217d084, 4);
    for (i = 0; i < 12; i++) {
        NNS_SndPlayerStopSeq(data_0217c838 + i, func_0210d960());
    }
    v = func_0210d960();
    for (j = 0, q = (&data_0217c7c4)->mUnk_0c; j < (&data_0217c7c4)->mUnk_00; j++) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) q, v);
        q += (&data_0217c7c4)->mUnk_10;
    }
    NNS_SndPlayerStopSeq(&data_0217c788, 13);
    NNS_SndPlayerStopSeq(&data_0217c778, 13);
    data_0217c7a4 = 0;
}

void func_02105ec0(void) {
    s32 i;
    s32 j;
    u8 *q;
    Unk0217c7c4 *p;

    if (*(vu16 *) 0x027ffc40 == 2 && GetCurrentSceneNumber() == 6) {
        return;
    }
    data_0217c7f0.mUnk_0c = 0;
    data_0217c7f0.mUnk_08 = 0;
    func_0210d570(&data_0217d070, 1);
    func_0210d9a0(&data_0217d084, 0);
    for (i = 0; i < 12; i++) {
        NNS_SndPlayerStopSeq(data_0217c838 + i, 0);
    }
    p = &data_0217c7c4;
    for (j = 0, q = p->mUnk_0c; j < p->mUnk_00; j++) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) q, 0);
        q += p->mUnk_10;
    }
    data_0217c7a4 = 0;
    NNS_SndPlayerStopSeq(&data_0217c788, 0);
    NNS_SndPlayerStopSeq(&data_0217c778, 0);
}

void func_02105e98(void) {
    u32 v1;
    v1 = func_0210d960();
    NNS_SndPlayerStopSeq(&data_0217d07c, v1);
}

void func_02105d70(void) {
    u32 x;
    s32 y;
    s32 j;
    u8 *v;
    s32 i;
    NNSSndSeqPlayer **p;
    Unk0217c7c4 *q;

    x = func_0210d960();
    data_0217c814.mUnk_20 = 1;
    func_0210d970(0xa);
    if (data_0217c7ac != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c7ac, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c7ac, 0, 0x11);
    if (data_0217c814.mUnk_0c == 2) {
        return;
    }
    func_0210d9a0(&data_0217d084, 5);
    if (data_0217c814.mUnk_16 == 1) {
        data_0217c814.mUnk_16 = 3;
    }
    p = data_0217c838;
    for (i = 0; i < 0xc; i++) {
        NNS_SndPlayerMoveVolume(p, 0, func_0210d960());
        p++;
    }
    y = func_0210d960();
    q = &data_0217c7c4;
    for (j = 0, v = q->mUnk_0c; j < q->mUnk_00; j++) {
        NNS_SndPlayerMoveVolume((NNSSndSeqPlayer **) v, 0, y);
        v += q->mUnk_10;
    }
    func_0210d970(x);
}

void func_02105c4c(void) {
    u32 x;
    s32 y;
    s32 j;
    u8 *v;
    s32 i;
    NNSSndSeqPlayer **p;
    Unk0217c7c4 *q;

    x = func_0210d960();
    data_0217c814.mUnk_20 = 0;
    func_0210d970(0xa);
    if (data_0217c7ac != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c7ac, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c7ac, 0, 0x12);
    if (data_0217c814.mUnk_0c == 2) {
        return;
    }
    func_0210dc50(&data_0217d084);
    if (data_0217c814.mUnk_16 == 3) {
        data_0217c814.mUnk_16 = 1;
    }
    p = data_0217c838;
    for (i = 0; i < 0xc; i++) {
        NNS_SndPlayerMoveVolume(p, 0x7f, func_0210d960());
        p++;
    }
    y = func_0210d960();
    q = &data_0217c7c4;
    for (j = 0, v = q->mUnk_0c; j < q->mUnk_00; j++) {
        NNS_SndPlayerMoveVolume((NNSSndSeqPlayer **) v, 0x7f, y);
        v += q->mUnk_10;
    }
    func_0210d970(x);
}

void func_02105b64(s32 a) {
    u32 x;
    s32 j;
    u8 *v;
    s32 i;
    NNSSndSeqPlayer **p;
    Unk0217c7c4 *q;
    u32 h;

    h = data_0215a6d8[a];
    if (data_0217c7ac != NULL) {
        NNS_SndPlayerStopSeq(&data_0217c7ac, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217c7ac, 0, h);
    if (a == 4) {
        return;
    }
    p = data_0217c838;
    for (i = 0; i < 0xc; i++) {
        NNS_SndPlayerStopSeq(p, func_0210d960());
        p++;
    }
    x = func_0210d960();
    q = &data_0217c7c4;
    for (j = 0, v = q->mUnk_0c; j < q->mUnk_00; j++) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) v, x);
        v += q->mUnk_10;
    }
    func_0210d9a0(&data_0217d084, 4);
}

void func_02105b48(void) {
    NNS_SndPlayerStopSeqAll(func_0210d960());
}

void func_02105b28(NNSSndSeqPlayer **a, u32 b) {
    NNS_SndPlayerSetTrackVolume(a, data_0216cb20, (u8) b);
}

void func_02105b0c(NNSSndSeqPlayer **a, u32 b) {
    NNS_SndPlayerSetTrackPitch(a, data_0216cb20, b);
}

void func_02105ac0(s32 a) {
    if (data_0217c794 != 0) {
        return;
    }
    data_0217c794 = 1;
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, a);
}

void func_02105a30(u32 a) {
    s32 r;

    data_0217c784 = a;
    if (a - 1 > 1) {
        return;
    }
    r = (a == 1) ? 0x47 : 0x48;
    NNS_SndHeapLoadState(data_0217d130, data_0217c798[0]);
    NNS_SndHeapGetCurrentLevel(data_0217d130);
    NNS_SndArcLoadSeq(r, data_0217d130);
    NNS_SndPlayerStopSeq(&data_0217d07c, 2);
    func_0210d7dc(r, 0x7f, &data_0217c83c);
}

void func_021059e0(void) {
    if (data_0217d070.mUnk_0c != NULL) {
        return;
    }
    if (data_0217c838[1] != NULL) {
        return;
    }
    func_0210d5c0(&data_0217d070);
}

void func_02105980(int a, u32 b) {
    if (data_0217c784 - 1 <= 1) {
        NNS_SndPlayerStopSeq(&data_0217c83c, b);
    }
    if (a == 3) {
        NNS_SndPlayerStopSeq(&data_0217d07c, b);
        return;
    }
}

void func_0210593c(u32 a) {
    if (a != 4) {
        return;
    }
    if (data_0217d070.mUnk_0c != NULL) {
        return;
    }
    func_0210d5c0(&data_0217d070);
}

void func_021057f0(u32 a, u32 b) {
    u32 r = 0xff;
    data_0217c784 = a;
    data_0217c79c = 0;
    data_0217c7a0 = 0;
    data_0217c774 = 0xff;
    if (a != 3) {
        return;
    }
    switch (b) {
        case 1:
            data_0217c774 = 1;
            r = 0x25;
            break;
        case 2:
            data_0217c774 = 2;
            r = 0x26;
            break;
        case 3:
            data_0217c774 = 3;
            r = 0x27;
            break;
        case 4:
            data_0217c774 = 4;
            r = 0x28;
            break;
        case 5:
            data_0217c774 = 5;
            r = 0x29;
            break;
        case 6:
            data_0217c774 = 6;
            r = 0x25;
            break;
        case 7:
            data_0217c774 = 7;
            r = 0x17;
            break;
    }
    NNS_SndHeapLoadState(data_0217d130, data_0217c798[0]);
    NNS_SndHeapGetCurrentLevel(data_0217d130);
    NNS_SndArcLoadBank(r, data_0217d130);
    NNS_SndArcLoadBank(0x2a, data_0217d130);
    NNS_SndArcLoadSeqArc(4, data_0217d130);
}

void func_021055b0(s32 a) {
    s32 v;
    u32 f;
    s32 n;
    if (data_0217c784 == 0) {
        if (data_0217d070.mUnk_0c != NULL) {
            return;
        }
        func_0210d5c0(&data_0217d070);
        return;
    }
    if (a != 0 && a != 0x32) {
        return;
    }
    f = 0;
    v = 0x78;
    n = (a == 0x32) ? data_0217c79c : data_0217c7a0;
    if (n < 5) {
        switch (n) {
            case 0:
                v = 0xf;
                break;
            case 1:
                v = 0x1e;
                f = 1;
                break;
            case 2:
                v = 0x2d;
                break;
            case 3:
                v = 0x46;
                break;
            case 4:
                v = 0x2d;
                break;
        }
    } else {
        switch ((n - 5) % 6) {
            case 0:
                v = 0x1e;
                break;
            case 1:
                v = 0x2d;
                break;
            case 2:
                v = 0x46;
                break;
            case 3:
                v = 0x5f;
                f = 1;
                break;
            case 4:
                v = 0x46;
                break;
            case 5:
                v = 0x2d;
                break;
        }
    }
    if (a == 0x32) {
        NNSSndSeqPlayer **p = &data_0217c83c;
        if (*p != NULL) {
            NNS_SndPlayerStopSeq(p, 0);
        }
        NNS_SndArcPlayerStartSeqArc(p, 4, 0);
        if (*p != NULL) {
            NNS_SndPlayerSetTrackVolume(p, data_0216cb20, v & 0xff);
        }
        data_0217c79c++;
        return;
    }
    if (a != 0) {
        return;
    }
    if (f != 0) {
        u16 h = data_0217c774;
        if (h != 0xff) {
            NNSSndSeqPlayer **p = &data_0217c840;
            if (*p != NULL) {
                NNS_SndPlayerStopSeq(p, 0);
            }
            NNS_SndArcPlayerStartSeqArc(p, 4, h);
        }
    }
    data_0217c7a0++;
}

void func_02105584(u32 a, u32 b) {
    NNS_SndPlayerStopSeq(&data_0217c83c, b);
    NNS_SndPlayerStopSeq(&data_0217c840, b);
}

void func_02105550(void) {
    NNS_SndPlayerStopSeq(&data_0217c83c, 0);
    NNS_SndPlayerStopSeq(&data_0217c840, 0);
}
