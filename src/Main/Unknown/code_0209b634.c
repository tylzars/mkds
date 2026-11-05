#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020ea618.h"
#include "Main/Unknown/code_020ea670.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020109c4.h"
#include "code_02012b30.h"

void *func_0209bbfc(void *b) {
    Unk020e6fd4 *a = b;
    MapObject *e;
    s32 i;

    if (a != NULL) {
        for (i = 0; i < a->mUnk_04 && (e = a->mUnk_00[i]) != NULL; i++) {
            if ((e->mFlags & 0x100) != 0) {
                func_020d233c(e);
                return e;
            }
        }
    }
    return NULL;
}

void func_0209bbd0(void *a, void *b) {
    MapObjectModel *o = b;

    if (o->mNsbmdModel == NULL) {
        return;
    }
    func_020e6a18(o->mNsbmdModel);
}

void DrawMapObjectModel(void *a, void *b, void *d) {
    MapObjectModel *o = b;
    MapObject *c = d;

    func_01ff9048(0x1b, o, 3);
    if (o->mNsbmdModel != NULL) {
        func_020ea5b0(o->mNsbmdModel, c->mUnk_66, NULL);
    }
    if (o->mAnimatedModel == NULL && o->mShadowModel == NULL) {
        return;
    }
    if (o->mAnimatedModel != NULL) {
        if (o->mAnimations[2] != NULL) {
            func_020ea670(o->mAnimatedModel, c->mUnk_66);
        } else {
            func_020ea7cc(o->mAnimatedModel, c->mUnk_66);
        }
    }
    if (o->mShadowModel == NULL) {
        return;
    }
    func_020ea618(o->mShadowModel, c->mUnk_66);
}

// Like DrawMapObjectModel but passes the object's position to the model draw, which lowers the alpha of an object whose
// camera depth is below its alpha level (near fade) and picks a polygon id for it.
void DrawMapObjectModelWithPos(u32 a, MapObjectModel *b, int d) {
    MapObjectModel *o = b;
    MapObject *c = (MapObject *) d;

    func_01ff9048(0x1b, o, 3);
    if (o->mNsbmdModel != NULL) {
        func_020ea5b0(o->mNsbmdModel, c->mUnk_66, &c->mPos);
    }
    if (o->mAnimatedModel == NULL && o->mShadowModel == NULL) {
        return;
    }
    if (o->mAnimatedModel != NULL) {
        if (o->mAnimations[2] != NULL) {
            func_020ea670(o->mAnimatedModel, c->mUnk_66);
        } else {
            func_020ea7cc(o->mAnimatedModel, c->mUnk_66);
        }
    }
    if (o->mShadowModel == NULL) {
        return;
    }
    func_020ea618(o->mShadowModel, c->mUnk_66);
}

void func_0209ba58(void *a, void *b, void *c) {
    MapObjectModel *o = b;

    if (o->mAnimatedModel == NULL) {
        return;
    }
    func_020ea740(o->mAnimatedModel, ((MapObject *) c)->mUnk_66);
}

void func_0209ba08(void *a, u32 b) {
    MapObjectModel *o = a;
    Unk020e6488 *m = o->mNsbmdModel;

    if (m != NULL) {
        m->mUnk_14 &= ~0xf;
        m->mUnk_14 |= b;
    }
    if (o->mAnimatedModel == NULL) {
        return;
    }
    func_020849b0(o->mAnimatedModel, b);
}

void func_0209b9a4(void *a, u16 b) {
    MapObjectModel *o = a;
    Unk020e6488 *m = o->mNsbmdModel;

    if (m != NULL) {
        m->mUnk_14 &= ~0x1f0000;
        m->mUnk_14 |= b << 16;
    }
    if (o->mAnimatedModel != NULL) {
        func_0201308c(o->mAnimatedModel->mUnk_004, b);
    }
    if (o->mShadowModel != NULL) {
        o->mShadowModel->mUnk_6e = b;
    }
}

// Stores a polygon id (6 bits at bit 24 of the polygon attribute) in every model the bundle holds; 0x3f at creation,
// func_020d3c44 hands out 1..0x3e; the draw may replace it.
void SetMapObjectModelPolygonId(void *a, u32 b) {
    MapObjectModel *o = a;
    Unk020e6488 *m = o->mNsbmdModel;

    if (m != NULL) {
        m->mUnk_14 &= ~0x3f000000;
        m->mUnk_14 |= b << 24;
    }
    if (o->mAnimatedModel != NULL) {
        func_020130d4(o->mAnimatedModel->mUnk_004, b);
    }
    if (o->mShadowModel != NULL) {
        o->mShadowModel->mUnk_6c = b;
    }
}

void func_0209b904(void *a, u32 b, u16 c) {
    MapObjectModel *o = a;

    if (o->mAnimatedModel == NULL) {
        return;
    }
    func_020134b0(o->mAnimatedModel->mUnk_004, c, b);
}

void func_0209b8ac(void *a, u32 b) {
    MapObjectModel *o = a;
    Unk020e6488 *m = o->mNsbmdModel;

    if (m != NULL) {
        if (b != 0) {
            m->mUnk_14 |= 0x8000;
        } else {
            m->mUnk_14 &= ~0x8000;
        }
    }
    if (o->mAnimatedModel == NULL) {
        return;
    }
    func_02013044(o->mAnimatedModel->mUnk_004, b);
}

void func_0209b7a0(void *a, s32 b, s32 c) {
    MapObjectModel *o = a;
    Unk020e6488 *m;
    s32 k;

    if (o->mNsbmdModel != NULL) {
        m = o->mNsbmdModel;
        k = b != 0 || c != 0 ? 1 : 0;
        if (k ^ data_021759c0->mUnk_57) {
            m->mUnk_14 &= ~0x80;
            o->mNsbmdModel->mUnk_14 |= 0x40;
        } else {
            m->mUnk_14 |= 0x80;
            o->mNsbmdModel->mUnk_14 &= ~0x40;
        }
    }
    if (o->mAnimatedModel != NULL) {
        k = b != 0 || c != 0 ? 1 : 0;
        if (k ^ data_021759c0->mUnk_57) {
            func_02084958(o->mAnimatedModel, 1);
        } else {
            func_02084958(o->mAnimatedModel, 2);
        }
    }
    o->mScale.mUnk_00 = b != 0 ? -0x1000 : 0x1000;
    o->mScale.mUnk_04 = c != 0 ? -0x1000 : 0x1000;
}

// Sets the current frame of slot 0 in 20.12 fixed point (the track frame follows).
void SetMapObjectModelNsbcaFrameIndex(void *a, u16 b) {
    MapObjectModel *o = a;
    Unk02087d0c *p = o->mAnimations[0];

    p->mUnk_0c = b << 12;
    p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_0c;
}

// Number of frames of the animation in slot 0 (its length, not the current frame).
u16 GetMapObjectModelNsbcaFrameCount(void *a) {
    MapObjectModel *o = a;

    return (u16) ((u32) func_02087d0c(o->mAnimations[0]) >> 12);
}

// Sets the current frame of slot 2 in 20.12 fixed point (the track frame follows).
void SetMapObjectModelNsbmaFrameIndex(void *a, u32 b) {
    MapObjectModel *o = a;
    Unk02087d0c *p = o->mAnimations[2];

    p->mUnk_0c = b << 12;
    p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_0c;
}

// Number of frames of the animation in slot 2 (its length, not the current frame).
s32 GetMapObjectModelNsbmaFrameCount(void *a) {
    MapObjectModel *o = a;

    return (u16) ((u32) func_02087d0c(o->mAnimations[2]) >> 12);
}

// Number of frames of the animation in slot 3 (its length, not the current frame).
u16 GetMapObjectModelNsbtaFrameCount(void *a) {
    MapObjectModel *o = a;

    return (u16) ((u32) func_02087d0c(o->mAnimations[3]) >> 12);
}

// Sets the current frame of slot 3 in 20.12 fixed point (the track frame follows).
void SetMapObjectModelNsbtaFrameIndex(void *a, s32 b) {
    MapObjectModel *o = a;
    Unk02087d0c *p = o->mAnimations[3];

    p->mUnk_0c = b << 12;
    p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_0c;
}

void func_0209b688(void *a, u16 b) {
    MapObjectModel *o = a;
    Unk02087d0c *p;

    if (o->mNsbmdModel != NULL) {
        o->mNsbmdModel->mUnk_18 = b;
        return;
    }
    if (o->mAnimatedModel == NULL) {
        return;
    }
    p = o->mAnimations[1];
    p->mUnk_0c = b << 12;
    p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_0c;
}

u16 func_0209b634(void *a) {
    MapObjectModel *o = a;

    if (o->mNsbmdModel != NULL) {
        return o->mNsbmdModel->mUnk_1a;
    }
    if (o->mAnimatedModel == NULL) {
        return 0;
    }
    return (u16) ((u32) func_02087d0c(o->mAnimations[1]) >> 12);
}
