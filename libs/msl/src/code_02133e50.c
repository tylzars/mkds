#include "code_021423e4.h"
#pragma avoid_byte all

#include "code_02133e50.h"
#include "code_02134890.h"
#include "code_02139e20.h"
#include "code_0200e77c.h"
#include "Main/Unknown/code_02142000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_0217e000.h"

void abort(void) {
    raise(1);
    data_0217e990 = 1;
    exit(1);
}

void exit(int a) {
    if (data_0217e990 == 0) {
        func_021424e8();
        if (data_0217e988 != 0) {
            data_0217e988();
            data_0217e988 = 0;
        }
    }
    func_02133e50(a);
}

void func_02133e50(int a) {
    if (func_0200ec08(data_0217eadc[0]) == 0) {
        data_0217ea94[0] = data_0216ff5c.mUnk_08->mUnk_6c;
        data_0217eab8[0] = 1;
    } else if (data_0217ea94[0] == data_0216ff5c.mUnk_08->mUnk_6c) {
        data_0217eab8[0]++;
    } else {
        func_0200ed34(data_0217eadc[0]);
        data_0217ea94[0] = data_0216ff5c.mUnk_08->mUnk_6c;
        data_0217eab8[0] = 1;
    }
    while (data_0217e98c > 0) {
        data_0217e994[--data_0217e98c]();
    }
    if (--data_0217eab8[0] == 0) {
        func_0200ecc4(data_0217eadc[0]);
    }
    if (data_0217e984 != 0) {
        data_0217e984();
        data_0217e984 = 0;
    }
    fflush(0);
    func_02142590();
}
