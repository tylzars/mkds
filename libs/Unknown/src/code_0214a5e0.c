#include "code_0214a5e0.h"
#include "registers.h"

// Writes the horizontal and vertical offset word to the BG0 offset register of the main engine.
void G2Bg0OfsWrite(u32 offset) {
    reg_G2_BG0OFS = offset;
}
