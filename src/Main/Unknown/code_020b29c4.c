#include "Main/Unknown/code_020b29c4.h"
#include "Main/Unknown/code_02055000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020b252c.h"
#include "Main/Unknown/code_020b2a4c.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020b33d8.h"

#pragma thumb on
#pragma optimize_for_size on
u32 func_020b29c4(void) {
    u32 a = 0;
    u32 b = 0;
    u32 c = 0;
    u32 d;

    if (func_020b33d8() != 0 && func_020b33f4() > 0xf0 && func_020b2a4c() == 0 &&
        (func_020b252c() != 2 || func_020a126c() == 0)) {
        d = 1;
        if (func_020b252c() == 4) {
            if ((func_020b252c() == 4 ? func_020a126c() : 0) != 0) {
                d = 0;
            }
        }
        if (d != 0) {
            c = 1;
        }
    }
    if (c != 0) {
        if (func_020b252c() != 5) {
            b = 1;
        }
    }
    if (b != 0) {
        if (func_020b2ec0() != 0 || func_02055b1c() == 0) {
            a = 1;
        }
    }
    return a;
}
#pragma thumb off
