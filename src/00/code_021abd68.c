#include "00/code_021abd68.h"
#include "00/code_021abca0.h"
#include "00/code_021ac3a8.h"

void func_ov000_021ac34c(u32 *a, const u8 *b, u32 c) {
    u32 i;
    for (i = 0; i < c; i += 4) {
        *a++ = (b[i] << 24) | (b[i + 1] << 16) | (b[i + 2] << 8) | b[i + 3];
    }
}

void func_ov000_021abd68(Unk021abca0 *a, const u8 *b) {
    u32 w[16];
    u32 p;
    u32 q;
    u32 r;
    u32 s;
    u32 t;
    u32 i;
    s32 j;
    p = a->mUnk_00;
    q = a->mUnk_04;
    r = a->mUnk_08;
    s = a->mUnk_0c;
    t = a->mUnk_10;
    func_ov000_021ac34c(w, b, 0x40);
    i = 0;
    for (j = 0; j < 3; j++) {
        t += ((p << 5) | (p >> 27)) + (s ^ (q & (r ^ s))) + w[i] + 0x5a827999;
        q = (q << 30) | (q >> 2);
        s += ((t << 5) | (t >> 27)) + (r ^ (p & (q ^ r))) + w[i + 1] + 0x5a827999;
        p = (p << 30) | (p >> 2);
        r += ((s << 5) | (s >> 27)) + (q ^ (t & (p ^ q))) + w[i + 2] + 0x5a827999;
        t = (t << 30) | (t >> 2);
        q += ((r << 5) | (r >> 27)) + (p ^ (s & (t ^ p))) + w[i + 3] + 0x5a827999;
        s = (s << 30) | (s >> 2);
        p += ((q << 5) | (q >> 27)) + (t ^ (r & (s ^ t))) + w[i + 4] + 0x5a827999;
        r = (r << 30) | (r >> 2);
        i += 5;
    }
    t += ((p << 5) | (p >> 27)) + (s ^ (q & (r ^ s))) + w[15] + 0x5a827999;
    q = (q << 30) | (q >> 2);
    s += ((t << 5) | (t >> 27)) + (r ^ (p & (q ^ r))) + func_ov000_021ac3a8(0, w) + 0x5a827999;
    p = (p << 30) | (p >> 2);
    r += ((s << 5) | (s >> 27)) + (q ^ (t & (p ^ q))) + func_ov000_021ac3a8(1, w) + 0x5a827999;
    t = (t << 30) | (t >> 2);
    q += ((r << 5) | (r >> 27)) + (p ^ (s & (t ^ p))) + func_ov000_021ac3a8(2, w) + 0x5a827999;
    s = (s << 30) | (s >> 2);
    p += ((q << 5) | (q >> 27)) + (t ^ (r & (s ^ t))) + func_ov000_021ac3a8(3, w) + 0x5a827999;
    r = (r << 30) | (r >> 2);
    i = 4;
    for (j = 0; j < 4; j++) {
        t += ((p << 5) | (p >> 27)) + (s ^ (q ^ r)) + func_ov000_021ac3a8(i, w) + 0x6ed9eba1;
        q = (q << 30) | (q >> 2);
        s += ((t << 5) | (t >> 27)) + (r ^ (p ^ q)) + func_ov000_021ac3a8(i + 1, w) + 0x6ed9eba1;
        p = (p << 30) | (p >> 2);
        i += 2;
        i &= 0xf;
        r += ((s << 5) | (s >> 27)) + (q ^ (t ^ p)) + func_ov000_021ac3a8(i, w) + 0x6ed9eba1;
        t = (t << 30) | (t >> 2);
        q += ((r << 5) | (r >> 27)) + (p ^ (s ^ t)) + func_ov000_021ac3a8(i + 1, w) + 0x6ed9eba1;
        s = (s << 30) | (s >> 2);
        p += ((q << 5) | (q >> 27)) + (t ^ (r ^ s)) + func_ov000_021ac3a8(i + 2, w) + 0x6ed9eba1;
        r = (r << 30) | (r >> 2);
        i += 3;
    }
    for (j = 0; j < 4; j++) {
        t += ((p << 5) | (p >> 27)) + ((q & (r | s)) | (r & s)) + func_ov000_021ac3a8(i, w) + 0x8f1bbcdc;
        q = (q << 30) | (q >> 2);
        s += ((t << 5) | (t >> 27)) + ((p & (q | r)) | (q & r)) + func_ov000_021ac3a8(i + 1, w) + 0x8f1bbcdc;
        p = (p << 30) | (p >> 2);
        r += ((s << 5) | (s >> 27)) + ((t & (p | q)) | (p & q)) + func_ov000_021ac3a8(i + 2, w) + 0x8f1bbcdc;
        t = (t << 30) | (t >> 2);
        i += 3;
        i &= 0xf;
        q += ((r << 5) | (r >> 27)) + ((s & (t | p)) | (t & p)) + func_ov000_021ac3a8(i, w) + 0x8f1bbcdc;
        s = (s << 30) | (s >> 2);
        p += ((q << 5) | (q >> 27)) + ((r & (s | t)) | (s & t)) + func_ov000_021ac3a8(i + 1, w) + 0x8f1bbcdc;
        r = (r << 30) | (r >> 2);
        i += 2;
    }
    for (j = 0; j < 4; j++) {
        t += ((p << 5) | (p >> 27)) + (s ^ (q ^ r)) + func_ov000_021ac3a8(i, w) + 0xca62c1d6;
        q = (q << 30) | (q >> 2);
        s += ((t << 5) | (t >> 27)) + (r ^ (p ^ q)) + func_ov000_021ac3a8(i + 1, w) + 0xca62c1d6;
        p = (p << 30) | (p >> 2);
        r += ((s << 5) | (s >> 27)) + (q ^ (t ^ p)) + func_ov000_021ac3a8(i + 2, w) + 0xca62c1d6;
        t = (t << 30) | (t >> 2);
        q += ((r << 5) | (r >> 27)) + (p ^ (s ^ t)) + func_ov000_021ac3a8(i + 3, w) + 0xca62c1d6;
        s = (s << 30) | (s >> 2);
        i += 4;
        i &= 0xf;
        p += ((q << 5) | (q >> 27)) + (t ^ (r ^ s)) + func_ov000_021ac3a8(i, w) + 0xca62c1d6;
        r = (r << 30) | (r >> 2);
        i += 1;
    }
    a->mUnk_00 += p;
    a->mUnk_04 += q;
    a->mUnk_08 += r;
    a->mUnk_0c += s;
    a->mUnk_10 += t;
}
