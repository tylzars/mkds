#include "code_02146af4.h"

#include "Main/Unknown/unk_02180000.h"
#include "code_0200fd1c.h"
#include "code_02146a50.h"
#include "code_0214d5b8.h"

UnkWordFunc *data_021802a4;
u32 data_021802a0;

void func_02146b80(void) {
    func_0214d5b8();
    func_0214d7c4(14, func_02146b14);
    data_021802a4 = 0;
}

void func_02146b14(u32 a, u32 b) {
    u32 r;
    UnkWordFunc *fn;

    if ((b & 0x3F) == 0x11) {
        fn = data_021802a4;
        data_021802a0 = 1;
        r = 1;
        if (fn != 0) {
            r = fn();
        }
        if (r != 0) {
            func_02146ab4();
        }
    } else {
        func_0200fd1c();
    }
}

void func_02146b04(void *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_021802a4;
    *(u32 *) ((value1) + (0)) = value0;
}

u32 func_02146af4(void) {
    u32 value0;
    value0 = (u32) &data_021802a0;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    return value0;
}
