#pragma once

#include "types.h"

// Sends data on FIFO tag 13, waiting and trying again until the send is accepted.
void CTRDGi_SendtoPxi(u32 data);
