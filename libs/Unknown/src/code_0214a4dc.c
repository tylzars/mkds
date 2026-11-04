#include "code_0214a4dc.h"
#include "code_0214c728.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214c000.h"
#include "Main/Unknown/code_0214d000.h"

void func_0214a530(const void *a) {
    *(vu32 *) 0x4000400 = 0x16;
    func_0214c74c(a, (void *) 0x4000400);
}

void func_0214a514(const void *a) {
    *(vu32 *) 0x4000400 = 0x17;
    func_0214c728(a, (void *) 0x4000400);
}

void func_0214a4f8(const void *a) {
    *(vu32 *) 0x4000400 = 0x19;
    func_0214c728(a, (void *) 0x4000400);
}

void func_0214a4dc(const void *a) {
    *(vu32 *) 0x4000400 = 0x1a;
    MemCopy9Words(a, (void *) 0x4000400);
}
