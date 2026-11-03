#include "code_0200fc8c.h"
#include "code_0200fd1c.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"
#include "code_0214d5b8.h"

u16 data_0217027c;
u16 data_02170280;

void func_0200fe58(void *p) {
    func_0214d1fc((void *) 0x27ffcf4, p, 6);
}

void func_0200fddc(Unk0200fddc *p) {
    u8 *s;

    s = (u8 *) 0x27ffc80;
    p->mUnk_00 = (u32) (*(u16 *) (s + 0x64) << 29) >> 29;
    p->mUnk_01 = (u32) (s[2] << 28) >> 28;
    p->mUnk_02 = s[3];
    p->mUnk_03 = s[4];
    p->mUnk_18 = s[0x1a];
    p->mUnk_4e = s[0x50];
    func_0214cffc(s + 6, p->mUnk_04, 0x14);
    func_0214cffc(s + 0x1c, p->mUnk_1a, 0x34);
}

void func_0200fd74(void) {
    if (data_0217027c != 0) {
        return;
    }
    data_0217027c = 1;
    func_0214d5b8();
    while (func_0214d79c(0xc, 1) == 0) {
    }
    func_0214d7c4(0xc, func_0200fd30);
}

void func_0200fd30(u32 a, u32 b) {
    if (((b & 0x7f00) << 8) >> 16 == 0x10) {
        data_02170280 = 1;
        return;
    }
    func_0200fd1c();
}

void func_0200fd1c(void) {
    while (1) {
        func_0200fca0();
        func_0200fd04();
    }
}
