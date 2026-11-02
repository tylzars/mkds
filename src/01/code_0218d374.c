#include "01/code_0218d374.h"

#include "01/code_02185ef4.h"
#include "01/code_02188000.h"
#include "01/code_02188da4.h"
#include "01/code_02187000.h"
#include "01/code_0218d520.h"
#include "01/code_0218ddb4.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/code_0210b708.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_0218d000.h"
#include "01/code_0218e000.h"
#include "01/unk_021a7000.h"

void func_ov001_0218d3ec(Unk02188950 *param_1) {
    s32 x;
    s32 y;
    s32 t;

    if (func_020a1154((u16) data_021759c0->mUnk_62) <= 1) {
        y = 0x1000 - param_1->mUnk_0a0->mUnk_0ac;
        t = func_ov001_02187f38(param_1);
        x = (s32) (((s64) t * y) >> 12);
    } else if (func_020a1154((u16) data_021759c0->mUnk_62) <= 2) {
        y = 0x1000 - param_1->mUnk_0a0->mUnk_0a8;
        t = func_ov001_02187f38(param_1);
        x = (s32) (((s64) t * y) >> 12);
    } else {
        x = func_ov001_02187f38(param_1);
    }
    func_ov001_02187218(param_1, 1, func_ov001_0218d520);
    func_ov001_02188dcc(param_1, 0);
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_088), (s32) (param_1->mUnk_0a0->mUnk_08c));
    func_ov001_0218d824(param_1, x);
    func_ov001_0218d87c(param_1, x);
    func_ov001_0218d8f4(param_1, x);
    func_ov001_0218dce4(param_1);
}

void func_ov001_0218d374(Unk02188950 *param_1) {
    int i;
    Unk0218d87c *list;
    Unk02188950 *p;

    func_ov001_02187218(param_1, 8, 0);
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_078), (s32) (param_1->mUnk_0a0->mUnk_07c));
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    list = func_02100138(0x1fe);
    if (list != 0) {
        for (i = 0; i < list->mUnk_04 && (p = list->mUnk_00[i]) != 0; i++) {
            func_ov001_02187218(p, 1, 0);
            func_ov001_02188d64(p, (s32) (p->mUnk_0a0->mUnk_078), (s32) (p->mUnk_0a0->mUnk_07c));
        }
    }
}
