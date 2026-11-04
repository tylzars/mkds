#pragma avoid_byte all

#include "code_02134398.h"
#include "code_02134890.h"
#include "code_0213ee6c.h"
#include "Main/Unknown/unk_0216e000.h"

int FflushAll(void) {
    int r;
    int i;
    FILE *p;

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

double nan(const char *a) {
    return data_0216ec9c;
}
