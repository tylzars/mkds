#include "Main/Unknown/code_02035db4.h"
#include "Main/Unknown/code_0205905c.h"
#include "Main/Unknown/code_02035e44.h"
#include "Main/Unknown/code_02035e38.h"
#include "Main/Unknown/code_02035e30.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

s32 func_02035db4(u32 a) {
    s32 r;
    Unk02174e6c *o;

    switch (data_02174e6c->mUnk_64c) {
        case 9:
            r = func_020591bc();
            switch (r) {
                case 1:
                    if (func_02035e44() != 0) {
                        func_02035e38();
                    }
                    data_02174e6c->mUnk_64c = 10;
                    break;
                case 2:
                    break;
            }
            break;
        case 10:
            if (a != 0) {
                func_02035e30(a, 1);
            }
            data_02174e6c->mUnk_64c = 11;
            break;
    }
    o = data_02174e6c;
    o->mUnk_640 = (o->mUnk_640 + 1) % 0x100;
    return -1;
}

#pragma thumb off
