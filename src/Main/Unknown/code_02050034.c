#include "Main/Unknown/code_02050034.h"
#include "Main/Unknown/code_02050000.h"
#include "Main/Unknown/code_02050080.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02057fe4.h"
#include "Main/Unknown/unk_0217a000.h"

u32 GetParticipantIndex(u32 position) {
    return (data_0217aa00->mParticipantIndices[position]);
}

// Also rebuilds the participant index tables, combines the participants' bits and requests the next state.
void SetParticipantMask(u8 mask) {
    u32 value0 = mask;
    data_0217aa00->mParticipantMask = value0;
    func_02050080();
    func_02058b10();
}
