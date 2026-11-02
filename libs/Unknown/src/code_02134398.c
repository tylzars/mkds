#pragma avoid_byte all

#include "code_02134398.h"
#include "code_02134890.h"
#include "code_0213ee6c.h"
#include "Main/Unknown/unk_0216e000.h"

int func_021343b0(void) {
    int r;
    int i;
    Unk0213c94c *p;

    r = 0;
    i = 1;
    p = data_0216eb7c;
    do {
        if (p->mUnk_04_7 != 0) {
            if (fflush(p) != 0) {
                r = -1;
            }
        }
        p = (i < 3) ? &data_0216eb7c[i++] : 0;
    } while (p != 0);
    return r;
}

double func_02134398(const u8 *a) {
    return data_0216ec9c;
}
