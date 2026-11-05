#include "Main/Unknown/code_020f8ddc.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020f36d8.h"

#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020f6be8.h"

void func_020f8ddc(void *a) {
    ItemObject *p = a;

    if (p == NULL) {
        return;
    }
    if (data_021759c0->mMode != 4) {
        return;
    }
    if ((u32) p->mKind > 1) {
        return;
    }
    func_0208b7bc(0x441, &p->mPos);
    func_0208b7bc(0x440, &p->mPos);
}
