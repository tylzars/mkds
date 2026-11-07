#include "os_timer.h"
#include "Main/Unknown/unk_02170000.h"

// Marks timer timerNum as reserved.
void OSi_SetTimerReserved(u32 timerNum) {
    data_02170248 = data_02170248 | (1 << timerNum);
}
