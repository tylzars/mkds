#include "Main/Unknown/code_02122ae4.h"
#include "00/code_021832d8.h"

u32 func_02122ae4(void) {
    u32 result;
    u32 value1;
    u32 flag;
    u32 testedFlag;
    u32 one;
    u32 testedStep;
    u32 twelve;
    value1 = (u32) &gWiFiSession;
    result = 0u;
    value1 = *(const u32 *) ((value1) + (0));
    value1 = (value1) + (0x1000u);
    flag = *(const u8 *) ((value1) + (2477));
    testedFlag = flag;
    one = 1u;
    if (testedFlag != one) {
        return result;
    }
    value1 = *(const u32 *) ((value1) + (2384));
    testedStep = value1;
    twelve = 0xcu;
    if (testedStep == twelve) {
        result = 1u;
    }
    return result;
}
