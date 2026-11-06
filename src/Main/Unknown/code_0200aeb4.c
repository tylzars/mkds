#include "Main/Unknown/code_0200aeb4.h"

#include "Main/Unknown/code_0200f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02007ec4.h"
#include "Main/Unknown/code_0200b1b0.h"

#pragma thumb on

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
        v2 = OS_DisableInterrupts();
        while (a->mUnk_c0 == NULL) {
            OS_SetThreadPriority(&a->mUnk_00, v6);
            OS_SleepThread(NULL);
        }
        v1 = a->mUnk_c0;
        a->mUnk_c0 = a->mUnk_c0->mUnk_00;
        OS_SetThreadPriority(&a->mUnk_00, v1->mUnk_04_1);
        OS_RestoreInterrupts(v2);
        if (v1->mUnk_08 != NULL) {
            ((void (*)(Unk0200aeec *)) v1->mUnk_08)(v1);
        }
        v3 = OS_DisableInterrupts();
        v4 = (void (*)(Unk0200aeec *)) v1->mUnk_0c;
        v5 = OS_GetThreadPriority(&a->mUnk_00);
        if (a->mUnk_c0 == NULL) {
            v2 = v6;
        } else if (v5 < a->mUnk_c0->mUnk_04_1) {
            v2 = a->mUnk_c0->mUnk_04_1;
        } else {
            v2 = v5;
        }
        if (v2 != v5) {
            OS_SetThreadPriority(&a->mUnk_00, v2);
        }
        v1->mUnk_00 = NULL;
        v1->mUnk_04_0 = 0;
        if (v4 != NULL) {
            v4(v1);
        }
        if (v1 == &a->mUnk_c4) {
            break;
        }
        OS_RestoreInterrupts(v3);
    }
    OS_ExitThread();
}

void func_0200b02c(Unk0200aeec_head *a, u32 b) {
    u32 v1;
    u32 v2;
    v1 = OS_DisableInterrupts();
    if (data_0216fde0 == NULL) {
        data_0216fde0 = a;
        func_0200b00c(&a->mUnk_c4);
        a->mUnk_c0 = NULL;
        v2 = (b - 0xe4) & ~3;
        OS_CreateThread(&a->mUnk_00, func_0200b08c, a, (u8 *) a + 0xe4 + v2, v2, 0);
        OS_WakeupThreadDirect(&a->mUnk_00);
    }
    OS_RestoreInterrupts(v1);
}

#pragma thumb off

#pragma thumb on

u32 func_0200b018(void) {
    if (data_0216fde0 != NULL) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on
void func_0200b00c(void *arg0) {
    void *value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    value1 = 0u;
    value2 = 32u;
    MI_CpuFill8(value0, (u8) value1, value2);
}
#pragma thumb off

#pragma thumb on

u32 func_0200aff8(Unk0200aeec *a) {
    if (a->mUnk_04_0 != 0) {
        return 1;
    }
    return 0;
}

void func_0200aeec(Unk0200aeec *a, void *b, void *c, u32 d) {
    Unk0200aeec_head *v1;
    u32 v2;
    u32 v3;
    Unk0200aeec *v4;
    Unk0200aeec *v5;
    v1 = data_0216fde0;
    if (func_0200b018() == 0) {
        OS_Terminate();
    }
    if (a->mUnk_04_0 != 0) {
        OS_Terminate();
    }
    if (d > 31) {
        v2 = OS_GetThreadPriority(&v1->mUnk_00);
        if (d == 32) {
            if (v2 != 0) {
                d = v2 - 1;
            } else {
                d = 0;
            }
        } else if (d == 33) {
            if (v2 < 31) {
                d = v2 + 1;
            } else {
                d = 31;
            }
        } else if (d == 34) {
            d = v2;
        } else {
            d = 31;
        }
    }
    v3 = OS_DisableInterrupts();
    a->mUnk_04_0 = 1;
    a->mUnk_04_1 = d;
    a->mUnk_08 = b;
    a->mUnk_0c = c;
    if (v1->mUnk_c0 == NULL) {
        if (a == &v1->mUnk_c4) {
            data_0216fde0 = NULL;
        }
        v1->mUnk_c0 = a;
        OS_WakeupThreadDirect(&v1->mUnk_00);
    } else {
        v4 = v1->mUnk_c0;
        if (a == &v1->mUnk_c4) {
            if (v4->mUnk_00 != NULL) {
                do {
                    v4 = v4->mUnk_00;
                } while (v4->mUnk_00 != NULL);
            }
            v4->mUnk_00 = a;
            data_0216fde0 = NULL;
        } else if (v4->mUnk_04_1 > d) {
            v1->mUnk_c0 = a;
            a->mUnk_00 = v4;
        } else {
            while ((v5 = v4->mUnk_00) != NULL && v5->mUnk_04_1 <= d) {
                v4 = v5;
            }
            a->mUnk_00 = v5;
            v4->mUnk_00 = a;
        }
    }
    OS_RestoreInterrupts(v3);
}

#pragma thumb off

#pragma thumb on

void func_0200aeb4(void *a) {
    u32 v1;
    int v2;
    v1 = ((s64) OS_DisableInterrupts());
    v2 = func_0200b018();
    if (v2 != 0) {
        func_0200aeec(&data_0216fde0->mUnk_c4, NULL, a, 0);
    }
    OS_RestoreInterrupts(v1);
}

#pragma thumb off
