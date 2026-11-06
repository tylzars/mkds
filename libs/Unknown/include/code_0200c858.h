#pragma once

#include "types.h"

// Copies up to n - 1 characters of srcp to destp, padding with zeros after the end of srcp, and terminates destp.
void STD_CopyLStringZeroFill(char *destp, const char *srcp, s32 n);
