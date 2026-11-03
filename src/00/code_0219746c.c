#include "00/code_0218e0fc.h"
#include "00/code_0218e368.h"
#include "00/code_0218e3c4.h"
#include "00/code_02196960.h"
#include "00/code_021971ec.h"
#include "00/code_0219742c.h"
#include "00/code_0219746c.h"
#include "00/code_0218e8c4.h"
#include "00/code_021a3668.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/unk_021b4000.h"
#include "code_0213442c.h"
#include "code_02134d30.h"
#include "code_02135014.h"
#include "code_02139f70.h"

s8 *func_ov000_02197a9c(const char *a, const char *b, s8 *c) {
    u32 d;
    char e[0x80];
    d = strlen(b);
    if (strlen(a) + d + 0x14 >= 0x80) {
        *(Unk021b3e44 *) c = data_ov000_021b3e44;
        return c;
    }
    sprintf(e, data_ov000_021b3e64, b, a);
    func_ov000_0218e0fc(e, strlen(e), (char *) c);
    return c;
}

s32 func_ov000_02197924(s32 a, s32 b) {
    u8 c[8];
    s8 d[0x84];
    s32 e;
    data_ov000_021b4e68 = a;
    if (b != 0) {
        data_ov000_021b3b34 = b;
    }
    if (data_ov000_021b4d28 != 1) {
        return 1;
    }
    if (*(u32 *) &data_ov000_021b4e50 == 0) {
        func_ov000_0219742c();
    }
    func_ov000_0218e8b8();
    data_ov000_021b4e64 = func_ov000_0218e8c4();
    if (data_ov000_021b3b2c != -1) {
        func_ov000_02197634();
    }
    data_ov000_021b4e54 = 0;
    if (func_ov000_0218e374((u32) data_ov000_021b3c48) == -1) {
        strcpy((char *) d, data_ov000_021b4e84);
        strcat((char *) d, data_ov000_021b3e40);
        strcat((char *) d, data_ov000_021b3c48);
    } else {
        strcpy((char *) d, data_ov000_021b3c48);
    }
    if (func_ov000_02197064(d, 0x74e0, c, NULL) == 0) {
        return 2;
    }
    data_ov000_021b3b2c = func_ov000_0218e554(2, 1, 0);
    if (data_ov000_021b3b2c == -1) {
        return 1;
    }
    func_ov000_0218e80c(data_ov000_021b3b2c, 0);
    e = func_ov000_0218e4b4(data_ov000_021b3b2c, c, 8);
    if (e == -1) {
        e = func_ov000_0218e368(data_ov000_021b3b2c);
        if (e != -6 && e != -0x4c && e != -0x1a) {
            data_ov000_021b4e60 = 1;
            func_ov000_0218e53c(data_ov000_021b3b2c);
            return 3;
        }
    }
    data_ov000_021b4e58 = func_ov000_021a3690(0x40);
    if (data_ov000_021b4e58 == NULL) {
        return 3;
    }
    data_ov000_021b4e74 = 0x40;
    data_ov000_021b4e54 = 0;
    data_ov000_021b4e48 = func_ov000_0218e8c4();
    data_ov000_021b4e60 = 2;
    return 6;
}

s32 func_ov000_021976bc(void) {
    s32 a[2];
    s32 b;
    s32 c;
    switch (data_ov000_021b4e60) {
        case 1:
            return 3;
        case 2:
            a[0] = 0;
            a[1] = 0;
            b = func_ov000_0218e68c(data_ov000_021b3b2c, NULL, (u32 *) &a[0], (u32 *) &a[1]);
            if (b == -1 || (b == 1 && a[1] == 1)) {
                data_ov000_021b4e60 = 1;
                func_ov000_02197634();
                return 3;
            }
            if (b == 0) {
                if (func_ov000_0218e8c4() - data_ov000_021b4e48 > data_ov000_021b3b34) {
                    data_ov000_021b4e60 = 1;
                    func_ov000_02197634();
                    return 7;
                }
                return 6;
            }
            if (b != 1 || a[0] != 1) {
                func_0213442c(data_ov000_021b3e14, data_ov000_021b3e34, NULL, 0x145);
            }
            data_ov000_021b4e60 = 3;
        case 3:
            if (func_ov000_0218e668(data_ov000_021b3b2c) == 0) {
                if (func_ov000_0218e8c4() - data_ov000_021b4e48 > data_ov000_021b3b34) {
                    data_ov000_021b4e60 = 1;
                    func_ov000_02197634();
                    return 7;
                }
                return 6;
            }
            b = func_ov000_0218e460(data_ov000_021b3b2c, data_ov000_021b4e58 + data_ov000_021b4e54,
                                    data_ov000_021b4e74 - data_ov000_021b4e54, 0);
            if (b == -1) {
                data_ov000_021b4e60 = 1;
                func_ov000_02197634();
                return 3;
            }
            data_ov000_021b4e54 += b;
            data_ov000_021b4e74 -= b;
            if (data_ov000_021b4e54 < 0x26) {
                return 6;
            }
            data_ov000_021b4e58[data_ov000_021b4e54] = 0;
            data_ov000_021b4e60 = 4;
            data_ov000_021b3b30 = data_ov000_021b3b88;
            func_ov000_021971ec(data_ov000_021b4e58, data_ov000_021b4e54);
            c = func_ov000_0219735c(data_ov000_021b4e58, data_ov000_021b4e68);
            if (c != 0) {
                data_ov000_021b4e60 = 1;
                func_ov000_02197634();
                return c;
            }
            data_ov000_021b4e60 = 4;
            data_ov000_021b4e74 += data_ov000_021b4e54;
            data_ov000_021b4e54 = 0;
            memset(data_ov000_021b4e58, 0, data_ov000_021b4e74);
        case 4:
            if (func_ov000_0218e668(data_ov000_021b3b2c) == 0) {
                if (func_ov000_0218e8c4() - data_ov000_021b4e48 > data_ov000_021b3b34) {
                    data_ov000_021b4e60 = 1;
                    func_ov000_02197634();
                    return 7;
                }
                return 6;
            }
            c = func_ov000_021972b4();
            if (c != 0) {
                data_ov000_021b4e60 = 1;
                func_ov000_02197634();
                return c;
            }
            data_ov000_021b4e74 += data_ov000_021b4e54;
            data_ov000_021b4e54 = 0;
            memset(data_ov000_021b4e58, 0, data_ov000_021b4e74);
            data_ov000_021b4e60 = 5;
        case 5:
            return 0;
        default:
            return 3;
    }
}

s32 func_ov000_02197690(s32 a) {
    s32 b = func_ov000_02197924(a, 0);
    if (b == 6) {
        do {
            b = func_ov000_021976bc();
            func_ov000_0218e8bc(5);
        } while (b == 6);
    }
    return b;
}

void func_ov000_02197634(void) {
    if (data_ov000_021b3b2c != -1) {
        func_ov000_0218e524(data_ov000_021b3b2c, 2);
        func_ov000_0218e53c(data_ov000_021b3b2c);
    }
    data_ov000_021b3b2c = -1;
    func_ov000_02196960();
    if (data_ov000_021b4e58 != NULL) {
        func_ov000_021a3668(data_ov000_021b4e58);
        data_ov000_021b4e58 = NULL;
        data_ov000_021b4e74 = 0;
        data_ov000_021b4e54 = 0;
    }
}

s8 *func_ov000_021975f4(s8 *a) {
    if (a == NULL) {
        a = data_ov000_021b4e6c;
    }
    if (a == NULL) {
        func_ov000_02197190(data_ov000_021b4e4c ^ 0x38f371e6, data_ov000_021b4e78);
        return data_ov000_021b4e78;
    }
    return a + 0x10;
}

void func_ov000_02197594(s32 a, s32 b, s32 c, UnkFunc *d, s32 e) {
    Unk021b3bb8 f = data_ov000_021b3bb8;
    s8 g[0x100];
    s32 h;
    data_ov000_021b3b30 = data_ov000_021b3b98;
    func_ov000_021971ec(f.mUnk_00, 0x23);
    h = sprintf((char *) g, (const char *) f.mUnk_00, b, c, a);
    func_ov000_02196f8c(g, h, a, d, e);
}

void func_ov000_02197558(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    func_ov000_02196e50(a, b, c, d, (const u8 *) e, strlen((const char *) e) + 1, (UnkFunc *) f, g, 1);
}

BOOL func_ov000_0219746c(void) {
    s32 a;
    s32 b;
    if (data_ov000_021b3b2c == -1) {
        return FALSE;
    }
    if (data_ov000_021b4e60 != 5) {
        return FALSE;
    }
    if (func_ov000_02196e48(data_ov000_021b3b2c) != 0) {
        do {
            if (data_ov000_021b4e74 - data_ov000_021b4e54 < 0x80) {
                if (data_ov000_021b4e74 < 0x100) {
                    data_ov000_021b4e74 = 0x100;
                } else {
                    data_ov000_021b4e74 = data_ov000_021b4e74 * 2;
                }
                data_ov000_021b4e58 = func_ov000_021a3678(data_ov000_021b4e58, data_ov000_021b4e74 + 1);
                if (data_ov000_021b4e58 == NULL) {
                    return FALSE;
                }
            }
            a = func_ov000_0218e460(data_ov000_021b3b2c, data_ov000_021b4e58 + data_ov000_021b4e54,
                                    data_ov000_021b4e74 - data_ov000_021b4e54, 0);
            if (a <= 0) {
                func_ov000_02197634();
                return FALSE;
            }
            data_ov000_021b4e54 += a;
            data_ov000_021b4e58[data_ov000_021b4e54] = 0;
            b = func_ov000_02196a84((u8 *) data_ov000_021b4e58, data_ov000_021b4e54);
            if (b == data_ov000_021b4e54) {
                data_ov000_021b4e54 = 0;
            } else {
                memmove(data_ov000_021b4e58, data_ov000_021b4e58 + b, data_ov000_021b4e54 - b);
                data_ov000_021b4e54 -= b;
            }
        } while (func_ov000_02196e48(data_ov000_021b3b2c) != 0);
    }
    return data_ov000_021b3b2c != -1;
}
