#include "Main/Unknown/code_020aa81c.h"

#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_020a9ff4.h"
#include "Main/Unknown/code_020ab000.h"
#include "Main/Unknown/code_020ab5bc.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ab604.h"
#include "Main/Unknown/code_020ab660.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/unk_02167000.h"
#include "code_02023374.h"
#include "code_0214d018.h"
#include "code_0214e308.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_020ab088.h"
#include "Main/Unknown/code_020ab5e4.h"
#include "Main/Unknown/code_020ab714.h"
#include "Main/Unknown/code_020ab194.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020ab72c.h"
#include "Main/Unknown/code_020ab748.h"
#include "Main/Unknown/code_020ab758.h"
#include "Main/Unknown/code_020ab798.h"
#include "Main/Unknown/code_020ab7a4.h"
#include "Main/Unknown/code_020ab848.h"
#include "Main/Unknown/code_020ab8c4.h"
#include "Main/Unknown/code_020a9cd4.h"
#include "Main/Unknown/code_020ab8d4.h"
#include "Main/Unknown/code_020ab94c.h"
#include "Main/Unknown/code_020a9ed8.h"
#include "Main/Unknown/code_020a9f40.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020aba94.h"
#include "Main/Unknown/code_020aba9c.h"
#include "code_0200eddc.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020aa810.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_021059e0.h"
#include "code_0212df7c.h"
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
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1e7);
            } else {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 7:
            if (func_020a9e80() != 7) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1e8);
            } else {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 0x10:
            v = func_020aa790(data_0217b334->mUnk_40[i]);
            w = data_0217b334->mUnk_40[i];
            if (w == v) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 0x11:
            v = func_020aa738(data_0217b334->mUnk_40[i]);
            w = data_0217b334->mUnk_40[i];
            if (w == v) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 0x12:
            v = func_020aa6e0(data_0217b334->mUnk_40[i]);
            w = data_0217b334->mUnk_40[i];
            if (w == v) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 4:
        case 5:
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1eb);
            break;
        case 0x20:
        case 0x3000:
            if (b != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ea);
            }
            break;
        case 8:
            if (b != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1e9);
            }
            break;
        default:
            if (b != 0 && a >= 0x20) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1e6);
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

    data_0217b334 = HeapAlloc(GetHeap(func_020364e8()), 0x78);
    data_0217b334->mUnk_44 = c;
    data_0217b334->mUnk_4a = c;
    data_0217b334->mUnk_46 = 0;
    data_0217b334->mUnk_48 = 0;
    data_0217b334->mUnk_40 = HeapAlloc(GetHeap(func_020364e8()), (c + 1) * 2);
    data_0217b334->mUnk_0c = b * (a * 2);
    data_0217b334->mUnk_04 = HeapAlloc(GetHeap(func_020364e8()), data_0217b334->mUnk_0c);
    data_0217b334->mUnk_08 = 0x4020;
    data_0217b334->mUnk_00 = HeapAllocAligned(GetHeap(func_020364e8()), data_0217b334->mUnk_08, 0x20);
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
    LoadNcgrData2(&data_0217b334->mUnk_10[0], FindSceneFile(data_02167bf4));
    LoadNcgrData2(&data_0217b334->mUnk_10[2], FindSceneFile(data_02167c0c));
    LoadNcgrData2(&data_0217b334->mUnk_10[1], FindSceneFile(data_02167c24));
    LoadNcgrData2(&data_0217b334->mUnk_10[3], FindSceneFile(data_02167c3c));
    LoadNcgrData2(&data_0217b334->mUnk_10[4], FindSceneFile(data_02167c54));
    LocateNcgr2(&data_0217b334->mUnk_24, FindSceneFile(data_02167c6c));
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
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1e3);
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
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1e2);
            }
        }
    } else if (func_020aa810() == 0x10) {
        v = func_020aa790(data_0217b334->mUnk_40[i]);
        if (v != data_0217b334->mUnk_40[i]) {
            data_0217b334->mUnk_40[i] = v;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ec);
        }
    } else if (func_020aa810() == 0x11) {
        v = func_020aa738(data_0217b334->mUnk_40[i]);
        if (v != data_0217b334->mUnk_40[i]) {
            data_0217b334->mUnk_40[i] = v;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ec);
        }
    } else if (func_020aa810() == 0x12) {
        v = func_020aa6e0(data_0217b334->mUnk_40[i]);
        if (v != data_0217b334->mUnk_40[i]) {
            data_0217b334->mUnk_40[i] = v;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ec);
        }
    } else if (func_020aa810() == 0x13) {
        v = func_020aa650(data_0217b334->mUnk_40[i]);
        if (v != data_0217b334->mUnk_40[i]) {
            data_0217b334->mUnk_40[i] = v;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ec);
        } else {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ed);
        }
    }
    func_020aa810();
}

#pragma thumb off

#pragma thumb on

void func_020aba9c(void) {
    DC_FlushRange(data_0217b334->mUnk_04, data_0217b334->mUnk_0c);
    GXS_LoadBG2Scr(data_0217b334->mUnk_04, 0, data_0217b334->mUnk_0c);
    DC_FlushRange(data_0217b334->mUnk_00, data_0217b334->mUnk_08);
    GXS_LoadBG2Char(data_0217b334->mUnk_00, 0, data_0217b334->mUnk_08);
    return;
}

#pragma thumb off

#pragma thumb on
void func_020aba94(u32 arg0) {
    u32 value0 = arg0;
    u32 value3;
    func_020ab07c(value0);
}
#pragma thumb off

#pragma thumb on

void func_020ab9d0(u32 a) {
    switch (a) {
        case 0:
            func_020a9f40(data_0217b334->mUnk_28[a], data_0217b334->mUnk_10[a], data_usa_021567fc[a]);
            break;
        case 1:
            func_020a9ff4(data_0217b334->mUnk_28[a], data_0217b334->mUnk_10[a], data_usa_021567fc[a]);
            break;
        case 2:
            func_020a9fc4(data_0217b334->mUnk_28[a], data_0217b334->mUnk_10[a], data_usa_021567fc[a]);
            break;
        case 3:
            func_020a9f98(data_0217b334->mUnk_28[a], data_0217b334->mUnk_10[a], data_usa_021567fc[a]);
            break;
        case 4:
            func_020a9f6c(data_0217b334->mUnk_28[a], data_0217b334->mUnk_10[a], data_usa_021567fc[a]);
            break;
        case 5:
            func_020a9f40(data_0217b334->mUnk_28[a], data_0217b334->mUnk_10[a], data_usa_021567fc[a]);
            break;
    }
    data_0217b334->mUnk_4c = a;
}

void func_020ab94c(s32 a, s32 b) {
    data_0217b334->mUnk_50 = a;
    data_0217b334->mUnk_54 = b;
    func_020ab194(data_0217b334->mUnk_50, data_0217b334->mUnk_54);
    *(vu32 *) 0x4001018 = (-data_0217b334->mUnk_50 & 0x1ff) | ((-data_0217b334->mUnk_54 << 16) & 0x1ff0000);
    func_020a9efc(data_0217b334->mUnk_50 + data_0217b334->mUnk_58, data_0217b334->mUnk_54 + data_0217b334->mUnk_5c,
                  data_0217b334->mUnk_50 + data_0217b334->mUnk_60, data_0217b334->mUnk_54 + data_0217b334->mUnk_64);
    func_020a9ed8(data_0217b334->mUnk_50 + data_0217b334->mUnk_68, data_0217b334->mUnk_54 + data_0217b334->mUnk_6c,
                  data_0217b334->mUnk_50 + data_0217b334->mUnk_70, data_0217b334->mUnk_54 + data_0217b334->mUnk_74);
}

#pragma thumb off

#pragma thumb on

void func_020ab910(u32 a, u32 b, u32 c, u32 d) {
    Unk0217b334 **v1;
    Unk0217b334 *v2;
    v1 = &data_0217b334;
    data_0217b334->mUnk_58 = a;
    (*v1)->mUnk_5c = b;
    (*v1)->mUnk_60 = c;
    (*v1)->mUnk_64 = d;
    v2 = *v1;
    func_020a9efc((u32) (v2->mUnk_50 + v2->mUnk_58), (u32) (v2->mUnk_54 + v2->mUnk_5c),
                  (u32) (v2->mUnk_50 + v2->mUnk_60), (u32) (v2->mUnk_54 + v2->mUnk_64));
}

void func_020ab8d4(u32 a, u32 b, u32 c, u32 d) {
    Unk0217b334 **v1;
    Unk0217b334 *v2;
    v1 = &data_0217b334;
    data_0217b334->mUnk_68 = a;
    (*v1)->mUnk_6c = b;
    (*v1)->mUnk_70 = c;
    (*v1)->mUnk_74 = d;
    v2 = *v1;
    func_020a9ed8((u32) (v2->mUnk_50 + v2->mUnk_68), (u32) (v2->mUnk_54 + v2->mUnk_6c),
                  (u32) (v2->mUnk_50 + v2->mUnk_70), (u32) (v2->mUnk_54 + v2->mUnk_74));
}

#pragma thumb off

#pragma thumb on

void func_020ab8cc(u16 a) {
    func_020a9ea0(a);
}

u32 func_020ab8c4(void) {
    return func_020a9e90();
}

#pragma thumb off

#pragma thumb on

void func_020ab848(s32 *a, s32 *b, s32 *c, s32 *d) {
    s32 value;
    func_020ab11c(a, b, c, d);
    *a = *a - data_0217b334->mUnk_50;
    *b = *b - data_0217b334->mUnk_54;
    *c = *c - data_0217b334->mUnk_50;
    *d = *d - data_0217b334->mUnk_54;
    value = *a;
    if (value < 0) {
        value += 0x100;
    }
    *a = value;
    value = *b;
    if (value < 0) {
        value += 0x100;
    }
    *b = value;
    value = *c;
    if (value < 0) {
        value += 0x100;
    }
    *c = value;
    value = *d;
    if (value < 0) {
        value += 0x100;
    }
    *d = value;
}

#pragma thumb off

#pragma thumb on

void func_020ab7a4(const u16 *a) {
    s32 i;

    for (i = 0; i < data_0217b334->mUnk_44; i++) {
        data_0217b334->mUnk_40[i] = 0;
    }
    for (i = 0; i < data_0217b334->mUnk_4a; i++) {
        data_0217b334->mUnk_40[i] = *a;
        if (*a == 0) {
            data_0217b334->mUnk_46 = i;
            data_0217b334->mUnk_48 = data_0217b334->mUnk_46;
            return;
        }
        a++;
    }
    data_0217b334->mUnk_46 = data_0217b334->mUnk_4a - 1;
    data_0217b334->mUnk_48 = data_0217b334->mUnk_46;
    data_0217b334->mUnk_40[data_0217b334->mUnk_4a] = 0;
}

#pragma thumb off

#pragma thumb on

u16 *func_020ab798(void) {
    return data_0217b334->mUnk_40;
}

#pragma thumb off

#pragma thumb on

void func_020ab758(u16 a) {
    data_0217b334->mUnk_4a = a;
    if (data_0217b334->mUnk_46 >= data_0217b334->mUnk_4a - 1) {
        data_0217b334->mUnk_46 = data_0217b334->mUnk_4a - 1;
        data_0217b334->mUnk_48 = data_0217b334->mUnk_46;
        data_0217b334->mUnk_40[data_0217b334->mUnk_4a] = 0;
    }
}

#pragma thumb off

#pragma thumb on

u16 func_020ab748(void) {
    return data_0217b334->mUnk_46;
}

#pragma thumb off

#pragma thumb on

void func_020ab72c(void) {
    MemFillWordsByBlock_inline(&data_0217b2d8, 0x28);
}

#pragma thumb off

#pragma thumb on

void func_020ab714(void) {
    func_020ab72c();
    data_0217b2d8.mUnk_24 = TRUE;
}

#pragma thumb off

#pragma thumb on

void func_020ab660(u16 a, volatile TPData b) {
    u32 t;
    u16 v;

    t = a ^ data_0217b2d8.mUnk_06;
    data_0217b2d8.mUnk_04 = a & t;
    data_0217b2d8.mUnk_08 = ~a & t;
    data_0217b2d8.mUnk_06 = a;
    if ((data_0217b2d8.mUnk_06 & data_0217b2d8.mUnk_0a) != 0) {
        data_0217b2d8.mUnk_00++;
    } else {
        data_0217b2d8.mUnk_00 = 0;
    }
    if (data_0217b2d8.mUnk_24 != FALSE) {
        if (b.mValidity != 0) {
            b.mX = data_0217b2d8.mUnk_0c[0];
            b.mY = data_0217b2d8.mUnk_0c[1];
            b.mTouch = data_0217b2d8.mUnk_0c[2];
            b.mValidity = data_0217b2d8.mUnk_0c[3];
            b.mTouch = 0;
        }
        v = b.mTouch;
        if (v != data_0217b2d8.mUnk_0c[2]) {
            data_0217b2d8.mUnk_1c = v != 0 ? 1 : 3;
            data_0217b2d8.mUnk_18 = 0;
        } else if (v != 0) {
            data_0217b2d8.mUnk_1c = 2;
            data_0217b2d8.mUnk_18++;
        } else {
            data_0217b2d8.mUnk_1c = 0;
        }
        if (v != 0) {
            data_0217b2d8.mUnk_14 = b.mX;
            data_0217b2d8.mUnk_16 = b.mY;
        }
        data_0217b2d8.mUnk_20 = v;
        data_0217b2d8.mUnk_0c[0] = b.mX;
        data_0217b2d8.mUnk_0c[1] = b.mY;
        data_0217b2d8.mUnk_0c[2] = b.mTouch;
        data_0217b2d8.mUnk_0c[3] = b.mValidity;
    }
}

#pragma thumb off

#pragma thumb on
u32 func_020ab650(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) data_0217b2d8.mUnk_04;
    value1 = (value1) & (value0);
    value0 = (value1) + (0u);
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 func_020ab640(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) data_0217b2d8.mUnk_06;
    value1 = (value1) & (value0);
    value0 = (value1) + (0u);
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 func_020ab634(void) {
    u32 value0;
    value0 = (u32) data_0217b2d8.mUnk_20;
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 func_020ab628(void) {
    u32 value0;
    value0 = (u32) data_0217b2d8.mUnk_1c;
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 func_020ab61c(void) {
    u32 value0;
    value0 = (u32) data_0217b2d8.mUnk_14;
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 func_020ab610(void) {
    u32 value0;
    value0 = (u32) data_0217b2d8.mUnk_16;
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 func_020ab604(void) {
    u32 value0;
    value0 = (u32) data_0217b2d8.mUnk_24;
    return value0;
}
#pragma thumb off

#pragma thumb on

void func_020ab5f4(Unk0217b278_34 *p0) {
    p0->mUnk_00 = (u16) 0x0u;
    p0->mUnk_06 = (u16) 0x0u;
    p0->mUnk_02 = (u16) 0x28u;
    p0->mUnk_04 = (u16) 0x2du;
}

void func_020ab5e4(Unk0217b278_34 *p0, u32 p1, u32 p2) {
    p0->mUnk_00 = (u16) 0x0u;
    p0->mUnk_06 = (u16) 0x0u;
    p0->mUnk_02 = (u16) p1;
    p0->mUnk_04 = (u16) (((p1) + (p2)));
}

#pragma thumb off

#pragma thumb on

void func_020ab5bc(Unk0217b278_34 *p) {
    p->mUnk_00 = p->mUnk_00 + 1;
    if (p->mUnk_00 == p->mUnk_02 || p->mUnk_00 == p->mUnk_04) {
        p->mUnk_06 = 1;
    }
    if (p->mUnk_00 > p->mUnk_04) {
        p->mUnk_00 = p->mUnk_02 + 1;
    }
}

#pragma thumb off

#pragma thumb on

void func_020ab5b4(Unk0217b278_34 *p0) {
    p0->mUnk_00 = (u16) 0x0u;
    p0->mUnk_06 = (u16) 0x0u;
}

#pragma thumb off

#pragma thumb on

BOOL func_020ab59c(Unk0217b278_34 *p) {
    if (p->mUnk_00 == p->mUnk_02 || p->mUnk_00 == p->mUnk_04) {
        return TRUE;
    }
    return FALSE;
}

void func_020ab580(u16 a) {
    func_020ab5f4(&data_0217b2cc.mUnk_00);
    data_0217b2cc.mUnk_08 = a;
    data_0217b2cc.mUnk_0a = 0;
}

void func_020ab528(void) {
    if (data_0217b2cc.mUnk_0a == 0 && func_020ab650(data_0217b2cc.mUnk_08) != 0) {
        data_0217b2cc.mUnk_0a = func_020ab650(data_0217b2cc.mUnk_08);
        return;
    }
    if (func_020ab640(data_0217b2cc.mUnk_0a) != 0) {
        func_020ab5bc(&data_0217b2cc.mUnk_00);
    } else {
        func_020ab5b4(&data_0217b2cc.mUnk_00);
        data_0217b2cc.mUnk_0a = 0;
    }
}

u16 func_020ab500(void) {
    u32 v;

    if (func_020ab59c(&data_0217b2cc.mUnk_00) != FALSE) {
        v = func_020ab640(data_0217b2cc.mUnk_0a);
    } else {
        v = 0;
    }
    return v;
}

u16 func_020ab4d4(void) {
    if (func_020ab650(0x2fff) != 0) {
        return func_020ab650(0x2fff);
    }
    return func_020ab500();
}

void func_020ab45c(Unk0217b278 *p) {
    switch (p->mUnk_3c) {
        case 4:
            p->mUnk_42 = p->mUnk_42 != 4 ? 4 : 0;
            break;
        case 5:
            p->mUnk_42 = p->mUnk_42 != 5 ? 5 : 0;
            break;
    }
    switch (p->mUnk_42) {
        case 0:
            p->mUnk_30 = data_0217b318 + 1;
            break;
        case 4:
            p->mUnk_30 = data_0217b304 + 1;
            break;
        case 5:
            p->mUnk_30 = data_0217b31c + 1;
            break;
    }
}

void func_020ab3ec(Unk0217b278 *p) {
    switch (p->mUnk_3c) {
        case 4:
            p->mUnk_40 = 4;
            p->mUnk_42 = 0;
            break;
        case 5:
            p->mUnk_40 = 5;
            p->mUnk_42 = 0;
            break;
    }
    switch (p->mUnk_40) {
        case 4:
            if (p->mUnk_42 == 0) {
                p->mUnk_30 = data_0217b338 + 1;
            }
            break;
        case 5:
            if (p->mUnk_42 == 0) {
                p->mUnk_30 = data_0217b300 + 1;
            }
            break;
    }
}

Unk0217b278_10 *func_020ab338(u16 a) {
    Unk0217b278_10 *e;
    s32 i;
    u16 n;
    u16 c;
    u16 *w;

    if (data_0217b278.mUnk_2c != NULL) {
        e = data_0217b278.mUnk_2c->mUnk_00;
        n = data_0217b278.mUnk_2c->mUnk_0e;
        c = data_0217b278.mUnk_2c->mUnk_0c;
        w = data_0217b278.mUnk_30;
        switch (a) {
            case 0:
                return NULL;
            case 1:
                return &data_0217b278.mUnk_00;
            case 2:
                return &data_0217b278.mUnk_08;
            case 8:
                return e;
            case 10:
                return e + 1;
            case 0x20:
            case 0x3000:
                return e + 2;
        }
        for (i = 0; i < n; i++) {
            if (e[i].mUnk_02 > 1 && e[i].mUnk_03 > 1 && a == w[e[i].mUnk_06 - c - 1]) {
                return &e[i];
            }
        }
    }
    return NULL;
}

s32 func_020ab2a4(Unk0217b278_10 *p) {
    Unk0217b278_10 *e;
    s32 i;
    s32 n;
    u16 c;
    u16 *w;

    if (data_0217b278.mUnk_2c != NULL) {
        e = data_0217b278.mUnk_2c->mUnk_00;
        n = data_0217b278.mUnk_2c->mUnk_0e;
        c = data_0217b278.mUnk_2c->mUnk_0c;
        w = data_0217b278.mUnk_30;
        if (p == NULL) {
            return 0;
        }
        if (p == &data_0217b278.mUnk_00) {
            return 1;
        }
        if (p == &data_0217b278.mUnk_08) {
            return 2;
        }
        for (i = 0; i < n; i++) {
            if (e[i].mUnk_02 > 1 && e[i].mUnk_03 > 1 && p == &e[i]) {
                switch (i) {
                    case 0:
                        return 8;
                    case 1:
                        return 0xa;
                    case 2:
                        return 0x20;
                }
                return w[e[i].mUnk_06 - c - 1];
            }
        }
    }
    return 0;
}

s32 func_020ab1d0(u32 a) {
    Unk0217b278_1c *t;
    u16 c;

    t = data_0217b278.mUnk_2c;
    if (t != NULL) {
        if (a == 0) {
            return 0;
        }
        c = t->mUnk_0c;
        if (a <= c || a == 0xffff) {
            if (t->mUnk_08 == func_020ab3ec) {
                switch ((s32) a) {
                    case 1:
                        return 8;
                    case 2:
                        return 0xa;
                    case 3:
                        return 0x3000;
                    case 4:
                        return 6;
                    case 5:
                        return 7;
                    case 6:
                        return 0x10;
                    case 7:
                        return 0x11;
                    case 8:
                        return 0x12;
                    case 0xffff:
                        return 0x13;
                }
            } else {
                switch ((s32) a) {
                    case 1:
                        return 8;
                    case 2:
                        return 0xa;
                    case 3:
                        return 0x20;
                    case 4:
                        return 4;
                    case 5:
                        return 5;
                }
            }
        }
        if (a <= 0xff && data_0217b278.mUnk_30[a - c - 1] > 0x20) {
            return data_0217b278.mUnk_30[a - c - 1];
        }
    }
    return 0;
}

void func_020ab1a8(u16 a, u16 b, u16 c) {
    data_021679fc[0] = a;
    data_021679fc[1] = b;
    data_021679fc[2] = c;
    func_020ab580(data_021679fc[2] | (data_021679fc[0] | 0xf0 | data_021679fc[1]));
}

#pragma thumb off

#pragma thumb on
u32 func_020ab194(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (u32) &data_0217b234;
    *(u32 *) ((value2) + 0u) = value0;
    value0 = (u32) &data_0217b238;
    *(u32 *) ((value0) + 0u) = value1;
    return value0;
}
#pragma thumb off

#pragma thumb on

void func_020ab11c(s32 *a, s32 *b, s32 *c, s32 *d) {
    if (data_0217b278.mUnk_44 != NULL && a != NULL && b != NULL && c != NULL && d != NULL) {
        *a = data_0217b278.mUnk_44->mUnk_00;
        *b = data_0217b278.mUnk_44->mUnk_01;
        *c = data_0217b278.mUnk_44->mUnk_00 + data_0217b278.mUnk_44->mUnk_02;
        *d = data_0217b278.mUnk_44->mUnk_01 + data_0217b278.mUnk_44->mUnk_03;
        if (data_0217b278.mUnk_44->mUnk_06 <= 0xff) {
            *a = *a + data_0217b234;
            *b = *b + data_0217b238;
            *c = *c + data_0217b234;
            *d = *d + data_0217b238;
        }
    }
}

void func_020ab088(struct Unk02022aa8 *a, void *b, u16 *c, s32 d, s32 e, s32 f) {
    MI_CpuFill8(&data_0217b278, 0, 0x54);
    data_0217b254.mUnk_00 = a;
    data_0217b254.mUnk_04 = b;
    data_0217b254.mUnk_08 = b;
    data_0217b254.mUnk_0c = c;
    data_0217b254.mUnk_10 = d;
    data_0217b254.mUnk_14 = e;
    data_0217b254.mUnk_1c = f;
    func_020ab714();
    func_020ab5e4(&data_0217b2ac, 0x28, 5);
    func_020ab580(data_021679fc[2] | (data_021679fc[0] | 0xf0 | data_021679fc[1]));
    data_0217b24c[0] = data_0217b244[0] = data_0217b23c[0] = data_02167a04[0];
    data_0217b24c[1] = data_02167a04[1];
    data_0217b244[1] = data_02167a04[2];
    data_0217b23c[1] = data_02167a04[3];
}

#pragma thumb off

#pragma thumb on
void func_020ab07c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    data_0217b254.mUnk_18 = value0;
}
#pragma thumb off

#pragma thumb on
void func_020ab070(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    data_0217b254.mUnk_20 = value0;
}
#pragma thumb off

#pragma thumb on
void func_020ab064(u16 (*arg0)(s32, u16)) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_0217b278;
    *(u32 *) ((value1) + 76u) = value0;
}
#pragma thumb off

#pragma thumb on
void func_020ab058(s32 (*arg0)(u32, s32)) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_0217b278;
    *(u32 *) ((value1) + 80u) = value0;
}
#pragma thumb off

#pragma thumb on

void func_020ab028(s32 a) {
    if (data_0217b278.mUnk_50 != NULL) {
        if (data_0217b278.mUnk_50(func_020ab1d0(data_0217b278.mUnk_3c), a) != 0) {
            data_0217b278.mUnk_3c = 0;
        }
    }
}

void func_020aafa8(Unk0217b278 *a) {
    s32 w;
    s32 h;
    s32 i;
    s32 v1;
    BOOL j0;
    s32 j;
    volatile u16 n;

    h = a->mUnk_2c->mUnk_04->mUnk_02;
    w = a->mUnk_2c->mUnk_04->mUnk_00;
    n = h * w;
    MIi_CpuClear16(n, data_0217b254.mUnk_0c, data_0217b254.mUnk_14 * (data_0217b254.mUnk_10 * 2));
    i = 0;
    v1 = 0;
    v1 = (u32) v1;
    j0 = FALSE;
    if (i < w) {
        v1 = 0;
        v1 = (u32) v1;
        do {
            for (j = j0; j < h; j++) {
                data_0217b254.mUnk_0c[j + i * data_0217b254.mUnk_14 / 2] =
                    (data_0217b254.mUnk_18 << 12) | (j + (data_0217b254.mUnk_1c + v1));
            }
            v1 += h;
            i++;
        } while (i < w);
    }
}

u16 func_020aaf70(Unk0217b278_1c *a) {
    u16 i;
    const Unk0217b278_1c *p = a;

    for (i = 0; i < p->mUnk_0e; i++) {
        if (a->mUnk_0c + 1 == a->mUnk_00[i].mUnk_06) {
            return i;
        }
    }
    return 0;
}

Unk0217b278_10 *func_020aaea0(Unk0217b278 *a, s32 b, s32 c) {
    Unk0217b278_10 *e;
    Unk0217b278_1c *q;
    s32 n;
    Unk0217b278_10 *t;
    s32 i;

    e = &a->mUnk_00;
    if (e->mUnk_02 > 1 && e->mUnk_03 > 1 && e->mUnk_01 <= c && c < e->mUnk_01 + e->mUnk_03 && e->mUnk_00 <= b &&
        b < e->mUnk_00 + e->mUnk_02) {
        return e;
    }
    e = &a->mUnk_08;
    if (e->mUnk_02 > 1 && e->mUnk_03 > 1 && e->mUnk_01 <= c && c < e->mUnk_01 + e->mUnk_03 && e->mUnk_00 <= b &&
        b < e->mUnk_00 + e->mUnk_02) {
        return e;
    }
    q = a->mUnk_2c;
    t = q->mUnk_00;
    n = q->mUnk_0e;
    for (i = 0; i < n; i++) {
        if (t[i].mUnk_02 > 1 && t[i].mUnk_03 > 1 && data_0217b238 + t[i].mUnk_01 <= c &&
            c < data_0217b238 + (t[i].mUnk_01 + t[i].mUnk_03) && data_0217b234 + t[i].mUnk_00 <= b &&
            b < data_0217b234 + (t[i].mUnk_00 + t[i].mUnk_02)) {
            return &t[i];
        }
    }
    return NULL;
}

void func_020aad9c(Unk0217b278 *a) {
    Unk02022aa8 *f;
    Unk0217b278_10 *e;
    Unk02022ce4_08 *u;
    Unk02022c80 *t;
    Unk02023374_24 v1;
    Unk02023374 v2;
    s32 c;
    Unk0217b278_1c *q;
    u32 g;
    s32 v;
    s32 n;
    s32 j;
    s32 h;
    s32 i;
    s32 k;

    f = data_0217b254.mUnk_00;
    c = f->mUnk_00->mUnk_08->mUnk_01;
    q = a->mUnk_2c;
    MIi_CpuCopyFast(q->mUnk_04->mData, data_0217b254.mUnk_04, q->mUnk_04->mDataSize);
    NNS_G2dCharCanvasInitForBG(&v2, data_0217b254.mUnk_04, q->mUnk_04->mUnk_02, q->mUnk_04->mUnk_00, 4);
    n = func_020aaf70(q);
    i = 0;
    if (q->mUnk_0e - n > 0) {
        j = 0;
        k = n;
        do {
            e = &q->mUnk_00[(u32) n];
            g = *(u16 *) ((u8 *) a->mUnk_30 + j);
            if (e->mUnk_02 > 1 && e->mUnk_03 > 1) {
                v = NNS_G2dFontFindGlyphIndex(f, g);
                if (v == 0xffff) {
                    v = f->mUnk_00->mUnk_02;
                }
                t = NNS_G2dFontGetCharWidthsFromIndex(f, v);
                v1.mUnk_00 = t;
                u = f->mUnk_00->mUnk_08;
                v1.mUnk_04 = u->mUnk_08 + v * u->mUnk_02;
                h = (e->mUnk_02 - t->mUnk_01) / 2;
                v2.mUnk_14(&v2, f, e->mUnk_00 + h, e->mUnk_01 + (e->mUnk_03 - c) / 2, data_0217b254.mUnk_20, &v1);
            }
            n++;
            j += 2;
            i++;
        } while (i < q->mUnk_0e - k);
    }
}

void func_020aab70(Unk0217b278 *a) {
    Unk0217b278_1c *q;
    Unk0217b278_10 *e;
    Unk0217b278_10 *r;

    q = a->mUnk_2c;
    MIi_CpuCopyFast(data_0217b254.mUnk_04, data_0217b254.mUnk_08, q->mUnk_04->mDataSize);
    MemFillWordsByBlock_inline((u8 *) data_0217b254.mUnk_08 + (q->mUnk_04->mDataSize << 5), 0x20);
    if (a->mUnk_40 != 0) {
        e = q->mUnk_00 + (a->mUnk_40 - 1);
        r = e;
        do {
            func_020aa3a0(data_0217b254.mUnk_08, data_0217b278.mUnk_2c->mUnk_04->mUnk_02 << 3, 8, r->mUnk_00,
                          r->mUnk_01, r->mUnk_00 + r->mUnk_02, r->mUnk_01 + r->mUnk_03);
            r += r->mUnk_04;
        } while (r != e);
    }
    if (a->mUnk_42 != 0) {
        e = q->mUnk_00 + (a->mUnk_42 - 1);
        r = e;
        do {
            func_020aa3a0(data_0217b254.mUnk_08, data_0217b278.mUnk_2c->mUnk_04->mUnk_02 << 3, 8, r->mUnk_00,
                          r->mUnk_01, r->mUnk_00 + r->mUnk_02, r->mUnk_01 + r->mUnk_03);
            r += r->mUnk_04;
        } while (r != e);
    }
    e = a->mUnk_44;
    if (e != NULL && e->mUnk_06 != 0 && e->mUnk_06 <= 0xff && e->mUnk_06 != data_0217b2b8[1] &&
        e->mUnk_06 != data_0217b2b8[0] && e != a->mUnk_10 && e != a->mUnk_18) {
        r = e;
        do {
            func_020aa47c(data_0217b254.mUnk_08, data_0217b278.mUnk_2c->mUnk_04->mUnk_02 << 3, 8, r->mUnk_00,
                          r->mUnk_01, r->mUnk_00 + r->mUnk_02, r->mUnk_01 + r->mUnk_03);
            r += r->mUnk_04;
        } while (r != e);
    }
    e = a->mUnk_18;
    if (e != NULL && e->mUnk_06 != 0 && e->mUnk_06 <= 0xff && e->mUnk_06 != data_0217b2b8[1] &&
        e->mUnk_06 != data_0217b2b8[0]) {
        r = e;
        do {
            func_020aa3a0(data_0217b254.mUnk_08, data_0217b278.mUnk_2c->mUnk_04->mUnk_02 << 3, 8, r->mUnk_00,
                          r->mUnk_01, r->mUnk_00 + r->mUnk_02, r->mUnk_01 + r->mUnk_03);
            r += r->mUnk_04;
        } while (r != e);
    }
    e = a->mUnk_10;
    if (e != NULL && e->mUnk_06 != 0 && e->mUnk_06 <= 0xff && e->mUnk_06 != data_0217b2b8[1] &&
        e->mUnk_06 != data_0217b2b8[0] && e != a->mUnk_18) {
        if (a->mUnk_14 != NULL && e->mUnk_06 == a->mUnk_14->mUnk_06) {
            r = e;
            do {
                func_020aa3a0(data_0217b254.mUnk_08, data_0217b278.mUnk_2c->mUnk_04->mUnk_02 << 3, 8, r->mUnk_00,
                              r->mUnk_01, r->mUnk_00 + r->mUnk_02, r->mUnk_01 + r->mUnk_03);
                r += r->mUnk_04;
            } while (r != e);
            return;
        }
        r = e;
        do {
            func_020aa47c(data_0217b254.mUnk_08, data_0217b278.mUnk_2c->mUnk_04->mUnk_02 << 3, 8, r->mUnk_00,
                          r->mUnk_01, r->mUnk_00 + r->mUnk_02, r->mUnk_01 + r->mUnk_03);
            r += r->mUnk_04;
        } while (r != e);
    }
}

u32 func_020aab40(Unk0217b278 *a) {
    u32 r;
    u32 b;
    Unk0217b278_10 *p;

    r = 0;
    b = 0;
    p = a->mUnk_10;
    if (p != NULL && a->mUnk_14 != NULL) {
        b = 1;
    }
    if (b != 0) {
        if (a->mUnk_14->mUnk_06 == p->mUnk_06) {
            r = 1;
        }
    }
    return r;
}

void func_020aa89c(u16 a, TPData b) {
    u16 h;
    u16 k;
    void (*fn)(Unk0217b278 *);

    func_020ab660(a, b);
    func_020ab528();
    data_0217b278.mUnk_3c = 0;
    data_0217b278.mUnk_3e = 0;
    if (data_0217b278.mUnk_2c != NULL && data_0217b278.mUnk_30 != NULL) {
        if (func_020ab640(data_021679fc[0]) != 0) {
            data_0217b278.mUnk_18 = data_0217b278.mUnk_44;
        } else if (func_020ab640(data_021679fc[1]) != 0) {
            data_0217b278.mUnk_18 = data_0217b278.mUnk_2c->mUnk_00;
        } else {
            data_0217b278.mUnk_18 = NULL;
        }
        k = data_021679fc[0];
        if ((func_020ab4d4() & k) != 0) {
            data_0217b278.mUnk_3c = data_0217b278.mUnk_44->mUnk_06;
            func_020ab028(func_020ab650(k));
        } else {
            k = data_021679fc[1];
            if ((func_020ab4d4() & k) != 0) {
                data_0217b278.mUnk_3c = 1;
                func_020ab028(func_020ab650(k));
            } else {
                k = data_021679fc[2];
                if ((func_020ab4d4() & k) != 0) {
                    fn = data_0217b278.mUnk_2c->mUnk_08;
                    if (fn == func_020ab45c) {
                        h = data_0217b2b8[1];
                        if (h == 0) {
                            data_0217b278.mUnk_3c = 4;
                        } else if (h == 4) {
                            data_0217b278.mUnk_3c = 5;
                        } else if (h == 5) {
                            data_0217b278.mUnk_3c = 5;
                        }
                        func_020ab028(func_020ab650(k));
                    } else if (fn == func_020ab3ec) {
                        data_0217b278.mUnk_3c = 0xffff;
                        func_020ab028(func_020ab650(k));
                    }
                }
            }
        }
        if ((func_020ab4d4() & 0x40) != 0) {
            data_0217b278.mUnk_44 = func_020aa0ec(0x40, data_0217b278.mUnk_44, data_0217b278.mUnk_2c->mUnk_00);
        } else if ((func_020ab4d4() & 0x80) != 0) {
            data_0217b278.mUnk_44 = func_020aa0ec(0x80, data_0217b278.mUnk_44, data_0217b278.mUnk_2c->mUnk_00);
        } else if ((func_020ab4d4() & 0x20) != 0) {
            data_0217b278.mUnk_44 = func_020aa0ec(0x20, data_0217b278.mUnk_44, data_0217b278.mUnk_2c->mUnk_00);
        } else if ((func_020ab4d4() & 0x10) != 0) {
            data_0217b278.mUnk_44 = func_020aa0ec(0x10, data_0217b278.mUnk_44, data_0217b278.mUnk_2c->mUnk_00);
        }
        if (func_020ab634() != 0) {
            data_0217b278.mUnk_14 = func_020aaea0(&data_0217b278, func_020ab61c(), func_020ab610());
        }
        if (func_020ab628() == 1) {
            data_0217b278.mUnk_10 = func_020aaea0(&data_0217b278, func_020ab61c(), func_020ab610());
            if (data_0217b278.mUnk_10 != NULL) {
                data_0217b278.mUnk_3c = data_0217b278.mUnk_10->mUnk_06;
                func_020ab028(1);
            }
        } else if (func_020ab628() == 3) {
            data_0217b278.mUnk_10 = NULL;
        }
        if (func_020aab40(&data_0217b278) != 0) {
            func_020ab5bc(&data_0217b2ac);
            if (func_020ab59c(&data_0217b2ac) != FALSE) {
                data_0217b278.mUnk_3c = data_0217b278.mUnk_10->mUnk_06;
                func_020ab028(0);
            }
        } else {
            func_020ab5b4(&data_0217b2ac);
        }
        data_0217b278.mUnk_3e = func_020ab1d0(data_0217b278.mUnk_3c);
        if (data_0217b278.mUnk_3e >= 0x20) {
            fn = data_0217b278.mUnk_2c->mUnk_08;
            if (fn == func_020ab45c) {
                if (data_0217b2b8[1] == 4) {
                    data_0217b2b8[1] = 0;
                }
            } else if (fn == func_020ab3ec) {
                data_0217b2b8[1] = 0;
            }
        }
        if (data_0217b278.mUnk_3c != 0 && data_0217b278.mUnk_2c->mUnk_08 != NULL) {
            data_0217b278.mUnk_2c->mUnk_08(&data_0217b278);
        }
        func_020aad9c(&data_0217b278);
        func_020aab70(&data_0217b278);
    }
}

void func_020aa81c(void) {
    TPData a;
    TPData b;

    if (func_020ab604() != 0) {
        do {
            TP_RequestSamplingAsync();
        } while (TP_WaitRawResult(&a) != 0);
        TP_GetCalibratedPoint(&b, &a);
    } else {
        b.mTouch = 0;
        b.mValidity = 3;
    }
    func_020aa89c(((*(vu16 *) 0x4000130 | *(vu16 *) 0x27fffa8) ^ 0x2fff) & 0x2fff, b);
}

#pragma thumb off
