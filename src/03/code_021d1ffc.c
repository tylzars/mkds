#include "03/code_021d1ffc.h"
#include "03/code_021d1790.h"
#include "03/code_021d1970.h"
#include "Main/Unknown/code_02022000.h"

void func_ov003_021d1ffc(Unk021d1ffc *param_1, s32 param_2, s32 param_3, Unk021d1770 *param_4, s32 param_5) {
    void *a = func_ov003_021d1974((int) param_4, 0);

    func_ov003_021d18f0(param_4, -1, 0, 0);
    func_ov003_021d1890(param_4, -1, 0, 0xf);
    func_ov003_021d1790(param_4, -1, param_5);
    func_02022eb0(a, param_1->mUnk_36, param_1->mUnk_37, param_2, param_3, 0, param_1->mUnk_34, 2);
}
