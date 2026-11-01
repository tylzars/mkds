#include "Main/Unknown/code_020353a4.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02125ed0.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

void func_020353f8(void) {
    s32 r;
    s32 n;

    r = func_02025ebc(&data_02174e68->mUnk_90);
    *(u32 *) 0x4000010 = (r << 16) & 0x1ff0000;
    n = -r;
    *(u32 *) 0x400101c = (n << 16) & 0x1ff0000;
    if (r != 0) {
        *(u32 *) 0x4000000 = (*(u32 *) 0x4000000 & 0xffff1fff) | 0x2000;
        *(u16 *) 0x4000048 = (u32) ((*(u16 *) 0x4000048 & ~0x3f) | 0x1f) | 0x20;
        *(u16 *) 0x400004a = (u32) ((*(u16 *) 0x400004a & ~0x3f) | 0xe) | 0x20;
        *(u16 *) 0x4000040 = 0xff;
        *(u16 *) 0x4000044 = ((n << 8) & 0xff00) | 0xc0;
        *(u32 *) 0x4001000 = (*(u32 *) 0x4001000 & 0xffff1fff) | 0x2000;
        *(u16 *) 0x4001048 = (u32) ((*(u16 *) 0x4001048 & ~0x3f) | 0x1f) | 0x20;
        *(u16 *) 0x400104a = (u32) ((*(u16 *) 0x400104a & ~0x3f) | 7) | 0x20;
        *(u16 *) 0x4001040 = 0xff;
        *(u16 *) 0x4001044 = (r + 0xc0) & 0xff;
    } else {
        *(u32 *) 0x4000000 = (u32) (*(u32 *) 0x4000000 & 0xffff1fff);
        *(u32 *) 0x4001000 = (u32) (*(u32 *) 0x4001000 & 0xffff1fff);
    }
}

void func_020353a4(void) {
    void *e;
    void *f;

    e = func_020b3f7c(data_02174e64->mUnk_088, 0x11);
    f = func_020b3f7c(data_02174e64->mUnk_084, 4);
    func_02125ed0(0, 5);
    func_02126230(e, f);
    data_02174e64->mUnk_090 = 0;
    data_02174e64->mUnk_094 = 15;
}

#pragma thumb off
