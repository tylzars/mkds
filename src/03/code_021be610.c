#include "03/code_021be610.h"
#include "03/code_021bf098.h"
#include "03/code_021d1770.h"
#include "03/code_021d1000.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"
#include "03/code_021d2ecc.h"
#include "03/unk_021d5000.h"
#include "03/unk_021d8000.h"
#include "03/unk_021da000.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "code_02147cd8.h"
#include "03/code_021d1970.h"
#include "03/code_021d1c18.h"
#include "00/code_021a669c.h"

void func_ov003_021bf048(u32 param_0) {
    Unk021da108 *a;
    s32 i;

    func_ov003_021d34c8(0, param_0);
    a = data_ov003_021da108;
    if (a->mUnk_10 != 0) {
        func_ov003_021d34c8(0, a->mUnk_10);
    }
    for (i = 0; i < 2; i++) {
        if (data_ov003_021da108->mUnk_00[i] != 0) {
            func_ov003_021d197c((Unk021d1770 *) data_ov003_021da108->mUnk_00[i]);
        }
    }
    func_ov003_021d197c((Unk021d1770 *) data_ov003_021da108->mUnk_08);
    func_ov003_021d2808(&data_ov003_021da108);
}

void func_ov003_021befa4(u32 param_0) {
    Unk021da108 *a;
    s32 i;
    s32 n;
    u32 b;
    u32 c;
    u32 d;

    a = data_ov003_021da108;
    a->mUnk_14 = a->mUnk_14 + 1;
    if (data_ov003_021da108->mUnk_14 >= 0x10) {
        a = data_ov003_021da108;
        n = data_ov003_021d5ecc[a->mUnk_17];
        for (i = 0; i < n; i++) {
            a = data_ov003_021da108;
            b = (data_ov003_021d5edc + a->mUnk_17 * 2)[i];
            func_ov003_021d1c3c(0, b, (u8 *) func_ov003_021d1974(a->mUnk_00[i], 0));
            func_ov003_021d1790((Unk021d1770 *) data_ov003_021da108->mUnk_00[i], -1, 1);
        }
        func_ov003_021bf258(data_ov003_021d5ec4[1]);
        data_ov003_021da108->mUnk_14 = 0;
        data_ov003_021da108->mUnk_16 = -1;
        a = data_ov003_021da108;
        if (a->mUnk_10 != 0) {
            a->mUnk_10 = 0;
            func_ov003_021d34c8(0, param_0);
        }
    }
}

void func_ov003_021beef8(int param_1) {
    Unk021da104 *a;
    Unk021da104_04 *b;
    u32 c;

    a = func_ov003_021d283c(0xc, 4);
    data_ov003_021da104 = a;
    a->mUnk_08 = param_1;
    data_ov003_021da104->mUnk_04 = func_ov003_021d1c18(0, 0x47);
    b = data_ov003_021da104->mUnk_04;
    b->mUnk_04 = (b->mUnk_04 & 0xfffff3ff) | 0x400;
    b = data_ov003_021da104->mUnk_04;
    b->mUnk_00 = b->mUnk_00 & 0xfffff3ff;
    b->mUnk_04 = (b->mUnk_04 & 0xffff0fff) | (data_ov003_021d5ebc[param_1] << 12);
    b = data_ov003_021da104->mUnk_04;
    b->mUnk_00 =
        ((data_ov003_021d5ec0[0] & 0x1ff) << 16) | ((b->mUnk_00 & 0xfe00ff00) | (data_ov003_021d5ec0[1] & 0xff));
    data_ov003_021da104->mUnk_00 = func_ov003_021d3544(1, func_ov003_021bee24, NULL, 0x78);
}

void func_ov003_021beecc(void) {
    func_ov003_021d34c0(1, data_ov003_021da104->mUnk_00);
    func_ov003_021d2f00((u32 *) data_ov003_021da104->mUnk_04);
    func_ov003_021d2808(&data_ov003_021da104);
}

void func_ov003_021bee24(void) {
    Unk021da104 *a;
    Unk021da104_04 *b;
    u32 c;

    data_ov003_021da104->mUnk_09 = Div32Remainder(data_ov003_021da104->mUnk_09 + 1, 0x28);
    c = Div32(data_ov003_021da104->mUnk_09, 5) + 0x47;
    func_ov003_021d1c3c(0, c, (u8 *) data_ov003_021da104->mUnk_04);
    b = data_ov003_021da104->mUnk_04;
    b->mUnk_04 = (b->mUnk_04 & 0xfffff3ff) | 0x400;
    a = data_ov003_021da104;
    c = data_ov003_021d5ebc[a->mUnk_08];
    b = a->mUnk_04;
    b->mUnk_00 = b->mUnk_00 & 0xfffff3ff;
    b->mUnk_04 = (b->mUnk_04 & 0xffff0fff) | (c << 12);
    b = data_ov003_021da104->mUnk_04;
    b->mUnk_00 =
        ((data_ov003_021d5ec0[0] & 0x1ff) << 16) | ((b->mUnk_00 & 0xfe00ff00) | (data_ov003_021d5ec0[1] & 0xff));
}

void func_ov003_021bea3c(Unk021bea3c *param_0) {
    if (param_0 == NULL) {
        return;
    }
    switch (param_0->mUnk_00) {
        case 1:
            if (param_0->mUnk_02 == 0) {
                if (data_ov003_021d8bfc == 4) {
                    data_ov003_021d8bfc = 3;
                    if (data_ov003_021d8c50 != NULL) {
                        data_ov003_021d8c50(6, 0);
                    }
                } else if (data_ov003_021d8bfc == 6) {
                    if (func_ov000_021a61c4(data_ov003_021d8c14, data_ov003_021d8c18, data_ov003_021d8c30) == 3) {
                        return;
                    }
                    data_ov003_021d8bfc = 3;
                    if (data_ov003_021d8c50 != NULL) {
                        data_ov003_021d8c50(2, 0);
                    }
                } else if (data_ov003_021d8bfc == 8) {
                    if (func_ov000_021a5e84((Unk021a5e84 *) data_ov003_021d8c1c, (Unk02188de4 *) data_ov003_021d8bf8,
                                            data_ov003_021d8c28) == 3) {
                        return;
                    }
                    data_ov003_021d8bfc = 3;
                    if (data_ov003_021d8c50 != NULL) {
                        data_ov003_021d8c50(2, 0);
                    }
                }
            } else {
                data_ov003_021d8bfc = 1;
                if (data_ov003_021d8c50 != NULL) {
                    data_ov003_021d8c50(2, 0);
                }
            }
            break;
        case 3:
            if (param_0->mUnk_02 == 0) {
                if (data_ov003_021d8bfc == 6) {
                    data_ov003_021d8bfc = 5;
                    if (data_ov003_021d8c50 != NULL) {
                        data_ov003_021d8c50(8, 0);
                    }
                }
            } else {
                data_ov003_021d8bfc = 3;
                if (data_ov003_021d8c50 != NULL) {
                    data_ov003_021d8c50(9, 0);
                }
            }
            break;
        case 5:
            if (param_0->mUnk_02 == 0) {
                if (data_ov003_021d8bfc == 8) {
                    data_ov003_021d8bfc = 7;
                    if (data_ov003_021d8c50 != NULL) {
                        data_ov003_021d8c50(12, 0);
                    }
                }
            } else {
                data_ov003_021d8bfc = 3;
                if (data_ov003_021d8c50 != NULL) {
                    data_ov003_021d8c50(13, 0);
                }
            }
            break;
        case 4:
            if (param_0->mUnk_02 == 0) {
                if (data_ov003_021d8bfc == 4) {
                    data_ov003_021d8bfc = 3;
                    if (data_ov003_021d8c50 != NULL) {
                        data_ov003_021d8c50(10, 0);
                    }
                } else if (data_ov003_021d8bfc == 6) {
                    if (func_ov000_021a61c4(data_ov003_021d8c14, data_ov003_021d8c18, data_ov003_021d8c30) == 3) {
                        return;
                    }
                    data_ov003_021d8bfc = 3;
                    if (data_ov003_021d8c50 != NULL) {
                        data_ov003_021d8c50(2, 0);
                    }
                } else if (data_ov003_021d8bfc == 2) {
                    if (func_ov000_021a61e4() == 3) {
                        return;
                    }
                    data_ov003_021d8bfc = 3;
                    if (data_ov003_021d8c50 != NULL) {
                        data_ov003_021d8c50(2, 0);
                    }
                } else if (data_ov003_021d8bfc == 8) {
                    if (func_ov000_021a5e84((Unk021a5e84 *) data_ov003_021d8c1c, (Unk02188de4 *) data_ov003_021d8bf8,
                                            data_ov003_021d8c28) == 3) {
                        return;
                    }
                    data_ov003_021d8bfc = 3;
                    if (data_ov003_021d8c50 != NULL) {
                        data_ov003_021d8c50(2, 0);
                    }
                }
            } else {
                data_ov003_021d8bfc = 3;
                if (data_ov003_021d8c50 != NULL) {
                    data_ov003_021d8c50(11, 0);
                }
            }
            break;
        case 6:
            if (param_0->mUnk_02 == 0) {
                if (data_ov003_021d8bfc == 4) {
                    data_ov003_021d8bfc = 3;
                    if (data_ov003_021d8c50 != NULL) {
                        data_ov003_021d8c50(14, 0);
                    }
                } else if (data_ov003_021d8bfc == 6) {
                    if (func_ov000_021a61c4(data_ov003_021d8c14, data_ov003_021d8c18, data_ov003_021d8c30) == 3) {
                        return;
                    }
                    data_ov003_021d8bfc = 3;
                    if (data_ov003_021d8c50 != NULL) {
                        data_ov003_021d8c50(2, 0);
                    }
                } else if (data_ov003_021d8bfc == 2) {
                    if (func_ov000_021a61e4() == 3) {
                        return;
                    }
                    data_ov003_021d8bfc = 3;
                    if (data_ov003_021d8c50 != NULL) {
                        data_ov003_021d8c50(2, 0);
                    }
                } else if (data_ov003_021d8bfc == 8) {
                    if (func_ov000_021a5e84((Unk021a5e84 *) data_ov003_021d8c1c, (Unk02188de4 *) data_ov003_021d8bf8,
                                            data_ov003_021d8c28) == 3) {
                        return;
                    }
                    data_ov003_021d8bfc = 3;
                    if (data_ov003_021d8c50 != NULL) {
                        data_ov003_021d8c50(2, 0);
                    }
                } else if (data_ov003_021d8bfc == 7) {
                    data_ov003_021d8bfc = 3;
                }
            } else {
                data_ov003_021d8bfc = 3;
                if (data_ov003_021d8c50 != NULL) {
                    data_ov003_021d8c50(15, 0);
                }
            }
            break;
        case 2:
            if (param_0->mUnk_02 == 0) {
                if (data_ov003_021d8bfc == 2) {
                    func_ov000_021a6428();
                    data_ov003_021d8bfc = 0;
                    if (data_ov003_021d8c50 != NULL) {
                        data_ov003_021d8c50(20, 0);
                    }
                }
            } else {
                data_ov003_021d8bfc = 3;
                if (data_ov003_021d8c50 != NULL) {
                    data_ov003_021d8c50(2, 0);
                }
            }
            break;
        case 7:
            if (data_ov003_021d8bfc == 5) {
                if (data_ov003_021d8c50 != NULL) {
                    data_ov003_021d8c50(5, 0);
                }
            }
            break;
        case 8:
            if (data_ov003_021d8c50 != NULL) {
                data_ov003_021d8c50(4, 0);
            }
            break;
        case 9:
            data_ov003_021d8bfc = 0;
            if (data_ov003_021d8c50 != NULL) {
                data_ov003_021d8c50(3, 0);
            }
            break;
        default:
            if (data_ov003_021d8c50 != NULL) {
                data_ov003_021d8c50(1, 0);
            }
            break;
    }
}

u32 func_ov003_021be9b8(void) {
    switch (data_ov003_021d8bfc) {
        case 5:
            if (func_ov000_021a61c4(NULL, NULL, 0) != 3) {
                return 0;
            }
            break;
        case 7:
            if (func_ov000_021a5db0() != 3) {
                return 0;
            }
            break;
        case 1:
            if (func_ov000_021a629c((Unk021a5a78 *) data_ov003_021d8bd8,
                                    (void (*)(Unk021a586c *)) func_ov003_021bea3c) != 3) {
                return 0;
            }
            break;
        case 0:
        case 2:
        case 3:
        case 4:
        case 6:
        case 8:
        default:
            return 0;
    }
    return 1;
}

s32 func_ov003_021be96c(u8 *param_0, s32 param_1) {
    s32 a;
    s32 i;

    func_ov000_021a67dc(1);
    a = func_ov000_021a6844();
    if (a > 0) {
        i = 0;
        if (a > 0) {
            do {
                if (i >= param_1) {
                    break;
                }
                MemCopyWords(func_ov000_021a6788(i), param_0, 0xc0);
                i++;
                param_0 += 0xc0;
            } while (i < a);
        }
    }
    func_ov000_021a67dc(0);
    return a;
}

u32 func_ov003_021be860(u8 *param_0, u8 *param_1, s32 param_2, u32 param_3) {
    u32 a = IrqDisable();
    u8 *b;
    s32 i;

    data_ov003_021d8c30 = param_3;
    b = data_ov003_021d8c64;
    data_ov003_021d8c14 = b;
    if (param_0 != NULL) {
        for (i = 0; i < 6; i++) {
            *b++ = *param_0++;
        }
    } else {
        MemFill(b, 0xff, 6);
        data_ov003_021d8c14 = data_usa_ov000_021b0788;
    }
    b = data_ov003_021d8cc4;
    data_ov003_021d8c18 = b;
    if (param_1 != NULL && param_2 > 0 && param_2 < 0x20) {
        i = 0;
        if (param_2 > 0) {
            do {
                *b++ = *param_1++;
                i++;
            } while (i < param_2);
        }
        if (i < 0x20) {
            b = data_ov003_021d8cc4 + i;
            do {
                *b++ = 0;
                i++;
            } while (i < 0x20);
        }
    } else {
        MemFill(data_ov003_021d8cc4, 0xff, 0x20);
        data_ov003_021d8c18 = data_usa_ov000_021b0790;
    }
    if (data_ov003_021d8bfc == 3) {
        if (func_ov000_021a61c4(data_ov003_021d8c64, data_ov003_021d8c18, data_ov003_021d8c30) == 3) {
            data_ov003_021d8bfc = 6;
            IrqRestore(a);
            return 1;
        }
    } else if (func_ov003_021be9b8() == 1) {
        data_ov003_021d8bfc = 6;
        IrqRestore(a);
        return 1;
    }
    IrqRestore(a);
    return 0;
}

u32 func_ov003_021be820(void) {
    u32 a = IrqDisable();

    if (data_ov003_021d8bfc == 7) {
        if (func_ov000_021a5db0() == 3) {
            data_ov003_021d8bfc = 4;
            IrqRestore(a);
            return 1;
        }
    }
    IrqRestore(a);
    return 0;
}

u32 func_ov003_021be7b8(void) {
    u32 a = IrqDisable();

    if (data_ov003_021d8bfc == 3) {
        if (func_ov000_021a61e4() != 3) {
            IrqRestore(a);
            return 0;
        }
        data_ov003_021d8bfc = 2;
        IrqRestore(a);
        return 1;
    }
    if (func_ov003_021be9b8() == 1) {
        data_ov003_021d8bfc = 2;
        IrqRestore(a);
        return 1;
    }
    IrqRestore(a);
    return 0;
}

u32 func_ov003_021be708(void *param_0, void *param_1, u32 param_2) {
    u32 a = IrqDisable();

    data_ov003_021d8c28 = param_2;
    if (param_1 != NULL) {
        MemCopy(param_1, data_ov003_021d8bf8, 0x60);
    } else {
        MemFill(data_ov003_021d8bf8, 0, 0x60);
    }
    MemCopyWords(param_0, data_ov003_021d8c1c, 0xc0);
    if (func_ov003_021be9b8() == 1) {
        data_ov003_021d8bfc = 8;
        IrqRestore(a);
        return 1;
    }
    if (data_ov003_021d8bfc == 3) {
        if (func_ov000_021a5e84((Unk021a5e84 *) data_ov003_021d8c1c, (Unk02188de4 *) data_ov003_021d8bf8,
                                data_ov003_021d8c28) == 3) {
            data_ov003_021d8bfc = 8;
            IrqRestore(a);
            return 1;
        }
    }
    IrqRestore(a);
    return 0;
}

u32 func_ov003_021be610(void (*param_0)(u32, u32), void *param_1, u32 param_2) {
    u32 a = IrqDisable();
    Unk021d8bd8 *b;
    u32 c;

    data_ov003_021d8bf8 = param_1;
    b = (Unk021d8bd8 *) (((u32) param_1 + 0x63) & ~3);
    data_ov003_021d8bd8 = b;
    c = ((u32) b + 0x2f) & ~0x1f;
    data_ov003_021d8c0c = (void *) c;
    c = (c + 0x231f) & ~0x1f;
    data_ov003_021d8c1c = (u8 *) c;
    c = (c + 0xdf) & ~0x1f;
    b->mUnk_04 = (void *) c;
    data_ov003_021d8bd8->mUnk_08 = (u32) param_1 + param_2 - (u32) data_ov003_021d8bd8->mUnk_04;
    data_ov003_021d8bd8->mUnk_0c = 0;
    data_ov003_021d8bd8->mUnk_00 = 3;
    data_ov003_021d8c50 = (UnkFunc *) param_0;
    if (data_ov003_021d8bfc == 0) {
        if (func_ov000_021a6470(data_ov003_021d8c0c, 0x2300) != 0) {
            IrqRestore(a);
            return 0;
        }
        data_ov003_021d8bfc = 1;
    }
    if (data_ov003_021d8bfc == 1) {
        if (func_ov000_021a629c((Unk021a5a78 *) data_ov003_021d8bd8, (void (*)(Unk021a586c *)) func_ov003_021bea3c) !=
            3) {
            IrqRestore(a);
            return 0;
        }
        data_ov003_021d8bfc = 4;
        IrqRestore(a);
        return 1;
    }
    IrqRestore(a);
    return 0;
}
