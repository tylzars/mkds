#include "00/code_0218e80c.h"
#include "00/code_021a3690.h"
#include "00/code_021a8dd8.h"
#include "code_02139f70.h"
#include "code_0214177c.h"

void *func_ov000_0218e880(u8 *a) {
    void *b;
    if (a == 0) {
        return 0;
    }
    b = func_ov000_021a3690(func_0213a434(a) + 1);
    if (b != 0) {
        func_0213a2d0(b, a);
    }
    return b;
}

s8 *func_ov000_0218e850(s8 *a) {
    s32 c;
    s8 *b;
    b = a;
    c = *a;
    if (c != 0) {
        do {
            if (c >= 0 && c < 0x80) {
                c = data_0215d184[c];
            }
            *a = c;
            a++;
            c = *a;
        } while (c != 0);
    }
    return b;
}

s32 func_ov000_0218e80c(s32 a, s32 b) {
    s32 c;
    c = func_ov000_021a8dd8((Unk021a6fa8 *) a, 3, 0);
    if (b != 0) {
        c = c & ~4;
    } else {
        c = c | 4;
    }
    return func_ov000_021a8dd8((Unk021a6fa8 *) a, 4, c) == 0;
}
