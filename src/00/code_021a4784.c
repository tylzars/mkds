#include "00/code_021a4784.h"
#include "00/code_021a39d8.h"
#include "00/code_021a4000.h"

#include "00/code_0218e49c.h"
#include "00/code_021a3668.h"
#include "00/code_021a3000.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e8c4.h"
#include "00/code_0218e3c4.h"

void func_ov000_021a49f4(void *a, UnkFunc *b) {
    if (a == NULL) {
        a = data_ov000_021b426c;
    }
    *(UnkFunc **) ((u8 *) a + 0xa0) = b;
    return;
}

void func_ov000_021a49e0(void *a, UnkFunc *b) {
    if (a == NULL) {
        a = data_ov000_021b426c;
    }
    *(UnkFunc **) ((u8 *) a + 0xa4) = b;
    return;
}

void func_ov000_021a49cc(void *a, void (*b)(void *, u16)) {
    if (a == NULL) {
        a = data_ov000_021b426c;
    }
    *(void (**)(void *, u16))((u8 *) a + 0xa8) = b;
    return;
}

void func_ov000_021a49a0(Unk021a4a08 *a) {
    if (a == NULL) {
        a = data_ov000_021b426c;
    }
    if (a->mUnk_0bc != 0) {
        func_ov000_021a4868(a);
    }
    func_ov000_021a4940(a);
    return;
}

void func_ov000_021a4940(Unk021a4a08 *a) {
    u8 b[8];
    s32 c;
    s32 d;
    s32 e;

    c = 8;
    if (a->mUnk_0c4 != 0 && func_ov000_0218e668(a->mUnk_000) != 0) {
        d = 0;
        do {
            e = func_ov000_0218e438(a->mUnk_000, data_ov000_021b5e50, 0xff, d, b, &c);
            if (e != ~d) {
                data_ov000_021b5e50[e] = d;
                func_ov000_021a3c14((Unk021a3a18 *) a, data_ov000_021b5e50, e, b);
            }
        } while (func_ov000_0218e668(a->mUnk_000) != 0);
    }
}

void func_ov000_021a4868(Unk021a4a08 *a) {
    u32 b;
    s32 c;

    b = func_ov000_0218e8c4();
    if (a->mUnk_000 != -1) {
        c = a->mUnk_0b8;
        if (c > 0 && b - a->mUnk_0ac > 10000) {
            if (c >= 4) {
                a->mUnk_0b8 = 0;
                a->mUnk_09c(5, data_ov000_021b442c, a->mUnk_10c);
                return;
            }
            func_ov000_021a3a18((Unk021a3a18 *) a, 3);
            a->mUnk_0b8 = a->mUnk_0b8 + 1;
        } else if (a->mUnk_0b4 != 0 && b - a->mUnk_0ac > 10000) {
            func_ov000_021a3a18((Unk021a3a18 *) a, 1);
        } else if (b - a->mUnk_0ac > 60000 || a->mUnk_0ac == 0 || b < a->mUnk_0ac) {
            func_ov000_021a3a18((Unk021a3a18 *) a, 0);
        }
        if (b - a->mUnk_0b0 > 20000) {
            func_ov000_021a3bbc((Unk021a3a18 *) a);
        }
    }
}

void func_ov000_021a4818(Unk021a4a08 *a) {
    int v1;
    if (a == NULL) {
        a = data_ov000_021b426c;
    }
    if (a->mUnk_0bc != 0) {
        v1 = func_ov000_0218e8c4();
        if ((u32) (v1 - a->mUnk_0ac) < ((u32) 0x00002710u)) {
            a->mUnk_0b4 = 1;
            return;
        }
        func_ov000_021a3a18((Unk021a3a18 *) a, 1);
        a->mUnk_0b4 = 0;
    }
    return;
}

void func_ov000_021a47ac(Unk021a4a08 *a) {
    if (a == NULL) {
        a = data_ov000_021b426c;
    }
    if (a->mUnk_0bc != 0) {
        func_ov000_021a3a18((Unk021a3a18 *) a, 2);
    }
    if (a->mUnk_000 != -1 && a->mUnk_0c4 != 0) {
        func_ov000_0218e53c(a->mUnk_000);
    }
    a->mUnk_000 = -1;
    a->mUnk_0ac = 0;
    if (a->mUnk_0c4 != 0) {
        func_ov000_0218e8b4();
    }
    if (a != &data_ov000_021b4278) {
        func_ov000_021a3668(a);
    }
}

void func_ov000_021a4784(u32 a, int b) {
    int v1;
    v1 = *(s32 *) (a + 0x100);
    if (((v1 < 0xfe) && (1 <= b)) && (b <= 254)) {
        *(s32 *) (a + 0x100) = v1 + 1;
        *(s8 *) (a + v1) = (s8) b;
    }
}
