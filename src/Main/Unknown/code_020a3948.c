#include "Main/Unknown/code_020a3948.h"
#include "Main/Unknown/code_0209b000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02061808.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02148538.h"

void func_020a3eb8(Unk020a3eb8 *a) {
    data_0217b204 = func_0209bc74(a, data_02167878, data_02167888);
    func_0209b940(data_0217b204, 0x3f);
    func_0209b9a4(data_0217b204, 0x1a);
    func_0209b8ac(data_0217b204, 0);
    a->mUnk_1c = 1;
}

void func_020a3e38(void *p) {
    Unk02061808 *g;

    g = func_02061808();
    data_0217b214.x = g->mUnk_024.x >> 1;
    data_0217b214.y = g->mUnk_024.y >> 1;
    data_0217b214.z = g->mUnk_024.z >> 1;
    data_0217b208.x = g->mUnk_024.x >> 3;
    data_0217b208.y = g->mUnk_024.y >> 3;
    data_0217b208.z = g->mUnk_024.z >> 3;
    func_0209bbd0(p, data_0217b204);
}

void func_020a3948(void *p, Unk020a2fe4 *a) {
    s32 j;
    s32 n;
    s32 i;
    s32 k;
    s32 u;
    u32 m;
    s32 t;
    s32 w0;
    s32 w1;
    s32 w2;
    s32 m0[9];
    s32 m1[9];
    s32 f0[3];
    s32 g0[3];
    s32 f1[3];
    s32 g1[3];
    s32 h[3];
    Unk020a2fe4 *e;

    if (a->mUnk_a4 >= 0) {
        if (func_0207a974(a->mUnk_a4)->mUnk_384 == 0) {
            return;
        }
    }
    n = a->mUnk_f4;
    if (n == 1 && a->mUnk_f8 == 0) {
        m = a->mUnk_00.mUnk_78 & ~0xc000001f;
        if (m < 0x2710) {
            a->mUnk_e8.x = data_0217b214.x + (a->mUnk_00.mUnk_04.x >> 1);
            a->mUnk_e8.y = data_0217b214.y + (a->mUnk_00.mUnk_04.y >> 1);
            a->mUnk_e8.z = data_0217b214.z + (a->mUnk_00.mUnk_04.z >> 1);
            a->mUnk_e4 = 0x800;
        } else if (m < 0x9c40) {
            a->mUnk_e8.x = data_0217b208.x + a->mUnk_00.mUnk_04.x - (a->mUnk_00.mUnk_04.x >> 3);
            a->mUnk_e8.y = data_0217b208.y + a->mUnk_00.mUnk_04.y - (a->mUnk_00.mUnk_04.y >> 3);
            a->mUnk_e8.z = data_0217b208.z + a->mUnk_00.mUnk_04.z - (a->mUnk_00.mUnk_04.z >> 3);
            a->mUnk_e4 = 0xe00;
        } else {
            a->mUnk_e8 = a->mUnk_00.mUnk_04;
            a->mUnk_e4 = 0x1000;
        }
        w0 = 0x1e;
        func_01ff9048(0x14, &w0, 1);
        func_01ff9048(0x19, func_020e6cf8(&a->mUnk_e8), 12);
        if (a->mUnk_00.mUnk_7e != 0) {
            i = (a->mUnk_00.mUnk_7e >> 4) * 2;
            func_02146d60(m0, data_0215d4b4[i + 1], data_0215d4b4[i]);
            func_01ff9048(0x1a, m0, 9);
        }
        u = a->mUnk_e4;
        f0[0] = u;
        f0[1] = u;
        f0[2] = u;
        func_01ff9048(0x1b, f0, 3);
        t = a->mUnk_d0 + a->mUnk_d8;
        if (t != 0x1000) {
            g0[0] = t;
            g0[1] = t;
            g0[2] = t;
            func_01ff9048(0x1b, g0, 3);
        }
        func_0209b940(data_0217b204, func_020d3c44());
        func_0209b688(data_0217b204, a->mUnk_a8);
        func_0209bb2c(p, data_0217b204, a);
    } else if (n > 0) {
        m = a->mUnk_00.mUnk_78 & ~0xc000001f;
        if (m < 0x2710) {
            a->mUnk_e8.x = data_0217b214.x + (a->mUnk_b0.x >> 1);
            a->mUnk_e8.y = data_0217b214.y + (a->mUnk_b0.y >> 1);
            a->mUnk_e8.z = data_0217b214.z + (a->mUnk_b0.z >> 1);
            a->mUnk_e4 = 0x800;
        } else if (m < 0x9c40) {
            a->mUnk_e8.x = data_0217b208.x + a->mUnk_b0.x - (a->mUnk_b0.x >> 3);
            a->mUnk_e8.y = data_0217b208.y + a->mUnk_b0.y - (a->mUnk_b0.y >> 3);
            a->mUnk_e8.z = data_0217b208.z + a->mUnk_b0.z - (a->mUnk_b0.z >> 3);
            a->mUnk_e4 = 0xe00;
        } else {
            a->mUnk_e8 = a->mUnk_b0;
            a->mUnk_e4 = 0x1000;
        }
        w1 = 0x1e;
        func_01ff9048(0x14, &w1, 1);
        func_01ff9048(0x19, func_020e6cbc(&a->mUnk_e8), 12);
        u = a->mUnk_e4;
        f1[0] = u;
        f1[1] = u;
        f1[2] = u;
        func_01ff9048(0x1b, f1, 3);
        for (j = 0; j < n; j++) {
            i = data_02156720[n - 1][j];
            e = a->mUnk_f8[i];
            func_01ff9048(0x11, 0, 0);
            k = data_02156700[n - 1][i];
            func_02146d60(m1, data_0215d4b4[(k >> 4) * 2 + 1], data_0215d4b4[(k >> 4) * 2]);
            func_01ff9048(0x1a, m1, 9);
            t = e->mUnk_d0;
            if (t != 0x1000) {
                g1[0] = t;
                g1[1] = t;
                g1[2] = t;
                func_01ff9048(0x1b, g1, 3);
            }
            h[0] = 0;
            h[1] = 0xf66;
            h[2] = 0;
            func_01ff9048(0x1c, h, 3);
            func_0209b940(data_0217b204, func_020d3c44());
            func_0209b688(data_0217b204, e->mUnk_a8);
            func_0209bb2c(p, data_0217b204, a);
            w2 = 1;
            func_01ff9048(0x12, &w2, 1);
        }
    }
}
