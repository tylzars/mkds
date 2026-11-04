#include "00/code_0218d818.h"
#include "00/code_0219a044.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/code_02197e58.h"
#include "00/code_021985ec.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_0219a0d0.h"
#include "00/code_0219a3f4.h"

void func_ov000_0219a06c(Gt2Socket *a) {
    s32 b;
    for (b = DarrayGetCount(a->mConnectionsToFree) - 1; b >= 0; b--) {
        func_ov000_0219a220(*(Gt2Connection **) DarrayGetElement(a->mConnectionsToFree, b));
    }
}

void func_ov000_0219a044(Gt2Socket *a) {
    if (a->mUnk_18 == 0) {
        a->mUnk_18 = 1;
        func_ov000_021988e8(a);
        if (func_ov000_02198448(a) != 0) {
            DeleteSocket(a);
        }
    }
}
