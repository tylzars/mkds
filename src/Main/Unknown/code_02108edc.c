#include "Main/Unknown/code_02108edc.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212c6ac.h"
#include "code_0212df7c.h"

void func_02108edc(s32 a, s32 b) {
    u32 c;
    Unk0210bf24 *p;

    if (a == b) {
        if (data_0217c76c[0] != 0xff) {
            func_0212ecc0(&data_0217d068, 0, data_0217c76c[0]);
        }
        if (data_0217c76c[0] == 0x1d7) {
            func_0212ecc0(&data_0217d068, 0, 0x1de);
            return;
        }
        c = data_021759c0->mUnk_3c;
        if (c == 0x65 || c == 0xc9) {
            func_0212ecc0(&data_0217d068, 0, 0xd4);
        }
    } else {
        c = data_0217c770[0];
        if (c == 0xff) {
            return;
        }
        if (!(data_0217c780 & 1)) {
            return;
        }
        p = func_0210e128((Unk0217c7c4 *) data_0217c7c4);
        if (data_0217d084.mUnk_0c == 0) {
            return;
        }
        if (p->mUnk_00 != 0) {
            func_0212c6f0(&p->mUnk_00, 0);
        }
        if (p->mUnk_00 != 0) {
            func_0212c6f0(&p->mUnk_00, 0);
        }
        func_0212ecc0(p, 0, c);
    }
}
