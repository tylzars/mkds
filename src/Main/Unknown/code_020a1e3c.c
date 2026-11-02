#include "Main/Unknown/code_020a1e3c.h"

#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020a2204.h"
#include "Main/Unknown/code_020a2220.h"
#include "Main/Unknown/code_020a223c.h"
#include "Main/Unknown/code_020a228c.h"
#include "Main/Unknown/code_020a22ac.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020a2300.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"

void func_020a238c(u32 p0) {
    *(u32 *) ((u8 *) (u32) (((u32) data_0217b1fc)) + 956) = p0;
}

Unk020a3fa8_a4 *func_020a2378(void) {
    return data_0217b1fc->mUnk_3bc;
}

void func_020a2364(u32 p0) {
    *(u32 *) ((u8 *) (u32) (((u32) data_0217b1fc)) + 896) = p0;
}

void func_020a2350(u32 p0) {
    *(u32 *) ((u8 *) (u32) (((u32) data_0217b1fc)) + 900) = p0;
}

void func_020a233c(s32 (*p0)(u16 a, u16 b)) {
    *(u32 *) ((u8 *) (u32) (((u32) data_0217b1fc)) + 904) = (u32) p0;
}

void func_020a2328(void (*p0)(u16 a)) {
    *(u32 *) ((u8 *) (u32) (((u32) data_0217b1fc)) + 908) = (u32) p0;
}

void func_020a2314(void (*a)(void)) {
    data_0217b1fc->mUnk_390 = a;
}

void func_020a2300(u32 p0) {
    *(u32 *) ((u8 *) (u32) (((u32) data_0217b1fc)) + 924) = p0;
}

void func_020a22ac(u16 a) {
    if (func_02061fec() != 1) {
        return;
    }
    if (func_01ffc67c(func_0207a974(a)) != 0) {
        return;
    }
    data_0217b1fc->mUnk_000[a].mUnk_64 = 10;
}

void func_020a228c(int a) {
    *(u32 *) (a * 0x70 + (u32) data_0217b1fc + 100) = 0xffffffff;
}

s32 func_020a2264(u16 a) {
    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return -1;
    }
    return data_0217b1fc->mUnk_000[a].mUnk_64;
}

s32 func_020a223c(u16 a) {
    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return -1;
    }
    return data_0217b1fc->mUnk_000[a].mUnk_68;
}

void func_020a2220(u16 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value3;
    value3 = (u32) &data_0217b1fc;
    value2 = 0x70u;
    value3 = (u32) * (const u32 *) ((value3) + (0));
    value2 = (value0) * (value2) + (value3);
    *(u32 *) ((value2) + (108)) = value1;
}

u32 func_020a2204(u16 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217b1fc;
    value1 = 0x70u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value1) + (108));
    return value0;
}

void func_020a21bc(s32 a, s32 b) {
    if (b == 0) {
        return;
    }
    if (data_0217b1fc->mUnk_39c != NULL) {
        data_0217b1fc->mUnk_39c(a, b);
    }
}

s32 func_020a1ee4(s32 a, s32 b) {
    Unk0206bcb0 *v1;
    Unk0206bcb0 *v2;
    Unk0217b1fc_000 *v3;
    Unk0217b1fc_000 *v4;
    BOOL f5;
    s32 f4;
    BOOL f11;
    BOOL t;

    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return 0;
    }
    v1 = func_0207a974(a);
    v2 = func_0207a974(b);
    v4 = &data_0217b1fc->mUnk_000[b];
    v3 = &data_0217b1fc->mUnk_000[a];
    f5 = FALSE;
    if (v4->mUnk_24[a] == 0) {
        if ((v1->mUnk_48 & 0x100000) != 0) {
            f5 = TRUE;
        }
    }
    f4 = 0;
    if (v3->mUnk_24[b] == 0) {
        if ((v2->mUnk_48 & 0x100000) != 0) {
            f4 = 1;
        }
    }
    f11 = TRUE;
    if ((v1->mUnk_4c & 0x400000) == 0) {
        if (func_0207a8a4(a) != 1) {
            f11 = FALSE;
        }
    }
    t = TRUE;
    if ((v2->mUnk_4c & 0x400000) == 0) {
        if (func_0207a8a4(b) != 1) {
            t = FALSE;
        }
    }
    if (f4 != 0) {
        v3->mUnk_24[b] = 1;
    }
    if (f5 != FALSE) {
        v4->mUnk_24[a] = 1;
    }
    if (f11 == FALSE && t == FALSE && f5 != FALSE && f4 != 0) {
        if (data_0217b1fc->mUnk_384 != NULL) {
            data_0217b1fc->mUnk_384(a, b);
            return 1;
        }
    } else if (f11 == FALSE && f4 != 0) {
        f4 = 0;
        if (func_0207a8a4(b) == 1) {
            v3->mUnk_20 = 1;
            if (data_0217b1fc->mUnk_380 != NULL) {
                f4 = data_0217b1fc->mUnk_380(a, b);
                if ((v1->mUnk_4c & 0x400000) == 0) {
                    func_0206c17c(v1);
                }
            }
        } else if (data_0217b1fc->mUnk_380 != NULL) {
            f4 = data_0217b1fc->mUnk_380(a, b);
            if ((v1->mUnk_4c & 0x400000) == 0) {
                func_0206c17c(v1);
            }
        }
        return f4;
    } else if (t == FALSE && f5 != FALSE) {
        f4 = 0;
        if (func_0207a8a4(a) == 1) {
            v4->mUnk_20 = 1;
            if (data_0217b1fc->mUnk_380 != NULL) {
                f4 = data_0217b1fc->mUnk_380(b, a);
                if ((v2->mUnk_4c & 0x400000) == 0) {
                    func_0206c17c(v2);
                }
            }
        } else if (data_0217b1fc->mUnk_380 != NULL) {
            f4 = data_0217b1fc->mUnk_380(b, a);
            if ((v2->mUnk_4c & 0x400000) == 0) {
                func_0206c17c(v2);
            }
        }
        return f4;
    }
    return 0;
}

void func_020a1e40(s32 a, Unk020f41c4_A *p) {
    u16 v;

    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return;
    }
    if (func_0207a974(a)->mUnk_180 == 0) {
        return;
    }
    if (p->mUnk_44 != 0 && p->mUnk_44 != 1 && p->mUnk_44 != 9) {
        return;
    }
    v = p->mUnk_78;
    if ((v & 0x8000) != 0) {
        return;
    }
    data_0217b1fc->mUnk_000[a].mUnk_44 = v & ~0xff00;
}

u32 func_020a1e3c(u32 p0) {
    return p0;
}
