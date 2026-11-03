#include "00/code_02193818.h"
#include "00/code_021960a4.h"
#include "00/code_0218e49c.h"
#include "00/code_0218f15c.h"

int func_ov000_021961e8(GpConnection *a, u32 b, u32 c, u32 d, u32 e) {
    int v1;
    int v2;
    a->mGpiConnection->mSearchCount = a->mGpiConnection->mSearchCount + 1;
    v1 = func_ov000_021938cc(a, 3, b, &v2, c, d, e);
    if (((v1 == 0) && (v1 = func_ov000_021962d4(a, (Unk021937c0Node *) v2), v1 == 0)) &&
        ((*(s32 *) (v2 + 8) == 0 || (v1 = func_ov000_0218f2e8(a, *(u32 *) (v2 + 0x18)), v1 == 0)))) {
        v1 = 0;
    }
    return v1;
}

int func_ov000_021960a4(GpConnection *a, s8 *b, s8 *c, s8 *d, s8 *e, s8 *f, int g, int h, u32 l, u32 m, u32 n) {
    int v1;
    int v2[2];
    if ((((((b == NULL) || (*b == 0)) && ((d == NULL || (*d == 0)))) && ((e == NULL || (*e == 0)))) &&
         ((f == NULL || (*f == 0)))) &&
        ((g == 0 && ((c == NULL || (*c == 0)))))) {
        func_ov000_02196590((u32 *) a, data_ov000_021b38ac);
        return 2;
    }
    v1 = func_ov000_02196240(a, (Unk02196240 **) v2, (u32) 1);
    if (v1 == 0) {
        if (b == NULL) {
            *(u8 *) (v2[0] + 0x28) = 0;
        } else {
            func_ov000_02196914((u8 *) (v2[0] + 0x28), b, 0x1f);
        }
        if (c == NULL) {
            *(u8 *) (v2[0] + 0x47) = 0;
        } else {
            func_ov000_02196914((u8 *) (v2[0] + 0x47), c, 0x15);
        }
        if (d == NULL) {
            *(u8 *) (v2[0] + 0x5c) = 0;
        } else {
            func_ov000_02196914((u8 *) (v2[0] + 0x5c), d, 0x33);
        }
        func_ov000_0218e850((s8 *) ((s8 *) (u32) (v2[0] + 0x5c)));
        if (e == NULL) {
            *(u8 *) (v2[0] + 0x8f) = 0;
        } else {
            func_ov000_02196914((u8 *) (v2[0] + 0x8f), e, 0x1f);
        }
        if (f == NULL) {
            *(u8 *) (v2[0] + 0xae) = 0;
        } else {
            func_ov000_02196914((u8 *) (v2[0] + 0xae), f, 0x1f);
        }
        *(s32 *) (v2[0] + 0x130) = g;
        if (h < 0) {
            h = 0;
        }
        *(s32 *) (v2[0] + 0x134) = h;
        v1 = func_ov000_021961e8(a, (u32) (v2[0]), l, m, n);
        if (v1 == 0) {
            v1 = 0;
        }
    }
    return v1;
}
