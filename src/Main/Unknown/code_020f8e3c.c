#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02070398.h"

u32 func_020f8e3c(u32 kart, u32 soundId) {
    u32 kartCopy = kart;
    u32 soundIdCopy = soundId;
    u32 flagBit;
    u32 kartCompared;
    u32 zero;
    u32 flagBitCompared;
    u32 zeroAgain;
    kartCompared = kartCopy;
    zero = 0u;
    if (kartCompared == zero) {
    }
    if (kartCompared == zero) {
    }
    if (kartCompared == zero) {
        return kartCopy;
    }
    flagBit = *(const u32 *) ((kartCopy) + (124));
    flagBit = (flagBit) & (1u);
    flagBitCompared = flagBit;
    zeroAgain = 0u;
    if (flagBitCompared == zeroAgain) {
    }
    if (flagBitCompared == zeroAgain) {
    }
    if (flagBitCompared == zeroAgain) {
        return kartCopy;
    }
    kartCopy = (u32) func_020719bc((SoundSource *) kartCopy, soundIdCopy);
    return kartCopy;
}
