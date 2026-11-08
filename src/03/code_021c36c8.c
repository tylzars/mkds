#include "03/code_021c36c8.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021c209c.h"
#include "03/code_021c36b0.h"

void func_ov003_021c36c8(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        func_ov003_021c212c(UpdateJb5Info);
    }
}
