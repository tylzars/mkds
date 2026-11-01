#include "Main/Unknown/code_02032ab0.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_02033d9c.h"
#include "Main/Unknown/code_02033dd0.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_0210f714.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bc8.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_020a23a0.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"

#pragma thumb on

void func_02032ac4(Unk02032ac4 *a) {
    Unk02174e14_00 *s;
    Unk02174e14_00 *t;
    Unk02175628Index v1;
    s32 x;
    s32 j;
    void *m;
    void *n;
    void *m2;
    void *n2;
    s32 i;
    s32 r;

    t = &data_02174e60->mUnk_048[1];
    s = &data_02174e60->mUnk_048[0];
    if (data_02174e60->mUnk_148 != 0) {
        if (data_02174e60->mUnk_14c != 0) {
            data_02174e60->mUnk_14c = data_02174e60->mUnk_14c - 1;
            x = (data_02174e60->mUnk_14c + 0x3c) / 0x3c;
            s->mUnk_18[data_02174e60->mUnk_0ce].mUnk_00 = x >= 10 ? 1 : 0;
            if (data_02174e60->mUnk_14c == 0) {
                func_0212ecc0(&data_0217d068, 0, 0x51);
            } else if ((data_02174e60->mUnk_14c + 0x3c) % 0x3c == 0 && x <= 4) {
                func_0212ecc0(&data_0217d068, 0, 0x50);
            }
        } else {
            x = 0;
        }
        m = s->mUnk_0c;
        n = s->mUnk_08;
        func_02124748(data_02174e60->mUnk_0cc + (x / 10) % 10, n, s->mUnk_00, m, 0, data_02174e60->mUnk_0ce, n, m);
        m2 = s->mUnk_0c;
        n2 = s->mUnk_08;
        func_02124748(data_02174e60->mUnk_0cc + x % 10, n2, s->mUnk_00, m2, 0, data_02174e60->mUnk_0ce + 1, n2, m2);
    } else {
        s->mUnk_18[data_02174e60->mUnk_0ce + 1].mUnk_00 = 0;
        s->mUnk_18[data_02174e60->mUnk_0ce].mUnk_00 = s->mUnk_18[data_02174e60->mUnk_0ce + 1].mUnk_00;
    }
    switch (data_02174e60->mUnk_150) {
        case 0:
            data_02174e60->mUnk_144 = data_02174e60->mUnk_144 + 1;
            if (func_020546d8() == 1) {
                data_02174e60->mUnk_150 = 1;
            }
            break;
        case 1:
            data_02174e60->mUnk_144 = data_02174e60->mUnk_144 + 1;
            if (func_02054754() == 1) {
                data_02174e60->mUnk_150 = 2;
            }
            break;
        case 2:
            r = func_0210f714();
            data_02174e60->mUnk_144 = data_02174e60->mUnk_144 + 1;
            if (data_02174e60->mUnk_144 > r) {
                data_02174e60->mUnk_144 = 0;
                data_02174e60->mUnk_150 = 3;
            }
            break;
        case 3:
            switch (data_02174e60->mUnk_0e0) {
                case 0:
                    if ((u16) (data_02175628[func_020435bc()].mUnk_00 & 1) != 0) {
                        func_0212ecc0(&data_0217d068, 0, 5);
                        if (a != 0) {
                            a->mUnk_04 = 1;
                        }
                        data_02174e60->mUnk_150 = 7;
                    }
                    break;
                case 1:
                case 2:
                    v1 = UNK_02175628_INDEX_8;
                    if ((u16) (data_02175628[v1].mUnk_00 & 1) != 0) {
                        func_02033d9c();
                        data_02174e60->mUnk_150 = 4;
                        func_0212ecc0(&data_0217d068, 0, 5);
                    }
                    break;
                case 3:
                    if (func_02033dfc() != 0) {
                        func_02121dec(1);
                        data_02174e60->mUnk_150 = 5;
                    } else if ((u16) (data_02175628[func_020435bc()].mUnk_00 & 1) != 0 || func_02033dd0() != 0) {
                        func_02033d9c();
                        func_0212ecc0(&data_0217d068, 0, 5);
                        data_02174e60->mUnk_150 = 4;
                    }
                    break;
            }
            break;
        case 4:
            switch (data_02174e60->mUnk_0e0) {
                case 1:
                case 2:
                    if (func_02127788() != 0) {
                        switch (func_02127794()) {
                            case 0:
                                if (data_021759d0->mUnk_1c_2 != 0) {
                                    data_0217b488->mUnk_74 = 3;
                                    data_0217b488->mUnk_08 = 4;
                                    if (a != 0) {
                                        a->mUnk_04 = 6;
                                    }
                                } else {
                                    data_0217b488->mUnk_08 = 4;
                                    if (a != 0) {
                                        a->mUnk_04 = 1;
                                    }
                                }
                                data_02174e60->mUnk_150 = 7;
                                break;
                            case 1:
                                data_0217aa00->mUnk_0454 = data_0217aa00->mUnk_0454 | 0x80;
                                data_02174e60->mUnk_150 = 6;
                                break;
                            case -1:
                                data_02174e60->mUnk_150 = 3;
                                break;
                        }
                        func_021277e4();
                    }
                    break;
                case 3:
                    if (func_02127788() != 0 || func_02033dfc() != 0) {
                        switch (func_02127794()) {
                            case 0:
                                data_02174e60->mUnk_150 = 5;
                                func_02121dec(1);
                                break;
                            case 1:
                                func_02121dec(0);
                                data_0217b488->mUnk_1c = 1;
                                if (a != 0) {
                                    a->mUnk_04 = 0xc;
                                }
                                data_02174e60->mUnk_150 = 7;
                                break;
                            case -1:
                                data_02174e60->mUnk_150 = 3;
                                break;
                        }
                        func_021277e4();
                    }
                    break;
            }
            break;
        case 5:
            if (func_02121c78() != 0) {
                switch (func_02121c78()) {
                    case 1:
                        data_0217b488->mUnk_1c = 2;
                        break;
                    case 2:
                        data_0217b488->mUnk_1c = 1;
                        break;
                }
                if (a != 0) {
                    a->mUnk_04 = 0xc;
                }
                data_02174e60->mUnk_150 = 7;
            }
            break;
        case 6:
            if (func_02054f58() == 1) {
                if (a != 0) {
                    a->mUnk_04 = 0;
                }
                data_02174e60->mUnk_150 = 7;
            }
            break;
    }
    func_020a2558();
    func_020a23cc();
    for (i = 0; i < 2; i++) {
        func_02124c30(data_02174e60->mUnk_048[i].mUnk_0c, data_02174e60->mUnk_048[i].mUnk_08,
                      data_02174e60->mUnk_048[i].mUnk_14, (void *) data_02174e60->mUnk_0b8[i],
                      data_02174e60->mUnk_048[i].mUnk_18);
    }
    j = t->mUnk_0c->mUnk_06;
    for (i = 0; i < 8; i++) {
        t->mUnk_18[i + j].mUnk_06 = t->mUnk_18[i + j].mUnk_06 + 1;
        func_02124100(i, 0xe, t->mUnk_14, t->mUnk_18, t->mUnk_0c);
        func_02124bc8(i + j, t->mUnk_0c, t->mUnk_08, t->mUnk_14, (void *) data_02174e60->mUnk_0b8[1], t->mUnk_18);
        func_02124100(i, 0xf, t->mUnk_14, t->mUnk_18, t->mUnk_0c);
        t->mUnk_18[i + j].mUnk_06 = t->mUnk_18[i + j].mUnk_06 - 1;
    }
    func_02125928();
}

void func_02032ab0(void) {
    data_0217b488->mUnk_04 = 1;
    func_02125da0();
}

#pragma thumb off
