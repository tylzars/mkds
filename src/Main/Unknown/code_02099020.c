#include "Main/Unknown/code_02099020.h"

#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/unk_02156000.h"

void func_02099278(u32 p0) {
    u32 v1 = ((u32) (&data_02156598));
    u32 v3 = (*(u16 *) ((p0) + (2)));
    u32 v4 = (*(u16 *) ((v1) + (0)));
    u32 v5 = ((v3) | (v4));
    u32 v7;
    u32 v9;
    *(u16 *) ((p0) + (2)) = v5;
    ParkMapObject((void *) p0);
    CreateMapObjectSoundSourceFalloff2((MapObject *) p0);
}

u32 func_02099208(Unk0209905c *a, Kart *b, u8 *c, u8 *d) {
    u32 v1 = *c;
    u8 v2 = *d;
    if (v1 == 1) {
        a->mUnk_00.mFlags = a->mUnk_00.mFlags | data_usa_02156590;
        a->mUnk_cc = 1;
        if (b->mItemEffect == 1 || b->mItemEffect == 3) {
            a->mUnk_00.mDistanceSquaredAndFlags = a->mUnk_00.mDistanceSquaredAndFlags | data_usa_02156594;
        }
        StartSoundIfKartStarOrKiller(&a->mUnk_00, b);
    }
    return v2;
}

void func_0209905c(void *a, Unk0209905c *p) {
    s32 t;
    Unk0210b7a8 s;
    Unk0209905c_d0_08 *n;
    switch (p->mUnk_cc) {
        case 0:
            p->mUnk_c4 = p->mUnk_c4 + p->mUnk_c8;
            p->mUnk_c8 = p->mUnk_c8 - 0x1000;
            if (p->mUnk_c4 <= 0) {
                p->mUnk_c4 = 0;
                p->mUnk_c8 = 0x5800;
                if ((p->mUnk_00.mDistanceSquaredAndFlags & 4) == 0) {
                    if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                        t = 2;
                    } else if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                        t = 3;
                    } else {
                        t = 4;
                    }
                    s.mUnk_00 = 0x1af;
                    s.mUnk_04 = &p->mUnk_00.mPos;
                    s.mUnk_08 = t;
                    s.mUnk_0c = GetHorizontalCameraDistanceSquared(&p->mUnk_00.mPos);
                    func_0210b7a8(&s);
                }
            }
            if (func_020d8cc8(&p->mUnk_a0) != FALSE && p->mUnk_a0.mUnk_18 == 0) {
                p->mUnk_cc = 1;
            } else {
                func_020d8918(&p->mUnk_a0, &p->mUnk_00.mPos, &p->mUnk_00.mUnk_10);
                p->mUnk_00.mPos.y = p->mUnk_00.mPos.y + (p->mUnk_c4 + 0xf000);
            }
            if (p->mUnk_d0 == NULL) {
                return;
            }
            if ((p->mUnk_00.mFlags & 0x12) != 0) {
                p->mUnk_d0->mUnk_24 |= 2;
                return;
            }
            func_0208b5b0(p->mUnk_d0, &p->mUnk_00.mPos);
            p->mUnk_d0->mUnk_24 &= ~2;
            return;
        case 1:
            if (p->mUnk_d0 != NULL) {
                for (n = p->mUnk_d0->mUnk_08; n != NULL; n = n->mUnk_00) {
                    n->mUnk_26 = n->mUnk_24;
                }
                func_0208b6b0((void **) &p->mUnk_d0);
            }
            ParkMapObject(&p->mUnk_00);
            return;
    }
}

void func_02099020(void) {
    func_0209bf70(&func_02099208, NULL, NULL, 1, 1, (0x0000018du));
}
