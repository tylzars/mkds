#include "Main/Unknown/code_020cb618.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020cc744.h"
#include "01/code_021a11a4.h"
#include "Main/Unknown/code_020cae38.h"
#include "Main/Unknown/code_020cae54.h"
#include "Main/Unknown/code_020cb99c.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02029890.h"
#include "01/code_0219c784.h"
#include "01/code_0219eab4.h"
#include "01/code_0219f8ec.h"
#include "01/code_ov001_02197b34.h"
#include "01/code_0219b540.h"
#include "Main/Unknown/code_02026000.h"
#include "Main/Unknown/code_02028000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/code_02128000.h"
#include "Main/Unknown/code_0212b000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02027f68.h"
#include "Main/Unknown/code_02117db0.h"
#include "Main/Unknown/code_021196f4.h"
#include "Main/Unknown/code_0211b23c.h"
#include "Main/Unknown/code_0211e4e8.h"
#include "Main/Unknown/code_02032000.h"

#pragma thumb on
#pragma optimize_for_size on
void func_020cb6c0(void) {
    Unk0217b43c *p;
    s32 v;

    p = data_0217b43c;
    if (p->mUnk_00c != p->mUnk_008) {
        switch (p->mUnk_00c) {
            case 4:
                func_ov001_021a1858((s32) func_020cb99c(), p->mUnk_108, p->mUnk_50c);
                break;
            case 5:
            case 8:
            case 15:
            case 21:
                v = (func_020cae54() == 0) ? UNK_020CB6C0_0 : UNK_020CB6C0_1;
                p = data_0217b43c;
                func_02026910(func_020cb99c(), v, p->mUnk_108, p->mUnk_50c);
                break;
            case 6:
            case 9:
            case 22:
                v = (func_020cae54() == 0) ? UNK_020CB6C0_0 : UNK_020CB6C0_1;
                p = data_0217b43c;
                func_02028864(func_020cb99c(), v, p->mUnk_108, p->mUnk_50c);
                break;
            case 7:
                func_02117e24(func_020cb99c(), p->mUnk_108, p->mUnk_50c, 0);
                break;
            case 11:
                if (func_020cae54() == 0) {
                    v = 2;
                } else if (func_020cae38() != 0) {
                    v = 3;
                } else {
                    v = 4;
                }
                p = data_0217b43c;
                func_02117e24(func_020cb99c(), p->mUnk_108, p->mUnk_50c, v);
                break;
            case 23:
                func_02117e24(func_020cb99c(), p->mUnk_108, p->mUnk_50c, 1);
                break;
            case 13:
                if (func_020cae54() == 0) {
                    v = 1;
                } else if (func_020cae38() != 0) {
                    v = 2;
                } else {
                    v = 3;
                }
                p = data_0217b43c;
                func_02119770(func_020cb99c(), p->mUnk_108, p->mUnk_50c, v);
                break;
            case 25:
                func_02119770(func_020cb99c(), p->mUnk_108, p->mUnk_50c, 0);
                break;
            case 10:
                if (func_020cae54() == 0) {
                    v = 0;
                } else if (func_020cae38() != 0) {
                    v = 2;
                } else {
                    v = 4;
                }
                p = data_0217b43c;
                func_0211b2cc(func_020cb99c(), (s32) p->mUnk_108, p->mUnk_50c, v);
                break;
            case 16:
                if (func_020cae54() == 0) {
                    v = 1;
                } else if (func_020cae38() != 0) {
                    v = 3;
                } else {
                    v = 5;
                }
                p = data_0217b43c;
                func_0211b2cc(func_020cb99c(), (s32) p->mUnk_108, p->mUnk_50c, v);
                break;
            case 14:
                v = (func_020cae54() == 0) ? UNK_020CB6C0_0 : UNK_020CB6C0_1;
                p = data_0217b43c;
                func_02032654(func_020cb99c(), v, p->mUnk_108, p->mUnk_50c);
                break;
            case 17:
                v = (func_02029930()->mUnk_e4 == 0) ? UNK_020CB6C0_1 : UNK_020CB6C0_0;
                p = data_0217b43c;
                func_ov001_0219d2c0(func_020cb99c(), v, p->mUnk_108, p->mUnk_50c);
                break;
            case 18:
                func_ov001_0219f058(func_020cb99c(), p->mUnk_108, p->mUnk_50c);
                break;
            case 19:
                func_ov001_021a0190((s32) func_020cb99c(), (s32) p->mUnk_108, (s32) p->mUnk_50c);
                break;
            case 20:
                func_ov001_02198100(func_020cb99c(), p->mUnk_108, (s32) p->mUnk_50c);
                break;
            case 26:
                func_ov001_0219bb48((u32) func_020cb99c(), (u32) p->mUnk_108, (u32) p->mUnk_50c);
                break;
            case 12:
            case 24:
                func_0211e958(func_020cb99c(), p->mUnk_108, p->mUnk_50c);
                break;
            case 29:
                func_020cc744();
                break;
        }
        switch (data_0217b43c->mUnk_00c) {
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 16:
            case 17:
                data_0217b43c->mUnk_958 = 0;
                data_0217b43c->mUnk_95c = 0;
                break;
            case 8:
            case 15:
                if (func_020cccb4() == 0xe) {
                    data_0217b43c->mUnk_958 = 0;
                    data_0217b43c->mUnk_95c = 0;
                }
                break;
        }
    }
}

void func_020cb618(void) {
    if (data_0217b43c->mUnk_00c != data_0217b43c->mUnk_008) {
        switch (data_0217b43c->mUnk_008) {
            case 4:
                func_ov001_021a1838();
                break;
            case 5:
            case 8:
            case 15:
            case 21:
                func_020260e4();
                break;
            case 6:
            case 9:
            case 22:
                func_0202808c();
                break;
            case 7:
            case 11:
            case 23:
                func_02117db0();
                break;
            case 13:
            case 25:
                func_021196f4();
                break;
            case 10:
            case 16:
                func_0211b23c();
                break;
            case 14:
                func_0203223c();
                break;
            case 17:
                func_ov001_0219d26c();
                break;
            case 18:
                func_ov001_0219efec();
                break;
            case 19:
                func_ov001_021a0140();
                break;
            case 20:
                func_ov001_021980e0();
                break;
            case 26:
                func_ov001_0219baf4();
                break;
            case 12:
            case 24:
                func_0211e924();
                break;
        }
    }
}
