#include "Main/Unknown/code_0205dc84.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02036588.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02108ed8.h"
#include "Main/Unknown/code_02108ec4.h"
#include "03/code_021c2000.h"
#include "00/code_021a3000.h"
#include "01/code_021956dc.h"
#include "code_02004dc0.h"
#include "code_0200c914.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_02148a58.h"
#include "code_021488e8.h"
#include "code_021458c4.h"
#include "Main/Unknown/unk_00000000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "registers.h"

#pragma opt_loop_invariants off

static inline void func_0205dee0_inline(void *c, void *e) {
    u8 d;
    u32 f;
    if (FS_LoadOverlay(0, (u32) e) != 0) {
        func_0200cc74(1, NULL);
        func_0200ca9c(1);
        reg_OS_IME;
        reg_OS_IME = 0;
        func_0200fca0();
        func_02148a58(0);
        func_ov000_021a397c(2);
        f = 1;
        d = data_021759d0->mUnk_04;
        if (d < 6) {
            f = data_02154904[d];
        }
        func_ov003_021c2494(c, f, 0x20);
        func_02036778();
        FS_UnloadOverlay(0, (u32) e);
    }
}

void func_0205dee0(void) {
    void *b;
    void *c;
    void *a;
    a = func_020364e0(func_020364e8());
    func_02057d9c();
    if (data_021759d4->mUnk_0c != 0) {
        func_02145d38();
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2 && data_0217aa20->mUnk_0c != NULL) {
        func_02108720();
        func_02036b30(a, data_0217aa20->mUnk_0c);
        data_0217aa20->mUnk_0c = NULL;
    }
    func_02108ed8();
    b = func_020369fc(a);
    c = func_02036b74(b, 0x40000, 0x20);
    func_0205dee0_inline(c, (void *) SDK_OVERLAY_OV003_ID);
    func_02036ab0(b);
    func_02148908((u16 *) 0x400006c, 0x10);
    func_02148908((u16 *) 0x400106c, 0x10);
    func_02039044();
    func_02108ec4();
    a = func_02036bec(a, func_021087d4(1));
    func_02108598(1, (u32) a);
    data_0217aa20->mUnk_0c = a;
}

static inline BOOL func_0205dd38_inline(void) {
    if (data_0217aa20->mUnk_04 == 3 || data_0217aa20->mUnk_04 == data_0217aa20->mUnk_00) {
        return TRUE;
    }
    return FALSE;
}

s32 func_0205dd38(s16 *a) {
    Unk02036590 q;
    void *h;
    func_0205e0b0();
    while (func_0205dd38_inline()) {
        data_0217aa20->mUnk_04 = 3;
        data_021653b8[0] = data_021653b8[1];
        data_021653b8[1] = *a;
        data_021653b8[2] = -1;
        func_02036590(&q, data_0215490c[*a]);
        func_020364f8(&q, (u32) data_021653b8);
        if (data_021653b8[2] != -1) {
            *a = data_021653b8[2];
        } else {
            *a = 9;
        }
        switch (data_021759d0->mUnk_20) {
            case 0:
            case 1:
            case 2:
                data_0217aa20->mUnk_04 = 0;
                break;
            case 3:
                data_0217aa20->mUnk_04 = 1;
                break;
            case 4:
                func_0205dee0();
                data_021759d0->mUnk_20 = 3;
                break;
        }
    }
    h = func_020364e0(func_020364e8());
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2 && data_0217aa20->mUnk_0c != NULL) {
        func_02108720();
        func_02036b30(h, data_0217aa20->mUnk_0c);
        data_0217aa20->mUnk_0c = NULL;
    }
    switch (data_0217aa20->mUnk_00) {
        case 0:
            func_02054330();
            break;
        case 1:
            func_02120514();
            break;
    }
    return 0;
}

void func_0205dc84(void) {
    Unk02036590 q;
    data_0217aa20->mUnk_08 = 9;
    data_0217aa20->mUnk_00 = 0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        data_021759d0->mUnk_20 = 2;
        data_0217b488->mUnk_74 = 0;
        data_0217aa20->mUnk_08 = 6;
    }
    do {
        data_0217aa20->mUnk_04 = 3;
        func_02036590(&q, (u32) func_0205dd38);
        func_020364f8(&q, (u32) &data_0217aa20->mUnk_08);
        data_0217aa20->mUnk_00 = data_0217aa20->mUnk_04;
    } while (1);
}
