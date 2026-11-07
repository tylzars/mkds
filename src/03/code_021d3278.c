#include "03/code_021d3278.h"
#include "pm.h"

void func_ov003_021d3278(void) {
    int v1;
    int v2[1];
    v1 = PM_GetLEDPattern((u32 *) v2);
    if ((v1 == 0) && (v2[0] != 0xf)) {
        PMi_SendLEDPatternCommand(0xf);
    }
}
