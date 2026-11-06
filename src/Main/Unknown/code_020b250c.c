#include "Main/Unknown/code_020b250c.h"
#include "Main/Unknown/code_020b252c.h"
#include "Main/Unknown/code_020b24e4.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma thumb on
#pragma optimize_for_size on
BOOL func_020b250c(void) {
    return func_020b252c() == MODE_GRAND_PRIX && GetCourseNumber() == 4;
}
#pragma thumb off
