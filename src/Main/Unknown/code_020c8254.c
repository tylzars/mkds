#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c8254.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_02100094.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_020222ec.h"
#include "code_02148538.h"

void func_020c8bdc(void) {
    s32 i;
    u32 a;
    Unk020e1e98 *p;
    s32 s;
    Vec3 *v;
    s32 x;
    s32 y;
    Vec3 w;

    a = func_020c0db0();
    for (i = 0; i < data_0217b424->mUnk_08; i++) {
        p = data_0217b424->mUnk_00[i];
        s = p->mUnk_000.mUnk_58.z;
        v = &p->mUnk_000.mPos;
        x = (s64) p->mUnk_000.mMatrix.mUnk_00[2].x * s >> 12;
        y = (s64) p->mUnk_000.mMatrix.mUnk_00[2].z * s >> 12;
        if (data_021759c0->mUnk_57 != 0) {
            data_0217b424->mUnk_0c[i] = func_02148714(-y, x) + 0x8000;
        } else {
            data_0217b424->mUnk_0c[i] = func_02148714(y, x);
        }
        func_020b5ae8(v, &data_0217b424->mUnk_14[i], a, 0, 0);
        w.x = v->x + x;
        w.z = v->z + y;
        func_020b5ae8(&w, &data_0217b424->mUnk_2c[i], a, 0, 0);
    }
}

void func_020c82dc(Unk020c06c4 *p) {
    Unk020224e0_c *c;
    s32 r[4];
    u32 a;
    u16 v1;
    u16 v2;
    u16 v3;
    u16 t;
    s32 x;
    s32 y;
    s32 v4;
    s32 v5;
    s32 v6;
    s32 v7;
    s32 j;
    u16 v8;
    s32 v9;
    s32 v10;
    s32 v11;
    s32 v12;
    s32 v13;
    s32 v14;
    s32 v15;
    u16 v16;
    s32 v17;
    s32 v18;
    s32 v19;
    s32 v20;
    s32 v21;
    s32 v22;
    s32 v23;
    s32 q0[2];
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 q4[2];
    s32 q5[2];
    s32 q6[2];
    s32 q7[2];
    s32 q8[2];

    a = func_020c0dc4();
    if (data_0217b424->mUnk_04 <= 0) {
        return;
    }
    if (a == 0) {
        if (data_021759c0->mUnk_57 != 0) {
            t = data_0217b424->mUnk_0c[0] - func_020b6368();
        } else {
            t = data_0217b424->mUnk_0c[0] + func_020b6368();
        }
        v1 = func_020ae5c4(p);
        func_020b4cb0(r, t);
        x = data_0217b424->mUnk_2c[0].mUnk_00;
        y = data_0217b424->mUnk_2c[0].mUnk_04;
        if (x > -32 && x < 288 && y > -32 && y < 224) {
            c = GetRaceSNcerEntry(156);
            q0[0] = x << 12;
            q0[1] = y << 12;
            p->mUnk_400 +=
                func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c, r, q0, v1, 1);
        }
        v4 = data_0217b424->mUnk_14[0].mUnk_00 - data_0217b424->mUnk_2c[0].mUnk_00;
        v5 = data_0217b424->mUnk_14[0].mUnk_04 - data_0217b424->mUnk_2c[0].mUnk_04;
        for (j = 0, v6 = 0, v7 = 0; j < 3; j++) {
            x = data_0217b424->mUnk_2c[0].mUnk_00 + (v6 + v4) / 4;
            y = data_0217b424->mUnk_2c[0].mUnk_04 + (v7 + v5) / 4;
            if (x > -32 && x < 288 && y > -32 && y < 224) {
                c = GetRaceSNcerEntry(155);
                q1[0] = x << 12;
                q1[1] = y << 12;
                p->mUnk_400 += func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c,
                                             r, q1, v1, 1);
            }
            v6 += v4;
            v7 += v5;
        }
        x = data_0217b424->mUnk_14[0].mUnk_00;
        y = data_0217b424->mUnk_14[0].mUnk_04;
        if (x > -32 && x < 288 && y > -32 && y < 224) {
            c = GetRaceSNcerEntry(154);
            q2[0] = x << 12;
            q2[1] = y << 12;
            p->mUnk_400 +=
                func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c, r, q2, v1, 1);
        }
        p->mUnk_000.mUnk_20[v1].mUnk_06 = r[0] >> 4;
        p->mUnk_000.mUnk_20[v1].mUnk_0e = r[1] >> 4;
        p->mUnk_000.mUnk_20[v1].mUnk_16 = r[2] >> 4;
        p->mUnk_000.mUnk_20[v1].mUnk_1e = r[3] >> 4;
    }
    if (data_0217b424->mUnk_08 == 3 && a == 0) {
        if (data_021759c0->mUnk_57 != 0) {
            v8 = data_0217b424->mUnk_0c[2] - func_020b6368();
        } else {
            v8 = data_0217b424->mUnk_0c[2] + func_020b6368();
        }
        v3 = func_020ae5c4(p);
        func_020b4cb0(r, v8);
        v9 = data_0217b424->mUnk_2c[2].mUnk_00;
        v10 = data_0217b424->mUnk_2c[2].mUnk_04;
        if (v9 > -32 && v9 < 288 && v10 > -32 && v10 < 224) {
            c = GetRaceSNcerEntry(156);
            q3[0] = v9 << 12;
            q3[1] = v10 << 12;
            p->mUnk_400 +=
                func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c, r, q3, v3, 1);
        }
        v11 = data_0217b424->mUnk_14[2].mUnk_00 - data_0217b424->mUnk_2c[2].mUnk_00;
        v12 = data_0217b424->mUnk_14[2].mUnk_04 - data_0217b424->mUnk_2c[2].mUnk_04;
        for (v15 = 0, v13 = 0, v14 = 0; v15 < 2; v15++) {
            v9 = data_0217b424->mUnk_2c[2].mUnk_00 + (v13 + v11) / 3;
            v10 = data_0217b424->mUnk_2c[2].mUnk_04 + (v14 + v12) / 3;
            if (v9 > -32 && v9 < 288 && v10 > -32 && v10 < 224) {
                c = GetRaceSNcerEntry(155);
                q4[0] = v9 << 12;
                q4[1] = v10 << 12;
                p->mUnk_400 += func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c,
                                             r, q4, v3, 1);
            }
            v13 += v11;
            v14 += v12;
        }
        v9 = data_0217b424->mUnk_14[2].mUnk_00;
        v10 = data_0217b424->mUnk_14[2].mUnk_04;
        if (v9 > -32 && v9 < 288 && v10 > -32 && v10 < 224) {
            c = GetRaceSNcerEntry(154);
            q5[0] = v9 << 12;
            q5[1] = v10 << 12;
            p->mUnk_400 +=
                func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c, r, q5, v3, 1);
        }
        p->mUnk_000.mUnk_20[v3].mUnk_06 = r[0] >> 4;
        p->mUnk_000.mUnk_20[v3].mUnk_0e = r[1] >> 4;
        p->mUnk_000.mUnk_20[v3].mUnk_16 = r[2] >> 4;
        p->mUnk_000.mUnk_20[v3].mUnk_1e = r[3] >> 4;
    }
    if (data_021759c0->mUnk_57 != 0) {
        v16 = data_0217b424->mUnk_0c[1] - func_020b6368();
    } else {
        v16 = data_0217b424->mUnk_0c[1] + func_020b6368();
    }
    v2 = func_020ae5c4(p);
    func_020b4cb0(r, v16);
    v17 = data_0217b424->mUnk_2c[1].mUnk_00;
    v18 = data_0217b424->mUnk_2c[1].mUnk_04;
    if (v17 > -16 && v17 < 272 && v18 > -16 && v18 < 208) {
        c = GetRaceSNcerEntry(159);
        q6[0] = v17 << 12;
        q6[1] = v18 << 12;
        p->mUnk_400 +=
            func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c, r, q6, v2, 1);
    }
    v19 = data_0217b424->mUnk_14[1].mUnk_00 - data_0217b424->mUnk_2c[1].mUnk_00;
    v20 = data_0217b424->mUnk_14[1].mUnk_04 - data_0217b424->mUnk_2c[1].mUnk_04;
    for (v23 = 0, v21 = 0, v22 = 0; v23 < 3; v23++) {
        v17 = data_0217b424->mUnk_2c[1].mUnk_00 + (v21 + v19) / 4;
        v18 = data_0217b424->mUnk_2c[1].mUnk_04 + (v22 + v20) / 4;
        if (v17 > -16 && v17 < 272 && v18 > -16 && v18 < 208) {
            c = GetRaceSNcerEntry(158);
            q7[0] = v17 << 12;
            q7[1] = v18 << 12;
            p->mUnk_400 +=
                func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c, r, q7, v2, 1);
        }
        v21 += v19;
        v22 += v20;
    }
    v17 = data_0217b424->mUnk_14[1].mUnk_00;
    v18 = data_0217b424->mUnk_14[1].mUnk_04;
    if (v17 > -16 && v17 < 272 && v18 > -16 && v18 < 208) {
        c = GetRaceSNcerEntry(157);
        q8[0] = v17 << 12;
        q8[1] = v18 << 12;
        p->mUnk_400 +=
            func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c, r, q8, v2, 1);
    }
    p->mUnk_000.mUnk_20[v2].mUnk_06 = r[0] >> 4;
    p->mUnk_000.mUnk_20[v2].mUnk_0e = r[1] >> 4;
    p->mUnk_000.mUnk_20[v2].mUnk_16 = r[2] >> 4;
    p->mUnk_000.mUnk_20[v2].mUnk_1e = r[3] >> 4;
}

s32 func_020c8254(void) {
    u16 a[3] = {0x19a, 0x195, 0x19c};
    u16 i;
    u16 b;

    for (i = 0; i < 3; i++) {
        b = a[i];
        if (func_021000d0(b) != NULL) {
            return func_020c0c2c(&data_0217b420, b);
        }
    }
    return 0;
}
