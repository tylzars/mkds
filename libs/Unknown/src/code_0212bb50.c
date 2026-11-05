#include "code_0212bb50.h"

#include "Main/Unknown/unk_0217d000.h"
#include "code_020207ec.h"

u32 data_0217d440;
u32 data_0217d438;
u32 data_0217d43c;

u32 func_0212bc58(u32 a) {
    if (a == 0) {
        return 1;
    }
    if (a & data_0217d440) {
        return 0;
    }
    SND_LockChannel(a, 0);
    data_0217d440 |= a;
    return 1;
}

void func_0212bc20(u32 a) {
    if (a == 0) {
        return;
    }
    SND_UnlockChannel(a, 0);
    data_0217d440 &= ~a;
}

u32 func_0212bbfc(u32 a) {
    if (a & data_0217d438) {
        return 0;
    }
    data_0217d438 |= a;
    return 1;
}

void func_0212bbe0(u32 a) {
    data_0217d438 &= ~a;
}

s32 func_0212bb9c(void) {
    s32 i;
    u32 m;

    m = 1;
    for (i = 0; i < 8; i++) {
        if ((data_0217d43c & m) == 0) {
            data_0217d43c |= m;
            return i;
        }
        m <<= 1;
    }
    return -1;
}

void func_0212bb7c(s32 a) {
    data_0217d43c &= ~(1 << a);
}

u32 func_0212bb50(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    value2 = (u32) &data_0217d440;
    value3 = 0u;
    value1 = (u32) &data_0217d438;
    value0 = (u32) &data_0217d43c;
    *(u32 *) ((value2) + (0)) = value3;
    *(u32 *) ((value1) + (0)) = value3;
    *(u32 *) ((value0) + (0)) = value3;
    return value0;
}
