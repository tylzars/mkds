#include "code_0200db5c.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/unk_0216f000.h"

void func_0200dbd4(void *a) {
    func_0200fc8c();
    for (;;) {
        func_0200fd04();
    }
}

u32 func_0200db9c(void) {
    u32 s;
    u32 r;

    s = func_0200fca0();
    if (data_0216ff48 < 0xffffffff) {
        r = data_0216ff48;
        data_0216ff48 = r + 1;
    }
    func_0200fcb4(s);
    return r;
}

u32 func_0200db64(void) {
    u32 s;
    u32 r;

    s = func_0200fca0();
    r = 0;
    if (data_0216ff48 != 0) {
        r = data_0216ff48;
        data_0216ff48 = r - 1;
    }
    func_0200fcb4(s);
    return r;
}

void func_0200db5c(Unk0200db5c *t, void (*f)(void *)) {
    t->mUnk_b4 = f;
}
