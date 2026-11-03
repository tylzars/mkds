#include "code_0200dbe8.h"
#include "code_0200dc3c.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/unk_0216f000.h"

void func_0200dc1c(Unk0200db5c **arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) * (const u32 *) ((value0) + (0));
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    value12 = (u32) &func_0200df68;
    value0 = value2;
    *(u32 *) ((value2) + (176)) = value1;
    func_0200df68((Unk0200db5c *) value0);
}

void (*func_0200dbe8(void (*arg0)(Unk0200db5c *, Unk0200db5c *)))(Unk0200db5c *, Unk0200db5c *) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value4;
    u32 value5;
    value5 = value0;
    value0 = (u32) func_0200fca0();
    value1 = (u32) &data_0216ff5c;
    value4 = (u32) * (const u32 *) ((value1) + (12));
    *(u32 *) ((value1) + (12)) = value5;
    value0 = (u32) func_0200fcb4(value0);
    value0 = value4;
    return (void (*)(Unk0200db5c *, Unk0200db5c *)) value0;
}
