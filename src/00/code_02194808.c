#include "00/code_02194808.h"
#include "00/code_02194828.h"
#include "00/code_02194840.h"

Unk02194828 *func_ov000_02194808(Unk0218f960 *a, u32 b) {
    Unk02194828Search s;

    s.mKey = b;
    s.mEntry = NULL;
    func_ov000_02194840(a, func_ov000_02194828, &s);
    return s.mEntry;
}
