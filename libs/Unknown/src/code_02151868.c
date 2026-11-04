#include "code_021510a4.h"
#include "code_02151868.h"
#include "code_020205b0.h"
#include "code_0214d018.h"
#include "code_0200fd1c.h"
#include "Main/Unknown/unk_02180000.h"

#pragma thumb on

void func_02151910(Unk021510a4 *a) {
    MemCopy(data_021804a0, a, 6);
    a->mUnk_00 &= ~0xfffff80000000000ULL;
    MemCopy(data_021804a0 + 5, &a->mUnk_08, 6);
    a->mUnk_08 >>= 3;
    a->mUnk_08 &= ~0xfffff80000000000ULL;
    MemCopy(data_021804a0 + 10, &a->mUnk_10, 2);
    a->mUnk_10 = a->mUnk_10 >> 6;
    a->mUnk_10 &= 0x3ff;
    MemCopy(data_021804a0 + 12, &a->mUnk_12, 2);
}

u32 func_02151868(Unk021510a4 *a, u8 *b) {
    u32 c;
    s32 d;
    c = *(u32 *) data_0218049c;
    func_021510a4(a);
    Crc16InitTable((u16 *) (b + 0x200), 0xa001);
    for (d = 0; d < 2;) {
        if (func_0215122c(c, 0x100, b) == 0) {
            IrqDisableLoopForever();
            return 0;
        }
        MemCopy(data_021804a0, b + 0xf0, 0xe);
        *(u16 *) (b + 0xfe) = Crc16((u16 *) (b + 0x200), b, 0xfe);
        do {
            func_021511d8(c, 0x100, b);
        } while (func_0215119c(b, c, 0x100, b + 0x100) == 0);
        d++;
        c += 0x100;
    }
    if (func_02151154() != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off
