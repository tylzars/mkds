#include "03/code_021d3278.h"
#include "pm.h"

void func_ov003_021d3278(void) {
    int result;
    int pattern[1];
    result = PM_GetLEDPattern((u32 *) pattern);
    if ((result == 0) && (pattern[0] != 0xf)) {
        PMi_SendLEDPatternCommand(0xf);
    }
}
