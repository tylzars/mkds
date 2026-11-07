#include "Main/Unknown/code_0204aa60.h"
#include "Main/Unknown/code_0204ad24.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0210d960.h"
#include "Main/Unknown/code_0210f868.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "pm.h"

void func_0204acd0(s32 a) {
    if (data_021759d0->mUnk_1c_1) {
        return;
    }
    data_021759d0->mUnk_1c_1 = 1;
    func_0210f8b0(&data_021759d0->mUnk_08, a, 0xff);
}

void func_0204ac60(void) {
    if (!data_021759d0->mUnk_1c_1) {
        return;
    }
    if (data_021759d0->mUnk_1c_0) {
        return;
    }
    data_021759d0->mUnk_1c_0 = 1;
    func_0210dcb8(&data_021759d0->mUnk_08, data_0216cb28);
}

void func_0204ac10(void) {
    Unk021759d0 *p = data_021759d0;

    if (!p->mUnk_1c_0) {
        return;
    }
    func_0210dca8(&p->mUnk_08, GetSoundFadeSteps());
    data_021759d0->mUnk_1c_0 = 0;
}

void func_0204aba8(void) {
    if (data_021759d0->mUnk_1c_0) {
        return;
    }
    if (!data_021759d0->mUnk_1c_1) {
        return;
    }
    func_0210dc7c(&data_021759d0->mUnk_08);
    data_021759d0->mUnk_1c_1 = 0;
}

void func_0204ab64(u32 a) {
    if (!data_021759d0->mUnk_1c_0) {
        return;
    }
    func_0210dca8(&data_021759d0->mUnk_08, a);
}

s32 func_0204aab4(s32 a, s32 b) {
    Unk021759d0 *p = data_021759d0;
    s32 c = p->mUnk_48;
    s32 d = p->mUnk_4c;
    BOOL r = TRUE;

    if (a == 0) {
        c = 1;
    } else if (a == 1) {
        c = 0;
    }
    if (b == 0) {
        d = 1;
    } else if (b == 1) {
        d = 0;
    }
    if (c != p->mUnk_48) {
        if (PM_SetBackLight(0, c) == 0) {
            data_021759d0->mUnk_48 = c;
        } else {
            r = FALSE;
        }
    }
    if (d != data_021759d0->mUnk_4c) {
        if (PM_SetBackLight(1, d) == 0) {
            data_021759d0->mUnk_4c = d;
        } else {
            r = FALSE;
        }
    }
    return r;
}

void *func_0204aa60(void) {
    void *r = NULL;
    Unk021759d0 *p = data_021759d0;

    switch (p->mUnk_20) {
        case 0:
        case 3:
            r = &p->mUnk_60;
            break;
        case 1:
        case 2:
            r = &data_0217aa00->mUnk_1ee8;
            break;
    }
    return r;
}
