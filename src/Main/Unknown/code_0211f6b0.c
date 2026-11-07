#include "Main/Unknown/code_0211f6b0.h"
#include "00/code_021832d8.h"

u32 BuddyChangedCallback(void) {
    u32 address;
    u32 flag;
    address = (u32) &gWiFiSession;
    flag = 1u;
    address = *(const u32 *) ((address) + (0));
    address = (address) + (0x1000u);
    *(u32 *) ((address) + (3324)) = flag;
    return address;
}
