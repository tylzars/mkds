#include "Main/Unknown/code_02066ac0.h"
#include "Main/Unknown/code_020435c4.h"

#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_02068eac.h"
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
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_02075000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_020172d0.h"
#include "code_0212df7c.h"
#include "code_02147288.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02081120.h"
#include "Main/Unknown/code_0206d020.h"

s32 func_02067bf4(Kart *a, s32 *b) {
    *b = 0xc;
    a->mUnk_48 &= 0xdfe77fdf;
    a->mUnk_238 = 0;
    a->mUnk_538.mUnk_00 = 0;
    a->mUnk_23c = 0;
    if ((a->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
        if ((a->mUnk_4c & 0x10000000) == 0 && (a->mUnk_48 & 0x4000000) == 0) {
            ResetCameraHalfFovAngleGoal();
        }
        func_02055c5c();
    }
    a->mForwardSpeed = 0;
    return 5;
}

s32 func_02067b60(Kart *a, s32 *b) {
    *b = 0xc;
    a->mUnk_48 &= 0xdfe77fdf;
    a->mUnk_238 = 0;
    a->mUnk_538.mUnk_00 = 0;
    a->mUnk_23c = 0;
    if ((a->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
        if ((a->mUnk_4c & 0x10000000) == 0 && (a->mUnk_48 & 0x4000000) == 0) {
            ResetCameraHalfFovAngleGoal();
        }
        func_02055c5c();
    }
    if (func_0206bcb0(a, 1, 0) != FALSE) {
        func_02081224(a->mIndex);
    }
    return 5;
}

s32 func_02067b0c(Kart *a, s32 *b, s32 c) {
    if (func_0206a24c(a) != FALSE && a->mUnk_44c != (struct MapObject *) c &&
        (a->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
        func_0207a6b0()->mUnk_14++;
    }
    *b = 0;
    return 0;
}

s32 func_02067ad4(Kart *p) {
    func_02083f6c((u16) data_usa_02154a84[p->mSurfaceVariant], p);
    return 0;
}

s32 func_02067a9c(Kart *p) {
    func_02083f6c((u16) data_usa_02154ac4[p->mSurfaceVariant], p);
    return 0;
}

s32 func_02067a64(Kart *p) {
    func_02083f6c((u16) data_usa_02154ae4[p->mSurfaceVariant], p);
    return 5;
}

s32 func_02067a2c(Kart *p) {
    func_0207a6c0(p);
    func_02083f6c((u16) data_usa_02154b24[p->mSurfaceVariant], p);
    return 2;
}

s32 func_020679f4(Kart *a) {
    func_0207a6c0(a);
    func_02083f6c((u16) data_02154b44[a->mSurfaceVariant], a);
    return 3;
}

s32 func_020679bc(Kart *a) {
    func_0207a6c0(a);
    func_02083f6c((u16) data_02154bc4[a->mSurfaceVariant], a);
    return 4;
}

s32 func_02067984(Kart *a) {
    func_02083f6c((u16) data_02154a64[a->mSurfaceVariant], a);
    return 6;
}

s32 func_020678d4(Kart *a) {
    Unk02165518 b;
    Unk0210bf24 *c;

    if (a->mSurfaceGroup != 8 || (a->mUnk_44 & 0x80000000) != 0) {
        func_0206d020(a, 0, 0x3c);
        b = data_02165518;
        if (a->mSurfaceVariant > 0 && (a->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
            c = func_021090c4(&a->mUnk_00, b.mUnk_00[a->mSurfaceVariant - 1], 0x7f, 0);
            if (c != NULL) {
                c->mUnk_19 = c->mUnk_19 | 0x10;
            }
        }
    } else {
        a->mUnk_238 = 0x3c;
    }
    func_020839d8(a);
    return 8;
}

s32 func_02067834(Kart *a) {
    if (a->mSurfaceGroup != 8 || (a->mUnk_44 & 0x80000000) != 0) {
        if (data_021759c0->mCourseId == 0xc || data_021759c0->mCourseId == 0x28) {
            func_021090c4(&a->mUnk_00, 0x15e, 0x7f, 0);
        }
    }
    a->mUnk_48 = a->mUnk_48 | 0x10000000;
    a->mUnk_260 = data_021655b0[a->mSurfaceVariant];
    a->mUnk_4c4 = data_0216559c[a->mSurfaceVariant];
    func_020839d8(a);
    return 8;
}

s32 func_02067778(Kart *a) {
    Unk02165518 b;
    Unk0210bf24 *c;

    if (a->mSurfaceGroup != 8 || (a->mUnk_44 & 0x80000000) != 0) {
        func_0206d020(a, 0, 0x3c);
        b = data_02165518;
        if (a->mSurfaceVariant > 0 && (a->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
            c = func_021090c4(&a->mUnk_00, b.mUnk_00[a->mSurfaceVariant - 1], 0x7f, 0);
            if (c != NULL) {
                c->mUnk_19 = c->mUnk_19 | 0x10;
            }
        }
    } else {
        a->mUnk_238 = 0x3c;
    }
    func_020839d8(a);
    a->mUnk_48 = a->mUnk_48 | 0x400000;
    return 8;
}

s32 func_020676fc(Kart *a) {
    u16 b;

    func_02083f6c(0, a);
    if ((a->mUnk_48 & 0x10000) == 0) {
        b = a->mSurfaceVariant;
        if (data_021759c0->mMode == 2 || data_021759c0->mMode == 4) {
            func_020705fc(a, b);
        } else {
            a->mUnk_48 = a->mUnk_48 | 0x10000;
            func_020710b0(a, 0);
        }
    }
    return 9;
}

s32 func_020676c4(Kart *a) {
    func_02083f6c((u16) data_02154aa4[a->mSurfaceVariant], a);
    return 0xa;
}

s32 func_02067630(Kart *a) {
    Unk0210bf24 *b;

    if (a->mSurfaceGroup != 0xb || (a->mUnk_44 & 0x80000000) != 0) {
        func_0206d020(a, 0, 0x3c);
        if ((a->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
            b = func_021090c4(&a->mUnk_00, 0x1b9, 0x7f, 0);
            if (b != NULL) {
                b->mUnk_19 = b->mUnk_19 | 0x10;
            }
        }
    } else {
        a->mUnk_238 = 0x3c;
    }
    a->mUnk_48 = a->mUnk_48 | 0x40000001;
    func_020839d8(a);
    return 0xb;
}

s32 func_020675f8(Kart *a) {
    func_02083f6c((u16) data_02154b04[a->mSurfaceVariant], a);
    return 0;
}

u32 func_020675b4(Kart *a) {
    Unk0208c5b8 *b;
    u32 c;

    b = func_0208c5b8(a->mIndex);
    if (b->mUnk_34 != FALSE) {
        c = 0;
    } else {
        c = b->mUnk_38;
    }
    return (b->mUnk_40 | (b->mUnk_3c | c)) != 0 ? 1 : 0;
}

void func_02067488(Kart *a) {
    Vec3 b;
    Kart *c;
    u32 d;

    d = a->mUnk_7c;
    if ((d & 2) == 0) {
        return;
    }
    if ((d & 0x200000) != 0) {
        return;
    }
    if (func_02061fec() != 1) {
        return;
    }
    if (gCourseMap->mUnk_70 == 0 && gCourseMap->mUnk_90 == 0) {
        return;
    }
    func_0208c218(a->mUnk_310);
    if (a->mIndex != func_02061f90()) {
        return;
    }
    if (data_021759c0->mMode != 0) {
        return;
    }
    c = GetKart(data_021759c0->mEntryIndex);
    Vec3Sub(&a->mPos, &c->mPos, &b);
    b.x = b.x >> 12;
    b.y = b.y >> 12;
    b.z = b.z >> 12;
    if (b.x * b.x + b.y * b.y + b.z * b.z > 0x271000) {
        a->mUnk_48 = a->mUnk_48 | 0x8000000;
    } else {
        a->mUnk_48 = a->mUnk_48 & ~0x8000000;
    }
}

void func_02066fe0(Kart *a) {
    Unk021759c0 *p;
    CourseMap *q;
    Unk021759c0_70 *b;
    u32 c;
    s32 d;
    u16 i;
    s32 e;
    Unk0206ceb4 *f;
    u32 g;

    if ((a->mUnk_7c & 0x1000) != 0) {
        return;
    }
    a->mUnk_7c = a->mUnk_7c | 0x1000;
    if ((a->mUnk_7c & 0x400) == 0) {
        q = gCourseMap;
        if ((q->mUnk_70 != 0 || q->mUnk_90 != 0) && IsKartEnded(a->mIndex) != 0) {
            p = data_021759c0;
            i = a->mIndex;
            b = &p->mCurrentEntries[i].mPlayer;
            c = 0;
            if ((u32) b->mKind <= 3 && ((1 << b->mKind) & 0xd) != 0) {
                c = 1;
            }
            if (c != 0) {
                c = a->mUnk_7c;
                if ((c & 6) == 0 && (c & 8) == 0) {
                    data_02175664[a->mEntryIndex].mSourceKind = 3;
                    if (gRaceProgress->mUnk_000[a->mIndex].mStatus == 1) {
                        func_0208c260(a->mUnk_310, a->mIndex);
                        a->mUnk_7c = a->mUnk_7c | 2;
                        if ((a->mUnk_7c & 2) != 0) {
                            for (i = 0; i < 12; i++) {
                                if (i != 0) {
                                    a->mPhysicalParam->mUnk_38[i] = a->mPhysicalParam->mUnk_38[i] << 2;
                                    if (a->mPhysicalParam->mUnk_38[i] > a->mPhysicalParam->mUnk_38[0]) {
                                        a->mPhysicalParam->mUnk_38[i] = a->mPhysicalParam->mUnk_38[0];
                                    }
                                }
                            }
                        }
                    } else {
                        a->mUnk_7c = a->mUnk_7c | 8;
                    }
                }
            } else if (p->mUnk_1c == 1 && gRaceProgress->mUnk_000[a->mIndex].mStatus != 1) {
                a->mUnk_7c = a->mUnk_7c | 0x200000;
            } else if (p->mMode == 4) {
                a->mUnk_7c = a->mUnk_7c | 0x200000;
                a->mUnk_48 = a->mUnk_48 | 0x2000;
            }
            if ((a->mUnk_7c & KART_7C_ENTRY_KIND_2) != 0) {
                func_02068ec0(a, 0);
            }
        }
    }
    func_0207b44c(a);
    func_02103890(a->mIndex);
    func_02081768(a->mIndex);
    if ((a->mUnk_4c & 0x40) != 0) {
        a->mUnk_4c = a->mUnk_4c & ~0x40;
        func_0207b1a8(a);
        a->mUnk_29c = 0;
        func_020817b8(a->mIndex);
        func_02068a64(a, 0, 1);
        if ((a->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0 && data_021759c0->mUnk_00c == 0) {
            func_02106dc8();
        }
        if ((a->mUnk_4c & 0x2000) != 0) {
            func_0207b13c(a);
        }
    }
    f = &a->mUnk_538;
    if ((a->mUnk_4c & 0x10000000) != 0 && f->mUnk_24 == FALSE) {
        f->mUnk_24 = TRUE;
        if ((a->mUnk_7c & 0x200) != 0) {
            a->mUnk_514->mUnk_2c ^= 0x200000;
        }
    }
    if ((a->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
        func_020617d8();
        p = data_021759c0;
        if (p->mMode != 0 && p->mMode != 1 &&
            ((p->mUnk_1c == 1 && gRaceProgress->mUnk_000[a->mIndex].mStatus != 1) ||
             ((i = p->mKartCount) > 1 && (c = GetKartRank(a->mIndex), c == i)))) {
            func_02075cf0();
        } else {
            func_02075eb8();
            func_02081f30();
        }
    } else if (data_021759c0->mMode == 3 || data_021759c0->mMode == 5) {
        if (gRaceProgress->mUnk_000[a->mIndex].mStatus == 1) {
            e = 0;
            if (func_020617a8((u32 *) &e) != 0 && (u32) e > 0xb4) {
                func_0212ecc0(&data_0217d068, 0, 0x45);
            }
        }
    }
    p = data_021759c0;
    if (p->mMode == 2) {
        return;
    }
    g = 1;
    if (data_0217d084.mUnk_04 != 2 && data_0217d084.mUnk_04 != 3) {
        g = 0;
    }
    if (g == 0) {
        return;
    }
    if (a->mIndex == p->mEntryIndex) {
        c = func_02110e58();
        switch (c) {
            case 0:
                d = 9;
                break;
            case 1:
                d = 0xa;
                break;
            case 2:
                d = 0xb;
                break;
        }
        func_0210b198(a->mUnk_3cc, d, 0x6e, 7, -1);
        return;
    }
    d = func_02110fb8(GetKartRank(a->mIndex));
    if ((a->mUnk_48 & 0x840) != 0) {
        return;
    }
    func_0210af40(a, a->mUnk_3cc, d);
}

void func_02066de8(Kart *a) {
    Unk02012f58 b;
    s32 c;
    s32 d;
    u16 e;
    s32 f;

    a->mUnk_5a0 = a->mUnk_5a0 + data_021654c8;
    a->mUnk_5a4 = gPairsByAngle[(a->mUnk_5a0 >> 4) * 2];
    if (a->mUnk_594 > 0) {
        a->mUnk_594 = (s64) a->mUnk_594 * data_021654fc + 0x800 >> 12;
        a->mUnk_594 = a->mUnk_594 - 0x64;
        if ((a->mUnk_44 & 0x10) == 0 || (a->mForwardSpeed > 0 ? a->mForwardSpeed : -a->mForwardSpeed) < 0x3000) {
            a->mUnk_594 = (s64) a->mUnk_594 * 0xe66 + 0x800 >> 12;
        }
        if (a->mUnk_594 < 0) {
            a->mUnk_594 = 0;
        }
    }
    f = a->mUnk_598 * a->mUnk_594 - a->mUnk_59c;
    a->mUnk_59c = a->mUnk_59c + (s32) ((s64) f * data_021654f8 + 0x800 >> 12);
    c = (s64) a->mUnk_59c * data_021654cc + 0x800 >> 12;
    d = (s64) c * a->mUnk_5a4 + 0x800 >> 12;
    e = d;
    Matrix4x3FromPairY(&b, gPairsByAngle[(e >> 4) * 2], gPairsByAngle[(e >> 4) * 2 + 1]);
    Matrix4x3Multiply(&b, &a->mUnk_150_m, &a->mUnk_184_m);
    if ((a->mUnk_59c > 0 ? a->mUnk_59c : -a->mUnk_59c) >= 0x29) {
        return;
    }
    a->mUnk_4c = a->mUnk_4c & ~0x2000000;
    a->mUnk_5a0 = 0;
    a->mUnk_5a4 = 0;
    a->mUnk_594 = 0;
    a->mUnk_598 = 0;
}

void func_02066ac0(Kart *a) {
    Unk0206bcb0_514 *b;
    Unk02066ac0 *c;
    Unk0206bcb0_514 *e;
    Unk0217aa14_104 *f;
    Unk020653d0 *g;
    s32 i;
    s32 j;
    s16 k;
    u32 h;
    Unk02066ac0 *m;
    Unk02066ac0 *n;

    b = a->mUnk_514;
    j = 0;
    h = func_0205b954(((u8 *) data_0217aa18)[a->mIndex & 0xff]);
    b->mUnk_24 = func_02061fec() == 1 ? 0x333 : j;
    if (h > b->mUnk_20) {
        f = func_0205b978(((u8 *) data_0217aa18)[a->mIndex & 0xff], h);
        g = f != NULL ? (Unk020653d0 *) f->mUnk_08 : 0;
        if (g != NULL) {
            i = data_0217aa14->mUnk_728 - h;
            if (i < 0) {
                k = -i;
                c = ListGetNth(&b->mUnk_8c, 0);
                if (c != NULL) {
                    ListRemove(&b->mUnk_8c, c);
                    c->mUnk_0c = *g;
                    c->mUnk_08 = k + 1;
                    ListAppend(&b->mUnk_80, c);
                }
                e = a->mUnk_514;
                e->mUnk_5c = e->mUnk_5c + (s32) ((s64) (e->mUnk_40 - e->mUnk_5c) * 0x333 + 0x800 >> 12);
                a->mUnk_388 = e->mUnk_5c;
            } else {
                if (i > 0x19) {
                    i = 0x19;
                }
                func_020653d0(a, g, i);
                j = 1;
            }
        }
        b->mUnk_20 = h;
    } else {
        e = a->mUnk_514;
        e->mUnk_5c = e->mUnk_5c + (s32) ((s64) (e->mUnk_40 - e->mUnk_5c) * 0x333 + 0x800 >> 12);
        a->mUnk_388 = e->mUnk_5c;
    }
    e = a->mUnk_514;
    m = ListGetNext(&e->mUnk_80, NULL);
    while (m != NULL) {
        n = ListGetNext(&e->mUnk_80, m);
        m->mUnk_08 = m->mUnk_08 - 1;
        if (m->mUnk_08 <= 0) {
            if (j == 0) {
                func_020653d0(a, &m->mUnk_0c, 0);
            }
            ListRemove(&e->mUnk_80, m);
            ListAppend(&e->mUnk_8c, m);
            if (n == NULL) {
                break;
            }
            m = n;
        }
        m = ListGetNext(&e->mUnk_80, m);
    }
    if ((a->mUnk_514->mUnk_44 & 2) != 0) {
        func_0204360c(a->mEntryIndex, 1);
    }
    if ((a->mUnk_514->mUnk_44 & 4) != 0) {
        func_0204360c(a->mEntryIndex, 2);
    }
    if ((a->mUnk_514->mUnk_44 & 8) != 0) {
        func_0204360c(a->mEntryIndex, 0x20);
    }
    if ((a->mUnk_514->mUnk_44 & 0x10) != 0) {
        func_0204360c(a->mEntryIndex, 0x10);
    }
    if ((a->mUnk_514->mUnk_44 & 1) != 0) {
        a->mUnk_44 = a->mUnk_44 | 0x10;
    }
    if ((a->mUnk_514->mUnk_44 & 0x20) != 0) {
        a->mUnk_238 = 3;
        a->mUnk_48 = a->mUnk_48 | 0x20;
    } else {
        a->mUnk_238 = 0;
        a->mUnk_48 = a->mUnk_48 & ~0x20;
    }
}
