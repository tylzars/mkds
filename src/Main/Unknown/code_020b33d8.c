#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02089ef4.h"
#include "Main/Unknown/code_020b33d8.h"

#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Unknown/code_02089000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_020d3c7c.h"
#include "Main/Unknown/code_020b1de4.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020b36c8.h"
#include "Main/Unknown/code_020b36dc.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"

void func_020b36dc(void) {
    data_0217b358 = HeapAlloc(GetHeap(func_020364e8()), 0xc);
    data_0217b358->mUnk_00 = 0;
    data_0217b358->mUnk_04 = 0;
    data_0217b358->mUnk_08 = 0;
}

u32 func_020b36c8(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b358;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void func_020b36a4(void) {
    data_0217b358->mUnk_00 = 0;
    data_0217b358->mUnk_08 = -0x78;
}

void func_020b3584(void) {
    Unk0217b358 *p = data_0217b358;
    s32 a;
    s32 *q;

    if (p->mUnk_00 != 0) {
        a = p->mUnk_08;
        if (a < 200) {
            p->mUnk_08 = a + 1;
            if (a == -1) {
                func_0203c98c();
                return;
            }
            if (a != 180) {
                return;
            }
            func_02106efc();
            func_02061fcc();
            data_0217b358->mUnk_04 = 1;
            return;
        }
        q = &p->mUnk_08;
        if (a < 0x7fffffff) {
            *q = a + 1;
        }
        return;
    }
    if (data_021759c0->mUnk_08 == 5) {
        if ((data_0217aa14->mUnk_75c & 2) == 0) {
            return;
        }
        p->mUnk_00 = 1;
        func_020617f0();
        func_020d3c7c();
        return;
    }
    if (func_02054754() == 1) {
        data_0217b358->mUnk_00 = 1;
    }
}

void func_020b3410(void) {
    Unk0212c400 **p;
    s32 a = data_0217b358->mUnk_08;

    if (a < -21) {
        return;
    }
    if (a >= 200) {
        return;
    }
    if (a == 0 || a == 60 || a == 120) {
        if (data_0217c780 & 1) {
            p = (Unk0212c400 **) func_0210e128((void *) func_02108ea0(0));
            if (data_0217d084.mUnk_0c != 0) {
                if (*p != NULL) {
                    func_0212c6f0(p, 0);
                }
                if (*p != NULL) {
                    func_0212c6f0(p, 0);
                }
                func_0212ecc0(p, 0, 0x27);
            }
        }
    }
    if (a == 175) {
        if (data_0217c780 & 1) {
            p = (Unk0212c400 **) func_0210e128((void *) func_02108ea0(0));
            if (data_0217d084.mUnk_0c != 0) {
                if (*p != NULL) {
                    func_0212c6f0(p, 0);
                }
                if (*p != NULL) {
                    func_0212c6f0(p, 0);
                }
                func_0212ecc0(p, 0, 0x28);
            }
        }
    }
    if (a == -21) {
        func_02089ef4(0);
    }
    if (a != 180) {
        return;
    }
    func_02089ef4(1);
}

s32 func_020b33f4(void) {
    if (data_0217b358 != NULL) {
        return data_0217b358->mUnk_08;
    }
    return -0x78;
}

s32 func_020b33d8(void) {
    if (data_0217b358 != NULL) {
        return data_0217b358->mUnk_04;
    }
    return 0;
}
