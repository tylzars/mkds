#include "code_0214259c.h"

#include "code_0200eddc.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200fc8c.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"
#include "Main/Unknown/unk_0217e000.h"
#include "code_02142eac.h"
#include "code_0200e77c.h"
#include "code_0214c778.h"
#include "code_0214d5b8.h"

u16 data_0217eed0;
struct Unk02142aa8 *data_0217eed4;
OSMessageQueue data_0217eed8;
void *data_0217eef8[10];

s32 WM_Init(void *buf, u32 n) {
    s32 r;

    r = InitWorkBufferWithSize(buf, n, 0xf00);
    if (r == 0) {
        data_0217eed4->mUnk_016 = 0;
    }
    return r;
}

s32 InitWorkBufferWithSize(void *buf, u32 n, u32 size) {
    s32 i;
    s32 j;

    if (data_0217eed0 != 0) {
        return 3;
    }
    data_0217eed0 = 1;
    if (buf == 0) {
        data_0217eed0 = 0;
        return 6;
    }
    if (n > 3) {
        data_0217eed0 = 0;
        return 6;
    }
    if (((u32) buf & 0x1f) != 0) {
        data_0217eed0 = 0;
        return 6;
    }
    PxiInit();
    if (PxiCallbackBitIsSet(0xa, 1) == 0) {
        data_0217eed0 = 0;
        return 4;
    }
    DC_InvalidateRange(buf, size);
    MI_DmaFill32(n, buf, 0, size);
    data_0217eed4 = buf;
    data_0217eed4->mUnk_000 = (u8 *) buf + 0x200;
    data_0217eed4->mStatusArea = (Unk02142988 *) ((u8 *) data_0217eed4->mUnk_000 + 0x300);
    data_0217eed4->mRequestArea = (u16 *) ((u8 *) data_0217eed4->mStatusArea + 0x800);
    data_0217eed4->mMessageArea = (Unk021425e8 *) ((u8 *) data_0217eed4->mRequestArea + 0x100);
    func_021425cc();
    data_0217eed4->mUnk_014 = n;
    for (i = 0; i < 16; i++) {
        WM_SetPortCallback((u16) i, 0, 0);
    }
    OS_InitMessageQueue(&data_0217eed8, data_0217eef8, 10);
    for (j = 0; j < 10; j++) {
        *(u16 *) data_0217ef60[j] = 0x8000;
        DC_StoreRange(data_0217ef60[j], 2);
        OS_SendMessage(&data_0217eed8, data_0217ef60[j], 1);
    }
    PxiCallbackSet(0xa, ReceiveCommandReply);
    return 0;
}

s32 WM_Finish(void) {
    s32 r;

    if (GetErrorUnlessInitialized() != 0) {
        return 3;
    }
    r = GetErrorUnlessStateIsOneOf(1, 0);
    if (r != 0) {
        return r;
    }
    func_021425cc();
    PxiCallbackSet(0xa, 0);
    data_0217eed4 = 0;
    data_0217eed0 = 0;
    return 0;
}

u32 SetCommandCallback(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (u32) &data_0217eed4;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value0 = (value2) + ((value0 << 2));
    *(u32 *) ((value0) + (24)) = value1;
    return value0;
}

s32 SendCommandMessage(u32 a, u16 b, ...) {
    void *p;
    u32 *ap;
    s32 i;
    s32 r;

    if (OS_ReceiveMessage(&data_0217eed8, &p, 0) == 0) {
        return 8;
    }
    DC_InvalidateRange(p, 2);
    if ((*(u16 *) p & 0x8000) == 0) {
        OS_JamMessage(&data_0217eed8, p, 1);
        return 8;
    }
    if (b == 0) {
        DC_StoreRange(data_0217eed4->mRequestArea, 0x100);
        DC_InvalidateRange(p, 0x100);
        MI_DmaCopy32(data_0217eed4->mUnk_014, data_0217eed4->mRequestArea, p, 0x100);
    }
    *(u16 *) p = a;
    ap = (u32 *) (((u32) &b & ~3) + 4);
    for (i = 0; i < b; i++) {
        ap++;
        ((u32 *) ((u8 *) p + 4))[i] = ap[-1];
    }
    DC_StoreRange(p, 0x100);
    r = PxiSendFifoWord(0xa, (u32) p, 0);
    OS_SendMessage(&data_0217eed8, p, 1);
    if (r < 0) {
        return 8;
    }
    return 2;
}

Unk02142aa8 *GetWorkBuffer(void) {
    u32 value0;
    value0 = (u32) &data_0217eed4;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    return (Unk02142aa8 *) value0;
}

s32 GetErrorUnlessInitialized(void) {
    if (data_0217eed0 != 0) {
        return 0;
    }
    return 3;
}

s32 GetErrorUnlessStateAtLeast2(void) {
    s32 r;

    r = GetErrorUnlessInitialized();
    if (r != 0) {
        return r;
    }
    DC_InvalidateRange(data_0217eed4->mStatusArea, 2);
    if (data_0217eed4->mStatusArea->mState <= 1) {
        return 3;
    }
    return 0;
}

s32 GetErrorUnlessStateIsOneOf(s32 n, ...) {
    u32 *ap;
    u16 v;
    s32 r;

    r = GetErrorUnlessInitialized();
    if (r != 0) {
        return r;
    }
    DC_InvalidateRange(data_0217eed4->mStatusArea, 2);
    v = data_0217eed4->mStatusArea->mState;
    ap = (u32 *) (((u32) &n & ~3) + 4);
    r = 3;
    while (n != 0) {
        ap++;
        if (ap[-1] == v) {
            r = 0;
        }
        n--;
    }
    return r;
}

void ReceiveCommandReply(u32 a, Unk021425e8 *m, s32 c) {
    Unk021425e8Func cb;
    u16 t;
    u16 k;
    u16 v7;
    u16 v6;
    u8 *p5;
    u8 *p4;
    u16 i;
    volatile u16 z;

    if (c != 0) {
        return;
    }
    DC_InvalidateRange(data_0217eed4->mMessageArea, 0x100);
    if (data_0217eed4->mUnk_016 == 0) {
        DC_InvalidateRange(data_0217eed4->mStatusArea, 0x800);
    }
    if (m != data_0217eed4->mMessageArea) {
        DC_InvalidateRange(m, 0x100);
    }
    if (m->mCommand >= 0x2a) {
        if (m->mCommand == 0x80) {
            if (m->mResultCode == 0x13) {
                IrqDisableLoopForever();
            }
            cb = data_0217eed4->mIndicationCallback;
            if (cb != 0) {
                cb(m);
            }
        } else if (m->mCommand == 0x82) {
            if (data_0217eed4->mPortCallbacks[m->mUnk_06] != 0) {
                m->mUnk_1c = data_0217eed4->mPortCallbackArgs[m->mUnk_06];
                DC_InvalidateRange(m->mUnk_08, data_0217eed4->mStatusArea->mUnk_046);
                data_0217eed4->mPortCallbacks[m->mUnk_06](m);
            }
        } else if (m->mCommand == 0x81) {
            m->mCommand = 0xf;
            cb = m->mUnk_1c;
            if (cb != 0) {
                cb(m);
            }
        }
    } else {
        if (m->mCommand == 0xe) {
            if ((u16) (m->mUnk_04 + 0xfff5) <= 1) {
                if (m->mResultCode == 0) {
                    DC_InvalidateRange(m->mUnk_08, data_0217eed4->mStatusArea->mUnk_046);
                }
            }
        }
        if (m->mCommand == 2 && m->mResultCode == 0) {
            cb = data_0217eed4->mCommandCallbacks[m->mCommand];
            WM_Finish();
            if (cb == 0) {
                return;
            }
            cb(m);
            return;
        }
        cb = data_0217eed4->mCommandCallbacks[m->mCommand];
        if (cb != 0) {
            cb(m);
            if (data_0217eed0 == 0) {
                return;
            }
        }
        t = m->mCommand;
        if (t == 8 || t == 0xc) {
            if (t == 8) {
                p5 = (u8 *) m + 0xa;
                p4 = (u8 *) m + 0x14;
                k = *(u16 *) &m->mUnk_08;
                v7 = m->mUnk_10;
                v6 = 0;
            } else if (t == 0xc) {
                v7 = 0;
                k = *(u16 *) &m->mUnk_08;
                v6 = m->mUnk_10;
                p4 = 0;
                p5 = (u8 *) m + 0xa;
            }
            if (k == 7 || k == 9) {
                data_0217ef20.mCommand = 0x82;
                data_0217ef20.mResultCode = 0;
                data_0217ef20.mUnk_04 = k;
                data_0217ef20.mUnk_08 = 0;
                data_0217ef20.mUnk_0c = 0;
                data_0217ef20.mUnk_10 = 0;
                data_0217ef20.mUnk_12 = v7;
                data_0217ef20.mUnk_20 = v6;
                data_0217ef20.mUnk_1a = 0xffff;
                MemCopy(p5, data_0217ef20.mUnk_14, 6);
                if (p4 != 0) {
                    MemCopyHalfwords(p4, data_0217ef20.mUnk_24, 0x18);
                } else {
                    z = 0;
                    MemFillHalfwords(z, data_0217ef20.mUnk_24, 0x18);
                }
                for (i = 0; i < 16; i++) {
                    data_0217ef20.mUnk_06 = i;
                    if (data_0217eed4->mPortCallbacks[i] != 0) {
                        data_0217ef20.mUnk_1c = data_0217eed4->mPortCallbackArgs[i];
                        data_0217eed4->mPortCallbacks[i](&data_0217ef20);
                    }
                }
            }
        }
    }
    DC_InvalidateRange(data_0217eed4->mMessageArea, 0x100);
    func_021425cc();
    if (m == data_0217eed4->mMessageArea) {
        return;
    }
    m->mCommand |= 0x8000;
    DC_StoreRange(m, 0x100);
}

void func_021425cc(void) {
    if ((*(u16 *) 0x27fff96 & 1) != 0) {
        *(u16 *) 0x27fff96 &= ~1;
    }
}

Unk02142988 *GetStatusArea(void) {
    if (GetErrorUnlessInitialized() != 0) {
        return 0;
    }
    return data_0217eed4->mStatusArea;
}
