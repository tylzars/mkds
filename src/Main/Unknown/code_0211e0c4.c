#include "Main/Unknown/code_0211e0c4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_02061428.h"
#include "Main/Unknown/code_02061540.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02090354.h"

#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02090000.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02061418.h"
#include "Main/Unknown/code_0206152c.h"
#include "Main/Unknown/code_02061644.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"

#pragma thumb on

void func_0211e480(void *a) {
    data_0217d374 = HeapAlloc(a, 0x14);
    data_0217d374->mUnk_00 = (u8 *) CreateCourseGhostRecords((u32) a);
    func_02061540(data_0217d374->mUnk_00);
    func_02057d9c();
    data_0217d374->mUnk_04 = (u8 *) func_0206152c((u32) a);
    func_02061428(data_0217d374->mUnk_04);
    func_02057d9c();
    data_0217d374->mUnk_08 = (u8 *) CreateGhostFileRecords((u32) a);
    func_02061358(data_0217d374->mUnk_08);
    func_02057d9c();
    LoadStaffGhostTime(a);
}

void func_0211e474(void) {
    data_0217d374 = NULL;
}

void func_0211e418(u32 a) {
    s32 i;

    data_0217d374->mUnk_0c = a;
    data_0217d374->mUnk_10 = -1;
    for (i = 0; i < 0xa; i++) {
        if (IsGhostRecordFilled(data_0217d374->mUnk_04 + (u8) i * 0x230) != FALSE &&
            GetGhostRecordCourseId(data_0217d374->mUnk_04 + (u8) i * 0x230) == a) {
            data_0217d374->mUnk_10 = i;
            return;
        }
    }
}

void func_0211e38c(u32 a, void *b) {
    u8 *p;

    switch (a) {
        case 0:
            p = data_0217d374->mUnk_00;
            GetGhostRecordTime(p + FindCupCourseIndex(data_0217d374->mUnk_0c) * 0x30, b);
            break;
        case 1:
            GetGhostRecordTime(data_0217d374->mUnk_04 + (u8) data_0217d374->mUnk_10 * 0x230, b);
            break;
        case 2:
            p = data_0217d374->mUnk_08;
            GetGhostRecordTime(p + FindCupCourseIndex(data_0217d374->mUnk_0c) * 0x230, b);
            break;
        case 4:
            break;
    }
}

void func_0211e2f8(u32 a, void *b) {
    u8 *p;
    u8 buf[0x14];

    switch (a) {
        case 0:
            p = data_0217d374->mUnk_00;
            GetGhostRecordName(p + FindCupCourseIndex(data_0217d374->mUnk_0c) * 0x30, buf);
            break;
        case 1:
            GetGhostRecordName(data_0217d374->mUnk_04 + (u8) data_0217d374->mUnk_10 * 0x230, buf);
            break;
        case 2:
            p = data_0217d374->mUnk_08;
            GetGhostRecordName(p + FindCupCourseIndex(data_0217d374->mUnk_0c) * 0x230, buf);
            break;
        case 4:
            break;
    }
    MI_CpuFill8(b, 0, 0x20);
    MIi_CpuCopy16(buf, b, 0x14);
}

s32 func_0211e274(u32 a) {
    u8 *p;
    s32 r = -1;

    switch (a) {
        case 4:
            r = -1;
            break;
        case 0:
            p = data_0217d374->mUnk_00;
            r = GetGhostRecordCharacterIndex(p + FindCupCourseIndex(data_0217d374->mUnk_0c) * 0x30);
            break;
        case 1:
            r = GetGhostRecordCharacterIndex(data_0217d374->mUnk_04 + (u8) data_0217d374->mUnk_10 * 0x230);
            break;
        case 2:
            p = data_0217d374->mUnk_08;
            r = GetGhostRecordCharacterIndex(p + FindCupCourseIndex(data_0217d374->mUnk_0c) * 0x230);
            break;
    }
    return r;
}

s32 func_0211e1f0(u32 a) {
    u8 *p;
    s32 r = -1;

    switch (a) {
        case 4:
            r = -1;
            break;
        case 0:
            p = data_0217d374->mUnk_00;
            r = GetGhostRecordKartIndex(p + FindCupCourseIndex(data_0217d374->mUnk_0c) * 0x30);
            break;
        case 1:
            r = GetGhostRecordKartIndex(data_0217d374->mUnk_04 + (u8) data_0217d374->mUnk_10 * 0x230);
            break;
        case 2:
            p = data_0217d374->mUnk_08;
            r = GetGhostRecordKartIndex(p + FindCupCourseIndex(data_0217d374->mUnk_0c) * 0x230);
            break;
    }
    return r;
}

s32 func_0211e160(u32 a) {
    s32 r = 0;
    u8 *p;

    switch (a) {
        case 4:
            r = 1;
            break;
        case 0:
            p = data_0217d374->mUnk_00;
            r = IsGhostRecordFilled(p + FindCupCourseIndex(data_0217d374->mUnk_0c) * 0x30);
            break;
        case 1:
            if (data_0217d374->mUnk_10 != -1) {
                r = 1;
            }
            break;
        case 2:
            if (IsTimeRecordFilled(data_0217d374->mUnk_0c, 0) != FALSE) {
                u32 buf;

                GetTimeRecordTime(data_0217d374->mUnk_0c, 0, &buf);
                r = IsTimeLessThanStaffGhostTime(data_0217d374->mUnk_0c, &buf);
            } else {
                r = 0;
            }
            break;
    }
    return r;
}

BOOL func_0211e130(void) {
    u32 a = 0;

    a |= func_0211e160(a);
    a |= func_0211e160(1);
    a |= func_0211e160(2);
    if (a == 0) {
        return TRUE;
    }
    return FALSE;
}

void func_0211e0c4(u32 a) {
    switch (a) {
        case 4:
            func_02043fb0(data_0217d374->mUnk_0c);
            break;
        case 0:
            func_020442d0(data_0217d374->mUnk_0c);
            break;
        case 1:
            func_0204419c(data_0217d374->mUnk_0c, (u8) data_0217d374->mUnk_10);
            break;
        case 2:
            func_02044060(data_0217d374->mUnk_0c);
            break;
    }
}

#pragma thumb off
