#include "Main/Unknown/code_02001e54.h"

// Zero fill kept in .text after the last function (as in the original, up to the next file).
#pragma explicit_zero_data on
#pragma define_section MAIN_TEXT ".text"                                                                               \
                                 ".text" abs32 RWX
#pragma section MAIN_TEXT begin

u32 data_02001e54[0x11ac / 4] = {0};

#pragma section MAIN_TEXT end
#pragma explicit_zero_data off
