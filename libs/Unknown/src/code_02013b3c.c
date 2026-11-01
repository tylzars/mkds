#include "code_02013b3c.h"
#include "code_02013b20.h"

Unk02013b3c_t *func_02013b3c(const void *a, u16 b, u32 c) {
    Unk02013b3c_e *p;
    Unk02013b3c_t *tab;
    u32 i;

    p = func_02013b20(a, b);
    i = p->mUnk_04;
    tab = (Unk02013b3c_t *) ((const u8 *) a + p->mUnk_06);
    i = (i * c) >> 12;
    while (i != 0 && tab[i].mUnk_00 >= c) {
        i--;
    }
    while (i + 1 < p->mUnk_00 && (&tab[i])[1].mUnk_00 <= c) {
        i++;
    }
    return &tab[i];
}
