#include "01/code_021827f0.h"
#include "code_0212c6ac.h"
#include "01/code_02181000.h"
#include "01/code_02182000.h"
#include "01/code_02183000.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02108000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"

void func_ov001_02182bbc(u32 param_1) {
    if (data_021759c0->mUnk_08 == 4) {
        func_ov001_02181660(param_1);
    }
}

void func_ov001_02182a3c(s32 param_1) {
    int i;
    s32 n;
    Unk02181c3c_list *list;
    Unk02181c3c *p;
    Unk020f41c4_B *rng;
    u16 r;
    int k;

    n = 0;
    list = func_02100138(0x68);
    func_0207a974((u16) data_021759c0->mUnk_62);
    if (list != 0) {
        for (i = 0; i < list->mUnk_04 && (p = list->mUnk_00[i]) != 0; i++) {
            if (p->mUnk_0f8 == 7) {
                n++;
                if (n <= param_1) {
                    if (p->mUnk_0e8 == 0) {
                        rng = func_020d22d0();
                        rng->mUnk_00 = (s64) rng->mUnk_08 * (s64) rng->mUnk_00 + rng->mUnk_10;
                        r = ((u64) (u32) (rng->mUnk_00 >> 32) * 0x10000) >> 32;
                        p->mUnk_0b0 = 0x1000;
                        p->mUnk_0a0 = 0;
                        p->mUnk_0e8 = (Vec3 *) ((data_021759c0->mUnk_08 == 4
                                                     ? (u32) func_ov001_02181b68(
                                                           data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)
                                                     : 0) +
                                                4);
                        p->mUnk_000.mUnk_04.x = p->mUnk_0e8->x;
                        p->mUnk_000.mUnk_04.y = p->mUnk_0e8->y;
                        p->mUnk_000.mUnk_04.z = p->mUnk_0e8->z;
                        p->mUnk_000.mUnk_10.x = 0;
                        p->mUnk_000.mUnk_10.y = 0x4cd;
                        p->mUnk_000.mUnk_10.z = 0;
                        k = (r >> 4) * 2;
                        p->mUnk_0ec.x = ((s64) data_0215d4b4[k] * 0x14000) >> 12;
                        p->mUnk_0ec.y = -0xa000;
                        p->mUnk_0ec.z = ((s64) data_0215d4b4[k + 1] * 0x14000) >> 12;
                    }
                } else {
                    if (p->mUnk_0e8 != 0) {
                        p->mUnk_0e8 = 0;
                    }
                }
            }
        }
    }
}

void func_ov001_021829ac(s32 param_1) {
    Unk02181c3c_list *list;
    Unk02181c3c *p;
    s32 n;
    int i;

    n = 0;
    list = func_02100138(0x68);
    func_0207a974((u16) data_021759c0->mUnk_62);
    if (list != 0) {
        for (i = 0; i < list->mUnk_04 && (p = list->mUnk_00[i]) != 0; i++) {
            if (p->mUnk_0f8 == 7) {
                if (p->mUnk_0e8 != 0) {
                    p->mUnk_0e8 = 0;
                }
                n++;
                if (n <= param_1) {
                    if ((p->mUnk_000.mUnk_02 & 0x100) == 0) {
                        func_020d2398(&p->mUnk_000);
                    }
                    if (data_021759c0->mUnk_08 == 4) {
                        func_ov001_0218155c(1);
                    }
                }
            }
        }
    }
}

void func_ov001_021828f0(void) {
    int i;
    Unk02181c3c *p;
    Unk02181c3c_list *list;
    u32 *q;

    list = func_02100138(0x68);
    if (list != 0) {
        for (i = 0; i < list->mUnk_04 && (p = list->mUnk_00[i]) != 0; i++) {
            if (p->mUnk_0f8 == 0 && (p->mUnk_000.mUnk_02 & 0x100) == 0) {
                p->mUnk_000.mUnk_10.y = 0x5000;
                p->mUnk_0a0 = 0x32;
                p->mUnk_0f8 = 8;
                p->mUnk_000.mUnk_02 |= data_ov001_021a6574;
            }
        }
    }
    q = (u32 *) func_02108e6c(2);
    if ((data_0217c780 & 1) && data_0217d084.mUnk_0c != 0) {
        if (*q != 0) {
            func_0212c6f0((Unk0212c400 **) q, 0);
        }
        if (*q != 0) {
            func_0212c6f0((Unk0212c400 **) q, 0);
        }
        func_0212ecc0(q, 0, 0x233);
    }
}

void func_ov001_021827f0(void) {
    int i;
    Unk02181c3c *p;
    Unk02181c3c_list *list;
    u32 *q;

    list = func_02100138(0x68);
    if (list != 0) {
        for (i = 0; i < list->mUnk_04 && (p = list->mUnk_00[i]) != 0; i++) {
            if (p->mUnk_0f8 == 9 && (p->mUnk_000.mUnk_02 & 0x100) == 0) {
                p->mUnk_000.mUnk_04.x = p->mUnk_000.mUnk_9c->mUnk_00.x;
                p->mUnk_000.mUnk_04.y = p->mUnk_000.mUnk_9c->mUnk_00.y + 0xa000;
                p->mUnk_000.mUnk_04.z = p->mUnk_000.mUnk_9c->mUnk_00.z;
                p->mUnk_000.mUnk_10.x = 0;
                p->mUnk_000.mUnk_10.y = 0x5000;
                p->mUnk_000.mUnk_10.z = 0;
                p->mUnk_0e4 = p->mUnk_000.mUnk_9c->mUnk_00.y + 0xe000;
                p->mUnk_0f8 = 2;
                p->mUnk_0b0 = 0x1000;
                p->mUnk_0a0 = 0;
                p->mUnk_000.mUnk_02 &= ~1;
            }
        }
    }
    q = (u32 *) func_02108e6c(2);
    if ((data_0217c780 & 1) && data_0217d084.mUnk_0c != 0) {
        if (*q != 0) {
            func_0212c6f0((Unk0212c400 **) q, 0);
        }
        if (*q != 0) {
            func_0212c6f0((Unk0212c400 **) q, 0);
        }
        func_0212ecc0(q, 0, 0x232);
    }
}
