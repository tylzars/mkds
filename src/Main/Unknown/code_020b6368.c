#include "Main/Unknown/code_020b6368.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_020b4dc4.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02061808.h"
#include "Main/Unknown/code_02074874.h"
#include "Main/Unknown/code_02102674.h"
#include "code_02148538.h"

s32 func_020b64e8(void) {
    s32 r = 0;

    switch (func_020b4e5c()) {
        case 1:
        case 11:
        case 14:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 30:
        case 33:
        case 34:
        case 38:
        case 40:
        case 48:
        case 50:
            r = 1;
            break;
    }
    return r;
}

s32 func_020b6430(void) {
    s32 r = 0;

    switch (func_020b4e5c()) {
        case 1:
        case 11:
        case 16:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 34:
        case 40:
        case 48:
        case 50:
            r = 1;
            break;
    }
    return r;
}

// non-matching: the load of data_0217b3c0 is scheduled before the two instructions of the remainder (rsb, add ror)
// instead of after them; the original's order is what this block gets when it is scheduled again after register
// colouring (3 words differ at +0x5c)
u16 func_020b6368(void) {
    u16 r = 0;
    Unk020748a8 *p;
    s32 a;

    switch (func_020b1dbc()) {
        case 1:
            if (func_020b4df8() == 2) {
                p = func_02061808();
            } else {
                p = func_020748a8();
            }
            a = func_02148714(p->mUnk_030[8], p->mUnk_030[2]);
            r = (0x14000 - a) % 0x10000;
            data_0217b3c0->mUnk_8c = 0;
            break;
        case 3:
            a = func_020b5250(func_020b57e4()->mUnk_10);
            r = (a << 16) / 360 + 0x8000;
            break;
        case 2:
        default:
            break;
    }
    return r;
}
