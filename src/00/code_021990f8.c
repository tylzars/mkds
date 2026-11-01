#include "00/code_021990f8.h"
#include "00/code_0218dc44.h"
#include "00/code_0218e3c4.h"
#include "00/code_0218e368.h"
#include "00/code_0218e644.h"
#include "00/code_02193818.h"
#include "00/code_021a4868.h"
#include "00/code_02199000.h"
#include "00/code_0219922c.h"
#include "00/code_0219a000.h"
#include "00/code_021992d4.h"
#include "00/code_0219a044.h"
#include "00/code_0218e8c4.h"

typedef struct Unk0219914cHeader {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk0219914cHeader;

u32 func_ov000_0219914c(Unk02197e8c *a) {
    Unk0219914cHeader h;
    u8 v1[0x5dc];
    s32 n;
    s32 r;
    u32 e;
    while (func_ov000_0218e668(a->mUnk_00) != 0) {
        n = 8;
        r = func_ov000_0218e438(a->mUnk_00, v1, 0x5dc, 0, (u8 *) &h, &n);
        if (r == -1) {
            e = func_ov000_0218e368(a->mUnk_00);
            if (e == -15) {
                if (func_ov000_0219922c((int) a, h.mUnk_04,
                                        (u16) (((h.mUnk_02 >> 8) & 0xff) | ((h.mUnk_02 << 8) & 0xff00))) == 0) {
                    return 0;
                }
            } else if (e != -35) {
                func_ov000_0219a044(a);
                return 0;
            }
        } else {
            if (func_ov000_021992d4(a, v1, r, h.mUnk_04,
                                    (u16) (((h.mUnk_02 >> 8) & 0xff) | ((h.mUnk_02 << 8) & 0xff00))) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

u32 func_ov000_021990f8(Unk02197fe8 *a, u16 b, s32 c) {
    Unk021990f8Entry d = {0, 0, 0, {0, 0}, 0};
    s32 e;
    d.mUnk_00 = a->mUnk_50.mUnk_08;
    d.mUnk_04 = c;
    d.mUnk_08 = b;
    d.mUnk_0c = func_ov000_0218e8c4();
    e = func_ov000_0218dc44(a->mUnk_60);
    func_ov000_0218dbc0(a->mUnk_60, &d);
    if (e + 1 == func_ov000_0218dc44(a->mUnk_60)) {
        return 1;
    }
    return 0;
}
