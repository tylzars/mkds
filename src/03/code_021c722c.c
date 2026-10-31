#include "03/code_021c722c.h"
#include "03/code_021d2168.h"
#include "03/code_021d254c.h"
#include "03/code_021d27d8.h"
#include "03/code_021d2f00.h"

void func_ov003_021c722c(void) {
    int v1[1];
    func_ov003_021bf410();
    func_ov003_021d2f00((u32 *) (u32) (*(u32 *) ((int) data_ov003_021da1fc + 4)));
    func_ov003_021d2168(0);
    func_ov003_021bf620((u32) &data_ov003_021d7338, (u32) &func_0214c090);
    func_ov003_021d272c(1, (u32) 1);
    func_ov003_021d272c(0, (u32) 0x15);
    func_ov003_021c20dc(v1, 0);
    if (3 <= v1[0]) {
        v1[0] = v1[0] + 1;
    }
    func_ov003_021c2120((u32) 2, (u32) 1);
    func_ov003_021c20f8((u32) 0, (u32) (v1[0] + 3));
    func_ov003_021c212c(func_ov003_021c965c);
    func_ov003_021d2808((int *) &data_ov003_021da1fc);
}
