#include "03/code_021c2aa0.h"
#include "03/code_021c209c.h"
#include "03/code_021c2c94.h"
#include "03/code_021c3000.h"
#include "03/code_021cb000.h"
#include "03/code_021cb11c.h"
#include "03/code_021d1f70.h"

void func_ov003_021c2aa0(void) {
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0) {
        switch (GetMode()) {
            case 0:
                func_ov003_021c2120(0, 1);
                SetUpdateFunction(SetupJb2Menu);
                break;
            case 1:
                func_ov003_021c2120(1, 1);
                SetUpdateFunction(CreateAp);
                break;
        }
    }
}
