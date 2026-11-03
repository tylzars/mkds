#include "03/code_021bbc94.h"

#include "03/code_021bb03c.h"
#include "03/code_021bb438.h"
#include "03/unk_021d3000.h"

void func_ov003_021bca90(u8 *a, u8 *b, u8 *c) {
    *c = *a ^ *b;
    c[1] = a[1] ^ b[1];
    c[2] = a[2] ^ b[2];
    c[3] = a[3] ^ b[3];
    c[4] = a[4] ^ b[4];
    c[5] = a[5] ^ b[5];
    c[6] = a[6] ^ b[6];
    c[7] = a[7] ^ b[7];
    return;
}

int func_ov003_021bc7a8(u32 *a, u8 *b, int c) {
    int i = 0;
    u32 v1;

    a[0] = ((u32) b[0] << 24) ^ ((u32) b[1] << 16) ^ ((u32) b[2] << 8) ^ (u32) b[3];
    a[1] = ((u32) b[4] << 24) ^ ((u32) b[5] << 16) ^ ((u32) b[6] << 8) ^ (u32) b[7];
    a[2] = ((u32) b[8] << 24) ^ ((u32) b[9] << 16) ^ ((u32) b[10] << 8) ^ (u32) b[11];
    a[3] = ((u32) b[12] << 24) ^ ((u32) b[13] << 16) ^ ((u32) b[14] << 8) ^ (u32) b[15];
    if (c == 128) {
        for (;;) {
            v1 = a[3];
            a[4] = a[0] ^ (data_ov003_021d52bc[(v1 >> 16) & 0xff] & 0xff000000) ^
                   (data_ov003_021d52bc[(v1 >> 8) & 0xff] & 0x00ff0000) ^
                   (data_ov003_021d52bc[v1 & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[v1 >> 24] & 0x000000ff) ^
                   data_ov003_021d3694[i];
            a[5] = a[1] ^ a[4];
            a[6] = a[2] ^ a[5];
            a[7] = a[3] ^ a[6];
            if (++i == 10) {
                return 10;
            }
            a += 4;
        }
    }
    a[4] = ((u32) b[16] << 24) ^ ((u32) b[17] << 16) ^ ((u32) b[18] << 8) ^ (u32) b[19];
    a[5] = ((u32) b[20] << 24) ^ ((u32) b[21] << 16) ^ ((u32) b[22] << 8) ^ (u32) b[23];
    if (c == 192) {
        for (;;) {
            v1 = a[5];
            a[6] = a[0] ^ (data_ov003_021d52bc[(v1 >> 16) & 0xff] & 0xff000000) ^
                   (data_ov003_021d52bc[(v1 >> 8) & 0xff] & 0x00ff0000) ^
                   (data_ov003_021d52bc[v1 & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[v1 >> 24] & 0x000000ff) ^
                   data_ov003_021d3694[i];
            a[7] = a[1] ^ a[6];
            a[8] = a[2] ^ a[7];
            a[9] = a[3] ^ a[8];
            if (++i == 8) {
                return 12;
            }
            a[10] = a[4] ^ a[9];
            a[11] = a[5] ^ a[10];
            a += 6;
        }
    }
    a[6] = ((u32) b[24] << 24) ^ ((u32) b[25] << 16) ^ ((u32) b[26] << 8) ^ (u32) b[27];
    a[7] = ((u32) b[28] << 24) ^ ((u32) b[29] << 16) ^ ((u32) b[30] << 8) ^ (u32) b[31];
    if (c == 256) {
        for (;;) {
            v1 = a[7];
            a[8] = a[0] ^ (data_ov003_021d52bc[(v1 >> 16) & 0xff] & 0xff000000) ^
                   (data_ov003_021d52bc[(v1 >> 8) & 0xff] & 0x00ff0000) ^
                   (data_ov003_021d52bc[v1 & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[v1 >> 24] & 0x000000ff) ^
                   data_ov003_021d3694[i];
            a[9] = a[1] ^ a[8];
            a[10] = a[2] ^ a[9];
            a[11] = a[3] ^ a[10];
            if (++i == 7) {
                return 14;
            }
            v1 = a[11];
            a[12] = a[4] ^ (data_ov003_021d52bc[v1 >> 24] & 0xff000000) ^
                    (data_ov003_021d52bc[(v1 >> 16) & 0xff] & 0x00ff0000) ^
                    (data_ov003_021d52bc[(v1 >> 8) & 0xff] & 0x0000ff00) ^
                    (data_ov003_021d52bc[v1 & 0xff] & 0x000000ff);
            a[13] = a[5] ^ a[12];
            a[14] = a[6] ^ a[13];
            a[15] = a[7] ^ a[14];
            a += 8;
        }
    }
    return i;
}

int func_ov003_021bc5e4(u32 *a, u8 *b, int c) {
    int i, j, r;
    u32 v1;

    r = func_ov003_021bc7a8(a, b, c);
    for (i = 0, j = 4 * r; i < j; i += 4, j -= 4) {
        v1 = a[i];
        a[i] = a[j];
        a[j] = v1;
        v1 = a[i + 1];
        a[i + 1] = a[j + 1];
        a[j + 1] = v1;
        v1 = a[i + 2];
        a[i + 2] = a[j + 2];
        a[j + 2] = v1;
        v1 = a[i + 3];
        a[i + 3] = a[j + 3];
        a[j + 3] = v1;
    }
    for (i = 1; i < r; i++) {
        a += 4;
        a[0] = data_ov003_021d56bc[data_ov003_021d52bc[a[0] >> 24] & 0xff] ^
               data_ov003_021d5abc[data_ov003_021d52bc[(a[0] >> 16) & 0xff] & 0xff] ^
               data_ov003_021d36bc[data_ov003_021d52bc[(a[0] >> 8) & 0xff] & 0xff] ^
               data_ov003_021d3abc[data_ov003_021d52bc[a[0] & 0xff] & 0xff];
        a[1] = data_ov003_021d56bc[data_ov003_021d52bc[a[1] >> 24] & 0xff] ^
               data_ov003_021d5abc[data_ov003_021d52bc[(a[1] >> 16) & 0xff] & 0xff] ^
               data_ov003_021d36bc[data_ov003_021d52bc[(a[1] >> 8) & 0xff] & 0xff] ^
               data_ov003_021d3abc[data_ov003_021d52bc[a[1] & 0xff] & 0xff];
        a[2] = data_ov003_021d56bc[data_ov003_021d52bc[a[2] >> 24] & 0xff] ^
               data_ov003_021d5abc[data_ov003_021d52bc[(a[2] >> 16) & 0xff] & 0xff] ^
               data_ov003_021d36bc[data_ov003_021d52bc[(a[2] >> 8) & 0xff] & 0xff] ^
               data_ov003_021d3abc[data_ov003_021d52bc[a[2] & 0xff] & 0xff];
        a[3] = data_ov003_021d56bc[data_ov003_021d52bc[a[3] >> 24] & 0xff] ^
               data_ov003_021d5abc[data_ov003_021d52bc[(a[3] >> 16) & 0xff] & 0xff] ^
               data_ov003_021d36bc[data_ov003_021d52bc[(a[3] >> 8) & 0xff] & 0xff] ^
               data_ov003_021d3abc[data_ov003_021d52bc[a[3] & 0xff] & 0xff];
    }
    return r;
}

void func_ov003_021bc1c4(u32 *a, int b, u8 *c, u8 *d) {
    u32 s0, s1, s2, s3, t0, t1, t2, t3;
    int r;

    s0 = (((u32) c[0] << 24) ^ ((u32) c[1] << 16) ^ ((u32) c[2] << 8) ^ (u32) c[3]) ^ a[0];
    s1 = (((u32) c[4] << 24) ^ ((u32) c[5] << 16) ^ ((u32) c[6] << 8) ^ (u32) c[7]) ^ a[1];
    s2 = (((u32) c[8] << 24) ^ ((u32) c[9] << 16) ^ ((u32) c[10] << 8) ^ (u32) c[11]) ^ a[2];
    s3 = (((u32) c[12] << 24) ^ ((u32) c[13] << 16) ^ ((u32) c[14] << 8) ^ (u32) c[15]) ^ a[3];
    r = b >> 1;
    for (;;) {
        t0 = data_ov003_021d42bc[s0 >> 24] ^ data_ov003_021d46bc[(s1 >> 16) & 0xff] ^
             data_ov003_021d4abc[(s2 >> 8) & 0xff] ^ data_ov003_021d4ebc[s3 & 0xff] ^ a[4];
        t1 = data_ov003_021d42bc[s1 >> 24] ^ data_ov003_021d46bc[(s2 >> 16) & 0xff] ^
             data_ov003_021d4abc[(s3 >> 8) & 0xff] ^ data_ov003_021d4ebc[s0 & 0xff] ^ a[5];
        t2 = data_ov003_021d42bc[s2 >> 24] ^ data_ov003_021d46bc[(s3 >> 16) & 0xff] ^
             data_ov003_021d4abc[(s0 >> 8) & 0xff] ^ data_ov003_021d4ebc[s1 & 0xff] ^ a[6];
        t3 = data_ov003_021d42bc[s3 >> 24] ^ data_ov003_021d46bc[(s0 >> 16) & 0xff] ^
             data_ov003_021d4abc[(s1 >> 8) & 0xff] ^ data_ov003_021d4ebc[s2 & 0xff] ^ a[7];
        a += 8;
        if (--r == 0) {
            break;
        }
        s0 = data_ov003_021d42bc[t0 >> 24] ^ data_ov003_021d46bc[(t1 >> 16) & 0xff] ^
             data_ov003_021d4abc[(t2 >> 8) & 0xff] ^ data_ov003_021d4ebc[t3 & 0xff] ^ a[0];
        s1 = data_ov003_021d42bc[t1 >> 24] ^ data_ov003_021d46bc[(t2 >> 16) & 0xff] ^
             data_ov003_021d4abc[(t3 >> 8) & 0xff] ^ data_ov003_021d4ebc[t0 & 0xff] ^ a[1];
        s2 = data_ov003_021d42bc[t2 >> 24] ^ data_ov003_021d46bc[(t3 >> 16) & 0xff] ^
             data_ov003_021d4abc[(t0 >> 8) & 0xff] ^ data_ov003_021d4ebc[t1 & 0xff] ^ a[2];
        s3 = data_ov003_021d42bc[t3 >> 24] ^ data_ov003_021d46bc[(t0 >> 16) & 0xff] ^
             data_ov003_021d4abc[(t1 >> 8) & 0xff] ^ data_ov003_021d4ebc[t2 & 0xff] ^ a[3];
    }
    s0 = (data_ov003_021d52bc[t0 >> 24] & 0xff000000) ^ (data_ov003_021d52bc[(t1 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d52bc[(t2 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[t3 & 0xff] & 0x000000ff) ^ a[0];
    d[0] = s0 >> 24;
    d[1] = s0 >> 16;
    d[2] = s0 >> 8;
    d[3] = s0;
    s1 = (data_ov003_021d52bc[t1 >> 24] & 0xff000000) ^ (data_ov003_021d52bc[(t2 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d52bc[(t3 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[t0 & 0xff] & 0x000000ff) ^ a[1];
    d[4] = s1 >> 24;
    d[5] = s1 >> 16;
    d[6] = s1 >> 8;
    d[7] = s1;
    s2 = (data_ov003_021d52bc[t2 >> 24] & 0xff000000) ^ (data_ov003_021d52bc[(t3 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d52bc[(t0 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[t1 & 0xff] & 0x000000ff) ^ a[2];
    d[8] = s2 >> 24;
    d[9] = s2 >> 16;
    d[10] = s2 >> 8;
    d[11] = s2;
    s3 = (data_ov003_021d52bc[t3 >> 24] & 0xff000000) ^ (data_ov003_021d52bc[(t0 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d52bc[(t1 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[t2 & 0xff] & 0x000000ff) ^ a[3];
    d[12] = s3 >> 24;
    d[13] = s3 >> 16;
    d[14] = s3 >> 8;
    d[15] = s3;
}

void func_ov003_021bbd9c(u32 *a, int b, u8 *c, u8 *d) {
    u32 s0, s1, s2, s3, t0, t1, t2, t3;
    int r;

    s0 = (((u32) c[0] << 24) ^ ((u32) c[1] << 16) ^ ((u32) c[2] << 8) ^ (u32) c[3]) ^ a[0];
    s1 = (((u32) c[4] << 24) ^ ((u32) c[5] << 16) ^ ((u32) c[6] << 8) ^ (u32) c[7]) ^ a[1];
    s2 = (((u32) c[8] << 24) ^ ((u32) c[9] << 16) ^ ((u32) c[10] << 8) ^ (u32) c[11]) ^ a[2];
    s3 = (((u32) c[12] << 24) ^ ((u32) c[13] << 16) ^ ((u32) c[14] << 8) ^ (u32) c[15]) ^ a[3];
    r = b >> 1;
    for (;;) {
        t0 = data_ov003_021d56bc[s0 >> 24] ^ data_ov003_021d5abc[(s3 >> 16) & 0xff] ^
             data_ov003_021d36bc[(s2 >> 8) & 0xff] ^ data_ov003_021d3abc[s1 & 0xff] ^ a[4];
        t1 = data_ov003_021d56bc[s1 >> 24] ^ data_ov003_021d5abc[(s0 >> 16) & 0xff] ^
             data_ov003_021d36bc[(s3 >> 8) & 0xff] ^ data_ov003_021d3abc[s2 & 0xff] ^ a[5];
        t2 = data_ov003_021d56bc[s2 >> 24] ^ data_ov003_021d5abc[(s1 >> 16) & 0xff] ^
             data_ov003_021d36bc[(s0 >> 8) & 0xff] ^ data_ov003_021d3abc[s3 & 0xff] ^ a[6];
        t3 = data_ov003_021d56bc[s3 >> 24] ^ data_ov003_021d5abc[(s2 >> 16) & 0xff] ^
             data_ov003_021d36bc[(s1 >> 8) & 0xff] ^ data_ov003_021d3abc[s0 & 0xff] ^ a[7];
        a += 8;
        if (--r == 0) {
            break;
        }
        s0 = data_ov003_021d56bc[t0 >> 24] ^ data_ov003_021d5abc[(t3 >> 16) & 0xff] ^
             data_ov003_021d36bc[(t2 >> 8) & 0xff] ^ data_ov003_021d3abc[t1 & 0xff] ^ a[0];
        s1 = data_ov003_021d56bc[t1 >> 24] ^ data_ov003_021d5abc[(t0 >> 16) & 0xff] ^
             data_ov003_021d36bc[(t3 >> 8) & 0xff] ^ data_ov003_021d3abc[t2 & 0xff] ^ a[1];
        s2 = data_ov003_021d56bc[t2 >> 24] ^ data_ov003_021d5abc[(t1 >> 16) & 0xff] ^
             data_ov003_021d36bc[(t0 >> 8) & 0xff] ^ data_ov003_021d3abc[t3 & 0xff] ^ a[2];
        s3 = data_ov003_021d56bc[t3 >> 24] ^ data_ov003_021d5abc[(t2 >> 16) & 0xff] ^
             data_ov003_021d36bc[(t1 >> 8) & 0xff] ^ data_ov003_021d3abc[t0 & 0xff] ^ a[3];
    }
    s0 = (data_ov003_021d3ebc[t0 >> 24] & 0xff000000) ^ (data_ov003_021d3ebc[(t3 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d3ebc[(t2 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d3ebc[t1 & 0xff] & 0x000000ff) ^ a[0];
    d[0] = s0 >> 24;
    d[1] = s0 >> 16;
    d[2] = s0 >> 8;
    d[3] = s0;
    s1 = (data_ov003_021d3ebc[t1 >> 24] & 0xff000000) ^ (data_ov003_021d3ebc[(t0 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d3ebc[(t3 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d3ebc[t2 & 0xff] & 0x000000ff) ^ a[1];
    d[4] = s1 >> 24;
    d[5] = s1 >> 16;
    d[6] = s1 >> 8;
    d[7] = s1;
    s2 = (data_ov003_021d3ebc[t2 >> 24] & 0xff000000) ^ (data_ov003_021d3ebc[(t1 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d3ebc[(t0 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d3ebc[t3 & 0xff] & 0x000000ff) ^ a[2];
    d[8] = s2 >> 24;
    d[9] = s2 >> 16;
    d[10] = s2 >> 8;
    d[11] = s2;
    s3 = (data_ov003_021d3ebc[t3 >> 24] & 0xff000000) ^ (data_ov003_021d3ebc[(t2 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d3ebc[(t1 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d3ebc[t0 & 0xff] & 0x000000ff) ^ a[3];
    d[12] = s3 >> 24;
    d[13] = s3 >> 16;
    d[14] = s3 >> 8;
    d[15] = s3;
}

void func_ov003_021bbd70(Unk021bbd70 *a) {
    a->mUnk_14 = 0;
    a->mUnk_10 = a->mUnk_14;
    a->mUnk_00[0] = 0x67452301;
    a->mUnk_00[1] = 0xefcdab89;
    a->mUnk_00[2] = 0x98badcfe;
    a->mUnk_00[3] = 0x10325476;
}

void func_ov003_021bbcf0(Unk021bbd70 *a, const u8 *b, u32 c) {
    u32 i;
    u32 d;
    u32 e;
    d = (a->mUnk_10 >> 3) & 0x3f;
    a->mUnk_10 += c << 3;
    if (a->mUnk_10 < (c << 3)) {
        a->mUnk_14++;
    }
    a->mUnk_14 += c >> 29;
    e = 0x40 - d;
    if (c >= e) {
        func_ov003_021bb3bc(a->mUnk_18 + d, b, e);
        func_ov003_021bb438(a, a->mUnk_18);
        for (i = e; i + 63 < c; i += 64) {
            func_ov003_021bb438(a, b + i);
        }
        d = 0;
    } else {
        i = 0;
    }
    func_ov003_021bb3bc(a->mUnk_18 + d, b + i, c - i);
}

void func_ov003_021bbc94(u8 *a, Unk021bbd70 *b) {
    u8 c[8];
    u32 i;
    u32 d;
    func_ov003_021bb408(c, &b->mUnk_10, 8);
    i = (b->mUnk_10 >> 3) & 0x3f;
    if (i < 0x38) {
        d = 0x38 - i;
    } else {
        d = 0x78 - i;
    }
    func_ov003_021bbcf0(b, data_ov003_021d68dc, d);
    func_ov003_021bbcf0(b, c, 8);
    func_ov003_021bb408(a, b->mUnk_00, 0x10);
    func_ov003_021bb3a4(b, 0, 0x58);
}
