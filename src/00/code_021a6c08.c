#include "00/code_021a6c08.h"

#include "00/code_021a6908.h"
#include "00/code_021a68dc.h"
#include "00/code_021a669c.h"
#include "00/code_021a6934.h"
#include "00/unk_021b5000.h"
#include "code_0200edc0.h"
#include "code_02133048.h"
#include "code_02142eac.h"
#include "code_0200fc8c.h"
#include "00/code_021a574c.h"

u8 func_ov000_021a6c90(void) {
    s32 a = 0;
    u32 b = data_ov000_021b5f80;
    s32 i;

    if (b > 16) {
        for (i = 0; i < 16; i++) {
            a += data_ov000_021b5f84[i];
        }
        a = a / 16;
    } else if (b != 0) {
        for (i = 0; i < (s32) b; i++) {
            a += data_ov000_021b5f84[i];
        }
        a = a / (s32) b;
    }
    return a;
}

s32 func_ov000_021a6c68(void) {
    u32 value = func_ov000_021a6c90();
    s32 level = 0;
    if (value >= 28) {
        level = 3;
    } else if (value >= 22) {
        level = 2;
    } else if (value >= 16) {
        level = 1;
    }
    return level;
}

void func_ov000_021a6c08(u8 c) {
    u8 a;
    u8 b;

    if (c & 2) {
        a = (c >> 2) & 0xff;
    } else {
        a = (c >> 2) + 25;
    }
    b = data_ov000_021b5f80;
    data_ov000_021b5f84[b % 16] = a;
    if (b >= 16) {
        data_ov000_021b5f80 = (b + 1) % 16 + 16;
    } else {
        data_ov000_021b5f80++;
    }
}
