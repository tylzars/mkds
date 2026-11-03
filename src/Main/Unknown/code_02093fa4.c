#include "Main/Unknown/code_02093fa4.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/code_020d7d80.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/unk_0217c000.h"

void func_02093fa4(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value4;
    value4 = value0;
    value1 = (u32) * (const u32 *) ((value4) + (156));
    value0 = (value4) + (0xacu);
    value2 = 0u;
    func_020d7da8((Unk020e0144 *) value0, (Unk020fa294 *) value1, (s32) value2);
    value0 = (value4) + (0xacu);
    func_020d7d80((u32 *) value0);
    value0 = 0x1a2u;
    value2 = value4;
    value1 = 0x14u;
    func_020ac588(value0, value1, (void *) value2);
    value0 = (u32) &data_0217ca6c;
    value0 = (u32) * (const u32 *) ((value0) + (356));
    *(u32 *) ((value4) + (112)) = value0;
}
