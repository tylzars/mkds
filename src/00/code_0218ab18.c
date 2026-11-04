#include "00/code_0218a9bc.h"
#include "00/code_0218ab18.h"
#include "00/code_0218acf4.h"
#include "00/code_0218ae68.h"
#include "00/code_0218aea4.h"
#include "00/code_021a4b84.h"
#include "code_02139f70.h"
#include "00/code_0218e2dc.h"

void func_ov000_0218ac54(Unk0218a9bc *p, SbServer *e, s32 a, s32 b) {
    u8 *c;
    c = &e->mUnk_14;
    e->mUnk_14 &= 0xc3;
    if (b == 0) {
        *c |= 4;
    } else if (b == 1) {
        *c |= 8;
    } else if (b == 2) {
        return;
    }
    if (p->mUnk_08.mUnk_08 < p->mUnk_04) {
        func_ov000_0218ad44(p, e);
        return;
    }
    if (a != 0) {
        func_ov000_0218aec4(&p->mUnk_14, e);
    } else {
        func_ov000_0218aedc(&p->mUnk_14, e);
    }
}

void func_ov000_0218ab90(Unk0218a9bc *p, SbServer *e, s8 *v1, s32 n) {
    s32 a;
    s32 b;
    if (v1[0] == 0) {
        v1 += 5;
        n -= 5;
        if ((e->mUnk_14 & 4) != 0) {
            a = 0;
            if (p->mUnk_40 > 0) {
                do {
                    b = func_ov000_0218d0c8(v1, n);
                    if (b < 0) {
                        break;
                    }
                    SbServerSetValue(e, data_ov000_021b45bc[p->mUnk_2c[a]], (const char *) v1);
                    v1 += b;
                    n -= b;
                    a++;
                } while (a < p->mUnk_40);
            }
            e->mUnk_14 |= 0x41;
        } else {
            func_ov000_0218b010(e, v1, n);
            e->mUnk_14 |= 0x43;
        }
        e->mUnk_14 &= 0xf3;
        e->mPing = func_ov000_0218e8c4() - e->mPing;
        func_ov000_0218ae68(&p->mUnk_08, e);
        p->mUnk_44(p, 0, e, p->mUnk_48);
    }
}

void func_ov000_0218ab18(Unk0218a9bc *p, SbServer *e, s8 *v1, s32 n) {
    BOOL a;
    if (strstr((const char *) v1, data_ov000_021b2180) != NULL) {
        a = TRUE;
    } else {
        a = FALSE;
    }
    func_ov000_0218b148(e, v1);
    if (a != FALSE) {
        if ((e->mUnk_14 & 4) != 0) {
            e->mUnk_14 |= 0x41;
        } else {
            e->mUnk_14 |= 0x42;
        }
        e->mUnk_14 &= 0xf3;
        e->mPing = func_ov000_0218e8c4() - e->mPing;
        func_ov000_0218ae68(&p->mUnk_08, e);
        p->mUnk_44(p, 0, e, p->mUnk_48);
    }
}
