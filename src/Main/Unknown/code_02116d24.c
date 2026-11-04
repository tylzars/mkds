#include "Main/Unknown/code_02116d24.h"

#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"
#include "code_0214cfe4.h"

#pragma thumb on

const u16 data_0215c5d0[4] = {0, 1, 2, 0};

void func_02116d24(void) {
    u8 *q;
    Unk0217d354 *p;

    data_0217d354->mUnk_28++;
    if (data_0217d354->mUnk_28 >= 4) {
        data_0217d354->mUnk_24++;
        if (data_0217d354->mUnk_24 >= 3) {
            data_0217d354->mUnk_24 = 0;
        }
        data_0217d354->mUnk_28 = 0;
        func_02124748(data_0215c5d0[data_0217d354->mUnk_24], data_0217d354->mUnk_00, data_0217d354->mUnk_04,
                      data_0217d354->mUnk_0c, data_0217d354->mUnk_20, data_0217d354->mUnk_18, data_0217d354->mUnk_10,
                      data_0217d354->mUnk_14);
        p = data_0217d354;
        q = p->mUnk_08->mUnk_0c;
        switch (p->mUnk_20) {
            case 0:
                CallQueueAppend(0xe, p->mUnk_1c << 5, q + 0x1c0, 0x20);
                break;
            case 1:
                CallQueueAppend(0x1e, p->mUnk_1c << 5, q + 0x1c0, 0x20);
                break;
        }
    }
}

#pragma thumb off
