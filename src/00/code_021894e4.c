#include "00/code_02188ec0.h"
#include "00/code_021894e4.h"
#include "00/unk_021b0000.h"
#include "00/unk_021b2000.h"
#include "code_0214d018.h"

u8 func_ov000_021894e4(s32 a, Unk02188ec0_444 *b, Unk02188ec0_300 *c, Unk02188ee0 *d) {
    u8 n;
    u8 i;
    u8 j;

    n = 0;
    for (i = 0; i < a; b++, d++, i++) {
        if (i >= 9) {
            break;
        }
        if (b->mUnk_00 == 0 && d->mUnk_36 != b->mUnk_03) {
            for (j = 0; j < 0x20; j++) {
                if (d->mUnk_0c[j] == 0) {
                    break;
                }
                c->mUnk_04[j] = d->mUnk_0c[j];
            }
            c->mUnk_03 = j;
            c->mUnk_02 = d->mUnk_36 - 1;
            c++;
            n++;
        }
    }
    return n;
}

u8 func_ov000_0218954c(Unk02188ec0 *v1) {
    s32 i;
    u8 n;
    u8 j;
    BOOL v2;
    Unk02188db0 *e;
    Unk02188ec0_300 *c;

    n = 0;
    e = v1->mUnk_000;
    c = v1->mUnk_300;
    for (i = 0; i < 3; e++, i++) {
        if (v1->mUnk_d0c == 0 || v1->mUnk_d0c == i + 1) {
            if (e->mUnk_e7 != 0xff) {
                for (j = 0; j < 0x20; j++) {
                    if (e->mUnk_40[j] == 0) {
                        break;
                    }
                    c->mUnk_04[j] = e->mUnk_40[j];
                }
                if (j != 0) {
                    c->mUnk_03 = j;
                    c->mUnk_01 = i;
                    v2 = TRUE;
                } else {
                    v2 = FALSE;
                }
                if (v2 != FALSE) {
                    n++;
                    c++;
                }
                if (e->mUnk_e7 == 1) {
                    for (j = 0; j < 0x20; j++) {
                        if (e->mUnk_60[j] == 0) {
                            break;
                        }
                        c->mUnk_04[j] = e->mUnk_60[j];
                    }
                    if (j != 0) {
                        c->mUnk_03 = j;
                        c->mUnk_01 = i + 3;
                        v2 = TRUE;
                    } else {
                        v2 = FALSE;
                    }
                    if (v2 != FALSE) {
                        n++;
                        c++;
                    }
                }
            }
        }
    }
    return n;
}

u8 func_ov000_02189614(Unk02188ec0 *v1) {
    u8 n;
    Unk02188ec0_300 *c;

    c = v1->mUnk_300;
    n = func_ov000_0218954c(v1);
    c += n;
    if (v1->mUnk_d0c == 0 || v1->mUnk_d0c == 4) {
        func_0214d1fc(data_ov000_021b20d0, c->mUnk_04, 8);
        c->mUnk_03 = 8;
        c->mUnk_01 = 6;
        n++;
        c++;
    }
    if (v1->mUnk_d0c == 0 || v1->mUnk_d0c == 7) {
        func_0214d1fc(data_ov000_021b06e8, c->mUnk_04, 8);
        c->mUnk_03 = 8;
        c->mUnk_01 = 9;
        n++;
        c++;
    }
    if (v1->mUnk_d0c == 0 || v1->mUnk_d0c == 8) {
        func_0214d1fc(data_ov000_021b06f8, c->mUnk_04, 0xb);
        c->mUnk_03 = 0xb;
        c->mUnk_01 = 10;
        n++;
    }
    return n;
}

u8 func_ov000_021896c4(Unk02188ec0 *v1) {
    u8 n;
    Unk02188ec0_300 *c;

    c = v1->mUnk_300;
    n = func_ov000_0218954c(v1);
    c += n;
    if (v1->mUnk_d0c == 0 || v1->mUnk_d0c == 6) {
        func_0214d1fc(data_ov000_021b06f0, c->mUnk_04, 8);
        c->mUnk_03 = 8;
        c->mUnk_01 = 8;
        n++;
    }
    return n;
}
