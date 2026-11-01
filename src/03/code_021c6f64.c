#include "03/code_021c6f64.h"

// non-matching: same instructions, registers differ (loop pointer and counters swapped: ours r7 count, r6 offset, r2
// object; original r5, r3, r7), size 0xf0 against 0xec
s32 func_ov003_021c6f64(void) {
    u8 a[4];
    u8 b[4];
    u8 *k;
    u8 *j;
    s32 c;
    s32 e;
    s32 d;
    u8 *i;
    s32 z;
    s32 f;
    s32 g;
    s32 h;
    a[0] = data_ov003_021d72fc[0];
    a[1] = data_ov003_021d72fc[1];
    a[2] = data_ov003_021d72fc[2];
    a[3] = data_ov003_021d72fc[3];
    c = 0;
    d = c;
    k = (u8 *) data_ov003_021da1fc;
    z = c;
    do {
        if ((k + 8)[d] != 0x20) {
            j = k + 8 + d;
            i = a;
            for (e = z; e < 3; e++) {
                if (j[e] > *i) {
                    return 0;
                }
                if (j[e] < *i) {
                    break;
                }
                i++;
            }
        }
        d += 3;
        c++;
    } while (c < 4);
    k += 8;
    func_ov003_021cd2e0((char *) k, b);
    func_ov003_021c20dc(&f, 0);
    if (f == 1) {
        g = 0;
        h = 0;
        i = b;
        do {
            for (e = 0; e < 8; e++) {
                if (g != 0) {
                    if ((*i & (1 << (7 - e))) != 0) {
                        return 0;
                    }
                } else if ((*i & (1 << (7 - e))) == 0) {
                    g = 1;
                }
            }
            i++;
            h++;
        } while (h < 4);
        return 1;
    }
    if (func_02151620(b) != 0) {
        return 1;
    }
    return 0;
}
