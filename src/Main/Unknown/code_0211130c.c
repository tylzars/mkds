#include "Main/Unknown/code_0211130c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_020ae630.h"

#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_02111450.h"
#include "Main/Unknown/code_021114b0.h"
#include "Main/Unknown/code_021114cc.h"
#include "Main/Unknown/code_02111584.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02111368.h"
#include "Main/Unknown/code_021113ac.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_021115b0.h"

#pragma thumb on

void InitRecordScene(s16 *a) {
    void *p;
    p = GetHeap(func_020364e8());
    data_0217d33c = HeapAlloc(p, 0x404);
    data_0217d340 = HeapAlloc(p, 0x404);
    func_021115b0(p, *a);
}

#pragma thumb off

#pragma thumb on
void ReleaseRecordScene(void) {
    u32 value0;
    u32 value1;
    func_02111584();
    value1 = 0u;
    value0 = (u32) &data_0217d33c;
    *(u32 *) ((value0) + 0u) = value1;
    value0 = (u32) &data_0217d340;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on
void func_02111368(void) {
    u32 value0;
    u32 value1;
    func_021114b0();
    value0 = (u32) &data_0217d33c;
    value0 = *(const u32 *) ((value0) + 0u);
    value1 = (u32) &data_0217d340;
    value1 = *(const u32 *) ((value1) + 0u);
    func_020ae5f0((void *) value0, (void *) value1);
}
#pragma thumb off

#pragma thumb on

void UpdateRecordScene(Unk02111324 *a) {
    func_020ae6ac(data_0217d33c, data_0217d340);
    func_021114cc();
    func_020ae630(data_0217d33c, data_0217d340);
    if (a != NULL && func_0211145c() != -1) {
        a->mUnk_04 = func_0211145c();
    }
}

void *func_02111318(void) {
    return data_0217d33c;
}

void *func_0211130c(void) {
    return data_0217d340;
}

#pragma thumb off
