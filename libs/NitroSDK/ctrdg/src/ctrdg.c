#include "ctrdg.h"
#include "code_0214d5b8.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_0200007e.h"

#pragma thumb on

// Sends data on FIFO tag 13, waiting and trying again until the send is accepted.
void CTRDGi_SendtoPxi(u32 data) {
    if (PXI_SendWordByFifo(13, data, 0) != 0) {
        do {
            WaitByLoop(1);
        } while (PXI_SendWordByFifo(13, data, 0) != 0);
    }
}
