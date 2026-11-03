#include "Main/Unknown/code_02077f5c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "code_02012b30.h"
#include "00/code_02182fdc.h"
#include "01/code_021a2398.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02077eb4.h"
#include "Main/Unknown/code_02078580.h"
#include "Main/Unknown/code_020799a0.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "code_02013740.h"
#include "code_0214c1bc.h"

#pragma thumb on

void func_02077f5c(void) {
    data_0217ad08->mUnk_1dc = 1;
    data_0217ad08->mUnk_1f0 = 0;
}

Unk0217ad00_014 *func_02077f7c(int param_1) {
    Unk0217ad00_014 *r = NULL;
    if (gKartModels->mUnk_014 != NULL) {
        r = gKartModels->mUnk_014 + gKartModels->mUnk_018[param_1];
    }
    return r;
}

void func_02077f9c(int param_1, struct Unk0206bcb0_590 *param_2, u8 *param_3) {
    Unk0201290c *e;
    u8 *t;
    u8 *u;
    u8 *w;
    s32 k;
    s32 h;
    e = param_2->mUnk_010[0]->mUnk_04;
    func_0200ee74(param_3, 0x20);
    if (func_020799a0(param_1) != 0) {
        k = func_02013754((u8 *) e + e->mUnk_08 + 4, data_usa_02154ff8);
    } else {
        k = func_02013754((u8 *) e + e->mUnk_08 + 4, data_usa_02155068);
    }
    t = (u8 *) e + e->mUnk_08;
    u = t + 4;
    w = u + *(u16 *) (t + 0xa);
    h = ((Unk0201290c_08 *) (t + *(u32 *) (w + *(u16 *) w * k + 4)))->mUnk_1c << 4;
    func_0214c48c();
    func_0214c418(param_3, h, 0x20);
    func_0214c3c0();
}

void func_0207800c(void) {
    u32 i;
    if (gKartModels->mUnk_014 != NULL) {
        func_02078078();
        for (i = 0; i < data_021759c0->mUnk_3d0; i = (u16) (i + 1)) {
            if (gKartModels->mUnk_000[i].mUnk_000 == 0xc) {
                func_02077f9c(i, &gKartModels->mUnk_000[i], (u8 *) func_02077f7c(i));
            }
        }
    }
}

void func_02078078(void) {
    u16 i;
    for (i = 0; i < 8; i++) {
        gKartModels->mUnk_018[i] = data_0217b488->mUnk_10c[i];
    }
}

void func_020780b0(void) {
    Unk0217ad08_058 *p;
    if (data_0217ad08->mUnk_264 >= 0) {
        p = &data_0217ad08->mUnk_058[data_0217ad08->mUnk_264];
        func_020787f4(0, data_usa_021656ec);
        func_02078580(p, &data_0217ad08->mUnk_024, 0);
        func_01ff9234();
    }
}

void func_020780f4(void) {
    Unk0217ad08_058 *p;
    Unk0217ad08_024 *q;
    if (data_0217ad08->mUnk_264 >= 0) {
        p = &data_0217ad08->mUnk_058[data_0217ad08->mUnk_264];
        q = &data_0217ad08->mUnk_024;
        if (q->mUnk_00 != -1 && q->mUnk_04 != -1) {
            func_020787f4(q->mUnk_2c, data_usa_021656ec);
            func_02078580(p, &data_0217ad08->mUnk_024, data_0217ad08->mUnk_1e4);
            func_01ff9234();
        }
    }
}

void func_02078158(void) {
    Unk0217ad08_024 *q = &data_0217ad08->mUnk_024;
    s32 a = 0;
    BOOL b;
    s32 d;
    s32 w;
    u16 k;
    Unk02175628Index v1;
    s32 v = 2;
    Unk0217ad08_1f4 *p;

    p = &data_0217ad08->mUnk_1f4[data_0217ad08->mUnk_266];
    if (data_0217aa0c->mUnk_f8 == 0 && p->mUnk_2c == 0) {
        w = ~a;
        v1 = UNK_02175628_INDEX_8;
        k = data_02175628[v1].mUnk_00;
        if ((u16) (k & 0x100) != 0) {
            d = a;
            do {
                data_0217ad08->mUnk_000++;
                if (data_0217ad08->mUnk_000 > 0x23) {
                    data_0217ad08->mUnk_000 = a;
                }
                if (func_02077a70(&w, data_0217ad08->mUnk_000) != 0) {
                    func_02078a9c(w);
                    func_02078a34(data_0217ad08->mUnk_000);
                    d = 1;
                    func_0212ecc0(&data_0217d068, a, 0x1fd);
                }
            } while (d == 0);
            data_0217ad08->mUnk_004++;
            if (data_0217ad08->mUnk_004 >= data_0217ad08->mUnk_008) {
                data_0217ad08->mUnk_004 = 0;
            }
        } else if ((u16) (k & 0x200) != 0) {
            d = a;
            do {
                data_0217ad08->mUnk_000--;
                if (data_0217ad08->mUnk_000 < 0) {
                    data_0217ad08->mUnk_000 = 0x23;
                }
                if (func_02077a70(&w, data_0217ad08->mUnk_000) != 0) {
                    func_02078a9c(w);
                    func_02078a34(data_0217ad08->mUnk_000);
                    d = 1;
                    func_0212ecc0(&data_0217d068, a, 0x1fe);
                }
            } while (d == 0);
            data_0217ad08->mUnk_004--;
            if (data_0217ad08->mUnk_004 < 0) {
                data_0217ad08->mUnk_004 = data_0217ad08->mUnk_008 - 1;
            }
        }
    }
    b = FALSE;
    d = b;
    func_02108e6c(2);
    v1 = UNK_02175628_INDEX_8;
    k = data_02175628[v1].mUnk_02;
    if ((u16) (k & 0x10) != 0) {
        q->mUnk_16 += 0x1c2;
        b = TRUE;
    } else if ((u16) (k & 0x20) != 0) {
        q->mUnk_16 -= 0x1c2;
        b = TRUE;
    }
    v1 = UNK_02175628_INDEX_8;
    k = data_02175628[v1].mUnk_02;
    if ((u16) (k & 0x80) != 0) {
        q->mUnk_18 += 0x1c2;
        if (q->mUnk_18 > 0x1b58) {
            q->mUnk_18 = 0x1b58;
        } else {
            d = 1;
        }
    } else if ((u16) (k & 0x40) != 0) {
        q->mUnk_18 -= 0x1c2;
        if (q->mUnk_18 < -0x1388) {
            q->mUnk_18 = -0x1388;
        } else {
            d = 1;
        }
    }
    if (d != 0 || b != FALSE) {
        a = 1;
    }
    func_02108e6c(1);
    v1 = UNK_02175628_INDEX_8;
    k = data_02175628[v1].mUnk_02;
    if ((u16) (k & 0x400) != 0) {
        q->mUnk_08 += 0x7b;
        if (q->mUnk_08 > data_usa_021656e0) {
            q->mUnk_08 = data_usa_021656e0;
        } else {
            v = 0;
        }
    } else {
        v1 = UNK_02175628_INDEX_8;
        k = data_02175628[v1].mUnk_02;
        if ((u16) (k & 2) != 0) {
            q->mUnk_08 -= 0x7b;
            if (q->mUnk_08 < 0x800) {
                q->mUnk_08 = 0x800;
            } else {
                v = 1;
            }
        }
    }
    q->mUnk_1a = q->mUnk_18;
    func_02110aac(v, a);
    func_02077b3c();
    func_02077b1c();
}

void func_020783c8(void) {
    s16 i = data_0217ad08->mUnk_264;
    if (i >= 0) {
        func_02087de0(data_0217ad08->mUnk_058[i].mUnk_08);
        if (data_0217ad08->mUnk_1f4[data_0217ad08->mUnk_266].mUnk_2c == 0) {
            func_02078e4c(func_ov001_021a2398(), func_ov001_021a23ac());
        }
    }
}

void func_02078420(s32 param_1) {
    Unk0217ad08_024 *q;
    Unk0217ad08_058 *e;
    q = &data_0217ad08->mUnk_024;
    data_0217ad08->mUnk_1e4 = param_1;
    func_02077b3c();
    func_020789f4();
    if (data_0217ad08->mUnk_264 >= 0) {
        e = &data_0217ad08->mUnk_058[data_0217ad08->mUnk_264];
        if (data_0217ad08->mUnk_1d8 != NULL || data_0217ad08->mUnk_1dc != 0) {
            func_02077f0c(&q->mUnk_14, 0xeaab, data_usa_021656e8);
            if (data_0217ad08->mUnk_1d8 == NULL && data_0217ad08->mUnk_1dc != 0) {
                data_0217ad08->mUnk_1f0++;
                if (data_0217ad08->mUnk_1f0 > 0x3c) {
                    data_0217ad08->mUnk_1dc = 0;
                }
            }
        } else {
            q->mUnk_14 += 0x64;
        }
        q->mUnk_16 = param_1 != 0 ? (u16) -q->mUnk_14 : q->mUnk_14;
        func_02087de0(e->mUnk_08);
        if (data_0217ad08->mUnk_1e8 != NULL && data_0217ad08->mUnk_1ec != NULL &&
            data_0217ad08->mUnk_1f4[data_0217ad08->mUnk_266].mUnk_2c == 0) {
            func_02078e4c(data_0217ad08->mUnk_1e8, data_0217ad08->mUnk_1ec);
        }
    }
    func_02077b1c();
}

#pragma thumb off
