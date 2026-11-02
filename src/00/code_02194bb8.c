#include "00/code_02194bb8.h"
#include "00/code_02196590.h"
#include "00/code_021a3690.h"
#include "code_0213442c.h"

BOOL func_ov000_02194bb8(Unk0218f960 *a) {
    Unk0218f960_00 *r;
    Unk021937c0Node **v;
    Unk021937c0Node *p;
    Unk02196240 *c;
    u32 t;
    s32 n;
    s32 i;

    r = a->mUnk_00;
    n = 0;
    if (r->mUnk_210 > 0) {
        v = func_ov000_021a3690(r->mUnk_210 * 4);
        if (v == NULL) {
            func_ov000_02196590(a, data_ov000_021b35f8);
            return TRUE;
        }
        for (p = r->mUnk_424; p != NULL; p = p->mNext) {
            if (p->mUnk_00 == 3 && p->mUnk_14 != 5 && p->mUnk_04->mUnk_13c == 0) {
                if (n >= r->mUnk_210) {
                    func_0213442c(data_ov000_021b3608, data_ov000_021b3628, NULL, 0x563);
                }
                v[n++] = p;
                p->mUnk_04->mUnk_13c = 1;
            }
        }
        for (i = 0; i < n; i++) {
            t = func_ov000_02194cac(a, (Unk02194cac *) v[i]);
            if (t != 0) {
                v[i]->mUnk_1c = t;
            }
        }
        for (i = 0; i < n; i++) {
            c = v[i]->mUnk_04;
            c->mUnk_13c = 0;
            if (c->mUnk_140 != 0) {
                func_ov000_02193818(a, v[i]);
            }
        }
        func_ov000_021a3668(v);
    }
    return FALSE;
}
