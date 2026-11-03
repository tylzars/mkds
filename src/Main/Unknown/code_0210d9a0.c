#include "Main/Unknown/code_0210d9a0.h"
#include "Main/Unknown/code_0210d120.h"
#include "Main/Unknown/code_0210d960.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212bcac.h"

void func_0210d9a0(Unk0217d084 *a, u32 b) {
    u32 v;

    v = func_0210d960();
    switch (b) {
        case 0:
            if (a->mUnk_04 != 0) {
                func_0210d200(0);
                func_0210d120(0);
                func_0212c6f0(&a->mUnk_00->mUnk_10, 0);
                func_0212c6f0(&a->mUnk_00->mUnk_0c, 0);
                if (a->mUnk_18 != NULL) {
                    func_0212c6f0(a->mUnk_18, 0);
                }
                a->mUnk_10 = 0;
                a->mUnk_0c = 0;
            }
            break;
        case 1:
            if (a->mUnk_04 != 1) {
                func_0210d200(0);
                func_0210d120(0);
                if (a->mUnk_04 == 5) {
                    v = func_0210d960();
                    func_0212c620(&a->mUnk_00->mUnk_0c, 0x7f, v);
                    func_0212c620(&a->mUnk_00->mUnk_10, 0x7f, v);
                    if (a->mUnk_18 != NULL) {
                        func_0212c620(a->mUnk_18, 0x7f, v);
                    }
                }
                a->mUnk_10 = 0;
                a->mUnk_0c = 1;
            }
            break;
        case 2:
            if (a->mUnk_04 != 2) {
                if (a->mUnk_04 == 5) {
                    u32 w;

                    w = func_0210d960();
                    func_0212c620(&a->mUnk_00->mUnk_0c, 0x7f, w);
                    func_0212c620(&a->mUnk_00->mUnk_10, 0x7f, w);
                    if (a->mUnk_18 != NULL) {
                        func_0212c620(a->mUnk_18, 0x7f, w);
                    }
                    func_0210d1a4(0x7f, v);
                }
                a->mUnk_10 = 1;
                a->mUnk_0c = 1;
            }
            break;
        case 3:
            if (a->mUnk_04 != 3) {
                a->mUnk_10 = 0;
                a->mUnk_0c = 0;
                func_0210d200(5);
                func_0210d120(5);
                func_0212c6f0(&a->mUnk_00->mUnk_10, 5);
            }
            break;
        case 4:
            if (a->mUnk_04 != 4) {
                a->mUnk_10 = 0;
                a->mUnk_0c = 0;
                func_0210d200(v);
                func_0210d120(v);
                func_0212c6f0(&a->mUnk_00->mUnk_10, v);
                func_0212c6f0(&a->mUnk_00->mUnk_0c, v);
                if (a->mUnk_18 != NULL) {
                    func_0212c6f0(a->mUnk_18, v);
                }
            }
            break;
        case 5:
            if (a->mUnk_04 != 5) {
                func_0212c620(&a->mUnk_00->mUnk_0c, 0, v);
                func_0212c620(&a->mUnk_00->mUnk_10, 0, v);
                if (a->mUnk_18 != NULL) {
                    func_0212c620(a->mUnk_18, 0, v);
                }
                a->mUnk_10 = 0;
                a->mUnk_0c = 0;
                func_0210d1a4(0, v);
                a->mUnk_08 = a->mUnk_04;
            }
            break;
    }
    a->mUnk_04 = b;
}
