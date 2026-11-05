#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffdee4.h"

void func_020d2450(void *a) {
    int v1;
    u8 v2[12];
    u8 v3[20];
    v1 = func_01ffdee4(((s32 *) (a + 4)), NULL, 0, 0xa000, 8, 0xfffffffe, NULL, (v2), NULL, NULL, NULL, NULL, NULL,
                       NULL);
    if (v1 != 0) {
        func_020d7b88((Vec3 *) v2, ((u32 *) (void *) v3));
        Matrix3x3FromQuaternion(((s32 *) (a + 0x28)), v3);
        return;
    }
}
