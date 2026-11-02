#include "00/code_02193634.h"
#include "00/code_021947e4.h"
#include "00/code_02196914.h"
#include "00/code_021965a0.h"
#include "00/code_021a3690.h"
#include "00/code_02196590.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "code_02135014.h"
#include "code_02139f70.h"
#include "code_02134d30.h"
#include "code_0213a460.h"
#include "00/code_021919ac.h"
#include "00/code_02193818.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_021967b4.h"
#include "00/code_02191200.h"
#include "00/code_02196240.h"

#include "00/code_02190ba0.h"
#include "00/code_02192d64.h"
#include "00/code_02196000.h"
#include "00/unk_021b3000.h"

BOOL func_ov000_021937e8(Unk0218f960 *object, Unk021937c0Node **output, u32 key) {
    Unk021937c0Node *node = object->mUnk_00->mUnk_424;
    while (node != NULL) {
        if (node->mUnk_18 == key) {
            if (output != NULL) {
                *output = node;
            }
            return TRUE;
        }
        node = node->mNext;
    }
    if (output != NULL) {
        *output = NULL;
    }
    return FALSE;
}

BOOL func_ov000_021937c0(Unk0218f960 *object) {
    Unk021937c0Node *node = object->mUnk_00->mUnk_424;
    while (node != NULL) {
        if (node->mUnk_08 != 0 && node->mUnk_00 != 3) {
            return TRUE;
        }
        node = node->mNext;
    }
    return FALSE;
}

s32 func_ov000_02193748(Unk0218f960 *c, Unk021937c0Node *d, const u8 *e) {
    s32 a = 0;
    u32 b = d->mUnk_00;

    switch (b) {
        case 0:
            a = func_ov000_02191284(c, d, e);
            break;
        case 1:
            a = func_ov000_02194a0c(c, d, e);
            break;
        case 2:
            a = func_ov000_02192e04(c, d, e);
            break;
        case 4:
            a = func_ov000_021964e4(c, d, e);
            break;
        default:
            func_ov000_0219690c(c, data_ov000_021b3264, b);
            func_0213442c(data_ov000_021b32ac, data_ov000_021b32b0, NULL, 0x146);
            break;
    }
    if (a != 0) {
        d->mUnk_1c = a;
    }
    return a;
}

u32 func_ov000_02193634(int a, int b, int c) {
    if (a == 0 && b == 0 && c == 0) {
        return 1;
    }
    if (a < 0 || b < 0 || c < 0) {
        return 0;
    }
    switch (b) {
        case 0:
            if (a != 0) {
                return 0;
            }
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (a > 0x1f) {
                return 0;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (a > 0x1e) {
                return 0;
            }
            break;
        case 2:
            if ((c % 4 == 0 && c % 100 != 0) || c % 400 == 0) {
                if (a > 0x1d) {
                    return 0;
                }
            } else if (a > 0x1c) {
                return 0;
            }
            break;
        default:
            return 0;
    }
    if (c < 0x76c) {
        return 0;
    }
    if (c > 0x81f) {
        return 0;
    }
    if (c == 0x81f) {
        if (b > 6) {
            return 0;
        }
        if (b == 6 && a > 6) {
            return 0;
        }
    }
    return 1;
}
