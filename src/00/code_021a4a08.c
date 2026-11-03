#include "00/code_021a4a08.h"
#include "00/code_021a3690.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "00/code_021a4654.h"
#include "code_021384cc.h"
#include "code_02135014.h"
#include "code_02139f70.h"
#include "00/code_0218e8c4.h"

s32 func_ov000_021a4a08(Unk021a4a08 **a, s32 b, s32 c, const char *d, const char *e, s32 f, s32 g, Unk021a4a08Func88 h,
                        Unk021a4a08Func8c i, Unk021a4a08Func8c j, Unk021a4a08Func94 k, Unk021a4a08Func98 l,
                        Unk021a4a08Func9c m, void *n) {
    char p[0x40];
    s32 r;
    s8 s;
    s32 t;
    Unk021a4a08 *o;

    if (a == NULL) {
        o = &data_ov000_021b4278;
    } else {
        *a = func_ov000_021a3690(0x110);
        o = *a;
    }
    srand(func_ov000_0218e8c4());
    strcpy((char *) o->mUnk_004, d);
    strcpy((char *) o->mUnk_044, e);
    o->mUnk_0c0 = c;
    r = 0;
    o->mUnk_0ac = 0;
    o->mUnk_0b0 = 0;
    o->mUnk_000 = b;
    o->mUnk_0b8 = 1;
    o->mUnk_10c = n;
    o->mUnk_088 = h;
    o->mUnk_08c = i;
    o->mUnk_090 = j;
    o->mUnk_094 = k;
    o->mUnk_098 = l;
    o->mUnk_09c = m;
    o->mUnk_0a0 = 0;
    o->mUnk_0a4 = 0;
    o->mUnk_0d4 = 0;
    o->mUnk_0bc = f;
    o->mUnk_0c4 = 0;
    o->mUnk_0c8 = g;
    o->mUnk_104 = 0;
    o->mUnk_108 = 0;
    o->mUnk_0a8 = NULL;
    o->mUnk_0b4 = 0;
    do {
        o->mUnk_084[r] = (s32) rand() % 0xff;
        r++;
    } while (r < 4);
    r = 0;
    do {
        o->mUnk_0d8[r] = -1;
        r++;
    } while (r < 10);
    o->mUnk_100 = 0;
    if (data_ov000_021b5df8 == 0) {
        func_ov000_021a46d4();
    }
    if (f != 0) {
        s = data_ov000_021b5e10[0];
        if (s == 0) {
            sprintf(p, data_ov000_021b4464, d);
        }
        t = func_ov000_021a4654(s != 0 ? data_ov000_021b5e10 : p, 0x6cfc, &o->mUnk_0cc, NULL);
    } else {
        t = 1;
    }
    if (t != 0) {
        return 0;
    }
    return 3;
}
