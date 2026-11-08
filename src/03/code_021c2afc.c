#include "03/code_021c2afc.h"
#include "03/code_021c2aa0.h"
#include "03/code_021d1dd0.h"

void func_ov003_021c2afc(void) {
    StartBlendBrightnessFade(2, 1, 2, 0x14);
    StartBlendBrightnessFade(2, 0, 2, 0x14);
    SetUpdateFunction(func_ov003_021c2aa0);
}
