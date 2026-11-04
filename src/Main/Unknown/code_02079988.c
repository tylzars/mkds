#include "Main/Unknown/code_02079988.h"

#include "Main/Unknown/code_020799a0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02079a04.h"
#include "Main/Unknown/code_02079a14.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_02087cd0.h"
#include "Main/Unknown/code_02079a3c.h"
#include "Main/Unknown/code_02079b40.h"
#include "Main/Unknown/code_02079b60.h"
#include "Main/Unknown/code_02079b9c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02079bcc.h"
#include "Main/Unknown/code_02079c0c.h"
#include "Main/Unknown/code_0207a104.h"
#include "Main/Unknown/code_0207a14c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "01/code_0218155c.h"
#include "Main/Unknown/code_0207a30c.h"
#include "Main/Unknown/code_0207a32c.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_0207a68c.h"
#include "Main/Unknown/code_0207a6b0.h"
#include "Main/Unknown/code_0207a73c.h"
#include "Main/Unknown/code_0207a74c.h"
#include "Main/Unknown/code_0207a780.h"
#include "Main/Unknown/code_0207a790.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_0207a7ec.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_0207a7fc.h"
#include "Main/Unknown/code_02066ac0.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_0207a870.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0207a8c4.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020638c0.h"
#include "Main/Unknown/code_02063b70.h"
#include "Main/Unknown/code_020649ec.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/code_020733ec.h"

void func_0207ad88(Unk0207adf8 *a, u32 b, u32 c) {
    if ((a->mUnk_70 & 1) != 0) {
        func_02084ad8(a, a->mUnk_6e);
        data_02155a20[a->mUnk_00.mUnk_58](a);
        func_02084a88(a, a->mUnk_6e, a->mUnk_6c);
        data_02155a20[a->mUnk_00.mUnk_58](a);
    }
}

void func_0207abec(u32 a) {
    u16 i;
    void *h = GetHeap(func_020364e8());
    Unk0206cdd4_B *q;
    data_0217ad18 = HeapAlloc(h, a * 0x5a8);
    data_usa_0217acf4 = a;
    q = HeapAlloc(h, 0x1c);
    data_usa_0217acfc = q;
    data_0217ad10 = 0;
    data_0217ad20 = 0;
    data_usa_021658c0 = -1;
    q->mUnk_00 = 0;
    q->mUnk_04 = 0;
    q->mUnk_08 = 0;
    q->mUnk_0c = 0;
    q->mUnk_10 = 0;
    q->mUnk_14 = 0;
    q->mUnk_18 = 0;
    data_usa_021658bc = data_021759c0->mUnk_08 == 2 ? 1 : 2;
    func_02073630();
    func_0208c284();
    func_020845cc(a);
    data_0217ad24 = 0;
    if (data_021759c0->mUnk_08 == 4) {
        if (gCourseMap->mUnk_10f != 0) {
            data_0217ad24 = 1;
        }
    }
    for (i = 0; i < a; i++) {
        data_0217ad18[i].mIndex = i;
        data_0217ad18[i].mUnk_78 = data_021759c0->mUnk_68[i].mUnk_08.mUnk_0c;
        func_020649ec(&data_0217ad18[i], data_usa_021655e4);
    }
    data_0217ad28 = 0;
}

void func_0207aaec(void) {
    s32 i;
    Unk0206bcb0 *p = data_0217ad18;
    data_0217ad20 = 0;
    data_usa_021658c0 = -1;
    for (i = 0; i < data_usa_0217acf4; i++) {
        func_01ffcac0(p);
        p++;
    }
    func_0207a32c();
    p = data_0217ad18;
    for (i = 0; i < data_usa_0217acf4; i++) {
        p->mUnk_20c_fn[3](p);
        p++;
    }
    p = data_0217ad18;
    for (i = 0; i < data_usa_0217acf4; i++) {
        p->mUnk_20c_fn[4](p);
        p++;
    }
}

void func_0207aa7c(void) {
    Unk0206bcb0 *p = data_0217ad18;
    s16 i;
    for (i = 0; i < data_usa_0217acf4; i++) {
        p->mUnk_20c_fn[2](p);
        p++;
    }
}

void func_0207a9f4(void) {
    s32 i = 0;
    u16 *p = func_02086058();
    (data_0217ad18[data_021759c0->mUnk_62].mKartModelsEntry)->mUnk_060 = 1;
    for (; i < data_usa_0217acf4; i++) {
        func_02063cc4(&data_0217ad18[*p]);
        p++;
    }
}

void func_0207a990(void) {
    s32 i;
    for (i = 0; i < data_usa_0217acf4; i++) {
        func_020638c0(&data_0217ad18[i]);
    }
    data_0217ad18 = NULL;
}

Unk0206bcb0 *func_0207a974(s32 a) {
    return &data_0217ad18[a];
}

void func_0207a948(Vec3 *a, s32 b) {
    *a = *data_0217ad18[b].mUnk_508;
}

void func_0207a91c(Vec3 *a, u8 b) {
    *a = *data_0217ad18[b].mUnk_534;
}

void func_0207a8f0(Vec3 *a, s32 b) {
    *a = data_0217ad18[b].mUnk_8c;
}

void func_0207a8c4(Vec3 *a, s32 b) {
    *a = data_0217ad18[b].mUnk_bc;
}

u32 func_0207a8a4(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217ad18;
    value1 = 0x5a8u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value1) + (668));
    return value0;
}

u16 func_0207a880(s32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217ad18;
    value1 = 0x5a8u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (value1) + (0x200u);
    value0 = (u32) * (const u16 *) ((value0) + (54));
    return (u16) value0;
}

u32 func_0207a870(void) {
    return (u32) data_0217ad24;
}

s32 func_0207a84c(s32 a) {
    return func_02068eac(&data_0217ad18[a]);
}

void func_0207a828(s32 a) {
    func_02066fe0(&data_0217ad18[a]);
}

u32 func_0207a7fc(s32 a) {
    return (data_0217ad18[a].mUnk_48 & 1) != 0;
}

u32 func_0207a7ec(void) {
    return (u32) data_0217ad30;
}

void func_0207a790(s32 a) {
    u16 i;

    data_0217ad28 = 0;
    for (i = 0; i < 8; i++) {
        if (func_02040de0(a, i) != 0) {
            data_0217ad28 |= 1 << i;
        }
    }
}

u32 func_0207a780(void) {
    return data_0217ad28;
}

void func_0207a74c(s32 a) {
    data_0217ad30 = (s32) (((s64) a * data_0217ad2c + 0x800) >> 12);
}

void func_0207a73c(u32 p0) {
    data_0217ad2c = p0;
}

void func_0207a70c(s32 a) {
    if (a == data_021759c0->mUnk_62) {
        data_usa_0217acfc->mUnk_08++;
    }
}

void func_0207a6c0(Unk0206bcb0 *a) {
    if (a->mIndex != data_021759c0->mUnk_62) {
        return;
    }
    if (a->mUnk_4c & 0x40) {
        return;
    }
    if (!(a->mUnk_48 & 0x20000000)) {
        data_usa_0217acfc->mUnk_0c++;
    }
}

Unk0206cdd4_B *func_0207a6b0(void) {
    return data_usa_0217acfc;
}

u32 func_0207a68c(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_0217ad18;
    value1 = 0x5a8u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value12 = (u32) &func_0206c0a8;
    value0 = (value1) * (value0) + (value2);
    value0 = (u32) func_0206c0a8((Unk0206bcb0 *) value0);
    return value0;
}

void func_0207a5f0(s32 a) {
    s32 i;
    Unk0206bcb0 *p = data_0217ad18;
    Unk0206bcb0_590 *s;
    for (i = 0; i < data_usa_0217acf4; i++) {
        s = p->mKartModelsEntry;
        func_02013044(s->mUnk_010[1]->mUnk_04, a);
        func_02013044(s->mUnk_010[0]->mUnk_04, a);
        if (s->mUnk_010[2] != NULL) {
            func_02013044(s->mUnk_010[2]->mUnk_04, a);
        }
        p++;
    }
}

s32 func_0207a5c4(s32 a) {
    return (data_0217ad18[a].mUnk_48 & 0x800) != 0 ? 1 : 0;
}

BOOL func_0207a574(void) {
    Unk0206bcb0 *p = &data_0217ad18[data_021759c0->mUnk_62];
    if (p->mState != 0 || (p->mUnk_48 & 0x4000000) != 0) {
        return TRUE;
    }
    return FALSE;
}

s32 func_0207a538(void) {
    return (data_0217ad18[data_021759c0->mUnk_62].mUnk_44 & 0xc0) != 0 ? 1 : 0;
}

s32 func_0207a4fc(void) {
    return (data_0217ad18[data_021759c0->mUnk_62].mUnk_48 & 0x1000) != 0 ? 1 : 0;
}

void func_0207a32c(void) {
    s32 d[3];
    u32 n = func_0203c8dc((u16) data_021759c0->mUnk_62);
    u16 i;
    u16 k;
    s32 j;
    Unk0206bcb0 *p;
    if (data_021759c0->mUnk_00c == 5) {
        for (k = 0; k < 3; k++) {
            data_0217ad18[k].mUnk_4c |= 0x8000;
        }
        return;
    }
    d[0] = data_021759c0->mUnk_62;
    if (n == 1) {
        d[1] = func_02085408(2);
        if (d[1] >= 0) {
            if ((data_0217ad18[d[1]].mKartModelsEntry)->mUnk_060 != 0) {
                d[1] = -1;
            }
        }
    } else {
        d[1] = func_02085408((u16) (n - 1));
        if (d[1] >= 0) {
            if ((data_0217ad18[d[1]].mKartModelsEntry)->mUnk_060 != 0) {
                d[1] = -1;
            }
        }
        if (n < data_021759c0->mKartCount) {
            j = func_02085408((u16) (n + 1));
            if (j >= 0) {
                p = &data_0217ad18[j];
                p->mUnk_4c |= 0x40000;
            }
        }
    }
    for (i = 0; i < data_usa_021658bc; i++) {
        j = d[i];
        if (j >= 0) {
            p = &data_0217ad18[j];
            if ((p->mUnk_4c & 0x10000000) == 0) {
                p->mUnk_4c |= 0x8000;
            }
        }
    }
}

u32 func_0207a31c(void) {
    return ((u32) data_0217ad10);
}

void func_0207a30c(u32 p0) {
    data_0217ad10 = (u16) p0;
}

void func_0207a2d4(s32 a) {
    if (data_usa_021658c0 < 0 || a < data_usa_021658c0) {
        data_usa_021658c0 = a;
        data_0217ad20 = 1;
    }
}

BOOL func_0207a2a8(s32 *a) {
    if (data_0217ad20 == 0) {
        return FALSE;
    }
    *a = data_usa_021658c0;
    return TRUE;
}

s32 func_0207a218(void) {
    BOOL r = TRUE;
    s32 m = data_021759c0->mUnk_08;
    if (m == 4) {
        Unk0206bcb0 *p = &data_0217ad18[data_021759c0->mUnk_62];
        if (p->mState != 0 || (p->mUnk_48 & 0x2000840) != 0 || (p->mUnk_44 & 0x10) == 0 ||
            (m != 4 ? 0 : func_ov001_021816b4()) != 0) {
            r = FALSE;
        }
    }
    return r;
}

void func_0207a14c(Unk0201290c *a, u32 b) {
    u32 c;
    u32 d;
    u32 e;
    u32 f;
    switch (b) {
        case 0: {
            u16 *p = (u16 *) gKartModels->mUnk_004;
            c = p[0];
            d = p[1];
            e = p[2];
            f = p[3];
            break;
        }
        case 2:
            d = 0;
            e = 0;
            f = 0;
            c = 0x2108;
            break;
        case 3:
            d = 0;
            e = 0;
            c = 0x2108;
            f = 0x4210;
            break;
        case 1:
            c = 0x7fff;
            d = 0x14a5;
            f = 0x2108;
            e = 0;
            break;
    }
    func_020132cc(a, c);
    func_02013284(a, d);
    func_0201323c(a, e);
    func_020131f4(a, f);
}

u16 func_0207a134(void) {
    u32 value0;
    value0 = (u32) &gKartModels;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (u32) * (const u32 *) ((value0) + (4));
    value0 = (u32) * (const u16 *) ((value0) + (0));
    return (u16) value0;
}

u16 func_0207a11c(void) {
    u32 value0;
    value0 = (u32) &gKartModels;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (u32) * (const u32 *) ((value0) + (4));
    value0 = (u32) * (const u16 *) ((value0) + (6));
    return (u16) value0;
}

u16 func_0207a104(void) {
    u32 value0;
    value0 = (u32) &gKartModels;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (u32) * (const u32 *) ((value0) + (4));
    value0 = (u32) * (const u16 *) ((value0) + (2));
    return (u16) value0;
}

void func_02079f70(struct Unk0206bcb0_590 *a, u16 b, u16 c, u16 d) {
    Unk0206bcb0_590_6a *q;

    q = &a->mUnk_06a;
    q->mUnk_06 = a->mUnk_06a.mUnk_00 & 0x1f;
    q->mUnk_0c = (s16) (b & 0x1f) - q->mUnk_06;
    q->mUnk_08 = (a->mUnk_06a.mUnk_00 >> 5) & 0x1f;
    q->mUnk_0e = (s16) ((b >> 5) & 0x1f) - q->mUnk_08;
    q->mUnk_0a = (a->mUnk_06a.mUnk_00 >> 10) & 0x1f;
    q->mUnk_10 = (s16) ((b >> 10) & 0x1f) - q->mUnk_0a;
    q->mUnk_12 = q->mUnk_02 & 0x1f;
    q->mUnk_18 = (s16) (c & 0x1f) - q->mUnk_12;
    q->mUnk_14 = (q->mUnk_02 >> 5) & 0x1f;
    q->mUnk_1a = (s16) ((c >> 5) & 0x1f) - q->mUnk_14;
    q->mUnk_16 = (q->mUnk_02 >> 10) & 0x1f;
    q->mUnk_1c = (s16) ((c >> 10) & 0x1f) - q->mUnk_16;
    q->mUnk_1e = q->mUnk_04 & 0x1f;
    q->mUnk_24 = (s16) (d & 0x1f) - q->mUnk_1e;
    q->mUnk_20 = (q->mUnk_04 >> 5) & 0x1f;
    q->mUnk_26 = (s16) ((d >> 5) & 0x1f) - q->mUnk_20;
    q->mUnk_22 = (q->mUnk_04 >> 10) & 0x1f;
    q->mUnk_28 = (s16) ((d >> 10) & 0x1f) - q->mUnk_22;
    q->mUnk_2a = 0;
}

s32 func_02079ce0(struct Unk0206bcb0_590 *a, s32 b) {
    Unk0206bcb0_590_6a *q = &a->mUnk_06a;
    BOOL r = FALSE;

    if (q->mUnk_2a < 0x1000) {
        q->mUnk_2a += b;
        if (q->mUnk_2a >= 0x1000) {
            q->mUnk_2a = 0x1000;
            r = TRUE;
        }
        q->mUnk_00 = (s16) (q->mUnk_06 + (s32) (((s64) q->mUnk_0c * q->mUnk_2a + 0x800) >> 12)) +
                     ((s16) (q->mUnk_08 + (s32) (((s64) q->mUnk_0e * q->mUnk_2a + 0x800) >> 12)) << 5) +
                     ((s16) (q->mUnk_0a + (s32) (((s64) q->mUnk_10 * q->mUnk_2a + 0x800) >> 12)) << 10);
        func_020132cc(a->mUnk_010[0]->mUnk_04, q->mUnk_00);
        func_020132cc(a->mUnk_010[1]->mUnk_04, q->mUnk_00);
        if (a->mUnk_010[2] != NULL) {
            func_020132cc(a->mUnk_010[2]->mUnk_04, q->mUnk_00);
        }
        q->mUnk_02 = (s16) (q->mUnk_12 + (s32) (((s64) q->mUnk_18 * q->mUnk_2a + 0x800) >> 12)) +
                     ((s16) (q->mUnk_14 + (s32) (((s64) q->mUnk_1a * q->mUnk_2a + 0x800) >> 12)) << 5) +
                     ((s16) (q->mUnk_16 + (s32) (((s64) q->mUnk_1c * q->mUnk_2a + 0x800) >> 12)) << 10);
        func_020131f4(a->mUnk_010[0]->mUnk_04, q->mUnk_02);
        func_020131f4(a->mUnk_010[1]->mUnk_04, q->mUnk_02);
        if (a->mUnk_010[2] != NULL) {
            func_020131f4(a->mUnk_010[2]->mUnk_04, q->mUnk_02);
        }
        {
            s16 x = q->mUnk_1e + (s32) (((s64) q->mUnk_24 * q->mUnk_2a + 0x800) >> 12);
            s16 y = q->mUnk_20 + (s32) (((s64) q->mUnk_26 * q->mUnk_2a + 0x800) >> 12);
            s16 z = q->mUnk_22 + (s32) (((s64) q->mUnk_28 * q->mUnk_2a + 0x800) >> 12);
            func_02013284(a->mUnk_010[0]->mUnk_04, q->mUnk_04);
            func_02013284(a->mUnk_010[1]->mUnk_04, q->mUnk_04);
            if (a->mUnk_010[2] != NULL) {
                func_02013284(a->mUnk_010[2]->mUnk_04, q->mUnk_04);
            }
            q->mUnk_04 = x + (y << 5) + (z << 10);
        }
    } else {
        r = TRUE;
    }
    return r;
}

void func_02079c0c(struct Unk0206bcb0_590 *a) {
    u16 *p = (u16 *) gKartModels->mUnk_004;
    u32 b;
    u32 c;
    u32 d;

    b = p[0];
    c = p[3];
    d = p[1];
    func_020132cc(a->mUnk_010[0]->mUnk_04, b);
    func_020132cc(a->mUnk_010[1]->mUnk_04, b);
    func_020131f4(a->mUnk_010[0]->mUnk_04, c);
    func_020131f4(a->mUnk_010[1]->mUnk_04, c);
    func_02013284(a->mUnk_010[0]->mUnk_04, d);
    func_02013284(a->mUnk_010[1]->mUnk_04, d);
    if (a->mUnk_010[2] != NULL) {
        func_020132cc(a->mUnk_010[2]->mUnk_04, b);
        func_020131f4(a->mUnk_010[2]->mUnk_04, c);
        func_02013284(a->mUnk_010[2]->mUnk_04, d);
    }
}

Unk0206bcb0_590 *func_02079bf0(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gKartModels;
    value1 = 0xb4u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value0 = (value1) * (value0) + (value2);
    return (Unk0206bcb0_590 *) value0;
}

void *func_02079bcc(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gKartModels;
    value1 = 0xb4u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value1) + (20));
    value0 = (u32) * (const u32 *) ((value0) + (4));
    return (void *) value0;
}

void func_02079b9c(struct Unk0206bcb0_590 *a, s32 b) {
    func_02013468(a->mUnk_010[1]->mUnk_04, gKartModels->mUnk_00c, b != 0 ? 0x1f : 0);
}

void *func_02079b88(void) {
    return &gKartModels->mUnk_02c;
}

void *func_02079b74(void) {
    return &gKartModels->mUnk_098;
}

void *func_02079b60(void) {
    return &gKartModels->mUnk_10c;
}

u32 func_02079b40(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gKartModels;
    value1 = 0xb4u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u16 *) ((value1) + (104));
    return value0;
}

#pragma thumb on
void func_02079a3c(u32 *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value4;
    value4 = (value0) + (0u);
    value0 = 0u;
    value1 = ~(value0);
    *(u32 *) ((value4) + 0u) = value1;
    *(u32 *) ((value4) + 4u) = value1;
    *(u32 *) ((value4) + 8u) = value0;
    *(u32 *) ((value4) + 12u) = value0;
    *(u32 *) ((value4) + 16u) = value0;
    *(u32 *) ((value4) + 20u) = value0;
    *(u32 *) ((value4) + 24u) = value0;
    *(u32 *) ((value4) + 28u) = value0;
    *(u32 *) ((value4) + 32u) = value0;
    value0 = (value4) + (0u);
    value0 = (value0) + 36u;
    func_02079a04(value0);
    value0 = 0u;
    *(u32 *) ((value4) + 84u) = value0;
    *(u32 *) ((value4) + 88u) = value0;
    *(u32 *) ((value4) + 92u) = value0;
    *(u32 *) ((value4) + 96u) = value0;
    *(u32 *) ((value4) + 100u) = value0;
    value1 = (value4) + (0u);
    value1 = (value1) + 104u;
    *(u16 *) ((value1) + 0u) = (u16) value0;
    value1 = (value4) + (0u);
    value1 = (value1) + 172u;
    *(u32 *) ((value1) + 0u) = value0;
    value1 = (value4) + (0u);
    value1 = (value1) + 176u;
    *(u32 *) ((value1) + 0u) = value0;
    value1 = (value4) + (0u);
    value1 = (value1) + 110u;
    *(u16 *) ((value1) + 0u) = (u16) value0;
    value1 = (value4) + (0u);
    value1 = (value1) + 110u;
    value2 = (u32) * (const u16 *) ((value1) + 0u);
    value1 = (value4) + (0u);
    value1 = (value1) + 108u;
    *(u16 *) ((value1) + 0u) = (u16) value2;
    value1 = (value4) + (0u);
    value1 = (value1) + 108u;
    value2 = (u32) * (const u16 *) ((value1) + 0u);
    value1 = (value4) + (0u);
    value1 = (value1) + 106u;
    *(u16 *) ((value1) + 0u) = (u16) value2;
    value1 = (value4) + (0u);
    value1 = (value1) + 116u;
    *(u16 *) ((value1) + 0u) = (u16) value0;
    value1 = 116u;
    value2 = (u32) * (const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 114u;
    *(u16 *) ((value1) + 0u) = (u16) value2;
    value1 = 114u;
    value2 = (u32) * (const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 112u;
    *(u16 *) ((value1) + 0u) = (u16) value2;
    value1 = (value4) + (0u);
    value1 = (value1) + 122u;
    *(u16 *) ((value1) + 0u) = (u16) value0;
    value1 = 122u;
    value2 = (u32) * (const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 120u;
    *(u16 *) ((value1) + 0u) = (u16) value2;
    value1 = 120u;
    value2 = (u32) * (const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 118u;
    *(u16 *) ((value1) + 0u) = (u16) value2;
    value1 = (value4) + (0u);
    value1 = (value1) + 128u;
    *(u16 *) ((value1) + 0u) = (u16) value0;
    value1 = 128u;
    value2 = (u32) * (const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 126u;
    *(u16 *) ((value1) + 0u) = (u16) value2;
    value1 = 126u;
    value2 = (u32) * (const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 124u;
    *(u16 *) ((value1) + 0u) = (u16) value2;
    value1 = (value4) + (0u);
    value1 = (value1) + 134u;
    *(u16 *) ((value1) + 0u) = (u16) value0;
    value1 = 134u;
    value2 = (u32) * (const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 132u;
    *(u16 *) ((value1) + 0u) = (u16) value2;
    value1 = 132u;
    value2 = (u32) * (const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 130u;
    *(u16 *) ((value1) + 0u) = (u16) value2;
    value1 = (value4) + (0u);
    value1 = (value1) + 140u;
    *(u16 *) ((value1) + 0u) = (u16) value0;
    value1 = 140u;
    value2 = (u32) * (const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 138u;
    *(u16 *) ((value1) + 0u) = (u16) value2;
    value1 = 138u;
    value2 = (u32) * (const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 136u;
    *(u16 *) ((value1) + 0u) = (u16) value2;
    value1 = (value4) + (0u);
    value1 = (value1) + 146u;
    *(u16 *) ((value1) + 0u) = (u16) value0;
    value1 = 146u;
    value2 = (u32) * (const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 144u;
    *(u16 *) ((value1) + 0u) = (u16) value2;
    value1 = 144u;
    value2 = (u32) * (const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 142u;
    *(u16 *) ((value1) + 0u) = (u16) value2;
    value4 = (value4) + 148u;
    *(u16 *) ((value4) + 0u) = (u16) value0;
}
#pragma thumb off

#pragma thumb on

void func_02079a14(Unk0206bcb0_590 *a) {
    func_02087cd0(a->mUnk_098, func_02087d0c(&gKartModels->mUnk_10c));
}

#pragma thumb off

#pragma thumb on
void func_02079a04(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = 0u;
    *(u32 *) ((value0) + 0u) = value1;
    *(u32 *) ((value0) + 20u) = value1;
    *(u16 *) ((value0) + 24u) = (u16) value1;
    *(u32 *) ((value0) + 4u) = value1;
    *(u16 *) ((value0) + 16u) = (u16) value1;
}
#pragma thumb off

#pragma thumb on

u32 func_020799a0(s32 e) {
    BOOL a = TRUE;
    s32 b = a;
    s32 c = a;
    s32 d = a;
    if (e != data_021759c0->mUnk_62 && e != data_021759c0->mUnk_063) {
        d = 0;
    }
    if (d == 0 && data_021759c0->mUnk_08 != 4) {
        c = 0;
    }
    if (c == 0 && func_02062eb0() == 0) {
        b = 0;
    }
    if (b == 0 && data_021759c0->mUnk_08 != 1) {
        a = FALSE;
    }
    if (a != FALSE) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void func_02079988(int a, u32 b) {
    u16 v1;
    v1 = (int) b % 3;
    *(u16 *) (a + 0x68) = v1;
}

#pragma thumb off
