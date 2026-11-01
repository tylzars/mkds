#include "Main/Unknown/code_02030b18.h"
#include "Main/Unknown/code_02030a20.h"
#include "Main/Unknown/code_02031280.h"
#include "Main/Unknown/code_02031208.h"
#include "Main/Unknown/code_0202f14c.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02108c1c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0212b5ec.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02182fdc.h"
#include "code_0201ea58.h"
#include "code_0212d5e0.h"
#include "code_0212df7c.h"
#include "code_0214cfe4.h"

#pragma thumb on

s32 func_02030b18(Unk02030b18 *a) {
    Unk02174e58_24 *p;
    s32 v1;
    s32 v;
    s32 v2;
    u16 k;
    u16 v3[12];
    s32 x;
    u32 b1;
    u32 a1;
    u32 w;
    s32 y;

    v1 = -1;
    k = func_020435bc();
    v = 0;
    p = &data_02174e58->mUnk_24[1];
    if (data_02174e58->mUnk_9c > 0) {
        data_02174e58->mUnk_9c = data_02174e58->mUnk_9c - 1;
    }
    func_020317a0();
    v2 = data_02174e58->mUnk_74;
    if (data_02174e58->mUnk_84 == 0 && data_02174e58->mUnk_8c == 0) {
        data_02174e58->mUnk_74 = func_02032000();
        if (data_02174e58->mUnk_74 != v2) {
            func_02031f5c();
            if (data_02174e58->mUnk_88 == 0) {
                if (data_02174e58->mUnk_74 > v2) {
                    func_0212d5e0(&data_0217c868);
                    func_0212ecc0(&data_0217d068, 0, 2);
                    func_0212d5e0(&data_0217d0a0);
                } else if (data_02174e58->mUnk_74 < v2) {
                    func_0212d5e0(&data_0217c868);
                    func_0212ecc0(&data_0217d068, 0, 3);
                    func_0212d5e0(&data_0217d0a0);
                }
                data_02174e58->mUnk_88 = 0;
            }
        }
        func_02031b6c();
    }
    if (data_02174e58->mUnk_84 == 0 && data_02174e58->mUnk_80 == 0) {
        v3[0] = 0;
        func_0214cfe4(v3[0], &v3[1], 0x16);
        if (func_0204ff14(func_0202f14c()->mUnk_00, &v3[1]) != 0) {
            v3[11] = 0;
            func_0212426c(1, data_usa_02153d7c[0].mUnk_00, p->mUnk_14, &v3[1], p->mUnk_0c, p->mUnk_18);
            data_02174e58->mUnk_80 = 1;
        }
    }
    func_02031ba4();
    if (data_02174e58->mUnk_148 != 0) {
        data_02174e58->mUnk_14c = data_02174e58->mUnk_14c + 1;
        if (data_02174e58->mUnk_14c > 0x96) {
            func_02108ddc();
            data_02174e58->mUnk_148 = 0;
        }
    }
    switch (data_02174e58->mUnk_94) {
        case 0:
            if (func_02031268() != 0) {
                data_02174e58->mUnk_94 = 1;
            }
            break;
        case 1:
            b1 = 0;
            a1 = 0;
            w = data_02175674[k].mUnk_00;
            if (w == 0 && data_02175680[k].mUnk_00 < 5) {
                a1 = 1;
            }
            if (a1 == 0 && data_0217567c[k].mUnk_00 == 0 && w != 0) {
                b1 = 1;
            }
            if (b1 != 0) {
                v = func_02128210(data_02175670[k].mUnk_00, data_02175672[k].mUnk_00);
            }
            y = data_02174e58->mUnk_90;
            if (y == 0) {
                switch (data_0217aa00->mUnk_0004) {
                    case 7:
                    case 8:
                    case 9:
                    case 10:
                    case 11:
                        x = 1;
                        break;
                    default:
                        x = 0;
                        break;
                }
                if (x != 0) {
                    func_021282c8();
                    func_02025f14(&data_02174e58->mUnk_a0, 2);
                    func_0212d5e0(&data_0217c868);
                    func_0212ecc0(&data_0217d068, 0, 6);
                    func_0212d5e0(&data_0217d0a0);
                    data_02174e58->mUnk_148 = 1;
                    data_02174e58->mUnk_90 = 1;
                    break;
                }
            }
            if (data_02174e58->mUnk_70 == 11) {
                data_0217b488->mUnk_04 = 1;
                data_0217b488->mUnk_08 = 4;
                if (a != 0) {
                    a->mUnk_04 = 1;
                }
                data_02174e58->mUnk_94 = 7;
            } else if (y == 0) {
                if ((u16) (data_02175628[k].mUnk_00 & 2) != 0 || v != 0) {
                    data_02174e58->mUnk_6c = 0;
                    data_02174e58->mUnk_94 = 3;
                    data_02174e58->mUnk_7c = 1;
                    func_02125fc0();
                    func_02128310(0);
                    func_0212d5e0(&data_0217c868);
                    func_0212ecc0(&data_0217d068, 0, 3);
                    func_0212d5e0(&data_0217d0a0);
                }
            }
            break;
        case 5:
            if (func_02125f6c() != 0) {
                func_0212ecc0(&data_0217d068, 0, 0x15);
            }
            if (func_02125f54() != 0) {
                data_02174e58->mUnk_6c = 0;
                data_02174e58->mUnk_94 = 3;
                func_02125fc0();
            }
            break;
        case 3:
            if (data_02174e58->mUnk_70 == 11) {
                func_02025f14(&data_02174e58->mUnk_a0, 2);
                func_02025f14(&data_02174e58->mUnk_b0, 2);
                func_02025f14(&data_02174e58->mUnk_c0, 2);
                data_02174e58->mUnk_94 = 4;
            }
            break;
        case 4:
            if (func_02031250() != 0) {
                data_02174e58->mUnk_94 = 6;
            }
            break;
        case 6:
            v1 = data_02174e58->mUnk_6c;
            break;
    }
    func_02031208();
    return v1;
}

s32 func_02030ea4(Unk02030b18 *a) {
    Unk02174e58_24 *p;
    s32 v1;
    s32 v2;
    u16 k;
    s32 m;
    s32 z;
    u32 b1;
    u32 a1;
    u32 w;
    s32 x;
    s32 y;

    v1 = -1;
    k = func_020435bc();
    p = &data_02174e58->mUnk_24[1];
    v2 = data_02174e58->mUnk_74;
    if (data_02174e58->mUnk_9c > 0) {
        data_02174e58->mUnk_9c = data_02174e58->mUnk_9c - 1;
    }
    func_02031960();
    if (data_02174e58->mUnk_94 != 0 && data_02174e58->mUnk_94 != 3 && data_02174e58->mUnk_94 != 4 &&
        data_02174e58->mUnk_94 != 5 && data_02174e58->mUnk_94 != 6) {
        if (data_0217aa00 == 0) {
            x = 0;
        } else {
            x = data_0217aa00->mUnk_0000;
        }
        if (x == 1) {
            if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
                x = data_0217aa00->mUnk_1699;
            } else {
                x = data_0217aa00->mUnk_0044.mUnk_40;
            }
        } else {
            x = 0;
        }
        data_02174e58->mUnk_74 = x;
        if (data_02174e58->mUnk_74 != v2) {
            func_02031f5c();
            if (data_02174e58->mUnk_74 > v2) {
                func_0212d5e0(&data_0217c868);
                func_0212ecc0(&data_0217d068, 0, 2);
                func_0212d5e0(&data_0217d0a0);
            } else {
                func_0212d5e0(&data_0217c868);
                func_0212ecc0(&data_0217d068, 0, 3);
                func_0212d5e0(&data_0217d0a0);
            }
        }
    }
    func_02031b6c();
    func_02031ba4();
    func_0212b80c();
    if (data_02174e58->mUnk_148 != 0) {
        data_02174e58->mUnk_14c = data_02174e58->mUnk_14c + 1;
        if (data_02174e58->mUnk_14c > 0x96) {
            func_02108ddc();
            data_02174e58->mUnk_148 = 0;
        }
    }
    switch (data_02174e58->mUnk_94) {
        case 0:
            if (func_02031268() != 0) {
                data_02174e58->mUnk_94 = 1;
                p->mUnk_18[0x10].mUnk_00 = 1;
                func_02031b30(1);
            }
            break;
        case 1:
            z = 0;
            m = -1;
            b1 = 0;
            a1 = 0;
            w = data_02175674[k].mUnk_00;
            if (w == 0 && data_02175680[k].mUnk_00 < 5) {
                a1 = 1;
            }
            if (a1 == 0 && data_0217567c[k].mUnk_00 == 0 && w != 0) {
                b1 = 1;
            }
            if (b1 != 0) {
                x = data_02175670[k].mUnk_00;
                y = data_02175672[k].mUnk_00;
                z = func_02128210(x, y);
                m = func_0201ea84(p->mUnk_10, x, y);
            }
            if ((u16) (data_02175628[k].mUnk_00 & 1) != 0 || m == 0) {
                if (data_02174e58->mUnk_74 > 0 && data_02174e58->mUnk_d0.mUnk_00 == 1) {
                    func_02031b30(0);
                    func_021282c8();
                    func_0212b7e8();
                    func_0212d5e0(&data_0217c868);
                    func_0212ecc0(&data_0217d068, 0, 6);
                    func_0212d5e0(&data_0217d0a0);
                    data_02174e58->mUnk_78 = 1;
                    data_02174e58->mUnk_148 = 1;
                    data_02174e58->mUnk_94 = 2;
                    break;
                }
            }
            if ((u16) (data_02175628[k].mUnk_00 & 2) != 0 || z != 0) {
                data_02174e58->mUnk_6c = 1;
                data_02174e58->mUnk_94 = 3;
                data_02174e58->mUnk_7c = 1;
                func_02125fc0();
                func_02128310(0);
                func_0212d5e0(&data_0217c868);
                func_0212ecc0(&data_0217d068, 0, 5);
                func_0212d5e0(&data_0217d0a0);
            }
            break;
        case 2:
            data_02174e58->mUnk_98 = data_02174e58->mUnk_98 + 1;
            if (data_02174e58->mUnk_98 >= 5) {
                func_02031b30(1);
                if (data_02174e58->mUnk_70 == 11) {
                    data_0217b488->mUnk_04 = 1;
                    data_0217b488->mUnk_08 = 4;
                    if (a != 0) {
                        a->mUnk_04 = 1;
                    }
                    data_02174e58->mUnk_98 = 0;
                    data_02174e58->mUnk_94 = 7;
                }
            }
            break;
        case 5:
            if (func_02125f6c() != 0) {
                func_0212ecc0(&data_0217d068, 0, 0x15);
            }
            if (func_02125f54() != 0) {
                func_02125fc0();
                data_02174e58->mUnk_6c = 0;
                data_02174e58->mUnk_94 = 3;
            }
            break;
        case 3:
            if (data_02174e58->mUnk_70 == 11) {
                func_02025f14(&data_02174e58->mUnk_a0, 2);
                func_02025f14(&data_02174e58->mUnk_b0, 2);
                func_02025f14(&data_02174e58->mUnk_c0, 2);
                data_02174e58->mUnk_94 = 4;
            }
            break;
        case 4:
            if (func_02031250() != 0) {
                data_02174e58->mUnk_94 = 6;
            }
            break;
        case 6:
            v1 = data_02174e58->mUnk_6c;
            break;
    }
    func_02031208();
    return v1;
}

#pragma thumb off
