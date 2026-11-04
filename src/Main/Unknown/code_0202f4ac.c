#include "Main/Unknown/code_0202f4ac.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_02038c94.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"

void func_0202f530(void *p, u32 v, u32 n) {
    volatile u32 value = v;

    MemFillWordsByBlock(value, p, n);
}

void func_0202f51c(void *p, u32 n) {
    func_0202f530(p, 0, n);
}

void func_0202f4e0(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    func_02038d28(a->mUnk_28, b, c, d, e, f, g, h);
}

void func_0202f4ac(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    func_02038cd8(a->mUnk_70, b, c, d, e, f, g);
}
