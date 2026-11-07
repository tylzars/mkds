#include "Main/Unknown/code_020681e4.h"

// A response-table entry with nothing to do: stores 0 and returns 0.
u32 CollideKartWithMapObjectNoResponse(u32 kart, u32 outValue) {
    u32 result;
    u32 outValueCopy = outValue;
    result = 0u;
    *(u32 *) ((outValueCopy) + (0)) = result;
    return result;
}
