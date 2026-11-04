#include "01/code_021928c8.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "01/code_02188158.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_0209b000.h"
#include "01/code_02192000.h"
#include "Main/Unknown/code_0209bef0.h"

Unk021a9bc8 *data_ov001_021a9bc8;

void func_ov001_02192d28(void) {
    data_ov001_021a9bc8 = HeapAlloc((void *) GetHeap(func_020364e8()), 0x54);
}

void func_ov001_02192a78(void) {
    Unk02175628Index idx;
    BOOL f1;
    int f0;
    u16 v;
    u16 t;
    s32 n;

    data_ov001_021a9bc8->mUnk_18 = data_ov001_021a9bc8->mUnk_00;
    data_ov001_021a9bc8->mUnk_1c = data_ov001_021a9bc8->mUnk_04;
    data_ov001_021a9bc8->mUnk_20 = data_ov001_021a9bc8->mUnk_08;
    data_ov001_021a9bc8->mUnk_28 = data_ov001_021a9bc8->mUnk_10;
    data_ov001_021a9bc8->mUnk_24 = data_ov001_021a9bc8->mUnk_0c;
    if (data_ov001_021a9bc8->mUnk_10 == 0 && data_02175928[0x14] != 0 && data_02175928[0x15] != 0) {
        data_ov001_021a9bc8->mUnk_08 = 1;
    } else {
        data_ov001_021a9bc8->mUnk_08 = 0;
    }
    if (data_ov001_021a9bc8->mUnk_10 != 0 && data_02175928[0x14] == 0 && data_02175928[0x15] == 0) {
        data_ov001_021a9bc8->mUnk_0c = 1;
    } else {
        data_ov001_021a9bc8->mUnk_0c = 0;
    }
    idx = UNK_02175628_INDEX_8;
    f1 = TRUE;
    f0 = 0;
    v = data_02175628[idx].mHasPair;
    if (v == 0 && data_02175628[idx].mNoPairCount < 5) {
        f0 = f1;
    }
    if (f0 == 0 && v == 0) {
        f1 = FALSE;
    }
    if (f1 != FALSE && (v = data_02175928[0x14]) != 0 && data_02175928[0x15] != 0) {
        data_ov001_021a9bc8->mUnk_00 = v;
        data_ov001_021a9bc8->mUnk_04 = data_02175928[0x15];
        data_ov001_021a9bc8->mUnk_10 = 1;
    } else {
        data_ov001_021a9bc8->mUnk_10 = 0;
    }
    if (data_ov001_021a9bc8->mUnk_10 != 0 && data_ov001_021a9bc8->mUnk_00 <= data_ov001_021a9bc8->mUnk_18 + 1 &&
        data_ov001_021a9bc8->mUnk_00 >= data_ov001_021a9bc8->mUnk_18 - 1 &&
        data_ov001_021a9bc8->mUnk_04 <= data_ov001_021a9bc8->mUnk_1c + 1 &&
        data_ov001_021a9bc8->mUnk_04 >= data_ov001_021a9bc8->mUnk_1c - 1) {
        data_ov001_021a9bc8->mUnk_14++;
        if (data_ov001_021a9bc8->mUnk_14 > 0x3c) {
            data_ov001_021a9bc8->mUnk_14 = 0;
            data_ov001_021a9bc8->mUnk_08 = 1;
            data_ov001_021a9bc8->mUnk_0c = 1;
        }
    } else {
        data_ov001_021a9bc8->mUnk_14 = 0;
    }
    t = data_021758e8[0x11] & 0x20;
    if (t == 0) {
        n = 0;
    } else {
        n = data_ov001_021a9bc8->mUnk_2c + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    data_ov001_021a9bc8->mUnk_2c = n;
    t = data_021758e8[0x11] & 0x10;
    if (t == 0) {
        n = 0;
    } else {
        n = data_ov001_021a9bc8->mUnk_30 + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    data_ov001_021a9bc8->mUnk_30 = n;
    t = data_021758e8[0x11] & 0x40;
    if (t == 0) {
        n = 0;
    } else {
        n = data_ov001_021a9bc8->mUnk_34 + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    data_ov001_021a9bc8->mUnk_34 = n;
    t = data_021758e8[0x11] & 0x80;
    if (t == 0) {
        n = 0;
    } else {
        n = data_ov001_021a9bc8->mUnk_38 + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    data_ov001_021a9bc8->mUnk_38 = n;
    t = data_021758e8[0x11] & 0x1;
    if (t == 0) {
        n = 0;
    } else {
        n = data_ov001_021a9bc8->mUnk_3c + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    data_ov001_021a9bc8->mUnk_3c = n;
    t = data_021758e8[0x11] & 0x2;
    if (t == 0) {
        n = 0;
    } else {
        n = data_ov001_021a9bc8->mUnk_40 + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    data_ov001_021a9bc8->mUnk_40 = n;
    t = data_021758e8[0x11] & 0x400;
    if (t == 0) {
        n = 0;
    } else {
        n = data_ov001_021a9bc8->mUnk_44 + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    data_ov001_021a9bc8->mUnk_44 = n;
    t = data_021758e8[0x11] & 0x800;
    if (t == 0) {
        n = 0;
    } else {
        n = data_ov001_021a9bc8->mUnk_48 + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    data_ov001_021a9bc8->mUnk_48 = n;
    t = data_021758e8[0x11] & 0x200;
    if (t == 0) {
        n = 0;
    } else {
        n = data_ov001_021a9bc8->mUnk_4c + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    data_ov001_021a9bc8->mUnk_4c = n;
    t = data_021758e8[0x11] & 0x100;
    if (t == 0) {
        n = 0;
    } else {
        n = data_ov001_021a9bc8->mUnk_50 + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    data_ov001_021a9bc8->mUnk_50 = n;
}

s32 func_ov001_02192a6c(void) {
    return data_ov001_021a9bc8->mUnk_00;
}

u32 func_ov001_02192a60(void) {
    return data_ov001_021a9bc8->mUnk_04;
}

u32 func_ov001_02192a54(void) {
    return data_ov001_021a9bc8->mUnk_08;
}

u32 func_ov001_02192a48(void) {
    return data_ov001_021a9bc8->mUnk_10;
}

u32 func_ov001_02192a3c(void) {
    return data_ov001_021a9bc8->mUnk_18;
}

u32 func_ov001_02192a30(void) {
    return data_ov001_021a9bc8->mUnk_1c;
}

u32 func_ov001_02192a24(void) {
    return data_ov001_021a9bc8->mUnk_28;
}

u16 func_ov001_02192a14(u16 a) {
    return data_021758e8[0x10] & a;
}

u16 func_ov001_02192a04(u16 a) {
    return data_021758e8[0x11] & a;
}

BOOL func_ov001_021928c8(int a) {
    switch (a) {
        case 0x20:
            return data_ov001_021a9bc8->mUnk_2c == 1 || data_ov001_021a9bc8->mUnk_2c == 0xf;
        case 0x10:
            return data_ov001_021a9bc8->mUnk_30 == 1 || data_ov001_021a9bc8->mUnk_30 == 0xf;
        case 0x40:
            return data_ov001_021a9bc8->mUnk_34 == 1 || data_ov001_021a9bc8->mUnk_34 == 0xf;
        case 0x80:
            return data_ov001_021a9bc8->mUnk_38 == 1 || data_ov001_021a9bc8->mUnk_38 == 0xf;
        case 1:
            return data_ov001_021a9bc8->mUnk_3c == 1 || data_ov001_021a9bc8->mUnk_3c == 0xf;
        case 2:
            return data_ov001_021a9bc8->mUnk_40 == 1 || data_ov001_021a9bc8->mUnk_40 == 0xf;
        case 0x400:
            return data_ov001_021a9bc8->mUnk_44 == 1 || data_ov001_021a9bc8->mUnk_44 == 0xf;
        case 0x800:
            return data_ov001_021a9bc8->mUnk_48 == 1 || data_ov001_021a9bc8->mUnk_48 == 0xf;
        case 0x200:
            return data_ov001_021a9bc8->mUnk_4c == 1 || data_ov001_021a9bc8->mUnk_4c == 0xf;
        case 0x100:
            return data_ov001_021a9bc8->mUnk_50 == 1 || data_ov001_021a9bc8->mUnk_50 == 0xf;
    }
    return FALSE;
}
