#include "Main/Unknown/code_020815a0.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/unk_0217a000.h"

// Lets the Killer effect end by itself and forgets it.
u32 StopKartKillerEffect(u32 kartIndex) {
    u32 value0 = kartIndex;
    u32 value1;
    u32 value2;
    u32 kartEffects;
    u32 effect;
    u32 zero;
    value2 = (u32) &gKartEffects;
    value1 = 0x58u;
    value2 = *(const u32 *) ((value2) + (0));
    kartEffects = (value0) * (value1) + (value2);
    value2 = *(const u32 *) ((kartEffects) + (44));
    effect = value2;
    zero = 0u;
    if (effect == zero) {
        return value0;
    }
    value1 = *(const u32 *) ((value2) + (36));
    value0 = 0u;
    value1 = (value1) & ~(1u);
    value1 = (value1) | (1u);
    *(u32 *) ((value2) + (36)) = value1;
    *(u32 *) ((kartEffects) + (44)) = value0;
    return value0;
}

void ReleaseKartKillerEffect(u32 kartIndex) {
    u32 value0 = kartIndex;
    u32 recordSize;
    u32 value2;
    u32 kartEffects;
    u32 effect;
    u32 zero;
    value2 = (u32) &gKartEffects;
    recordSize = 0x58u;
    value2 = *(const u32 *) ((value2) + (0));
    kartEffects = (value0) * (recordSize) + (value2);
    value0 = *(const u32 *) ((kartEffects) + (44));
    effect = value0;
    zero = 0u;
    if (effect == zero) {
    }
    if (effect == zero) {
        return;
    }
    DeleteEffect((Unk0201ca6c *) value0);
    value0 = 0u;
    *(u32 *) ((kartEffects) + (44)) = value0;
}
