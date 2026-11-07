#include "code_020205b0.h"

void Crc8InitTable(u8 *a, u32 b) {
    u32 v;
    u32 i;
    u32 j;

    for (i = 0; i < 0x100; i++) {
        v = i;
        for (j = 0; j < 8; j++) {
            if (v & 0x80) {
                v = b ^ (v << 1);
            } else {
                v = v << 1;
            }
        }
        a[i] = v;
    }
}

void Crc8Continue(const u8 *a, u8 *b, const u8 *c, u32 d) {
    u32 v;
    u32 i;

    v = *b;
    for (i = 0; i < d; i++) {
        v = a[(v ^ *c) & 0xff];
        c++;
    }
    *b = v;
}

void Crc16InitTable(u16 *a, u32 b) {
    u32 v;
    u32 i;
    u32 j;

    for (i = 0; i < 0x100; i++) {
        v = i;
        for (j = 0; j < 8; j++) {
            if (v & 1) {
                v = b ^ (v >> 1);
            } else {
                v = v >> 1;
            }
        }
        a[i] = v;
    }
}

void Crc16Continue(const u16 *a, u16 *b, const u8 *c, u32 d) {
    u32 v;
    u32 i;

    v = *b;
    for (i = 0; i < d; i++) {
        v = a[(v ^ *c) & 0xff] ^ (v >> 8);
        c++;
    }
    *b = v;
}

void Crc32InitTable(u32 *a, u32 b) {
    u32 v;
    u32 i;
    u32 j;

    for (i = 0; i < 0x100; i++) {
        v = i;
        for (j = 0; j < 8; j++) {
            if (v & 1) {
                v = b ^ (v >> 1);
            } else {
                v = v >> 1;
            }
        }
        a[i] = v;
    }
}

void Crc32Continue(const u32 *a, u32 *b, const u8 *c, u32 d) {
    u32 v;
    u32 i;

    v = *b;
    for (i = 0; i < d; i++) {
        v = a[(v ^ *c) & 0xff] ^ (v >> 8);
        c++;
    }
    *b = v;
}

u8 Crc8(const u8 *a, const void *b, u32 c) {
    u8 v;

    v = 0;
    Crc8Continue(a, &v, b, c);
    return v;
}

u16 Crc16(const u16 *a, const u8 *b, u32 c) {
    u16 v;

    v = 0;
    Crc16Continue(a, &v, b, c);
    return v;
}

u32 Crc32(const u32 *a, const void *b, u32 c) {
    u32 v;

    v = -1;
    Crc32Continue(a, &v, b, c);
    return ~v;
}
