#include "code_0200c858.h"

void StringCopyBounded(s8 *a, const s8 *b, s32 c) {
    s32 i;
    c = c - 1;
    for (i = 0; i < c; i++) {
        a[i] = *b;
        if (*b != 0) {
            b++;
        }
    }
    a[i] = 0;
}
