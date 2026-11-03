#include "Main/Unknown/code_0202bb80.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_0211ac70.h"

#include "Main/Unknown/code_0211ac88.h"
#include "Main/Unknown/code_0211b23c.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_0212b5ec.h"
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
#include "Main/Unknown/code_0211d650.h"
#include "Main/Unknown/code_021281b4.h"
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
#include "Main/Unknown/code_020ae3b4.h"
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
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_0212b000.h"
#include "Main/Unknown/code_0212b91c.h"
#include "code_02148ca0.h"
#include "registers.h"
#include "Main/Unknown/code_0211d000.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0202cb2c.h"
#include "Main/Unknown/code_0202b604.h"
#include "01/code_021956dc.h"

#pragma thumb on

u16 func_0211d62c(void) {
    int v1;
    v1 = *(s32 *) &data_0217d368;
    if (*(s32 *) (v1 + 0x6c) == 0) {
        return 0;
    }
    return *(u16 *) (v1 + 0xb0) + *(u16 *) (v1 + 0xb2);
}

#pragma thumb off

#pragma thumb on

void func_0211d56c(void) {
    u32 a = 1;
    u16 h = data_0217d368->mUnk_04->mUnk_06;
    Unk027ffc40 *v;

    if (data_0217d368->mUnk_7c != 0) {
        data_0217d368->mUnk_60 = 0;
        data_0217d368->mUnk_7c = 0;
        if (data_0217d368->mUnk_14[h + data_0215cd4c[data_0217d368->mUnk_60].mUnk_00[0]].mUnk_00 == 0 ||
            (func_0211d650() == 8 && data_0217d368->mUnk_60 == 1)) {
            a = 0;
            func_0211d56c();
        }
    } else {
        data_0217d368->mUnk_60++;
        if (data_0217d368->mUnk_60 >= 5) {
            data_0217d368->mUnk_60--;
            data_0217d368->mUnk_7c = a;
            v = (Unk027ffc40 *) 0x027ffc40;
            if (v->mUnk_00 != 2) {
                func_0212b7fc();
            }
        } else if (data_0217d368->mUnk_14[h + data_0215cd4c[data_0217d368->mUnk_60].mUnk_00[0]].mUnk_00 == 0 ||
                   (func_0211d650() == 8 && data_0217d368->mUnk_60 == 1)) {
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
    u16 h = data_0217d368->mUnk_04->mUnk_06;
    Unk027ffc40 *v;

    if (data_0217d368->mUnk_7c != 0) {
        data_0217d368->mUnk_60 = 4;
        data_0217d368->mUnk_7c = 0;
        if (data_0217d368->mUnk_14[h + data_0215cd4c[data_0217d368->mUnk_60].mUnk_00[0]].mUnk_00 == 0 ||
            (func_0211d650() == 8 && data_0217d368->mUnk_60 == 1)) {
            a = 0;
            func_0211d4a8();
        }
    } else {
        data_0217d368->mUnk_60--;
        if (data_0217d368->mUnk_60 < 0) {
            data_0217d368->mUnk_60++;
            data_0217d368->mUnk_7c = a;
            v = (Unk027ffc40 *) 0x027ffc40;
            if (v->mUnk_00 != 2) {
                func_0212b7fc();
            }
        } else if (data_0217d368->mUnk_14[h + data_0215cd4c[data_0217d368->mUnk_60].mUnk_00[0]].mUnk_00 == 0 ||
                   (func_0211d650() == 8 && data_0217d368->mUnk_60 == 1)) {
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
    Unk0217d368 *p;
    p = data_0217d368;
    if (p->mUnk_68[1] == 0) {
        return p->mUnk_ac[a];
    }
    return p->mUnk_ac[a] + p->mUnk_b0[a];
}

u32 func_0211d44c(s32 a) {
    if (func_0211d478(data_0217d368->mUnk_8c[a]) != 1) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void func_0211d428(u16 a, u32 b) {
    data_0217d368->mUnk_8c[a] = b;
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
    if (data_0217d368->mUnk_68[1] != 0) {
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
    switch (data_0217d368->mUnk_2c) {
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
    if (b == data_0217d368->mUnk_8c[a]) {
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
        data_0217d368->mUnk_ac[b]++;
        data_0217d368->mUnk_ac[func_0211d3f4(b)]--;
    } else {
        data_0217d368->mUnk_b0[b]++;
        data_0217d368->mUnk_b0[func_0211d3f4(b)]--;
    }
    b = func_0211d3a8();
    if (b != 2 && data_0217d368->mUnk_b0[b] != 0) {
        func_0211d2f0(&c);
        while (b != data_0217d368->mUnk_8c[c]) {
            func_0211d2f0(&c);
        }
        func_0211d174(c, func_0211d3f4(b));
    }
    v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mUnk_0432 : 0;
    if (a == data_0217aa00->mUnk_1e52[v].mUnk_00) {
        switch (data_0217d368->mUnk_8c[a]) {
            case 0:
                data_0217d368->mUnk_50[1][0] = 6;
                break;
            case 1:
                data_0217d368->mUnk_50[1][1] = 6;
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
    data_0217d368->mUnk_ac[0] = 0;
    data_0217d368->mUnk_ac[1] = 0;
    for (i = 0; i < n; i++) {
        switch (data_0217d368->mUnk_2c) {
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
        if (n / 2 <= data_0217d368->mUnk_ac[a]) {
            a = func_0211d3f4(a);
        }
        func_0211d428(i, a);
        data_0217d368->mUnk_ac[a]++;
    }
}

void func_0211cfd0(void) {
    s32 a;
    s32 i;
    Unk020f41c4_B *p;
    a = 2;
    func_0211d650();
    data_0217d368->mUnk_b0[0] = 0;
    data_0217d368->mUnk_b0[1] = 0;
    for (i = func_0211d650(); i < 8; i++) {
        switch (data_0217d368->mUnk_2c) {
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
        data_0217d368->mUnk_b0[a]++;
    }
}

BOOL func_0211cea8(void) {
    Unk0217d368 *p;
    p = data_0217d368;
    if (p->mUnk_60 == 0 && p->mUnk_68[0] == 3 && func_0205fbb8(0x10) == 0) {
        return FALSE;
    }
    p = data_0217d368;
    switch (p->mUnk_2c) {
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
    switch (data_0217d368->mUnk_2c) {
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
            b = a != FALSE ? func_0202056c(data_0217aa00->mUnk_15f6) : 0;
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
    Unk0217d368 *p;
    s32 i;
    data_0217d368->mUnk_68[data_0217d368->mUnk_60]++;
    if (data_0215ccc0[data_0217d368->mUnk_60] <= data_0217d368->mUnk_68[data_0217d368->mUnk_60]) {
        data_0217d368->mUnk_68[data_0217d368->mUnk_60] = 0;
    }
    if (func_0211cea8() == FALSE) {
        func_0211ccac(0);
    }
    p = data_0217d368;
    if (p->mUnk_60 != 3) {
        func_0212426c(1, data_0215cd4e[p->mUnk_60 * 2], p->mUnk_0c,
                      GetBmgEntry(p->mUnk_1c, data_0216dc0c[p->mUnk_60][p->mUnk_68[p->mUnk_60]]), p->mUnk_04,
                      p->mUnk_14);
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
            data_0217d368->mUnk_50[0][i] = 0;
        }
    }
    if (data_0217d368->mUnk_60 == 4) {
        for (i = 0; i < 2; i++) {
            data_0217d368->mUnk_50[1][i] = 0;
        }
    }
    if (data_0217d368->mUnk_60 == 1) {
        if (data_0217d368->mUnk_68[1] == 0) {
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
    data_0217d368->mUnk_3c[data_0217d368->mUnk_60][1] = 6;
    if (a != 0) {
        func_0212ecc0(&data_0217d068, 0, 1);
    }
}

void func_0211cb6c(s32 a) {
    Unk0217d368 *p;
    s32 i;
    data_0217d368->mUnk_68[data_0217d368->mUnk_60]--;
    if (data_0217d368->mUnk_68[data_0217d368->mUnk_60] < 0) {
        data_0217d368->mUnk_68[data_0217d368->mUnk_60] = data_0215ccc0[data_0217d368->mUnk_60] - 1;
    }
    if (func_0211cea8() == FALSE) {
        func_0211cb6c(0);
    }
    p = data_0217d368;
    if (p->mUnk_60 != 3) {
        func_0212426c(1, data_0215cd4e[p->mUnk_60 * 2], p->mUnk_0c,
                      GetBmgEntry(p->mUnk_1c, data_0216dc0c[p->mUnk_60][p->mUnk_68[p->mUnk_60]]), p->mUnk_04,
                      p->mUnk_14);
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
            data_0217d368->mUnk_50[0][i] = 0;
        }
    }
    if (data_0217d368->mUnk_60 == 4) {
        for (i = 0; i < 2; i++) {
            data_0217d368->mUnk_50[1][i] = 0;
        }
    }
    if (data_0217d368->mUnk_60 == 1) {
        if (data_0217d368->mUnk_68[1] == 0) {
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
    data_0217d368->mUnk_3c[data_0217d368->mUnk_60][0] = 6;
    if (a != 0) {
        func_0212ecc0(&data_0217d068, 0, 1);
    }
}

void func_0211cafc(void) {
    BOOL a;
    Unk0217d368 *p;
    a = FALSE;
    p = data_0217d368;
    if (p->mUnk_60 == 3) {
        switch (p->mUnk_68[3]) {
            case 0:
                func_0211d910(p->mUnk_88 + 1);
                data_0217d368->mUnk_50[0][1] = 6;
                a = TRUE;
                break;
            case 1:
                func_0211d844(p->mUnk_8a + 1);
                data_0217d368->mUnk_50[0][1] = 6;
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
    Unk0217d368 *p;
    a = FALSE;
    p = data_0217d368;
    if (p->mUnk_60 == 3) {
        switch (p->mUnk_68[3]) {
            case 0:
                func_0211d910(p->mUnk_88 - 1);
                data_0217d368->mUnk_50[0][0] = 6;
                a = TRUE;
                break;
            case 1:
                func_0211d844(p->mUnk_8a - 1);
                data_0217d368->mUnk_50[0][0] = 6;
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
                data_0217d368->mUnk_14[data_0215cd88[i][j]].mUnk_00 = 0;
                data_0217d368->mUnk_14[data_0215cdb0[i][j]].mUnk_00 = 0;
                data_0217d368->mUnk_14[data_0215cdc4[i][j]].mUnk_00 = 0;
            }
        }
        return;
    }
    for (i = 0; i < 5; i++) {
        if (func_0211d650() == 8 && i == 1) {
            for (j = 0; j < 2; j++) {
                data_0217d368->mUnk_14[data_0215cd88[i][j]].mUnk_00 = 0;
                data_0217d368->mUnk_14[data_0215cdb0[i][j]].mUnk_00 = 0;
                data_0217d368->mUnk_14[data_0215cdc4[i][j]].mUnk_00 = 0;
            }
        } else {
            data_0217d368->mUnk_14[data_0215cdb0[i][0]].mUnk_04 = -func_020adc64(6 - data_0217d368->mUnk_3c[i][0]);
            data_0217d368->mUnk_14[data_0215cdb0[i][1]].mUnk_04 = func_020adc64(6 - data_0217d368->mUnk_3c[i][1]);
            for (j = 0; j < 2; j++) {
                if (data_0217d368->mUnk_3c[i][j] > 0) {
                    data_0217d368->mUnk_3c[i][j]--;
                    data_0217d368->mUnk_14[data_0215cd88[i][j]].mUnk_00 = 0;
                    data_0217d368->mUnk_14[data_0215cdb0[i][j]].mUnk_00 = 1;
                    data_0217d368->mUnk_14[data_0215cdc4[i][j]].mUnk_00 = 0;
                } else if (data_0217d368->mUnk_60 == i && data_0217d368->mUnk_7c == 0) {
                    data_0217d368->mUnk_14[data_0215cd88[i][j]].mUnk_00 = 1;
                    data_0217d368->mUnk_14[data_0215cdb0[i][j]].mUnk_00 = 0;
                    data_0217d368->mUnk_14[data_0215cdc4[i][j]].mUnk_00 = 0;
                } else {
                    data_0217d368->mUnk_14[data_0215cd88[i][j]].mUnk_00 = 0;
                    data_0217d368->mUnk_14[data_0215cdb0[i][j]].mUnk_00 = 0;
                    data_0217d368->mUnk_14[data_0215cdc4[i][j]].mUnk_00 = 1;
                }
            }
        }
    }
    if (data_0217d368->mUnk_2c == 3) {
        for (j = 0; j < 2; j++) {
            data_0217d368->mUnk_14[data_0215cd88[0][j]].mUnk_00 = 0;
            data_0217d368->mUnk_14[data_0215cd88[2][j]].mUnk_00 = 0;
            data_0217d368->mUnk_14[data_0215cdb0[0][j]].mUnk_00 = 0;
            data_0217d368->mUnk_14[data_0215cdb0[2][j]].mUnk_00 = 0;
            data_0217d368->mUnk_14[data_0215cdc4[0][j]].mUnk_00 = 0;
            data_0217d368->mUnk_14[data_0215cdc4[2][j]].mUnk_00 = 0;
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
    Unk0217d368 *p;
    a[0] = 8;
    a[1] = 8;
    for (i = 0; i < 8; i++) {
        func_0211c810(i, 3);
    }
    if (func_0211d62c() != 0) {
        p = data_0217d368;
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
            while (data_0217d368->mUnk_8c[v] != func_0211d3f4(data_0217d368->mUnk_8c[0])) {
                func_0211d2f0(&a[0]);
                v = a[0];
            }
            func_0211c810(v, 0);
            if (data_0217d368->mUnk_b0[data_0217d368->mUnk_8c[0]] != 0) {
                func_0211d2f0(&a[1]);
                while (data_0217d368->mUnk_8c[0] != data_0217d368->mUnk_8c[a[1]]) {
                    func_0211d2f0(&a[1]);
                }
                func_0211c810(a[1], 1);
            } else if (data_0217d368->mUnk_b0[func_0211d3f4(data_0217d368->mUnk_8c[0])] > 1) {
                func_0211d2f0(&a[1]);
                while (data_0217d368->mUnk_8c[a[1]] != func_0211d3f4(data_0217d368->mUnk_8c[0]) || a[0] == a[1]) {
                    func_0211d2f0(&a[1]);
                }
                func_0211c810(a[1], 1);
            }
        } else if (data_0217d368->mUnk_b0[data_0217d368->mUnk_8c[0]] != 0) {
            func_0211d2f0(&a[0]);
            while (data_0217d368->mUnk_8c[0] != data_0217d368->mUnk_8c[a[0]]) {
                func_0211d2f0(&a[0]);
            }
            func_0211c810(a[0], 0);
            if (data_0217d368->mUnk_b0[data_0217d368->mUnk_8c[0]] > 1) {
                func_0211d2f0(&a[1]);
                while (data_0217d368->mUnk_8c[0] != data_0217d368->mUnk_8c[a[1]] || a[0] == a[1]) {
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
            func_0202950c(i, data_0215cca4[data_0217d368->mUnk_8c[i]]);
        } else if (data_0217d368->mUnk_68[1] != 0) {
            func_020294d4(i, 1);
            func_0202950c(i, data_0215cca4[data_0217d368->mUnk_8c[i]]);
        } else {
            func_020294d4(i, 4);
            func_0202950c(i, data_0215cca4[data_0217d368->mUnk_8c[i]]);
        }
    }
    if (data_0217d368->mUnk_68[0] == 3) {
        func_020295c0(data_0215cd18[2]);
        func_020295b0();
    } else {
        func_020295c0(data_0215cd18[data_0217d368->mUnk_68[0]]);
        func_020295a0();
    }
    func_02029570(data_0215cd28[data_0217d368->mUnk_68[1]]);
    func_02029560(data_0215cce4[data_0217d368->mUnk_68[2]]);
    func_02029540(data_0215ccf0[data_0217d368->mUnk_68[3]]);
    switch (data_0217d368->mUnk_68[3]) {
        case 0:
            func_02029550(data_0217d368->mUnk_88);
            break;
        case 1:
            func_02029550(data_0217d368->mUnk_8a);
            break;
    }
    if (data_0217d368->mUnk_78 == 0) {
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
        if (data_0217d368->mUnk_68[3] != 2) {
            if (data_0217d368->mUnk_60 == 3 && data_0217d368->mUnk_7c == 0) {
                data_0217d368->mUnk_14[30].mUnk_00 = 1;
                data_0217d368->mUnk_14[31].mUnk_00 = 0;
            } else {
                data_0217d368->mUnk_14[30].mUnk_00 = 0;
                data_0217d368->mUnk_14[31].mUnk_00 = 1;
            }
            for (j = 0; j < 2; j++) {
                if (data_0217d368->mUnk_50[0][j] > 0) {
                    data_0217d368->mUnk_50[0][j]--;
                    data_0217d368->mUnk_14[data_0215ccac[0][j]].mUnk_00 = 1;
                } else {
                    data_0217d368->mUnk_14[data_0215ccac[0][j]].mUnk_00 = 0;
                }
            }
        } else {
            data_0217d368->mUnk_14[30].mUnk_00 = 0;
            data_0217d368->mUnk_14[31].mUnk_00 = 0;
            for (j = 0; j < 2; j++) {
                data_0217d368->mUnk_14[data_0215ccac[0][j]].mUnk_00 = 0;
            }
        }
        if (data_0217d368->mUnk_78 == 2) {
            for (j = 0; j < 2; j++) {
                if (data_0217d368->mUnk_60 == 4 && data_0217d368->mUnk_7c == 0) {
                    v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mUnk_0432 : 0;
                    if (func_0211d44c(data_0217aa00->mUnk_1e52[v].mUnk_00) != 0) {
                        data_0217d368->mUnk_14[data_0215cc6c[j]].mUnk_00 = 1;
                        data_0217d368->mUnk_14[data_0215cc70[j]].mUnk_00 = 0;
                    } else {
                        data_0217d368->mUnk_14[data_0215cc6c[j]].mUnk_00 = 0;
                        data_0217d368->mUnk_14[data_0215cc70[j]].mUnk_00 = 1;
                    }
                } else {
                    data_0217d368->mUnk_14[data_0215cc6c[j]].mUnk_00 = 0;
                    data_0217d368->mUnk_14[data_0215cc70[j]].mUnk_00 = 1;
                }
                if (data_0217d368->mUnk_50[1][j] > 0) {
                    data_0217d368->mUnk_50[1][j]--;
                    data_0217d368->mUnk_14[data_0215ccac[1][j]].mUnk_00 = 1;
                } else {
                    data_0217d368->mUnk_14[data_0215ccac[1][j]].mUnk_00 = 0;
                }
            }
        } else {
            for (j = 0; j < 2; j++) {
                data_0217d368->mUnk_14[data_0215cc6c[j]].mUnk_00 = 0;
                data_0217d368->mUnk_14[data_0215cc70[j]].mUnk_00 = 0;
                data_0217d368->mUnk_14[data_0215ccac[1][j]].mUnk_00 = 0;
            }
        }
    } else {
        data_0217d368->mUnk_14[30].mUnk_00 = 0;
        data_0217d368->mUnk_14[31].mUnk_00 = 0;
        for (j = 0; j < 2; j++) {
            data_0217d368->mUnk_14[data_0215ccac[0][j]].mUnk_00 = 0;
        }
        if (data_0217d368->mUnk_78 == 2) {
            for (j = 0; j < 2; j++) {
                v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mUnk_0432 : 0;
                if (func_0211d44c(data_0217aa00->mUnk_1e52[v].mUnk_00) != 0) {
                    data_0217d368->mUnk_14[data_0215cc6c[j]].mUnk_00 = 1;
                    data_0217d368->mUnk_14[data_0215cc70[j]].mUnk_00 = 0;
                } else {
                    data_0217d368->mUnk_14[data_0215cc6c[j]].mUnk_00 = 1;
                    data_0217d368->mUnk_14[data_0215cc70[j]].mUnk_00 = 1;
                }
                if (data_0217d368->mUnk_50[1][j] > 0) {
                    data_0217d368->mUnk_50[1][j]--;
                    data_0217d368->mUnk_14[data_0215ccac[1][j]].mUnk_00 = 1;
                } else {
                    data_0217d368->mUnk_14[data_0215ccac[1][j]].mUnk_00 = 0;
                }
            }
        } else {
            for (j = 0; j < 2; j++) {
                data_0217d368->mUnk_14[data_0215cc6c[j]].mUnk_00 = 0;
                data_0217d368->mUnk_14[data_0215cc70[j]].mUnk_00 = 0;
                data_0217d368->mUnk_14[data_0215ccac[1][j]].mUnk_00 = 0;
            }
        }
    }
}

void func_0211c0cc(void) {
    Unk0217d368 *p;
    if (data_021759d0->mUnk_20 == 2) {
        data_0217d368->mUnk_14[data_0217d368->mUnk_04->mUnk_06 + 14].mUnk_00 = 1;
        p = data_0217d368;
        if (p->mUnk_78 == 2) {
            func_0212426c(1, 0xe, data_0217d368->mUnk_0c, GetBmgEntry(p->mUnk_1c, 0x15), p->mUnk_04, p->mUnk_14);
        } else {
            func_0212426c(1, 0xe, data_0217d368->mUnk_0c, GetBmgEntry(p->mUnk_1c, 0x14), p->mUnk_04, p->mUnk_14);
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
    if (data_0217d368->mUnk_78 == 2) {
        for (i = 0; i < 8; i++) {
            n = data_0215cdec[i];
            a = -1;
            c = FALSE;
            b = FALSE;
            p = &data_02175628[n];
            y = p->mUnk_4c;
            if (y == 0 && p->mUnk_58 < 5) {
                b = TRUE;
            }
            if (b == FALSE && p->mUnk_54 == 0 && y != 0) {
                c = TRUE;
            }
            if (c != FALSE) {
                a = func_0201ea84(data_0217d368->mUnk_08, p->mUnk_48, p->mUnk_4a - data_0217d368->mUnk_58);
            }
            if (func_020ae408(n, 0x200) != 0 || a == 0x11) {
                if (i == 0) {
                    if (a == 0x11) {
                        data_0217d368->mUnk_60 = 4;
                        data_0217d368->mUnk_7c = 0;
                    }
                    if (data_0217d368->mUnk_7c == 0 && data_0217d368->mUnk_60 == 4) {
                        func_0211d174(i, 0);
                    }
                } else {
                    func_0211d174(i, 0);
                }
            } else if (func_020ae408(n, 0x100) != 0 || a == 0x12) {
                if (i == 0) {
                    if (a == 0x12) {
                        data_0217d368->mUnk_60 = 4;
                        data_0217d368->mUnk_7c = 0;
                    }
                    if (data_0217d368->mUnk_7c == 0 && data_0217d368->mUnk_60 == 4) {
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
        switch (data_0217d368->mUnk_2c) {
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
                data_0217d368->mUnk_ac[b]++;
            } else {
                data_0217d368->mUnk_b0[b]++;
            }
        }
    } else {
        a = 0;
    }
    data_0217d368->mUnk_60 = 4;
    while (a != data_0217d368->mUnk_78) {
        func_0211ccac(0);
    }
    if (func_0202967c() != 0) {
        b = 3;
    } else {
        b = data_0215ccfc[func_0202969c()];
    }
    a = 0;
    data_0217d368->mUnk_60 = 0;
    while (b != data_0217d368->mUnk_68[0]) {
        func_0211ccac(0);
    }
    b = data_0215cd08[func_0202966c()];
    data_0217d368->mUnk_60 = 1;
    while (b != data_0217d368->mUnk_68[1]) {
        func_0211ccac(0);
    }
    switch (data_0217d368->mUnk_2c) {
        case 0:
        case 1:
            if (b == 0 && data_0217d368->mUnk_68[1] != 2) {
                do {
                    func_0211ccac(0);
                } while (data_0217d368->mUnk_68[1] != 2);
            }
            break;
    }
    b = data_0215cccc[func_0202965c()];
    data_0217d368->mUnk_60 = 2;
    while (b != data_0217d368->mUnk_68[2]) {
        func_0211ccac(0);
    }
    b = data_0215ccd8[func_0202963c()];
    data_0217d368->mUnk_60 = 3;
    while (b != data_0217d368->mUnk_68[3]) {
        func_0211ccac(0);
    }
    switch (data_0217d368->mUnk_68[3]) {
        case 0:
            func_0211d910(func_0202964c());
            break;
        case 1:
            func_0211d844(func_0202964c());
            break;
    }
    data_0217d368->mUnk_60 = 0;
}

void func_0211bd10(void) {
    BOOL a;
    u8 b;
    switch (data_0217d368->mUnk_2c) {
        case 0:
        case 1:
            data_0217d368->mUnk_ac[0] = 1;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            a = TRUE;
            if (data_0217aa00->mUnk_0004 != 8 && data_0217aa00->mUnk_0004 != 9) {
                a = FALSE;
            }
            b = a != FALSE ? func_0202056c(data_0217aa00->mUnk_15f6) : 0;
            data_0217d368->mUnk_ac[0] = b;
            break;
    }
}

void func_0211baec(void) {
    s32 i;
    s32 j;
    s32 c;
    data_0217d368->mUnk_34 = 0;
    data_0217d368->mUnk_38 = 0;
    c = data_0217d368->mUnk_58 - 0xc0;
    data_0217d368->mUnk_5c = c;
    c = data_0217d368->mUnk_58 - 0xc0;
    data_0217d368->mUnk_5c = c;
    c = data_0217d368->mUnk_04->mUnk_06;
    data_0217d368->mUnk_14[40].mUnk_06 = data_0217d368->mUnk_58 + 0xc0;
    data_0217d368->mUnk_14[41].mUnk_06 = data_0217d368->mUnk_58 + 0xc0;
    data_0217d368->mUnk_14[42].mUnk_06 = data_0217d368->mUnk_58 + 0xc0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            data_0217d368->mUnk_14[data_0215cd88[i][j]].mUnk_06 = data_0217d368->mUnk_58 - 0xc0;
            data_0217d368->mUnk_14[data_0215cdb0[i][j]].mUnk_06 = data_0217d368->mUnk_58 - 0xc0;
            data_0217d368->mUnk_14[data_0215cdc4[i][j]].mUnk_06 = data_0217d368->mUnk_58 - 0xc0;
        }
        for (j = 0; j < 2; j++) {
            data_0217d368->mUnk_14[c + data_0215cd4c[i].mUnk_00[j]].mUnk_06 = data_0217d368->mUnk_58 - 0xc0;
        }
    }
    data_0217d368->mUnk_14[c + 10].mUnk_06 = data_0217d368->mUnk_58 - 0xc0;
    data_0217d368->mUnk_14[c + 12].mUnk_06 = data_0217d368->mUnk_58 - 0xc0;
    data_0217d368->mUnk_14[30].mUnk_06 = data_0217d368->mUnk_58 - 0xc0;
    data_0217d368->mUnk_14[31].mUnk_06 = data_0217d368->mUnk_58 - 0xc0;
    data_0217d368->mUnk_14[34].mUnk_06 = data_0217d368->mUnk_58 - 0xc0;
    data_0217d368->mUnk_14[37].mUnk_06 = data_0217d368->mUnk_58 - 0xc0;
    data_0217d368->mUnk_14[35].mUnk_06 = data_0217d368->mUnk_58 - 0xc0;
    data_0217d368->mUnk_14[38].mUnk_06 = data_0217d368->mUnk_58 - 0xc0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            data_0217d368->mUnk_14[data_0215ccac[i][j]].mUnk_06 = data_0217d368->mUnk_58 - 0xc0;
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        data_0217d368->mUnk_14[c + 13].mUnk_06 = data_0217d368->mUnk_58 + 0xc0;
        c += 8;
        data_0217d368->mUnk_14[c].mUnk_06 = data_0217d368->mUnk_58 + 0xc0;
    } else {
        c += 14;
        data_0217d368->mUnk_14[c].mUnk_06 = data_0217d368->mUnk_58 + 0xc0;
    }
}

void func_0211bad8(void) {
    data_0217d368->mUnk_34 = 1;
    data_0217d368->mUnk_38 = 0;
}

void func_0211baac(void) {
    data_0217d368->mUnk_34 = 2;
    data_0217d368->mUnk_38 = 0;
    switch (data_0217d368->mUnk_2c) {
        case 0:
        case 1:
            func_02128374();
            break;
    }
}

void func_0211ba98(void) {
    data_0217d368->mUnk_34 = 3;
    data_0217d368->mUnk_38 = 0;
}

void func_0211ba58(void) {
    data_0217d368->mUnk_34 = 4;
    data_0217d368->mUnk_38 = 0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_0212b7e8();
    }
    func_0212ecc0(&data_0217d068, 0, 5);
    func_0211c474();
}

void func_0211ba1c(void) {
    void *a;
    data_0217d368->mUnk_34 = 5;
    data_0217d368->mUnk_38 = 0;
    a = GetBmgEntry(data_0217d368->mUnk_18, 4);
    func_021277f8(a, GetBmgEntry(data_0217d368->mUnk_18, 2), 0);
}

void func_0211ba08(void) {
    data_0217d368->mUnk_34 = 6;
    data_0217d368->mUnk_38 = 0;
}

void func_0211b9ec(void) {
    data_0217d368->mUnk_34 = 7;
    data_0217d368->mUnk_38 = 0;
    func_021277e4();
}

void func_0211b9d8(void) {
    data_0217d368->mUnk_34 = 8;
    data_0217d368->mUnk_38 = 0;
}

void func_0211b2cc(void *a, s32 b, void *c, s32 d) {
    void *h;
    s32 i;
    s32 j;
    s32 n;
    s32 e;
    Unk0217d368 *p;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x8200;
    h = func_02036948(a);
    data_0217d368 = func_02036bec(h, 0xbc);
    data_0217d368->mUnk_28 = h;
    data_0217d368->mUnk_2c = d;
    data_0217d368->mUnk_30 = 0;
    data_0217d368->mUnk_60 = 0;
    data_0217d368->mUnk_64 = 4;
    data_0217d368->mUnk_58 = 0;
    data_0217d368->mUnk_7c = 0;
    data_0217d368->mUnk_80 = 0;
    data_0217d368->mUnk_84 = 1;
    data_0217d368->mUnk_88 = 0;
    data_0217d368->mUnk_8a = 0;
    data_0217d368->mUnk_b4 = c;
    data_0217d368->mUnk_b8 = 0;
    for (i = 0; i < 2; i++) {
        data_0217d368->mUnk_ac[i] = 0;
        data_0217d368->mUnk_b0[i] = 0;
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            data_0217d368->mUnk_3c[i][j] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            data_0217d368->mUnk_50[i][j] = 0;
        }
    }
    func_0211db90();
    func_02124ed0(data_0217d368->mUnk_28, data_0217d368->mUnk_04, data_0217d368->mUnk_0c, &data_0217d368->mUnk_14);
    data_0217d368->mUnk_18 = func_02047a28(data_0216de38);
    data_0217d368->mUnk_1c = FindSceneFile(data_0216de44);
    n = data_0217d368->mUnk_04->mUnk_06;
    e = func_02148ca0();
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            if (!(i == 3 && j == 1)) {
                e -= func_021243ac(data_0217d368->mUnk_28, data_0215cd4c[i].mUnk_00[j], data_0217d368->mUnk_0c,
                                   data_0215cd60[i][j], data_0215cd74[i].h[j], i * 2 + j, data_0217d368->mUnk_00,
                                   data_0217d368->mUnk_04, data_0217d368->mUnk_14, e);
            }
        }
        p = data_0217d368;
        func_0212426c(1, data_0215cd4c[i].mUnk_00[0], data_0217d368->mUnk_0c, GetBmgEntry(p->mUnk_1c, data_0215ccb4[i]),
                      p->mUnk_04, p->mUnk_14);
        if (i != 3) {
            p = data_0217d368;
            func_0212426c(1, data_0215cd4c[i].mUnk_00[1], data_0217d368->mUnk_0c,
                          GetBmgEntry(p->mUnk_1c, data_0216dc0c[i][p->mUnk_68[i]]), p->mUnk_04, p->mUnk_14);
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        p = data_0217d368;
        e -= func_021243ac(p->mUnk_28, 9, p->mUnk_0c, 0x96, 0xf, n + 3, p->mUnk_00, p->mUnk_04, p->mUnk_14, e);
        p = data_0217d368;
        e -= func_021243ac(p->mUnk_28, 0xa, p->mUnk_0c, 0xc8, 0xf, n + 9, p->mUnk_00, p->mUnk_04, p->mUnk_14, e);
        p = data_0217d368;
        func_0212426c(1, 0xa, data_0217d368->mUnk_0c, GetBmgEntry(p->mUnk_1c, data_0216dc0c[3][2]), p->mUnk_04,
                      p->mUnk_14);
    } else {
        p = data_0217d368;
        e -= func_021243ac(p->mUnk_28, 0xa, p->mUnk_0c, 0xc8, 0xf, n + 3, p->mUnk_00, p->mUnk_04, p->mUnk_14, e);
        p = data_0217d368;
        func_0212426c(1, 0xa, data_0217d368->mUnk_0c, GetBmgEntry(p->mUnk_1c, data_0216dc0c[3][2]), p->mUnk_04,
                      p->mUnk_14);
    }
    p = data_0217d368;
    e -= func_021243ac(p->mUnk_28, 0xc, p->mUnk_0c, 0x37, 0xf, n + 0xb, p->mUnk_00, p->mUnk_04, p->mUnk_14, e);
    p = data_0217d368;
    func_0212426c(1, 0xc, data_0217d368->mUnk_0c, GetBmgEntry(p->mUnk_1c, data_0216dc0c[4][2]), p->mUnk_04, p->mUnk_14);
    if (data_021759d0->mUnk_20 != 2) {
        p = data_0217d368;
        e -= func_021243ac(p->mUnk_28, 0xd, p->mUnk_0c, 0x32, 0xd, 0x29, p->mUnk_00, p->mUnk_04, p->mUnk_14, e);
        p = data_0217d368;
        func_0212426c(1, 0xd, data_0217d368->mUnk_0c, GetBmgEntry(p->mUnk_18, 4), p->mUnk_04, p->mUnk_14);
        p = data_0217d368;
        func_021243ac(p->mUnk_28, 8, p->mUnk_0c, 0x15, 0xf, 0x1f, p->mUnk_00, p->mUnk_04, p->mUnk_14, e);
    } else {
        p = data_0217d368;
        func_021243ac(p->mUnk_28, 0xe, p->mUnk_0c, 0xc8, 0xd, 0x2a, p->mUnk_00, p->mUnk_04, p->mUnk_14, e);
    }
    func_0211d910(0);
    func_0211d844(0);
    switch (data_0217d368->mUnk_2c) {
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
    switch (data_0217d368->mUnk_2c) {
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
    p = data_0217d368;
    switch (p->mUnk_2c) {
        case 0:
            p->mUnk_60 = 1;
            if (data_0217d368->mUnk_68[1] == 0) {
                func_0211ccac(0);
            }
            data_0217d368->mUnk_60 = 0;
            break;
        case 1:
            p->mUnk_58 = -0x1c;
            data_0217d368->mUnk_60 = 1;
            if (data_0217d368->mUnk_68[1] == 0) {
                func_0211ccac(0);
            }
            data_0217d368->mUnk_60 = 3;
            if (data_0217d368->mUnk_68[3] == 1) {
                func_0211cb6c(0);
            }
            data_0217d368->mUnk_60 = 1;
            break;
        case 2:
            p->mUnk_58 = -0x1c;
            data_0217d368->mUnk_60 = 1;
            if (func_0211d650() == 8) {
                data_0217d368->mUnk_60 = 2;
            }
            break;
        case 3:
            p->mUnk_60 = 3;
            if (data_0217d368->mUnk_68[3] == 1) {
                func_0211cb6c(0);
            }
            data_0217d368->mUnk_60 = 1;
            if (func_0211d650() == 8) {
                data_0217d368->mUnk_60 = 3;
            }
            break;
        case 5:
            p->mUnk_58 = -0x1c;
            data_0217d368->mUnk_60 = 3;
            if (data_0217d368->mUnk_68[3] == 1) {
                func_0211cb6c(0);
            }
            data_0217d368->mUnk_60 = 1;
            if (func_0211d650() == 8) {
                data_0217d368->mUnk_60 = 2;
            }
            break;
    }
    switch (data_0217d368->mUnk_2c) {
        case 1:
            data_0217d368->mUnk_14[n + data_0215cd4c[0].mUnk_00[0]].mUnk_00 = 0;
            break;
        case 2:
            data_0217d368->mUnk_14[n + data_0215cd4c[0].mUnk_00[0]].mUnk_00 = 0;
            break;
        case 3:
            data_0217d368->mUnk_14[n + data_0215cd4c[0].mUnk_00[0]].mUnk_00 = 0;
            data_0217d368->mUnk_14[n + data_0215cd4c[2].mUnk_00[0]].mUnk_00 = 0;
            data_0217d368->mUnk_14[n + data_0215cd4c[0].mUnk_00[1]].mUnk_00 = 0;
            data_0217d368->mUnk_14[n + data_0215cd4c[2].mUnk_00[1]].mUnk_00 = 0;
            for (j = 0; j < 2; j++) {
                data_0217d368->mUnk_14[data_0215cd88[0][j]].mUnk_00 = 0;
                data_0217d368->mUnk_14[data_0215cd88[2][j]].mUnk_00 = 0;
                data_0217d368->mUnk_14[data_0215cdb0[0][j]].mUnk_00 = 0;
                data_0217d368->mUnk_14[data_0215cdb0[2][j]].mUnk_00 = 0;
                data_0217d368->mUnk_14[data_0215cdc4[0][j]].mUnk_00 = 0;
                data_0217d368->mUnk_14[data_0215cdc4[2][j]].mUnk_00 = 0;
            }
            break;
        case 5:
            data_0217d368->mUnk_14[n + data_0215cd4c[0].mUnk_00[0]].mUnk_00 = 0;
            break;
    }
    if (func_0211d650() == 8 && data_0217d368->mUnk_68[1] != 0) {
        do {
            func_0211cb6c(0);
        } while (data_0217d368->mUnk_68[1] != 0);
    }
    func_0211baec();
    p = data_0217d368;
    func_02116dd4(p->mUnk_28, p->mUnk_00, p->mUnk_04, 0x2a, 0xe, 1);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_0212b928(data_0217d368->mUnk_28, data_0217d368->mUnk_10, 9);
    }
    func_02036820(data_0217d368->mUnk_28);
    func_0211d9dc();
}

void func_0211b23c(void) {
    Unk0217d368 *p;
    u32 a;
    u32 b;
    p = data_0217d368;
    if (p->mUnk_b8 == 1 && (p->mUnk_2c == 3 || p->mUnk_68[2] == 1)) {
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
    func_02036ab0(data_0217d368->mUnk_28);
    data_0217d368 = NULL;
}

#pragma thumb off

#pragma thumb on

void func_0211b224(void) {
    int v1;
    v1 = func_02036c5c();
    if (v1 != 0) {
        func_0211bad8();
    }
}

#pragma thumb off

#pragma thumb on

void func_0211b07c(void) {
    Unk0217d368 *p;
    s32 i;
    s16 b;
    s32 j;
    s32 c;
    func_0211c818();
    func_0211c14c();
    data_0217d368->mUnk_38++;
    p = data_0217d368;
    c = func_020ae4c0(1, -192, 0, p->mUnk_38, 10);
    b = p->mUnk_58 + c;
    p->mUnk_5c = b;
    c = data_0217d368->mUnk_04->mUnk_06;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            data_0217d368->mUnk_14[data_0215cd88[i][j]].mUnk_06 = b;
            data_0217d368->mUnk_14[data_0215cdb0[i][j]].mUnk_06 = b;
            data_0217d368->mUnk_14[data_0215cdc4[i][j]].mUnk_06 = b;
        }
        for (j = 0; j < 2; j++) {
            data_0217d368->mUnk_14[c + data_0215cd4c[i].mUnk_00[j]].mUnk_06 = b;
        }
    }
    data_0217d368->mUnk_14[c + 10].mUnk_06 = b;
    data_0217d368->mUnk_14[c + 12].mUnk_06 = b;
    data_0217d368->mUnk_14[34].mUnk_06 = b;
    data_0217d368->mUnk_14[37].mUnk_06 = b;
    data_0217d368->mUnk_14[35].mUnk_06 = b;
    data_0217d368->mUnk_14[38].mUnk_06 = b;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            data_0217d368->mUnk_14[data_0215ccac[i][j]].mUnk_06 = b;
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        c += 8;
        data_0217d368->mUnk_14[c].mUnk_06 = b;
        data_0217d368->mUnk_14[30].mUnk_06 = b;
        data_0217d368->mUnk_14[31].mUnk_06 = b;
    }
    if (data_0217d368->mUnk_38 >= 10) {
        func_0211baac();
    }
}

void func_0211afd0(void) {
    s16 a;
    s32 b;
    func_0211c818();
    func_0211c14c();
    data_0217d368->mUnk_38++;
    a = -func_0212825c(data_0217d368->mUnk_38);
    b = data_0217d368->mUnk_04->mUnk_06;
    if (data_021759d0->mUnk_20 != 2) {
        data_0217d368->mUnk_14[0x28].mUnk_06 = a;
        data_0217d368->mUnk_14[0x29].mUnk_06 = a;
        data_0217d368->mUnk_14[b + 13].mUnk_06 = a;
    } else {
        data_0217d368->mUnk_14[0x2a].mUnk_06 = a;
        data_0217d368->mUnk_14[b + 14].mUnk_06 = a;
    }
    switch (data_0217d368->mUnk_2c) {
        case 0:
        case 1:
            if (data_0217d368->mUnk_38 >= 10 && IsSelectReturnState2NoState3Or4Request() != 0) {
                func_0211ba98();
                return;
            }
            break;
        default:
            if (data_0217d368->mUnk_38 >= 10) {
                func_0211ba98();
            }
            break;
    }
}

void func_0211acec(void) {
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
        a = func_0201ea84(data_0217d368->mUnk_08, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
        if (a != 0x13) {
            a = func_0201ea84(data_0217d368->mUnk_08, q->mUnk_00, r->mUnk_00 - data_0217d368->mUnk_58);
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
    switch (data_0217d368->mUnk_2c) {
        case 0:
        case 1:
            func_021281c8(0xe);
            func_0211b9d8();
            data_0217d368->mUnk_b8 = 2;
            func_02128310(0);
            func_0202b7c0(1);
            break;
    }
    goto end;
chain:
    if (a <= 4) {
        d = data_0215cdd8[a];
        if (func_0211d650() != 8 || d != 1) {
            data_0217d368->mUnk_60 = d;
            data_0217d368->mUnk_7c = 0;
            func_0211cb6c(1);
        }
    } else if (a - 5 <= 4) {
        d = data_0215cd24[a];
        if (func_0211d650() != 8 || d != 1) {
            data_0217d368->mUnk_60 = d;
            data_0217d368->mUnk_7c = 0;
            func_0211ccac(1);
        }
    } else if (a == 0x13) {
        if (data_0217d368->mUnk_7c != 0) {
            data_0217d368->mUnk_84 = 0;
        }
        data_0217d368->mUnk_7c = 1;
        func_0211ba58();
    } else if (a - 10 <= 4) {
        d = data_0215cd74[a].mUnk_00;
        if (func_0211d650() != 8 || d != 1) {
            data_0217d368->mUnk_60 = d;
            data_0217d368->mUnk_7c = 0;
            func_0212ecc0(&data_0217d068, 0, 0);
        }
    } else if ((u16) (r->mUnk_00 & 1) != 0) {
        if (data_0217d368->mUnk_7c != 0) {
            func_0211ba58();
            data_0217d368->mUnk_84 = 0;
        } else {
            func_0211d56c();
        }
    } else if (a == 0xf) {
        if (data_0217d368->mUnk_68[3] != 2) {
            data_0217d368->mUnk_60 = 3;
            data_0217d368->mUnk_7c = 0;
            func_0211ca8c();
        }
    } else if (a == 0x10) {
        if (data_0217d368->mUnk_68[3] != 2) {
            data_0217d368->mUnk_60 = 3;
            data_0217d368->mUnk_7c = 0;
            func_0211cafc();
        }
    } else if (func_020ae408(8, 0x40) != 0) {
        func_0211d4a8();
    } else if (func_020ae408(8, 0x80) != 0) {
        func_0211d56c();
    } else if (func_020ae408(8, 0x20) != 0) {
        if (data_0217d368->mUnk_7c == 0) {
            func_0211cb6c(1);
        }
    } else if (func_020ae408(8, 0x10) != 0) {
        if (data_0217d368->mUnk_7c == 0) {
            func_0211ccac(1);
        }
    } else if (func_020ae408(8, 0x200) != 0) {
        func_0211ca8c();
    } else if (func_020ae408(8, 0x100) != 0) {
        func_0211cafc();
    }
end:
    if (data_0217d368->mUnk_34 != 4) {
        func_0211bf94();
    }
}

void func_0211ac88(void) {
    func_0211c818();
    func_0211c14c();
    data_0217d368->mUnk_38++;
    if (data_0217d368->mUnk_38 == 5) {
        data_0217d368->mUnk_84 = 1;
    }
    if (data_0217d368->mUnk_38 >= 10) {
        if (data_0217d368->mUnk_2c == 3 || data_0217d368->mUnk_68[2] == 1) {
            func_0211ba1c();
            return;
        }
        func_0211b9d8();
        data_0217d368->mUnk_b8 = 1;
        func_0202b7c0(3);
    }
}

#pragma thumb off

#pragma thumb on

void func_0211ac70(void) {
    int v1;
    v1 = func_021277c8();
    if (v1 != 0) {
        func_0211ba08();
    }
}

#pragma thumb off
