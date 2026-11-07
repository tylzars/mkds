#include "Main/Unknown/code_020de9ec.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d8c74.h"

#include "Main/Unknown/code_020de9f8.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_020deb2c.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020debec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e55b4.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020df428.h"
#include "code_021471bc.h"

#pragma thumb on

void func_020df428(Unk020de6a8 *a, Unk020de6a8_1 *b) {
    InitItemBox(a, b);
    if (a->mUnk_0f8 != 0) {
        a->mUnk_108.mUnk_00.mUnk_08 = (0x0000ffffu);
        return;
    }
    func_020d7d4c(&a->mUnk_108, (CourseMapRow *) b, *&data_02158908, b->mUnk_28);
    func_020d859c(&a->mUnk_108, b->mUnk_30, 1);
    func_020d8c74(&a->mUnk_108.mUnk_00, &a->mUnk_000.mPos);
}

#pragma thumb off

#pragma thumb on
void func_020df3f8(void) {
    data_0217b750 = 0;
    data_0217b754 = 0;
    data_0217b75c = 0x1000;
    data_0217b760.x = 0x1000;
    data_0217b760.y = 0x1000;
    data_0217b760.z = 0x1000;
}
#pragma thumb off

Unk020de390 *CreateItemBoxKindData(void) {
    Unk020de390 *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x40);
    *p = data_02158654;
    return p;
}

Unk020de334 *CreateBoxDrawList(void) {
    data_0217b70c = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    *data_0217b70c = data_02158628;
    func_020d49d8(&data_0217b70c);
    return data_0217b70c;
}

Unk020de334 *CreateQuestionDrawList(void) {
    data_0217b700 = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    *data_0217b700 = data_021585fc;
    func_020d49d8(&data_0217b700);
    return data_0217b700;
}

Unk020de334 *func_020df294(void) {
    data_0217b714 = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    *data_0217b714 = data_021585d0;
    func_020d49d8(&data_0217b714);
    return data_0217b714;
}

Unk020de2d8 *CreateItemBoxUpdateList(void) {
    data_0217b718 = HeapAlloc(GetHeap(func_020364e8()), 0x28);
    *data_0217b718 = data_021585a8;
    func_020e6f50(&data_0217b718);
    return data_0217b718;
}

void SetupDrawBox(void) {
    func_020e6a18(gBox);
}

void DrawBox(void *a, Unk020de6a8 *b, void *c, u16 d) {
    MtxFx43 q;
    Unk020e6488 *p;
    Vec3 *w;
    s32 e;
    s32 g;
    s32 h;
    u16 x;
    u16 y;
    u16 r;
    Unk020de84c_14 *t;

    if (b->mUnk_0e8 < 1) {
        return;
    }
    if (b->mUnk_100 != NULL) {
        b->mUnk_100(b->mUnk_104, &q);
        r = AllocPolygonIdWrapping();
        p = gBox;
        p->mUnk_14 = p->mUnk_14 & 0xc0ffffff;
        p->mUnk_14 = p->mUnk_14 | r << 24;
    } else {
        t = &data_0217b704[b->mUnk_0a0];
        e = t->mUnk_00;
        q.mUnk_00[0].x = e;
        g = t->mUnk_04;
        q.mUnk_00[0].y = g;
        q.mUnk_00[0].z = 0;
        h = -t->mUnk_10;
        q.mUnk_00[1].x = h;
        q.mUnk_00[1].y = t->mUnk_08;
        q.mUnk_00[1].z = g;
        q.mUnk_00[2].x = t->mUnk_0c;
        q.mUnk_00[2].y = h;
        q.mUnk_00[2].z = e;
        w = b->mUnk_0fc;
        q.mUnk_00[3].x = w->x >> 4;
        q.mUnk_00[3].y = w->y >> 4;
        q.mUnk_00[3].z = w->z >> 4;
        y = b->mUnk_0f0;
        p = gBox;
        p->mUnk_14 = p->mUnk_14 & 0xc0ffffff;
        p->mUnk_14 = p->mUnk_14 | y << 24;
    }
    x = b->mUnk_0e8;
    p = gBox;
    p->mUnk_14 = p->mUnk_14 & 0xffe0ffff;
    p->mUnk_14 = p->mUnk_14 | x << 16;
    if (b->mUnk_0fc != NULL) {
        if (b->mUnk_000.mScale.z < 0x29) {
            return;
        }
        func_020e67c4(gBox, &q, &b->mUnk_000.mScale, 0, d);
    } else {
        func_020e67c4(gBox, &q, NULL, 0, d);
    }
}

void SetupDrawQuestion(void) {
    func_020e6a18(gQuestion);
}

void DrawQuestion(void *a, Unk020de6a8 *b, void *c, u16 d) {
    MtxFx43 q;
    s32 e;
    s32 f;
    Unk020de84c_08 *t;
    Unk020e6488 *p;
    Vec3 *w;
    s32 x;
    Unk020e6488 *p2;
    u16 y;

    b->mUnk_0f0 = AllocPolygonIdWrapping();
    if (b->mUnk_100 != NULL) {
        return;
    }
    if ((s32) (b->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0) > 0x27100) {
        if (func_0203c5e4() == 0) {
            return;
        }
    }
    if (b->mUnk_0ec < 1) {
        return;
    }
    t = &data_0217b708[b->mUnk_0a2];
    e = t->mUnk_00;
    q.mUnk_00[0].x = e;
    q.mUnk_00[0].y = 0;
    f = -t->mUnk_04;
    q.mUnk_00[0].z = f;
    q.mUnk_00[1].x = 0;
    q.mUnk_00[1].y = 0x1000;
    q.mUnk_00[1].z = 0;
    q.mUnk_00[2].x = -f;
    q.mUnk_00[2].y = 0;
    q.mUnk_00[2].z = e;
    w = b->mUnk_0fc;
    q.mUnk_00[3].x = w->x >> 4;
    q.mUnk_00[3].y = w->y >> 4;
    q.mUnk_00[3].z = w->z >> 4;
    p = gQuestion;
    x = b->mUnk_0ec;
    p->mUnk_14 &= 0xffe0ffff;
    p->mUnk_14 |= (u16) x << 16;
    y = b->mUnk_0f0;
    p2 = gQuestion;
    p2->mUnk_14 &= 0xc0ffffff;
    p2->mUnk_14 |= y << 24;
    func_020e67c4(gQuestion, &q, b->mUnk_0fc != NULL ? &b->mUnk_000.mScale : 0, 0, d);
}

void func_020dee8c(void) {
    s32 n;

    func_020e55b4();
    if (func_020b2ec0() != 0) {
        return;
    }
    data_0217b6fc += 0xca;
    n = data_0217b6fc >> 4;
    MTX_RotY43_(&data_0217b720, gPairsByAngle[n * 2], gPairsByAngle[n * 2 + 1]);
}

void func_020dec4c(void *a, Unk020de6a8 *b, u32 c, u32 d) {
    Vec3 v;
    Vec3 *p;
    s32 n;
    s32 x;
    s32 y;
    MtxFx43 *q;

    n = b->mUnk_0a4 - 0x40;
    if (n >= 0x40) {
        b->mUnk_0e8 = 0x1a;
        b->mUnk_0ec = 0x14;
        n = 0xd;
    } else {
        x = n * 0x1a >> 6;
        y = n * 0x14 >> 6;
        n = n * 0xd >> 6;
        if (x > 0) {
            if (y < 1) {
                y = 1;
            }
            if (n < 1) {
                n = 1;
            }
        }
        b->mUnk_0e8 = x;
        b->mUnk_0ec = y;
    }
    if ((s32) (b->mUnk_000.mDistanceSquaredAndFlags & ~0xc000001f) > 0x27100) {
        if (func_0203c5e4() == 0) {
            return;
        }
    }
    if (n < 1) {
        return;
    }
    if (b->mUnk_0b0 == 0) {
        b->mUnk_0b4.mUnk_030 = n;
        func_020e54e4(&b->mUnk_0b4, b->mUnk_0a8 != 0 ? &data_0217b75c : 0, c, d);
        return;
    }
    if (b->mUnk_0b0 != 1) {
        return;
    }
    if (b->mUnk_0a8 != 0) {
        p = b->mUnk_0fc;
        data_0217b720.mUnk_00[3].x = p->x >> 4;
        data_0217b720.mUnk_00[3].y = p->y >> 4;
        data_0217b720.mUnk_00[3].z = p->z >> 4;
        func_020e5370(&data_0217b760, &data_0217b720, (u16) n, d);
        return;
    }
    v.x = ((s64) b->mUnk_000.mScale.x * 0x1666) >> 12;
    v.y = ((s64) b->mUnk_000.mScale.y * 0x1666) >> 12;
    v.z = ((s64) b->mUnk_000.mScale.z * 0x1666) >> 12;
    if (b->mUnk_100 != NULL) {
        q = SetTranslationMatrixPos(b->mUnk_0fc);
    } else {
        p = b->mUnk_0fc;
        data_0217b720.mUnk_00[3].x = p->x >> 4;
        data_0217b720.mUnk_00[3].y = p->y >> 4;
        data_0217b720.mUnk_00[3].z = p->z >> 4;
        q = &data_0217b720;
    }
    func_020e5370(&v, q, (u16) n, d);
}

void UpdateItemBox(void *a, Unk020de6a8 *b) {
    u32 n;

    b->mUnk_0a0++;
    if (b->mUnk_0a0 >= 0x12c) {
        b->mUnk_0a0 = 0;
    }
    b->mUnk_0a2++;
    if (b->mUnk_0a2 >= 0x82) {
        b->mUnk_0a2 = 0;
    }
    n = b->mUnk_0a4;
    if (n >= 0x80) {
        return;
    }
    b->mUnk_0a4 = n + 1;
    if (n > 0x60) {
        b->mUnk_000.mFlags = b->mUnk_000.mFlags & ~1;
    }
}

void func_020deb2c(Vec3 *a, void *b, u32 c, int d, u32 e) {
    void *v1;
    u32 v2;
    v2 = *OFFSET_PTR(u16, b, 0x74);
    if (d == 0) {
        if (v2 == gRaceSetup->mEntryIndex) {
            v1 = StartEffect(0x2d, a);
            if (v1 != NULL) {
                SetupKartFollowEffect(v1, v2, 0x1e);
            }
            v1 = StartEffect(0x2e, a);
            if (v1 != NULL) {
                SetupKartFollowEffect(v1, v2, 0x1e);
            }
        }
        v1 = StartEffect(0x2f, a);
        if (v1 != NULL) {
            SetupKartFollowEffect(v1, v2, 0x1e);
        }
    }
    func_020d26ec(b, 0xd4);
    StartItemSlotForKart(v2, c, e);
}

u8 CollideKartWithItemBox(Unk020de6a8 *a, Unk020dea50_1 *b, void *c, u8 *d) {
    s32 v;
    BOOL n;
    u32 m;

    if ((b->mUnk_7c & 0x400000) != 0) {
        return 0;
    }
    n = FALSE;
    a->mUnk_0a4 = 0;
    a->mUnk_000.mFlags |= data_021585a4;
    m = a->mUnk_000.mDistanceSquaredAndFlags & 3;
    v = gRaceSetup->mCurrentEntries[b->mUnk_74].mPlayer.mKind;
    if ((u32) v <= 3) {
        if (((1 << v) & 0xd) != 0) {
            n = TRUE;
        }
    }
    func_020deb2c(&a->mUnk_000.mPos, b, n != FALSE ? a->mUnk_0f2 : a->mUnk_0f4, m, a->mUnk_0ac);
    if (a->mUnk_0f8 != 0 || a->mUnk_000.mCourseMapRow->mUnk_32 != 0) {
        a->mUnk_0a4 = 0x80;
        ParkMapObject(&a->mUnk_000);
    }
    return *d;
}

u32 func_020de9f8(Unk020de6a8 *a) {
    if (a->mUnk_0f8 != 0) {
        return 0x270f000;
    }
    if (a->mUnk_0a8 == 0) {
        return 0;
    }
    return func_020d8828(&a->mUnk_108.mUnk_00, &a->mUnk_000.mPos);
}

void func_020de9ec(Unk020de6a8 *p0) {
    p0->mUnk_0a4 = 0x80;
}
