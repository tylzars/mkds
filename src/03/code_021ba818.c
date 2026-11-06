#include "03/code_021ba818.h"
#include "00/code_021a5db0.h"
#include "00/code_021a5e84.h"
#include "00/code_021a61c4.h"
#include "00/code_021a61e4.h"
#include "00/code_021a629c.h"
#include "00/code_021a6428.h"
#include "00/code_021a6470.h"
#include "00/code_021a669c.h"
#include "00/code_021a6788.h"
#include "00/code_021a67dc.h"
#include "00/code_021a6844.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "00/unk_021b0000.h"

void func_ov003_021bac90(s16 *a) {
    if (a == NULL) {
        return;
    }
    switch (a[0]) {
        case 1:
            if (a[1] == 0) {
                if (data_ov003_021d8b98 == 4) {
                    data_ov003_021d8b98 = 3;
                    if (data_ov003_021d8b9c != NULL) {
                        data_ov003_021d8b9c(6, 0);
                    }
                } else if (data_ov003_021d8b98 == 6) {
                    if (func_ov000_021a61c4(data_ov003_021d8b90, data_ov003_021d8b94, data_ov003_021d8b84) != 3) {
                        data_ov003_021d8b98 = 3;
                        if (data_ov003_021d8b9c != NULL) {
                            data_ov003_021d8b9c(2, 0);
                        }
                    }
                } else if (data_ov003_021d8b98 == 8) {
                    if (func_ov000_021a5e84((Unk021a5e84 *) data_ov003_021d8ba0, data_ov003_021d8ba4,
                                            data_ov003_021d8b8c) != 3) {
                        data_ov003_021d8b98 = 3;
                        if (data_ov003_021d8b9c != NULL) {
                            data_ov003_021d8b9c(2, 0);
                        }
                    }
                }
            } else {
                data_ov003_021d8b98 = 1;
                if (data_ov003_021d8b9c != NULL) {
                    data_ov003_021d8b9c(2, 0);
                }
            }
            break;
        case 3:
            if (a[1] == 0) {
                if (data_ov003_021d8b98 == 6) {
                    data_ov003_021d8b98 = 5;
                    if (data_ov003_021d8b9c != NULL) {
                        data_ov003_021d8b9c(8, 0);
                    }
                }
            } else {
                data_ov003_021d8b98 = 3;
                if (data_ov003_021d8b9c != NULL) {
                    data_ov003_021d8b9c(9, 0);
                }
            }
            break;
        case 5:
            if (a[1] == 0) {
                if (data_ov003_021d8b98 == 8) {
                    data_ov003_021d8b98 = 7;
                    if (data_ov003_021d8b9c != NULL) {
                        data_ov003_021d8b9c(0xc, 0);
                    }
                }
            } else {
                data_ov003_021d8b98 = 3;
                if (data_ov003_021d8b9c != NULL) {
                    data_ov003_021d8b9c(0xd, 0);
                }
            }
            break;
        case 4:
            if (a[1] == 0) {
                if (data_ov003_021d8b98 == 4) {
                    data_ov003_021d8b98 = 3;
                    if (data_ov003_021d8b9c != NULL) {
                        data_ov003_021d8b9c(0xa, 0);
                    }
                } else if (data_ov003_021d8b98 == 6) {
                    if (func_ov000_021a61c4(data_ov003_021d8b90, data_ov003_021d8b94, data_ov003_021d8b84) != 3) {
                        data_ov003_021d8b98 = 3;
                        if (data_ov003_021d8b9c != NULL) {
                            data_ov003_021d8b9c(2, 0);
                        }
                    }
                } else if (data_ov003_021d8b98 == 2) {
                    if (func_ov000_021a61e4() != 3) {
                        data_ov003_021d8b98 = 3;
                        if (data_ov003_021d8b9c != NULL) {
                            data_ov003_021d8b9c(2, 0);
                        }
                    }
                } else if (data_ov003_021d8b98 == 8) {
                    if (func_ov000_021a5e84((Unk021a5e84 *) data_ov003_021d8ba0, data_ov003_021d8ba4,
                                            data_ov003_021d8b8c) != 3) {
                        data_ov003_021d8b98 = 3;
                        if (data_ov003_021d8b9c != NULL) {
                            data_ov003_021d8b9c(2, 0);
                        }
                    }
                }
            } else {
                data_ov003_021d8b98 = 3;
                if (data_ov003_021d8b9c != NULL) {
                    data_ov003_021d8b9c(0xb, 0);
                }
            }
            break;
        case 6:
            if (a[1] == 0) {
                if (data_ov003_021d8b98 == 4) {
                    data_ov003_021d8b98 = 3;
                    if (data_ov003_021d8b9c != NULL) {
                        data_ov003_021d8b9c(0xe, 0);
                    }
                } else if (data_ov003_021d8b98 == 6) {
                    if (func_ov000_021a61c4(data_ov003_021d8b90, data_ov003_021d8b94, data_ov003_021d8b84) != 3) {
                        data_ov003_021d8b98 = 3;
                        if (data_ov003_021d8b9c != NULL) {
                            data_ov003_021d8b9c(2, 0);
                        }
                    }
                } else if (data_ov003_021d8b98 == 2) {
                    if (func_ov000_021a61e4() != 3) {
                        data_ov003_021d8b98 = 3;
                        if (data_ov003_021d8b9c != NULL) {
                            data_ov003_021d8b9c(2, 0);
                        }
                    }
                } else if (data_ov003_021d8b98 == 8) {
                    if (func_ov000_021a5e84((Unk021a5e84 *) data_ov003_021d8ba0, data_ov003_021d8ba4,
                                            data_ov003_021d8b8c) != 3) {
                        data_ov003_021d8b98 = 3;
                        if (data_ov003_021d8b9c != NULL) {
                            data_ov003_021d8b9c(2, 0);
                        }
                    }
                } else {
                    data_ov003_021d8b98 = 3;
                }
            } else {
                data_ov003_021d8b98 = 3;
                if (data_ov003_021d8b9c != NULL) {
                    data_ov003_021d8b9c(0xf, 0);
                }
            }
            break;
        case 2:
            if (a[1] == 0) {
                if (data_ov003_021d8b98 == 2) {
                    func_ov000_021a6428();
                    data_ov003_021d8b98 = 0;
                    if (data_ov003_021d8b9c != NULL) {
                        data_ov003_021d8b9c(0x14, 0);
                    }
                }
            } else {
                data_ov003_021d8b98 = 3;
                if (data_ov003_021d8b9c != NULL) {
                    data_ov003_021d8b9c(2, 0);
                }
            }
            break;
        case 7:
            if (data_ov003_021d8b98 == 5) {
                if (data_ov003_021d8b9c != NULL) {
                    data_ov003_021d8b9c(5, 0);
                }
            }
            break;
        default:
            if (data_ov003_021d8b9c != NULL) {
                data_ov003_021d8b9c(1, 0);
            }
            break;
    }
}

BOOL func_ov003_021bac0c(void) {
    switch (data_ov003_021d8b98) {
        case 5:
            if (func_ov000_021a61c4(NULL, NULL, 0) != 3) {
                return FALSE;
            }
            break;
        case 7:
            if (func_ov000_021a5db0() != 3) {
                return FALSE;
            }
            break;
        case 1:
            if (func_ov000_021a629c((Unk021a5a78 *) data_ov003_021d8b88,
                                    (void (*)(Unk021a586c *)) func_ov003_021bac90) != 3) {
                return FALSE;
            }
            break;
        case 0:
        case 2:
        case 3:
        case 4:
        case 6:
        case 8:
        default:
            return FALSE;
    }
    return TRUE;
}

s32 func_ov003_021babc0(Unk021ba778Src *a, s32 b) {
    s32 n;
    s32 i;
    func_ov000_021a67dc(1);
    n = func_ov000_021a6844();
    if (n > 0) {
        for (i = 0; i < n; i++, a++) {
            if (i >= b) {
                break;
            }
            MIi_CpuCopy32(func_ov000_021a6788(i), a, 0xc0);
        }
    }
    func_ov000_021a67dc(0);
    return n;
}

BOOL func_ov003_021baaac(const u8 *a, const u8 *b, s32 c, u32 d) {
    u32 v1 = OS_DisableInterrupts();
    s32 i;
    data_ov003_021d8b84 = d;
    if (a != NULL) {
        for (i = 0; i < 6; i++) {
            data_ov003_021d8ba8[i] = *a++;
        }
        data_ov003_021d8b90 = data_ov003_021d8ba8;
    } else {
        MI_CpuFill8(data_ov003_021d8ba8, 0xff, 6);
        data_ov003_021d8b90 = data_ov000_021b07bc;
    }
    if (b != NULL && c > 0 && c <= 0x20) {
        for (i = 0; i < c; i++) {
            data_ov003_021d8bb0[i] = *b++;
        }
        for (; i < 0x20; i++) {
            data_ov003_021d8bb0[i] = 0;
        }
        data_ov003_021d8b94 = data_ov003_021d8bb0;
    } else {
        MI_CpuFill8(data_ov003_021d8bb0, 0xff, 0x20);
        data_ov003_021d8b94 = data_ov000_021b07c4;
    }
    if (data_ov003_021d8b98 == 3) {
        if (func_ov000_021a61c4(data_ov003_021d8b90, data_ov003_021d8b94, data_ov003_021d8b84) == 3) {
            data_ov003_021d8b98 = 6;
            OS_RestoreInterrupts(v1);
            return TRUE;
        }
    } else if (func_ov003_021bac0c() == TRUE) {
        data_ov003_021d8b98 = 6;
        OS_RestoreInterrupts(v1);
        return TRUE;
    }
    OS_RestoreInterrupts(v1);
    return FALSE;
}

BOOL func_ov003_021baa68(void) {
    u32 v1 = OS_DisableInterrupts();
    if (data_ov003_021d8b98 == 5) {
        if (func_ov000_021a61c4(NULL, NULL, 0) == 3) {
            data_ov003_021d8b98 = 4;
            OS_RestoreInterrupts(v1);
            return TRUE;
        }
    }
    OS_RestoreInterrupts(v1);
    return FALSE;
}

BOOL func_ov003_021baa28(void) {
    u32 v1 = OS_DisableInterrupts();
    if (data_ov003_021d8b98 == 7) {
        if (func_ov000_021a5db0() == 3) {
            data_ov003_021d8b98 = 4;
            OS_RestoreInterrupts(v1);
            return TRUE;
        }
    }
    OS_RestoreInterrupts(v1);
    return FALSE;
}

BOOL func_ov003_021ba9c0(void) {
    u32 v1 = OS_DisableInterrupts();
    if (data_ov003_021d8b98 == 3) {
        if (func_ov000_021a61e4() != 3) {
            OS_RestoreInterrupts(v1);
            return FALSE;
        }
        data_ov003_021d8b98 = 2;
        OS_RestoreInterrupts(v1);
        return TRUE;
    }
    if (func_ov003_021bac0c() == TRUE) {
        data_ov003_021d8b98 = 2;
        OS_RestoreInterrupts(v1);
        return TRUE;
    }
    OS_RestoreInterrupts(v1);
    return FALSE;
}

BOOL func_ov003_021ba910(Unk021ba778Src *a, Unk021d8a4c *b, u32 c) {
    u32 v1 = OS_DisableInterrupts();
    data_ov003_021d8b8c = c;
    if (b != NULL) {
        MI_CpuCopy8(b, data_ov003_021d8ba4, 0x50);
    } else {
        MI_CpuFill8(data_ov003_021d8ba4, 0, 0x50);
    }
    MIi_CpuCopy32(a, data_ov003_021d8ba0, 0xc0);
    if (func_ov003_021bac0c() == TRUE) {
        data_ov003_021d8b98 = 8;
        OS_RestoreInterrupts(v1);
        return TRUE;
    }
    if (data_ov003_021d8b98 == 3) {
        if (func_ov000_021a5e84((Unk021a5e84 *) data_ov003_021d8ba0, data_ov003_021d8ba4, data_ov003_021d8b8c) == 3) {
            data_ov003_021d8b98 = 8;
            OS_RestoreInterrupts(v1);
            return TRUE;
        }
    }
    OS_RestoreInterrupts(v1);
    return FALSE;
}

BOOL func_ov003_021ba818(Unk021ba818Func *a, u8 *b, s32 c) {
    u32 v1 = OS_DisableInterrupts();
    data_ov003_021d8ba4 = b;
    data_ov003_021d8b88 = (Unk021d8b88 *) (((u32) b + 0x53) & ~3);
    data_ov003_021d8b80 = (u8 *) (((u32) data_ov003_021d8b88 + 0x2f) & ~0x1f);
    data_ov003_021d8ba0 = (Unk021ba778Src *) (((u32) data_ov003_021d8b80 + 0x231f) & ~0x1f);
    data_ov003_021d8b88->mUnk_04 = (u8 *) (((u32) data_ov003_021d8ba0 + 0xdf) & ~0x1f);
    data_ov003_021d8b88->mUnk_08 = (b + c) - data_ov003_021d8b88->mUnk_04;
    data_ov003_021d8b88->mUnk_0c = 0;
    data_ov003_021d8b88->mUnk_00 = 3;
    data_ov003_021d8b9c = a;
    if (data_ov003_021d8b98 == 0) {
        if (func_ov000_021a6470((Unk021b5f50 *) data_ov003_021d8b80, 0x2300) != 0) {
            OS_RestoreInterrupts(v1);
            return FALSE;
        }
        data_ov003_021d8b98 = 1;
    }
    if (data_ov003_021d8b98 == 1) {
        if (func_ov000_021a629c((Unk021a5a78 *) data_ov003_021d8b88, (void (*)(Unk021a586c *)) func_ov003_021bac90) !=
            3) {
            OS_RestoreInterrupts(v1);
            return FALSE;
        }
        data_ov003_021d8b98 = 4;
        OS_RestoreInterrupts(v1);
        return TRUE;
    }
    OS_RestoreInterrupts(v1);
    return FALSE;
}
