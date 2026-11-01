#include "03/code_021bf43c.h"
#include "03/code_021bf620.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d6000.h"
#include "code_0214b824.h"

u32 func_ov003_021bf43c(u32 v1, s32 v2, u32 v3) {
    void *a;
    void *b;

    if (data_ov003_021da10c != 0) {
        return 0;
    }
    func_ov003_021bf620(data_ov003_021d697c, func_0214bdd4);
    *(vu32 *) 0x4001010 = 0x1920000;
    a = func_ov003_021d2288(1, 0);
    b = func_ov003_021c250c(data_ov003_021da19c, v1, v2, v3);
    func_ov003_021d2070(a, data_ov003_021d5efc[0], data_ov003_021d5efc[1], data_ov003_021d5efc[2],
                        data_ov003_021d5efc[3], 2, func_ov003_021bf4dc(), b);
    func_ov003_021d1fd0(a);
    data_ov003_021da10c = 1;
    return 1;
}
