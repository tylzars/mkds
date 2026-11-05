#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020646f0.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_02075000.h"
#include "Main/Unknown/code_02087cfc.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_0206390c.h"
#include "Main/Unknown/code_02040de0.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_0208c4e8.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020a128c.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210ab30.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_0210fb10.h"
#include "Main/Unknown/code_0210fb54.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_021112fc.h"
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
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02154000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_0203c5f8.h"

void func_02068b98(Kart *a) {
    u32 b;
    s32 c;
    BOOL d;
    vu32 *e;
    u32 f;
    vu32 *h;
    s32 g;
    Vec3 *k;

    b = a->mUnk_7c;
    if ((b & 0x40) != 0) {
        if ((b & 0x40000) == 0) {
            return;
        }
        if ((b & 0x800000) != 0) {
            return;
        }
    }
    c = a->mUnk_3c8;
    if (c >= 0x19 || (b & KART_7C_ENTRY_KIND_2) != 0) {
        d = FALSE;
        if (data_021759c0->mMode == MODE_BATTLE) {
            if (func_020a128c() != 0) {
                d = TRUE;
            }
        }
        a->mUnk_7c = a->mUnk_7c | 0x40;
        e = &a->mUnk_7c;
        f = *e;
        if ((f & 0x800006) == 0 && d == FALSE && (f & 0x40000) != 0) {
            if (a->mUnk_3c8 >= 0xb9) {
                *e = *e | 0x80000;
                func_02063ad0(a);
                k = data_021759c0->mMode == 5 ? &a->mUnk_1d8 : &a->mUnk_1b8;
                if (a->mUnk_2c8 == -1) {
                    a->mUnk_2c8 = func_020d555c(k, a->mPhysicalParam->mRadius + 0xd000, 0x8000, a);
                }
                if (a->mUnk_2ca == -1) {
                    c = a->mPhysicalParam->mRadius;
                    a->mUnk_2ca = func_020d555c(&a->mUnk_1f0, (s32) ((s64) c << 15 >> 12), 0x800, a);
                }
                h = &a->mUnk_7c;
                a->mUnk_7c = a->mUnk_7c & 0xdfffff9f;
                a->mUnk_7c = a->mUnk_7c | 0x400000;
                if ((a->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) == 0) {
                    *h = *h | 0x1000000;
                }
                if ((a->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
                    a->mUnk_7c = a->mUnk_7c | 0x4000;
                } else {
                    a->mUnk_7c = a->mUnk_7c | 0x8000;
                }
                func_02104f84(a->mIndex);
                if ((a->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
                    func_0210fb10();
                }
                func_0210ab30(a);
                return;
            }
            if ((f & 1) != 0) {
                c = a->mUnk_3c8;
                if (c == 0x70) {
                    func_02055a94();
                } else if (c == 0x73) {
                    func_02055c18(0x3c);
                    func_0210fb54();
                }
            }
            a->mUnk_3c8 = a->mUnk_3c8 + 1;
            return;
        }
        a->mPos.x = 0x1000000;
        a->mPos.y = 0xff000000;
        a->mPos.z = 0x1000000;
        a->mScale = data_02154f94;
    } else {
        g = 0x18 - c;
        a->mScaleFactor.x = data_usa_02154de4[g];
        a->mScaleFactor.y = data_usa_02154e48[g];
        a->mScaleFactor.z = data_usa_02154eac[g];
        a->mScale.x = (s32) ((s64) a->mScaleBase.x * a->mScaleFactor.x >> 12);
        a->mScale.y = (s32) ((s64) a->mScaleBase.y * a->mScaleFactor.y >> 12);
        a->mScale.z = (s32) ((s64) a->mScaleBase.z * a->mScaleFactor.z >> 12);
        a->mScale.y = (s32) ((s64) a->mScaleYFactor * a->mScale.y >> 12);
        a->mUnk_3c8 = a->mUnk_3c8 + 1;
    }
}

void func_02068b5c(Kart *a) {
    if ((a->mUnk_7c & 0x40000) != 0) {
        return;
    }
    a->mUnk_7c = a->mUnk_7c | 0x40000;
    func_02068ec0(a, 0);
}

void func_02068a64(Kart *a, s32 b, s32 c) {
    u32 d;
    u32 j;
    Unk0206bcb0_590 *e;
    BOOL h;
    BOOL i;
    s32 *f;
    s32 g;

    d = a->mUnk_7c;
    if ((d & KART_7C_MODELS_ENTRY_008_SET) != 0) {
        e = a->mKartModelsEntry;
        h = FALSE;
        f = &e->mUnk_024;
        g = e->mUnk_008->mUnk_1a;
        i = TRUE;
        if (f[5] != 0) {
            if (g != 0) {
                func_02087cfc(e->mUnk_008, (u16) g, 1);
            }
            f[5] = 0;
        }
        if (b == 1) {
            b = 1;
            h = TRUE;
        } else {
            j = a->mUnk_7c;
            if ((j & 0x10000) != 0) {
                if (g == b) {
                    i = FALSE;
                }
                b = 2;
            } else if ((j & 0x20000) != 0) {
                if (g == b) {
                    i = FALSE;
                }
                b = 3;
                h = TRUE;
            }
        }
        if (i != FALSE) {
            func_0207b6c0(a->mKartModelsEntry, b, c);
        }
        func_0207b708(a->mKartModelsEntry, h);
    } else {
        h = FALSE;
        if (b == 1 || (d & 0x20000) != 0) {
            h = TRUE;
        }
        func_0207b708(a->mKartModelsEntry, h);
    }
}

void func_02068a10(Kart *a) {
    if ((a->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) != 0) {
        func_0207b054(a, 1, 0);
        func_0207b708(a->mKartModelsEntry, 1);
    }
    if ((a->mUnk_48 & 0x840) != 0) {
        return;
    }
    func_0210af40(a, a->mUnk_3cc, 0);
}

void func_02068a00(Kart *a) {
    func_0210ad58(a, a->mUnk_3cc);
}

void func_020688a0(Kart *a) {
    s32 b;
    u32 c;
    u32 d;

    if ((a->mUnk_7c & 0x10000000) != 0) {
        return;
    }
    a->mUnk_7c = a->mUnk_7c | 0x10000008;
    a->mUnk_48 = a->mUnk_48 | 0x2000;
    if ((a->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
        if (IsKartEnded((u16) data_021759c0->mEntryIndex) != 0) {
            b = gRaceProgress->mUnk_4e0;
        } else {
            b = 6;
        }
        switch (b) {
            case 0:
                StartEntryCameraKind8Entry();
                func_02068494(a, 1, 1);
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            default:
                if ((a->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
                    if (data_021759c0->mMode == MODE_MISSION_RUN) {
                        func_020a16d0(a->mIndex);
                    }
                    a->mUnk_7c = a->mUnk_7c | 0x20000;
                    func_02068a64(a, 3, 1);
                }
                break;
        }
        if (data_021759c0->mMode == MODE_MISSION_RUN) {
            func_020a12b8();
        }
    }
    c = a->mUnk_7c;
    if ((c & KART_7C_INDEX_IS_SELECTED_ENTRY) == 0) {
        return;
    }
    if (data_021759c0->mMode == MODE_BATTLE || data_021759c0->mMode == MODE_MISSION_RUN) {
        d = 1;
        if ((c & 0x10000) != 0) {
            d = 0;
        } else if ((c & 0x20000) != 0) {
            d = 2;
        }
        func_021112fc(d);
    }
}

void func_02068640(Kart *a, s32 b) {
    Vec3 c;
    Vec3 e;
    Vec3 d;
    Vec3 *f;
    s32 g;
    u32 h;
    u32 i;
    vu32 *k;

    if ((a->mUnk_7c & 0x100000) != 0) {
        return;
    }
    func_020fa9e4();
    if (b != 0) {
        a->mUnk_7c = a->mUnk_7c | 0x2000000;
    }
    a->mUnk_7c = a->mUnk_7c | 0x100100;
    a->mUnk_7c = a->mUnk_7c | 8;
    a->mUnk_48 = a->mUnk_48 | 0x2000;
    a->mUnk_7c = a->mUnk_7c & 0xffbf1fff;
    if ((a->mUnk_7c & 0x20) != 0) {
        GetCourseMapKartStartPlacement(&c, &d, a->mIndex);
        a->mHeadingAngle = (u32) (d.y * 0xb6) >> 12;
        QuaternionFromAxisAngle(&data_02154f7c, a->mHeadingAngle, &a->mUnk_e0_m);
        func_01ffcd84(&a->mUnk_120, &a->mUnk_e0_m);
        GetKartForward(a, &e);
        ResetKartAndSetPos(a, &c, &e, NULL);
        f = data_021759c0->mMode == 5 ? &a->mUnk_1d8 : &a->mUnk_1b8;
        if (a->mUnk_2c8 == -1) {
            a->mUnk_2c8 = func_020d555c(f, a->mPhysicalParam->mRadius + 0xd000, 0x8000, a);
        }
        if (a->mUnk_2ca == -1) {
            g = a->mPhysicalParam->mRadius;
            a->mUnk_2ca = func_020d555c(&a->mUnk_1f0, (s32) ((s64) g << 15 >> 12), 0x800, a);
        }
        a->mUnk_7c = a->mUnk_7c | 0x80;
        a->mUnk_7c = a->mUnk_7c & ~0x60;
        a->mScale = data_02154f94;
    }
    k = &a->mUnk_7c;
    a->mUnk_7c = a->mUnk_7c & ~0x80;
    if ((a->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) == 0) {
        *k = *k | 0x40;
    } else {
        StartEntryCameraKind6Entry();
    }
    func_02068494(a, 0, b);
    h = a->mUnk_7c;
    if ((h & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
        if (data_021759c0->mMode == MODE_BATTLE || data_021759c0->mMode == MODE_MISSION_RUN) {
            i = 1;
            if ((h & 0x10000) != 0) {
                i = 0;
            } else if ((h & 0x20000) != 0) {
                i = 2;
            }
            func_021112fc(i);
        }
    }
    if ((a->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) == 0) {
        return;
    }
    func_0210ab48(a->mUnk_3cc, b);
}

void func_02068494(Kart *a, s32 b, s32 c) {
    Unk02068494 d;
    s32 i;
    BOOL j;
    CourseMap *k;

    i = a->mForwardSpeed;
    d.mUnk_04 = a->mPos;
    if (b != 0) {
        k = gCourseMap;
        if (k->mUnk_3c == NULL) {
            j = FALSE;
        } else {
            d.mUnk_10 = k->mUnk_3c->mUnk_00;
            d.mUnk_1c = k->mUnk_3c->mUnk_0c;
            d.mUnk_00 = k->mUnk_3c->mUnk_1a;
            j = TRUE;
        }
        if (j == FALSE) {
            return;
        }
    }
    func_02072930(a);
    func_02079c0c(a->mKartModelsEntry);
    a->mUnk_210(a);
    a->mUnk_7c = a->mUnk_7c & ~0xe000;
    func_02103890(a->mIndex);
    func_020646f0(a, b);
    a->mPos.y = a->mPos.y - 0x1000;
    if (b != 0) {
        if (d.mUnk_00 != 0) {
            a->mForwardSpeed = i;
            a->mUnk_48 = a->mUnk_48 | 0x2000;
        }
    }
    a->mUnk_44 = a->mUnk_44 | 0x10;
    if ((a->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) != 0) {
        if (c != 0) {
            a->mUnk_7c = a->mUnk_7c | 0x10000;
            func_02068a64(a, 2, 1);
        } else {
            a->mUnk_7c = a->mUnk_7c | 0x20000;
            func_02068a64(a, 3, 1);
        }
    }
    if (data_021759c0->mMode == MODE_BATTLE) {
        Vec3Sub(&a->mPos, &d.mUnk_04, &d.mUnk_28);
        func_020a21bc(a->mIndex, (s32) &d.mUnk_28);
    }
    if ((a->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) == 0) {
        return;
    }
    func_02055bd4(0);
    func_020e79c4();
}

void func_02068440(Kart *a, s32 b) {
    Unk0208c5b8 *c;

    a->mUnk_2fc = b;
    if (a->mUnk_2fc != 2) {
        return;
    }
    c = func_0208c5b8(a->mIndex);
    func_0208c884(c, (a->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) != 0 ? 1 : 0);
    StartSound(&a->mSoundSource, 0xd2, 0x7f, 0);
}

void func_020681f0(Kart *a) {
    Unk0208c5b8 *b;
    u16 *c;
    u16 *d;
    u32 e;
    enum { K0 } k;

    if ((a->mUnk_7c & 0x402) == 0) {
        if (a->mUnk_2fc >= 3) {
            return;
        }
        a->mUnk_30c = a->mUnk_30c - 1;
        if (a->mUnk_30c > 0) {
            return;
        }
        k = a->mEntryIndex;
        e = data_02175628[k].mUnk_00;
        if ((u16) (e & 0x20) != 0) {
            c = &a->mUnk_300;
            if (a->mUnk_304 == c) {
                if (c[1] == c[0]) {
                    c[0]++;
                    a->mUnk_30c = 10;
                }
            } else if (c[1] > c[0]) {
                c[0]++;
                a->mUnk_2fc = a->mUnk_2fc + 1;
                a->mUnk_30c = 10;
                if (a->mUnk_2fc == 2) {
                    b = func_0208c5b8(a->mIndex);
                    func_0208c884(b, (a->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) != 0 ? 1 : 0);
                    StartSound(&a->mSoundSource, 0xd2, 0x7f, 0);
                }
            }
        } else if ((u16) (e & 0x10) != 0) {
            d = &a->mUnk_302;
            if (a->mUnk_308 == d) {
                c = &a->mUnk_300;
                if (c[0] > c[1]) {
                    d[0] = d[0] + 1;
                    a->mUnk_2fc = a->mUnk_2fc + 1;
                    a->mUnk_30c = 10;
                    if (a->mUnk_2fc == 2) {
                        b = func_0208c5b8(a->mIndex);
                        func_0208c884(b, (a->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) != 0 ? 1 : 0);
                        StartSound(&a->mSoundSource, 0xd2, 0x7f, 0);
                    }
                }
            } else {
                c = &a->mUnk_300;
                if (c[1] == c[0]) {
                    d[0] = d[0] + 1;
                    a->mUnk_30c = 10;
                }
            }
        }
    }
    if (a->mUnk_2fc != 3) {
        return;
    }
    b = func_0208c5b8(a->mIndex);
    if ((a->mUnk_4c & 0x8000) != 0) {
        func_0208d650(b);
        func_0208c520(b);
        func_0208cacc(b, (a->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) != 0 ? 1 : 0);
    } else {
        func_0208c534(func_0208c5b8(a->mIndex));
    }
    a->mUnk_2fc = a->mUnk_2fc + 1;
}
