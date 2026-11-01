#include "01/code_0218df20.h"
#include "01/code_02181820.h"
#include "01/code_02181b54.h"
#include "01/code_021827f0.h"
#include "01/code_02187098.h"
#include "01/code_02187e78.h"
#include "01/code_02187eb0.h"
#include "01/code_02188158.h"
#include "01/code_02188484.h"
#include "01/code_021864ac.h"
#include "01/code_0218e344.h"
#include "01/code_0218e594.h"
#include "01/code_0218e5c4.h"
#include "01/code_0218e690.h"
#include "01/code_0218eb94.h"
#include "01/code_0218edc8.h"
#include "01/code_0218f900.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2300.h"
#include "Main/Unknown/code_02062eb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_02181000.h"
#include "01/code_0218e000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02110000.h"
#include "Main/Unknown/code_020a128c.h"

void func_ov001_0218e298(Unk02188950 *param_1, Unk0206bcb0 *param_2) {
    func_ov001_02182bbc((u16) param_1->mUnk_0a0->mUnk_110);
    param_1->mUnk_000.mUnk_10.x = 0;
    param_1->mUnk_000.mUnk_10.y = param_1->mUnk_0a0->mUnk_114;
    param_1->mUnk_000.mUnk_10.z = 0;
    param_1->mUnk_2d8 = 0xc;
    param_1->mUnk_158 = func_ov001_0218f3ec;
    func_ov001_02188200(param_1, func_ov001_0218f9a8);
    func_02073fb0(param_1->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
    func_02068a10(param_2);
    func_ov001_021888a4(param_1, 0, 0x32000);
    param_1->mUnk_0a8 = 1;
    if (!(data_021759c0->mUnk_08 == 4 ? func_020a126c() : 0)) {
        func_02061874();
    }
}

void func_ov001_0218e208(Unk0218d87c *param_1) {
    s32 i;
    Unk02188950 *obj;
    Unk02188950_a0 *a0;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (obj = param_1->mUnk_00[i]) != 0; i++) {
            if (func_02062ec4() != 0) {
                func_ov001_0218e4ac(obj);
            } else {
                func_ov001_0218e520(obj);
            }
            if (data_021759c0->mUnk_08 == 4) {
                a0 = obj->mUnk_0a0;
                func_ov001_02181844(a0->mUnk_1b8, a0->mUnk_1bc, a0->mUnk_1c0, a0->mUnk_1c4);
            }
        }
    }
    func_020a2314((void (*)(void)) func_ov001_0218e58c);
}

void func_ov001_0218df20(u32 param_1, Unk02188950 *param_2) {
    Unk0206bcb0 *p;

    if (data_021759c0->mUnk_08 == 4 ? func_020a126c() : 0) {
        if (func_ov001_021871f8(param_2, 5) != 0) {
            if (data_021759c0->mUnk_08 == 4 ? func_020a1084((u16) data_021759c0->mUnk_62) : 0) {
                func_ov001_0218e710(param_2);
            } else if (data_021759c0->mUnk_08 == 4 ? func_020a128c() : 0) {
                func_ov001_0218e5c4(param_2);
            } else {
                func_ov001_0218e594(param_2);
            }
        }
    } else {
        if (param_2->mUnk_0a8 != 0) {
            if (func_ov001_021871f8(param_2, 5) != 0) {
                p = func_0207a974((u16) data_021759c0->mUnk_62);
                if (p->mUnk_180 == 0 && (p->mUnk_48 & 0x200) == 0 &&
                    func_ov001_02188104(param_2, 0, param_2->mUnk_0a0->mUnk_184) != 0 &&
                    func_ov001_02188000(param_2, 0, param_2->mUnk_0a0->mUnk_180) != 0 &&
                    func_ov001_02188104(param_2, param_2->mUnk_0a0->mUnk_188, 0) != 0) {
                    func_ov001_0218e8d8(param_2);
                }
            }
            if (func_ov001_021871f8(param_2, 3) != 0) {
                if (func_ov001_021881a8(param_2, (Vec3 *) func_ov001_02187fc0(param_2),
                                        (s32) (param_2->mUnk_0a0->mUnk_138), 0) != 0) {
                    func_ov001_02187e78(param_2);
                }
                func_ov001_02188200(param_2, func_ov001_0218e344);
                param_2->mUnk_000.mUnk_02 &= ~0x40;
                func_ov001_02182a3c(0);
                func_ov001_0218ec40(param_2);
            }
        } else {
            p = func_0207a974((u16) data_021759c0->mUnk_62);
            if (p->mUnk_48 & 0x200) {
                if (data_021759c0->mUnk_08 == 4 ? func_ov001_02181820() : 0) {
                    if (data_021759c0->mUnk_08 == 4) {
                        func_ov001_0218182c((u16) param_2->mUnk_0a0->mUnk_1bc);
                    }
                } else {
                    if (data_021759c0->mUnk_08 == 4) {
                        func_ov001_0218182c(0);
                    }
                }
                if ((param_2->mUnk_000.mUnk_02 & 1) == 0) {
                    func_ov001_02188200(param_2, func_ov001_0218f9a8);
                    param_2->mUnk_000.mUnk_02 |= data_ov001_021a65b0;
                    func_ov001_0218e7d0(param_2);
                }
            }
            if (data_021759c0->mUnk_08 == 4 ? func_ov001_02181838() : 0) {
                if (func_ov001_021871f8(param_2, 3) != 0) {
                    if ((s32) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181838() : 0) < param_2->mUnk_0a0->mUnk_1c8) {
                        if (param_2->mUnk_000.mUnk_02 & 1) {
                            func_ov001_02188200(param_2, func_ov001_0218f9a8);
                            param_2->mUnk_000.mUnk_02 |= data_ov001_021a65b0;
                            func_ov001_0218ee88(param_2);
                        } else {
                            func_ov001_02188200(param_2, func_ov001_0218f9a8);
                            param_2->mUnk_000.mUnk_02 |= data_ov001_021a65b0;
                            func_ov001_0218ef30(param_2);
                        }
                    } else if ((param_2->mUnk_000.mUnk_02 & 1) == 0) {
                        func_ov001_02188200(param_2, func_ov001_0218f9a8);
                        param_2->mUnk_000.mUnk_02 |= data_ov001_021a65b0;
                        func_ov001_0218e7d0(param_2);
                    }
                }
            }
        }
        if (data_0217d20c == 0) {
            func_02110350(param_2->mUnk_000.mUnk_94);
        } else if (func_02110324() != 0) {
            func_020d275c(&param_2->mUnk_000, (u32) (0x22a));
        } else if (data_0217d20c == 4) {
            func_020d275c(&param_2->mUnk_000, (u32) (0x22b));
        }
    }
    func_ov001_021864ac(param_1, param_2);
}
