#include "01/code_0218c55c.h"
#include "01/code_02187eb0.h"
#include "01/code_02188cd8.h"
#include "Main/Unknown/code_02042044.h"

u32 func_ov001_0218c55c(Unk02188950 *a) {
    CourseMapGroupEntry *v1;
    v1 = func_ov001_02187fc0(a);
    SetMoveAnglePoint(a, &v1->mPos);
    v1 = func_ov001_02187fc0(a);
    func_ov001_02188d8c(a, &v1->mPos);
    return 0;
}
