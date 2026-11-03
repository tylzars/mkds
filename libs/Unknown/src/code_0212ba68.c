#include "code_0212ba68.h"
#include "code_020207ec.h"
#include "code_02020e3c.h"
#include "code_02020eb0.h"
#include "code_0212b9ec.h"
#include "code_0212bcac.h"
#include "code_0212c9d4.h"
#include "code_0212ee54.h"
#include "code_0214f4a4.h"
#include "code_0201ec30.h"
#include "Main/Unknown/code_02021000.h"
#include "code_0212bb50.h"

Unk0214f4bc data_0217d42c;
Unk0214f4bc data_0217d420;
u32 data_0217d418;
u32 data_0217d41c;
s8 data_0217d414;

void func_0212baa8(void) {
    if (data_0217d41c != 0) {
        return;
    }
    data_0217d41c = 1;
    func_02020e64();
    data_0217d420.mUnk_00 = func_0212b9f8;
    data_0217d420.mUnk_04 = 0;
    data_0217d42c.mUnk_00 = func_0212b9ec;
    data_0217d42c.mUnk_04 = 0;
    func_0214f4ec(&data_0217d420);
    func_0214f4d4(&data_0217d42c);
    func_0212bb50();
    func_0212d0ec();
    func_0212c310();
    data_0217d414 = -1;
    data_0217d418 = 1;
}

void func_0212ba74(void) {
    while (func_02021488(0) != 0) {
    }
    func_0212c19c();
    func_0212d03c();
    func_0212f094();
    func_020211e4(0);
}

void func_0212ba68(u32 a) {
    func_02020964(a);
}
