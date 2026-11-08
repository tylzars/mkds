#include "03/code_021c2a74.h"
#include "03/code_021c2904.h"
#include "03/code_021c209c.h"
#include "03/code_021c2a28.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"

void func_ov003_021c2a74(void) {
    StartBlendBrightnessFade(3, 1, 0x3f, 0x14);
    StartBlendBrightnessFade(3, 0, 0x3f, 0x14);
    SetUpdateFunction(func_ov003_021c2a28);
}
