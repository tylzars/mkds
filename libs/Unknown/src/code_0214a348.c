#include "code_0214a348.h"

// Sets the brightness amount of a blend register block. A negative value changes a brightness increase effect
// to a decrease; a positive value changes a decrease to an increase.
void G2x_ChangeBlendBrightness_(u16 *reg, s32 brightness) {
    u32 control;

    control = reg[0];
    if (brightness < 0) {
        if ((control & 0xc0) == 0x80) {
            reg[0] = (control & ~0xc0) | 0xc0;
        }
        reg[2] = -brightness;
    } else {
        if ((control & 0xc0) == 0xc0) {
            reg[0] = (control & ~0xc0) | 0x80;
        }
        reg[2] = brightness;
    }
}
