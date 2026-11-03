#include "Main/Unknown/code_02099278.h"
#include "Main/Unknown/code_020d22e0.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/unk_02156000.h"

void func_02099278(u32 p0) {
    u32 v1 = ((u32) (&data_02156598));
    u32 v3 = ((u32) * (u16 *) ((p0) + (2)));
    u32 v4 = ((u32) * (u16 *) ((v1) + (0)));
    u32 v5 = ((v3) | (v4));
    u32 v7;
    u32 v9;
    *(u16 *) ((p0) + (2)) = (u16) v5;
    func_020d2398((void *) (p0));
    func_020d28e0((MapObject *) p0);
}
