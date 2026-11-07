#include "Main/Unknown/code_020cb4c0.h"
#include "Main/Unknown/code_0204984c.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020cae54.h"
#include "Main/Unknown/code_020cb600.h"
#include "Main/Unknown/code_020cb618.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02049000.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void func_020cb51c(u32 a) {
    Unk0217b43c *p;
    enum { K0 } k;

    if (func_02049b6c() == 0) {
        if (func_020cae54() == 1 || func_020cae54() == 2) {
            if (data_0217b43c->mUnk_958 == FALSE) {
                if (func_020546d8() != 1) {
                    return;
                }
                data_0217b43c->mUnk_958 = TRUE;
            }
            if (data_0217b43c->mUnk_95c == FALSE) {
                if (func_02054754() != 1) {
                    return;
                }
                data_0217b43c->mUnk_95c = TRUE;
            }
        }
        func_020ae6ac(data_0217b43c->mMainOam, data_0217b43c->mSubOam);
        if (data_0217b43c->mUnk_104 != FALSE) {
            data_0217b43c->mUnk_104 = FALSE;
            func_020cb6c0();
            p = data_0217b43c;
            k = p->mScreenNumber;
            p->mScreenCallbacks[k].mUpdate(a);
        } else {
            p = data_0217b43c;
            k = p->mScreenNumber;
            p->mScreenCallbacks[k].mUpdate(a);
            if (data_0217b43c->mUnk_004 != 0) {
                func_020cb618();
                func_020cb6c0();
            }
        }
        func_02125928();
        func_0212a920();
        if (AreBrightnessFadesClear() != 0) {
            func_020cb600(&data_0217b43c->mUnk_000);
        }
    }
}

void func_020cb4c0(void) {
    if (func_02049b6c() == 0) {
        if (func_020cae54() == 1 || func_020cae54() == 2) {
            if (data_0217b43c->mUnk_958 == FALSE || data_0217b43c->mUnk_95c == FALSE) {
                return;
            }
        }
        func_020ae630(data_0217b43c->mMainOam, data_0217b43c->mSubOam);
    }
}
