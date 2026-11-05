#include "Main/Unknown/code_020e6fd4.h"
#include "code_02146d78.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_0210c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020e73a0.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020e7a84.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020ea000.h"
#include "code_0212bcac.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087cfc.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ea514.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02077bc0.h"

void func_020e7a40(void) {
    u32 value0;
    u32 value1;
    u32 compareLeft0;
    u32 compareRight0;
    value0 = (u32) data_021759c0->mUnk_00c;
    compareLeft0 = value0;
    compareRight0 = 6u;
    if (compareLeft0 == compareRight0) {
    }
    if (compareLeft0 == compareRight0) {
    }
    if (compareLeft0 == compareRight0) {
        return;
    }
    value0 = (u32) &data_0217b9ec;
    value1 = 4u;
    func_02046bcc((void *) value0, (u16) value1);
}

#pragma thumb off
void func_020e7a18(void) {
    if (data_021759c0->mUnk_00c != 6) {
        data_0217b8b4 = 0x14;
    }
}

void func_020e79c4(void) {
    if (data_021759c0->mUnk_00c == 6) {
        return;
    }
    func_0212c6f0(func_02108e6c(4), 1);
    data_0217b8c8 = NULL;
}

#pragma thumb on
void func_020e7760(void) {
    Kart *q;
    Vec3 *v;
    s32 i;
    Vec3 *s;
    BOOL a;

    if (data_021759c0->mUnk_00c == 6) {
        return;
    }
    if (data_021759c0->mUnk_00c == 3) {
        data_0217b8c8 = NULL;
        return;
    }
    if (data_021759c0->mEntryIndex < 0) {
        data_0217b8c8 = NULL;
        return;
    }
    data_0217b888 = data_021759c0->mEntryIndex;
    q = GetKart(data_0217b888);
    data_0217b8c8 = q;
    data_0217b8c0 = &q->mKartModelsEntry->mUnk_040;
    data_0217b9c0.x = 0;
    data_0217b9c0.y = 0;
    data_0217b9c0.z = 0;
    data_0217b90c = data_0217b9c0;
    data_0217b918 = data_0217b90c;
    data_0217b93c = data_0217b918;
    data_0217b99c = data_0217b93c;
    data_0217b930 = data_0217b99c;
    data_0217b9b4.x = 0;
    data_0217b9b4.y = 0;
    data_0217b9b4.z = 0;
    data_0217b924.x = 0;
    data_0217b924.y = 0;
    data_0217b924.z = 0;
    data_0217b870 = 0;
    data_0217b8b8 = 0;
    data_0217b88c = 0;
    data_0217b8cc = 0;
    data_0217b8ec = 0;
    data_0217b948 = data_0217b930;
    a = TRUE;
    data_0217b8f0 = a;
    data_0217b8bc = a;
    data_0217b894 = 0;
    if (gCourseMap->mSettings->mUnk_04 != 0) {
        a = FALSE;
    }
    data_0217b8f8 = a;
    data_0217b890 = 4;
    data_0217b87c = 1;
    data_0217b884 = func_02044618();
    func_020ea37c();
    data_0217bb28[0].x = 0;
    data_0217bb28[0].y = 0;
    data_0217bb28[0].z = 0;
    s = data_02159440;
    for (i = 0; i < 7; i++) {
        v = &data_0217bb28[i + 1];
        *v = *s;
        if (data_0217b8f8 != 0) {
            v->x = -v->x;
            v->y = -v->y;
            v->z = -v->z;
        }
        s++;
    }
    switch (data_021759c0->mMode) {
        case MODE_BATTLE:
            data_0217b8b0 = 0;
            break;
        case MODE_MISSION_RUN: {
            BOOL b;

            b = FALSE;
            if ((u8) (data_021759c0->mUnk_2f + 0xfe) <= 8 &&
                (0x115 & (1 << (u8) (data_021759c0->mUnk_2f + 0xfe))) != 0) {
                b = TRUE;
            }
            data_0217b8b0 = b;
            break;
        }
        default:
            data_0217b8b0 = 1;
            break;
    }
    switch (data_021759c0->mUnk_010) {
        case 0:
            data_0217b880 = 0x50;
            break;
        case 1:
            data_0217b880 = 0x3c;
            break;
        case 2:
        default:
            data_0217b880 = 0x2d;
            break;
    }
    data_0217b9dc.mUnk_00 = 0x101;
    data_0217b9dc.mUnk_04 = &data_0217b930;
    data_0217b9dc.mUnk_08 = 1;
    func_02046be8(&data_0217b9ec, (UnkFunc *const *) data_0216c33c, 7, NULL);
    func_02046bcc(&data_0217b9ec, 0);
}

void func_020e7460(void) {
    s32 x;
    s32 j;
    s32 i;
    void *h;
    Unk0216c324 *s;
    Unk0217bb08 *q;
    void *p;
    s32 n;
    s32 k;

    h = GetHeap(func_020364e8());
    if (data_021759c0->mUnk_00c == 6) {
        return;
    }
    func_020e64b8(&data_0217ba2c, FindSceneFile(data_0216c374), FindSceneFile(data_0216c384), 0);
    func_020e6ab8(&data_0217ba2c);
    data_0217ba2c.mUnk_14 |= 0xc0;
    func_020e64b8(&data_0217ba00, FindSceneFile(data_0216c394), NULL, 0);
    func_020e6ab8(&data_0217ba00);
    data_0217ba00.mUnk_14 |= 0xc0;
    data_0217b8a4 = HeapAlloc(h, 0x78);
    data_0217b8a8 = HeapAlloc(h, 0x78);
    data_0217b8a0 = HeapAlloc(h, 0x78);
    data_0217b8e0 = HeapAlloc(h, 0x78);
    data_0217b904 = HeapAlloc(h, 0x78);
    for (i = 0, x = 0; i < 0x3c; i++) {
        data_0217b8a4[i] = (u16) (((s64) gPairsByAngle[(x >> 4) * 2] * 0x4c) >> 12);
        k = (u16) (((u64) (s64) gPairsByAngle[((u16) (x + 0xa218) >> 4) * 2] * 0xb60b60b60b + 0x80000000000) >> 44) >>
            4;
        data_0217b8a8[i] = gPairsByAngle[k * 2];
        data_0217b8a0[i] = gPairsByAngle[k * 2 + 1];
        data_0217b8e0[i] = (u32) (((s64) gPairsByAngle[((u16) (x + 0x1554) >> 4) * 2] * 0x19a) >> 12) + 0xe66;
        data_0217b904[i] = (u32) (((s64) gPairsByAngle[((u16) (x + 0xbbb0) >> 4) * 2] * 0x19a) >> 12) + 0x119a;
        x += 0x444;
    }
    data_0217b8e8 = 0;
    n = 2;
    for (j = n, s = data_0216c324, q = data_0217bb08; j < 4; j++) {
        if (s->mUnk_00 != NULL) {
            q->mUnk_00 = HeapAlloc(h, 0x6c);
            p = FindSceneFile(s->mUnk_00);
            func_02084e28(q->mUnk_00, p);
            func_02084968(q->mUnk_00, 0x3f, n, 0x294a);
            func_02084958(q->mUnk_00, 3);
        } else {
            q->mUnk_00 = NULL;
        }
        if (s->mUnk_04 != NULL) {
            q->mUnk_04 = HeapAlloc(h, 0x38);
            func_020ea514(0, q->mUnk_00, q->mUnk_04, p, FindSceneFile(s->mUnk_04));
            func_02087cfc(q->mUnk_04, 0, 1);
        } else {
            q->mUnk_04 = NULL;
        }
        if (s->mUnk_08 != NULL) {
            q->mUnk_08 = HeapAlloc(h, 0x38);
            func_020ea514(4, q->mUnk_00, q->mUnk_08, p, FindSceneFile(s->mUnk_08));
            func_02087cfc(q->mUnk_08, 0, 1);
        } else {
            q->mUnk_08 = NULL;
        }
        s++;
        q++;
    }
    func_020e6488((Unk020e6488 **) data_0217baf4, FindSceneFile(data_0216c3a4), (u32) FindSceneFile(data_0216c3b4), 0);
    func_020e6ab8(data_0217bae8[0].mUnk_0c);
    data_0217bae8[0].mUnk_0c->mUnk_14 |= 0xc0;
    func_020e6488((Unk020e6488 **) data_0217bb04, FindSceneFile(data_0216c3c4), 0, 0);
    func_020e6ab8(data_0217bae8[1].mUnk_0c);
    data_0217bae8[1].mUnk_0c->mUnk_14 |= 0xc0;
}
#pragma thumb off

Unk020e7410 *func_020e7410(void) {
    Unk020e7410 *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x40);
    *p = *(Unk020e7410 *) data_02159370;
    return p;
}

Unk020e6fd4 *func_020e73b4(void) {
    Unk020e6fd4 *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x28);
    data_0217b864 = p;
    *p = *(Unk020e6fd4 *) data_02159348;
    func_020e6f50(&data_0217b864);
    return (Unk020e6fd4 *) data_0217b864;
}

Vec3 *func_020e73a0(u32 arg0) {
    return (*(Vec3 ***) data_0217b86c)[arg0];
}

u16 func_020e7388(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_0217b868;
    value0 = (value0 << 1);
    value1 = (u32) * (const u32 *) ((value1) + (0));
    value0 = (u32) * (const u16 *) ((value1) + (value0));
    return (u16) value0;
}

#pragma thumb on
void func_020e730c(void) {
    Unk020e730c *e;
    s32 n;
    s32 i;

    n = ((Unk020e6fd4 *) data_0217b864)->mUnk_04;
    *(void **) data_0217b86c = HeapAlloc(GetHeap(func_020364e8()), n * 4);
    data_0217b868 = HeapAlloc(GetHeap(func_020364e8()), n * 2);
    for (i = 0; i < ((Unk020e6fd4 *) data_0217b864)->mUnk_04; i++) {
        s32 k;

        e = (Unk020e730c *) ((Unk020e6fd4 *) data_0217b864)->mUnk_00[i];
        k = e->mUnk_a0;
        (*(Vec3 ***) data_0217b86c)[k] = &e->mUnk_00.mPos;
        data_0217b868[k] = e->mUnk_a2;
    }
}

void func_020e72cc(Unk020e730c *p, struct CourseMapRow *q) {
    p->mUnk_a0 = q->mUnk_28;
    switch (data_021759c0->mUnk_010) {
        case 0:
            p->mUnk_a2 = q->mUnk_2a;
            break;
        case 1:
            p->mUnk_a2 = q->mUnk_2c;
            break;
        case 2:
            p->mUnk_a2 = q->mUnk_2e;
            break;
    }
}
#pragma thumb off

void func_020e71a0(MapObject *p) {
    Unk020e71a0_94 *q;
    BOOL a;
    BOOL b;

    q = p->mUnk_94;
    if ((p->mFlags & 2) == 0) {
        q->mSoundSource.mUnk_40 = p->mUnk_78 & ~0xc000001f;
        a = (func_020d4ddc(p) == FALSE);
        b = (q->mSoundSource.mUnk_34 & 1) != 0;
        if (a != FALSE) {
            if (b != FALSE) {
                goto ret;
            }
            goto call;
        }
    ret:
        if (a != FALSE) {
            return;
        }
        if (b == FALSE) {
            return;
        }
    call:
        func_0210cfbc(&q->mSoundSource, 2, 1);
    } else {
        s32 v;

        v = func_020d4ef4(&p->mPos);
        q->mSoundSource.mUnk_40 = v;
        if (func_020d4d60(p, v) != FALSE) {
            p->mUnk_78 |= data_02159310;
            if ((q->mSoundSource.mUnk_34 & 1) != 0) {
                func_0210cfbc(&q->mSoundSource, 2, 1);
            }
        } else if ((q->mSoundSource.mUnk_34 & 1) == 0) {
            func_0210cfbc(&q->mSoundSource, 2, 1);
        }
    }
}

void func_020e705c(Unk020e6fd4 *p) {
    MapObject *e;
    Vec3 t;
    void (*cb)(void *p, MapObject *e);
    s32 n;
    void **arr;

    cb = p->mUnk_10;
    n = p->mUnk_04;
    arr = p->mUnk_00;
    if (cb == NULL) {
        s32 i;

        for (i = 0; i < n; i++) {
            e = arr[i];
            if (e->mUnk_94 != NULL) {
                func_020e71a0(e);
            }
        };
        return;
    }
    if (p->mUnk_18 == 2) {
        s32 i;

        for (i = 0; i < n; i++) {
            e = arr[i];
            if ((e->mFlags & 4) == 0) {
                t = e->mPos;
                cb(p, e);
                Vec3Sub(&e->mPos, &t, &e->mUnk_10);
                if (e->mUnk_94 != NULL) {
                    func_020e71a0(e);
                }
            }
        };
        return;
    }
    {
        s32 i;

        for (i = 0; i < n; i++) {
            e = arr[i];
            if ((e->mFlags & 4) == 0) {
                cb(p, e);
                if (e->mUnk_94 != NULL) {
                    func_020e71a0(e);
                }
            }
        }
    }
}

void func_020e6fd4(Unk020e6fd4 *p) {
    MapObject *e;
    u8 buf[2];
    s32 i;
    s32 n;
    void **arr;
    s32 (*cb)(MapObject *, void *, void *, void *);

    n = p->mUnk_04;
    cb = p->mUnk_1c;
    arr = p->mUnk_00;
    buf[0] = p->mUnk_20;
    buf[1] = 0;
    if (cb == NULL) {
        return;
    }
    for (i = 0; i < n; i++) {
        e = arr[i];
        if ((e->mFlags & 0x88) == 0) {
            cb(e, NULL, &buf[0], &buf[1]);
        }
    }
}
