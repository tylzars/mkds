#include "00/code_021a6908.h"
#include "ITCM/code_01ff8000.h"

u32 func_ov000_021a6908(u8 *a) {
    if (*(s32 *) (a + 8) == 0) {
        *(s32 *) (a + 8) = (s32) func_01ff8000;
        *(s32 *) (a + 0xc) = *(s32 *) (a + 0xc) + 1;
        return 1;
    }
    if (*(s32 *) (a + 8) == (s32) func_01ff8000) {
        *(s32 *) (a + 0xc) = *(s32 *) (a + 0xc) + 1;
        return 1;
    }
    return 0;
}
