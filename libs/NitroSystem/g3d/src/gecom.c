#include "gecom.h"
#include "Main/Unknown/unk_02173000.h"

// Selects the fast DMA transfer for display lists when set.
void NNS_G3dGeUseFastDma(BOOL enabled) {
    data_0217320c = enabled;
}
