#include "Main/Unknown/code_020071b4.h"
#include "Main/Unknown/code_02007478.h"
#include "Main/Unknown/code_020075f8.h"
#include "Main/Unknown/code_02007ec4.h"
#include "Main/Unknown/code_0200c0d8.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0214cfe4.h"

#pragma thumb on

u32 func_020072c0(void) {
    Unk020074d8_msg message;
    Unk020072c0_buf v2;
    u8 v11;
    u8 v14;
    Unk0216fdac *work;
    Unk0216fdac *childEntry;
    DataRangeTable *rangeTable;
    DataRange *lowestRange;
    s32 i;
    DataRange *range;
    u8 *v9;
    u32 v10;
    Unk02007478 *loadJob;
    Unk0216fdac *v12;
    Unk0216fdac *v13;
    v12 = data_0216fdac;
    if (v12->mUnk_1524 == 0) {
        return 21;
    }
    v11 = 0;
    do {
        work = data_0216fdac;
        work->mUnk_1525 = (work->mUnk_1525 + 1) % 16;
        v13 = (Unk0216fdac *) *(u32 *) &data_0216fdac;
        childEntry = OFFSET_PTR(Unk0216fdac, v13, v13->mUnk_1525 * 0x5d4);
        if (childEntry->mUnk_1d52 != 0 && childEntry->mUnk_1d4c != 0) {
            break;
        }
        v11++;
    } while (v11 < 16);
    if (v11 == 16) {
        return 21;
    }
    func_02007154(v13->mUnk_1525);
    work = data_0216fdac;
    childEntry = OFFSET_PTR(Unk0216fdac, work, work->mUnk_1525 * 0x5d4);
    if (func_0200806c(&v2, work->mUnk_1d2c + work->mUnk_1525 * 0x5d4, childEntry->mUnk_1d48,
                      work->mUnk_1788 + work->mUnk_1525 * 0x5d4) == FALSE) {
        return 21;
    }
    message.mUnk_00 = 4;
    work = data_0216fdac;
    message.mUnk_02 = work->mUnk_1525;
    message.mUnk_04 = (OFFSET_PTR(Unk0216fdac, work, work->mUnk_1525 * 0x5d4))->mUnk_1d48;
    v9 = WriteParentMessage((u8 *) &message, (u8 *) work);
    v14 = v2.mUnk_0c;
    work = data_0216fdac;
    v10 = v2.mUnk_08 - ((u32 *) (OFFSET_PTR(Unk0216fdac, work, work->mUnk_1525 * 0x5d4))->mUnk_1d2c)[v14] +
          (OFFSET_PTR(Unk0216fdac, work, work->mUnk_1525 * 0x5d4))->mUnk_1d58[v14];
    childEntry = OFFSET_PTR(Unk0216fdac, work, work->mUnk_1525 * 0x5d4);
    rangeTable = childEntry->mUnk_1d54;
    if (CopyFromDataRanges(rangeTable, v10, v9, v2.mUnk_04) == 0) {
        loadJob = (Unk02007478 *) data_0216fdac->mUnk_7ce0;
        if (func_0200aff8(&loadJob->mUnk_00) == 0) {
            if (rangeTable->mUnk_00 != 0) {
                range = rangeTable->mUnk_30;
                lowestRange = NULL;
                for (i = 0; i < 4; range++, i++) {
                    if (range->mUnk_0c == 2) {
                        if (lowestRange == NULL || lowestRange->mOffset > range->mOffset) {
                            lowestRange = range;
                        }
                    }
                }
                if (lowestRange == NULL) {
                    OS_Terminate();
                }
                rangeTable->mUnk_00 = 0;
                lowestRange->mUnk_0c = 1;
                lowestRange->mOffset = v10 & ~0x1f;
                loadJob->mDataRange = lowestRange;
                loadJob->mDataRangeTable = rangeTable;
                func_0200aeec(&loadJob->mUnk_00, (void *) LoadDataRange, NULL, 4);
            }
        }
        return 21;
    }
    work = data_0216fdac;
    return func_02008908(v2.mUnk_04 + 6, (OFFSET_PTR(Unk0216fdac, work, work->mUnk_1525 * 0x5d4))->mUnk_1d4c,
                         (u32) work);
}

int func_020071b4(void) {
    u16 childMasks[6];
    u16 i;
    int result;
    Unk0216fdac *work;
    childMasks[0] = 0;
    MIi_CpuClear16(childMasks[0], &childMasks[1], 10);
    i = 1;
    work = data_0216fdac;
    for (; i <= 15; i++) {
        switch (work->mUnk_14e8[i - 1]) {
            case 2:
                childMasks[1] |= 1 << i;
                break;
            case 5:
                childMasks[2] |= 1 << i;
                break;
            case 4:
                childMasks[3] |= 1 << i;
                break;
            case 8:
                childMasks[4] |= 1 << i;
                break;
            case 11:
                childMasks[5] |= 1 << i;
                break;
        }
    }
    if (childMasks[4] != 0) {
        result = SendParentMessage(5, childMasks[4]);
    } else if (childMasks[1] != 0) {
        result = SendParentMessage(1, childMasks[1]);
    } else if (childMasks[5] != 0) {
        result = SendParentMessage(6, childMasks[5]);
    } else if (childMasks[3] != 0) {
        result = SendParentMessage(2, childMasks[3]);
    } else if (childMasks[2] != 0) {
        result = func_020074d8();
    } else {
        result = func_020072c0();
    }
    if (result == 21) {
        result = SendParentMessage(0, 0xffff);
    }
    return result;
}

#pragma thumb off
