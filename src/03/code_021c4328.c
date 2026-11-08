#include "03/code_021c4328.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021c209c.h"
#include "03/code_021c4310.h"

void func_ov003_021c4328(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(func_ov003_021c4310);
    }
}
