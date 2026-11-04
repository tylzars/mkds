#include "code_0214e1e0.h"
#include "code_0214e274.h"
#include "code_0214e258.h"

// Returns DateToDays(a) * 86400 + TimeToSeconds(b), or -1 when either returns -1.
s64 DateTimeToSeconds(const Unk0214e1e0 *a, const Unk0214e1e0 *b) {
    s32 x;
    s32 y;

    x = DateToDays(a);
    if (x == -1) {
        return -1;
    }
    y = TimeToSeconds(b);
    if (y == -1) {
        return -1;
    }
    return (s64) x * 86400 + y;
}
