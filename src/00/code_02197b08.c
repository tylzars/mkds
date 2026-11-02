#include "00/code_02197b08.h"

BOOL func_ov000_02197b08(const u8 *left, const u8 *right) {
    s32 i;
    for (i = 0; i < 0x20; i++) {
        if (i != 0 && i != 0xd && left[i] != right[i]) {
            return FALSE;
        }
    }
    return TRUE;
}
