#include "03/code_021bbd9c.h"

int func_ov003_021bc7a8(u32 *param_1, u8 *param_2, int param_3) {
    int i = 0;
    u32 v1;

    param_1[0] = ((u32) param_2[0] << 24) ^ ((u32) param_2[1] << 16) ^ ((u32) param_2[2] << 8) ^ (u32) param_2[3];
    param_1[1] = ((u32) param_2[4] << 24) ^ ((u32) param_2[5] << 16) ^ ((u32) param_2[6] << 8) ^ (u32) param_2[7];
    param_1[2] = ((u32) param_2[8] << 24) ^ ((u32) param_2[9] << 16) ^ ((u32) param_2[10] << 8) ^ (u32) param_2[11];
    param_1[3] = ((u32) param_2[12] << 24) ^ ((u32) param_2[13] << 16) ^ ((u32) param_2[14] << 8) ^ (u32) param_2[15];
    if (param_3 == 128) {
        for (;;) {
            v1 = param_1[3];
            param_1[4] = param_1[0] ^ (data_ov003_021d52bc[(v1 >> 16) & 0xff] & 0xff000000) ^
                         (data_ov003_021d52bc[(v1 >> 8) & 0xff] & 0x00ff0000) ^
                         (data_ov003_021d52bc[v1 & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[v1 >> 24] & 0x000000ff) ^
                         data_ov003_021d3694[i];
            param_1[5] = param_1[1] ^ param_1[4];
            param_1[6] = param_1[2] ^ param_1[5];
            param_1[7] = param_1[3] ^ param_1[6];
            if (++i == 10) {
                return 10;
            }
            param_1 += 4;
        }
    }
    param_1[4] = ((u32) param_2[16] << 24) ^ ((u32) param_2[17] << 16) ^ ((u32) param_2[18] << 8) ^ (u32) param_2[19];
    param_1[5] = ((u32) param_2[20] << 24) ^ ((u32) param_2[21] << 16) ^ ((u32) param_2[22] << 8) ^ (u32) param_2[23];
    if (param_3 == 192) {
        for (;;) {
            v1 = param_1[5];
            param_1[6] = param_1[0] ^ (data_ov003_021d52bc[(v1 >> 16) & 0xff] & 0xff000000) ^
                         (data_ov003_021d52bc[(v1 >> 8) & 0xff] & 0x00ff0000) ^
                         (data_ov003_021d52bc[v1 & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[v1 >> 24] & 0x000000ff) ^
                         data_ov003_021d3694[i];
            param_1[7] = param_1[1] ^ param_1[6];
            param_1[8] = param_1[2] ^ param_1[7];
            param_1[9] = param_1[3] ^ param_1[8];
            if (++i == 8) {
                return 12;
            }
            param_1[10] = param_1[4] ^ param_1[9];
            param_1[11] = param_1[5] ^ param_1[10];
            param_1 += 6;
        }
    }
    param_1[6] = ((u32) param_2[24] << 24) ^ ((u32) param_2[25] << 16) ^ ((u32) param_2[26] << 8) ^ (u32) param_2[27];
    param_1[7] = ((u32) param_2[28] << 24) ^ ((u32) param_2[29] << 16) ^ ((u32) param_2[30] << 8) ^ (u32) param_2[31];
    if (param_3 == 256) {
        for (;;) {
            v1 = param_1[7];
            param_1[8] = param_1[0] ^ (data_ov003_021d52bc[(v1 >> 16) & 0xff] & 0xff000000) ^
                         (data_ov003_021d52bc[(v1 >> 8) & 0xff] & 0x00ff0000) ^
                         (data_ov003_021d52bc[v1 & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[v1 >> 24] & 0x000000ff) ^
                         data_ov003_021d3694[i];
            param_1[9] = param_1[1] ^ param_1[8];
            param_1[10] = param_1[2] ^ param_1[9];
            param_1[11] = param_1[3] ^ param_1[10];
            if (++i == 7) {
                return 14;
            }
            v1 = param_1[11];
            param_1[12] = param_1[4] ^ (data_ov003_021d52bc[v1 >> 24] & 0xff000000) ^
                          (data_ov003_021d52bc[(v1 >> 16) & 0xff] & 0x00ff0000) ^
                          (data_ov003_021d52bc[(v1 >> 8) & 0xff] & 0x0000ff00) ^
                          (data_ov003_021d52bc[v1 & 0xff] & 0x000000ff);
            param_1[13] = param_1[5] ^ param_1[12];
            param_1[14] = param_1[6] ^ param_1[13];
            param_1[15] = param_1[7] ^ param_1[14];
            param_1 += 8;
        }
    }
    return i;
}

int func_ov003_021bc5e4(u32 *param_1, u8 *param_2, int param_3) {
    int i, j, r;
    u32 v1;

    r = func_ov003_021bc7a8(param_1, param_2, param_3);
    for (i = 0, j = 4 * r; i < j; i += 4, j -= 4) {
        v1 = param_1[i];
        param_1[i] = param_1[j];
        param_1[j] = v1;
        v1 = param_1[i + 1];
        param_1[i + 1] = param_1[j + 1];
        param_1[j + 1] = v1;
        v1 = param_1[i + 2];
        param_1[i + 2] = param_1[j + 2];
        param_1[j + 2] = v1;
        v1 = param_1[i + 3];
        param_1[i + 3] = param_1[j + 3];
        param_1[j + 3] = v1;
    }
    for (i = 1; i < r; i++) {
        param_1 += 4;
        param_1[0] = data_ov003_021d56bc[data_ov003_021d52bc[param_1[0] >> 24] & 0xff] ^
                     data_ov003_021d5abc[data_ov003_021d52bc[(param_1[0] >> 16) & 0xff] & 0xff] ^
                     data_ov003_021d36bc[data_ov003_021d52bc[(param_1[0] >> 8) & 0xff] & 0xff] ^
                     data_ov003_021d3abc[data_ov003_021d52bc[param_1[0] & 0xff] & 0xff];
        param_1[1] = data_ov003_021d56bc[data_ov003_021d52bc[param_1[1] >> 24] & 0xff] ^
                     data_ov003_021d5abc[data_ov003_021d52bc[(param_1[1] >> 16) & 0xff] & 0xff] ^
                     data_ov003_021d36bc[data_ov003_021d52bc[(param_1[1] >> 8) & 0xff] & 0xff] ^
                     data_ov003_021d3abc[data_ov003_021d52bc[param_1[1] & 0xff] & 0xff];
        param_1[2] = data_ov003_021d56bc[data_ov003_021d52bc[param_1[2] >> 24] & 0xff] ^
                     data_ov003_021d5abc[data_ov003_021d52bc[(param_1[2] >> 16) & 0xff] & 0xff] ^
                     data_ov003_021d36bc[data_ov003_021d52bc[(param_1[2] >> 8) & 0xff] & 0xff] ^
                     data_ov003_021d3abc[data_ov003_021d52bc[param_1[2] & 0xff] & 0xff];
        param_1[3] = data_ov003_021d56bc[data_ov003_021d52bc[param_1[3] >> 24] & 0xff] ^
                     data_ov003_021d5abc[data_ov003_021d52bc[(param_1[3] >> 16) & 0xff] & 0xff] ^
                     data_ov003_021d36bc[data_ov003_021d52bc[(param_1[3] >> 8) & 0xff] & 0xff] ^
                     data_ov003_021d3abc[data_ov003_021d52bc[param_1[3] & 0xff] & 0xff];
    }
    return r;
}

void func_ov003_021bc1c4(u32 *param_1, int param_2, u8 *param_3, u8 *param_4) {
    u32 s0, s1, s2, s3, t0, t1, t2, t3;
    int r;

    s0 =
        (((u32) param_3[0] << 24) ^ ((u32) param_3[1] << 16) ^ ((u32) param_3[2] << 8) ^ (u32) param_3[3]) ^ param_1[0];
    s1 =
        (((u32) param_3[4] << 24) ^ ((u32) param_3[5] << 16) ^ ((u32) param_3[6] << 8) ^ (u32) param_3[7]) ^ param_1[1];
    s2 = (((u32) param_3[8] << 24) ^ ((u32) param_3[9] << 16) ^ ((u32) param_3[10] << 8) ^ (u32) param_3[11]) ^
         param_1[2];
    s3 = (((u32) param_3[12] << 24) ^ ((u32) param_3[13] << 16) ^ ((u32) param_3[14] << 8) ^ (u32) param_3[15]) ^
         param_1[3];
    r = param_2 >> 1;
    for (;;) {
        t0 = data_ov003_021d42bc[s0 >> 24] ^ data_ov003_021d46bc[(s1 >> 16) & 0xff] ^
             data_ov003_021d4abc[(s2 >> 8) & 0xff] ^ data_ov003_021d4ebc[s3 & 0xff] ^ param_1[4];
        t1 = data_ov003_021d42bc[s1 >> 24] ^ data_ov003_021d46bc[(s2 >> 16) & 0xff] ^
             data_ov003_021d4abc[(s3 >> 8) & 0xff] ^ data_ov003_021d4ebc[s0 & 0xff] ^ param_1[5];
        t2 = data_ov003_021d42bc[s2 >> 24] ^ data_ov003_021d46bc[(s3 >> 16) & 0xff] ^
             data_ov003_021d4abc[(s0 >> 8) & 0xff] ^ data_ov003_021d4ebc[s1 & 0xff] ^ param_1[6];
        t3 = data_ov003_021d42bc[s3 >> 24] ^ data_ov003_021d46bc[(s0 >> 16) & 0xff] ^
             data_ov003_021d4abc[(s1 >> 8) & 0xff] ^ data_ov003_021d4ebc[s2 & 0xff] ^ param_1[7];
        param_1 += 8;
        if (--r == 0) {
            break;
        }
        s0 = data_ov003_021d42bc[t0 >> 24] ^ data_ov003_021d46bc[(t1 >> 16) & 0xff] ^
             data_ov003_021d4abc[(t2 >> 8) & 0xff] ^ data_ov003_021d4ebc[t3 & 0xff] ^ param_1[0];
        s1 = data_ov003_021d42bc[t1 >> 24] ^ data_ov003_021d46bc[(t2 >> 16) & 0xff] ^
             data_ov003_021d4abc[(t3 >> 8) & 0xff] ^ data_ov003_021d4ebc[t0 & 0xff] ^ param_1[1];
        s2 = data_ov003_021d42bc[t2 >> 24] ^ data_ov003_021d46bc[(t3 >> 16) & 0xff] ^
             data_ov003_021d4abc[(t0 >> 8) & 0xff] ^ data_ov003_021d4ebc[t1 & 0xff] ^ param_1[2];
        s3 = data_ov003_021d42bc[t3 >> 24] ^ data_ov003_021d46bc[(t0 >> 16) & 0xff] ^
             data_ov003_021d4abc[(t1 >> 8) & 0xff] ^ data_ov003_021d4ebc[t2 & 0xff] ^ param_1[3];
    }
    s0 = (data_ov003_021d52bc[t0 >> 24] & 0xff000000) ^ (data_ov003_021d52bc[(t1 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d52bc[(t2 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[t3 & 0xff] & 0x000000ff) ^
         param_1[0];
    param_4[0] = s0 >> 24;
    param_4[1] = s0 >> 16;
    param_4[2] = s0 >> 8;
    param_4[3] = s0;
    s1 = (data_ov003_021d52bc[t1 >> 24] & 0xff000000) ^ (data_ov003_021d52bc[(t2 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d52bc[(t3 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[t0 & 0xff] & 0x000000ff) ^
         param_1[1];
    param_4[4] = s1 >> 24;
    param_4[5] = s1 >> 16;
    param_4[6] = s1 >> 8;
    param_4[7] = s1;
    s2 = (data_ov003_021d52bc[t2 >> 24] & 0xff000000) ^ (data_ov003_021d52bc[(t3 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d52bc[(t0 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[t1 & 0xff] & 0x000000ff) ^
         param_1[2];
    param_4[8] = s2 >> 24;
    param_4[9] = s2 >> 16;
    param_4[10] = s2 >> 8;
    param_4[11] = s2;
    s3 = (data_ov003_021d52bc[t3 >> 24] & 0xff000000) ^ (data_ov003_021d52bc[(t0 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d52bc[(t1 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[t2 & 0xff] & 0x000000ff) ^
         param_1[3];
    param_4[12] = s3 >> 24;
    param_4[13] = s3 >> 16;
    param_4[14] = s3 >> 8;
    param_4[15] = s3;
}

void func_ov003_021bbd9c(u32 *param_1, int param_2, u8 *param_3, u8 *param_4) {
    u32 s0, s1, s2, s3, t0, t1, t2, t3;
    int r;

    s0 =
        (((u32) param_3[0] << 24) ^ ((u32) param_3[1] << 16) ^ ((u32) param_3[2] << 8) ^ (u32) param_3[3]) ^ param_1[0];
    s1 =
        (((u32) param_3[4] << 24) ^ ((u32) param_3[5] << 16) ^ ((u32) param_3[6] << 8) ^ (u32) param_3[7]) ^ param_1[1];
    s2 = (((u32) param_3[8] << 24) ^ ((u32) param_3[9] << 16) ^ ((u32) param_3[10] << 8) ^ (u32) param_3[11]) ^
         param_1[2];
    s3 = (((u32) param_3[12] << 24) ^ ((u32) param_3[13] << 16) ^ ((u32) param_3[14] << 8) ^ (u32) param_3[15]) ^
         param_1[3];
    r = param_2 >> 1;
    for (;;) {
        t0 = data_ov003_021d56bc[s0 >> 24] ^ data_ov003_021d5abc[(s3 >> 16) & 0xff] ^
             data_ov003_021d36bc[(s2 >> 8) & 0xff] ^ data_ov003_021d3abc[s1 & 0xff] ^ param_1[4];
        t1 = data_ov003_021d56bc[s1 >> 24] ^ data_ov003_021d5abc[(s0 >> 16) & 0xff] ^
             data_ov003_021d36bc[(s3 >> 8) & 0xff] ^ data_ov003_021d3abc[s2 & 0xff] ^ param_1[5];
        t2 = data_ov003_021d56bc[s2 >> 24] ^ data_ov003_021d5abc[(s1 >> 16) & 0xff] ^
             data_ov003_021d36bc[(s0 >> 8) & 0xff] ^ data_ov003_021d3abc[s3 & 0xff] ^ param_1[6];
        t3 = data_ov003_021d56bc[s3 >> 24] ^ data_ov003_021d5abc[(s2 >> 16) & 0xff] ^
             data_ov003_021d36bc[(s1 >> 8) & 0xff] ^ data_ov003_021d3abc[s0 & 0xff] ^ param_1[7];
        param_1 += 8;
        if (--r == 0) {
            break;
        }
        s0 = data_ov003_021d56bc[t0 >> 24] ^ data_ov003_021d5abc[(t3 >> 16) & 0xff] ^
             data_ov003_021d36bc[(t2 >> 8) & 0xff] ^ data_ov003_021d3abc[t1 & 0xff] ^ param_1[0];
        s1 = data_ov003_021d56bc[t1 >> 24] ^ data_ov003_021d5abc[(t0 >> 16) & 0xff] ^
             data_ov003_021d36bc[(t3 >> 8) & 0xff] ^ data_ov003_021d3abc[t2 & 0xff] ^ param_1[1];
        s2 = data_ov003_021d56bc[t2 >> 24] ^ data_ov003_021d5abc[(t1 >> 16) & 0xff] ^
             data_ov003_021d36bc[(t0 >> 8) & 0xff] ^ data_ov003_021d3abc[t3 & 0xff] ^ param_1[2];
        s3 = data_ov003_021d56bc[t3 >> 24] ^ data_ov003_021d5abc[(t2 >> 16) & 0xff] ^
             data_ov003_021d36bc[(t1 >> 8) & 0xff] ^ data_ov003_021d3abc[t0 & 0xff] ^ param_1[3];
    }
    s0 = (data_ov003_021d3ebc[t0 >> 24] & 0xff000000) ^ (data_ov003_021d3ebc[(t3 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d3ebc[(t2 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d3ebc[t1 & 0xff] & 0x000000ff) ^
         param_1[0];
    param_4[0] = s0 >> 24;
    param_4[1] = s0 >> 16;
    param_4[2] = s0 >> 8;
    param_4[3] = s0;
    s1 = (data_ov003_021d3ebc[t1 >> 24] & 0xff000000) ^ (data_ov003_021d3ebc[(t0 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d3ebc[(t3 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d3ebc[t2 & 0xff] & 0x000000ff) ^
         param_1[1];
    param_4[4] = s1 >> 24;
    param_4[5] = s1 >> 16;
    param_4[6] = s1 >> 8;
    param_4[7] = s1;
    s2 = (data_ov003_021d3ebc[t2 >> 24] & 0xff000000) ^ (data_ov003_021d3ebc[(t1 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d3ebc[(t0 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d3ebc[t3 & 0xff] & 0x000000ff) ^
         param_1[2];
    param_4[8] = s2 >> 24;
    param_4[9] = s2 >> 16;
    param_4[10] = s2 >> 8;
    param_4[11] = s2;
    s3 = (data_ov003_021d3ebc[t3 >> 24] & 0xff000000) ^ (data_ov003_021d3ebc[(t2 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d3ebc[(t1 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d3ebc[t0 & 0xff] & 0x000000ff) ^
         param_1[3];
    param_4[12] = s3 >> 24;
    param_4[13] = s3 >> 16;
    param_4[14] = s3 >> 8;
    param_4[15] = s3;
}
