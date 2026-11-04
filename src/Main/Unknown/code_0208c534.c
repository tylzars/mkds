#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"

void func_0208d758(void *a) {
    u16 i;
    u16 j;
    Unk0208c5b8 *e;

    data_0217b078 = HeapAlloc(a, data_021759c0->mKartCount * 0x88);
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        e = &data_0217b078[i];
        e->mUnk_60 = i;
        if (i == data_021759c0->mEntryIndex || data_021759c0->mUnk_00c == 5 || data_021759c0->mMode == 1) {
            e->mUnk_4c = 0x14;
            e->mUnk_50 = 0x11;
            e->mUnk_54 = 0x12;
            e->mUnk_68 = func_0208d46c;
            e->mUnk_6c = func_0208d3d8;
            e->mUnk_70 = func_0208d358;
            e->mUnk_74 = func_0208d2d8;
            e->mUnk_78 = func_0208d234;
            e->mUnk_84 = func_0208d0dc;
            e->mUnk_7c = func_0208cefc;
            e->mUnk_80 = func_0208cd7c;
        } else {
            e->mUnk_4c = 0x15;
            e->mUnk_50 = 0x13;
            e->mUnk_54 = -1;
            e->mUnk_68 = func_0208d428;
            e->mUnk_6c = func_0208d3a8;
            e->mUnk_70 = func_0208d328;
            e->mUnk_74 = func_0208d298;
            e->mUnk_78 = func_0208d1ec;
            e->mUnk_84 = func_0208d02c;
            e->mUnk_7c = func_0208ceac;
            e->mUnk_80 = func_0208cd2c;
        }
        e->mUnk_58 = 0x16;
        e->mUnk_5c = 0x17;
        for (j = 0; j < 2; j++) {
            e->mUnk_10[j] = NULL;
            e->mUnk_18[j] = NULL;
            e->mUnk_00[j] = NULL;
            e->mUnk_20[j] = NULL;
            e->mUnk_28[j] = NULL;
        }
        e->mUnk_30 = 0;
        e->mUnk_34 = 0;
        e->mUnk_38 = 0;
        e->mUnk_3c = 0;
        e->mUnk_40 = 0;
        e->mUnk_44 = 0;
        e->mUnk_48 = 0;
        e->mUnk_4a = 0;
        e->mUnk_62 = 0;
        e->mUnk_64 = 0;
    }
}

void func_0208d6b0(Unk0208c5b8 *p) {
    u16 i;

    if (p->mUnk_3c != 0) {
        for (i = 0; i < 2; i++) {
            func_0208b6d0(&p->mUnk_00[i]);
        }
    }
    p->mUnk_3c = 0;
    for (i = 0; i < 2; i++) {
        p->mUnk_00[i] = func_0208b7bc(p->mUnk_4c, &data_02155fcc);
        p->mUnk_00[i]->mUnk_72 = 0x7fff;
        p->mUnk_00[i]->mUnk_80_8 = 0x1c;
        p->mUnk_00[i]->mUnk_6c = 0x1000;
    }
    p->mUnk_3c = 1;
}

void func_0208d650(Unk0208c5b8 *p) {
    u16 i;

    if (p->mUnk_3c == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        p->mUnk_00[i]->mUnk_24.mUnk_00_0 = 1;
        p->mUnk_00[i] = NULL;
    }
    p->mUnk_3c = 0;
}

void func_0208d4c4(Unk0208c5b8 *p, Unk0206bcb0 *q) {
    u16 i;
    Unk0217ae84 *e;
    Vec3 a;
    Vec3 b;
    Vec3 c;
    Unk0201ca6c *f;

    if (p->mUnk_3c == 0) {
        return;
    }
    e = func_020846a8(q->mIndex);
    for (i = 0; i < 2; i++) {
        a.x = (s32) (((s64) q->mUnk_3b0.x * 0xb33) >> 12);
        a.y = (s32) (((s64) q->mUnk_3b0.y * 0xb33) >> 12);
        a.z = (s32) (((s64) q->mUnk_3b0.z * 0xb33) >> 12);
        p->mUnk_00[i]->mUnk_40 = a;
        b.x = -a.x;
        b.y = -a.y;
        b.z = -a.z;
        Vec3Add(&e->mUnk_34[i], &b, &c);
        f = p->mUnk_00[i];
        f->mUnk_28.x = c.x + f->mUnk_20->mUnk_00->mUnk_04.x;
        f->mUnk_28.y = c.y + f->mUnk_20->mUnk_00->mUnk_04.y;
        f->mUnk_28.z = c.z + f->mUnk_20->mUnk_00->mUnk_04.z;
        if ((q->mUnk_44 & 0x10) == 0) {
            p->mUnk_00[i]->mUnk_24.mUnk_00_1 = 1;
        } else {
            p->mUnk_00[i]->mUnk_24.mUnk_00_1 = 0;
        }
    }
}

void func_0208d46c(Unk0208c5b8 *p) {
    u16 i;

    for (i = 0; i < 2; i++) {
        p->mUnk_10[i] = func_0208b7bc(p->mUnk_50, &data_02155fcc);
        p->mUnk_18[i] = func_0208b7bc(p->mUnk_54, &data_02155fcc);
    }
}

void func_0208d428(Unk0208c5b8 *p) {
    u16 i;

    for (i = 0; i < 2; i++) {
        p->mUnk_10[i] = func_0208b7bc(p->mUnk_50, &data_02155fcc);
    }
}

void func_0208d3d8(Unk0208c5b8 *p) {
    u16 i;

    for (i = 0; i < 2; i++) {
        p->mUnk_10[i]->mUnk_24.mUnk_00_1 = 1;
        p->mUnk_18[i]->mUnk_24.mUnk_00_1 = 1;
    }
}

void func_0208d3a8(Unk0208c5b8 *p) {
    u16 i;

    for (i = 0; i < 2; i++) {
        p->mUnk_10[i]->mUnk_24.mUnk_00_1 = 1;
    }
}

void func_0208d358(Unk0208c5b8 *p) {
    u16 i;

    for (i = 0; i < 2; i++) {
        p->mUnk_10[i]->mUnk_24.mUnk_00_1 = 0;
        p->mUnk_18[i]->mUnk_24.mUnk_00_1 = 0;
    }
}

void func_0208d328(Unk0208c5b8 *p) {
    u16 i;

    for (i = 0; i < 2; i++) {
        p->mUnk_10[i]->mUnk_24.mUnk_00_1 = 0;
    }
}

void func_0208d2d8(Unk0208c5b8 *p) {
    u16 i;

    for (i = 0; i < 2; i++) {
        func_0208b710(p->mUnk_10[i]);
        func_0208b710(p->mUnk_18[i]);
        p->mUnk_10[i] = NULL;
        p->mUnk_18[i] = NULL;
    }
}

void func_0208d298(Unk0208c5b8 *p) {
    u16 i;

    for (i = 0; i < 2; i++) {
        func_0208b710(p->mUnk_10[i]);
        p->mUnk_10[i] = NULL;
    }
}

void func_0208d234(Unk0208c5b8 *p) {
    u16 i;

    if (p->mUnk_38 == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        p->mUnk_10[i]->mUnk_24.mUnk_00_1 = 1;
        p->mUnk_18[i]->mUnk_24.mUnk_00_1 = 1;
    }
}

void func_0208d1ec(Unk0208c5b8 *p) {
    if (p->mUnk_38 == 0) {
        return;
    }
    if (p->mUnk_38 != 0) {
        p->mUnk_74(p);
    }
    p->mUnk_38 = 0;
    p->mUnk_30 = 0;
    p->mUnk_34 = 0;
    p->mUnk_62 = 0;
    p->mUnk_64 = 0;
}

void func_0208d0dc(Unk0208c5b8 *p, Vec3s16 *a, Vec3 *b) {
    u16 i;
    Unk0201ca6c *e;
    s32 n;

    for (i = 0; i < 2; i++) {
        p->mUnk_10[i]->mUnk_50 = a[i];
        p->mUnk_18[i]->mUnk_50 = a[i];
        e = p->mUnk_10[i];
        n = b[i].x;
        e->mUnk_28.x = n + e->mUnk_20->mUnk_00->mUnk_04.x;
        n = b[i].y;
        e->mUnk_28.y = n + e->mUnk_20->mUnk_00->mUnk_04.y;
        n = b[i].z;
        e->mUnk_28.z = n + e->mUnk_20->mUnk_00->mUnk_04.z;
        e = p->mUnk_18[i];
        n = b[i].x;
        e->mUnk_28.x = n + e->mUnk_20->mUnk_00->mUnk_04.x;
        n = b[i].y;
        e->mUnk_28.y = n + e->mUnk_20->mUnk_00->mUnk_04.y;
        n = b[i].z;
        e->mUnk_28.z = n + e->mUnk_20->mUnk_00->mUnk_04.z;
    }
}

void func_0208d02c(Unk0208c5b8 *p, Vec3s16 *a, Vec3 *b) {
    u16 i;
    Unk0201ca6c *e;
    s32 t;

    for (i = 0; i < 2; i++) {
        e = p->mUnk_10[i];
        e->mUnk_50 = a[i];
        e = p->mUnk_10[i];
        t = b[i].x;
        e->mUnk_28.x = t + e->mUnk_20->mUnk_00->mUnk_04.x;
        t = b[i].y;
        e->mUnk_28.y = t + e->mUnk_20->mUnk_00->mUnk_04.y;
        t = b[i].z;
        e->mUnk_28.z = t + e->mUnk_20->mUnk_00->mUnk_04.z;
    }
}

void func_0208cf5c(Unk0208c5b8 *p) {
    u16 i;

    if (p->mUnk_3c != 0) {
        for (i = 0; i < 2; i++) {
            p->mUnk_00[i]->mUnk_24.mUnk_00_3 = 1;
        }
    }
    if (p->mUnk_40 != 0) {
        for (i = 0; i < 2; i++) {
            p->mUnk_20[i]->mUnk_24.mUnk_00_3 = 1;
            p->mUnk_28[i]->mUnk_24.mUnk_00_3 = 1;
        }
    }
    if (p->mUnk_44 == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        p->mUnk_08[i]->mUnk_24.mUnk_00_3 = 1;
    }
}

void func_0208cefc(Unk0208c5b8 *p) {
    u16 i;

    if (p->mUnk_38 != 0) {
        for (i = 0; i < 2; i++) {
            p->mUnk_10[i]->mUnk_24.mUnk_00_3 = 1;
            p->mUnk_18[i]->mUnk_24.mUnk_00_3 = 1;
        }
    }
    func_0208cf5c(p);
}

void func_0208ceac(Unk0208c5b8 *p) {
    u16 i;

    if (p->mUnk_38 != 0) {
        for (i = 0; i < 2; i++) {
            p->mUnk_10[i]->mUnk_24.mUnk_00_3 = 1;
        }
    }
    func_0208cf5c(p);
}

void func_0208cddc(Unk0208c5b8 *p) {
    u16 i;

    if (p->mUnk_3c != 0) {
        for (i = 0; i < 2; i++) {
            p->mUnk_00[i]->mUnk_24.mUnk_00_3 = 0;
        }
    }
    if (p->mUnk_40 != 0) {
        for (i = 0; i < 2; i++) {
            p->mUnk_20[i]->mUnk_24.mUnk_00_3 = 0;
            p->mUnk_28[i]->mUnk_24.mUnk_00_3 = 0;
        }
    }
    if (p->mUnk_44 == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        p->mUnk_08[i]->mUnk_24.mUnk_00_3 = 0;
    }
}

void func_0208cd7c(Unk0208c5b8 *p) {
    u16 i;

    if (p->mUnk_38 != 0) {
        for (i = 0; i < 2; i++) {
            p->mUnk_10[i]->mUnk_24.mUnk_00_3 = 0;
            p->mUnk_18[i]->mUnk_24.mUnk_00_3 = 0;
        }
    }
    func_0208cddc(p);
}

void func_0208cd2c(Unk0208c5b8 *p) {
    u16 i;

    if (p->mUnk_38 != 0) {
        for (i = 0; i < 2; i++) {
            p->mUnk_10[i]->mUnk_24.mUnk_00_3 = 0;
        }
    }
    func_0208cddc(p);
}

void func_0208ccf0(Unk0208c5b8 *p) {
    if (p->mUnk_38 != 0) {
        p->mUnk_74(p);
    }
    p->mUnk_38 = 0;
    p->mUnk_30 = 0;
    p->mUnk_34 = 0;
    p->mUnk_62 = 0;
    p->mUnk_64 = 0;
}

void func_0208cb8c(Unk0208c5b8 *p, Unk0206bcb0 *q) {
    Unk0217ae84 *e;

    if (p->mUnk_34 != 0) {
        p->mUnk_30++;
        if (p->mUnk_30 > 10) {
            if (p->mUnk_38 != 0) {
                p->mUnk_74(p);
            }
            p->mUnk_38 = 0;
            p->mUnk_30 = 0;
            p->mUnk_34 = 0;
            p->mUnk_62 = 0;
            p->mUnk_64 = 0;
        }
    }
    if ((q->mUnk_44 & 8) && p->mUnk_64 != 0) {
        p->mUnk_62++;
        if (p->mUnk_62 > 10) {
            if (p->mUnk_38 != 0) {
                p->mUnk_74(p);
            }
            p->mUnk_38 = 0;
            p->mUnk_30 = 0;
            p->mUnk_34 = 0;
            p->mUnk_62 = 0;
            p->mUnk_64 = 0;
            p->mUnk_68(p);
            p->mUnk_38 = 1;
            p->mUnk_62 = 0;
            p->mUnk_64 = 0;
        }
    }
    if (p->mUnk_38 == 0) {
        return;
    }
    e = func_020846a8(q->mIndex);
    p->mUnk_84(p, e->mUnk_4c, e->mUnk_34);
    if ((q->mUnk_44 & 0x10) == 0) {
        p->mUnk_6c(p);
        return;
    }
    if (p->mUnk_34 == 0) {
        p->mUnk_70(p);
    }
}

void func_0208cacc(Unk0208c5b8 *p, int v1) {
    u16 i;

    if (v1 == 0) {
        return;
    }
    if (p->mUnk_40 != 0) {
        for (i = 0; i < 2; i++) {
            func_0208b710(p->mUnk_20[i]);
            func_0208b710(p->mUnk_28[i]);
            p->mUnk_20[i] = NULL;
            p->mUnk_28[i] = NULL;
        }
    }
    p->mUnk_40 = 0;
    p->mUnk_48 = 0;
    for (i = 0; i < 2; i++) {
        p->mUnk_20[i] = func_0208b7bc(p->mUnk_58, &data_02155fcc);
        p->mUnk_28[i] = func_0208b7bc(p->mUnk_5c, &data_02155fcc);
    }
    p->mUnk_40 = 1;
}

void func_0208c930(Unk0208c5b8 *p, Vec3s16 *a, Vec3 *b) {
    u16 i;
    Unk0201ca6c *e;
    s32 n;

    if (p->mUnk_40 == 0) {
        return;
    }
    p->mUnk_48++;
    if (p->mUnk_48 > 10) {
        if (p->mUnk_40 != 0) {
            for (i = 0; i < 2; i++) {
                func_0208b710(p->mUnk_20[i]);
                func_0208b710(p->mUnk_28[i]);
                p->mUnk_20[i] = NULL;
                p->mUnk_28[i] = NULL;
            }
        }
        p->mUnk_40 = 0;
        p->mUnk_48 = 0;
        return;
    }
    for (i = 0; i < 2; i++) {
        p->mUnk_20[i]->mUnk_50 = a[i];
        p->mUnk_28[i]->mUnk_50 = a[i];
        e = p->mUnk_20[i];
        n = b[i].x;
        e->mUnk_28.x = n + e->mUnk_20->mUnk_00->mUnk_04.x;
        n = b[i].y;
        e->mUnk_28.y = n + e->mUnk_20->mUnk_00->mUnk_04.y;
        n = b[i].z;
        e->mUnk_28.z = n + e->mUnk_20->mUnk_00->mUnk_04.z;
        e = p->mUnk_28[i];
        n = b[i].x;
        e->mUnk_28.x = n + e->mUnk_20->mUnk_00->mUnk_04.x;
        n = b[i].y;
        e->mUnk_28.y = n + e->mUnk_20->mUnk_00->mUnk_04.y;
        n = b[i].z;
        e->mUnk_28.z = n + e->mUnk_20->mUnk_00->mUnk_04.z;
    }
}

void func_0208c884(Unk0208c5b8 *p, int v1) {
    u16 i;

    if (v1 == 0) {
        return;
    }
    if (p->mUnk_44 != 0) {
        for (i = 0; i < 2; i++) {
            func_0208b710(p->mUnk_08[i]);
            p->mUnk_08[i] = NULL;
        }
    }
    p->mUnk_44 = 0;
    p->mUnk_4a = 0;
    for (i = 0; i < 2; i++) {
        p->mUnk_08[i] = func_0208b7bc(0x7e, &data_02155fcc);
    }
    p->mUnk_44 = 1;
}

void func_0208c6dc(Unk0208c5b8 *p, Vec3s16 *a, Vec3 *b) {
    u16 i;
    Unk0201ca6c *e;
    s32 t;

    if (p->mUnk_44 == 0) {
        return;
    }
    p->mUnk_4a++;
    if (p->mUnk_4a > 8) {
        if (p->mUnk_44 != 0) {
            for (i = 0; i < 2; i++) {
                func_0208b710(p->mUnk_08[i]);
                p->mUnk_08[i] = NULL;
            }
        }
        p->mUnk_44 = 0;
        p->mUnk_4a = 0;
        if (p->mUnk_3c == 0) {
            return;
        }
        for (i = 0; i < 2; i++) {
            p->mUnk_00[i]->mUnk_24.mUnk_00_1 = 0;
        }
        return;
    }
    for (i = 0; i < 2; i++) {
        e = p->mUnk_08[i];
        e->mUnk_50 = a[i];
        e = p->mUnk_08[i];
        t = b[i].x;
        e->mUnk_28.x = t + e->mUnk_20->mUnk_00->mUnk_04.x;
        t = b[i].y;
        e->mUnk_28.y = t + e->mUnk_20->mUnk_00->mUnk_04.y;
        t = b[i].z;
        e->mUnk_28.z = t + e->mUnk_20->mUnk_00->mUnk_04.z;
    }
    if (p->mUnk_3c == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        p->mUnk_00[i]->mUnk_24.mUnk_00_1 = 1;
    }
}

void func_0208c5d0(Unk0208c5b8 *p) {
    u16 i;
    u16 j;

    if (p->mUnk_3c != 0) {
        for (i = 0; i < 2; i++) {
            func_0208b6d0(&p->mUnk_00[i]);
        }
    }
    p->mUnk_3c = 0;
    if (p->mUnk_38 != 0) {
        p->mUnk_74(p);
    }
    p->mUnk_38 = 0;
    p->mUnk_30 = 0;
    p->mUnk_34 = 0;
    p->mUnk_62 = 0;
    p->mUnk_64 = 0;
    if (p->mUnk_40 != 0) {
        for (i = 0; i < 2; i++) {
            func_0208b710(p->mUnk_20[i]);
            func_0208b710(p->mUnk_28[i]);
            p->mUnk_20[i] = NULL;
            p->mUnk_28[i] = NULL;
        }
    }
    p->mUnk_40 = 0;
    p->mUnk_48 = 0;
    if (p->mUnk_44 != 0) {
        for (j = 0; j < 2; j++) {
            func_0208b710(p->mUnk_08[j]);
            p->mUnk_08[j] = NULL;
        }
    }
    p->mUnk_44 = 0;
    p->mUnk_4a = 0;
}

Unk0208c5b8 *func_0208c5b8(int v1) {
    return data_0217b078 + v1;
}

void func_0208c534(Unk0208c5b8 *p) {
    u16 i;

    if (p->mUnk_38 == 0) {
        p->mUnk_34 = 0;
    } else {
        p->mUnk_78(p);
        p->mUnk_34 = 1;
    }
    p->mUnk_62 = 0;
    p->mUnk_64 = 0;
    if (p->mUnk_3c == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        p->mUnk_00[i]->mUnk_24.mUnk_00_0 = 1;
        p->mUnk_00[i] = NULL;
    }
    p->mUnk_3c = 0;
}
