#include "Main/Unknown/code_02050000.h"
#include "Main/Unknown/code_02058b10.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02050034.h"

u32 func_02050064(u32 p0) {
    return ((u32) *
            (const u16 *) ((u8 *) (u32) (((((((u32) * (const u32 *) ((u8 *) (u32) (((u32) (&data_0217aa00))) + 0))) +
                                            (((p0) << 1)))) +
                                          (0x1e00u))) +
                           156));
}

void func_02050034(u8 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_0217aa00;
    value1 = (u32) * (const u32 *) ((value1) + (0));
    value1 = (value1) + (0x1000u);
    *(u8 *) ((value1) + (1526)) = (u8) value0;
    func_02050080();
    func_02058b10();
}
