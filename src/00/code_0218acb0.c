#include "00/code_0218acb0.h"
#include "00/code_0218a000.h"
#include "00/code_0218ae5c.h"
#include "00/code_0218b000.h"
#include "00/code_0218c000.h"
#include "00/code_021a3000.h"
#include "00/code_0218aea4.h"
#include "00/code_0218e2dc.h"

void func_ov000_0218acf0(MatchingServerList *a, u32 b) {
    a->mUnk_000.mUnk_28 = b;
}

void func_ov000_0218acd8(MatchingServerList *a) {
    func_ov000_0218ae5c(&a->mUnk_000.mUnk_14);
    func_ov000_0218ae5c(&a->mUnk_000.mUnk_08);
}

void func_ov000_0218acb0(MatchingServerList *p) {
    func_ov000_0218e53c(p->mUnk_000.mUnk_20);
    p->mUnk_000.mUnk_20 = 0xffffffff;
    func_ov000_0218ae5c(&p->mUnk_000.mUnk_14);
    func_ov000_0218ae5c(&p->mUnk_000.mUnk_08);
}
