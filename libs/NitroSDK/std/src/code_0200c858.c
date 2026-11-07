#include "code_0200c858.h"

// Copies up to n - 1 characters of srcp to destp, padding with zeros after the end of srcp, and terminates destp.
void STD_CopyLStringZeroFill(char *destp, const char *srcp, s32 n) {
    s32 i;
    n = n - 1;
    for (i = 0; i < n; i++) {
        destp[i] = *srcp;
        if (*srcp != 0) {
            srcp++;
        }
    }
    destp[i] = 0;
}
