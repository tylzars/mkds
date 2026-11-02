#include "Main/Unknown/code_02088338.h"

#include "code_02135014.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"

void func_02088888(int value) {
    if (value) {
        data_0217af24 = (const char *) data_02165fd4;
    } else {
        data_0217af24 = (const char *) data_02165fec;
    }
}

char *func_020887d8(u16 a, s32 b) {
    const char *e = "nsbmd";
    const char *p;
    if (b != 0) {
        p = data_02155cec[a].mUnk_00;
    } else {
        p = data_02155cf0[a].mUnk_00;
    }
    snprintf(data_0217af28, 0x100, "%s%s%s", data_0217af24, data_02165ac4, data_02165e80[a]);
    snprintf(data_0217af28, 0x100, "%s%s.%s", data_0217af28, p, e);
    return data_0217af28;
}

char *func_02088728(u16 a, s32 b) {
    const char *e = "nsbtx";
    const char *p;
    if (b != 0) {
        p = data_02155cec[a].mUnk_00;
    } else {
        p = data_02155cf0[a].mUnk_00;
    }
    snprintf(data_0217af28, 0x100, "%s%s%s", data_0217af24, data_02165ac4, data_02165e80[a]);
    snprintf(data_0217af28, 0x100, "%s%s.%s", data_0217af28, p, e);
    return data_0217af28;
}

char *func_0208867c(u16 a) {
    const char *e = "nsbmd";
    snprintf(data_0217af28, 0x100, "%s%s%skart_%s.%s", data_0217af24, data_02165ac8,
             a % 3 == 0 ? "mario/" : data_02165e80[a / 3], data_02155d88[a].mUnk_00, e);
    return data_0217af28;
}

char *func_020885d0(u16 a) {
    const char *e = "nsbtx";
    snprintf(data_0217af28, 0x100, "%s%s%skart_%s.%s", data_0217af24, data_02165ac8,
             a % 3 == 0 ? "mario/" : data_02165e80[a / 3], data_02155d88[a].mUnk_00, e);
    return data_0217af28;
}

char *func_02088574(u16 a, const char *b) {
    const char *p = "nsbmd";
    snprintf(data_0217af28, 0x100, "%s%stire/%s.%s", data_0217af24, data_02165ac8, b, p);
    return data_0217af28;
}

char *func_02088518(u16 a, const char *b) {
    const char *p = "nsbtx";
    snprintf(data_0217af28, 0x100, "%s%stire/%s.%s", data_0217af24, data_02165ac8, b, p);
    return data_0217af28;
}

char *func_020884bc(u16 a) {
    snprintf(data_0217af28, 0x100, "%s%sshadow/sh_%s.nsbmd", data_0217af24, data_02165ac8, data_02155d8c[a].mUnk_00);
    return data_0217af28;
}

const char *func_0208848c(s32 a, s32 b) {
    if (b != 0) {
        return data_02155cec[a].mUnk_00;
    } else {
        return data_02155cf0[a].mUnk_00;
    }
}

char *func_02088430(s32 a) {
    snprintf(data_0217af28, 0x100, "%s%s%s", data_0217af24, data_02165ac4, data_02165e80[a]);
    return data_0217af28;
}

s8 *func_020883e4(void) {
    snprintf((char *) &data_0217af28, 0x100, (const char *) &data_02165ef0, *(u32 *) &data_0217af24,
             *(u32 *) &data_02165ac4);
    return (s8 *) &data_0217af28;
}

char *func_02088390(u16 a) {
    snprintf(data_0217af28, 0x100, data_02165ed4, data_0217af24, data_02155cf4[a].mUnk_00);
    return data_0217af28;
}

char *func_02088338(s32 a) {
    snprintf(data_0217af28, 0x100, data_02165eb4, data_0217af24, data_02165e4c[a == 0]);
    return data_0217af28;
}
