#include "00/code_021a6908.h"
#include "ITCM/code_01ff8000.h"

u32 func_ov000_021a6908(u8 *a) {
    if (*(int *) (a + 8) == 0) {
        *(int *) (a + 8) = (int) func_01ff8000;
        *(int *) (a + 0xc) = *(int *) (a + 0xc) + 1;
        return 1;
    }
    if (*(int *) (a + 8) == (int) func_01ff8000) {
        *(int *) (a + 0xc) = *(int *) (a + 0xc) + 1;
        return 1;
    }
    return 0;
}
