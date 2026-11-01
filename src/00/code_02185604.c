#include "00/code_02185604.h"
#include "00/code_02184bec.h"
#include "00/code_0218554c.h"
#include "00/code_021855f8.h"
#include "00/code_0218536c.h"
#include "00/code_021804f4.h"
#include "00/code_ov000_021804e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_0212658c.h"

void func_ov000_02185788(void) {
    u8 a[20];
    s32 i;

    func_02061220((u32) a);
    for (i = 0; i < 12; i++) {
        data_ov000_021b4c88->mUnk_0e[i] = a[i];
    }
}

void func_ov000_021856a8(void) {
    s32 n = 0x4000;
    u8 a[12] = {0, 0, 1, 2, 3, 4, 1, 6, 7, 8, 9, 10};
    u8 b[12] = {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
    u16 c;
    s32 i;
    s16 z[2];

    c = data_ov000_021b4c88->mUnk_40->mUnk_06;
    func_ov000_02185788();
    for (i = 0; i < 12; i++) {
        if (b[i] == 0) {
            a[i] = a[i] + c;
        }
    }
    for (i = 0; i < 12; i++) {
        n -= func_021243ac(data_ov000_021b4c88->mUnk_2c, data_ov000_021b06dc[i], data_ov000_021b4c88->mUnk_48, 8, 0x10,
                           a[i], data_ov000_021b4c88->mUnk_34, data_ov000_021b4c88->mUnk_40,
                           data_ov000_021b4c88->mUnk_30, n);
        z[0] = 0;
        z[1] = 0;
        z[0] = data_ov000_021b4c88->mUnk_0e[i];
        func_0212426c(0, data_ov000_021b06dc[i], data_ov000_021b4c88->mUnk_48, z, data_ov000_021b4c88->mUnk_40,
                      data_ov000_021b4c88->mUnk_30);
    }
}

void func_ov000_02185604(void *a) {
    void *b;

    data_ov000_021b4c88 = func_02036bec(a, 0x54);
    data_ov000_021b4c88->mUnk_2c = a;
    data_ov000_021b4c88->mUnk_00 = 0;
    data_ov000_021b4c88->mUnk_04 = 0;
    data_ov000_021b4c88->mUnk_28 = -1;
    data_ov000_021b4c88->mUnk_08 = 0;
    data_ov000_021b4c88->mUnk_4c = func_0204799c(data_ov000_021b0fc0);
    data_ov000_021b4c88->mUnk_50 = func_02047a28(data_ov000_021b0fcc);
    func_ov000_0218554c();
    b = func_ov000_021804f4();
    func_020ae6d4(b, func_ov000_021804e0());
    func_02124ed0(a, data_ov000_021b4c88->mUnk_40, data_ov000_021b4c88->mUnk_48, &data_ov000_021b4c88->mUnk_30);
    data_ov000_021b4c88->mUnk_0c = 0x50;
    func_ov000_021854f8();
    func_ov000_021856a8();
    func_02126638(func_020b3f7c(data_ov000_021b4c88->mUnk_4c, 0x11), 0, 1, 0, 0, 0, 0);
}
