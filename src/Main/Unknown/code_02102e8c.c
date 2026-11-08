#include "Main/Unknown/code_02102e8c.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_02102eb8.h"

u32 InitItemGesso(u32 itemInUse, u32 gesso) {
    u32 kart = (*(u32 *) ((itemInUse) + (16)));
    u32 v4 = SetupItemGesso(gesso, 0x0u);
    u32 v7 = func_020f8e3c(kart, 0xf2u);
    return 0x1u;
}
