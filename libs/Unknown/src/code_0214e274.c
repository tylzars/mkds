#include "code_0214e274.h"
#include "Main/Unknown/unk_0216f000.h"

// Returns -1 when a field of a is out of range (mUnk_00 below 100, mUnk_04 in 1..12, mUnk_08 in 1..31, mUnk_0c below
// 7); otherwise mUnk_08 - 1 + data_0216f074[mUnk_04], plus 1 when mUnk_04 >= 3 and mUnk_00 is a multiple of 4, plus
// mUnk_00 * 365 + (mUnk_00 + 3) / 4.
s32 DateToDays(const Unk0214e1e0 *a) {
    u32 y;
    u32 m;
    u32 d;
    u32 n;

    if ((y = a->mUnk_00) >= 100 || (m = a->mUnk_04) < 1 || m > 12 || (d = a->mUnk_08) < 1 || d > 31 ||
        a->mUnk_0c >= 7 || m < 1 || m > 12) {
        return -1;
    }
    n = d - 1 + data_0216f074[m];
    if (m >= 3 && (y & 3) == 0) {
        n++;
    }
    return y * 365 + n + ((y + 3) >> 2);
}
