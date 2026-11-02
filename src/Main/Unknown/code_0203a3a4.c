#include "Main/Unknown/code_0203a3a4.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02045874.h"

#include "00/code_02182fdc.h"
#include "Main/Unknown/code_02029aa0.h"
#include "Main/Unknown/code_0204673c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"

u32 func_0203a8f4(void) {
    return ((u32) data_021759c0->mUnk_08);
}

void func_0203a8e0(u32 p0) {
    data_021759d0->mUnk_44 = p0;
}

void func_0203a520(Unk0203a0dc *a, u32 b) {
    s32 r;
    data_0217b488->mUnk_08 = 0;
    r = -1;
    switch (b) {
        case 10:
            func_02045a2c(0);
            r = 2;
            break;
        case 9:
            if (data_021759c0->mUnk_08 != 5) {
                u32 t;
                u32 f;
                Unk0217aa00 *q;
                f = 0;
                q = data_0217aa00;
                if (q == NULL) {
                    t = 0;
                } else {
                    t = q->mUnk_0000;
                }
                if (t != 0) {
                    if (q->mUnk_0004 != 0xd) {
                        f = 1;
                    }
                }
                if (f != 0) {
                    if (data_021759d0->mUnk_1c_2 != 0) {
                        r = 6;
                        data_0217b488->mUnk_74 = 3;
                    } else {
                        r = 1;
                    }
                    data_0217b488->mUnk_08 = 4;
                    data_0217b488->mUnk_04 = 1;
                } else {
                    r = 0;
                }
                if (data_021759c0->mUnk_08 == 1) {
                    func_0204673c();
                }
            } else {
                r = 0xc;
                data_0217b488->mUnk_1c = 0;
            }
            break;
        case 1:
        case 3:
            r = 2;
            data_021759c0->mUnk_1e8.mUnk_0c = 0;
            break;
        case 8:
            r = 2;
            data_021759c0->mUnk_1e8.mUnk_0c = r;
            break;
        case 2:
            switch (data_021759c0->mUnk_08) {
                case 0:
                    func_02046740();
                    r = 2;
                    break;
                case 3:
                    if (func_02045914() != 0) {
                        if (data_021759d0->mUnk_1c_2 == 0) {
                            r = 2;
                        } else {
                            r = 6;
                            data_0217b488->mUnk_74 = 1;
                        }
                    } else {
                        if (data_021759c0->mUnk_020 == 0) {
                            data_0217b488->mUnk_08 = 2;
                        }
                        if (data_021759d0->mUnk_1c_2 == 0) {
                            r = 1;
                        } else {
                            r = 6;
                            data_0217b488->mUnk_74 = 3;
                        }
                    }
                    break;
                case 5:
                    if (func_02045874() != 0) {
                        r = 0xc;
                        data_0217b488->mUnk_1c = 3;
                    } else {
                        r = 0xa;
                        data_0217b488->mUnk_1c = 2;
                    }
                    break;
                case 2:
                    if (func_020458cc() != 0) {
                        if (data_021759d0->mUnk_1c_2 == 0) {
                            r = 2;
                        } else {
                            r = 6;
                            data_0217b488->mUnk_74 = 1;
                        }
                    } else {
                        if (data_021759c0->mUnk_020 == 0) {
                            data_0217b488->mUnk_08 = 2;
                        }
                        if (data_021759d0->mUnk_1c_2 == 0) {
                            r = 1;
                        } else {
                            r = 6;
                            data_0217b488->mUnk_74 = 3;
                        }
                    }
                    break;
            }
            break;
        case 7:
            switch (data_021759c0->mUnk_08) {
                case 0:
                    if (func_02045bd4() != 0) {
                        r = 2;
                    } else {
                        r = 0xa;
                    }
                    break;
                case 4:
                    r = 0;
                    break;
                case 2:
                case 3:
                    if (data_021759d0->mUnk_1c_2 != 0) {
                        r = 6;
                        data_0217b488->mUnk_74 = 2;
                    } else {
                        r = 0xa;
                    }
                    break;
            }
            break;
        case 5:
            r = 1;
            data_0217b488->mUnk_08 = r;
            break;
        case 4:
            data_0217b488->mUnk_08 = 2;
            r = 1;
            break;
        case 6:
            data_0217b488->mUnk_08 = 3;
            r = 1;
            break;
    }
    if (r != -1) {
        a->mUnk_04 = r;
    }
}

u32 func_0203a50c(void) {
    return data_021759c0->mUnk_00c;
}

void func_0203a4d4(u32 a) {
    if (a != 0) {
        data_021759d0->mUnk_50 |= 1;
    } else {
        data_021759d0->mUnk_50 &= ~1;
    }
}

u32 func_0203a4cc(void) {
    return 0x8u;
}

u16 func_0203a4a8(u32 a, u32 b) {
    u32 v;
    v = data_02175628[a].mUnk_02;
    return v & b;
}

u32 func_0203a48c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value12 = (u32) &func_0212ecc0;
    value2 = value0;
    value0 = (u32) &data_0217d068;
    value1 = 0u;
    value0 = (u32) func_0212ecc0((const void *) value0, value1, value2);
    return value0;
}

u32 func_0203a440(u32 a) {
    u32 r;
    u32 f;
    u16 x;
    r = 1;
    f = 0;
    x = data_02175628[a].mUnk_4c;
    if (x == 0 && data_02175628[a].mUnk_58 < 5) {
        f = 1;
    }
    if (f == 0 && x == 0) {
        r = 0;
    }
    return r;
}

u32 func_0203a42c(void) {
    return (u32) data_0217561c->mUnk_4d0;
}

u32 func_0203a3cc(u32 a) {
    u32 r;
    u32 f;
    r = 0;
    f = 0;
    if (data_02175628[a].mUnk_4c == 0 && data_02175628[a].mUnk_58 < 5) {
        f = 1;
    }
    if (f == 0 && data_02175628[a].mUnk_54 == 0 && data_02175628[a].mUnk_4c != 0) {
        r = 1;
    }
    return r;
}

void func_0203a3b8(u32 p0) {
    data_021759c0->mUnk_1e8.mUnk_0c = p0;
}

u32 func_0203a3a4(void) {
    return ((u32) data_021759c0->mUnk_00);
}
