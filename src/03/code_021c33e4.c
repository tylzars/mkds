#include "03/code_021c33e4.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/code_021d2940.h"
#include "code_0200fc8c.h"
#include "code_0214f4a4.h"

void func_ov003_021c3490(void) {
    int v1;
    v1 = func_ov003_021d2b04(1);
    if (v1 != 0) {
        func_ov003_021bf31c((u8) (0));
    }
    return;
}

void func_ov003_021c348c(void) {
    return;
}

void func_ov003_021c3468(void) {
    int v1;
    v1 = func_ov003_021bf334();
    if (v1 == 0) {
        func_ov003_021cdc10(6);
        func_ov003_021c212c(func_ov003_021c3448);
    }
    return;
}

void func_ov003_021c3448(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0((u16) (8));
    func_ov003_021c212c(func_ov003_021c3410);
    return;
}

void func_ov003_021c3410(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        func_ov003_021d1ee0(3, 1, 0x3f, (u16) (0x40));
        func_ov003_021d1ee0(3, 0, 0x3f, (u16) (0x40));
        func_ov003_021c212c(func_ov003_021c33e4);
    }
    return;
}

void func_ov003_021c33e4(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_0200fd10((u32) (((u32) 0x01000000u)));
        PM_ForceToPowerOff();
    }
    return;
}
