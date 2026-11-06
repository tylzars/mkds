#include "01/code_02181bd0.h"

#include "01/code_02181000.h"
#include "01/code_02182000.h"
#include "01/code_02182f98.h"
#include "01/code_02183000.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b634.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_02108000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d8000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020d7da8.h"
#include "code_0212bcac.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_0210b000.h"
#include "ITCM/code_01ff8000.h"

Unk0219b250 *data_ov001_021a9b98;

void func_ov001_02182f1c(Unk02181c3c *p0, Kart *p1) {
    p0->mUnk_0ac = 0x1e;
    p0->mUnk_000.mPos.x = p1->mPos.x;
    p0->mUnk_000.mPos.y = p1->mPos.y + 0xc000;
    p0->mUnk_000.mPos.z = p1->mPos.z;
    p0->mUnk_000.mUnk_10.y = 0x3000;
    p0->mUnk_0f8 = 1;
    p0->mUnk_0b0 = 0x99a;
    p0->mUnk_0a0 = 0x1f;
    p0->mUnk_000.mFlags = p0->mUnk_000.mFlags | data_ov001_021a6574;
    p0->mUnk_0fc = StartEffect(0x3f5, &p0->mUnk_000.mPos);
    p0->mUnk_100 = 0xd;
}

void func_ov001_02182eb8(Unk02181c3c *a, s32 b) {
    a->mUnk_0a8 += b;
    if (a->mUnk_0a8 >= 5) {
        a->mUnk_0a8 -= 5;
        a->mUnk_0a4 += 1;
        if (a->mUnk_0a4 >= func_0209b634(data_ov001_021a9b98)) {
            a->mUnk_0a4 -= func_0209b634(data_ov001_021a9b98);
        }
    }
}

void func_ov001_02182e84(void) {
    Kart *c;
    Unk02181c3c *o;

    c = GetKart((u16) data_021759c0->mEntryIndex);
    o = UnparkFirstParkedMapObject(func_02100138(0x68));
    if (o != NULL) {
        func_ov001_02182f1c(o, c);
    }
}

void func_ov001_02182d30(void) {
    Kart *c;
    Unk02181c3c *o;
    Unk020f41c4_B *rnd;
    s32 a;
    s32 b;
    Unk0210b7a8 arg;

    c = GetKart((u16) data_021759c0->mEntryIndex);
    o = UnparkFirstParkedMapObject((Unk02181c3c_list *) (func_02100138((u32) (0x68))));
    if (o != NULL) {
        rnd = func_020d22d0();
        rnd->mUnk_00 = (s64) rnd->mUnk_08 * (s64) rnd->mUnk_00 + rnd->mUnk_10;
        a = (u16) (((u64) (u32) (rnd->mUnk_00 >> 32) * 0x10000) >> 32);
        rnd = func_020d22d0();
        rnd->mUnk_00 = (s64) rnd->mUnk_08 * (s64) rnd->mUnk_00 + rnd->mUnk_10;
        b = (u32) (((u64) (u32) (rnd->mUnk_00 >> 32) * 0x800) >> 32) + 0x800;
        o->mUnk_0f8 = 3;
        o->mUnk_0b0 = 0x99a;
        o->mUnk_0a0 = 0x10;
        o->mUnk_000.mPos.x = c->mPos.x;
        o->mUnk_000.mPos.y = c->mPos.y + 0x1a000;
        o->mUnk_000.mPos.z = c->mPos.z;
        o->mUnk_000.mUnk_10.x = c->mVelocity.x + (s32) (((s64) b * gPairsByAngle[(a >> 4) * 2]) >> 12);
        o->mUnk_000.mUnk_10.y = c->mVelocity.y + 0x4000;
        o->mUnk_000.mUnk_10.z = c->mVelocity.z + (s32) (((s64) b * gPairsByAngle[(a >> 4) * 2 + 1]) >> 12);
        o->mUnk_000.mFlags &= ~1;
        arg.mUnk_00 = 0x1d9;
        arg.mUnk_04 = NULL;
        arg.mUnk_08 = 2;
        arg.mUnk_0c = func_020d4ef4(NULL);
        func_0210b7a8(&arg);
    }
}

void func_ov001_02182bdc(void) {
    Kart *c;
    Unk02181c3c *o;
    Unk020f41c4_B *rnd;
    s32 a;
    s32 b;
    u8 n;
    Unk02188950 *v;
    Unk0210b7a8 arg;

    c = GetKart((u16) data_021759c0->mEntryIndex);
    o = UnparkFirstParkedMapObject((Unk02181c3c_list *) (func_02100138((u32) (0x68))));
    if (o != NULL) {
        rnd = func_020d22d0();
        rnd->mUnk_00 = (s64) rnd->mUnk_08 * (s64) rnd->mUnk_00 + rnd->mUnk_10;
        a = (u16) (((u64) (u32) (rnd->mUnk_00 >> 32) * 0x10000) >> 32);
        rnd = func_020d22d0();
        rnd->mUnk_00 = (s64) rnd->mUnk_08 * (s64) rnd->mUnk_00 + rnd->mUnk_10;
        b = (u32) (((u64) (u32) (rnd->mUnk_00 >> 32) * 0x800) >> 32) + 0x800;
        o->mUnk_0f8 = 5;
        o->mUnk_0b0 = 0x99a;
        o->mUnk_0a0 = 0x10;
        o->mUnk_0ac = 0x1e;
        v = NULL;
        if (data_021759c0->mMode == MODE_MISSION_RUN) {
            n = 0;
            if (data_021759c0->mMode == MODE_MISSION_RUN) {
                n = func_ov001_02181b54();
            }
            v = func_ov001_02181b68(n);
        }
        o->mUnk_0e8 = &v->mUnk_000.mPos;
        o->mUnk_000.mPos.x = c->mPos.x;
        o->mUnk_000.mPos.y = c->mPos.y + 0x1a000;
        o->mUnk_000.mPos.z = c->mPos.z;
        o->mUnk_000.mUnk_10.x = (s32) (((s64) b * gPairsByAngle[(a >> 4) * 2]) >> 12);
        o->mUnk_000.mUnk_10.y = 0x4000;
        o->mUnk_000.mUnk_10.z = (s32) (((s64) b * gPairsByAngle[(a >> 4) * 2 + 1]) >> 12);
        arg.mUnk_00 = 0x1d9;
        arg.mUnk_04 = NULL;
        arg.mUnk_08 = 2;
        arg.mUnk_0c = func_020d4ef4(NULL);
        func_0210b7a8(&arg);
    }
}

void func_ov001_02182bbc(u32 a) {
    if (data_021759c0->mMode == MODE_MISSION_RUN) {
        func_ov001_02181660(a);
    }
}

void func_ov001_02182a3c(s32 a) {
    int i;
    s32 n;
    Unk02181c3c_list *list;
    Unk02181c3c *p;
    Unk020f41c4_B *rng;
    u16 r;
    int k;

    n = 0;
    list = func_02100138(0x68);
    GetKart((u16) data_021759c0->mEntryIndex);
    if (list != NULL) {
        for (i = 0; i < list->mUnk_04 && (p = list->mUnk_00[i]) != NULL; i++) {
            if (p->mUnk_0f8 == 7) {
                n++;
                if (n <= a) {
                    if (p->mUnk_0e8 == NULL) {
                        rng = func_020d22d0();
                        rng->mUnk_00 = (s64) rng->mUnk_08 * (s64) rng->mUnk_00 + rng->mUnk_10;
                        r = ((u64) (u32) (rng->mUnk_00 >> 32) * 0x10000) >> 32;
                        p->mUnk_0b0 = 0x1000;
                        p->mUnk_0a0 = 0;
                        p->mUnk_0e8 =
                            (Vec3 *) ((data_021759c0->mMode == MODE_MISSION_RUN
                                           ? (u32) func_ov001_02181b68(
                                                 data_021759c0->mMode == MODE_MISSION_RUN ? func_ov001_02181b54() : 0)
                                           : 0) +
                                      4);
                        p->mUnk_000.mPos.x = p->mUnk_0e8->x;
                        p->mUnk_000.mPos.y = p->mUnk_0e8->y;
                        p->mUnk_000.mPos.z = p->mUnk_0e8->z;
                        p->mUnk_000.mUnk_10.x = 0;
                        p->mUnk_000.mUnk_10.y = 0x4cd;
                        p->mUnk_000.mUnk_10.z = 0;
                        k = (r >> 4) * 2;
                        p->mUnk_0ec.x = ((s64) gPairsByAngle[k] * 0x14000) >> 12;
                        p->mUnk_0ec.y = -0xa000;
                        p->mUnk_0ec.z = ((s64) gPairsByAngle[k + 1] * 0x14000) >> 12;
                    }
                } else {
                    if (p->mUnk_0e8 != NULL) {
                        p->mUnk_0e8 = NULL;
                    }
                }
            }
        }
    }
}

void func_ov001_021829ac(s32 a) {
    Unk02181c3c_list *list;
    Unk02181c3c *p;
    s32 n;
    int i;

    n = 0;
    list = func_02100138(0x68);
    GetKart((u16) data_021759c0->mEntryIndex);
    if (list != NULL) {
        for (i = 0; i < list->mUnk_04 && (p = list->mUnk_00[i]) != NULL; i++) {
            if (p->mUnk_0f8 == 7) {
                if (p->mUnk_0e8 != NULL) {
                    p->mUnk_0e8 = NULL;
                }
                n++;
                if (n <= a) {
                    if ((p->mUnk_000.mFlags & 0x100) == 0) {
                        ParkMapObject(&p->mUnk_000);
                    }
                    if (data_021759c0->mMode == MODE_MISSION_RUN) {
                        func_ov001_0218155c(1);
                    }
                }
            }
        }
    }
}

void func_ov001_021828f0(void) {
    int i;
    Unk02181c3c *p;
    Unk02181c3c_list *list;
    u32 *q;

    list = func_02100138(0x68);
    if (list != NULL) {
        for (i = 0; i < list->mUnk_04 && (p = list->mUnk_00[i]) != NULL; i++) {
            if (p->mUnk_0f8 == 0 && (p->mUnk_000.mFlags & 0x100) == 0) {
                p->mUnk_000.mUnk_10.y = 0x5000;
                p->mUnk_0a0 = 0x32;
                p->mUnk_0f8 = 8;
                p->mUnk_000.mFlags |= data_ov001_021a6574;
            }
        }
    }
    q = (u32 *) func_02108e6c(2);
    if ((data_0217c780 & 1) && data_0217d084.mUnk_0c != 0) {
        if (*q != 0) {
            NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) q, 0);
        }
        if (*q != 0) {
            NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) q, 0);
        }
        NNS_SndArcPlayerStartSeqArc((NNSSndSeqPlayer **) q, 0, 0x233);
    }
}

void func_ov001_021827f0(void) {
    int i;
    Unk02181c3c *p;
    Unk02181c3c_list *list;
    u32 *q;

    list = func_02100138(0x68);
    if (list != NULL) {
        for (i = 0; i < list->mUnk_04 && (p = list->mUnk_00[i]) != NULL; i++) {
            if (p->mUnk_0f8 == 9 && (p->mUnk_000.mFlags & 0x100) == 0) {
                p->mUnk_000.mPos.x = p->mUnk_000.mCourseMapRow->mUnk_00.x;
                p->mUnk_000.mPos.y = p->mUnk_000.mCourseMapRow->mUnk_00.y + 0xa000;
                p->mUnk_000.mPos.z = p->mUnk_000.mCourseMapRow->mUnk_00.z;
                p->mUnk_000.mUnk_10.x = 0;
                p->mUnk_000.mUnk_10.y = 0x5000;
                p->mUnk_000.mUnk_10.z = 0;
                p->mUnk_0e4 = p->mUnk_000.mCourseMapRow->mUnk_00.y + 0xe000;
                p->mUnk_0f8 = 2;
                p->mUnk_0b0 = 0x1000;
                p->mUnk_0a0 = 0;
                p->mUnk_000.mFlags &= ~1;
            }
        }
    }
    q = (u32 *) func_02108e6c(2);
    if ((data_0217c780 & 1) && data_0217d084.mUnk_0c != 0) {
        if (*q != 0) {
            NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) q, 0);
        }
        if (*q != 0) {
            NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) q, 0);
        }
        NNS_SndArcPlayerStartSeqArc((NNSSndSeqPlayer **) q, 0, 0x232);
    }
}

void func_ov001_021827a4(void) {
    if (data_021759c0->mMode == MODE_MISSION_RUN) {
        func_ov001_021816a8(func_ov001_02182e84);
    }
    if (data_021759c0->mMode == MODE_MISSION_RUN) {
        func_ov001_0218169c(func_ov001_02182d30);
    }
    if (data_021759c0->mMode == MODE_MISSION_RUN) {
        func_ov001_02181690(func_ov001_02182bdc);
    }
}

u8 func_ov001_0218274c(Unk02181c3c *c, Unk0218274c *d, u8 *e, u8 *f) {
    u8 a = *e;
    u8 b = *f;

    if (d->mUnk_48 & 0x200) {
        return 0;
    }
    if (a == 1) {
        if (c->mUnk_0f8 != 3 && c->mUnk_0f8 != 5 && c->mUnk_0f8 != 6) {
            ParkMapObject(&c->mUnk_000);
            if (data_021759c0->mMode == MODE_MISSION_RUN) {
                func_ov001_021815d0(1);
            }
        }
    }
    return b;
}

void func_ov001_021826fc(Unk0219b478 *a) {
    data_ov001_021a9b98 = LoadMapObjectModelAnimated(a, data_ov001_021a78c0);
    LoadMapObjectModelNsbtpAnimation(data_ov001_021a9b98, data_ov001_021a78cc);
    SetMapObjectModelPolygonId(data_ov001_021a9b98, 0x3f);
    func_0209ba08(data_ov001_021a9b98, 2);
    func_020849a0(data_ov001_021a9b98->mAnimatedModel, 0x294a);
    a->mUnk_1c = 1;
}

void func_ov001_0218263c(void *b, Unk02181c3c *c) {
    s32 a;
    Vec3 v;
    u32 t;
    s32 s;

    if (c->mUnk_0b0 > 0 && c->mUnk_0a0 != 0) {
        a = 0x1e;
        func_01ff9048((u32) (0x14), (&a), 1);
        func_01ff9048((u32) (0x19), (func_020e6cbc(&c->mUnk_000.mPos)), 0xc);
        s = c->mUnk_0b0;
        if (s != 0x1000) {
            v.x = s;
            v.y = s;
            v.z = s;
            func_01ff9048((u32) (0x1b), (&v), 3);
        }
        func_01ff9048((u32) (0x1b), (&c->mUnk_000.mScale), 3);
        SetMapObjectModelPolygonId(data_ov001_021a9b98, func_020d3c44());
        t = c->mUnk_0a0;
        if (t >= 0x1f) {
            t = 0x1f;
        }
        func_0209b9a4(data_ov001_021a9b98, t);
        func_0209b688(data_ov001_021a9b98, (u16) c->mUnk_0a4);
        func_0209bbd0(b, data_ov001_021a9b98);
        DrawMapObjectModel((b), (data_ov001_021a9b98), (c));
    }
}

void func_ov001_02182550(Unk02181c3c_list *a) {
    int i;
    Unk02181c3c *p;
    s32 n;

    if (a != NULL) {
        for (i = 0; i < a->mUnk_04 && (p = a->mUnk_00[i]) != NULL; i++) {
            p->mUnk_0d8 = p->mUnk_000.mCourseMapRow->mUnk_00;
            p->mUnk_000.mPos = p->mUnk_0d8;
            p->mUnk_000.mPos.y = p->mUnk_000.mPos.y + 0xe000;
            if (p->mUnk_000.mCourseMapRow->mUnk_26 >= 0) {
                func_020d7da8(&p->mUnk_0b4, p->mUnk_000.mCourseMapRow, 0);
                n = (p->mUnk_000.mCourseMapRow->mUnk_28 << 12) / 100;
                p->mUnk_0b4.mUnk_04 = n;
                p->mUnk_0b4.mUnk_10 = ((s64) n * p->mUnk_0b4.mUnk_00->mUnk_00[p->mUnk_0b4.mUnk_0c].mUnk_34) >> 12;
            } else {
                p->mUnk_0b4.mUnk_08 = 0xffff;
            }
            p->mUnk_0b0 = 0x1000;
            if (p->mUnk_000.mCourseMapRow->mUnk_2a == 0) {
                p->mUnk_0a0 = 0x1f;
            } else {
                p->mUnk_0a0 = 0;
            }
        }
    }
}

void func_ov001_0218254c(void) {}

void func_ov001_02181c3c(void *a, Unk02181c3c *b) {
    s32 n;
    switch (b->mUnk_0f8) {
        case 2:
            n = b->mUnk_0a0 + 1;
            if (n >= 31) {
                n = 31;
            }
            b->mUnk_0a0 = n;
            func_ov001_02182eb8(b, 1);
            b->mUnk_000.mUnk_10.y -= 0x333;
            VEC_Add(&b->mUnk_000.mPos, &b->mUnk_000.mUnk_10, &b->mUnk_000.mPos);
            if (b->mUnk_000.mPos.y <= b->mUnk_0e4) {
                b->mUnk_000.mPos.y = b->mUnk_0e4;
                if (b->mUnk_000.mUnk_10.y <= 0) {
                    b->mUnk_000.mUnk_10.y = ((s64) b->mUnk_000.mUnk_10.y * -0x800) >> 12;
                    if (b->mUnk_000.mUnk_10.y < 0x1000) {
                        b->mUnk_000.mUnk_10.x = 0;
                        b->mUnk_000.mUnk_10.y = 0;
                        b->mUnk_000.mUnk_10.z = 0;
                        b->mUnk_0f8 = 0;
                    }
                    func_020d2600(0x1d8, &b->mUnk_000.mPos, 2);
                }
            }
            break;
        case 0: {
            u16 radius;
            s32 i;
            BOOL found;
            Vec3 *v;
            s32 dx;
            s32 dz;
            func_ov001_02182eb8(b, 1);
            if (b->mUnk_0b4.mUnk_08 != 0xffff) {
                func_020d8cc8(&b->mUnk_0b4);
                func_020d8bf8(&b->mUnk_0b4, &b->mUnk_000.mPos, &b->mUnk_000.mUnk_10);
                b->mUnk_000.mPos.y += 0xe000;
                b->mUnk_0d8 = b->mUnk_000.mPos;
            } else {
                b->mUnk_000.mUnk_10.x = 0;
                b->mUnk_000.mUnk_10.y = 0;
                b->mUnk_000.mUnk_10.z = 0;
            }
            if (b->mUnk_000.mCourseMapRow->mUnk_2a != 0) {
                radius = b->mUnk_000.mCourseMapRow->mUnk_2a;
                for (i = 0; i < data_021759c0->mKartCount; i++) {
                    v = &GetKart((u16) i)->mPos;
                    dx = v->x - b->mUnk_000.mPos.x;
                    dz = v->z - b->mUnk_000.mPos.z;
                    if ((s64) dx * dx + (s64) dz * dz < (s64) (radius << 12) * (radius << 12)) {
                        found = TRUE;
                        goto checked;
                    }
                }
                found = FALSE;
            checked:
                if (!found) {
                    goto skip;
                }
            }
            n = b->mUnk_0a0 + 1;
            if (n >= 31) {
                n = 31;
            }
            b->mUnk_0a0 = n;
            break;
        skip:
            b->mUnk_0a0 = 0;
            break;
        }
        case 8:
            n = b->mUnk_0a0 - 1;
            if (n <= 0) {
                n = 0;
            }
            b->mUnk_0a0 = n;
            func_ov001_02182eb8(b, 4);
            b->mUnk_000.mPos.y += b->mUnk_000.mUnk_10.y;
            b->mUnk_000.mUnk_10.y -= 0x333;
            if (b->mUnk_0a0 == 0) {
                b->mUnk_0f8 = 9;
            }
            break;
        case 1: {
            Kart *e;
            n = b->mUnk_0a0 - 1;
            if (n <= 0) {
                n = 0;
            }
            b->mUnk_0a0 = n;
            func_ov001_02182eb8(b, 4);
            e = GetKart((u16) data_021759c0->mEntryIndex);
            b->mUnk_000.mPos.x = e->mPos.x;
            b->mUnk_000.mPos.y += b->mUnk_000.mUnk_10.y;
            b->mUnk_000.mPos.z = e->mPos.z;
            b->mUnk_000.mUnk_10.y -= 0x333;
            if (b->mUnk_0ac-- <= 0) {
                ParkMapObject((void *) ((u32) b));
            } else if (b->mUnk_0ac == 3) {
                func_02081f10(StartEffect(0x3f4, &e->mPos), e->mIndex, 0x18);
            }
            if (b->mUnk_0fc != NULL) {
                func_0208b5b0(b->mUnk_0fc, &b->mUnk_000.mPos);
                if (b->mUnk_100-- < 0) {
                    func_0208b6b0(&b->mUnk_0fc);
                }
            }
            break;
        }
        case 3: {
            u32 flags;
            Vec3 pos;
            Vec3 delta;
            Vec3 out1;
            Vec3 out2;
            n = b->mUnk_0a0 + 1;
            if (n >= 31) {
                n = 31;
            }
            b->mUnk_0a0 = n;
            if (b->mUnk_0b0 < 0x1000) {
                b->mUnk_0b0 += 0x29;
                if (b->mUnk_0b0 > 0x1000) {
                    b->mUnk_0b0 = 0x1000;
                }
            }
            func_ov001_02182eb8(b, 1);
            b->mUnk_000.mUnk_10.y -= 0x333;
            VEC_Add(&b->mUnk_000.mPos, &b->mUnk_000.mUnk_10, &b->mUnk_000.mPos);
            pos.x = b->mUnk_000.mPos.x;
            pos.y = b->mUnk_000.mExtent.x + (b->mUnk_000.mPos.y - 0xe000);
            pos.z = b->mUnk_000.mPos.z;
            if (func_020d2c2c(&pos, &b->mUnk_000.mUnk_10, b->mUnk_000.mExtent.x, b->mUnk_000.mCollisionSlotIndex, 2,
                              &delta) != 0) {
                VEC_Add(&b->mUnk_000.mPos, &delta, &b->mUnk_000.mPos);
                if ((s64) delta.x * delta.x + (s64) delta.y * delta.y + (s64) delta.z * delta.z >= 0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&delta, &b->mUnk_000.mUnk_10);
                }
                b->mUnk_000.mUnk_10.x = ((s64) b->mUnk_000.mUnk_10.x * 0x1400) >> 12;
                b->mUnk_000.mUnk_10.y = ((s64) b->mUnk_000.mUnk_10.y * 0x1400) >> 12;
                b->mUnk_000.mUnk_10.z = ((s64) b->mUnk_000.mUnk_10.z * 0x1400) >> 12;
            }
            if (func_01ffdee4(&pos, NULL, 0, b->mUnk_000.mExtent.x, 1, b->mUnk_000.mCollisionSlotIndex, &delta, &out1,
                              &out2, &flags, NULL, NULL, NULL, NULL) != 0) {
                VEC_Add(&b->mUnk_000.mPos, &delta, &b->mUnk_000.mPos);
                if (flags & 0x214300) {
                    func_020eaa14(&b->mUnk_000.mUnk_10, &out2, 0x1000, 0x1000, 0xc00, &b->mUnk_000.mUnk_10);
                    if ((s64) b->mUnk_000.mUnk_10.x * b->mUnk_000.mUnk_10.x +
                            (s64) b->mUnk_000.mUnk_10.y * b->mUnk_000.mUnk_10.y +
                            (s64) b->mUnk_000.mUnk_10.z * b->mUnk_000.mUnk_10.z >=
                        0x10) {
                        Vec3NormalizeAndGetLengthUnchecked(&b->mUnk_000.mUnk_10, &b->mUnk_000.mUnk_10);
                    }
                    b->mUnk_000.mUnk_10.x = ((s64) b->mUnk_000.mUnk_10.x * 0x1400) >> 12;
                    b->mUnk_000.mUnk_10.y = ((s64) b->mUnk_000.mUnk_10.y * 0x1400) >> 12;
                    b->mUnk_000.mUnk_10.z = ((s64) b->mUnk_000.mUnk_10.z * 0x1400) >> 12;
                }
                if ((flags & 0x1e34ef) && b->mUnk_000.mUnk_10.y <= 0) {
                    b->mUnk_000.mUnk_10.y = ((s64) b->mUnk_000.mUnk_10.y * -0x800) >> 12;
                    if (b->mUnk_000.mUnk_10.y < 0x1000) {
                        b->mUnk_000.mUnk_10.x = 0;
                        b->mUnk_000.mUnk_10.y = 0;
                        b->mUnk_000.mUnk_10.z = 0;
                        b->mUnk_0f8 = 0;
                    }
                    func_020d2600(0x1d8, &b->mUnk_000.mPos, 2);
                }
                if ((flags & 0x800) || b->mUnk_000.mPos.y < 0) {
                    b->mUnk_0f8 = 4;
                }
            }
            b->mUnk_0d8.x = b->mUnk_000.mPos.x;
            b->mUnk_0d8.z = b->mUnk_000.mPos.z;
            break;
        }
        case 4:
            func_ov001_02182eb8(b, 1);
            b->mUnk_000.mUnk_10.y -= 0x333;
            VEC_Add(&b->mUnk_000.mPos, &b->mUnk_000.mUnk_10, &b->mUnk_000.mPos);
            n = b->mUnk_0a0 - 1;
            if (n > 0) {
                b->mUnk_0a0 = n;
                break;
            }
            if (b->mUnk_000.mCourseMapRow->mUnk_2c != 0) {
                b->mUnk_0f8 = 7;
                b->mUnk_0b0 = 0x1000;
                b->mUnk_0a0 = 0;
                b->mUnk_000.mFlags |= data_ov001_021a6574;
                if (data_021759c0->mMode == MODE_MISSION_RUN) {
                    func_ov001_02181630(1);
                }
            } else {
                b->mUnk_000.mPos.x = b->mUnk_000.mCourseMapRow->mUnk_00.x;
                b->mUnk_000.mPos.y = b->mUnk_000.mCourseMapRow->mUnk_00.y + 0x64000;
                b->mUnk_000.mPos.z = b->mUnk_000.mCourseMapRow->mUnk_00.z;
                b->mUnk_000.mUnk_10.x = 0;
                b->mUnk_000.mUnk_10.y = 0;
                b->mUnk_000.mUnk_10.z = 0;
                b->mUnk_0e4 = b->mUnk_000.mCourseMapRow->mUnk_00.y + 0xe000;
                b->mUnk_0f8 = 2;
                b->mUnk_0b0 = 0x1000;
                b->mUnk_0a0 = 0;
                b->mUnk_000.mFlags &= ~1;
            }
            break;
        case 5:
            n = b->mUnk_0a0 + 1;
            if (n >= 31) {
                n = 31;
            }
            b->mUnk_0a0 = n;
            if (b->mUnk_0b0 < 0x1000) {
                b->mUnk_0b0 += 0x29;
                if (b->mUnk_0b0 > 0x1000) {
                    b->mUnk_0b0 = 0x1000;
                }
            }
            func_ov001_02182eb8(b, 1);
            b->mUnk_000.mUnk_10.y -= 0x333;
            VEC_Add(&b->mUnk_000.mPos, &b->mUnk_000.mUnk_10, &b->mUnk_000.mPos);
            if (b->mUnk_000.mUnk_10.y <= 0) {
                b->mUnk_0f8 = 6;
            }
            break;
        case 6:
            if (b->mUnk_0b0 < 0x1000) {
                b->mUnk_0b0 += 0x29;
                if (b->mUnk_0b0 > 0x1000) {
                    b->mUnk_0b0 = 0x1000;
                }
            }
            func_ov001_02182eb8(b, 1);
            if (b->mUnk_000.mPos.x < b->mUnk_0e8->x) {
                b->mUnk_000.mUnk_10.x += 0x400;
            } else if (b->mUnk_000.mPos.x > b->mUnk_0e8->x) {
                b->mUnk_000.mUnk_10.x -= 0x400;
            }
            if (b->mUnk_000.mPos.y < b->mUnk_0e8->y) {
                b->mUnk_000.mUnk_10.y += 0x400;
            } else if (b->mUnk_000.mPos.y > b->mUnk_0e8->y) {
                b->mUnk_000.mUnk_10.y -= 0x400;
            }
            if (b->mUnk_000.mPos.z < b->mUnk_0e8->z) {
                b->mUnk_000.mUnk_10.z += 0x400;
            } else if (b->mUnk_000.mPos.z > b->mUnk_0e8->z) {
                b->mUnk_000.mUnk_10.z -= 0x400;
            }
            VEC_Add(&b->mUnk_000.mPos, &b->mUnk_000.mUnk_10, &b->mUnk_000.mPos);
            if (b->mUnk_0ac-- <= 0) {
                b->mUnk_0ac = 0;
                n = b->mUnk_0a0 - 1;
                if (n <= 0) {
                    n = 0;
                }
                b->mUnk_0a0 = n;
                if (b->mUnk_0a0 < 1) {
                    b->mUnk_0f8 = 7;
                    b->mUnk_0b0 = 0x1000;
                    b->mUnk_0a0 = 0;
                    b->mUnk_0e8 = NULL;
                    b->mUnk_000.mFlags |= data_ov001_021a6574;
                }
            }
            break;
        case 7:
            if (b->mUnk_0e8 != NULL) {
                n = b->mUnk_0a0 + 2;
                if (n >= 31) {
                    n = 31;
                }
                b->mUnk_0a0 = n;
            } else {
                n = b->mUnk_0a0 - 2;
                if (n <= 0) {
                    n = 0;
                }
                b->mUnk_0a0 = n;
            }
            if (b->mUnk_0a0 != 0 && b->mUnk_0e8 != NULL) {
                func_ov001_02182eb8(b, 1);
                b->mUnk_000.mUnk_10.y -= 0x14;
                VEC_Add(&b->mUnk_0ec, &b->mUnk_000.mUnk_10, &b->mUnk_0ec);
                VEC_Add(&b->mUnk_0ec, b->mUnk_0e8, &b->mUnk_000.mPos);
                if ((s64) ((const Vec3 *) &b->mUnk_0ec)->x * ((const Vec3 *) &b->mUnk_0ec)->x +
                        (s64) ((const Vec3 *) &b->mUnk_0ec)->z * ((const Vec3 *) &b->mUnk_0ec)->z >=
                    0x190000000LL) {
                    b->mUnk_000.mUnk_10.x = ((s64) b->mUnk_0ec.x * -0x14) >> 12;
                    b->mUnk_000.mUnk_10.z = ((s64) b->mUnk_0ec.z * -0x14) >> 12;
                }
                if (b->mUnk_0ec.y < -0xa000) {
                    b->mUnk_000.mUnk_10.y = 0x4cd;
                }
            }
            break;
        case 9:
            break;
    }
}

void func_ov001_02181c20(void) {
    func_0209bfa8(&func_ov001_0218274c, NULL, NULL, (u32) (1), (u16) (1));
    return;
}

void *func_ov001_02181c08(void) {
    return (void *) func_0209bf1c(func_ov001_021826fc, func_ov001_0218263c, NULL);
}

void *func_ov001_02181bec(void) {
    return (void *) func_0209bf1c(func_ov001_021830a8, func_ov001_02182f98, func_ov001_02183090);
}

void *func_ov001_02181bd0(void) {
    return (void *) func_0209bf48(func_ov001_02182550, func_ov001_02181c3c, func_ov001_0218254c);
}
