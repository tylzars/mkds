#include "Main/Unknown/code_020a1748.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0212df7c.h"

void func_020a1ddc(s32 a) {
    s32 i;
    s32 n;

    n = data_021759c0->mUnk_3d0;
    for (i = 0; i < n; i++) {
        data_0217b1fc->mUnk_000[i].mUnk_24[a] = 0;
    }
}

static inline u16 func_020a1790_inline(Unk0217b1fc *d, s32 i) {
    s32 j;

    for (j = 0; j < 8; j++) {
        if ((u16) i == d->mUnk_000[j].mUnk_48) {
            return (u16) j;
        }
    }
    return 0;
}

u16 func_020a1cd8(s32 a) {
    s32 v;
    s32 i;
    s32 v1;

    if (data_021759c0->mUnk_08 == 2) {
        if (data_021759c0->mUnk_18 == 0) {
            v = 3 - data_0217b1fc->mUnk_000[a].mUnk_4c;
            v += 1;
        } else if (data_021759c0->mUnk_18 == 1) {
            v1 = 1;
            for (i = 0; i < data_021759c0->mUnk_3d0; i++) {
                if (data_0217b1fc->mUnk_000[i].mUnk_4c > v1) {
                    v1 = data_0217b1fc->mUnk_000[i].mUnk_4c;
                }
            }
            v = (v1 + 1 - data_0217b1fc->mUnk_000[a].mUnk_4c) / 2 + 1;
        } else {
            v = a;
        }
    } else {
        v = 3 - data_0217b1fc->mUnk_000[a].mUnk_4c;
        v += 1;
    }
    if (v < 1) {
        v = 1;
    } else if (v > 3) {
        v = 3;
    }
    return v;
}

void func_020a1b6c(u16 a) {
    s32 i;
    s32 j;
    s32 n;
    s32 v;
    Unk0217b1fc_000 *e0;
    u16 r1;
    u16 r0;
    Unk0217b1fc_000 *e1;

    for (i = data_0217b1fc->mUnk_000[a].mUnk_48 - 1; i >= 0; i--) {
        e1 = &data_0217b1fc->mUnk_000[func_020a1790_inline(data_0217b1fc, i)];
        r1 = e1->mUnk_48;
        r0 = data_0217b1fc->mUnk_000[a].mUnk_48;
        e0 = &data_0217b1fc->mUnk_000[a];
        if (r0 > r1) {
            if (e0->mUnk_4c > e1->mUnk_4c || (e0->mUnk_08 == 0 && e1->mUnk_08 != 0)) {
                e1->mUnk_48 = r0;
                data_0217b1fc->mUnk_000[a].mUnk_48 = r1;
            }
        }
    }
    n = data_021759c0->mUnk_3d0;
    data_0217b1fc->mUnk_3b0 = 0xffff;
    data_0217b1fc->mUnk_3ac = 0;
    for (j = 0; j < n; j++) {
        v = data_0217b1fc->mUnk_000[j].mUnk_4c;
        data_0217b1fc->mUnk_3b0 = (v < data_0217b1fc->mUnk_3b0 && v >= 0) ? v : data_0217b1fc->mUnk_3b0;
        v = data_0217b1fc->mUnk_000[j].mUnk_4c;
        data_0217b1fc->mUnk_3ac = (v > data_0217b1fc->mUnk_3ac) ? v : data_0217b1fc->mUnk_3ac;
    }
}

void func_020a19f8(u16 a) {
    s32 i;
    s32 j;
    s32 n;
    s32 v;
    Unk0217b1fc_000 *e0;
    u16 r1;
    u16 r0;
    Unk0217b1fc_000 *e1;

    for (i = data_0217b1fc->mUnk_000[a].mUnk_48 + 1; i < 8; i++) {
        e1 = &data_0217b1fc->mUnk_000[func_020a1790_inline(data_0217b1fc, i)];
        r1 = e1->mUnk_48;
        r0 = data_0217b1fc->mUnk_000[a].mUnk_48;
        e0 = &data_0217b1fc->mUnk_000[a];
        if (r0 < r1) {
            if (e0->mUnk_4c < e1->mUnk_4c || (e0->mUnk_08 != 0 && e1->mUnk_08 == 0)) {
                e1->mUnk_48 = r0;
                data_0217b1fc->mUnk_000[a].mUnk_48 = r1;
            }
        }
    }
    n = data_021759c0->mUnk_3d0;
    data_0217b1fc->mUnk_3b0 = 0xffff;
    data_0217b1fc->mUnk_3ac = 0;
    for (j = 0; j < n; j++) {
        v = data_0217b1fc->mUnk_000[j].mUnk_4c;
        data_0217b1fc->mUnk_3b0 = (v < data_0217b1fc->mUnk_3b0 && v >= 0) ? v : data_0217b1fc->mUnk_3b0;
        v = data_0217b1fc->mUnk_000[j].mUnk_4c;
        data_0217b1fc->mUnk_3ac = (v > data_0217b1fc->mUnk_3ac) ? v : data_0217b1fc->mUnk_3ac;
    }
}

void func_020a1904(u16 a) {
    Unk0206bcb0 *c;

    if (data_0217b1fc->mUnk_38c != NULL) {
        data_0217b1fc->mUnk_38c(a);
    }
    data_0217b1fc->mUnk_000[a].mUnk_08 = 1;
    if (data_021759c0->mUnk_08 == 2) {
        data_0217b1fc->mUnk_000[a].mUnk_4c = -1;
        data_0217b1fc->mUnk_000[a].mUnk_50 = 0;
    }
    if ((u32) a >= data_021759c0->mUnk_3d0) {
        return;
    }
    func_020a19f8(a);
    if (data_021759c0->mUnk_08 == 2) {
        func_02068b5c(func_0207a974(a));
    } else if (data_021759c0->mUnk_08 == 4) {
        c = func_0207a974(a);
        c->mUnk_48 |= 0x2000;
        c->mUnk_7c |= 8;
    }
}

void func_020a1790(void) {
    s32 n;
    s32 v;
    s32 i;
    s32 j;
    s32 v1;
    s32 k;
    u16 x;
    Unk0217b1fc *d;
    Unk0217b1fc_000 *e;
    Unk0206bcb0 *c;

    n = data_021759c0->mUnk_3d0;
    d = data_0217b1fc;
    for (k = 0; k < 8; k++) {
        if (d->mUnk_000[k].mUnk_48 == 0) {
            x = k;
            goto found;
        }
    }
    x = 0;
found:
    v = d->mUnk_000[x].mUnk_46;
    e = d->mUnk_000;
    for (j = 0; j < 8; j++, e++) {
        if (e->mUnk_08 == 0) {
            if (v != e->mUnk_46) {
                return;
            }
        }
    }
    for (i = 0; i < n; i++) {
        c = func_0207a974((u16) i);
        c->mUnk_48 |= 0x2000;
        c->mUnk_7c |= 8;
    }
    data_0217b1fc->mUnk_3b4 = v;
    if (data_021759c0->mUnk_08 == 2) {
        if (data_021759c0->mUnk_18 == 1) {
            func_0212ecc0(&data_0217d068, 0, 0x4a);
        }
        data_0217b1fc->mUnk_3a8 = 0x5a;
    } else if (data_021759c0->mUnk_08 == 4) {
        v1 = data_021759c0->mUnk_62;
        if (data_0217b1fc->mUnk_3b4 == v1) {
            func_0203e74c((u16) v1);
        } else {
            func_0203cd04((u16) v1);
        }
        data_0217b1fc->mUnk_3a8 = 0;
    }
}

void func_020a1748(u16 a) {
    Unk0217b1fc_000 *e;

    e = &data_0217b1fc->mUnk_000[a];
    e->mUnk_1c = -2;
    e->mUnk_18 = -2;
    e->mUnk_44 = a;
    data_0217b1fc->mUnk_388(a, a);
}
