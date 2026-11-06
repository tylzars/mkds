#include "00/code_02198d04.h"
#include "00/code_0218d818.h"
#include "00/code_02197b34.h"
#include "00/code_02198714.h"
#include "00/code_0219903c.h"
#include "00/unk_021b3000.h"
#include "code_02134398.h"
#include "00/code_02197e58.h"

#pragma opt_common_subs off

u32 func_ov000_02198fdc(Gt2Connection *param_1) {
    int v1;
    int *v2;
    v1 = DarrayGetCount(param_1->mUnk_60);
    if (v1 <= 0) {
        AssertionFailed(data_ov000_021b3fb0, data_ov000_021b3fb8, NULL, 0x475);
    }
    v2 = DarrayGetElement(param_1->mUnk_60, v1 + -1);
    v1 = SendConnectionBytes(param_1, param_1->mSendBuffer.mData + *v2, v2[1]);
    if (v1 == 0) {
        return 0;
    }
    param_1->mUnk_90 = 0;
    return 1;
}

u32 func_ov000_02198f80(Gt2Connection *param_1, const u8 *param_2, int param_3) {
    int v1;
    int v2[2];
    v1 = func_ov000_0219903c(param_1, 0, param_3 + 7, v2);
    if (v1 == 0) {
        return 0;
    }
    if (v2[0] != 0) {
        return 1;
    }
    AppendBufferBytes(&param_1->mSendBuffer, param_2, param_3);
    v1 = func_ov000_02198fdc(param_1);
    if (v1 != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02198f24(Gt2Connection *param_1, const void *param_2) {
    int v1;
    int v2;
    v1 = func_ov000_0219903c(param_1, 1, 0x27, &v2);
    if (v1 == 0) {
        return 0;
    }
    if (v2 != 0) {
        return 1;
    }
    AppendBufferBytes(&param_1->mSendBuffer, param_2, 0x20);
    v1 = func_ov000_02198fdc(param_1);
    if (v1 != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02198eb0(Gt2Connection *param_1, const u8 *param_2, const u8 *param_3) {
    int v1;
    int v2[2];
    v1 = func_ov000_0219903c(param_1, 2, 0x47, v2);
    if (v1 == 0) {
        return 0;
    }
    if (v2[0] != 0) {
        return 1;
    }
    AppendBufferBytes(&param_1->mSendBuffer, param_2, 0x20);
    AppendBufferBytes(&param_1->mSendBuffer, param_3, 0x20);
    v1 = func_ov000_02198fdc(param_1);
    if (v1 == 0) {
        return 0;
    }
    param_1->mUnk_8c = param_1->mLastSendTime;
    return 1;
}

u32 func_ov000_02198e44(Gt2Connection *param_1, const u8 *param_2, const u8 *param_3, int param_4) {
    int v1;
    int v2;
    v1 = func_ov000_0219903c(param_1, 3, param_4 + 0x27, &v2);
    if (v1 == 0) {
        return 0;
    }
    if (v2 != 0) {
        return 1;
    }
    AppendBufferBytes(&param_1->mSendBuffer, param_2, 0x20);
    AppendBufferBytes(&param_1->mSendBuffer, param_3, param_4);
    v1 = func_ov000_02198fdc(param_1);
    if (v1 != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02198df8(Gt2Connection *param_1) {
    int v1;
    int v2[2];
    v1 = func_ov000_0219903c(param_1, 4, 7, v2);
    if (v1 == 0) {
        return 0;
    }
    if (v2[0] != 0) {
        return 1;
    }
    v1 = func_ov000_02198fdc(param_1);
    if (v1 != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02198d9c(Gt2Connection *param_1, const void *param_2, int param_3) {
    int v1;
    int v2[2];
    v1 = func_ov000_0219903c(param_1, 5, param_3 + 7, v2);
    if (v1 == 0) {
        return 0;
    }
    if (v2[0] != 0) {
        return 1;
    }
    AppendBufferBytes(&param_1->mSendBuffer, param_2, param_3);
    v1 = func_ov000_02198fdc(param_1);
    if (v1 != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02198d50(Gt2Connection *param_1) {
    int v1;
    int v2[2];
    v1 = func_ov000_0219903c(param_1, 6, 7, v2);
    if (v1 == 0) {
        return 0;
    }
    if (v2[0] != 0) {
        return 1;
    }
    v1 = func_ov000_02198fdc(param_1);
    if (v1 != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02198d04(Gt2Connection *param_1) {
    int v1;
    int v2[2];
    v1 = func_ov000_0219903c(param_1, 7, 7, v2);
    if (v1 == 0) {
        return 0;
    }
    if (v2[0] != 0) {
        return 1;
    }
    v1 = func_ov000_02198fdc(param_1);
    if (v1 != 0) {
        return 1;
    }
    return 0;
}
