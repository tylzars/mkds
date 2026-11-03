#include "code_02004238.h"
#include "code_0214d018.h"

void FS_InitArchive(Unk02003a6c *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value4;
    value1 = 0u;
    value2 = 0x5cu;
    value4 = value0;
    func_0214d168((void *) value0, (u8) value1, value2);
    value1 = 0u;
    *(u32 *) ((value4) + (16)) = value1;
    value0 = (u32) * (const u32 *) ((value4) + (16));
    *(u32 *) ((value4) + (12)) = value0;
    *(u32 *) ((value4) + (24)) = value1;
    value0 = (u32) * (const u32 *) ((value4) + (24));
    *(u32 *) ((value4) + (20)) = value0;
}
