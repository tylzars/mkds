#include "00/code_02198a8c.h"
#include "00/code_02198714.h"
#include "00/code_02198ba8.h"
#include "00/code_02198d04.h"
#include "00/code_0219903c.h"
#include "00/code_0219a000.h"
#include "00/code_0219a01c.h"
#include "00/code_0219a044.h"
#include "00/code_0219a09c.h"
#include "00/code_0219a0d0.h"
#include "00/code_0219a3f4.h"
#include "00/code_021988e8.h"
#include "00/code_0219a430.h"
#include "00/unk_021b3000.h"

int func_ov000_02198b8c(Gt2Connection *a) {
    return func_ov000_02198b50(a->mSocket, a->mAddress, a->mPort);
}

BOOL func_ov000_02198b50(Gt2Socket *a, u32 b, int c) {
    u8 d[3];

    __memcpy(d, data_ov000_021b3fa4, 2);
    d[2] = 0x68;
    if (func_ov000_0219a110((u32 *) a, b, c, (u32) d, 3) != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov000_02198af4(Gt2Connection *a, Unk02198af4 *b) {
    func_ov000_0219a01c(a->mSendBuffer.mData, b->mUnk_00 + 5, a->mUnk_66);
    if (func_ov000_02198714((u32 *) a, (u32) (a->mSendBuffer.mData + b->mUnk_00), b->mUnk_04) == 0) {
        return FALSE;
    }
    b->mUnk_0c = a->mLastSendTime;
    if (a->mSendBuffer.mData[b->mUnk_00 + 2] == 2) {
        a->mUnk_8c = a->mLastSendTime;
    }
    return TRUE;
}

int func_ov000_02198ad8(Gt2Connection *a, u8 *b, int c, int d) {
    if (d != 0) {
        return func_ov000_02198f80(a, b, c);
    }
    return func_ov000_02198c58(a, b, c);
}

u32 func_ov000_02198ac4(Gt2Socket **a, const char *b, u32 c, u32 d, u32 e) {
    return CreateSocket(a, b, c, d, e);
}

void func_ov000_02198ab0(Gt2Socket *a) {
    func_ov000_021988e8(a);
    DeleteSocket(a);
}

void func_ov000_02198a8c(Gt2Socket *a) {
    if (func_ov000_0219914c(a) != 0) {
        if (func_ov000_0219a09c(a) != 0) {
            func_ov000_0219a06c(a);
        }
    }
}
