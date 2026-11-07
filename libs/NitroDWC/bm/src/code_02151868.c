#include "code_02151868.h"
#include "code_021510a4.h"
#include "code_020205b0.h"
#include "code_0214d018.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/unk_02180000.h"

#pragma thumb on

void DWCi_BM_GetWiFiInfo(DWCWiFiInfo *info) {
    MI_CpuCopy8(data_021804a0, info, 6);
    info->mAttestedUserId &= ~0xfffff80000000000ULL;
    MI_CpuCopy8(data_021804a0 + 5, &info->mNotAttestedId, 6);
    info->mNotAttestedId >>= 3;
    info->mNotAttestedId &= ~0xfffff80000000000ULL;
    MI_CpuCopy8(data_021804a0 + 10, &info->mPass, 2);
    info->mPass = info->mPass >> 6;
    info->mPass &= 0x3ff;
    MI_CpuCopy8(data_021804a0 + 12, &info->mRandomHistory, 2);
}

BOOL DWCi_BM_SetWiFiInfo(const DWCWiFiInfo *info, u8 *work) {
    u32 address;
    s32 page;
    address = *(u32 *) data_0218049c;
    DWCi_BACKUPlConvWifiInfo(info);
    Crc16InitTable((u16 *) (work + 0x200), 0xa001);
    for (page = 0; page < 2;) {
        if (readNvram(address, 0x100, work) == 0) {
            OS_Terminate();
            return 0;
        }
        MI_CpuCopy8(data_021804a0, work + 0xf0, 0xe);
        *(u16 *) (work + 0xfe) = Crc16((u16 *) (work + 0x200), work, 0xfe);
        do {
            writeNvram(address, 0x100, work);
        } while (verify(work, address, 0x100, work + 0x100) == 0);
        page++;
        address += 0x100;
    }
    if (writeDisable() != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off
