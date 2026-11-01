#include "03/code_021c25e0.h"
#include "03/code_021d0e90.h"
#include "03/code_021d27d8.h"
#include "03/code_021d34c8.h"
#include "code_0214cfe4.h"

// non-matching: the original reads the object pointer into r0 and the offset into r1 (ours swaps them) and its switch
// is a table for 0..20 plus compares for 23, 26, 29, 34 under a first compare against 26; ours is a compare tree
// (size 0x1bc against the original's 0x1d4)
void func_ov003_021c25e0(u32 a) {
    u8 b[2];
    Unk021da194 *p;
    func_ov003_021d0ee0();
    p = data_ov003_021da194;
    if (p->mUnk_1e2a0 != 0 && p->mUnk_1e2a1 == 0) {
        if (p->mUnk_1e298 == 0) {
            return;
        }
        p->mUnk_1e298(0);
        return;
    }
    func_ov003_021d0e9c(&b[0], &b[1]);
    switch (b[0]) {
        case 5:
            if (b[1] == 0) {
                break;
            }
            func_0214cffc(func_ov003_021d0e90(), data_ov003_021da194->mUnk_1e280, 0x16);
            if (data_ov003_021da194->mUnk_1e298 != 0) {
                data_ov003_021da194->mUnk_1e298(0);
            } else {
                data_ov003_021da194->mUnk_1e2a0 = 1;
            }
            break;
        case 13:
            if (b[1] == 0) {
                break;
            }
            if (data_ov003_021da194->mUnk_1e298 != 0) {
                data_ov003_021da194->mUnk_1e298(1);
            } else {
                data_ov003_021da194->mUnk_1e2a0 = 1;
            }
            break;
        case 20:
        case 23:
            if (b[1] == 0) {
                break;
            }
            if (data_ov003_021da194->mUnk_1e298 != 0) {
                data_ov003_021da194->mUnk_1e298(3);
            } else {
                data_ov003_021da194->mUnk_1e2a0 = 1;
            }
            break;
        case 26:
        case 29:
            if (b[1] == 0) {
                break;
            }
            if (data_ov003_021da194->mUnk_1e298 != 0) {
                data_ov003_021da194->mUnk_1e298(4);
            } else {
                data_ov003_021da194->mUnk_1e2a0 = 1;
            }
            break;
        case 12:
            if (b[1] == 0) {
                break;
            }
            if (data_ov003_021da194->mUnk_1e298 != 0) {
                data_ov003_021da194->mUnk_1e298(2);
            } else {
                data_ov003_021da194->mUnk_1e2a0 = 1;
            }
            break;
        case 34:
            func_ov003_021d34c8(0, a);
            func_ov003_021d2808(&data_ov003_021da194);
            break;
    }
}
