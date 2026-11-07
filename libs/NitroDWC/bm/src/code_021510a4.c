#include "code_021510a4.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"
#include "code_0214d5b8.h"
#include "code_0200f5ac.h"
#include "string.h"
#include "code_02134398.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/unk_02180000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200007e.h"

#pragma thumb on

u8 DWCi_BACKUPlConvMaskCidr(const u8 *mask) {
    s32 count;
    s32 byteIndex;
    s32 bit;
    u8 value;
    byteIndex = 0;
    count = 0;
    for (; byteIndex < 4; byteIndex++) {
        bit = 0;
        value = mask[byteIndex];
        for (; bit < 8; bit++) {
            if ((value >> bit) & 1) {
                count++;
            }
        }
    }
    return count;
}

void DWCi_BACKUPlConvMaskAddr(u32 mask, u8 *buf) {
    s32 i;
    u32 value;
    u32 shift;
    i = 0;
    value = ((u32) ~i >> mask) ^ ~i;
    shift = i;
    for (; i < 4; i++) {
        buf[i] = value >> (0x18 - shift);
        shift += 8;
    }
}

BOOL DWC_BACKUPlCheckSsid(const u8 *ssid) {
    s32 i;
    for (i = 0; i < 0x20; i++) {
        if (ssid[i] != 0) {
            return 1;
        }
    }
    return 0;
}

BOOL DWC_BACKUPlCheckIp(const u8 *ip, const u8 *mask) {
    u32 words[2];
    if (DWC_BACKUPlCheckAddress(ip) == 0) {
        return 0;
    }
    MI_CpuCopy8(ip, &words[0], 4);
    MI_CpuCopy8(mask, &words[1], 4);
    if ((words[0] | words[1]) == 0xfffffffe) {
        return 0;
    }
    if ((words[0] & ~words[1]) == 0) {
        return 0;
    }
    return 1;
}

BOOL DWC_BACKUPlCheckAddress(const u8 *address) {
    u8 first = *address;
    if (first == 0x7f) {
        return 0;
    }
    if (first < 1) {
        return 0;
    }
    if (first <= 0xdf) {
        return 1;
    }
    return 0;
}

static inline u32 sendSixWords(u32 tag, u32 w0, u32 w1, u32 w2, u32 w3, u32 w4, u32 w5) {
    if (PXI_SendWordByFifo(tag, w0, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(tag, w1, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(tag, w2, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(tag, w3, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(tag, w4, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(tag, w5, 0) < 0) {
        return 0;
    }
    return 1;
}

static inline u32 sendThreeWords(u32 tag, u32 w0, u32 w1, u32 w2) {
    if (PXI_SendWordByFifo(tag, w0, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(tag, w1, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(tag, w2, 0) < 0) {
        return 0;
    }
    return 1;
}

static inline u32 sendOneWord(u32 tag, u32 w0) {
    if (PXI_SendWordByFifo(tag, w0, 0) >= 0) {
        return 1;
    }
    return 0;
}

BOOL NVRAMm_ExecuteCommand(u32 state, u32 addr, u16 size, u8 *srcp) {
    u32 sending;
    u32 tag;
    u32 bufAddr;
    u32 readHeader;
    u32 sizeWord;
    u32 readBufHigh;
    u32 readBufLow;
    u32 writeHeader;
    u32 writeBufHigh;
    u32 statusHigh;
    u32 statusMid;
    u32 statusLow;
    u64 start;
    sending = 0;
    writeHeader = (addr >> 16) & 0xff;
    readHeader = writeHeader;
    readHeader |= 0x2002300;
    addr &= 0xffff;
    addr |= 0x10000;
    sizeWord = size;
    sizeWord &= 0xffff;
    sizeWord |= 0x30000;
    bufAddr = (u32) srcp;
    writeBufHigh = bufAddr;
    writeBufHigh >>= 16;
    readBufHigh = writeBufHigh;
    readBufHigh |= 0x40000;
    bufAddr &= 0xffff;
    readBufLow = bufAddr;
    readBufLow |= 0x1050000;
    writeHeader |= 0x2002500;
    writeBufHigh |= 0x30000;
    bufAddr |= 0x1040000;
    statusHigh = (u32) &data_usa_021804a0 >> 24;
    statusHigh |= 0x2002200;
    statusMid = (u32) &data_usa_021804a0 >> 8;
    statusMid &= 0xffff;
    statusMid |= 0x10000;
    statusLow = (u32) &data_usa_021804a0 << 8;
    statusLow &= 0xff00;
    statusLow |= 0x1020000;
    tag = 4;
    while (1) {
        if (sending == 0) {
            data_usa_02180478 = 0;
            switch (state) {
                case 1:
                    sending = sendSixWords(tag, readHeader, addr, 0x20000, sizeWord, readBufHigh, readBufLow);
                    break;
                case 2:
                    sending = sendOneWord(tag, 0x3002000);
                    break;
                case 3:
                    if (PXI_SendWordByFifo(tag, writeHeader, 0) < 0) {
                        sending = 0;
                    } else if (PXI_SendWordByFifo(tag, addr, 0) < 0) {
                        sending = 0;
                    } else if (PXI_SendWordByFifo(tag, size | 0x20000, 0) < 0) {
                        sending = 0;
                    } else if (PXI_SendWordByFifo(tag, writeBufHigh, 0) < 0) {
                        sending = 0;
                    } else if (PXI_SendWordByFifo(tag, bufAddr, 0) < 0) {
                        sending = 0;
                    } else {
                        sending = 1;
                    }
                    start = OS_GetTick();
                    break;
                case 4:
                case 5:
                    sending = sendThreeWords(tag, statusHigh, statusMid, statusLow);
                    break;
                case 6:
                    sending = sendOneWord(tag, 0x3002d00);
                    break;
                case 7:
                    sending = sendOneWord(tag, 0x3002100);
                    break;
            }
        } else if (data_usa_02180478 == 1) {
            sending = 0;
            if (data_usa_02180474 != 0) {
                break;
            }
            switch (state) {
                case 1:
                    return 1;
                case 2:
                    state = tag;
                    break;
                case 3:
                    state = 5;
                    break;
                case 4:
                case 5:
                    DC_InvalidateRange(&data_usa_021804a0, 1);
                    if (state == 4) {
                        if (data_usa_021804a0 & 2) {
                            state = 3;
                            break;
                        }
                        return 0;
                    }
                    if ((data_usa_021804a0 & 1) == 0) {
                        return 1;
                    }
                    if ((data_usa_021804a0 & 0x20) != 0 || ((OS_GetTick() - start) * 64) / 33514 > 4000) {
                        state = 6;
                    } else {
                        WaitByLoop(0x4000);
                    }
                    break;
                case 6:
                    return sending;
                case 7:
                    return 1;
            }
        }
    }
    return sending;
}

BOOL readNvram(u32 address, u32 size, void *buf) {
    u32 tag;
    DC_InvalidateRange(buf, size);
    tag = 4;
    while (PXI_IsCallbackReady(tag, 1) == 0) {
    }
    PXI_SetFifoRecvCallback(4, (UnkFunc *) Callback_NVRAM);
    tag = 1;
    while (1) {
        if (NVRAMm_ExecuteCommand(tag, address, size, buf) == 1) {
            break;
        }
        WaitByLoop(0x40000);
    }
    DC_InvalidateRange(buf, size);
    return 1;
}

void writeNvram(u32 address, u16 size, void *data) {
    u32 tag;
    tag = 4;
    while (PXI_IsCallbackReady(tag, 1) == 0) {
    }
    PXI_SetFifoRecvCallback(4, (UnkFunc *) Callback_NVRAM);
    DC_StoreRange(data, size);
    tag = 2;
    while (1) {
        if (NVRAMm_ExecuteCommand(tag, address, size, data) == 1) {
            break;
        }
        WaitByLoop(0x40000);
    }
}

BOOL verify(const u8 *src, u32 address, u32 size, const u8 *work) {
    if (readNvram(address, size, work) == 0) {
        return 0;
    }
    if (memcmp(src, work, size) == 0) {
        return 1;
    }
    return 0;
}

BOOL writeDisable(void) {
    u32 tag;
    u32 ready;
    u32 delay;
    u32 zero;
    tag = 4;
    ready = 1;
    while (PXI_IsCallbackReady(tag, ready) == 0) {
    }
    PXI_SetFifoRecvCallback(4, (UnkFunc *) Callback_NVRAM);
    delay = 0x40000;
    tag = 7;
    zero = 0;
    while (1) {
        if (NVRAMm_ExecuteCommand(tag, zero, zero, (u8 *) zero) == 1) {
            break;
        }
        WaitByLoop(delay);
    }
    return 1;
}

u16 Callback_NVRAM(u32 tag, u32 data, u32 err) {
    data_usa_02180474 = data & 0xff;
    data_usa_02180478 = 1;
    if (err != 0) {
        data_usa_02180474 = 0xff;
    }
    return data_usa_02180474;
}

u8 *DWCi_BACKUPlConvWifiInfo(const DWCWiFiInfo *info) {
    u64 notAttestedId;
    u32 byte5;
    u32 byte10;
    notAttestedId = info->mNotAttestedId;
    MI_CpuCopy8(info, data_021804a0, 5);
    byte5 = ((u32) (info->mAttestedUserId >> 32) >> 8) & 7;
    byte5 |= ((u32) notAttestedId & 0x1f) << 3;
    data_021804a0[5] = byte5;
    notAttestedId >>= 5;
    MI_CpuCopy8(&notAttestedId, data_021804a0 + 6, 4);
    byte10 = (u32) (notAttestedId >> 32) & 0x3f;
    byte10 |= (info->mPass & 3) << 6;
    data_021804a0[10] = byte10;
    data_021804a0[11] = info->mPass >> 2;
    MI_CpuCopy8(&info->mRandomHistory, data_021804a0 + 12, 2);
    return data_021804a0;
}

#pragma thumb off
