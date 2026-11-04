#include "Main/Unknown/code_020d7db4.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020d9000.h"

#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d849c.h"
#include "code_02147cd8.h"

#pragma thumb off

void func_020d8460(void *m, Vec3 *v) {
    Unk020d849c *p = m;
    func_020d91dc(&p->mUnk_00, p->mUnk_5c, v);
}

#pragma thumb on

void func_020d80e4(Unk020e0144_00_0 *p, s32 a, s32 b, Vec3 *c, Vec3 *d, Vec3 *e, Vec3 *f) {
    Vec3 t1;
    Vec3 t2;
    Vec3 t3;
    Vec3 t4;
    Vec3 t5;
    Vec3 t6;
    s32 n;
    s32 u = 0;
    s32 v = 0;
    s32 r;
    s32 w;
    s64 q;
    p->mUnk_00[0] = *d;
    p->mUnk_00[3] = *e;
    Vec3Sub(e, d, &t1);
    n = func_020d70ac(&t1, &t2);
    if (n == 0) {
        p->mUnk_00[1] = p->mUnk_00[0];
        p->mUnk_00[2] = p->mUnk_00[3];
        p->mUnk_30 = 0;
        p->mUnk_34 = 0;
        if (b != 0) {
            p->mUnk_48 = data_0215807c;
        }
        return;
    }
    if (c != NULL) {
        Vec3Sub(e, c, &t3);
        if (func_020d70ac(&t3, &t3) != 0) {
            w = (0x1000 - func_02039828(&t2, &t3)) >> 1;
            u = (s32) (((s64) n * (s64) w) >> 12);
            if (a != 0) {
                t4.x = (s32) (((s64) t3.x * n) >> 12);
                t4.y = (s32) (((s64) t3.y * n) >> 12);
                t4.z = (s32) (((s64) t3.z * n) >> 12);
            } else {
                r = n + u;
                t4.x = (s32) (((s64) t3.x * (s64) r) >> 12);
                t4.y = (s32) (((s64) t3.y * (s64) r) >> 12);
                t4.z = (s32) (((s64) t3.z * (s64) r) >> 12);
            }
            Vec3AddScaled(0x555, &t4, &p->mUnk_00[0], &p->mUnk_00[1]);
        } else {
            p->mUnk_00[1] = p->mUnk_00[0];
        }
    } else {
        p->mUnk_00[1] = p->mUnk_00[0];
    }
    if (f != NULL) {
        Vec3Sub(f, d, &t5);
        if (func_020d70ac(&t5, &t5) != 0) {
            w = (0x1000 - func_02039828(&t2, &t5)) >> 1;
            v = (s32) (((s64) n * (s64) w) >> 12);
            if (a != 0) {
                t6.x = (s32) (((s64) t5.x * n) >> 12);
                t6.y = (s32) (((s64) t5.y * n) >> 12);
                t6.z = (s32) (((s64) t5.z * n) >> 12);
            } else {
                r = n + v;
                t6.x = (s32) (((s64) t5.x * (s64) r) >> 12);
                t6.y = (s32) (((s64) t5.y * (s64) r) >> 12);
                t6.z = (s32) (((s64) t5.z * (s64) r) >> 12);
            }
            Vec3AddScaled(-0x555, &t6, &p->mUnk_00[3], &p->mUnk_00[2]);
        } else {
            p->mUnk_00[2] = p->mUnk_00[3];
        }
    } else {
        p->mUnk_00[2] = p->mUnk_00[3];
    }
    p->mUnk_40 = n;
    p->mUnk_44 = DivFixed12(0x1000000, p->mUnk_40);
    p->mUnk_38 = v + (n + u);
    p->mUnk_3c = DivFixed12(0x1000000, p->mUnk_38);
    p->mUnk_30 = p->mUnk_38;
    p->mUnk_34 = p->mUnk_3c;
    if (b != 0) {
        r = Vec3Dot(&t2, &data_02158088);
        p->mUnk_48.x = data_02158088.x - (s32) (((s64) t2.x * (s64) r) >> 12);
        p->mUnk_48.y = data_02158088.y - (s32) (((s64) t2.y * (s64) r) >> 12);
        p->mUnk_48.z = data_02158088.z - (s32) (((s64) t2.z * (s64) r) >> 12);
        q = (s64) p->mUnk_48.x * p->mUnk_48.x + (s64) p->mUnk_48.y * p->mUnk_48.y + (s64) p->mUnk_48.z * p->mUnk_48.z;
        if (q < 16) {
            r = 0;
        } else {
            r = func_02039860(&p->mUnk_48, &p->mUnk_48);
        }
        if (r == 0) {
            p->mUnk_48 = data_02158088;
        }
    }
}

void func_020d7e44(u32 a, int m) {
    Unk020d7e44 *b = (Unk020d7e44 *) m;
    Unk020e0144_00 *p;
    s32 n;
    s32 i;
    p = &data_0217b670[a];
    if (p->mUnk_00 != NULL) {
        return;
    }
    n = b->mUnk_02;
    p->mUnk_04 = n;
    p->mUnk_08 = b->mUnk_01;
    if (p->mUnk_08 == 0) {
        p->mUnk_04 = p->mUnk_04 - 1;
    }
    p->mUnk_00 = HeapAlloc(GetHeap(func_020364e8()), p->mUnk_04 * 0x54);
    if (n == 2) {
        func_020d80e4(p->mUnk_00, 0, 1, NULL, &func_02042044(a, 0)->mUnk_00, &func_02042044(a, 1)->mUnk_00, NULL);
        if (p->mUnk_08 != 0) {
            func_020d80e4(&p->mUnk_00[1], 0, 1, NULL, &func_02042044(a, 1)->mUnk_00, &func_02042044(a, 0)->mUnk_00,
                          NULL);
        }
        return;
    }
    if (p->mUnk_08 != 0) {
        func_020d80e4(p->mUnk_00, 0, 1, &func_02042044(a, n - 1)->mUnk_00, &func_02042044(a, 0)->mUnk_00,
                      &func_02042044(a, 1)->mUnk_00, &func_02042044(a, 2)->mUnk_00);
    } else {
        func_020d80e4(p->mUnk_00, 0, 1, NULL, &func_02042044(a, 0)->mUnk_00, &func_02042044(a, 1)->mUnk_00,
                      &func_02042044(a, 2)->mUnk_00);
    }
    for (i = 1; i < n - 2; i++) {
        func_020d80e4(&p->mUnk_00[i], 0, 1, &func_02042044(a, i - 1)->mUnk_00, &func_02042044(a, i)->mUnk_00,
                      &func_02042044(a, i + 1)->mUnk_00, &func_02042044(a, i + 2)->mUnk_00);
    }
    if (p->mUnk_08 != 0) {
        func_020d80e4(&p->mUnk_00[i], 0, 1, &func_02042044(a, i - 1)->mUnk_00, &func_02042044(a, i)->mUnk_00,
                      &func_02042044(a, i + 1)->mUnk_00, &func_02042044(a, 0)->mUnk_00);
    } else {
        func_020d80e4(&p->mUnk_00[i], 0, 1, &func_02042044(a, i - 1)->mUnk_00, &func_02042044(a, i)->mUnk_00,
                      &func_02042044(a, i + 1)->mUnk_00, NULL);
    }
    if (p->mUnk_08 != 0) {
        func_020d80e4(&p->mUnk_00[i + 1], 0, 1, &func_02042044(a, i)->mUnk_00, &func_02042044(a, i + 1)->mUnk_00,
                      &func_02042044(a, 0)->mUnk_00, &func_02042044(a, 1)->mUnk_00);
    }
}

void func_020d7df8(void) {
    s32 n = gCourseMap->mUnk_0c;
    s32 i;
    if (n != 0) {
        data_0217b670 = HeapAlloc(GetHeap(func_020364e8()), n * 0xc);
    }
    for (i = 0; i < n; i++) {
        data_0217b670[i].mUnk_00 = NULL;
    }
}

#pragma thumb off

#pragma thumb on

void func_020d7db4(Unk020e0144 *a, u16 b, int c) {
    a->mUnk_08 = b;
    func_020d7e44(a->mUnk_08, (s32) &gCourseMap->mUnk_08[a->mUnk_08]);
    a->mUnk_00 = &data_0217b670[a->mUnk_08];
    a->mUnk_04 = c;
    func_020d90a8(a, 0, 1);
}

#pragma thumb off
