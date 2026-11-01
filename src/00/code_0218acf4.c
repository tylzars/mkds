#include "00/code_0218acf4.h"
#include "00/code_0218ae5c.h"
#include "00/code_0218aea4.h"
#include "00/code_0218e3c4.h"
#include "00/code_0218e554.h"
#include "00/code_0218e8b4.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e8c4.h"

void func_ov000_0218acf4(Unk0218a9bc *p, s32 a, u32 b, s32 c, UnkFunc *f, void *g) {
    if (c == 0 && data_ov000_021b4d28 != 1) {
        return;
    }
    func_ov000_0218e8b8();
    p->mUnk_00 = b;
    p->mUnk_04 = a;
    p->mUnk_40 = 0;
    p->mUnk_44 = f;
    p->mUnk_48 = g;
    p->mUnk_28 = 0;
    p->mUnk_20 = func_ov000_0218e554(2, 2, 0);
    func_ov000_0218ae5c((u32 *) &p->mUnk_14);
    func_ov000_0218ae5c((u32 *) &p->mUnk_08);
}

void func_ov000_0218ad44(Unk0218a9bc *p, Unk0218af28 *e) {
    Unk0218aa14 a;
    u8 b[0x100];
    s32 c;
    s32 i;
    func_ov000_0218aedc((int *) &p->mUnk_08, (int) e);
    e->mUnk_1c = func_ov000_0218e8c4();
    a.mUnk_01 = 2;
    if ((e->mUnk_14 & 0x20) == 0) {
        if (p->mUnk_00 == 1) {
            b[0] = 0xfe;
            b[1] = 0xfd;
            b[2] = 0;
            __memcpy(&b[3], &e->mUnk_1c, 4);
            if ((e->mUnk_14 & 4) != 0) {
                b[7] = p->mUnk_40;
                for (i = 0; i < p->mUnk_40; i++) {
                    b[i + 8] = p->mUnk_2c[i];
                }
                b[p->mUnk_40 + 8] = 0;
                b[p->mUnk_40 + 9] = 0;
                c = p->mUnk_40 + 10;
            } else {
                b[7] = 0xff;
                b[8] = 0xff;
                b[9] = 0xff;
                c = 10;
            }
        } else if ((e->mUnk_14 & 4) != 0) {
            __memcpy(b, &data_ov000_021b2188, 13);
            c = 13;
        } else {
            __memcpy(b, &data_ov000_021b2198, 8);
            c = 8;
        }
        if (e->mUnk_00 == p->mUnk_28 && (e->mUnk_15 & 2) != 0) {
            a.mUnk_04 = e->mUnk_08;
            a.mUnk_02 = e->mUnk_0c;
        } else {
            a.mUnk_04 = e->mUnk_00;
            a.mUnk_02 = e->mUnk_04;
        }
        func_ov000_0218e3e4(p->mUnk_20, b, c, 0, &a, 8);
    }
}
