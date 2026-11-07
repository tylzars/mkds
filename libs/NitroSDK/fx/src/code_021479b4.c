#include "code_021479b4.h"

// Multiplies the 4x4 matrices a and b and writes the product to ab; ab may be the same as a or b.
void MTX_Concat44(const s32 *a, const s32 *b, s32 *ab) {
    MtxFx44 tmp;
    s32 *result;
    s32 x0;
    s32 x1;
    s32 x2;
    s32 x3;
    s32 y0;
    s32 y1;
    s32 y2;
    s32 y3;

    result = ab;
    if (result == b) {
        result = tmp.mUnk_00;
    }
    x0 = a[0];
    x1 = a[1];
    x2 = a[2];
    x3 = a[3];
    result[0] = ((s64) x0 * b[0] + (s64) x1 * b[4] + (s64) x2 * b[8] + (s64) x3 * b[12]) >> 12;
    result[1] = ((s64) x0 * b[1] + (s64) x1 * b[5] + (s64) x2 * b[9] + (s64) x3 * b[13]) >> 12;
    result[3] = ((s64) x0 * b[3] + (s64) x1 * b[7] + (s64) x2 * b[11] + (s64) x3 * b[15]) >> 12;
    y0 = b[2];
    y1 = b[6];
    y2 = b[10];
    y3 = b[14];
    result[2] = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2 + (s64) x3 * y3) >> 12;
    x0 = a[4];
    x1 = a[5];
    x2 = a[6];
    x3 = a[7];
    result[6] = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2 + (s64) x3 * y3) >> 12;
    result[5] = ((s64) x0 * b[1] + (s64) x1 * b[5] + (s64) x2 * b[9] + (s64) x3 * b[13]) >> 12;
    result[7] = ((s64) x0 * b[3] + (s64) x1 * b[7] + (s64) x2 * b[11] + (s64) x3 * b[15]) >> 12;
    y0 = b[0];
    y1 = b[4];
    y2 = b[8];
    y3 = b[12];
    result[4] = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2 + (s64) x3 * y3) >> 12;
    x0 = a[8];
    x1 = a[9];
    x2 = a[10];
    x3 = a[11];
    result[8] = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2 + (s64) x3 * y3) >> 12;
    result[9] = ((s64) x0 * b[1] + (s64) x1 * b[5] + (s64) x2 * b[9] + (s64) x3 * b[13]) >> 12;
    result[11] = ((s64) x0 * b[3] + (s64) x1 * b[7] + (s64) x2 * b[11] + (s64) x3 * b[15]) >> 12;
    y0 = b[2];
    y1 = b[6];
    y2 = b[10];
    y3 = b[14];
    result[10] = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2 + (s64) x3 * y3) >> 12;
    x0 = a[12];
    x1 = a[13];
    x2 = a[14];
    x3 = a[15];
    result[14] = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2 + (s64) x3 * y3) >> 12;
    result[13] = ((s64) x0 * b[1] + (s64) x1 * b[5] + (s64) x2 * b[9] + (s64) x3 * b[13]) >> 12;
    result[12] = ((s64) x0 * b[0] + (s64) x1 * b[4] + (s64) x2 * b[8] + (s64) x3 * b[12]) >> 12;
    result[15] = ((s64) x0 * b[3] + (s64) x1 * b[7] + (s64) x2 * b[11] + (s64) x3 * b[15]) >> 12;
    if (result == tmp.mUnk_00) {
        *(MtxFx44 *) ab = tmp;
    }
}
