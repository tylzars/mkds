#include "00/code_0219a61c.h"
#include "code_02139f70.h"
#include "00/code_0219a000.h"

void func_ov000_0219a61c(const char **a, s32 *b) {
    if (*a == NULL) {
        *a = data_ov000_021b3fc8;
        *b = 0;
    } else if (*b == -1) {
        *b = strlen(*a) + 1;
    }
}
