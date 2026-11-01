#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_0208bd20.h"
#include "Main/Unknown/code_0208bd40.h"
#include "Main/Unknown/code_0208bd44.h"
#include "Main/Unknown/code_0208bf6c.h"
#include "Main/Unknown/code_0208bfd8.h"
#include "Main/Unknown/unk_0217b000.h"

void func_0208c284(void) {
    if (data_021759c0->mUnk_00c == 5 || data_021759c0->mUnk_08 == 4) {
        data_0217b05c = func_0208be00;
        data_0217b060 = func_0208bde0;
        data_0217b058 = func_0208bdc0;
        data_0217b070 = func_0208c050;
        data_0217b074 = func_0208c03c;
        data_0217b064 = func_0208c000;
        data_0217b068 = func_0208bfec;
        data_0217b06c = func_0208bfd8;
    } else if (data_021759c0->mUnk_00c == 6) {
        data_0217b05c = func_0208bd44;
        data_0217b060 = func_0208bd40;
        data_0217b058 = func_0208bd20;
        data_0217b070 = func_0208c050;
        data_0217b074 = func_0208c03c;
        data_0217b064 = func_0208c000;
        data_0217b068 = func_0208bfec;
        data_0217b06c = func_0208bfd8;
    } else if (data_021759c0->mUnk_08 == 2) {
        data_0217b05c = func_0208bf94;
        data_0217b060 = func_0208bf6c;
        data_0217b058 = func_0208bf40;
        data_0217b070 = func_0208bef4;
        data_0217b074 = func_0208bee0;
        data_0217b064 = func_0208bea4;
        data_0217b068 = func_0208be90;
        data_0217b06c = func_0208be7c;
    } else {
        data_0217b05c = func_0208c0f0;
        data_0217b060 = func_0208c0c8;
        data_0217b058 = func_0208c09c;
        data_0217b070 = func_0208c050;
        data_0217b074 = func_0208c03c;
        data_0217b064 = func_0208c000;
        data_0217b068 = func_0208bfec;
        data_0217b06c = func_0208bfd8;
    }
}

void func_0208c260(Unk020888b4 *p, s32 a) {
    data_0217b05c(p, a);
}

void func_0208c23c(Unk020888b4 *p, Unk02175620_bc *a) {
    data_0217b060(p, a);
}

void func_0208c218(Unk020888b4 *p) {
    data_0217b058(p);
}

void func_0208c1f4(Unk020888b4 *p) {
    data_0217b070(p);
}

void func_0208c1d0(Vec3 *a, Vec3 *b, Unk020888b4 *c) {
    data_0217b064(a, b, c);
}

void func_0208c1ac(Unk020888b4 *p) {
    data_0217b068(p);
}

void func_0208c188(Unk020888b4 *p) {
    data_0217b06c(p);
}
