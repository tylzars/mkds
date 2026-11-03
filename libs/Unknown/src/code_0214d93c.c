#include "code_0214d93c.h"
#include "code_0214d954.h"

// Waits while the first word of data_021803b0 is 1.
// non-matching: the address of data_021803b0 is held in r1 and the value in r0; the original holds the address in ip.
void func_0214d93c(void) {
    vu32 *p = &data_021803b0.mUnk_00;

    while (*p == 1) {
    }
}
