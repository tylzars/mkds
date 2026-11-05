#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_02050080.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_02055710.h"
#include "Main/Unknown/code_020562b4.h"
#include "Main/Unknown/code_02059878.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0217a000.h"

static inline u32 func_02055030_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline s32 func_02055030_inline2(void) {
    BOOL r = FALSE;
    if (func_02055030_inline() != 0 && data_0217aa00->mUnk_0004 != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02055030_inline3(void) {
    BOOL r = FALSE;
    if (func_02055030_inline2() && !(data_0217aa00->mUnk_0454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02055030_inline4(void) {
    BOOL r = FALSE;
    if (func_02055030_inline3() && data_0217aa00->mUnk_0008 != 9) {
        r = TRUE;
    }
    return r;
}

s32 func_02055564(s32 a) {
    s32 r;

    r = 0;
    if (data_0217aa00->mUnk_0010 != 0) {
        if (data_0217aa00->mUnk_000c == 7 && data_0217aa00->mUnk_043b == 1) {
            if (func_020501b0(a) == 0) {
                func_02050e60(5);
            }
        }
        return 0;
    }
    if (func_02055030_inline4()) {
        return 3;
    }
    switch (data_0217aa00->mUnk_000c) {
        case 7:
            func_02051e98();
            break;
        case 9:
            func_02051d24(NULL, NULL, NULL, func_02055710, NULL);
            break;
        case 2:
        case 10:
            if (data_0217aa00->mUnk_0432 == 0xffff) {
                if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
                    func_02050e60(5);
                    return 3;
                }
                r = 2;
            } else {
                func_02051a24();
            }
            break;
        case 11:
            data_0217aa00->mUnk_0004 = 6;
            func_02059878();
            r = 1;
            break;
    }
    return r;
}

s32 func_020554e4(void) {
    if (data_0217aa00->mUnk_0010 != 0) {
        return 0;
    }
    switch (data_0217aa00->mUnk_000c) {
        case 11:
            if (data_0217aa00->mUnk_008b & 8) {
                func_02051658();
            }
            break;
        case 15:
            data_0217aa00->mUnk_008b &= ~8;
            data_0217aa00->mUnk_000c = 11;
            break;
    }
    return 0;
}

void func_02055340(void) {
    u8 v1;
    u8 b;
    u8 i;

    if (!func_02055030_inline2()) {
        return;
    }
    switch (data_0217aa00->mUnk_0004) {
        case 7:
        case 8:
        case 9:
            if (func_0205373c() == FALSE) {
                data_0217aa00->mUnk_0454 |= 0x10;
            }
            if (data_0217aa00->mUnk_0004 != 9) {
                return;
            }
            if (func_02055030_inline() != 1) {
                return;
            }
            func_02001000();
            break;
        case 2:
            b = data_0217aa00->mUnk_0044.mUnk_43;
            v1 = b | 1;
            if (data_0217aa00->mUnk_0044.mUnk_3e >= 8) {
                data_0217aa00->mUnk_0044.mUnk_3e++;
                if ((s32) data_0217aa00->mUnk_0044.mUnk_3e > 0x2c) {
                    data_0217aa00->mUnk_0044.mUnk_3e = 0;
                }
                return;
            }
            i = data_0217aa00->mUnk_0044.mUnk_3e % 8;
            if (v1 & (1 << i)) {
                if (func_020504a4(i, b) == FALSE) {
                    return;
                }
                data_0217aa00->mUnk_0044.mUnk_3e++;
            } else {
                data_0217aa00->mUnk_0044.mUnk_3e++;
            }
            break;
    }
}

s32 func_02055030(void) {
    BOOL r;

    r = FALSE;
    if (data_0217aa00->mUnk_0004 == 0) {
        data_0217aa00->mUnk_0454 &= ~0x80;
        return 1;
    }
    switch (data_0217aa00->mUnk_000c) {
        case 0x1d:
        case 0x1e:
            func_0204e074();
            break;
        case 0x22:
            func_0204e4bc();
            break;
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x27:
        case 0x28:
        case 0x29:
        case 0x2a:
        case 0x2b:
        case 0x2c:
        case 0x2e:
            data_0217aa00->mUnk_0010 = 0;
            break;
    }
    if (data_0217aa00->mUnk_0010 != 0 && data_0217aa00->mUnk_000c == 7 && data_0217aa00->mUnk_043b == 1) {
        data_0217aa00->mUnk_043b = 0;
    }
    if (data_0217aa00->mUnk_0010 != 0) {
        return 0;
    }
    if (func_02055030_inline4()) {
        return 3;
    }
    switch (data_0217aa00->mUnk_000c) {
        case 38:
            func_02050ec0();
            break;
        case 21:
            data_0217aa00->mUnk_000c = 0;
            break;
        case 0:
            func_020562b4();
            data_0217aa00->mUnk_0004 = 0;
            r = TRUE;
            data_0217aa00->mUnk_0454 &= ~0x80;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 9:
        case 19:
        case 20:
        case 27:
        case 31:
        case 32:
        case 36:
            func_02052cf4();
            break;
        case 7:
        case 8:
            func_02051e98();
            break;
        case 11:
        case 12:
        case 13:
        case 17:
            func_0205146c();
            break;
        case 6:
        case 10:
        case 16:
        case 18:
            switch (func_02055030_inline()) {
                case 1:
                    func_020513ac();
                    break;
                case 2:
                    func_02051230();
                    break;
            }
            break;
        case 14:
        case 15:
        case 37:
            func_020514c0();
            break;
        case 22:
        case 23:
        case 24:
        case 25:
            func_0204e090();
            break;
        case 28:
        case 29:
        case 30:
        case 33:
        case 34:
        case 35:
            func_0204e4bc();
            break;
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 46:
            func_0204eca0();
            break;
        case 45:
            func_0205146c();
            break;
        default:
            func_020533a0();
            break;
    }
    return r;
}

s32 func_02054f58(void) {
    s32 r;
    s32 v;

    r = 0;
    v = func_02055030();
    if (v == 3) {
        switch (data_0217aa00->mUnk_000c) {
            case 0x16:
            case 0x17:
            case 0x18:
            case 0x19:
                func_0204e090();
                break;
            case 0x27:
            case 0x28:
            case 0x29:
            case 0x2a:
            case 0x2b:
            case 0x2c:
            case 0x2e:
                func_0204eca0();
                break;
            case 0x1c:
            case 0x1d:
            case 0x1e:
            case 0x21:
            case 0x22:
            case 0x23:
                func_0204e4bc();
                break;
            default:
                func_020533a0();
                break;
        }
        data_0217aa00->mUnk_0008 = 9;
    } else {
        r = v;
    }
    return r;
}
