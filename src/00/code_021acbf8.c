#include "00/code_021acbf8.h"
#include "00/code_021acc68.h"
#include "00/code_021acec8.h"
#include "code_0214d018.h"

void func_ov000_021acbf8(u16 *a, const u16 *b, const u16 *c, s32 n) {
    s32 d;
    s32 e;
    s32 i;
    s32 j;
    const u16 *p;
    const u16 *q;

    MemFill(a, 0, n * 2);
    d = func_ov000_021acec8(b, n);
    e = func_ov000_021acec8(c, n);
    q = c;
    for (i = 0; i < e; i++) {
        j = 0;
        p = b;
        for (; j < d && j < n - i; j++) {
            func_ov000_021acc68(a, *p * *q, i + j, n);
            p++;
        }
        q++;
    }
}
