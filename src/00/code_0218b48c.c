#include "00/code_0218b48c.h"
#include "00/code_0218b64c.h"
#include "00/code_0218b708.h"
#include "00/code_0218a918.h"
#include "00/code_0218acb0.h"
#include "00/code_0218d180.h"
#include "00/code_0218d218.h"
#include "00/code_0218d2a8.h"

void func_ov000_0218b4d4(struct Unk0218b668 *p, s32 a) {
    s32 b;
    b = func_ov000_0218d300((u32) &p->mUnk_04c, a);
    if (b != -1) {
        func_ov000_0218d238(&p->mUnk_04c, b);
    }
}

s32 func_ov000_0218b4bc(struct Unk0218b668 *p) {
    func_ov000_0218a950((int) p);
    return func_ov000_0218b8e4(&p->mUnk_04c);
}

void func_ov000_0218b4a4(struct Unk0218b668 *p) {
    func_ov000_0218c980(&p->mUnk_04c);
    func_ov000_0218acd8((int) p);
}

void func_ov000_0218b48c(struct Unk0218b668 *p) {
    func_ov000_0218b4a4(p);
    func_ov000_0218d1a0((u32) &p->mUnk_04c);
}
