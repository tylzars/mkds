#include "01/code_021900ac.h"
#include "01/code_02190000.h"
#include "01/code_02191000.h"
#include "01/code_02192000.h"
#include "01/code_02181b54.h"
#include "01/code_02187000.h"
#include "01/code_02188000.h"
#include "01/code_02188158.h"
#include "01/code_02188218.h"
#include "01/code_02190fc4.h"
#include "01/code_02191b40.h"
#include "01/code_02191e1c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"

void func_ov001_02190948(Unk02188950 *param_1) {
    Unk0206bcb0 *r4;
    Unk02188950 *a;
    Unk02188950 *b;

    if (func_ov001_0218820c(param_1)) {
        r4 = func_0207a974((u16) data_021759c0->mUnk_62);
        func_ov001_02187218(param_1, 3, func_ov001_02190a20);
        func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_2c4, 0x270f000);
        func_ov001_02188998(param_1, &r4->mUnk_80);
        if (data_021759c0->mUnk_08 == 4) {
            a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
        } else {
            a = 0;
        }
        if (data_021759c0->mUnk_08 == 4) {
            b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
        } else {
            b = 0;
        }
        if (param_1->mUnk_0a8 == 4) {
            func_ov001_02191c14(a);
            func_ov001_021920dc(b);
        } else {
            func_ov001_021920dc(a);
            func_ov001_02191c14(b);
        }
    } else {
        func_ov001_02190acc(param_1);
    }
}

int func_ov001_021908a8(Unk02188950 *param_1) {
    Unk0206bcb0 *r4;
    Unk02188950 *a;
    Unk02188950 *b;

    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    r4 = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02188998(param_1, &r4->mUnk_80);
    func_ov001_021924cc();
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        func_ov001_02188218(param_1, 4);
        func_ov001_02190948(param_1);
    }
    return 0;
}

void func_ov001_0219081c(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 3, func_ov001_021908a8);
    func_ov001_02188c90(param_1);
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    func_ov001_02191b40(a);
    func_ov001_02191b40(b);
}

int func_ov001_0219079c(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    func_ov001_02192694();
    func_ov001_021924cc();
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        func_ov001_02188e88(param_1);
    }
    return 0;
}

int func_ov001_02190688(Unk02188950 *param_1) {
    Unk0206bcb0 *r4;
    Unk02188950 *a;
    Unk02188950 *b;

    r4 = func_0207a974((u16) data_021759c0->mUnk_62);
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    if (param_1->mUnk_0a8 == 4) {
        if (func_ov001_021871f8(a, 3)) {
            param_1->mUnk_0a8 = 5;
            func_ov001_02187218(param_1, 3, func_ov001_0219079c);
            func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_2c4, 0x270f000);
            func_ov001_02188998(param_1, &r4->mUnk_80);
            func_ov001_02191ecc(a);
            func_ov001_02191f70(b);
        }
    } else if (func_ov001_021871f8(b, 3)) {
        param_1->mUnk_0a8 = 4;
        func_ov001_02187218(param_1, 3, func_ov001_0219079c);
        func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_2c4, 0x270f000);
        func_ov001_02188998(param_1, &r4->mUnk_80);
        func_ov001_02191f70(a);
        func_ov001_02191ecc(b);
    }
    return 0;
}

void func_ov001_021905f8(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_ov001_02187218(param_1, 3, func_ov001_02190688);
    func_ov001_02188c90(param_1);
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    if (param_1->mUnk_0a8 == 4) {
        func_ov001_02191318(a);
        func_ov001_02191e1c(b);
    } else {
        func_ov001_02191e1c(a);
        func_ov001_02191318(b);
    }
}

int func_ov001_0219052c(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    func_ov001_02192694();
    func_ov001_021924cc();
    if (func_ov001_021881a8(param_1, &param_1->mUnk_188, 0, (s32) (param_1->mUnk_0a0->mUnk_2bc)) &&
        func_ov001_021881a8(a, &a->mUnk_1ac, (s32) (param_1->mUnk_0a0->mUnk_2c0), 0) &&
        func_ov001_021881a8(b, &b->mUnk_1ac, (s32) (param_1->mUnk_0a0->mUnk_2c0), 0)) {
        func_ov001_021905f8(param_1);
    }
    return 0;
}

void func_ov001_02190468(Unk02188950 *param_1) {
    Unk0206bcb0 *r4;
    Unk02188950 *a;
    Unk02188950 *b;

    r4 = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 3, func_ov001_0219052c);
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_2c4, 0x270f000);
    func_ov001_02188998(param_1, &r4->mUnk_80);
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    if (param_1->mUnk_0a8 == 4) {
        func_ov001_02192174(a);
        func_ov001_021920dc(b);
    } else {
        func_ov001_021920dc(a);
        func_ov001_02192174(b);
    }
}

int func_ov001_021903e0(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_0207a974((u16) data_021759c0->mUnk_62);
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        func_ov001_02188e88(param_1);
    }
    return 0;
}

void func_ov001_02190328(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 3, func_ov001_021903e0);
    func_ov001_02188c90(param_1);
    param_1->mUnk_0a8 = (param_1->mUnk_0a8 == 5) ? 4 : 5;
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    if (param_1->mUnk_0a8 == 4) {
        func_ov001_02191bc0(a);
        func_ov001_02191e1c(b);
    } else {
        func_ov001_02191e1c(a);
        func_ov001_02191bc0(b);
    }
}

void func_ov001_02190270(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 3, func_ov001_021903e0);
    func_ov001_02188c90(param_1);
    param_1->mUnk_0a8 = (param_1->mUnk_0a8 == 5) ? 4 : 5;
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    if (param_1->mUnk_0a8 == 4) {
        func_ov001_02191e90(a);
        func_ov001_02191b40(b);
    } else {
        func_ov001_02191b40(a);
        func_ov001_02191e90(b);
    }
}

void func_ov001_02190248(Unk02188950 *param_1) {
    func_ov001_02188218(param_1, (s32) ((u16) param_1->mUnk_0a0->mUnk_1ec));
    func_ov001_02190c08(param_1);
}

int func_ov001_02190168(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        if (func_ov001_02188220((Unk02188950 *) ((
                data_021759c0->mUnk_08 == 4
                    ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2))
                    : 0))) == 1) {
            func_ov001_02190270(param_1);
        } else if (func_ov001_02188220((Unk02188950 *) ((
                       data_021759c0->mUnk_08 == 4
                           ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2))
                           : 0))) == 2) {
            func_ov001_02190248(param_1);
        } else {
            func_ov001_02188e88(param_1);
        }
    }
    return 0;
}

void func_ov001_021900ac(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_ov001_02187218(param_1, 3, func_ov001_02190168);
    func_ov001_02188c90(param_1);
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    if (func_ov001_02188220((Unk02188950 *) ((
            data_021759c0->mUnk_08 == 4
                ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2))
                : 0))) >= 2) {
        func_ov001_02190fc4(a);
        func_ov001_02190fc4(b);
    } else {
        func_ov001_02191064(a);
        func_ov001_02191064(b);
    }
}
