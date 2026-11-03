#include "00/code_021ab728.h"
#include "00/code_021ab7e8.h"
#include "00/code_021abc04.h"
#include "00/unk_021b4000.h"

void func_ov000_021ab7e8(Unk021ab728 *a, const u8 *b) {
    u32 w[16];
    u32 p;
    u32 q;
    u32 r;
    u32 s;
    u32 i;
    s32 j;
    p = a->mUnk_00;
    q = a->mUnk_04;
    r = a->mUnk_08;
    s = a->mUnk_0c;
    func_ov000_021abc04(w, b, 0x40);
    i = 0;
    for (j = 0; j < 4; j++) {
        p += (s ^ (q & (r ^ s))) + w[data_ov000_021b4a64[i]] + data_ov000_021b4ae4[i];
        p = q + ((p << 7) | (p >> 25));
        s += (r ^ (p & (q ^ r))) + w[data_ov000_021b4a64[i + 1]] + data_ov000_021b4ae4[i + 1];
        s = p + ((s << 12) | (s >> 20));
        r += (q ^ (s & (p ^ q))) + w[data_ov000_021b4a64[i + 2]] + data_ov000_021b4ae4[i + 2];
        r = s + ((r << 17) | (r >> 15));
        q += (p ^ (r & (s ^ p))) + w[data_ov000_021b4a64[i + 3]] + data_ov000_021b4ae4[i + 3];
        q = r + ((q << 22) | (q >> 10));
        i += 4;
    }
    for (j = 0; j < 4; j++) {
        p += ((q & s) | (r & ~s)) + w[data_ov000_021b4a64[i]] + data_ov000_021b4ae4[i];
        p = q + ((p << 5) | (p >> 27));
        s += ((p & r) | (q & ~r)) + w[data_ov000_021b4a64[i + 1]] + data_ov000_021b4ae4[i + 1];
        s = p + ((s << 9) | (s >> 23));
        r += ((s & q) | (p & ~q)) + w[data_ov000_021b4a64[i + 2]] + data_ov000_021b4ae4[i + 2];
        r = s + ((r << 14) | (r >> 18));
        q += ((r & p) | (s & ~p)) + w[data_ov000_021b4a64[i + 3]] + data_ov000_021b4ae4[i + 3];
        q = r + ((q << 20) | (q >> 12));
        i += 4;
    }
    for (j = 0; j < 4; j++) {
        p += (s ^ (q ^ r)) + w[data_ov000_021b4a64[i]] + data_ov000_021b4ae4[i];
        p = q + ((p << 4) | (p >> 28));
        s += (r ^ (p ^ q)) + w[data_ov000_021b4a64[i + 1]] + data_ov000_021b4ae4[i + 1];
        s = p + ((s << 11) | (s >> 21));
        r += (q ^ (s ^ p)) + w[data_ov000_021b4a64[i + 2]] + data_ov000_021b4ae4[i + 2];
        r = s + ((r << 16) | (r >> 16));
        q += (p ^ (r ^ s)) + w[data_ov000_021b4a64[i + 3]] + data_ov000_021b4ae4[i + 3];
        q = r + ((q << 23) | (q >> 9));
        i += 4;
    }
    for (j = 0; j < 4; j++) {
        p += (r ^ (q | ~s)) + w[data_ov000_021b4a64[i]] + data_ov000_021b4ae4[i];
        p = q + ((p << 6) | (p >> 26));
        s += (q ^ (p | ~r)) + w[data_ov000_021b4a64[i + 1]] + data_ov000_021b4ae4[i + 1];
        s = p + ((s << 10) | (s >> 22));
        r += (p ^ (s | ~q)) + w[data_ov000_021b4a64[i + 2]] + data_ov000_021b4ae4[i + 2];
        r = s + ((r << 15) | (r >> 17));
        q += (s ^ (r | ~p)) + w[data_ov000_021b4a64[i + 3]] + data_ov000_021b4ae4[i + 3];
        q = r + ((q << 21) | (q >> 11));
        i += 4;
    }
    a->mUnk_00 += p;
    a->mUnk_04 += q;
    a->mUnk_08 += r;
    a->mUnk_0c += s;
}
