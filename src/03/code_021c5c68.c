#include "03/code_021c5c68.h"
#include "code_02147cd8.h"

void func_ov003_021c5c68(void) {
    int v1;
    int v2;
    int v3;
    int v4;
    v1 = func_02147d30((u32) ((*(u16 *) &data_ov003_021da1f0)), 0x1c);
    v4 = data_ov003_021da1f4->mUnk_51;
    func_ov003_021d2060(data_ov003_021da1f4->mUnk_0c, 0);
    if (5 < v4) {
        v4 = 5;
    }
    v2 = 0;
    v3 = v1;
    if (v4 > 0) {
        do {
            func_ov003_021c5b90((int) (v3), (int) (v2));
            v2 = v2 + 1;
            v3 = v3 + 1;
        } while (v2 < v4);
    }
    v3 = 0;
    if (v4 > 0) {
        do {
            func_ov003_021c5b34((int) (v1), (int) (v3));
            v3 = v3 + 1;
            v1 = v1 + 1;
        } while (v3 < v4);
    }
    func_ov003_021d1fd0(data_ov003_021da1f4->mUnk_0c);
    func_ov003_021c5aa4();
    return;
}
