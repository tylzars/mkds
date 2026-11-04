#include "00/code_021a6ce4.h"

#include "00/unk_021b5000.h"
#include "00/code_021a574c.h"
#include "00/code_021a6c08.h"
#include "code_02133048.h"
#include "code_0200fc8c.h"

u32 func_ov000_021a6ce4(void) {
    u32 a;
    Unk021b5f50 *b;
    u32 c;

    a = IrqDisable();
    b = func_ov000_021a5b30();
    c = 0;
    if (b != NULL && b->mUnk_2260 == 9) {
        c = func_ov000_021a6c68();
    }
    IrqRestore(a);
    return c;
}
