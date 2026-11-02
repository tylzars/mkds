#include "Main/Unknown/code_020abae0.h"
#include "Main/Unknown/code_020a9cd4.h"
#include "Main/Unknown/code_020a9ff4.h"
#include "Main/Unknown/code_020aa81c.h"
#include "Main/Unknown/code_020aa810.h"
#include "Main/Unknown/code_020ab000.h"
#include "Main/Unknown/code_020ab058.h"
#include "Main/Unknown/code_020ab604.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_021059e0.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"

#pragma thumb on

void func_020ac284(u8 *v1, u8 *v2, s32 n) {
    s32 i;
    s32 v3;

    v3 = n * n / 2;
    for (i = 0; i < v3; i++) {
        v2[i * 2] = v1[i] & 0xf;
        v2[i * 2 + 1] = (v1[i] >> 4) & 0xf;
    }
}

s32 func_020ac238(void) {
    s32 r;
    Unk0217b334 *d;
    s32 i;
    s32 j;

    r = 0;
    d = data_0217b334;
    i = d->mUnk_46;
    j = d->mUnk_4a - 1;
    if (i == j && d->mUnk_40[i] >= 0x20) {
        r = i;
    } else {
        j = i - 1;
        if (j >= 0 && d->mUnk_40[j] >= 0x20) {
            r = j;
        }
    }
    return r;
}

s32 func_020ac0b4(u32 a, s32 b) {
    s32 r;
    s32 i;
    u16 v;
    u16 w;

    r = 0;
    i = func_020ac238();
    switch ((s32) a) {
        case 6:
            if (func_020a9e80() != 6) {
                func_0212ecc0(&data_0217d068, r, 0x1e7);
            } else {
                func_0212ecc0(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 7:
            if (func_020a9e80() != 7) {
                func_0212ecc0(&data_0217d068, r, 0x1e8);
            } else {
                func_0212ecc0(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 0x10:
            v = func_020aa790(data_0217b334->mUnk_40[i]);
            w = data_0217b334->mUnk_40[i];
            if (w == v) {
                func_0212ecc0(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 0x11:
            v = func_020aa738(data_0217b334->mUnk_40[i]);
            w = data_0217b334->mUnk_40[i];
            if (w == v) {
                func_0212ecc0(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 0x12:
            v = func_020aa6e0(data_0217b334->mUnk_40[i]);
            w = data_0217b334->mUnk_40[i];
            if (w == v) {
                func_0212ecc0(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 4:
        case 5:
            func_0212ecc0(&data_0217d068, r, 0x1eb);
            break;
        case 0x20:
        case 0x3000:
            if (b != 0) {
                func_0212ecc0(&data_0217d068, 0, 0x1ea);
            }
            break;
        case 8:
            if (b != 0) {
                func_0212ecc0(&data_0217d068, r, 0x1e9);
            }
            break;
        default:
            if (b != 0 && a >= 0x20) {
                func_0212ecc0(&data_0217d068, 0, 0x1e6);
            }
            break;
    }
    return r;
}

u16 func_020abff4(s32 a, u16 b) {
    u16 r;

    r = 0;
    switch (a) {
        case 1:
            if ((b & 0x20) != 0 || (b & 0x10) != 0) {
                r = 2;
            } else if ((b & 0x40) != 0) {
                r = data_02156808[data_0217b334->mUnk_4c].mUnk_00;
            } else if ((b & 0x80) != 0) {
                r = data_02156808[data_0217b334->mUnk_4c].mUnk_02;
            }
            break;
        case 2:
            if ((b & 0x20) != 0 || (b & 0x10) != 0) {
                r = 1;
            } else if ((b & 0x40) != 0) {
                r = data_02156808[data_0217b334->mUnk_4c].mUnk_04;
            } else if ((b & 0x80) != 0) {
                r = data_02156808[data_0217b334->mUnk_4c].mUnk_06;
            }
            break;
    }
    func_02105ac0(0x1e4);
    return r;
}

void func_020abcf4(s32 a, s32 b, s32 c) {
    Unk0217b334 *p;

    data_0217b334 = func_02036bec(func_020364e0(func_020364e8()), 0x78);
    data_0217b334->mUnk_44 = c;
    data_0217b334->mUnk_4a = c;
    data_0217b334->mUnk_46 = 0;
    data_0217b334->mUnk_48 = 0;
    data_0217b334->mUnk_40 = func_02036bec(func_020364e0(func_020364e8()), (c + 1) * 2);
    data_0217b334->mUnk_0c = b * (a * 2);
    data_0217b334->mUnk_04 = func_02036bec(func_020364e0(func_020364e8()), data_0217b334->mUnk_0c);
    data_0217b334->mUnk_08 = 0x4020;
    data_0217b334->mUnk_00 = func_02036b74(func_020364e0(func_020364e8()), data_0217b334->mUnk_08, 0x20);
    p = data_0217b334;
    func_020ab088(func_020b403c(0), p->mUnk_00, p->mUnk_04, a, b, 0);
    func_020ab064(func_020abff4);
    func_020ab058(func_020ac0b4);
    func_020ab07c(0);
    func_020ab070(1);
    data_0217b334->mUnk_50 = 0;
    data_0217b334->mUnk_54 = 0;
    data_0217b334->mUnk_58 = 0x23;
    data_0217b334->mUnk_5c = 0x7a;
    data_0217b334->mUnk_60 = 0x7d;
    data_0217b334->mUnk_64 = 0x8e;
    data_0217b334->mUnk_68 = 0x83;
    data_0217b334->mUnk_6c = 0x7a;
    data_0217b334->mUnk_70 = 0xdd;
    data_0217b334->mUnk_74 = 0x8e;
    func_020b49f4(&data_0217b334->mUnk_10[0], FindSceneFile(data_02167bf4));
    func_020b49f4(&data_0217b334->mUnk_10[2], FindSceneFile(data_02167c0c));
    func_020b49f4(&data_0217b334->mUnk_10[1], FindSceneFile(data_02167c24));
    func_020b49f4(&data_0217b334->mUnk_10[3], FindSceneFile(data_02167c3c));
    func_020b49f4(&data_0217b334->mUnk_10[4], FindSceneFile(data_02167c54));
    func_020b49bc(&data_0217b334->mUnk_24, FindSceneFile(data_02167c6c));
    data_0217b334->mUnk_28[0] = FindSceneFile(data_02167c84);
    data_0217b334->mUnk_28[2] = FindSceneFile(data_02167c90);
    data_0217b334->mUnk_28[1] = FindSceneFile(data_02167c9c);
    data_0217b334->mUnk_28[3] = FindSceneFile(data_02167ca4);
    data_0217b334->mUnk_28[4] = FindSceneFile(data_02167cb0);
    data_0217b334->mUnk_28[5] = FindSceneFile(data_02167cbc);
    data_0217b318 = FindSceneFile(data_02167cc8);
    data_0217b31c = FindSceneFile(data_02167cd8);
    data_0217b304 = FindSceneFile(data_02167cec);
    data_0217b338 = FindSceneFile(data_02167d00);
    data_0217b30c = FindSceneFile(data_02167d10);
    data_0217b310 = FindSceneFile(data_02167d28);
    data_0217b314 = FindSceneFile(data_02167d40);
    data_0217b300 = FindSceneFile(data_02167d58);
    data_0217b308 = FindSceneFile(data_02167d68);
    data_0217b320 = FindSceneFile(data_02167d80);
    data_0217b324 = FindSceneFile(data_02167d98);
    data_0217b328 = FindSceneFile(data_02167db0);
    data_0217b32c = FindSceneFile(data_02167dc0);
    data_0217b330 = FindSceneFile(data_02167dd0);
    func_020ab1a8(1, 2, 0x400);
}

void func_020abae0(void) {
    s32 i;
    Unk02175628Index v1;
    Unk0217b334 *q;
    u16 v;

    i = func_020ac238();
    func_020aa81c();
    func_020aa810();
    v1 = UNK_02175628_INDEX_8;
    if ((u16) (data_02175628[v1].mUnk_00 & 8) != 0) {
        if (func_020ab8c4() != 1) {
            func_020ab8cc(1);
        }
    } else if (func_020aa810() == 8) {
        data_0217b334->mUnk_48 = data_0217b334->mUnk_46;
        q = data_0217b334;
        if (q->mUnk_46 != 0) {
            if (q->mUnk_40[q->mUnk_46] == 0) {
                q->mUnk_46--;
            }
            data_0217b334->mUnk_40[data_0217b334->mUnk_46] = 0;
            func_0212ecc0(&data_0217d068, 0, 0x1e3);
        }
    } else if (func_020aa810() >= 0x20) {
        data_0217b334->mUnk_48 = data_0217b334->mUnk_46;
        q = data_0217b334;
        if (q->mUnk_46 < q->mUnk_4a) {
            if (q->mUnk_40[q->mUnk_46] != func_020aa810()) {
                q = data_0217b334;
                q->mUnk_40[q->mUnk_46] = func_020aa810();
                data_0217b334->mUnk_40[data_0217b334->mUnk_46 + 1] = 0;
                if (data_0217b334->mUnk_46 < data_0217b334->mUnk_4a - 1) {
                    data_0217b334->mUnk_46++;
                }
                func_0212ecc0(&data_0217d068, 0, 0x1e2);
            }
        }
    } else if (func_020aa810() == 0x10) {
        v = func_020aa790(data_0217b334->mUnk_40[i]);
        if (v != data_0217b334->mUnk_40[i]) {
            data_0217b334->mUnk_40[i] = v;
            func_0212ecc0(&data_0217d068, 0, 0x1ec);
        }
    } else if (func_020aa810() == 0x11) {
        v = func_020aa738(data_0217b334->mUnk_40[i]);
        if (v != data_0217b334->mUnk_40[i]) {
            data_0217b334->mUnk_40[i] = v;
            func_0212ecc0(&data_0217d068, 0, 0x1ec);
        }
    } else if (func_020aa810() == 0x12) {
        v = func_020aa6e0(data_0217b334->mUnk_40[i]);
        if (v != data_0217b334->mUnk_40[i]) {
            data_0217b334->mUnk_40[i] = v;
            func_0212ecc0(&data_0217d068, 0, 0x1ec);
        }
    } else if (func_020aa810() == 0x13) {
        v = func_020aa650(data_0217b334->mUnk_40[i]);
        if (v != data_0217b334->mUnk_40[i]) {
            data_0217b334->mUnk_40[i] = v;
            func_0212ecc0(&data_0217d068, 0, 0x1ec);
        } else {
            func_0212ecc0(&data_0217d068, 0, 0x1ed);
        }
    }
    func_020aa810();
}

#pragma thumb off
