#include "00/code_02187fb8.h"
#include "00/unk_021b4000.h"
#include "code_0200db4c.h"

void func_ov000_02187fb8(void) {
    if (data_ov000_021b4cb0 != NULL) {
        if (gHttp != NULL) {
            func_ov000_02187274(gHttp);
        }
        func_ov000_02186474();
        if (data_ov000_021b4cb0->mUnk_11c.mUnk_6c != 0) {
            func_0200e084(&data_ov000_021b4cb0->mUnk_11c);
        }
        data_ov000_021b4cb0->mUnk_04 = 0xfffffff9;
    }
}
