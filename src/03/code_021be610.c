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
#include "00/unk_021b0000.h"

void ReleaseSlideButtons(u32 task) {
    SlideButtons *slideButtons;
    s32 i;

    func_ov003_021d34c8(0, task);
    slideButtons = data_ov003_021da108;
    if (slideButtons->mResetTask != 0) {
        func_ov003_021d34c8(0, slideButtons->mResetTask);
    }
    for (i = 0; i < 2; i++) {
        if (data_ov003_021da108->mButtons[i] != 0) {
            func_ov003_021d197c(data_ov003_021da108->mButtons[i]);
        }
    }
    func_ov003_021d197c(data_ov003_021da108->mUnk_08);
    func_ov003_021d2808(&data_ov003_021da108);
}

void AdvanceButtonReset(u32 task) {
    SlideButtons *slideButtons;
    s32 i;
    s32 buttonCount;
    u32 imageIndex;
    u32 c;
    u32 d;

    slideButtons = data_ov003_021da108;
    slideButtons->mStepFrames = slideButtons->mStepFrames + 1;
    if (data_ov003_021da108->mStepFrames >= 0x10) {
        slideButtons = data_ov003_021da108;
        buttonCount = data_ov003_021d5ecc[slideButtons->mKind];
        for (i = 0; i < buttonCount; i++) {
            slideButtons = data_ov003_021da108;
            imageIndex = (data_ov003_021d5edc + slideButtons->mKind * 2)[i];
            func_ov003_021d1c3c(0, imageIndex, func_ov003_021d1974(slideButtons->mButtons[i], 0));
            func_ov003_021d1790(data_ov003_021da108->mButtons[i], -1, 1);
        }
        SetSlideButtonsY(data_ov003_021d5ec4[1]);
        data_ov003_021da108->mStepFrames = 0;
        data_ov003_021da108->mButtonResult = -1;
        slideButtons = data_ov003_021da108;
        if (slideButtons->mResetTask != 0) {
            slideButtons->mResetTask = 0;
            func_ov003_021d34c8(0, task);
        }
    }
}

void func_ov003_021beef8(int index) {
    Unk021da104 *object;
    Unk021da104_04 *innerObject;
    u32 c;

    object = func_ov003_021d283c(0xc, 4);
    data_ov003_021da104 = object;
    object->mUnk_08 = index;
    data_ov003_021da104->mUnk_04 = func_ov003_021d1c18(0, 0x47);
    innerObject = data_ov003_021da104->mUnk_04;
    innerObject->mUnk_04 = (innerObject->mUnk_04 & 0xfffff3ff) | 0x400;
    innerObject = data_ov003_021da104->mUnk_04;
    innerObject->mUnk_00 = innerObject->mUnk_00 & 0xfffff3ff;
    innerObject->mUnk_04 = (innerObject->mUnk_04 & 0xffff0fff) | (data_ov003_021d5ebc[index] << 12);
    innerObject = data_ov003_021da104->mUnk_04;
    innerObject->mUnk_00 = ((data_ov003_021d5ec0[0] & 0x1ff) << 16) |
                           ((innerObject->mUnk_00 & 0xfe00ff00) | (data_ov003_021d5ec0[1] & 0xff));
    data_ov003_021da104->mUnk_00 = func_ov003_021d3544(1, func_ov003_021bee24, NULL, 0x78);
}

void func_ov003_021beecc(void) {
    func_ov003_021d34c0(1, data_ov003_021da104->mUnk_00);
    func_ov003_021d2f00((u32 *) data_ov003_021da104->mUnk_04);
    func_ov003_021d2808(&data_ov003_021da104);
}

void func_ov003_021bee24(void) {
    Unk021da104 *object;
    Unk021da104_04 *innerObject;
    u32 c;

    data_ov003_021da104->mUnk_09 = FX_ModS32(data_ov003_021da104->mUnk_09 + 1, 0x28);
    c = FX_DivS32(data_ov003_021da104->mUnk_09, 5) + 0x47;
    func_ov003_021d1c3c(0, c, (u8 *) data_ov003_021da104->mUnk_04);
    innerObject = data_ov003_021da104->mUnk_04;
    innerObject->mUnk_04 = (innerObject->mUnk_04 & 0xfffff3ff) | 0x400;
    object = data_ov003_021da104;
    c = data_ov003_021d5ebc[object->mUnk_08];
    innerObject = object->mUnk_04;
    innerObject->mUnk_00 = innerObject->mUnk_00 & 0xfffff3ff;
    innerObject->mUnk_04 = (innerObject->mUnk_04 & 0xffff0fff) | (c << 12);
    innerObject = data_ov003_021da104->mUnk_04;
    innerObject->mUnk_00 = ((data_ov003_021d5ec0[0] & 0x1ff) << 16) |
                           ((innerObject->mUnk_00 & 0xfe00ff00) | (data_ov003_021d5ec0[1] & 0xff));
}

void func_ov003_021bea3c(Unk021bea3c *message) {
    if (message == NULL) {
        return;
    }
    switch (message->mUnk_00) {
        case 1:
            if (message->mUnk_02 == 0) {
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
                    if (func_ov000_021a5e84(data_ov003_021d8c1c, data_ov003_021d8bf8, data_ov003_021d8c28) == 3) {
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
            if (message->mUnk_02 == 0) {
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
            if (message->mUnk_02 == 0) {
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
            if (message->mUnk_02 == 0) {
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
                    if (func_ov000_021a5e84(data_ov003_021d8c1c, data_ov003_021d8bf8, data_ov003_021d8c28) == 3) {
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
            if (message->mUnk_02 == 0) {
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
                    if (func_ov000_021a5e84(data_ov003_021d8c1c, data_ov003_021d8bf8, data_ov003_021d8c28) == 3) {
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
            if (message->mUnk_02 == 0) {
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

BOOL func_ov003_021be9b8(void) {
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
            if (func_ov000_021a629c(data_ov003_021d8bd8, (void (*)(Unk021a586c *)) func_ov003_021bea3c) != 3) {
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

s32 func_ov003_021be96c(u8 *output, s32 maxCount) {
    s32 count;
    s32 i;

    func_ov000_021a67dc(1);
    count = func_ov000_021a6844();
    if (count > 0) {
        i = 0;
        if (count > 0) {
            do {
                if (i >= maxCount) {
                    break;
                }
                MIi_CpuCopy32(func_ov000_021a6788(i), output, 0xc0);
                i++;
                output += 0xc0;
            } while (i < count);
        }
    }
    func_ov000_021a67dc(0);
    return count;
}

BOOL func_ov003_021be860(u8 *address, u8 *name, s32 nameLength, u32 param_3) {
    u32 savedInterrupts = OS_DisableInterrupts();
    u8 *cursor;
    s32 i;

    data_ov003_021d8c30 = param_3;
    cursor = data_ov003_021d8c64;
    data_ov003_021d8c14 = cursor;
    if (address != NULL) {
        for (i = 0; i < 6; i++) {
            *cursor++ = *address++;
        }
    } else {
        MI_CpuFill8(cursor, 0xff, 6);
        data_ov003_021d8c14 = data_ov000_021b07bc;
    }
    cursor = data_ov003_021d8cc4;
    data_ov003_021d8c18 = cursor;
    if (name != NULL && nameLength > 0 && nameLength < 0x20) {
        i = 0;
        if (nameLength > 0) {
            do {
                *cursor++ = *name++;
                i++;
            } while (i < nameLength);
        }
        if (i < 0x20) {
            cursor = data_ov003_021d8cc4 + i;
            do {
                *cursor++ = 0;
                i++;
            } while (i < 0x20);
        }
    } else {
        MI_CpuFill8(data_ov003_021d8cc4, 0xff, 0x20);
        data_ov003_021d8c18 = data_ov000_021b07c4;
    }
    if (data_ov003_021d8bfc == 3) {
        if (func_ov000_021a61c4(data_ov003_021d8c64, data_ov003_021d8c18, data_ov003_021d8c30) == 3) {
            data_ov003_021d8bfc = 6;
            OS_RestoreInterrupts(savedInterrupts);
            return 1;
        }
    } else if (func_ov003_021be9b8() == 1) {
        data_ov003_021d8bfc = 6;
        OS_RestoreInterrupts(savedInterrupts);
        return 1;
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}

BOOL func_ov003_021be820(void) {
    u32 savedInterrupts = OS_DisableInterrupts();

    if (data_ov003_021d8bfc == 7) {
        if (func_ov000_021a5db0() == 3) {
            data_ov003_021d8bfc = 4;
            OS_RestoreInterrupts(savedInterrupts);
            return 1;
        }
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}

BOOL func_ov003_021be7b8(void) {
    u32 savedInterrupts = OS_DisableInterrupts();

    if (data_ov003_021d8bfc == 3) {
        if (func_ov000_021a61e4() != 3) {
            OS_RestoreInterrupts(savedInterrupts);
            return 0;
        }
        data_ov003_021d8bfc = 2;
        OS_RestoreInterrupts(savedInterrupts);
        return 1;
    }
    if (func_ov003_021be9b8() == 1) {
        data_ov003_021d8bfc = 2;
        OS_RestoreInterrupts(savedInterrupts);
        return 1;
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}

BOOL func_ov003_021be708(void *entry, void *optionalBytes, u32 param_2) {
    u32 savedInterrupts = OS_DisableInterrupts();

    data_ov003_021d8c28 = param_2;
    if (optionalBytes != NULL) {
        MI_CpuCopy8(optionalBytes, data_ov003_021d8bf8, 0x60);
    } else {
        MI_CpuFill8(data_ov003_021d8bf8, 0, 0x60);
    }
    MIi_CpuCopy32(entry, data_ov003_021d8c1c, 0xc0);
    if (func_ov003_021be9b8() == 1) {
        data_ov003_021d8bfc = 8;
        OS_RestoreInterrupts(savedInterrupts);
        return 1;
    }
    if (data_ov003_021d8bfc == 3) {
        if (func_ov000_021a5e84(data_ov003_021d8c1c, data_ov003_021d8bf8, data_ov003_021d8c28) == 3) {
            data_ov003_021d8bfc = 8;
            OS_RestoreInterrupts(savedInterrupts);
            return 1;
        }
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}

BOOL func_ov003_021be610(void (*callback)(u32, u32), void *buffer, u32 size) {
    u32 savedInterrupts = OS_DisableInterrupts();
    Unk021a5a78 *alignedBlock;
    u32 cursor;

    data_ov003_021d8bf8 = buffer;
    alignedBlock = (Unk021a5a78 *) (((u32) buffer + 0x63) & ~3);
    data_ov003_021d8bd8 = alignedBlock;
    cursor = ((u32) alignedBlock + 0x2f) & ~0x1f;
    data_ov003_021d8c0c = (void *) cursor;
    cursor = (cursor + 0x231f) & ~0x1f;
    data_ov003_021d8c1c = (Unk021a5e84 *) cursor;
    cursor = (cursor + 0xdf) & ~0x1f;
    alignedBlock->mUnk_04 = (u8 *) cursor;
    data_ov003_021d8bd8->mUnk_08 = (u32) buffer + size - (u32) data_ov003_021d8bd8->mUnk_04;
    data_ov003_021d8bd8->mUnk_0c = 0;
    data_ov003_021d8bd8->mUnk_00 = 3;
    data_ov003_021d8c50 = (UnkFunc *) callback;
    if (data_ov003_021d8bfc == 0) {
        if (func_ov000_021a6470(data_ov003_021d8c0c, 0x2300) != 0) {
            OS_RestoreInterrupts(savedInterrupts);
            return 0;
        }
        data_ov003_021d8bfc = 1;
    }
    if (data_ov003_021d8bfc == 1) {
        if (func_ov000_021a629c(data_ov003_021d8bd8, (void (*)(Unk021a586c *)) func_ov003_021bea3c) != 3) {
            OS_RestoreInterrupts(savedInterrupts);
            return 0;
        }
        data_ov003_021d8bfc = 4;
        OS_RestoreInterrupts(savedInterrupts);
        return 1;
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}
