#include "Main/Unknown/code_020caf98.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_020cb0cc.h"
#include "Main/Unknown/code_020cb0f4.h"
#include "Main/Unknown/code_020cb11c.h"
#include "Main/Unknown/code_020cb1cc.h"
#include "Main/Unknown/code_020cb1f4.h"
#include "Main/Unknown/code_020cb224.h"
#include "Main/Unknown/code_020cb2d4.h"
#include "Main/Unknown/code_020cc000.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02128210.h"

#pragma thumb on
#pragma optimize_for_size on
void func_020caf98(s32 a) {
    u32 v;
    u32 b;
    s32 c;
    s32 o;
    Unk0217b43c *p;

    if (a != 0) {
        v = func_020cb224();
        if (func_020cb1f4(v, 1)) {
            func_020ccc74(3, 0x1f);
            func_020cb1cc(5);
            data_0217b43c->mUnk_934 = 1;
        } else if (func_020cb1f4(v, 2)) {
            func_020ccc74(2, 0x1b);
            func_02128310(1);
        } else if (func_020ae408(v, 0x40)) {
            p = data_0217b43c;
            p->mUnk_930 = (p->mUnk_930 + 4) % 5;
            func_02105ac0(0);
        } else if (func_020ae408(v, 0x80)) {
            p = data_0217b43c;
            p->mUnk_930 = (p->mUnk_930 + 6) % 5;
            func_02105ac0(0);
        } else if (func_020cb11c(v)) {
            b = func_020cb0f4(v);
            v = func_020cb0cc(v);
            c = func_020291c4(b, v, data_0217b43c->mSinglePlaySelectModeSBnbl);
            p = data_0217b43c;
            o = p->mUnk_930;
            if (c != -1) {
                if (o == c) {
                    p->mUnk_934 = 1;
                }
                data_0217b43c->mUnk_930 = c;
                func_020ccc74(3, 0x1f);
                func_020cb1cc(5);
            } else if (func_02128210(b, v)) {
                func_020ccc74(2, 0x1b);
                func_02128310(1);
            }
        }
    }
    func_020cb2d4();
}
