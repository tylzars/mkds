#include "00/code_0219cfc0.h"
#include "00/code_0219d948.h"
#include "00/unk_021b4000.h"
#include "00/code_0218f960.h"
#include "00/code_0218eb9c.h"
#include "00/unk_021b5000.h"
#include "00/code_0219c3e4.h"
#include "00/code_0219c954.h"
#include "00/code_021a3264.h"
#include "Main/Unknown/code_02152000.h"
#include "code_0213a460.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "00/code_0218e8c4.h"
#include "Main/Unknown/code_02152698.h"

u8 func_ov000_0219d9ec(void *a, u8 *b, u8 *c, char *d) {
    u8 e[4];
    Unk0218ec44 f;
    if (func_ov000_0219d094(a, &f) != 0) {
        if (f.mUnk_004 == 6) {
            if (b != NULL) {
                if (func_ov000_021a3530(data_ov000_021b40b0, e, f.mUnk_008, 0x2f) > 0) {
                    *b = strtoul(e, NULL, 10);
                } else {
                    *b = 0;
                }
            }
            if (c != NULL) {
                if (func_ov000_021a3530(data_ov000_021b40b4, e, f.mUnk_008, 0x2f) > 0) {
                    *c = strtoul(e, NULL, 10);
                } else {
                    *c = 0;
                }
            }
        } else {
            if (b != NULL) {
                *b = 0;
            }
            if (c != NULL) {
                *c = 0;
            }
        }
        if (d != NULL) {
            strcpy(d, f.mUnk_108);
        }
        return f.mUnk_004;
    }
    if (b != NULL) {
        *b = 0;
    }
    if (c != NULL) {
        *c = 0;
    }
    return 0;
}

s32 func_ov000_0219d9b0(void *a, s32 b) {
    s32 c;
    s32 i;
    Unk02152490 *d;
    c = 0;
    d = a;
    if (a == NULL) {
        return 0;
    }
    for (i = 0; i < b; i++) {
        if (func_02152698(d) != 0) {
            c++;
        }
        d++;
    }
    return c;
}

void func_ov000_0219d948(void *a) {
    s32 b;
    if (data_ov000_021b5664 != NULL && func_ov000_0219c3e4() != 0 && func_ov000_0219c9c4() != NULL) {
        b = func_02152520((void *) func_ov000_0219c9c4(), a);
        if (b != 0 && b != -1 && func_ov000_0218eb9c(data_ov000_021b5664->mUnk_04, b) != 0) {
            func_ov000_0218eb44(data_ov000_021b5664->mUnk_04, b);
        }
    }
    func_0214d168(a, 0, 12);
}
