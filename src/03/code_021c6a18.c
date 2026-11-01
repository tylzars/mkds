#include "03/code_021c6a18.h"
#include "03/code_021d2168.h"
#include "03/code_021d254c.h"
#include "03/code_021d27d8.h"
#include "03/code_021d2f00.h"

void func_ov003_021c6a18(void) {
    s32 v1;
    int v2[1];
    func_ov003_021bf410();
    func_ov003_021d2f00((u32 *) (u32) data_ov003_021da1f8->mUnk_04);
    func_ov003_021d2168(0);
    func_ov003_021bf620((u32) &data_ov003_021d728c, (u32) &func_0214c090);
    func_ov003_021d272c(1, (u32) 1);
    func_ov003_021d272c(0, (u32) 0x15);
    func_ov003_021c20dc(&v1, v2);
    if (v2[0] == 0) {
        func_ov003_021c2120((u32) 2, (u32) 1);
        func_ov003_021c20f8((u32) 0, (u32) v1);
        func_ov003_021c212c(func_ov003_021c965c);
    } else if (data_ov003_021da1f8->mUnk_2a == 0) {
        func_ov003_021c2120((u32) 0, (u32) 1);
        func_ov003_021c20f8((u32) 1, (u32) 0);
        func_ov003_021c212c(func_ov003_021c6668);
    } else {
        func_ov003_021c2120((u32) 0, (u32) 0);
        func_ov003_021c20f8((u32) 0, (u32) 1);
        func_ov003_021c212c(func_ov003_021cbf60);
    }
    func_ov003_021d2808((int *) &data_ov003_021da1f8);
}
