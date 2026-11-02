#include "00/code_0218a9bc.h"
#include "00/code_0218ab14.h"
#include "00/code_0218ab18.h"
#include "00/code_0218aea4.h"
#include "00/code_0218e3c4.h"
#include "00/code_021a39d8.h"
#include "00/code_021a4784.h"
#include "00/code_0218e49c.h"
#include "00/code_0218e8c4.h"

void func_ov000_0218aa14(Unk0218a9bc *p, s32 q) {
    s32 s;
    Unk0218aa14 v1;
    s32 a;
    s32 n;
    Unk0218af28 *e;
    s8 v2[0x800];
    a = 8;
    if (q != 0) {
        s = p->mUnk_24;
    } else {
        s = p->mUnk_20;
    }
    while (func_ov000_0218e668(s) != 0) {
        n = func_ov000_0218e438(s, v2, 0x7ff, 0, &v1, &a);
        if (n == -1) {
            break;
        }
        v2[n] = 0;
        for (e = p->mUnk_08.mUnk_00; e != 0; e = e->mUnk_20) {
            if ((q != 0 && (e->mUnk_15 & 8) != 0 && e->mUnk_10 == v1.mUnk_04) ||
                (e->mUnk_00 == v1.mUnk_04 && (e->mUnk_04 == v1.mUnk_02 || q != 0)) ||
                (e->mUnk_00 == p->mUnk_28 && (e->mUnk_15 & 2) != 0 && e->mUnk_08 == v1.mUnk_04 &&
                 e->mUnk_0c == v1.mUnk_02)) {
                if (q != 0) {
                    if (func_ov000_0218ab14(p, e, v2, n) != 0) {
                        break;
                    }
                } else {
                    if (p->mUnk_00 == 1) {
                        func_ov000_0218ab90(p, e, v2, n);
                    } else {
                        func_ov000_0218ab18(p, e, v2, n);
                    }
                    break;
                }
            }
        }
    }
}

void func_ov000_0218a9bc(Unk0218a9bc *p) {
    u32 a;
    Unk0218af28 *e;
    a = func_ov000_0218e8c4();
    e = p->mUnk_08.mUnk_00;
    while (e != 0) {
        if (a <= e->mUnk_1c + 0x9c4) {
            break;
        }
        e->mUnk_15 |= 0x10;
        p->mUnk_08.mUnk_00->mUnk_1c = 0x9c4;
        p->mUnk_08.mUnk_00->mUnk_15 &= 0xd3;
        p->mUnk_44(p, 1, p->mUnk_08.mUnk_00, p->mUnk_48);
        func_ov000_0218aea4((s32 *) &p->mUnk_08);
        e = p->mUnk_08.mUnk_00;
    }
}
