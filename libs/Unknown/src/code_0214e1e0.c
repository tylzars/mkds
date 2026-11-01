#include "code_0214e1e0.h"
#include "code_0214e274.h"
#include "code_0214e258.h"

// Returns func_0214e274(a) * 86400 + func_0214e258(b), or -1 when either returns -1.
s64 func_0214e1e0(const Unk0214e1e0 *a, const Unk0214e1e0 *b) {
    s32 x;
    s32 y;

    x = func_0214e274(a);
    if (x == -1) {
        return -1;
    }
    y = func_0214e258(b);
    if (y == -1) {
        return -1;
    }
    return (s64) x * 86400 + y;
}
