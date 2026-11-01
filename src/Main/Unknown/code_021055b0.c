#include "Main/Unknown/code_021055b0.h"

#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_0210d000.h"
#include "Main/Unknown/code_0212da2c.h"
#include "code_0212c478.h"
#include "code_0212da38.h"
#include "code_0212c6ac.h"
#include "code_0212df7c.h"

void func_0210593c(u32 a) {
    if (a != 4) {
        return;
    }
    if (data_0217d070.mUnk_0c != 0) {
        return;
    }
    func_0210d5c0(&data_0217d070);
}

void func_021057f0(u32 a, u32 b) {
    u32 r = 0xff;
    *(s32 *) data_0217c784 = a;
    data_0217c79c = 0;
    data_0217c7a0 = 0;
    data_0217c774 = 0xff;
    if (a != 3) {
        return;
    }
    switch (b) {
        case 1:
            data_0217c774 = 1;
            r = 0x25;
            break;
        case 2:
            data_0217c774 = 2;
            r = 0x26;
            break;
        case 3:
            data_0217c774 = 3;
            r = 0x27;
            break;
        case 4:
            data_0217c774 = 4;
            r = 0x28;
            break;
        case 5:
            data_0217c774 = 5;
            r = 0x29;
            break;
        case 6:
            data_0217c774 = 6;
            r = 0x25;
            break;
        case 7:
            data_0217c774 = 7;
            r = 0x17;
            break;
    }
    func_0212da38(data_0217d130, data_0217c798[0]);
    func_0212da2c(data_0217d130);
    func_0212e95c(r, data_0217d130);
    func_0212e95c(0x2a, data_0217d130);
    func_0212e994(4, data_0217d130);
}

void func_021055b0(s32 a) {
    s32 v;
    u32 f;
    s32 n;
    if (*(s32 *) data_0217c784 == 0) {
        if (data_0217d070.mUnk_0c != 0) {
            return;
        }
        func_0210d5c0(&data_0217d070);
        return;
    }
    if (a != 0 && a != 0x32) {
        return;
    }
    f = 0;
    v = 0x78;
    n = (a == 0x32) ? data_0217c79c : data_0217c7a0;
    if (n < 5) {
        switch (n) {
            case 0:
                v = 0xf;
                break;
            case 1:
                v = 0x1e;
                f = 1;
                break;
            case 2:
                v = 0x2d;
                break;
            case 3:
                v = 0x46;
                break;
            case 4:
                v = 0x2d;
                break;
        }
    } else {
        switch ((n - 5) % 6) {
            case 0:
                v = 0x1e;
                break;
            case 1:
                v = 0x2d;
                break;
            case 2:
                v = 0x46;
                break;
            case 3:
                v = 0x5f;
                f = 1;
                break;
            case 4:
                v = 0x46;
                break;
            case 5:
                v = 0x2d;
                break;
        }
    }
    if (a == 0x32) {
        Unk0212c400 **p = (Unk0212c400 **) data_0217c83c;
        if (*p != 0) {
            func_0212c6f0(p, 0);
        }
        func_0212ecc0(p, 4, 0);
        if (*p != 0) {
            func_0212c554(p, data_0216cb20, v & 0xff);
        }
        data_0217c79c++;
        return;
    }
    if (a != 0) {
        return;
    }
    if (f != 0) {
        u16 h = data_0217c774;
        if (h != 0xff) {
            Unk0212c400 **p = (Unk0212c400 **) data_0217c840;
            if (*p != 0) {
                func_0212c6f0(p, 0);
            }
            func_0212ecc0(p, 4, h);
        }
    }
    data_0217c7a0++;
}
