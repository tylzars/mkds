#include "Main/Unknown/code_020b4000.h"

#pragma thumb on
void *func_020b403c(s32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (value0 << 2);
    value0 = (u32) &gFontTable;
    value0 = (u32) * (const u32 *) ((value0) + (value1));
    return (void *) value0;
}
#pragma thumb off

#pragma thumb on
void *func_020b4030(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (value0 << 2);
    value0 = (u32) &gPlayerCharacterNclr;
    value0 = (u32) * (const u32 *) ((value0) + (value1));
    return (void *) value0;
}
#pragma thumb off

#pragma thumb on
void *func_020b4024(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (value0 << 2);
    value0 = (u32) &gPlayerCharacterShyguyNclr;
    value0 = (u32) * (const u32 *) ((value0) + (value1));
    return (void *) value0;
}
#pragma thumb off

#pragma thumb on
void *func_020b4018(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (value0 << 2);
    value0 = (u32) &gPlayerCharacterNcgr;
    value0 = (u32) * (const u32 *) ((value0) + (value1));
    return (void *) value0;
}
#pragma thumb off

#pragma thumb on
void *func_020b400c(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (value0 << 2);
    value0 = (u32) &gPlayerCharacterNcer;
    value0 = (u32) * (const u32 *) ((value0) + (value1));
    return (void *) value0;
}
#pragma thumb off

#pragma thumb on
void *func_020b4000(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (value0 << 2);
    value0 = (u32) &gPlayerCharacterBncl;
    value0 = (u32) * (const u32 *) ((value0) + (value1));
    return (void *) value0;
}
#pragma thumb off
