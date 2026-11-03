#include "Main/Unknown/code_020a0ff0.h"

#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a10d4.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020a1748.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020a1218.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020a128c.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_02156000.h"
#include "code_0212c6ac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020a1728.h"

void func_020a1728(int a) {
    *(u32 *) (a * 0x70 + (u32) data_0217b1fc + 8) = 0;
}

static inline u16 func_020a12b8_inline(s32 i) {
    s32 j;

    for (j = 0; j < 8; j++) {
        if ((u16) i == data_0217b1fc->mUnk_000[j].mUnk_48) {
            return (u16) j;
        }
    }
    return 0;
}

void func_020a16d0(u16 a) {
    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return;
    }
    if (data_0217b1fc->mUnk_000[a].mUnk_08 != 0) {
        return;
    }
    func_020a1904(a);
    func_020a1790();
}

u16 func_020a1520(void) {
    Unk0212c400 **h;
    s32 v;
    u16 k;
    s32 i;
    s32 m;
    s32 n;
    s32 a;

    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return 0;
    }
    v = data_0217b1fc->mUnk_3a4 + 1;
    if (v >= 3) {
        v = 3;
    }
    data_0217b1fc->mUnk_3a4 = v;
    data_0217b1fc->mUnk_3a2 = data_021565f0[data_0217b1fc->mUnk_3a4];
    a = data_0217b1fc->mUnk_3b0;
    if (a != data_0217b1fc->mUnk_3ac) {
        n = data_021759c0->mKartCount;
        for (m = 0; m <= a; m++) {
            for (i = n - 1; i >= 0; i--) {
                k = func_020a12b8_inline(i);
                if (m == data_0217b1fc->mUnk_000[k].mUnk_4c) {
                    func_020a1904(k);
                }
            }
            func_020a1790();
            if (data_0217b1fc->mUnk_3b4 >= 0) {
                return 0;
            }
        }
    }
    if (data_0217c780 & 1) {
        h = (Unk0212c400 **) func_0210e128((void *) func_02108ea0(0));
        if (data_0217d084.mUnk_0c != 0) {
            if (h[0] != NULL) {
                func_0212c6f0(h, 0);
            }
            if (h[0] != NULL) {
                func_0212c6f0(h, 0);
            }
            func_0212ecc0(h, 0, 0x4b);
        }
    }
    return data_0217b1fc->mUnk_3a2;
}

void func_020a12b8(void) {
    s32 n;
    s32 i;
    u16 k;
    s32 m;
    u16 s;
    Unk020f41c4_B *r;

    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return;
    }
    if (data_021759c0->mUnk_08 == 2) {
        n = data_021759c0->mKartCount;
        if (data_021759c0->mUnk_18 == 0) {
            if (data_0217b1fc->mUnk_3b4 >= 0) {
                return;
            }
            s = (u16) n;
            do {
                r = &data_0217561c->mUnk_47c;
                if ((u16) n == 0) {
                    m = 0;
                } else {
                    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                    if (s == 0) {
                        m = (u32) (r->mUnk_00 >> 32);
                    } else {
                        m = (u32) (((u64) (u32) (r->mUnk_00 >> 32) * (u64) s) >> 32);
                    }
                }
                k = (u16) m;
                if (data_0217b1fc->mUnk_000[k].mUnk_08 == 0) {
                    func_020a16d0(k);
                    data_0217b1fc->mUnk_000[k].mUnk_08 = 2;
                }
            } while (data_0217b1fc->mUnk_3b4 < 0);
        } else if (data_021759c0->mUnk_18 == 1) {
            for (i = n - 1; i >= 0; i--) {
                if (data_0217b1fc->mUnk_3b4 < 0) {
                    k = func_020a12b8_inline(i);
                    if (data_0217b1fc->mUnk_000[k].mUnk_08 == 0) {
                        func_020a16d0(k);
                        data_0217b1fc->mUnk_000[k].mUnk_08 = 2;
                    }
                }
            }
        }
    } else if (data_021759c0->mUnk_08 == 4) {
        for (i = 7; i >= 0; i--) {
            k = func_020a12b8_inline(i);
            if (k != data_021759c0->mUnk_62 && data_0217b1fc->mUnk_3b4 < 0) {
                func_020a16d0(k);
            }
        }
    }
}

u32 func_020a128c(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    value1 = (u32) &data_0217b1fc;
    value0 = 0u;
    value2 = (u32) * (const u32 *) ((value1) + (0));
    value1 = (u32) * (const u32 *) ((value2) + (948));
    compareLeft0 = value1;
    compareRight0 = 0u;
    if ((s32) compareLeft0 < (s32) compareRight0) {
        return value0;
    }
    value1 = (u32) * (const u32 *) ((value2) + (936));
    compareLeft1 = value1;
    compareRight1 = 0u;
    if ((s32) compareLeft1 < (s32) compareRight1) {
        value0 = 1u;
    }
    return value0;
}

BOOL func_020a126c(void) {
    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return TRUE;
    }
    return FALSE;
}

u16 func_020a1250(int arg0) {
    return data_0217b1fc->mUnk_000[arg0].mUnk_48;
}

u32 func_020a1238(void) {
    return ((u32) data_0217b1fc->mUnk_3a0);
}

void func_020a1218(short a) {
    Unk0217b1fc *v1;
    v1 = data_0217b1fc;
    v1->mUnk_3a0 = v1->mUnk_3a0 + a;
}

u16 func_020a119c(void) {
    s32 i;
    s32 v1;
    s32 n;
    s32 v;

    v1 = 0;
    n = data_021759c0->mKartCount;
    for (i = 0; i < n; i++) {
        v = data_0217b1fc->mUnk_000[(u16) i].mUnk_4c;
        if (v <= 0) {
            v = 0;
        }
        v1 += (u16) v;
    }
    return v1;
}

u16 func_020a1180(void) {
    return data_0217b1fc->mUnk_3ac;
}

u16 func_020a1154(u16 a) {
    s32 v;

    v = data_0217b1fc->mUnk_000[a].mUnk_4c;
    if (v <= 0) {
        v = 0;
    }
    return v;
}

void func_020a10f0(u16 a, s32 b) {
    data_0217b1fc->mUnk_000[a].mUnk_4c += b;
    if (b > 0) {
        func_020a1b6c(a);
    } else if (b < 0) {
        func_020a19f8(a);
    }
}

u16 func_020a10d4(u16 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217b1fc;
    value1 = 0x70u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u16 *) ((value1) + (80));
    return (u16) value0;
}

void func_020a10ac(u16 a, s32 b) {
    data_0217b1fc->mUnk_000[a].mUnk_50 += b;
}

BOOL func_020a1084(int a) {
    if (data_0217b1fc->mUnk_000[a].mUnk_08 != 0) {
        return TRUE;
    }
    return FALSE;
}

s32 func_020a1048(u16 a) {
    Unk0217b1fc *d;
    BOOL r;
    s32 v;

    d = data_0217b1fc;
    r = FALSE;
    v = d->mUnk_000[a].mUnk_4c;
    if (d->mUnk_3b0 == v) {
        if (d->mUnk_3ac != v) {
            r = TRUE;
        }
    }
    return r;
}

s32 func_020a100c(s32 a) {
    Unk0217b1fc_000 *e;
    BOOL r;

    e = &data_0217b1fc->mUnk_000[a];
    r = FALSE;
    if (data_0217b1fc->mUnk_3b4 == e->mUnk_46) {
        if (data_0217b1fc->mUnk_3a8 < 0) {
            r = TRUE;
        }
    }
    return r;
}

Vec3 *func_020a0ff0(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217b1fc;
    value1 = 0x70u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (value1) + (0xcu);
    return (Vec3 *) value0;
}
