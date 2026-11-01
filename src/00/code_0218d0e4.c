#include "00/code_0218d0e4.h"
#include "00/code_0218d000.h"
#include "00/code_021919ac.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"

void *func_ov000_0218d134(Unk021b4d24 *p, const u8 *v1) {
    s32 k[2];
    s32 *e;
    k[0] = (s32) v1;
    e = func_ov000_0218de28(func_ov000_0218b3f4(p), k);
    if (e != 0) {
        e[1] = e[1] + 1;
        return (void *) e[0];
    }
    k[0] = (s32) func_ov000_0218e880((u8 *) v1);
    k[1] = 1;
    func_ov000_0218def0(func_ov000_0218b3f4(p), k);
    return (void *) k[0];
}

void func_ov000_0218d0e4(Unk021b4d24 *p, u32 v1) {
    s32 k[2];
    s32 *e;
    k[0] = v1;
    e = func_ov000_0218de28(func_ov000_0218b3f4(p), k);
    if (e == 0) {
        func_0213442c(data_ov000_021b22a4, data_ov000_021b2218, 0, 0xf4);
    }
    if (e != 0) {
        e[1] = e[1] - 1;
        if (e[1] == 0) {
            func_ov000_0218de8c(func_ov000_0218b3f4(p), k);
        }
    }
}
