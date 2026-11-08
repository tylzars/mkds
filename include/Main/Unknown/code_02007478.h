#pragma once

#include "types.h"
#include "code_02003024.h"
#include "code_0200fc8c.h"
#include "fs_file.h"
#include "code_02003be0.h"
#include "Main/Unknown/code_02007148.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0200aeb4.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_02008908.h"
#include "Main/Unknown/code_0214d000.h"

// Object QueueWorkerTask runs LoadDataRange on: the member at 0x10 is the entry of DataRangeTable that is read.
typedef struct DataRangeLoadJob {
    /* 00 */ WorkerTask mUnk_00;
    /* 10 */ DataRange *mDataRange;
    /* 14 */ DataRangeTable *mDataRangeTable;
} DataRangeLoadJob;

// Six bytes handed to WriteParentMessage.
typedef struct Unk020074d8_msg {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
} Unk020074d8_msg;

extern u8 data_usa_02161784;

void LoadDataRange(DataRangeLoadJob *job);
u32 func_020074d8(void);
