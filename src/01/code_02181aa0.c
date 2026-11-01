#include "01/code_02181aa0.h"
#include "01/code_02181000.h"
#include "01/code_02182000.h"
#include "01/code_02183000.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02108000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"

u16 func_ov001_02181b30(void) {
    return data_ov001_021a9b90->mUnk_44 + data_021759c0->mUnk_3d0 - 1;
}

void func_ov001_02181aa0(void) {
    Unk021a9b90 *p;
    u32 n;

    if ((data_021759c0->mUnk_08 == 4 ? func_020a126c() : 0) != 0) {
        return;
    }
    p = data_ov001_021a9b90;
    n = func_ov001_0218180c();
    if (p->mUnk_04 >= n) {
        return;
    }
    p->mUnk_04 = p->mUnk_04 + 1;
    func_02108edc(data_ov001_021a9b90->mUnk_04, func_ov001_0218180c());
    switch (data_021759c0->mUnk_2f) {
        case 0:
        case 1:
        case 3:
        case 5:
        case 7:
            n = func_ov001_0218180c();
            if (data_ov001_021a9b90->mUnk_04 >= n) {
                func_0203e74c(data_021759c0->mUnk_62);
            }
            break;
    }
}
