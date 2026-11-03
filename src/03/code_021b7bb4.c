#include "03/code_021b7bb4.h"

#include "code_02133048.h"
#include "code_0214d018.h"
#include "code_0214d964.h"
#include "00/code_021b0014.h"
#include "03/code_021b94b8.h"
#include "00/code_021a8aa8.h"
#include "00/unk_021b6000.h"

void func_ov003_021b7ed0(const s8 *key, u8 *buffer, s32 size) {
    s32 half = size / 2;
    s32 i;
    for (i = 0; i < half; i++) {
        buffer[half + i] ^= key[i];
    }
}

void func_ov003_021b7e94(u8 *a, u32 b, u8 *c) {
    int v1;
    v1 = _s32_div_f(b, 2);
    func_ov003_021b7d90((void *) c, (const void *) (a + v1), v1);
    func_ov003_021b7d90((void *) (c + v1), (const void *) a, v1);
    func_ov003_021b7d90((void *) a, (const void *) c, b);
    return;
}

u32 func_ov003_021b7e70(u32 a, int b) {
    u32 v1;
    if (0 < b) {
        v1 = (*(UnkWordFunc *) (*(u32 *) &data_ov003_021d8a0c))(b);
        return v1;
    }
    return 0;
}

void func_ov003_021b7e58(u32 a, u32 b) {
    (*(UnkFunc *) (*(u32 *) &data_ov003_021d8a18))(b);
    return;
}

s32 func_ov003_021b7df4(u32 a, u32 b, u32 c) {
    data_ov003_021d6810.mUnk_10 = func_ov003_021b7cac(a);
    data_ov003_021d6810.mUnk_14 = func_ov003_021b7cac(b);
    data_ov003_021d6810.mUnk_18 = func_ov003_021b7cac(c);
    if (func_ov000_021a8c94(&data_ov003_021d6810) < 0) {
        return -1;
    }
    while (data_ov000_021b63b4 == 0) {
        func_0200dc3c(100);
    }
    return 0;
}

s32 func_ov003_021b7dc8(void) {
    if (func_ov000_021a8c8c() < 0) {
        return -1;
    }
    return -(func_ov003_021ba524() != 0);
}

s32 func_ov003_021b7da0(const u8 *left, const u8 *right, s32 count) {
    s32 difference = 0;
    while (count-- > 0 && (difference = *left - *right) == 0) {
        left++;
        right++;
    }
    return difference;
}

void func_ov003_021b7d90(void *arg0, const void *arg1, u32 arg2) {
    func_0214d1fc(arg1, arg0, arg2);
}

void func_ov003_021b7d84(void *arg0, s32 arg1, u32 arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2 = arg2;
    u32 value3;
    value1 = (value1 << 24);
    value1 = (value1 >> 24);
    value3 = (u32) &func_0214d168;
    func_0214d168((void *) value0, (u8) value1, value2);
    return;
}

s32 func_ov003_021b7d68(s32 v1, void *v2, s32 v3, s32 v4, Unk021b7cec *v5, s32 *v6) {
    v5->mUnk_00 = *v6;
    return func_ov000_021a90a0(v1, v2, v3, v4, v5);
}

s32 func_ov003_021b7d1c(s32 v1, Unk021b7ba0 *v2, void *v3, void *v4, Unk021b7d1c *v5) {
    Unk021b7ba0 t;
    s64 s;
    s = 0;
    t = *v2;
    s += v5->mUnk_00 * 0x1ff6210 / 0x40;
    s += v5->mUnk_04 * 0x1ff6210 / 0x40;
    return func_ov000_021a8b20(&t, 1, s);
}

s32 func_ov003_021b7d04(s32 a, void *b, s32 c, s32 d, Unk021b7cec *e, u32 f) {
    e->mUnk_00 = f;
    return func_ov000_021a9018(a, b, c, d, e);
}

s32 func_ov003_021b7d00(s32 id, s32 arg1, s32 arg2, void *value, s32 length) {
    return id;
}

s32 func_ov003_021b7cf8(s32 domain, s32 type, s32 protocol) {
    return func_ov000_021a918c(domain, type, protocol);
}

s32 func_ov003_021b7cec(s32 v1, Unk021b7cec *v2, u32 v3) {
    v2->mUnk_00 = v3;
    return func_ov000_021a916c(v1, v2);
}

s32 func_ov003_021b7ce4(s32 descriptor) {
    return func_ov000_021a9008(descriptor);
}

u32 func_ov003_021b7cac(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value4;
    value1 = (value0 << 24);
    value2 = 0xff000000u;
    value1 = (value1) & (value2);
    value4 = (value0 << 8);
    value2 = 0xff0000u;
    value4 = (value4) & (value2);
    value3 = (value0 >> 24);
    value2 = 255u;
    value3 = (value3) & (value2);
    value2 = (value0 >> 8);
    value0 = 0xff00u;
    value2 = (value2) & (value0);
    value3 = (value3) | (value2);
    value4 = (value4) | (value3);
    value1 = (value1) | (value4);
    value0 = (value1) + (0u);
    return value0;
}

u16 func_ov003_021b7c94(u16 value) {
    return ((value >> 8) & 0xff) | ((value << 8) & 0xff00);
}

u32 func_ov003_021b7c5c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value4;
    value1 = (value0 << 24);
    value2 = 0xff000000u;
    value1 = (value1) & (value2);
    value4 = (value0 << 8);
    value2 = 0xff0000u;
    value4 = (value4) & (value2);
    value3 = (value0 >> 24);
    value2 = 255u;
    value3 = (value3) & (value2);
    value2 = (value0 >> 8);
    value0 = 0xff00u;
    value2 = (value2) & (value0);
    value3 = (value3) | (value2);
    value4 = (value4) | (value3);
    value1 = (value1) | (value4);
    value0 = (value1) + (0u);
    return value0;
}

u16 func_ov003_021b7c44(u16 value) {
    return ((value >> 8) & 0xff) | ((value << 8) & 0xff00);
}

int func_ov003_021b7c30(const void *a) {
    const s8 *p = a;
    int i = 0;
    while (p[i] != 0) {
        i++;
    }
    return i;
}

u16 func_ov003_021b7bb4(void) {
    s32 a;
    u32 b[3];
    u32 *c;
    if (data_ov003_021d7c48 == 0) {
        a = 0;
        func_ov003_021b7d84(b, 0, 12);
        if (func_0214df78(b) == 0) {
            a += b[0] << 10;
            a += b[1] << 3;
            a += b[2];
        }
        data_ov003_021d7c60[0] = a;
        data_ov003_021d7c60[1] = 0x5d588b65;
        data_ov003_021d7c60[2] = 0x269ec3;
        data_ov003_021d7c48 = 1;
    }
    data_ov003_021d7c60[0] = data_ov003_021d7c60[2] + data_ov003_021d7c60[1] * data_ov003_021d7c60[0];
    return ((data_ov003_021d7c60[0] >> 16) * 0x7fff) >> 16;
}
