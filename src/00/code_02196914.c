#include "00/code_02196914.h"
#include "00/unk_021b3000.h"
#include "code_02134398.h"
#include "code_02139f70.h"

void GpiCopyString(char *dest, const char *src, s32 c) {
    if (dest == NULL) {
        AssertionFailed(data_ov000_021b3b10, data_ov000_021b3a1c, NULL, 0x2f);
    }
    if (src == NULL) {
        AssertionFailed(data_ov000_021b3b20, data_ov000_021b3a1c, NULL, 0x30);
    }
    strncpy(dest, src, c);
    *(dest + c + -1) = 0;
    return;
}
