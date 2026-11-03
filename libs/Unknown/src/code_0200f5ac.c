#include "code_0200f5ac.h"
#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/unk_02170000.h"

void func_0200f65c(void) {
    data_02170254++;
    if (data_02170250 != 0) {
        *(vu16 *) 0x4000102 = 0;
        *(vu16 *) 0x4000100 = 0;
        *(vu16 *) 0x4000102 = 0xc1;
        data_02170250 = 0;
    }
    func_0200cb50(0, func_0200f65c, 0);
}

u64 func_0200f5ac(void) {
    u32 s;
    volatile u16 t;
    volatile u64 v;

    s = func_0200fca0();
    t = *(vu16 *) 0x4000100;
    v = data_02170254 & 0xffffffffffffULL;
    if ((*(vu32 *) 0x4000214 & 8) && !(t & 0x8000)) {
        v++;
    }
    func_0200fcb4(s);
    return (v << 16) | t;
}
