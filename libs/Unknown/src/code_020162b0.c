#include "code_020162b0.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02173000.h"

void func_02016414(u32 a, s32 b) {
    data_02173214.mUnk_08 = a;
    func_020162b0();
    if (b != 0) {
        data_021619f4 = (u32(*)(s32, s32, s32)) func_020162d4;
        data_021619f8 = (void (*)(void *)) func_020162cc;
    }
}

u32 func_020162d4(u32 a, s32 b, s32 c) {
    u32 p = 0;
    u32 r;
    u32 e;
    u32 pad;
    u32 end;
    if (a == 0) {
        a = 8;
    } else {
        a = (a + 7) & ~7;
    }
    if (a >= 0x7fff8) {
        return 0;
    }
    if (c == 1) {
        e = data_02173214.mUnk_00;
        if (b != 0) {
            pad = (8 - (e & 7)) & 7;
        } else {
            pad = (16 - (e & 0xf)) & 0xf;
        }
        r = a + pad;
        if (data_02173214.mUnk_04 - e >= r) {
            end = e + r;
            if (b != 0 && end > 0x10000) {
                end = 0;
            } else {
                p = e + pad;
                end = 1;
                data_02173214.mUnk_00 += r;
            }
        } else {
            end = 0;
        }
    } else {
        e = data_02173214.mUnk_04;
        if (e >= a) {
            r = e - a;
            if (b != 0) {
                pad = r & 7;
            } else {
                pad = r & 0xf;
            }
            r = a + pad;
            if (e - data_02173214.mUnk_00 >= r) {
                if (b != 0 && e > 0x10000) {
                    end = 0;
                } else {
                    end = 1;
                    data_02173214.mUnk_04 -= r;
                    p = data_02173214.mUnk_04;
                }
                goto done;
            }
        }
        end = 0;
    }
done:
    if (end != 0) {
        return ((a >> 3) << 16) | ((p >> 3) & 0xffff);
    }
    return 0;
}

u32 func_020162cc(void) {
    return 0;
}

void func_020162b0(void) {
    data_02173214.mUnk_00 = 0;
    data_02173214.mUnk_04 = data_02173214.mUnk_08;
}
