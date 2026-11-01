#include "03/code_021bf620.h"
#include "03/code_021d1000.h"
#include "03/unk_021d5000.h"
#include "03/code_021c20d0.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_02139f70.h"

u32 func_ov003_021bf620(void *param_0, void *param_1) {
    u32 a;
    void *b;

    b = func_ov003_021d14b8(func_ov003_021bf650((const u8 *) param_0), &a, 4);
    func_0200ee74(b, a);
    ((void (*)(void *, u32, u32)) param_1)(b, 0, a);
    func_ov003_021d1490(b);
}

u8 *func_ov003_021bf650(const u8 *param_0) {
    u32 a;

    func_0213a228(data_ov003_021da110, param_0, 0x3f);
    if (param_0[5] == 0x78) {
        return data_ov003_021da110;
    }
    a = func_ov003_021c20d0();
    if (param_0[5] == 0x79 && a != 0) {
        return data_ov003_021da110;
    }
    data_ov003_021da110[5] = data_ov003_021d5f04[a];
    return data_ov003_021da110;
}
