#include "Main/Unknown/code_0202d6a0.h"

#pragma thumb on

void func_0202d6a0(void) {
    Unk0202de00_g t;
    u16 n[10];
    u16 m[11];
    s32 a;
    s32 b;
    func_0202dcf4(data_02174e40->mUnk_0a4, &t);
    func_0202dc68(data_02174e40->mUnk_0a4, n);
    func_0214cffc(n, m, 0x14);
    m[10] = 0;
    a = func_0202dbe8(data_02174e40->mUnk_0a4);
    b = func_0202db68(data_02174e40->mUnk_0a4);
    func_0202de00((Unk02174e14 *) data_02174e40->mUnk_050, data_usa_02153bec, m, a, b,
                  func_0202db04(data_02174e40->mUnk_0a4), &t);
}

void func_0202d720(void) {
    u16 s[6];
    Unk02174e14_00 *p;
    s32 n;
    p = &data_02174e40->mUnk_050[1];
    func_0212426c(1, 0xe, p->mUnk_14, func_020b3f7c(data_02174e40->mUnk_0ac, 0x56), p->mUnk_0c, p->mUnk_18);
    func_0212426c(1, 0xf, p->mUnk_14, func_020b3f7c(data_02174e40->mUnk_0ac, 0x57), p->mUnk_0c, p->mUnk_18);
    n = (s32) func_0202ddb0();
    if (n < 10) {
        s[0] = ' ';
    } else {
        s[0] = n / 10 % 10 + '0';
    }
    s[1] = n % 10 + '0';
    s[2] = '/';
    s[3] = '3';
    s[4] = '2';
    s[5] = 0;
    func_02124224(1, 0x10, p->mUnk_14, s, p->mUnk_0c, p->mUnk_18, 6);
    n = (s32) func_0202dd9c();
    if (n < 10) {
        s[0] = ' ';
    } else {
        s[0] = n / 10 % 10 + '0';
    }
    s[1] = n % 10 + '0';
    s[2] = '/';
    s[3] = '1';
    s[4] = '0';
    s[5] = 0;
    func_02124224(1, 0x11, p->mUnk_14, s, p->mUnk_0c, p->mUnk_18, 6);
}

#pragma thumb off
