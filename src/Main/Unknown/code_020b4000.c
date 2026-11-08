#include "Main/Unknown/code_020b4000.h"

#pragma thumb on
Unk02022aa8 *GetFontByIndex(s32 index) {
    u32 value0 = index;
    u32 byteOffset;
    byteOffset = (value0 << 2);
    value0 = (u32) &gFontTable;
    value0 = *(const u32 *) ((value0) + (byteOffset));
    return (void *) value0;
}
#pragma thumb off

#pragma thumb on
void *GetPlayerCharacterNclr(int index) {
    u32 value0 = index;
    u32 byteOffset;
    byteOffset = (value0 << 2);
    value0 = (u32) &gPlayerCharacterNclr;
    value0 = *(const u32 *) ((value0) + (byteOffset));
    return (void *) value0;
}
#pragma thumb off

#pragma thumb on
Nclr *GetPlayerCharacterShyguyNclr(u32 index) {
    u32 value0 = (u32) index;
    u32 byteOffset;
    byteOffset = (value0 << 2);
    value0 = (u32) &gPlayerCharacterShyguyNclr;
    value0 = *(const u32 *) ((value0) + (byteOffset));
    return (void *) value0;
}
#pragma thumb off

#pragma thumb on
Ncgr *GetPlayerCharacterNcgr(int index) {
    u32 value0 = index;
    u32 byteOffset;
    byteOffset = (value0 << 2);
    value0 = (u32) &gPlayerCharacterNcgr;
    value0 = *(const u32 *) ((value0) + (byteOffset));
    return (void *) value0;
}
#pragma thumb off

#pragma thumb on
Unk02021dc8 *GetPlayerCharacterNcer(int index) {
    u32 value0 = index;
    u32 byteOffset;
    byteOffset = (value0 << 2);
    value0 = (u32) &gPlayerCharacterNcer;
    value0 = *(const u32 *) ((value0) + (byteOffset));
    return (void *) value0;
}
#pragma thumb off

#pragma thumb on
void *GetPlayerCharacterBncl(int index) {
    u32 value0 = index;
    u32 byteOffset;
    byteOffset = (value0 << 2);
    value0 = (u32) &gPlayerCharacterBncl;
    value0 = *(const u32 *) ((value0) + (byteOffset));
    return (void *) value0;
}
#pragma thumb off
