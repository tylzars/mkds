#include "Main/Unknown/code_02035e44.h"
#include "Main/Unknown/code_02035db4.h"
#include "Main/Unknown/code_02035e30.h"
#include "Main/Unknown/code_02035e38.h"
#include "Main/Unknown/code_02036044.h"
#include "Main/Unknown/code_0203606c.h"
#include "Main/Unknown/code_020360e4.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_0205905c.h"
#include "Main/Unknown/code_02058b38.h"
#include "Main/Unknown/code_02058f20.h"
#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_0205e2cc.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_0217a000.h"

u32 func_02035e44(void) {
    return data_0217aa00->mUnk_0457 != 0;
}

#pragma thumb on

s32 func_02035e64(u32 a) {
    s32 r;
    Unk02174e6c *o;

    switch (data_02174e6c->mUnk_64c) {
        case 9:
            r = func_02058f20();
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
                func_02035e30(a, 10);
            }
            data_02174e6c->mUnk_64c = 11;
            break;
    }
    o = data_02174e6c;
    o->mUnk_640 = (o->mUnk_640 + 1) % 0x100;
    return -1;
}

s32 func_02035ee0(u32 a) {
    s32 r;
    Unk02174e6c *o;

    switch (data_02174e6c->mUnk_64c) {
        case 9:
            r = func_020591c4();
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
                func_02035e30(a, 2);
            }
            data_02174e6c->mUnk_64c = 11;
            break;
    }
    o = data_02174e6c;
    o->mUnk_640 = (o->mUnk_640 + 1) % 0x100;
    return -1;
}

s32 func_02035f5c(u32 a) {
    s32 r;
    Unk02174e6c *o;

    switch (data_02174e6c->mUnk_64c) {
        case 0:
            if (func_0205579c(0, 1) == 1) {
                data_02174e6c->mUnk_64c = 2;
            }
            break;
        case 2:
            r = func_02055730(0);
            switch (r) {
                case 1:
                    func_0204aa28(func_020360e4());
                    data_02174e6c->mUnk_64c = 4;
                    break;
                case 2:
                    break;
            }
            break;
        case 4:
            r = func_02058cac();
            switch (r) {
                case 1:
                    if (func_02035e44() != 0) {
                        func_02035e38();
                    }
                    func_0205e5c4(1);
                    data_02174e6c->mUnk_64c = 6;
                    break;
                case 2:
                    break;
            }
            break;
        case 6:
            if (func_0203606c() == 0) {
                func_02036058(1);
                func_02036044(4);
                if (a != 0) {
                    func_02035e30(a, 1);
                }
                data_02174e6c->mUnk_64c = 11;
            }
            break;
    }
    o = data_02174e6c;
    o->mUnk_640 = (o->mUnk_640 + 1) % 0x100;
    return -1;
}

#pragma thumb off
