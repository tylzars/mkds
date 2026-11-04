#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "code_02147cd8.h"

u32 func_020d8828(Unk020e0144 *a, Vec3 *b) {
    Unk020e0144_00 *p;
    s32 i;
    s64 m;
    Unk020e0144_00_0 *q;
    s64 s;
    s32 x;
    s32 z;
    s32 d;
    p = a->mUnk_00;
    m = 0;
    i = p->mUnk_04 - 1;
    q = p->mUnk_00;
    if (i >= 0) {
        q = &q[i];
        x = b->x;
        z = b->z;
        do {
            d = x - q->mUnk_00[0].x;
            s = (s64) d * d;
            d = z - q->mUnk_00[0].z;
            s = s + (s64) d * d;
            if (m < s) {
                m = s;
            }
            d = x - q->mUnk_00[3].x;
            s = (s64) d * d;
            d = z - q->mUnk_00[3].z;
            s = s + (s64) d * d;
            if (m < s) {
                m = s;
            }
            q--;
            i--;
        } while (i >= 0);
    }
    *(vu16 *) 0x40002b0 = 1;
    *(vs64 *) 0x40002b8 = m;
    while (*(vu16 *) 0x40002b0 & 0x8000) {
    }
    return *(vu32 *) 0x40002b4;
}

void func_020d879c(Unk020e0144 *a, Vec3 *b) {
    Unk020e0144_00_0 *p;
    s32 t;
    s32 u;
    p = &a->mUnk_00->mUnk_00[a->mUnk_0c];
    t = a->mUnk_14;
    u = 0x1000000 - t;
    b->x = (s32) (((s64) p->mUnk_00[0].x * u) >> 24);
    b->z = (s32) (((s64) p->mUnk_00[0].z * u) >> 24);
    b->x = b->x + (s32) (((s64) p->mUnk_00[3].x * t) >> 24);
    b->z = b->z + (s32) (((s64) p->mUnk_00[3].z * t) >> 24);
}

Vec3 *func_020d8654(Unk020fa294 *a) {
    u16 i;
    u16 k;
    u16 n;
    Vec3 *p;
    Vec3 v;
    Unk02042044 *e;
    Unk02042044 *f;
    s32 t;
    k = a->mUnk_26;
    n = gCourseMap->mUnk_08[k].mUnk_02;
    p = HeapAlloc(GetHeap(func_020364e8()), n * 12);
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            if (*(u8 *) ((u32) gCourseMap->mUnk_08 + k * 4 + 1) == 0) {
                continue;
            }
            e = func_02042044(k, 0);
            f = func_02042044(k, (u16) (n - 1));
            Vec3Sub(&e->mUnk_00, &f->mUnk_00, &v);
        } else {
            e = func_02042044(k, (u16) (i + 1));
            f = func_02042044(k, i);
            Vec3Sub(&e->mUnk_00, &f->mUnk_00, &v);
        }
        t = v.z;
        v.z = -v.x;
        v.y = 0;
        v.x = t;
        v.y = 0;
        func_02039860(&v, &p[i]);
    }
    return p;
}
