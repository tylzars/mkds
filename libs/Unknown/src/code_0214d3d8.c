#include "code_0214d3d8.h"
#include "code_0214c778.h"
#include "ITCM/code_01fff000.h"
#include "ITCM/code_01fff95c.h"

// Calls func_0214c7e8(a, 0xffffffff) and func_0214c778(a, b, d, 0x1000000). Does nothing more when d is 0. Otherwise
// waits for bit 31 of the word at 0x40000b0 + (a * 3 + 2) * 4 to clear and calls func_01ffff38(a, b, c, 0xaf000001).
void func_0214d3d8(u32 a, const void *b, void *c, u32 d) {
    func_0214c7e8(a, -1);
    func_0214c778(a, b, d, 0x1000000);
    if (d == 0) {
        return;
    }
    while (*(vu32 *) (0x40000b0 + (a * 3 + 2) * 4) & 0x80000000) {
    }
    func_01ffff38(a, b, c, 0xaf000001);
}
