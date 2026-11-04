#include "Main/Unknown/code_02007ec4.h"
#include "Main/Unknown/code_0200b02c.h"
#include "Main/Unknown/code_0200b00c.h"
#include "Main/Unknown/code_0200b1b0.h"
#include "code_0200fc8c.h"

#pragma thumb on

void func_0200b02c(Unk0200aeec_head *a, u32 b) {
    u32 v1;
    u32 v2;
    v1 = IrqDisable();
    if (data_0216fde0 == NULL) {
        data_0216fde0 = a;
        func_0200b00c(&a->mUnk_c4);
        a->mUnk_c0 = NULL;
        v2 = (b - 0xe4) & ~3;
        func_0200e28c(&a->mUnk_00, func_0200b08c, a, (u8 *) a + 0xe4 + v2, v2, 0);
        func_0200df68(&a->mUnk_00);
    }
    IrqRestore(v1);
}

void func_0200b08c(void *param_1) {
    Unk0200aeec_head *a;
    Unk0200aeec *v1;
    u32 v2;
    u32 v3;
    void (*v4)(Unk0200aeec *);
    u32 v5;
    u32 v6;
    a = param_1;
    v6 = 0;
    for (;;) {
        v2 = IrqDisable();
        while (a->mUnk_c0 == NULL) {
            func_0200dce0(&a->mUnk_00, v6);
            func_0200e01c(NULL);
        }
        v1 = a->mUnk_c0;
        a->mUnk_c0 = a->mUnk_c0->mUnk_00;
        func_0200dce0(&a->mUnk_00, v1->mUnk_04_1);
        IrqRestore(v2);
        if (v1->mUnk_08 != NULL) {
            ((void (*)(Unk0200aeec *)) v1->mUnk_08)(v1);
        }
        v3 = IrqDisable();
        v4 = (void (*)(Unk0200aeec *)) v1->mUnk_0c;
        v5 = func_0200dcd8(&a->mUnk_00);
        if (a->mUnk_c0 == NULL) {
            v2 = v6;
        } else if (v5 < a->mUnk_c0->mUnk_04_1) {
            v2 = a->mUnk_c0->mUnk_04_1;
        } else {
            v2 = v5;
        }
        if (v2 != v5) {
            func_0200dce0(&a->mUnk_00, v2);
        }
        v1->mUnk_00 = NULL;
        v1->mUnk_04_0 = 0;
        if (v4 != NULL) {
            v4(v1);
        }
        if (v1 == &a->mUnk_c4) {
            break;
        }
        IrqRestore(v3);
    }
    func_0200e260();
}

u32 func_0200b15c(u32 a, Unk02007ec4 *b, u16 c, u16 d, u32 e, u32 f) {
    u32 v1;
    u32 v2;
    if (func_0200b1b0(a, (struct Unk0217aa00_24 *) b) == 0) {
        return 0;
    }
    b->mUnk_3c = 0x10;
    b->mUnk_4a = 0;
    b->mUnk_4c = c;
    b->mUnk_4e = d;
    v1 = 0;
    if (f != 0) {
        v1 = 8;
    }
    if (e != 0) {
        v2 = 4;
    } else {
        v2 = 0;
    }
    b->mUnk_4b = v2 | v1 | 1;
    return 1;
}

#pragma thumb off
