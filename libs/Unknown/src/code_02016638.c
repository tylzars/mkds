#include "code_0200eddc.h"
#include "code_02016638.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/unk_02152000.h"

void func_02016638(Unk02016638 *p) {
    void (*f)(const void *, u32, u32);

    f = data_02152c54[p->mUnk_00];
    func_0200ee74((const void *) p->mUnk_04, p->mUnk_0c);
    f((const void *) p->mUnk_04, p->mUnk_08, p->mUnk_0c);
}
