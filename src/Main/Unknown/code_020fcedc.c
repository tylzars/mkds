#include "Main/Unknown/code_020fcedc.h"
#include "Main/Unknown/code_020fcf10.h"

void SteerItemKouraWAtAngleZero(ItemKouraW *item, u32 gain, u32 maxStep, u32 radius) {
    SteerItemKouraWToAnglePoint(item, maxStep, 0, radius, gain, 7, 3);
}
