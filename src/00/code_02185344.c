#include "00/code_02185344.h"
#include "00/unk_021b0000.h"
#include "code_0214b824.h"

#include "00/code_02180608.h"
#include "00/code_02184ba8.h"
#include "00/unk_021b4000.h"
#include "00/code_ov000_021804e0.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_020472a8.h"

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
    data_ov000_021b4c88->mUnk_4c = FindSceneFile(data_ov000_021b0fc0);
    data_ov000_021b4c88->mUnk_50 = func_02047a28(data_ov000_021b0fcc);
    func_ov000_0218554c();
    b = func_ov000_021804f4();
    func_020ae6d4(b, func_ov000_021804e0());
    func_02124ed0(a, data_ov000_021b4c88->mUnk_40, data_ov000_021b4c88->mUnk_48, &data_ov000_021b4c88->mUnk_30);
    data_ov000_021b4c88->mUnk_0c = 0x50;
    func_ov000_021854f8();
    func_ov000_021856a8();
    func_02126638(GetBmgEntry(data_ov000_021b4c88->mUnk_4c, 0x11), 0, 1, 0, 0, 0, 0);
}

void func_ov000_021855f8(void) {
    data_ov000_021b4c88 = 0;
}

void func_ov000_0218554c(void) {
    void *v1;
    v1 = FindSceneFile((const char *) &data_ov000_021b0f28);
    data_ov000_021b4c88->mUnk_40 = v1;
    v1 = FindSceneFile((const char *) &data_ov000_021b0f44);
    data_ov000_021b4c88->mUnk_48 = v1;
    v1 = FindSceneFile((const char *) &data_ov000_021b0f60);
    LocateNcgr2(&data_ov000_021b4c88->mUnk_38, v1);
    v1 = FindSceneFile((const char *) &data_ov000_021b0f80);
    LocateNcer(&data_ov000_021b4c88->mUnk_34, v1);
    v1 = FindSceneFile((const char *) &data_ov000_021b0fa0);
    LocateNclr(&data_ov000_021b4c88->mUnk_3c, v1);
    func_0214bf04(data_ov000_021b4c88->mUnk_38->mUnk_14, 0, (u32) data_ov000_021b4c88->mUnk_38->mUnk_10);
    func_0214c090(data_ov000_021b4c88->mUnk_3c->mUnk_0c, 0, (u32) 0x1a0);
    func_0214c090(data_ov000_021b4c88->mUnk_3c->mUnk_0c + 0xe0, 0x1c0, (u32) 0x40);
}

void func_ov000_021854f8(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        data_ov000_021b4c88->mUnk_30[data_ov000_021b06d8[i]].mUnk_06 = data_ov000_021b4c88->mUnk_0c;
    }
    for (i = 0; i < 12; i++) {
        data_ov000_021b4c88->mUnk_30[data_ov000_021b06dc[i] + data_ov000_021b4c88->mUnk_40->mUnk_06].mUnk_06 =
            data_ov000_021b4c88->mUnk_0c;
    }
}

void func_ov000_021854a8(void) {
    data_ov000_021b4c88->mUnk_08 = data_ov000_021b4c88->mUnk_08 + 1;
    data_ov000_021b4c88->mUnk_0c = func_020ae4c0(1, 0x50, 0, data_ov000_021b4c88->mUnk_08, 15);
    if (data_ov000_021b4c88->mUnk_08 >= 15 && func_02125fa4() != 0) {
        data_ov000_021b4c88->mUnk_04 = 1;
        data_ov000_021b4c88->mUnk_08 = 0;
    }
}

void func_ov000_02185418(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    s32 a;
    s32 b;
    u16 c;

    if ((u16) (data_02175628[i].mUnk_00 & 2) == 0) {
        a = 0;
        b = 0;
        c = data_02175628[i].mUnk_4c;
        if (c == 0 && data_02175628[i].mUnk_58 < 5) {
            b = 1;
        }
        if (b == 0 && data_02175628[i].mUnk_54 == 0 && c != 0) {
            a = 1;
        }
        if (a == 0 || func_02128210(data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a) == 0) {
            return;
        }
    }
    data_ov000_021b4c88->mUnk_04 = 2;
    data_ov000_021b4c88->mUnk_28 = 8;
    func_02128310(0);
    func_02125fc0();
}

void func_ov000_021853c4(void) {
    data_ov000_021b4c88->mUnk_08 = data_ov000_021b4c88->mUnk_08 + 1;
    data_ov000_021b4c88->mUnk_0c = func_020ae4c0(1, 0, 0x50, data_ov000_021b4c88->mUnk_08, 15);
    if (data_ov000_021b4c88->mUnk_08 >= 15 && func_02125f88() != 0 && func_02128294() != 0) {
        func_ov000_021806e0(data_ov000_021b4c88->mUnk_28);
    }
}

void func_ov000_0218536c(void) {
    Unk021b4c88 *p;

    data_ov000_021b4c88->mUnk_00 = data_ov000_021b4c88->mUnk_04;
    switch (data_ov000_021b4c88->mUnk_00) {
        case 0:
            func_ov000_021854a8();
            break;
        case 1:
            func_ov000_02185418();
            break;
        case 2:
            func_ov000_021853c4();
            break;
    }
    func_ov000_021854f8();
    p = data_ov000_021b4c88;
    func_02124c30(p->mUnk_40, p->mUnk_34, p->mUnk_48, func_ov000_021804f4(), p->mUnk_30);
}

void func_ov000_02185368(void) {}

void func_ov000_02185344(void) {
    Unk021b0cd4 callbacks = data_ov000_021b0f18;
    func_ov000_021806ec(&callbacks);
}
