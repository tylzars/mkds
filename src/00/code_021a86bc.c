#include "00/code_021a86bc.h"
#include "00/code_021a6fa8.h"

#include "00/code_021a8000.h"
#include "00/code_021a88a8.h"
#include "00/code_021a6d5c.h"
#include "00/code_021a6fb4.h"
#include "00/code_021a7bfc.h"
#include "00/code_021b0014.h"
#include "00/code_021b026c.h"
#include "00/unk_021b6000.h"
#include "00/code_021b0240.h"
#include "00/unk_021b5000.h"
#include "code_0200db4c.h"
#include "code_0200fc8c.h"

s32 func_ov000_021a8830(void) {
    if (data_ov000_021b63b4 == 0) {
        if ((data_ov000_021b5fa0 & 3) == 1) {
            if (func_0200fcf8() != 0x12) {
                func_0200dc3c(10);
            }
        }
    } else if (data_ov000_021b5f9c == 0) {
        data_ov000_021b5f9c = data_ov000_021b63b4;
    }
    return data_ov000_021b63b4;
}

s32 func_ov000_021a87bc(void) {
    s32 a;
    s32 b;
    if (data_ov000_021b5f9c == 0) {
        data_ov000_021b5f9c = data_ov000_021b63b4;
    }
    a = func_ov000_021a86e8();
    b = -0x1a;
    if (a == b) {
        do {
            func_0200dc3c(100);
        } while (func_ov000_021a86e8() == b);
    }
    a = func_ov000_021a70b0();
    if (a >= 0) {
        func_ov000_021b026c();
        func_ov000_021b02b0(NULL);
        if (data_ov000_021b5f94->mUnk_28 == NULL) {
            data_ov000_021b5f94->mUnk_1c(data_ov000_021b5fa8.mUnk_1c);
        }
        data_ov000_021b5f94 = NULL;
    }
    return a;
}

s32 func_ov000_021a8740(void) {
    Unk021a6fa8 *a;
    Unk021a6fa8 *b;
    u32 c;
    for (;;) {
        c = IrqDisable();
        a = data_ov000_021b6004;
        if (a != NULL) {
            b = data_ov000_021b5fa4;
            do {
                if (a != b && (a->mUnk_70 & 0x10) == 0) {
                    break;
                }
                a = a->mNext;
            } while (a != NULL);
        }
        IrqRestore(c);
        if (a == NULL) {
            break;
        }
        func_ov000_021a8604((s32) a);
    }
    if (data_ov000_021b6004 == NULL ||
        (data_ov000_021b6004 == data_ov000_021b5fa4 && data_ov000_021b6004->mNext == NULL)) {
        if (data_ov000_021b6008 == NULL) {
            return 0;
        }
    }
    return -0x1a;
}

s32 func_ov000_021a86e8(void) {
    s32 a;
    func_ov000_021a8740();
    if (data_ov000_021b5fa4 != NULL) {
        a = func_ov000_021a8740();
        if (a == 0) {
            func_ov000_021a8604((s32) data_ov000_021b5fa4);
            if (func_ov000_021a86bc(data_ov000_021b5fa4) != 0) {
                data_ov000_021b5fa4 = NULL;
            }
            a = -0x1a;
        }
        func_ov000_021a8424();
    } else {
        if (func_ov000_021b02bc() != 0) {
            a = 0;
        } else {
            a = -0x1a;
        }
    }
    return a;
}

u32 func_ov000_021a86bc(Unk021a6fa8 *a) {
    int v1;
    if (((0 <= (s32) a) && (v1 = func_ov000_021a8a80(), v1 != 0)) &&
        (v1 = func_ov000_021a8a5c((Unk021a8ab8 *) a), v1 == 0)) {
        return 1;
    }
    return 0;
}
