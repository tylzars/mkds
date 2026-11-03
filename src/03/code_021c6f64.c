#include "03/code_021c6f64.h"
#include "03/code_021cd2e0.h"
#include "03/unk_021da000.h"
#include "code_021510a4.h"

BOOL func_ov003_021c6f64(void) {
    u8 a[4];
    u8 *k;
    u8 *j;
    s32 c;
    s32 e;
    s32 d;
    u8 *i;
    s32 f;
    u8 b[4];
    BOOL g;
    s32 h;
    u8 *m;
    a[0] = data_ov003_021d72fc[0];
    a[1] = data_ov003_021d72fc[1];
    a[2] = data_ov003_021d72fc[2];
    a[3] = data_ov003_021d72fc[3];
    c = 0;
    d = 0;
    k = (u8 *) data_ov003_021da1fc;
    do {
        j = k + 8 + d;
        if (*j != 0x20) {
            for (e = 0, i = a; e < 3; e++) {
                if (j[e] > *i) {
                    return FALSE;
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
    func_ov003_021c20dc(&f, NULL);
    if (f == 1) {
        g = FALSE;
        h = 0;
        m = b;
        do {
            for (e = 0; e < 8; e++) {
                if (g != FALSE) {
                    if ((*m & (1 << (7 - e))) != 0) {
                        return FALSE;
                    }
                } else if ((*m & (1 << (7 - e))) == 0) {
                    g = TRUE;
                }
            }
            m++;
            h++;
        } while (h < 4);
        return TRUE;
    }
    if (func_02151620(b) != 0) {
        return TRUE;
    }
    return FALSE;
}
