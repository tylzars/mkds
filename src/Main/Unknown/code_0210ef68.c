#include "Main/Unknown/code_0210ef68.h"

#include "code_02003024.h"
#include "code_02004270.h"
#include "code_0212d254.h"
#include "code_0212d5e0.h"
#include "code_02004d80.h"
#include "Main/Unknown/code_0210e33c.h"
#include "code_0212d214.h"

u32 func_0210efcc(Unk0212d5f8 *a, const u8 *b, void *c, u32 d) {
    a->mUnk_8c = 0;
    a->mUnk_84 = 0;
    a->mUnk_88 = 0;
    if (FS_ConvertPathToFileID(&a->mUnk_7c, b) == 0) {
        return 0;
    }
    FS_InitFile(&a->mUnk_34);
    if (FS_OpenFileFast(&a->mUnk_34, a->mUnk_7c) == 0) {
        return 0;
    }
    a->mUnk_30 = 1;
    if (func_0212d6c4(a, c, d) == 0) {
        return 0;
    }
    func_0212d5e0(a);
    return 1;
}

void func_0210efac(Unk0217d178 *p) {
    s32 i;

    for (i = 0; i < 16; i++) {
        p->mUnk_00[i] = 0;
    }
    p->mUnk_40 = 0;
}

void func_0210ef68(Unk0217d178 *p) {
    s32 i;

    for (i = 0; i < p->mUnk_40; i++) {
        func_0212d238(p->mUnk_00[i], 0);
    }
}
