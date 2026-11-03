#include "Main/Unknown/code_02039530.h"
#include "Main/Unknown/code_02039230.h"
#include "Main/Unknown/unk_02175628.h"
#include "code_0200f5ac.h"

void func_02039530(u32 a, Unk02175628 *b) {
    u16 c;
    if (b->mUnk_20 != 0) {
        func_020392c8(a);
    }
    b->mUnk_00 = a & (a ^ b->mUnk_02);
    b->mUnk_04 = (a ^ 0xffff) & (a ^ b->mUnk_02);
    b->mUnk_02 = a;
    b->mUnk_06 = 0;
    switch (b->mUnk_08) {
        case 0:
            if (a & b->mUnk_0c) {
                b->mUnk_08 = 1;
                b->mUnk_0a = 0;
                b->mUnk_06 = a & b->mUnk_0c;
            }
            break;
        case 1:
            if (a & b->mUnk_0c) {
                b->mUnk_0a++;
                if (b->mUnk_0a >= b->mUnk_0e) {
                    b->mUnk_08 = 2;
                    b->mUnk_0a = 0;
                    b->mUnk_06 = a & b->mUnk_0c;
                }
            } else {
                b->mUnk_08 = 0;
            }
            break;
        case 2:
            if (a & b->mUnk_0c) {
                b->mUnk_0a++;
                if (b->mUnk_0a >= b->mUnk_10) {
                    b->mUnk_0a = 0;
                    b->mUnk_06 = a & b->mUnk_0c;
                }
            } else {
                b->mUnk_08 = 0;
            }
            break;
    }
    c = b->mUnk_02 & 0x30c;
    if (b->mUnk_14 != 0 && c == 0x30c) {
        if (b->mUnk_00 & 0x30c) {
            b->mUnk_18 = func_0200f5ac();
            b->mUnk_12 = 0;
            return;
        }
        if (b->mUnk_12 != 0) {
            return;
        }
        if ((u32) (func_0200f5ac() - b->mUnk_18) > 0x3fec4) {
            b->mUnk_12 = 1;
        }
        return;
    }
    if (c != 0x30c) {
        b->mUnk_14 = 1;
    }
    b->mUnk_12 = 0;
}
