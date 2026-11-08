#include "03/code_021c4ad4.h"
#include "03/code_021c391c.h"
#include "03/code_021c482c.h"
#include "03/code_021c3000.h"
#include "03/code_021c3fc8.h"
#include "03/code_021c4000.h"
#include "03/code_021bf000.h"
#include "03/code_021cef90.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"

#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021c209c.h"
#include "03/code_021d083c.h"
#include "03/code_021c25e0.h"
#include "03/code_021d1f70.h"
#include "03/unk_021da000.h"
#include "03/code_021cea3c.h"
#include "03/code_021d1000.h"
#include "03/code_021d3000.h"
#include "03/code_021d3488.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf410.h"
#include "code_0214cfe4.h"

void SetupJb5Move(void) {
    u8 *a;
    void *b;
    u16 c[12];
    a = func_ov003_021c27b4();
    b = func_ov003_021d2288(0, 0);
    data_ov003_021da1d4 = 0;
    data_ov003_021da1d0 = 0;
    LoadJb5MoveFileAndSetBgCnt();
    c[0] = 0;
    MIi_CpuClear16(c[0], &c[1], 0x16);
    MIi_CpuCopy16(a + 2, &c[1], a[1] * 2);
    func_ov003_021d2070(b, data_ov003_021d6380.mUnk_00, data_ov003_021d6380.mUnk_02,
                        data_ov003_021d6380.mUnk_04 - data_ov003_021d6380.mUnk_00,
                        data_ov003_021d6380.mUnk_06 - data_ov003_021d6380.mUnk_02, 2, 0x480, &c[1]);
    func_ov003_021d1fd0(b);
    func_ov003_021c27d0(func_ov003_021c4ad4);
    func_ov003_021c212c(func_ov003_021c4cb0);
}

void LoadJb5MoveFileAndSetBgCnt(void) {
    void *v2 = &gJb5MoveNscName;
    void *v3 = &GX_LoadBG2Scr;
    u32 v4 = LoadFileToVram(v2, v3);
    u32 v5 = 0x4001008u;
    u32 v6 = (*(u16 *) ((v5) + (0)));
    u32 v8 = ((v6) & ~(0x3u));
    u32 v9 = ((v8) | (0x3u));
    u32 v11;
    u32 v12;
    u32 v13;
    u32 v14;
    u32 v16;
    u32 v17;
    u32 v18;
    u32 v19;
    u32 v21;
    u32 v22;
    u32 v23;
    u32 v24;
    u32 v26;
    u32 v27;
    u32 v28;
    u32 v29;
    *(u16 *) ((v5) + (0)) = v9;
    v11 = 0x400100au;
    v12 = (*(u16 *) ((v11) + (0)));
    v13 = ((v12) & ~(0x3u));
    v14 = ((v13) | (0x3u));
    *(u16 *) ((v11) + (0)) = v14;
    v16 = 0x4000008u;
    v17 = (*(u16 *) ((v16) + (0)));
    v18 = ((v17) & ~(0x3u));
    v19 = ((v18) | (0x3u));
    *(u16 *) ((v16) + (0)) = v19;
    v21 = 0x400000au;
    v22 = (*(u16 *) ((v21) + (0)));
    v23 = ((v22) & ~(0x3u));
    v24 = ((v23) | (0x3u));
    *(u16 *) ((v21) + (0)) = v24;
    v26 = 0x400000cu;
    v27 = (*(u16 *) ((v26) + (0)));
    v28 = ((v27) & ~(0x3u));
    v29 = ((v28) | (0x3u));
    *(u16 *) ((v26) + (0)) = v29;
}

void func_ov003_021c4cb0(void) {
    func_ov003_021d1ee0(2, 0, 0x15, 8);
    func_ov003_021d2784(0, 0x15);
    func_ov003_021c212c(func_ov003_021c4c84);
}

void func_ov003_021c4c84(void) {
    int v1;
    v1 = func_ov003_021d1f70(0);
    if (v1 == 0) {
        func_ov003_021cefc0(0x5f, 4, 0, 0xffffffff, 0);
        func_ov003_021c212c(func_ov003_021c4c64);
    }
}

void func_ov003_021c4c64(void) {
    int v1;
    v1 = func_ov003_021cef80();
    if (v1 != -2) {
        func_ov003_021c212c(func_ov003_021c4c0c);
    }
}

void func_ov003_021c4c0c(void) {
    func_ov003_021c4c08();
    func_ov003_021c4c04();
    switch (func_ov003_021cef80()) {
        case 0:
            data_ov003_021da1d4 = 0;
            StartSoundSeq(7);
            break;
        case 1:
            data_ov003_021da1d4 = 1;
            StartSoundSeq(0xe);
            break;
        default:
            return;
    }
    func_ov003_021c27d0(NULL);
    func_ov003_021cef90();
    func_ov003_021c212c(func_ov003_021c4bc4);
}

void func_ov003_021c4c08(void) {}

void func_ov003_021c4c04(void) {}

void func_ov003_021c4bc4(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        if ((*(u8 *) &data_ov003_021da1d4) == 0) {
            func_ov003_021d1ee0(3, 1, 1, 8);
        }
        func_ov003_021d1ee0(3, 0, 0x15, 8);
        func_ov003_021c212c(func_ov003_021c4b78);
    }
}

void func_ov003_021c4b78(void) {
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0) {
        if (data_ov003_021da1d0 == 0 && data_ov003_021da1d4 == 1) {
            func_ov003_021c27c8();
        } else {
            func_ov003_021c2824();
        }
        func_ov003_021c212c(func_ov003_021c4ae0);
    }
}

void func_ov003_021c4ae0(void) {
    int v1;
    if (((data_ov003_021da1d0 == 0) && (data_ov003_021da1d4 != 0)) || (v1 = func_ov003_021c27e4(), v1 != 0)) {
        func_ov003_021d2168(0);
        func_ov003_021d272c(0, 0x15);
        if (data_ov003_021da1d4 == 0) {
            func_ov003_021bf410();
            func_ov003_021d272c(1, 1);
        }
        func_ov003_021c2120(0, 1);
        if (data_ov003_021da1d0 != 0) {
            func_ov003_021c212c(func_ov003_021c4aa4);
            return;
        }
        if (data_ov003_021da1d4 == 0) {
            func_ov003_021d272c(1, 1);
            func_ov003_021c212c(SetupOptMenu);
            return;
        }
        func_ov003_021c212c(func_ov003_021c4054);
    }
}

void func_ov003_021c4ad4(void) {
    data_ov003_021da1d0 = 1;
}
