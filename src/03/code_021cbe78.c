#include "03/code_021cbe78.h"
#include "03/code_021c209c.h"
#include "03/code_021bf000.h"
#include "03/code_021cb000.h"
#include "03/code_021cd000.h"
#include "03/code_021ce000.h"
#include "03/code_021cef90.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "code_0214b824.h"
#include "03/code_021cbc00.h"

void func_ov003_021cbe78(void) {
    Unk021d7708 a = data_ov003_021d7708;
    s32 b;
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0) {
        func_ov003_021c20dc(NULL, &b);
        func_ov003_021cefc0(a.mUnk_00[b], 1, 1, -1, 0);
        SetUpdateFunction(func_ov003_021cbe44);
    }
}
