#include "Main/Unknown/code_020d2b78.h"

#include "Main/Unknown/code_020d2c2c.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/code_020d6000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d2d94.h"

#pragma thumb on

void func_020d2d94(void) {
    int v1;
    Unk020e6fd4 **v2;
    void **v3;
    Unk020e6fd4 **v4;
    v2 = data_0217b4f0->mUnk_008;
    v4 = data_0217b4f0->mUnk_134;
    v1 = 0;
    do {
        if (*v2 != NULL) {
            v3 = *(void ***) ((s32) *v2 + 0x28);
            if (v3 != NULL) {
                *v3 = NULL;
            }
            *v2 = NULL;
        }
        v2 = v2 + 1;
        v1 = v1 + 1;
    } while (v1 < 0x18);
    v1 = 0;
    do {
        if (*v4 != NULL) {
            v3 = (*v4)->mUnk_24;
            if (v3 != NULL) {
                *v3 = NULL;
            }
            *v4 = NULL;
        }
        v4 = v4 + 1;
        v1 = v1 + 1;
    } while (v1 < 0x10);
}

#pragma thumb off

#pragma thumb on

s32 func_020d2c2c(Vec3 *b, Vec3 *c, s32 d, s16 e, s32 f, Vec3 *g) {
    s32 a;
    s32 i;
    a = 0;
    func_01ffd900(e, 0x2000);
    i = 0;
    if (data_0217b5a8 != 0) {
        Vec3 v;
        Vec3 mn;
        Vec3 mx;
        Unk020f41c4_A *q;
        Unk020e71a0 *p;
        s32 r;
        s32 t;
        {
            Vec3 z1 = {0, 0, 0};
            mn = z1;
        }
        {
            Vec3 z2 = {0, 0, 0};
            mx = z2;
        }
        q = &data_0217b4f0->mUnk_18c;
        for (; i < data_0217b5a8; i++) {
            p = data_0217b5c4[i];
            if (func_020d3e34(b, d, p, &v) != 0) {
                if (!(p->mUnk_02 & 0x40) && func_020d6968(f, p) != 0) {
                    t = v.x;
                    mn.x = ((const Vec3 *) &v)->x < mn.x ? t : mn.x;
                    mn.y = v.y < mn.y ? v.y : mn.y;
                    mn.z = v.z < mn.z ? v.z : mn.z;
                    mx.x = t > mx.x ? t : mx.x;
                    mx.y = v.y > mx.y ? v.y : mx.y;
                    mx.z = v.z > mx.z ? v.z : mx.z;
                }
                q->mUnk_50 = *b;
                q->mUnk_5c = *c;
                q->mUnk_44 = f;
                r = func_020d6a54(q, p, NULL);
                if (r > a) {
                    a = r;
                }
            }
        }
        if (a != 0 && g != NULL) {
            g->x = mx.x + mn.x;
            g->y = mx.y + mn.y;
            if (g->y < 0) {
                g->y = 0;
            }
            g->z = mx.z + mn.z;
        }
    }
    return a;
}

#pragma thumb off

#pragma thumb on

u32 func_020d2c20(void) {
    return ((u32) data_0217b4ec);
}

u32 func_020d2be8(void) {
    int v1;
    if (data_0217b4d8 != NULL) {
        return data_0217b4d8->mUnk_04;
    }
    v1 = *(s32 *) &data_0217b4e4;
    if ((v1 != 0) && (*(s32 *) (v1 + 0x170) != 0)) {
        return *(u32 *) (v1 + 0x174);
    }
    return 0;
}

u32 func_020d2bb0(void) {
    int v1;
    if (data_0217b4d8 != NULL) {
        return data_0217b4d8->mUnk_08;
    }
    v1 = *(s32 *) &data_0217b4e4;
    if ((v1 != 0) && (*(s32 *) (v1 + 0x170) != 0)) {
        return *(u32 *) (v1 + 0x178);
    }
    return 0;
}

u32 func_020d2b78(void) {
    int v1;
    if (data_0217b4d8 != NULL) {
        return data_0217b4d8->mUnk_0c;
    }
    v1 = *(s32 *) &data_0217b4e4;
    if ((v1 != 0) && (*(s32 *) (v1 + 0x170) != 0)) {
        return *(u32 *) (v1 + 0x17c);
    }
    return 0;
}

#pragma thumb off
