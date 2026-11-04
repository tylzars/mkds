#include "00/code_021a4654.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e368.h"
#include "00/unk_021b5000.h"
#include "code_02134d30.h"
#include "code_02135014.h"
#include "code_02139f70.h"

static inline u16 func_ov000_021a4654_inline(u16 v1) {
    return ((v1 >> 8) & 0xff) | ((v1 << 8) & 0xff00);
}

void func_ov000_021a4760(Unk021a471c *a, s32 b) {
    char c[0x18];

    sprintf(c, data_ov000_021b4428, b);
    func_ov000_021a471c(a, c);
}

void func_ov000_021a471c(Unk021a471c *a, const char *b) {
    s32 c;
    s32 d;

    c = strlen(b) + 1;
    d = 0x800 - a->mUnk_800;
    if (c > d) {
        c = d;
    }
    if (c != 0) {
        memcpy(&a->mUnk_000[a->mUnk_800], b, c);
        a->mUnk_800 += c;
        a->mUnk_000[a->mUnk_800 - 1] = 0;
    }
}

void func_ov000_021a46d4(void) {
    Unk021a8f84 *a;
    Unk021a46d4 *b;
    Unk021a46d4 *d;

    a = func_ov000_0218e5e4();
    if (a != NULL) {
        data_ov000_021b5df8 = 0;
        d = (Unk021a46d4 *) data_ov000_021b5dfc;
        for (; data_ov000_021b5df8 < 5; data_ov000_021b5df8++) {
            b = (Unk021a46d4 *) a->mUnk_0c[data_ov000_021b5df8];
            if (b == NULL) {
                break;
            }
            d[data_ov000_021b5df8] = *b;
        }
    }
}

BOOL func_ov000_021a4654(const char *a, u32 b, Unk021a4654 *c, Unk021a8f84 **d) {
    Unk021a8f84 *e;

    e = NULL;
    c->mUnk_01 = 2;
    c->mUnk_02 = func_ov000_021a4654_inline(b);
    if (a == NULL) {
        c->mUnk_04 = 0;
    } else {
        c->mUnk_04 = func_ov000_0218e374((u32) a);
    }
    if (c->mUnk_04 == -1) {
        if (strcmp(a, data_ov000_021b4418) != 0) {
            e = func_ov000_021a8f84(a);
            if (e == NULL) {
                return FALSE;
            }
            c->mUnk_04 = **e->mUnk_0c;
        }
    }
    if (d != NULL) {
        *d = e;
    }
    return TRUE;
}
