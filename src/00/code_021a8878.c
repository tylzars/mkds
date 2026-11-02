#include "00/code_021a8878.h"
#include "00/code_021a6fa8.h"
#include "00/code_021a86bc.h"

u32 func_ov000_021a8878(u32 first, u32 second) {
    if (func_ov000_021a8830() == 0) {
        return 0xffffffd9;
    }
    data_ov000_021b63d8[0] = first;
    data_ov000_021b63d8[1] = second;
    return 0;
}
