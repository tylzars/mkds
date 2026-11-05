#include "Main/Unknown/code_0211ac70.h"

#include "Main/Unknown/code_0202bb80.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_0211ac88.h"
#include "Main/Unknown/code_0211b23c.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128244.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0211b224.h"
#include "Main/Unknown/code_0211e4e8.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0202056c.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_0202c000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02116dc8.h"
#include "Main/Unknown/code_02116dd4.h"
#include "Main/Unknown/code_02116000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_0211d3a8.h"
#include "Main/Unknown/code_0211d3f4.h"
#include "Main/Unknown/code_0211d40c.h"
#include "Main/Unknown/code_0211d428.h"
#include "Main/Unknown/code_0211d44c.h"
#include "Main/Unknown/code_0211d62c.h"
#include "Main/Unknown/code_0211db90.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02127000.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_0212b000.h"
#include "code_02148950.h"
#include "registers.h"
#include "Main/Unknown/code_0211d000.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0202b604.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02125000.h"
#include "code_02016468.h"

#pragma thumb on

void func_0211db30(Unk0215ce70 *a, s32 b) {
    Unk0215ce70 v;

    if (gSelectRaceRule->mMode == 3) {
        v = data_0215ce70[b];
    } else {
        v = data_0215ce0c[b];
    }
    *a = v;
}

void func_0211d9dc(void) {
    Unk0215ce70 buf;
    s32 i;

    for (i = 0; i < 5; i++) {
        if (gSelectRaceRule->mUnk_7c == 0 && gSelectRaceRule->mUnk_60 == i) {
            func_02124100(data_0215cd4c[i].mUnk_00[0], 1, gSelectRaceRule->mBnll, gSelectRaceRule->mUnk_14,
                          gSelectRaceRule->mBncl);
        } else {
            func_02124100(data_0215cd4c[i].mUnk_00[0], 0, gSelectRaceRule->mBnll, gSelectRaceRule->mUnk_14,
                          gSelectRaceRule->mBncl);
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        if (gSelectRaceRule->mUnk_7c != 0 && gSelectRaceRule->mUnk_84 != 0) {
            gSelectRaceRule->mUnk_14[0x28].mUnk_00 = 0;
            gSelectRaceRule->mUnk_14[0x29].mUnk_00 = 1;
            func_02124100(0xd, 1, gSelectRaceRule->mBnll, gSelectRaceRule->mUnk_14, gSelectRaceRule->mBncl);
        } else {
            gSelectRaceRule->mUnk_14[0x28].mUnk_00 = 1;
            gSelectRaceRule->mUnk_14[0x29].mUnk_00 = 0;
            func_02124100(0xd, 0, gSelectRaceRule->mBnll, gSelectRaceRule->mUnk_14, gSelectRaceRule->mBncl);
        }
    }
    if (gSelectRaceRule->mUnk_80 == gSelectRaceRule->mUnk_7c && gSelectRaceRule->mUnk_64 == gSelectRaceRule->mUnk_60) {
        return;
    }
    for (i = 0; i < 5; i++) {
        func_0211db30(&buf, i);
        func_020b44a4(gSelectRaceRule->mNscr->mData, buf.mUnk_00, buf.mUnk_04, buf.mUnk_08, buf.mUnk_0c, buf.mUnk_10);
    }
    if (gSelectRaceRule->mUnk_7c == 0) {
        func_0211db30(&buf, gSelectRaceRule->mUnk_60);
        func_020b44a4(gSelectRaceRule->mNscr->mData, buf.mUnk_00, buf.mUnk_04, buf.mUnk_08, buf.mUnk_0c, buf.mUnk_12);
    }
    CallQueueAppend(0x1b, 0, gSelectRaceRule->mNscr->mData, 0x600);
}

void func_0211d910(s16 a) {
    u16 buf[0x40];
    u16 buf2[0x40];

    if (a < 1) {
        a = 1;
    }
    if (a > 0xa) {
        a = 0xa;
    }
    gSelectRaceRule->mUnk_88 = a;
    func_02124f4c(gSelectRaceRule->mUnk_88, buf2);
    if (data_021759d0->mUnk_20 != 2) {
        func_0212426c(1, 9, gSelectRaceRule->mBnll, GetBmgEntry(gSelectRaceRule->mUnk_1c, data_0216dc0c[3][0]),
                      gSelectRaceRule->mBncl, gSelectRaceRule->mUnk_14);
        func_02124248(1, 8, gSelectRaceRule->mBnll, buf2, gSelectRaceRule->mBncl, gSelectRaceRule->mUnk_14, 0xb);
    } else {
        func_02124f4c(gSelectRaceRule->mUnk_88, buf);
        func_0212513c(buf, GetBmgEntry(gSelectRaceRule->mUnk_1c, 0x16), buf2, 0x80);
        func_0212426c(1, 0xa, gSelectRaceRule->mBnll, buf2, gSelectRaceRule->mBncl, gSelectRaceRule->mUnk_14);
    }
}

void func_0211d844(s16 a) {
    u16 buf[0x40];
    u16 buf2[0x40];

    if (a < 1) {
        a = 1;
    }
    if (a > 0x20) {
        a = 0x20;
    }
    gSelectRaceRule->mUnk_8a = a;
    func_02124f4c(gSelectRaceRule->mUnk_8a, buf2);
    if (data_021759d0->mUnk_20 != 2) {
        func_0212426c(1, 9, gSelectRaceRule->mBnll, GetBmgEntry(gSelectRaceRule->mUnk_1c, data_0216dc0c[3][1]),
                      gSelectRaceRule->mBncl, gSelectRaceRule->mUnk_14);
        func_02124248(1, 8, gSelectRaceRule->mBnll, buf2, gSelectRaceRule->mBncl, gSelectRaceRule->mUnk_14, 0xb);
    } else {
        func_02124f4c(gSelectRaceRule->mUnk_8a, buf);
        func_0212513c(buf, GetBmgEntry(gSelectRaceRule->mUnk_1c, 0x17), buf2, 0x80);
        func_0212426c(1, 0xa, gSelectRaceRule->mBnll, buf2, gSelectRaceRule->mBncl, gSelectRaceRule->mUnk_14);
    }
}

void func_0211d66c(void) {
    u16 h = gSelectRaceRule->mBncl->mUnk_06;

    if (data_021759d0->mUnk_20 != 2) {
        switch (gSelectRaceRule->mUnk_68[3]) {
            case 0:
            case 1:
                gSelectRaceRule->mUnk_14[h + 9].mUnk_00 = 1;
                gSelectRaceRule->mUnk_14[h + 10].mUnk_00 = 0;
                gSelectRaceRule->mUnk_14[h + 8].mUnk_00 = 1;
                break;
            case 2:
                gSelectRaceRule->mUnk_14[h + 9].mUnk_00 = 0;
                gSelectRaceRule->mUnk_14[h + 10].mUnk_00 = 1;
                gSelectRaceRule->mUnk_14[h + 8].mUnk_00 = 0;
                break;
        }
        switch (gSelectRaceRule->mUnk_78) {
            case 0:
            case 1:
                gSelectRaceRule->mUnk_14[h + 11].mUnk_00 = 1;
                gSelectRaceRule->mUnk_14[h + 12].mUnk_00 = 0;
                break;
            case 2:
                gSelectRaceRule->mUnk_14[h + 11].mUnk_00 = 0;
                gSelectRaceRule->mUnk_14[h + 12].mUnk_00 = 1;
                break;
        }
    } else {
        gSelectRaceRule->mUnk_14[0x1e].mUnk_00 = 0;
        gSelectRaceRule->mUnk_14[0x1f].mUnk_00 = 0;
        switch (gSelectRaceRule->mUnk_68[3]) {
            case 0:
                gSelectRaceRule->mUnk_14[h + 10].mUnk_00 = 1;
                func_0211d910(gSelectRaceRule->mUnk_88);
                break;
            case 1:
                gSelectRaceRule->mUnk_14[h + 10].mUnk_00 = 1;
                func_0211d844(gSelectRaceRule->mUnk_8a);
                break;
            case 2:
                gSelectRaceRule->mUnk_14[h + 10].mUnk_00 = 1;
                func_0212426c(1, 0xa, gSelectRaceRule->mBnll,
                              GetBmgEntry(gSelectRaceRule->mUnk_1c, data_0216dc0c[3][2]), gSelectRaceRule->mBncl,
                              gSelectRaceRule->mUnk_14);
                break;
        }
        switch (gSelectRaceRule->mUnk_78) {
            case 0:
            case 1:
                gSelectRaceRule->mUnk_14[h + 11].mUnk_00 = 1;
                gSelectRaceRule->mUnk_14[h + 12].mUnk_00 = 0;
                break;
            case 2:
                gSelectRaceRule->mUnk_14[h + 11].mUnk_00 = 0;
                gSelectRaceRule->mUnk_14[h + 12].mUnk_00 = 1;
                break;
        }
    }
    if (gSelectRaceRule->mMode == 3) {
        gSelectRaceRule->mUnk_14[h + data_0215cd4c[0].mUnk_00[1]].mUnk_00 = 0;
        gSelectRaceRule->mUnk_14[h + data_0215cd4c[2].mUnk_00[1]].mUnk_00 = 0;
    }
}

u16 func_0211d650(void) {
    return gSelectRaceRule->mUnk_ac[0] + gSelectRaceRule->mUnk_ac[1];
}

#pragma thumb off

#pragma thumb on

u16 func_0211d62c(void) {
    int v1;
    v1 = *(s32 *) &gSelectRaceRule;
    if (*(s32 *) (v1 + 0x6c) == 0) {
        return 0;
    }
    return *(u16 *) (v1 + 0xb0) + *(u16 *) (v1 + 0xb2);
}

#pragma thumb off

#pragma thumb on

void func_0211d56c(void) {
    u32 a = 1;
    u16 h = gSelectRaceRule->mBncl->mUnk_06;
    Unk027ffc40 *v;

    if (gSelectRaceRule->mUnk_7c != 0) {
        gSelectRaceRule->mUnk_60 = 0;
        gSelectRaceRule->mUnk_7c = 0;
        if (gSelectRaceRule->mUnk_14[h + data_0215cd4c[gSelectRaceRule->mUnk_60].mUnk_00[0]].mUnk_00 == 0 ||
            (func_0211d650() == 8 && gSelectRaceRule->mUnk_60 == 1)) {
            a = 0;
            func_0211d56c();
        }
    } else {
        gSelectRaceRule->mUnk_60++;
        if (gSelectRaceRule->mUnk_60 >= 5) {
            gSelectRaceRule->mUnk_60--;
            gSelectRaceRule->mUnk_7c = a;
            v = (Unk027ffc40 *) 0x027ffc40;
            if (v->mUnk_00 != 2) {
                func_0212b7fc();
            }
        } else if (gSelectRaceRule->mUnk_14[h + data_0215cd4c[gSelectRaceRule->mUnk_60].mUnk_00[0]].mUnk_00 == 0 ||
                   (func_0211d650() == 8 && gSelectRaceRule->mUnk_60 == 1)) {
            a = 0;
            func_0211d56c();
        }
    }
    if (a != 0) {
        func_0212ecc0(&data_0217d068, 0, 0);
    }
}

void func_0211d4a8(void) {
    u32 a = 1;
    u16 h = gSelectRaceRule->mBncl->mUnk_06;
    Unk027ffc40 *v;

    if (gSelectRaceRule->mUnk_7c != 0) {
        gSelectRaceRule->mUnk_60 = 4;
        gSelectRaceRule->mUnk_7c = 0;
        if (gSelectRaceRule->mUnk_14[h + data_0215cd4c[gSelectRaceRule->mUnk_60].mUnk_00[0]].mUnk_00 == 0 ||
            (func_0211d650() == 8 && gSelectRaceRule->mUnk_60 == 1)) {
            a = 0;
            func_0211d4a8();
        }
    } else {
        gSelectRaceRule->mUnk_60--;
        if (gSelectRaceRule->mUnk_60 < 0) {
            gSelectRaceRule->mUnk_60++;
            gSelectRaceRule->mUnk_7c = a;
            v = (Unk027ffc40 *) 0x027ffc40;
            if (v->mUnk_00 != 2) {
                func_0212b7fc();
            }
        } else if (gSelectRaceRule->mUnk_14[h + data_0215cd4c[gSelectRaceRule->mUnk_60].mUnk_00[0]].mUnk_00 == 0 ||
                   (func_0211d650() == 8 && gSelectRaceRule->mUnk_60 == 1)) {
            a = 0;
            func_0211d4a8();
        }
    }
    if (a != 0) {
        func_0212ecc0(&data_0217d068, 0, 0);
    }
}

#pragma thumb off

#pragma thumb on

u16 func_0211d478(s32 a) {
    SelectRaceRule *p;
    p = gSelectRaceRule;
    if (p->mUnk_68[1] == 0) {
        return p->mUnk_ac[a];
    }
    return p->mUnk_ac[a] + p->mUnk_b0[a];
}

u32 func_0211d44c(s32 a) {
    if (func_0211d478(gSelectRaceRule->mUnk_8c[a]) != 1) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void func_0211d428(u16 a, u32 b) {
    gSelectRaceRule->mUnk_8c[a] = b;
    func_0202b6a0(a, data_0215cca4[b]);
}

#pragma thumb off

#pragma thumb on

u32 func_0211d40c(u16 a) {
    u32 v1;
    v1 = func_0211d650();
    if (v1 > a) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

u32 func_0211d3f4(u32 a) {
    u32 v = 2;

    switch (a) {
        case 0:
            v = 1;
            break;
        case 1:
            v = 0;
            break;
    }
    return v;
}

#pragma thumb off

#pragma thumb on

u32 func_0211d3a8(void) {
    u32 a;
    u32 b;
    if (gSelectRaceRule->mUnk_68[1] != 0) {
        a = func_0211d478(0);
        b = func_0211d478(1);
        if (a > b) {
            return 0;
        }
        a = func_0211d478(0);
        b = func_0211d478(1);
        if (a < b) {
            return 1;
        }
    }
    return 2;
}

#pragma thumb off

#pragma thumb on

BOOL func_0211d2f0(u16 *a) {
    Unk020f41c4_B *p;
    u32 n;
    u32 c;
    if (func_0211d62c() == 0) {
        *a = 8;
        return FALSE;
    }
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            c = func_0211d650();
            *a = c + func_020ae3b4(func_0211d62c());
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            p = &data_0217aa00->mUnk_1ee8;
            n = func_0211d62c();
            p->mUnk_00 = p->mUnk_10 + (u64) ((s64) p->mUnk_08 * (s64) p->mUnk_00);
            *a = func_0211d650() +
                 (n == 0 ? (u32) (p->mUnk_00 >> 32) : (u32) (((s64) (u32) (p->mUnk_00 >> 32) * (s64) n) >> 32));
            break;
    }
    return TRUE;
}

void func_0211d174(u16 a, u32 b) {
    u16 c;
    u16 v;
    c = 8;
    if (b == gSelectRaceRule->mUnk_8c[a]) {
        return;
    }
    if (func_0211d44c(a) == 0) {
        v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mUnk_0432 : 0;
        if (a == data_0217aa00->mUnk_1e52[v].mUnk_00) {
            func_0212ecc0(&data_0217d068, 0, 0x16);
        }
        return;
    }
    func_0211d428(a, b);
    if (func_0211d40c(a) != 0) {
        gSelectRaceRule->mUnk_ac[b]++;
        gSelectRaceRule->mUnk_ac[func_0211d3f4(b)]--;
    } else {
        gSelectRaceRule->mUnk_b0[b]++;
        gSelectRaceRule->mUnk_b0[func_0211d3f4(b)]--;
    }
    b = func_0211d3a8();
    if (b != 2 && gSelectRaceRule->mUnk_b0[b] != 0) {
        func_0211d2f0(&c);
        while (b != gSelectRaceRule->mUnk_8c[c]) {
            func_0211d2f0(&c);
        }
        func_0211d174(c, func_0211d3f4(b));
    }
    v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mUnk_0432 : 0;
    if (a == data_0217aa00->mUnk_1e52[v].mUnk_00) {
        switch (gSelectRaceRule->mUnk_8c[a]) {
            case 0:
                gSelectRaceRule->mUnk_50[1][0] = 6;
                break;
            case 1:
                gSelectRaceRule->mUnk_50[1][1] = 6;
                break;
        }
        func_0212ecc0(&data_0217d068, 0, 4);
    }
}

void func_0211d09c(void) {
    s32 a;
    s32 i;
    u16 n;
    Unk020f41c4_B *p;
    a = 2;
    n = func_0211d650();
    gSelectRaceRule->mUnk_ac[0] = 0;
    gSelectRaceRule->mUnk_ac[1] = 0;
    for (i = 0; i < n; i++) {
        switch (gSelectRaceRule->mMode) {
            case 0:
            case 1:
                a = func_020ae3b4(2);
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                p = &data_0217aa00->mUnk_1ee8;
                p->mUnk_00 = p->mUnk_10 + (u64) ((s64) p->mUnk_08 * (s64) p->mUnk_00);
                a = ((u64) (u32) (p->mUnk_00 >> 32) * 2) >> 32;
                break;
        }
        if (n / 2 <= gSelectRaceRule->mUnk_ac[a]) {
            a = func_0211d3f4(a);
        }
        func_0211d428(i, a);
        gSelectRaceRule->mUnk_ac[a]++;
    }
}

void func_0211cfd0(void) {
    s32 a;
    s32 i;
    Unk020f41c4_B *p;
    a = 2;
    func_0211d650();
    gSelectRaceRule->mUnk_b0[0] = 0;
    gSelectRaceRule->mUnk_b0[1] = 0;
    for (i = func_0211d650(); i < 8; i++) {
        switch (gSelectRaceRule->mMode) {
            case 0:
            case 1:
                a = func_020ae3b4(2);
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                p = &data_0217aa00->mUnk_1ee8;
                p->mUnk_00 = p->mUnk_10 + (u64) ((s64) p->mUnk_08 * (s64) p->mUnk_00);
                a = ((u64) (u32) (p->mUnk_00 >> 32) * 2) >> 32;
                break;
        }
        if (func_0211d478(a) >= 4) {
            a = func_0211d3f4(a);
        }
        func_0211d428(i, a);
        gSelectRaceRule->mUnk_b0[a]++;
    }
}

BOOL func_0211cea8(void) {
    SelectRaceRule *p;
    p = gSelectRaceRule;
    if (p->mUnk_60 == 0 && p->mUnk_68[0] == 3 && func_0205fbb8(0x10) == 0) {
        return FALSE;
    }
    p = gSelectRaceRule;
    switch (p->mMode) {
        case 0:
            if (p->mUnk_60 == 1 && p->mUnk_68[1] == 0) {
                return FALSE;
            }
            if (p->mUnk_60 == 4 && p->mUnk_78 == 2) {
                return FALSE;
            }
            break;
        case 1:
            if (p->mUnk_60 == 1 && p->mUnk_68[1] == 0) {
                return FALSE;
            }
            if (p->mUnk_60 == 3 && p->mUnk_68[3] == 1) {
                return FALSE;
            }
            if (p->mUnk_60 == 4 && p->mUnk_78 == 2) {
                return FALSE;
            }
            break;
        case 2:
            if (p->mUnk_60 == 4 && p->mUnk_78 == 1) {
                return FALSE;
            }
            break;
        case 3:
            if (p->mUnk_60 == 3 && p->mUnk_68[3] == 1) {
                return FALSE;
            }
            if (p->mUnk_60 == 4 && p->mUnk_78 == 1) {
                return FALSE;
            }
            break;
        case 4:
            if (p->mUnk_60 == 4 && p->mUnk_78 == 1) {
                return FALSE;
            }
            break;
        case 5:
            if (p->mUnk_60 == 3 && p->mUnk_68[3] == 1) {
                return FALSE;
            }
            if (p->mUnk_60 == 4 && p->mUnk_78 == 1) {
                return FALSE;
            }
            break;
    }
    return TRUE;
}

BOOL func_0211ce24(void) {
    BOOL a;
    u8 b;
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            if (func_0211d650() == 1) {
                return TRUE;
            }
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            a = TRUE;
            if (data_0217aa00->mUnk_0004 != 8 && data_0217aa00->mUnk_0004 != 9) {
                a = FALSE;
            }
            b = a != FALSE ? CountSetBits(data_0217aa00->mUnk_15f6) : 0;
            if (b == func_0211d650()) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

s32 func_0211cdec(void) {
    BOOL a;
    a = TRUE;
    if (func_0211d478(0) == 0) {
        a = FALSE;
    }
    if (func_0211d478(1) == 0) {
        a = FALSE;
    }
    if (func_0211d3a8() != 2) {
        a = FALSE;
    }
    if (func_0211ce24() == FALSE) {
        a = FALSE;
    }
    return a;
}

void func_0211ccac(s32 a) {
    SelectRaceRule *p;
    s32 i;
    gSelectRaceRule->mUnk_68[gSelectRaceRule->mUnk_60]++;
    if (data_0215ccc0[gSelectRaceRule->mUnk_60] <= gSelectRaceRule->mUnk_68[gSelectRaceRule->mUnk_60]) {
        gSelectRaceRule->mUnk_68[gSelectRaceRule->mUnk_60] = 0;
    }
    if (func_0211cea8() == FALSE) {
        func_0211ccac(0);
    }
    p = gSelectRaceRule;
    if (p->mUnk_60 != 3) {
        func_0212426c(1, data_0215cd4e[p->mUnk_60 * 2], p->mBnll,
                      GetBmgEntry(p->mUnk_1c, data_0216dc0c[p->mUnk_60][p->mUnk_68[p->mUnk_60]]), p->mBncl, p->mUnk_14);
    } else {
        switch (p->mUnk_68[3]) {
            case 0:
                func_0211d910(p->mUnk_88);
                break;
            case 1:
                func_0211d844(p->mUnk_8a);
                break;
        }
        for (i = 0; i < 2; i++) {
            gSelectRaceRule->mUnk_50[0][i] = 0;
        }
    }
    if (gSelectRaceRule->mUnk_60 == 4) {
        for (i = 0; i < 2; i++) {
            gSelectRaceRule->mUnk_50[1][i] = 0;
        }
    }
    if (gSelectRaceRule->mUnk_60 == 1) {
        if (gSelectRaceRule->mUnk_68[1] == 0) {
            if (func_0211cdec() == 0) {
                func_0211d09c();
            }
            func_0202b618(0);
        } else {
            if (func_0211cdec() == 0) {
                func_0211cfd0();
            }
            func_0202b618(1);
        }
    }
    gSelectRaceRule->mUnk_3c[gSelectRaceRule->mUnk_60][1] = 6;
    if (a != 0) {
        func_0212ecc0(&data_0217d068, 0, 1);
    }
}

void func_0211cb6c(s32 a) {
    SelectRaceRule *p;
    s32 i;
    gSelectRaceRule->mUnk_68[gSelectRaceRule->mUnk_60]--;
    if (gSelectRaceRule->mUnk_68[gSelectRaceRule->mUnk_60] < 0) {
        gSelectRaceRule->mUnk_68[gSelectRaceRule->mUnk_60] = data_0215ccc0[gSelectRaceRule->mUnk_60] - 1;
    }
    if (func_0211cea8() == FALSE) {
        func_0211cb6c(0);
    }
    p = gSelectRaceRule;
    if (p->mUnk_60 != 3) {
        func_0212426c(1, data_0215cd4e[p->mUnk_60 * 2], p->mBnll,
                      GetBmgEntry(p->mUnk_1c, data_0216dc0c[p->mUnk_60][p->mUnk_68[p->mUnk_60]]), p->mBncl, p->mUnk_14);
    } else {
        switch (p->mUnk_68[3]) {
            case 0:
                func_0211d910(p->mUnk_88);
                break;
            case 1:
                func_0211d844(p->mUnk_8a);
                break;
        }
        for (i = 0; i < 2; i++) {
            gSelectRaceRule->mUnk_50[0][i] = 0;
        }
    }
    if (gSelectRaceRule->mUnk_60 == 4) {
        for (i = 0; i < 2; i++) {
            gSelectRaceRule->mUnk_50[1][i] = 0;
        }
    }
    if (gSelectRaceRule->mUnk_60 == 1) {
        if (gSelectRaceRule->mUnk_68[1] == 0) {
            if (func_0211cdec() == 0) {
                func_0211d09c();
            }
            func_0202b618(0);
        } else {
            if (func_0211cdec() == 0) {
                func_0211cfd0();
            }
            func_0202b618(1);
        }
    }
    gSelectRaceRule->mUnk_3c[gSelectRaceRule->mUnk_60][0] = 6;
    if (a != 0) {
        func_0212ecc0(&data_0217d068, 0, 1);
    }
}

void func_0211cafc(void) {
    BOOL a;
    SelectRaceRule *p;
    a = FALSE;
    p = gSelectRaceRule;
    if (p->mUnk_60 == 3) {
        switch (p->mUnk_68[3]) {
            case 0:
                func_0211d910(p->mUnk_88 + 1);
                gSelectRaceRule->mUnk_50[0][1] = 6;
                a = TRUE;
                break;
            case 1:
                func_0211d844(p->mUnk_8a + 1);
                gSelectRaceRule->mUnk_50[0][1] = 6;
                a = TRUE;
                break;
        }
        if (a != FALSE) {
            func_0212ecc0(&data_0217d068, 0, 0x17);
        }
    }
}

void func_0211ca8c(void) {
    BOOL a;
    SelectRaceRule *p;
    a = FALSE;
    p = gSelectRaceRule;
    if (p->mUnk_60 == 3) {
        switch (p->mUnk_68[3]) {
            case 0:
                func_0211d910(p->mUnk_88 - 1);
                gSelectRaceRule->mUnk_50[0][0] = 6;
                a = TRUE;
                break;
            case 1:
                func_0211d844(p->mUnk_8a - 1);
                gSelectRaceRule->mUnk_50[0][0] = 6;
                a = TRUE;
                break;
        }
        if (a != FALSE) {
            func_0212ecc0(&data_0217d068, 0, 0x17);
        }
    }
}

void func_0211c818(void) {
    s32 i;
    s32 j;
    if (data_021759d0->mUnk_20 == 2) {
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 2; j++) {
                gSelectRaceRule->mUnk_14[data_0215cd88[i][j]].mUnk_00 = 0;
                gSelectRaceRule->mUnk_14[data_0215cdb0[i][j]].mUnk_00 = 0;
                gSelectRaceRule->mUnk_14[data_0215cdc4[i][j]].mUnk_00 = 0;
            }
        }
        return;
    }
    for (i = 0; i < 5; i++) {
        if (func_0211d650() == 8 && i == 1) {
            for (j = 0; j < 2; j++) {
                gSelectRaceRule->mUnk_14[data_0215cd88[i][j]].mUnk_00 = 0;
                gSelectRaceRule->mUnk_14[data_0215cdb0[i][j]].mUnk_00 = 0;
                gSelectRaceRule->mUnk_14[data_0215cdc4[i][j]].mUnk_00 = 0;
            }
        } else {
            gSelectRaceRule->mUnk_14[data_0215cdb0[i][0]].mUnk_04 = -func_020adc64(6 - gSelectRaceRule->mUnk_3c[i][0]);
            gSelectRaceRule->mUnk_14[data_0215cdb0[i][1]].mUnk_04 = func_020adc64(6 - gSelectRaceRule->mUnk_3c[i][1]);
            for (j = 0; j < 2; j++) {
                if (gSelectRaceRule->mUnk_3c[i][j] > 0) {
                    gSelectRaceRule->mUnk_3c[i][j]--;
                    gSelectRaceRule->mUnk_14[data_0215cd88[i][j]].mUnk_00 = 0;
                    gSelectRaceRule->mUnk_14[data_0215cdb0[i][j]].mUnk_00 = 1;
                    gSelectRaceRule->mUnk_14[data_0215cdc4[i][j]].mUnk_00 = 0;
                } else if (gSelectRaceRule->mUnk_60 == i && gSelectRaceRule->mUnk_7c == 0) {
                    gSelectRaceRule->mUnk_14[data_0215cd88[i][j]].mUnk_00 = 1;
                    gSelectRaceRule->mUnk_14[data_0215cdb0[i][j]].mUnk_00 = 0;
                    gSelectRaceRule->mUnk_14[data_0215cdc4[i][j]].mUnk_00 = 0;
                } else {
                    gSelectRaceRule->mUnk_14[data_0215cd88[i][j]].mUnk_00 = 0;
                    gSelectRaceRule->mUnk_14[data_0215cdb0[i][j]].mUnk_00 = 0;
                    gSelectRaceRule->mUnk_14[data_0215cdc4[i][j]].mUnk_00 = 1;
                }
            }
        }
    }
    if (gSelectRaceRule->mMode == 3) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mUnk_14[data_0215cd88[0][j]].mUnk_00 = 0;
            gSelectRaceRule->mUnk_14[data_0215cd88[2][j]].mUnk_00 = 0;
            gSelectRaceRule->mUnk_14[data_0215cdb0[0][j]].mUnk_00 = 0;
            gSelectRaceRule->mUnk_14[data_0215cdb0[2][j]].mUnk_00 = 0;
            gSelectRaceRule->mUnk_14[data_0215cdc4[0][j]].mUnk_00 = 0;
            gSelectRaceRule->mUnk_14[data_0215cdc4[2][j]].mUnk_00 = 0;
        }
    }
}

void func_0211c810(u16 a, u32 b) {
    func_020294c0(a, b);
}

void func_0211c5ac(void) {
    u16 a[2];
    s32 i;
    u16 v;
    SelectRaceRule *p;
    a[0] = 8;
    a[1] = 8;
    for (i = 0; i < 8; i++) {
        func_0211c810(i, 3);
    }
    if (func_0211d62c() != 0) {
        p = gSelectRaceRule;
        if (p->mUnk_78 == 0) {
            func_0211d2f0(&a[0]);
            func_0211c810(a[0], 0);
            if (func_0211d62c() > 1) {
                func_0211d2f0(&a[1]);
                while (a[0] == a[1]) {
                    func_0211d2f0(&a[1]);
                }
                func_0211c810(a[1], 1);
            }
        } else if (p->mUnk_b0[func_0211d3f4(p->mUnk_8c[0])] != 0) {
            func_0211d2f0(&a[0]);
            v = a[0];
            while (gSelectRaceRule->mUnk_8c[v] != func_0211d3f4(gSelectRaceRule->mUnk_8c[0])) {
                func_0211d2f0(&a[0]);
                v = a[0];
            }
            func_0211c810(v, 0);
            if (gSelectRaceRule->mUnk_b0[gSelectRaceRule->mUnk_8c[0]] != 0) {
                func_0211d2f0(&a[1]);
                while (gSelectRaceRule->mUnk_8c[0] != gSelectRaceRule->mUnk_8c[a[1]]) {
                    func_0211d2f0(&a[1]);
                }
                func_0211c810(a[1], 1);
            } else if (gSelectRaceRule->mUnk_b0[func_0211d3f4(gSelectRaceRule->mUnk_8c[0])] > 1) {
                func_0211d2f0(&a[1]);
                while (gSelectRaceRule->mUnk_8c[a[1]] != func_0211d3f4(gSelectRaceRule->mUnk_8c[0]) || a[0] == a[1]) {
                    func_0211d2f0(&a[1]);
                }
                func_0211c810(a[1], 1);
            }
        } else if (gSelectRaceRule->mUnk_b0[gSelectRaceRule->mUnk_8c[0]] != 0) {
            func_0211d2f0(&a[0]);
            while (gSelectRaceRule->mUnk_8c[0] != gSelectRaceRule->mUnk_8c[a[0]]) {
                func_0211d2f0(&a[0]);
            }
            func_0211c810(a[0], 0);
            if (gSelectRaceRule->mUnk_b0[gSelectRaceRule->mUnk_8c[0]] > 1) {
                func_0211d2f0(&a[1]);
                while (gSelectRaceRule->mUnk_8c[0] != gSelectRaceRule->mUnk_8c[a[1]] || a[0] == a[1]) {
                    func_0211d2f0(&a[1]);
                }
                func_0211c810(a[1], 1);
            }
        }
    }
}

void func_0211c474(void) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (func_0211d40c(i) != 0) {
            func_020294d4(i, 0);
            func_0202950c(i, data_0215cca4[gSelectRaceRule->mUnk_8c[i]]);
        } else if (gSelectRaceRule->mUnk_68[1] != 0) {
            func_020294d4(i, 1);
            func_0202950c(i, data_0215cca4[gSelectRaceRule->mUnk_8c[i]]);
        } else {
            func_020294d4(i, 4);
            func_0202950c(i, data_0215cca4[gSelectRaceRule->mUnk_8c[i]]);
        }
    }
    if (gSelectRaceRule->mUnk_68[0] == 3) {
        func_020295c0(data_0215cd18[2]);
        func_020295b0();
    } else {
        func_020295c0(data_0215cd18[gSelectRaceRule->mUnk_68[0]]);
        func_020295a0();
    }
    func_02029570(data_0215cd28[gSelectRaceRule->mUnk_68[1]]);
    func_02029560(data_0215cce4[gSelectRaceRule->mUnk_68[2]]);
    func_02029540(data_0215ccf0[gSelectRaceRule->mUnk_68[3]]);
    switch (gSelectRaceRule->mUnk_68[3]) {
        case 0:
            func_02029550(gSelectRaceRule->mUnk_88);
            break;
        case 1:
            func_02029550(gSelectRaceRule->mUnk_8a);
            break;
    }
    if (gSelectRaceRule->mUnk_78 == 0) {
        func_02029520();
    } else {
        func_02029530();
    }
    func_0211c5ac();
}

void func_0211c14c(void) {
    s32 j;
    u16 v;
    if (data_021759d0->mUnk_20 != 2) {
        if (gSelectRaceRule->mUnk_68[3] != 2) {
            if (gSelectRaceRule->mUnk_60 == 3 && gSelectRaceRule->mUnk_7c == 0) {
                gSelectRaceRule->mUnk_14[30].mUnk_00 = 1;
                gSelectRaceRule->mUnk_14[31].mUnk_00 = 0;
            } else {
                gSelectRaceRule->mUnk_14[30].mUnk_00 = 0;
                gSelectRaceRule->mUnk_14[31].mUnk_00 = 1;
            }
            for (j = 0; j < 2; j++) {
                if (gSelectRaceRule->mUnk_50[0][j] > 0) {
                    gSelectRaceRule->mUnk_50[0][j]--;
                    gSelectRaceRule->mUnk_14[data_0215ccac[0][j]].mUnk_00 = 1;
                } else {
                    gSelectRaceRule->mUnk_14[data_0215ccac[0][j]].mUnk_00 = 0;
                }
            }
        } else {
            gSelectRaceRule->mUnk_14[30].mUnk_00 = 0;
            gSelectRaceRule->mUnk_14[31].mUnk_00 = 0;
            for (j = 0; j < 2; j++) {
                gSelectRaceRule->mUnk_14[data_0215ccac[0][j]].mUnk_00 = 0;
            }
        }
        if (gSelectRaceRule->mUnk_78 == 2) {
            for (j = 0; j < 2; j++) {
                if (gSelectRaceRule->mUnk_60 == 4 && gSelectRaceRule->mUnk_7c == 0) {
                    v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mUnk_0432 : 0;
                    if (func_0211d44c(data_0217aa00->mUnk_1e52[v].mUnk_00) != 0) {
                        gSelectRaceRule->mUnk_14[data_0215cc6c[j]].mUnk_00 = 1;
                        gSelectRaceRule->mUnk_14[data_0215cc70[j]].mUnk_00 = 0;
                    } else {
                        gSelectRaceRule->mUnk_14[data_0215cc6c[j]].mUnk_00 = 0;
                        gSelectRaceRule->mUnk_14[data_0215cc70[j]].mUnk_00 = 1;
                    }
                } else {
                    gSelectRaceRule->mUnk_14[data_0215cc6c[j]].mUnk_00 = 0;
                    gSelectRaceRule->mUnk_14[data_0215cc70[j]].mUnk_00 = 1;
                }
                if (gSelectRaceRule->mUnk_50[1][j] > 0) {
                    gSelectRaceRule->mUnk_50[1][j]--;
                    gSelectRaceRule->mUnk_14[data_0215ccac[1][j]].mUnk_00 = 1;
                } else {
                    gSelectRaceRule->mUnk_14[data_0215ccac[1][j]].mUnk_00 = 0;
                }
            }
        } else {
            for (j = 0; j < 2; j++) {
                gSelectRaceRule->mUnk_14[data_0215cc6c[j]].mUnk_00 = 0;
                gSelectRaceRule->mUnk_14[data_0215cc70[j]].mUnk_00 = 0;
                gSelectRaceRule->mUnk_14[data_0215ccac[1][j]].mUnk_00 = 0;
            }
        }
    } else {
        gSelectRaceRule->mUnk_14[30].mUnk_00 = 0;
        gSelectRaceRule->mUnk_14[31].mUnk_00 = 0;
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mUnk_14[data_0215ccac[0][j]].mUnk_00 = 0;
        }
        if (gSelectRaceRule->mUnk_78 == 2) {
            for (j = 0; j < 2; j++) {
                v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mUnk_0432 : 0;
                if (func_0211d44c(data_0217aa00->mUnk_1e52[v].mUnk_00) != 0) {
                    gSelectRaceRule->mUnk_14[data_0215cc6c[j]].mUnk_00 = 1;
                    gSelectRaceRule->mUnk_14[data_0215cc70[j]].mUnk_00 = 0;
                } else {
                    gSelectRaceRule->mUnk_14[data_0215cc6c[j]].mUnk_00 = 1;
                    gSelectRaceRule->mUnk_14[data_0215cc70[j]].mUnk_00 = 1;
                }
                if (gSelectRaceRule->mUnk_50[1][j] > 0) {
                    gSelectRaceRule->mUnk_50[1][j]--;
                    gSelectRaceRule->mUnk_14[data_0215ccac[1][j]].mUnk_00 = 1;
                } else {
                    gSelectRaceRule->mUnk_14[data_0215ccac[1][j]].mUnk_00 = 0;
                }
            }
        } else {
            for (j = 0; j < 2; j++) {
                gSelectRaceRule->mUnk_14[data_0215cc6c[j]].mUnk_00 = 0;
                gSelectRaceRule->mUnk_14[data_0215cc70[j]].mUnk_00 = 0;
                gSelectRaceRule->mUnk_14[data_0215ccac[1][j]].mUnk_00 = 0;
            }
        }
    }
}

void func_0211c0cc(void) {
    SelectRaceRule *p;
    if (data_021759d0->mUnk_20 == 2) {
        gSelectRaceRule->mUnk_14[gSelectRaceRule->mBncl->mUnk_06 + 14].mUnk_00 = 1;
        p = gSelectRaceRule;
        if (p->mUnk_78 == 2) {
            func_0212426c(1, 0xe, gSelectRaceRule->mBnll, GetBmgEntry(p->mUnk_1c, 0x15), p->mBncl, p->mUnk_14);
        } else {
            func_0212426c(1, 0xe, gSelectRaceRule->mBnll, GetBmgEntry(p->mUnk_1c, 0x14), p->mBncl, p->mUnk_14);
        }
    }
}

void func_0211bf94(void) {
    s32 i;
    s32 a;
    BOOL c;
    BOOL b;
    u32 n;
    Unk02175628 *p;
    u16 y;
    if (gSelectRaceRule->mUnk_78 == 2) {
        for (i = 0; i < 8; i++) {
            n = data_0215cdec[i];
            a = -1;
            c = FALSE;
            b = FALSE;
            p = &data_02175628[n];
            y = p->mHasPair;
            if (y == 0 && p->mNoPairCount < 5) {
                b = TRUE;
            }
            if (b == FALSE && p->mPrevHasPair == 0 && y != 0) {
                c = TRUE;
            }
            if (c != FALSE) {
                a = RectTableFindContaining(gSelectRaceRule->mBnbl, p->mUnk_48, p->mUnk_4a - gSelectRaceRule->mUnk_58);
            }
            if (func_020ae408(n, 0x200) != 0 || a == 0x11) {
                if (i == 0) {
                    if (a == 0x11) {
                        gSelectRaceRule->mUnk_60 = 4;
                        gSelectRaceRule->mUnk_7c = 0;
                    }
                    if (gSelectRaceRule->mUnk_7c == 0 && gSelectRaceRule->mUnk_60 == 4) {
                        func_0211d174(i, 0);
                    }
                } else {
                    func_0211d174(i, 0);
                }
            } else if (func_020ae408(n, 0x100) != 0 || a == 0x12) {
                if (i == 0) {
                    if (a == 0x12) {
                        gSelectRaceRule->mUnk_60 = 4;
                        gSelectRaceRule->mUnk_7c = 0;
                    }
                    if (gSelectRaceRule->mUnk_7c == 0 && gSelectRaceRule->mUnk_60 == 4) {
                        func_0211d174(i, 1);
                    }
                } else {
                    func_0211d174(i, 1);
                }
            }
        }
    }
}

void func_0211bd84(void) {
    s32 a;
    s32 i;
    u32 b;
    a = 3;
    if (func_020cccb4() == 8 || func_020cccb4() == 9 || func_020cccb4() == 0xf) {
        func_02029520();
        func_020295a0();
        func_020295c0(0);
        func_02029570(0);
        func_02029560(0);
        func_02029540(0);
        func_02029550(0);
    }
    if (func_0202962c() != 0) {
        switch (gSelectRaceRule->mMode) {
            case 0:
            case 1:
                a = 1;
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                a = 2;
                break;
        }
        for (i = 0; i < 8; i++) {
            b = data_0215cc9c[func_02029618(i)];
            func_0211d428(i, b);
            if (func_020296ac(i) == 0) {
                gSelectRaceRule->mUnk_ac[b]++;
            } else {
                gSelectRaceRule->mUnk_b0[b]++;
            }
        }
    } else {
        a = 0;
    }
    gSelectRaceRule->mUnk_60 = 4;
    while (a != gSelectRaceRule->mUnk_78) {
        func_0211ccac(0);
    }
    if (func_0202967c() != 0) {
        b = 3;
    } else {
        b = data_0215ccfc[func_0202969c()];
    }
    a = 0;
    gSelectRaceRule->mUnk_60 = 0;
    while (b != gSelectRaceRule->mUnk_68[0]) {
        func_0211ccac(0);
    }
    b = data_0215cd08[func_0202966c()];
    gSelectRaceRule->mUnk_60 = 1;
    while (b != gSelectRaceRule->mUnk_68[1]) {
        func_0211ccac(0);
    }
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            if (b == 0 && gSelectRaceRule->mUnk_68[1] != 2) {
                do {
                    func_0211ccac(0);
                } while (gSelectRaceRule->mUnk_68[1] != 2);
            }
            break;
    }
    b = data_0215cccc[func_0202965c()];
    gSelectRaceRule->mUnk_60 = 2;
    while (b != gSelectRaceRule->mUnk_68[2]) {
        func_0211ccac(0);
    }
    b = data_0215ccd8[func_0202963c()];
    gSelectRaceRule->mUnk_60 = 3;
    while (b != gSelectRaceRule->mUnk_68[3]) {
        func_0211ccac(0);
    }
    switch (gSelectRaceRule->mUnk_68[3]) {
        case 0:
            func_0211d910(func_0202964c());
            break;
        case 1:
            func_0211d844(func_0202964c());
            break;
    }
    gSelectRaceRule->mUnk_60 = 0;
}

void func_0211bd10(void) {
    BOOL a;
    u8 b;
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            gSelectRaceRule->mUnk_ac[0] = 1;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            a = TRUE;
            if (data_0217aa00->mUnk_0004 != 8 && data_0217aa00->mUnk_0004 != 9) {
                a = FALSE;
            }
            b = a != FALSE ? CountSetBits(data_0217aa00->mUnk_15f6) : 0;
            gSelectRaceRule->mUnk_ac[0] = b;
            break;
    }
}

void func_0211baec(void) {
    s32 i;
    s32 j;
    s32 c;
    gSelectRaceRule->mNextState = 0;
    gSelectRaceRule->mStateFrames = 0;
    c = gSelectRaceRule->mUnk_58 - 0xc0;
    gSelectRaceRule->mUnk_5c = c;
    c = gSelectRaceRule->mUnk_58 - 0xc0;
    gSelectRaceRule->mUnk_5c = c;
    c = gSelectRaceRule->mBncl->mUnk_06;
    gSelectRaceRule->mUnk_14[40].mUnk_06 = gSelectRaceRule->mUnk_58 + 0xc0;
    gSelectRaceRule->mUnk_14[41].mUnk_06 = gSelectRaceRule->mUnk_58 + 0xc0;
    gSelectRaceRule->mUnk_14[42].mUnk_06 = gSelectRaceRule->mUnk_58 + 0xc0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mUnk_14[data_0215cd88[i][j]].mUnk_06 = gSelectRaceRule->mUnk_58 - 0xc0;
            gSelectRaceRule->mUnk_14[data_0215cdb0[i][j]].mUnk_06 = gSelectRaceRule->mUnk_58 - 0xc0;
            gSelectRaceRule->mUnk_14[data_0215cdc4[i][j]].mUnk_06 = gSelectRaceRule->mUnk_58 - 0xc0;
        }
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mUnk_14[c + data_0215cd4c[i].mUnk_00[j]].mUnk_06 = gSelectRaceRule->mUnk_58 - 0xc0;
        }
    }
    gSelectRaceRule->mUnk_14[c + 10].mUnk_06 = gSelectRaceRule->mUnk_58 - 0xc0;
    gSelectRaceRule->mUnk_14[c + 12].mUnk_06 = gSelectRaceRule->mUnk_58 - 0xc0;
    gSelectRaceRule->mUnk_14[30].mUnk_06 = gSelectRaceRule->mUnk_58 - 0xc0;
    gSelectRaceRule->mUnk_14[31].mUnk_06 = gSelectRaceRule->mUnk_58 - 0xc0;
    gSelectRaceRule->mUnk_14[34].mUnk_06 = gSelectRaceRule->mUnk_58 - 0xc0;
    gSelectRaceRule->mUnk_14[37].mUnk_06 = gSelectRaceRule->mUnk_58 - 0xc0;
    gSelectRaceRule->mUnk_14[35].mUnk_06 = gSelectRaceRule->mUnk_58 - 0xc0;
    gSelectRaceRule->mUnk_14[38].mUnk_06 = gSelectRaceRule->mUnk_58 - 0xc0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mUnk_14[data_0215ccac[i][j]].mUnk_06 = gSelectRaceRule->mUnk_58 - 0xc0;
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        gSelectRaceRule->mUnk_14[c + 13].mUnk_06 = gSelectRaceRule->mUnk_58 + 0xc0;
        c += 8;
        gSelectRaceRule->mUnk_14[c].mUnk_06 = gSelectRaceRule->mUnk_58 + 0xc0;
    } else {
        c += 14;
        gSelectRaceRule->mUnk_14[c].mUnk_06 = gSelectRaceRule->mUnk_58 + 0xc0;
    }
}

void func_0211bad8(void) {
    gSelectRaceRule->mNextState = 1;
    gSelectRaceRule->mStateFrames = 0;
}

void func_0211baac(void) {
    gSelectRaceRule->mNextState = 2;
    gSelectRaceRule->mStateFrames = 0;
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            func_02128374();
            break;
    }
}

void func_0211ba98(void) {
    gSelectRaceRule->mNextState = 3;
    gSelectRaceRule->mStateFrames = 0;
}

void func_0211ba58(void) {
    gSelectRaceRule->mNextState = 4;
    gSelectRaceRule->mStateFrames = 0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_0212b7e8();
    }
    func_0212ecc0(&data_0217d068, 0, 5);
    func_0211c474();
}

void func_0211ba1c(void) {
    void *a;
    gSelectRaceRule->mNextState = 5;
    gSelectRaceRule->mStateFrames = 0;
    a = GetBmgEntry(gSelectRaceRule->mUnk_18, 4);
    func_021277f8(a, GetBmgEntry(gSelectRaceRule->mUnk_18, 2), 0);
}

void func_0211ba08(void) {
    gSelectRaceRule->mNextState = 6;
    gSelectRaceRule->mStateFrames = 0;
}

void func_0211b9ec(void) {
    gSelectRaceRule->mNextState = 7;
    gSelectRaceRule->mStateFrames = 0;
    func_021277e4();
}

void func_0211b9d8(void) {
    gSelectRaceRule->mNextState = 8;
    gSelectRaceRule->mStateFrames = 0;
}

void InitSelectRaceRule(void *a, s32 b, void *c, s32 d) {
    void *h;
    s32 i;
    s32 j;
    s32 n;
    s32 e;
    SelectRaceRule *p;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x8200;
    h = CreateFrmHeapFromMaxFree(a);
    gSelectRaceRule = HeapAlloc(h, 0xbc);
    gSelectRaceRule->mHeap = h;
    gSelectRaceRule->mMode = d;
    gSelectRaceRule->mState = 0;
    gSelectRaceRule->mUnk_60 = 0;
    gSelectRaceRule->mUnk_64 = 4;
    gSelectRaceRule->mUnk_58 = 0;
    gSelectRaceRule->mUnk_7c = 0;
    gSelectRaceRule->mUnk_80 = 0;
    gSelectRaceRule->mUnk_84 = 1;
    gSelectRaceRule->mUnk_88 = 0;
    gSelectRaceRule->mUnk_8a = 0;
    gSelectRaceRule->mUnk_b4 = c;
    gSelectRaceRule->mUnk_b8 = 0;
    for (i = 0; i < 2; i++) {
        gSelectRaceRule->mUnk_ac[i] = 0;
        gSelectRaceRule->mUnk_b0[i] = 0;
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mUnk_3c[i][j] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mUnk_50[i][j] = 0;
        }
    }
    LocateAndQueueSelectRaceRule();
    func_02124ed0(gSelectRaceRule->mHeap, gSelectRaceRule->mBncl, gSelectRaceRule->mBnll, &gSelectRaceRule->mUnk_14);
    gSelectRaceRule->mUnk_18 = func_02047a28(data_0216de38);
    gSelectRaceRule->mUnk_1c = FindSceneFile(data_0216de44);
    n = gSelectRaceRule->mBncl->mUnk_06;
    e = func_02148ca0();
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            if (!(i == 3 && j == 1)) {
                e -= func_021243ac(gSelectRaceRule->mHeap, data_0215cd4c[i].mUnk_00[j], gSelectRaceRule->mBnll,
                                   data_0215cd60[i][j], data_0215cd74[i].h[j], i * 2 + j, gSelectRaceRule->mNcer,
                                   gSelectRaceRule->mBncl, gSelectRaceRule->mUnk_14, e);
            }
        }
        p = gSelectRaceRule;
        func_0212426c(1, data_0215cd4c[i].mUnk_00[0], gSelectRaceRule->mBnll, GetBmgEntry(p->mUnk_1c, data_0215ccb4[i]),
                      p->mBncl, p->mUnk_14);
        if (i != 3) {
            p = gSelectRaceRule;
            func_0212426c(1, data_0215cd4c[i].mUnk_00[1], gSelectRaceRule->mBnll,
                          GetBmgEntry(p->mUnk_1c, data_0216dc0c[i][p->mUnk_68[i]]), p->mBncl, p->mUnk_14);
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        p = gSelectRaceRule;
        e -= func_021243ac(p->mHeap, 9, p->mBnll, 0x96, 0xf, n + 3, p->mNcer, p->mBncl, p->mUnk_14, e);
        p = gSelectRaceRule;
        e -= func_021243ac(p->mHeap, 0xa, p->mBnll, 0xc8, 0xf, n + 9, p->mNcer, p->mBncl, p->mUnk_14, e);
        p = gSelectRaceRule;
        func_0212426c(1, 0xa, gSelectRaceRule->mBnll, GetBmgEntry(p->mUnk_1c, data_0216dc0c[3][2]), p->mBncl,
                      p->mUnk_14);
    } else {
        p = gSelectRaceRule;
        e -= func_021243ac(p->mHeap, 0xa, p->mBnll, 0xc8, 0xf, n + 3, p->mNcer, p->mBncl, p->mUnk_14, e);
        p = gSelectRaceRule;
        func_0212426c(1, 0xa, gSelectRaceRule->mBnll, GetBmgEntry(p->mUnk_1c, data_0216dc0c[3][2]), p->mBncl,
                      p->mUnk_14);
    }
    p = gSelectRaceRule;
    e -= func_021243ac(p->mHeap, 0xc, p->mBnll, 0x37, 0xf, n + 0xb, p->mNcer, p->mBncl, p->mUnk_14, e);
    p = gSelectRaceRule;
    func_0212426c(1, 0xc, gSelectRaceRule->mBnll, GetBmgEntry(p->mUnk_1c, data_0216dc0c[4][2]), p->mBncl, p->mUnk_14);
    if (data_021759d0->mUnk_20 != 2) {
        p = gSelectRaceRule;
        e -= func_021243ac(p->mHeap, 0xd, p->mBnll, 0x32, 0xd, 0x29, p->mNcer, p->mBncl, p->mUnk_14, e);
        p = gSelectRaceRule;
        func_0212426c(1, 0xd, gSelectRaceRule->mBnll, GetBmgEntry(p->mUnk_18, 4), p->mBncl, p->mUnk_14);
        p = gSelectRaceRule;
        func_021243ac(p->mHeap, 8, p->mBnll, 0x15, 0xf, 0x1f, p->mNcer, p->mBncl, p->mUnk_14, e);
    } else {
        p = gSelectRaceRule;
        func_021243ac(p->mHeap, 0xe, p->mBnll, 0xc8, 0xd, 0x2a, p->mNcer, p->mBncl, p->mUnk_14, e);
    }
    func_0211d910(0);
    func_0211d844(0);
    switch (gSelectRaceRule->mMode) {
        case 2:
        case 4:
            func_021170f8();
            func_02116fb0();
            func_02117060();
            func_02116ef8();
            break;
        case 3:
        case 5:
            func_021170f8();
            func_02116fb0();
            func_02117060();
            func_02116ec0();
            break;
    }
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            func_0202c0d4(0, 2);
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            func_0202c0d4(1, 2);
            break;
    }
    func_0211bd84();
    if (func_0211cdec() == 0) {
        func_0211bd10();
        func_0211d09c();
        func_0211cfd0();
    }
    p = gSelectRaceRule;
    switch (p->mMode) {
        case 0:
            p->mUnk_60 = 1;
            if (gSelectRaceRule->mUnk_68[1] == 0) {
                func_0211ccac(0);
            }
            gSelectRaceRule->mUnk_60 = 0;
            break;
        case 1:
            p->mUnk_58 = -0x1c;
            gSelectRaceRule->mUnk_60 = 1;
            if (gSelectRaceRule->mUnk_68[1] == 0) {
                func_0211ccac(0);
            }
            gSelectRaceRule->mUnk_60 = 3;
            if (gSelectRaceRule->mUnk_68[3] == 1) {
                func_0211cb6c(0);
            }
            gSelectRaceRule->mUnk_60 = 1;
            break;
        case 2:
            p->mUnk_58 = -0x1c;
            gSelectRaceRule->mUnk_60 = 1;
            if (func_0211d650() == 8) {
                gSelectRaceRule->mUnk_60 = 2;
            }
            break;
        case 3:
            p->mUnk_60 = 3;
            if (gSelectRaceRule->mUnk_68[3] == 1) {
                func_0211cb6c(0);
            }
            gSelectRaceRule->mUnk_60 = 1;
            if (func_0211d650() == 8) {
                gSelectRaceRule->mUnk_60 = 3;
            }
            break;
        case 5:
            p->mUnk_58 = -0x1c;
            gSelectRaceRule->mUnk_60 = 3;
            if (gSelectRaceRule->mUnk_68[3] == 1) {
                func_0211cb6c(0);
            }
            gSelectRaceRule->mUnk_60 = 1;
            if (func_0211d650() == 8) {
                gSelectRaceRule->mUnk_60 = 2;
            }
            break;
    }
    switch (gSelectRaceRule->mMode) {
        case 1:
            gSelectRaceRule->mUnk_14[n + data_0215cd4c[0].mUnk_00[0]].mUnk_00 = 0;
            break;
        case 2:
            gSelectRaceRule->mUnk_14[n + data_0215cd4c[0].mUnk_00[0]].mUnk_00 = 0;
            break;
        case 3:
            gSelectRaceRule->mUnk_14[n + data_0215cd4c[0].mUnk_00[0]].mUnk_00 = 0;
            gSelectRaceRule->mUnk_14[n + data_0215cd4c[2].mUnk_00[0]].mUnk_00 = 0;
            gSelectRaceRule->mUnk_14[n + data_0215cd4c[0].mUnk_00[1]].mUnk_00 = 0;
            gSelectRaceRule->mUnk_14[n + data_0215cd4c[2].mUnk_00[1]].mUnk_00 = 0;
            for (j = 0; j < 2; j++) {
                gSelectRaceRule->mUnk_14[data_0215cd88[0][j]].mUnk_00 = 0;
                gSelectRaceRule->mUnk_14[data_0215cd88[2][j]].mUnk_00 = 0;
                gSelectRaceRule->mUnk_14[data_0215cdb0[0][j]].mUnk_00 = 0;
                gSelectRaceRule->mUnk_14[data_0215cdb0[2][j]].mUnk_00 = 0;
                gSelectRaceRule->mUnk_14[data_0215cdc4[0][j]].mUnk_00 = 0;
                gSelectRaceRule->mUnk_14[data_0215cdc4[2][j]].mUnk_00 = 0;
            }
            break;
        case 5:
            gSelectRaceRule->mUnk_14[n + data_0215cd4c[0].mUnk_00[0]].mUnk_00 = 0;
            break;
    }
    if (func_0211d650() == 8 && gSelectRaceRule->mUnk_68[1] != 0) {
        do {
            func_0211cb6c(0);
        } while (gSelectRaceRule->mUnk_68[1] != 0);
    }
    func_0211baec();
    p = gSelectRaceRule;
    func_02116dd4(p->mHeap, p->mNcer, p->mBncl, 0x2a, 0xe, 1);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_0212b928(gSelectRaceRule->mHeap, gSelectRaceRule->mNclr, 9);
    }
    FrmHeapShrinkInParent(gSelectRaceRule->mHeap);
    func_0211d9dc();
}

void ReleaseSelectRaceRule(void) {
    SelectRaceRule *p;
    u32 a;
    u32 b;
    p = gSelectRaceRule;
    if (p->mUnk_b8 == 1 && (p->mMode == 3 || p->mUnk_68[2] == 1)) {
        a = ((reg_GX_DISPCNT) & 0x1f00) >> 8;
        a &= ~3;
        (reg_GX_DISPCNT) = ((reg_GX_DISPCNT) & 0xffffe0ff) | (a << 8);
    }
    b = (reg_G2_BG2CNT);
    b &= ~3;
    (reg_G2_BG2CNT) = b;
    (reg_G2_BG2CNT) = ((reg_G2_BG2CNT) & 0x43) | 0x9e10;
    func_02116dc8();
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_0212b91c();
    }
    HeapDestroy(gSelectRaceRule->mHeap);
    gSelectRaceRule = NULL;
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectRaceRuleState0(void) {
    int v1;
    v1 = func_02036c5c();
    if (v1 != 0) {
        func_0211bad8();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectRaceRuleState1(void) {
    SelectRaceRule *p;
    s32 i;
    s16 b;
    s32 j;
    s32 c;
    func_0211c818();
    func_0211c14c();
    gSelectRaceRule->mStateFrames++;
    p = gSelectRaceRule;
    c = func_020ae4c0(1, -192, 0, p->mStateFrames, 10);
    b = p->mUnk_58 + c;
    p->mUnk_5c = b;
    c = gSelectRaceRule->mBncl->mUnk_06;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mUnk_14[data_0215cd88[i][j]].mUnk_06 = b;
            gSelectRaceRule->mUnk_14[data_0215cdb0[i][j]].mUnk_06 = b;
            gSelectRaceRule->mUnk_14[data_0215cdc4[i][j]].mUnk_06 = b;
        }
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mUnk_14[c + data_0215cd4c[i].mUnk_00[j]].mUnk_06 = b;
        }
    }
    gSelectRaceRule->mUnk_14[c + 10].mUnk_06 = b;
    gSelectRaceRule->mUnk_14[c + 12].mUnk_06 = b;
    gSelectRaceRule->mUnk_14[34].mUnk_06 = b;
    gSelectRaceRule->mUnk_14[37].mUnk_06 = b;
    gSelectRaceRule->mUnk_14[35].mUnk_06 = b;
    gSelectRaceRule->mUnk_14[38].mUnk_06 = b;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mUnk_14[data_0215ccac[i][j]].mUnk_06 = b;
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        c += 8;
        gSelectRaceRule->mUnk_14[c].mUnk_06 = b;
        gSelectRaceRule->mUnk_14[30].mUnk_06 = b;
        gSelectRaceRule->mUnk_14[31].mUnk_06 = b;
    }
    if (gSelectRaceRule->mStateFrames >= 10) {
        func_0211baac();
    }
}

void AdvanceSelectRaceRuleState2(void) {
    s16 a;
    s32 b;
    func_0211c818();
    func_0211c14c();
    gSelectRaceRule->mStateFrames++;
    a = -func_0212825c(gSelectRaceRule->mStateFrames);
    b = gSelectRaceRule->mBncl->mUnk_06;
    if (data_021759d0->mUnk_20 != 2) {
        gSelectRaceRule->mUnk_14[0x28].mUnk_06 = a;
        gSelectRaceRule->mUnk_14[0x29].mUnk_06 = a;
        gSelectRaceRule->mUnk_14[b + 13].mUnk_06 = a;
    } else {
        gSelectRaceRule->mUnk_14[0x2a].mUnk_06 = a;
        gSelectRaceRule->mUnk_14[b + 14].mUnk_06 = a;
    }
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            if (gSelectRaceRule->mStateFrames >= 10 && IsSelectReturnState2NoState3Or4Request() != 0) {
                func_0211ba98();
                return;
            }
            break;
        default:
            if (gSelectRaceRule->mStateFrames >= 10) {
                func_0211ba98();
            }
            break;
    }
}

void AdvanceSelectRaceRuleState3(void) {
    Unk02175628 *p;
    Unk02175628 *q;
    Unk02175628 *r;
    u32 a;
    BOOL c;
    BOOL b;
    Unk02175628Index i;
    u32 d;
    u16 x;
    a = -1;
    i = UNK_02175628_INDEX_8;
    func_0211c818();
    func_0211c14c();
    c = FALSE;
    b = FALSE;
    p = &data_02175674[i];
    x = data_02175674[i].mUnk_00;
    if (x == 0 && data_02175680[i].mUnk_00 < 5) {
        b = TRUE;
    }
    if (b == FALSE && data_0217567c[i].mUnk_00 == 0 && x != 0) {
        c = TRUE;
    }
    if (c != FALSE) {
        r = &data_02175672[i];
        q = &data_02175670[i];
        a = RectTableFindContaining(gSelectRaceRule->mBnbl, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
        if (a != 0x13) {
            a = RectTableFindContaining(gSelectRaceRule->mBnbl, q->mUnk_00, r->mUnk_00 - gSelectRaceRule->mUnk_58);
            if (a == 0x13) {
                a = -1;
            }
        }
    }
    r = &data_02175628[i];
    if ((u16) (r->mUnk_00 & 2) == 0) {
        c = FALSE;
        b = FALSE;
        x = p->mUnk_00;
        if (x == 0 && data_02175680[i].mUnk_00 < 5) {
            b = TRUE;
        }
        if (b == FALSE && data_0217567c[i].mUnk_00 == 0 && x != 0) {
            c = TRUE;
        }
        if (c == FALSE ||
            IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175670[i].mUnk_00, data_02175672[i].mUnk_00) == 0) {
            goto chain;
        }
    }
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            func_021281c8(0xe);
            func_0211b9d8();
            gSelectRaceRule->mUnk_b8 = 2;
            func_02128310(0);
            func_0202b7c0(1);
            break;
    }
    goto end;
chain:
    if (a <= 4) {
        d = data_0215cdd8[a];
        if (func_0211d650() != 8 || d != 1) {
            gSelectRaceRule->mUnk_60 = d;
            gSelectRaceRule->mUnk_7c = 0;
            func_0211cb6c(1);
        }
    } else if (a - 5 <= 4) {
        d = data_0215cd24[a];
        if (func_0211d650() != 8 || d != 1) {
            gSelectRaceRule->mUnk_60 = d;
            gSelectRaceRule->mUnk_7c = 0;
            func_0211ccac(1);
        }
    } else if (a == 0x13) {
        if (gSelectRaceRule->mUnk_7c != 0) {
            gSelectRaceRule->mUnk_84 = 0;
        }
        gSelectRaceRule->mUnk_7c = 1;
        func_0211ba58();
    } else if (a - 10 <= 4) {
        d = data_0215cd74[a].mUnk_00;
        if (func_0211d650() != 8 || d != 1) {
            gSelectRaceRule->mUnk_60 = d;
            gSelectRaceRule->mUnk_7c = 0;
            func_0212ecc0(&data_0217d068, 0, 0);
        }
    } else if ((u16) (r->mUnk_00 & 1) != 0) {
        if (gSelectRaceRule->mUnk_7c != 0) {
            func_0211ba58();
            gSelectRaceRule->mUnk_84 = 0;
        } else {
            func_0211d56c();
        }
    } else if (a == 0xf) {
        if (gSelectRaceRule->mUnk_68[3] != 2) {
            gSelectRaceRule->mUnk_60 = 3;
            gSelectRaceRule->mUnk_7c = 0;
            func_0211ca8c();
        }
    } else if (a == 0x10) {
        if (gSelectRaceRule->mUnk_68[3] != 2) {
            gSelectRaceRule->mUnk_60 = 3;
            gSelectRaceRule->mUnk_7c = 0;
            func_0211cafc();
        }
    } else if (func_020ae408(8, 0x40) != 0) {
        func_0211d4a8();
    } else if (func_020ae408(8, 0x80) != 0) {
        func_0211d56c();
    } else if (func_020ae408(8, 0x20) != 0) {
        if (gSelectRaceRule->mUnk_7c == 0) {
            func_0211cb6c(1);
        }
    } else if (func_020ae408(8, 0x10) != 0) {
        if (gSelectRaceRule->mUnk_7c == 0) {
            func_0211ccac(1);
        }
    } else if (func_020ae408(8, 0x200) != 0) {
        func_0211ca8c();
    } else if (func_020ae408(8, 0x100) != 0) {
        func_0211cafc();
    }
end:
    if (gSelectRaceRule->mNextState != 4) {
        func_0211bf94();
    }
}

void AdvanceSelectRaceRuleState4(void) {
    func_0211c818();
    func_0211c14c();
    gSelectRaceRule->mStateFrames++;
    if (gSelectRaceRule->mStateFrames == 5) {
        gSelectRaceRule->mUnk_84 = 1;
    }
    if (gSelectRaceRule->mStateFrames >= 10) {
        if (gSelectRaceRule->mMode == 3 || gSelectRaceRule->mUnk_68[2] == 1) {
            func_0211ba1c();
            return;
        }
        func_0211b9d8();
        gSelectRaceRule->mUnk_b8 = 1;
        func_0202b7c0(3);
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectRaceRuleState5(void) {
    int v1;
    v1 = func_021277c8();
    if (v1 != 0) {
        func_0211ba08();
    }
}

#pragma thumb off
