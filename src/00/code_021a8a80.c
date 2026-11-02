#include "00/code_021a8a80.h"
#include "00/code_021a8aa8.h"
#include "00/unk_021b6000.h"

u32 func_ov000_021a8a80(s32 a) {
    if (a <= 0 || func_ov000_021a8ab8((Unk021a8ab8 **) &data_ov000_021b6004, (Unk021a8ab8 *) a) == NULL) {
        return 1;
    }
    return 0;
}
