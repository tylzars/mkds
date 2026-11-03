#include "Main/Unknown/code_0204b03c.h"
#include "Main/Unknown/code_0204b458.h"
#include "Main/Unknown/code_0204b714.h"
#include "code_0200eddc.h"
#include "code_021457ec.h"
#include "01/code_021956dc.h"

#pragma thumb on

void func_0204b5dc(void (*a)(u32 *, u32)) {
    u32 *p;
    u32 n;
    s32 e;
    BOOL f;
    u32 s;
    f = TRUE;
    s = func_021457ec();
    func_0204b3dc();
    e = 0;
    data_021759d4->mUnk_10 = 0;
    switch (s) {
        case 0:
            e = 0;
            break;
        case 1:
        case 4:
        case 6:
            e = 2;
            break;
        case 2:
        case 3:
        case 5:
        case 7:
        default:
            e = 1;
            break;
    }
    p = data_021759d4->mUnk_40;
    n = data_021759d4->mUnk_48;
    switch (data_021759d4->mUnk_14) {
        case 0:
            f = TRUE;
            break;
        case 1:
            data_021759d4->mUnk_1c = e;
            data_021759d4->mUnk_20 = data_021759d4->mUnk_40;
            data_021759d4->mUnk_24 = 0;
            func_0204b458(data_021759d4->mUnk_18, data_021759d4->mUnk_40, data_021759d4->mUnk_48, a, 2,
                          data_021759d4->mUnk_50);
            f = FALSE;
            break;
        case 2:
            if (e != 0) {
                if (data_021759d4->mUnk_1c == 0) {
                    p = data_021759d4->mUnk_20;
                    e = 0;
                } else if (e == 2 || data_021759d4->mUnk_1c == 2) {
                    e = 2;
                } else if (e != 1 && data_021759d4->mUnk_1c != 1) {
                    e = 3;
                } else {
                    e = 1;
                }
            }
            break;
    }
    if (f != FALSE) {
        if (e == 0) {
            if (a != NULL) {
                a(p, n);
            }
            func_0204ba7c();
            return;
        }
        if (e == 2) {
            data_021759d4->mUnk_0c = 0;
        }
        func_0204b344(e);
    }
}

void func_0204b574(void) {
    BOOL r;
    r = FALSE;
    if (func_021457ec() != 0) {
        r = TRUE;
    }
    if (r == FALSE) {
        func_0204ba7c();
        func_02145e8c((u32) data_021759d4->mUnk_40, data_021759d4->mUnk_44, data_021759d4->mUnk_48,
                      (UnkFunc *) func_0204b5dc, data_021759d4->mUnk_54, 1, 7, 10, 2);
    } else {
        func_0204b3dc();
        data_021759d4->mUnk_10 = 0;
        func_0204b344(r);
    }
}

u32 func_0204b518(void) {
    if (data_021759d4->mUnk_0c == 0 || func_02145d2c() == 0) {
        return 0;
    }
    if (func_0204b3a4() == 0) {
        return 0;
    }
    func_02145e8c(0, (u32) data_021759d4->mUnk_64, 1, (UnkFunc *) func_0204b574, NULL, 1, 6, 1, 0);
    return 1;
}

u32 func_0204b458(u32 a, u32 *b, u32 n, void (*c)(u32 *, u32), s32 d, s32 e) {
    u32 *p;
    u32 m;
    if (data_021759d4->mUnk_0c == 0 || func_02145d2c() == 0) {
        return 0;
    }
    data_021759d4->mUnk_04 = NULL;
    data_021759d4->mUnk_10 = 1;
    data_021759d4->mUnk_00 = 1;
    data_021759d4->mUnk_44 = a;
    data_021759d4->mUnk_40 = b;
    data_021759d4->mUnk_48 = n;
    data_021759d4->mUnk_50 = e;
    data_021759d4->mUnk_54 = c;
    data_021759d4->mUnk_14 = d;
    if (d != 2) {
        if (e != 0) {
            p = b + 2;
            m = n - 8;
        } else {
            p = b;
            m = n;
        }
        func_0204b284((u8 *) b, n, 0);
        func_0204b138(p, m);
        func_0200ee58(b, n);
        return func_0204b518();
    }
    func_02145e8c((u32) b, a, n, (UnkFunc *) func_0204b5dc, c, 1, 7, 10, 2);
    return 1;
}

#pragma thumb off
