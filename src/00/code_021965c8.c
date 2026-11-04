#include "00/code_02190cd4.h"
#include "00/code_021965c8.h"
#include "00/code_0218eb9c.h"
#include "00/code_02196000.h"

#include "00/code_021965a0.h"
#include "code_0213442c.h"
#include "00/code_021967b4.h"
#include "00/unk_021b3000.h"

u32 func_ov000_02196714(GpConnection *a, u32 b, u32 *c) {
    int v1;
    int v2;
    int v3[2];
    v2 = 0;
    v3[0] = 0;
    v1 = func_ov000_0218e68c((u32) (b), (u32 *) (0), (u32 *) (&v2), (u32 *) (v3));
    if (v1 == -1) {
        func_ov000_0219690c(a, data_ov000_021b3a58);
        func_ov000_021965a0(a, 5, data_ov000_021b3a6c);
        func_ov000_02190f4c(a, 3, 1);
        return 3;
    }
    if (0 < v1) {
        if (v3[0] != 0) {
            func_ov000_0219690c(a, data_ov000_021b3aa4);
            *c = 4;
            return 0;
        }
        if (v2 != 0) {
            func_ov000_0219690c(a, data_ov000_021b3abc);
            *c = 3;
            return 0;
        }
    }
    *c = 0;
    return 0;
}

s32 func_ov000_021965c8(GpConnection *a, s8 *b, s32 *c, s8 *d, s8 *e) {
    s8 *p;
    s8 f;
    s32 i;

    if (b == NULL) {
        func_0213442c(data_ov000_021b3a0c, data_ov000_021b3a1c, NULL, 0x199);
    }
    if (d == NULL) {
        func_0213442c(data_ov000_021b3a2c, data_ov000_021b3a1c, NULL, 0x19a);
    }
    if (e == NULL) {
        func_0213442c(data_ov000_021b3a38, data_ov000_021b3a1c, NULL, 0x19b);
    }
    p = b + *c;
    if (*p != 0x5c) {
        func_ov000_021965a0(a, 1, data_ov000_021b3a48);
        func_ov000_02190f4c(a, 3, 1);
        return 3;
    }
    i = 0;
    b = p + 2;
    f = p[1];
    if (f != 0x5c) {
        do {
            if (f == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b3a48);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            if (i == 0x1ff) {
                func_ov000_021965a0(a, 1, data_ov000_021b3a48);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            *d = f;
            d++;
            i++;
            f = *b;
            b++;
        } while (f != 0x5c);
    }
    *d = 0;
    i = 0;
    while ((f = *b++) != 0x5c && f != 0) {
        if (i == 0x1ff) {
            func_ov000_021965a0(a, 1, data_ov000_021b3a48);
            func_ov000_02190f4c(a, 3, 1);
            return 3;
        }
        *e = f;
        e++;
        i++;
    }
    *e = 0;
    *c = *c + ((b - p) - 1);
    return 0;
}
