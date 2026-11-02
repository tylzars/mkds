#include "Main/Unknown/code_020b1de4.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_020b252c.h"
#include "Main/Unknown/code_020b24e4.h"
#include "Main/Unknown/code_020b2540.h"
#include "Main/Unknown/code_020b3260.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_020b2000.h"
#include "Main/Unknown/code_020b3000.h"

void func_020b24cc(Unk02180728 *a, void *b, void *c, s32 d, s32 e) {
    a->mUnk_00 = b;
    a->mUnk_04 = c;
    a->mUnk_08 = d;
    a->mUnk_0c = e;
}

u32 func_020b24a4(Unk02180728 *a, s32 b, s32 c, u32 d, u32 e, void *f) {
    return func_02024340(a, b, c, d, e, f);
}

#pragma thumb on
#pragma optimize_for_size on

void func_020b1df0(void) {
    Unk0217b354 *p;
    u32 n;
    s32 i;

    data_0217b354 = func_02036bec(func_020b2540(), 0x1a4);
    data_0217b354->mUnk_000 = 0;
    data_0217b354->mUnk_004 = 0;
    data_0217b354->mUnk_008 = 0;
    data_0217b354->mUnk_00c = 0;
    data_0217b354->mUnk_014 = 0;
    data_0217b354->mUnk_010 = 0;
    data_0217b354->mUnk_01c = 0;
    if (func_020b252c() == 4) {
        data_0217b354->mUnk_020 = func_020adb34();
    } else {
        data_0217b354->mUnk_020 = 0;
    }
    data_0217b354->mUnk_02c = 0;
    data_0217b354->mUnk_030 = 0;
    func_020b3008();
    func_020b31e4();
    switch (func_020b252c()) {
        case 0:
            func_020b31b8(0, 0);
            func_020b31b8(0, 9);
            if (func_020b250c() != 0) {
                func_020b31b8(1, 7);
                func_020b31b8(1, 8);
            } else {
                func_020b31b8(1, 2);
                func_020b31b8(1, 8);
                func_020b31b8(1, 9);
            }
            if (func_020b250c() != 0) {
                func_020b31b8(3, 0);
                func_020b31b8(3, 7);
                func_020b31b8(3, 8);
            } else {
                func_020b31b8(3, 0);
                func_020b31b8(3, 2);
                func_020b31b8(3, 8);
                func_020b31b8(3, 9);
            }
            break;
        case 1:
            func_020b31b8(0, 0);
            func_020b31b8(0, 3);
            func_020b31b8(0, 4);
            func_020b31b8(0, 5);
            func_020b31b8(0, 9);
            func_020b31b8(1, 1);
            func_020b31b8(1, 4);
            func_020b31b8(1, 5);
            func_020b31b8(1, 8);
            func_020b31b8(1, 9);
            func_020b31b8(3, 0);
            func_020b31b8(3, 1);
            func_020b31b8(3, 4);
            func_020b31b8(3, 5);
            func_020b31b8(3, 8);
            func_020b31b8(3, 9);
            break;
        case 2:
            func_020b31b8(0, 0);
            func_020b31b8(0, 9);
            func_020b31b8(1, 2);
            func_020b31b8(1, 9);
            func_020b31b8(2, 7);
            break;
        case 3:
            func_020b31b8(0, 0);
            func_020b31b8(0, 9);
            func_020b31b8(1, 2);
            func_020b31b8(1, 9);
            func_020b31b8(2, 7);
            break;
        case 4:
            func_020b31b8(0, 0);
            func_020b31b8(0, 3);
            func_020b31b8(0, 6);
            func_020b31b8(0, 9);
            if (func_020b2f58() != 0) {
                if (func_020adc04() != 0) {
                    func_020b31b8(1, 1);
                    func_020b31b8(1, 6);
                    func_020b31b8(1, 9);
                    func_020b31b8(2, 6);
                    func_020b31b8(2, 1);
                    func_020b31b8(2, 10);
                    func_020b31b8(2, 9);
                } else {
                    func_020b31b8(1, 1);
                    func_020b31b8(1, 6);
                    func_020b31b8(1, 9);
                    func_020b31b8(2, 6);
                    func_020b31b8(2, 1);
                    func_020b31b8(2, 9);
                }
            } else {
                func_020b31b8(1, 1);
                func_020b31b8(1, 6);
                func_020b31b8(1, 9);
                func_020b31b8(2, 6);
                func_020b31b8(2, 1);
                func_020b31b8(2, 9);
            }
            break;
        case 5:
            func_020b31b8(0, 0);
            if (func_020b24f8() != 4) {
                func_020b31b8(1, 2);
            } else {
                func_020b31b8(1, 7);
            }
            break;
    }
    if (func_020b24e4() != 3 && func_020b24e4() != 6) {
        const char *t[6] = {
            "choises_s_1.NSCR", "choises_s_2.NSCR", "choises_s_3.NSCR",
            "choises_s_4.NSCR", "choises_s_5.NSCR", "choises_s_6.NSCR",
        };

        LoadNclrData(&data_0217b354->mChoisesSBNclr, FindSceneFileWrapper("choises_s_b.NCLR"));
        LoadNcgrData(&data_0217b354->mChoisesSBNcgr, FindSceneFileWrapper("choises_s_b.NCGR"));
        for (i = 0; i < 6; i++) {
            LoadNscrData(&data_0217b354->mChoisesSNscrs[i], FindSceneFileWrapper(t[i]));
        }
        data_0217b354->mUnk_17c = data_0217b354->mChoisesSNscrs[data_0217b354->mUnk_038[0].mUnk_18 - 1];
        data_0217b354->mUnk_180 = data_0217b354->mChoisesSNscrs[data_0217b354->mUnk_038[1].mUnk_18 - 1];
        data_0217b354->mUnk_184 = data_0217b354->mChoisesSNscrs[data_0217b354->mUnk_038[2].mUnk_18 - 1];
        data_0217b354->mUnk_188 = data_0217b354->mChoisesSNscrs[data_0217b354->mUnk_038[3].mUnk_18 - 1];
        data_0217b354->mUnk_174 = func_02036bec(func_020b2540(), func_020b3260(data_0217b354->mUnk_038[1].mUnk_18));
        switch (func_020b252c()) {
            case 2:
            case 3:
            case 4:
                data_0217b354->mUnk_178 =
                    func_02036bec(func_020b2540(), func_020b3260(data_0217b354->mUnk_038[2].mUnk_18));
                break;
        }
        data_0217b354->mUnk_0a8 = func_020b403c(2);
        func_02023408(data_0217b354->mUnk_0ac[0], func_020b3374()->mUnk_14, 0x20, 0xc, 4);
        p = data_0217b354;
        func_020b24cc(&p->mUnk_12c[0], p->mUnk_0ac[0], p->mUnk_0a8, func_020b4acc(), 0);
        func_02023408(data_0217b354->mUnk_0ac[1], data_0217b354->mUnk_174, 0x20, 0xc, 4);
        p = data_0217b354;
        func_020b24cc(&p->mUnk_12c[1], p->mUnk_0ac[1], p->mUnk_0a8, func_020b4acc(), 0);
        n = func_020b3260(data_0217b354->mUnk_038[1].mUnk_18) >> 1;
        for (i = 0; i < n; i++) {
            data_0217b354->mUnk_174[i] = func_020b3374()->mUnk_14[i];
        }
        if (data_0217b354->mUnk_178 != 0) {
            func_02023408(data_0217b354->mUnk_0ac[2], data_0217b354->mUnk_178, 0x20, 0xc, 4);
            p = data_0217b354;
            func_020b24cc(&p->mUnk_12c[2], p->mUnk_0ac[2], p->mUnk_0a8, func_020b4acc(), 0);
            n = func_020b3260(data_0217b354->mUnk_038[2].mUnk_18) >> 1;
            for (i = 0; i < n; i++) {
                data_0217b354->mUnk_178[i] = func_020b3374()->mUnk_14[i];
            }
        }
        func_02023408(data_0217b354->mUnk_0ac[3], func_020b3374()->mUnk_14, 0x20, 0xc, 4);
        p = data_0217b354;
        func_020b24cc(&p->mUnk_12c[3], p->mUnk_0ac[3], p->mUnk_0a8, func_020b4acc(), 0);
        if (func_020b24e4() != 2) {
            for (i = 0; i < data_0217b354->mUnk_038[0].mUnk_18; i++) {
                func_020b24a4(&data_0217b354->mUnk_12c[0], 0x90, i * 16 + 9, 0xc, 0x412,
                              func_020b320c(0, data_0217b354->mUnk_038[0].mUnk_00[i]));
            }
        } else {
            for (i = 0; i < data_0217b354->mUnk_038[3].mUnk_18; i++) {
                func_020b24a4(&data_0217b354->mUnk_12c[3], 0x90, i * 16 + 9, 0xc, 0x412,
                              func_020b320c(3, data_0217b354->mUnk_038[3].mUnk_00[i]));
            }
        }
        for (i = 0; i < data_0217b354->mUnk_038[1].mUnk_18; i++) {
            func_020b24a4(&data_0217b354->mUnk_12c[1], 0x90, i * 16 + 9, 0xc, 0x412,
                          func_020b320c(1, data_0217b354->mUnk_038[1].mUnk_00[i]));
        }
        for (i = 0; i < data_0217b354->mUnk_038[2].mUnk_18; i++) {
            func_020b24a4(&data_0217b354->mUnk_12c[2], 0x90, i * 16 + 9, 0xc, 0x412,
                          func_020b320c(2, data_0217b354->mUnk_038[2].mUnk_00[i]));
        }
    } else {
        data_0217b354->mChoisesSBNclr = 0;
        data_0217b354->mChoisesSBNcgr = 0;
        data_0217b354->mUnk_174 = 0;
        data_0217b354->mUnk_178 = 0;
        data_0217b354->mUnk_17c = 0;
        data_0217b354->mUnk_180 = 0;
        data_0217b354->mUnk_184 = 0;
        data_0217b354->mUnk_188 = 0;
    }
}

void func_020b1de4(void) {
    data_0217b354 = 0;
}

#pragma thumb off
