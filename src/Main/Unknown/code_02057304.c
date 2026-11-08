#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_02057498.h"
#include "Main/Unknown/code_02090000.h"
#include "Main/Unknown/code_02090354.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"
#include "code_02152500.h"

#pragma thumb on

void SetBitArrayBit(s32 bitIndex, u8 *bytes, s32 c) {
    u8 *bitArrayByte;

    bitArrayByte = GetBitArrayByte(bitIndex, bytes);
    *bitArrayByte |= 1 << (u8) (bitIndex % 8);
}

BOOL IsBitArrayBitSet(s32 bitIndex, u8 *bytes, s32 c) {
    u8 *bitArrayByte;

    bitArrayByte = GetBitArrayByte(bitIndex, bytes);
    return (*bitArrayByte & (1 << (u8) (bitIndex % 8))) != 0 ? 1 : 0;
}

void ClearBitArrayBit(s32 bitIndex, u8 *bytes, s32 c) {
    u8 *bitArrayByte;

    bitArrayByte = GetBitArrayByte(bitIndex, bytes);
    *bitArrayByte &= ~(1 << (u8) (bitIndex % 8));
}

BOOL IsCourseGhostBitSet(u8 bitIndex) {
    return IsBitArrayBitSet(bitIndex, data_0217aa08->mFirstBlock->mCourseGhostBits, 4);
}

void ClearCourseGhostBit(s32 bitIndex) {
    ClearBitArrayBit(bitIndex, data_0217aa08->mFirstBlock->mCourseGhostBits, 4);
}

BOOL IsSlotGhostBitSet(u32 bitIndex) {
    return IsBitArrayBitSet(bitIndex, data_0217aa08->mFirstBlock->mSlotGhostBits, 2);
}

void ResetBackupFirstBlock(s32 copyOwnerName) {
    u16 ownerCharCount;
    u8 *ownerText;

    MI_CpuFill8(data_0217aa08->mFirstBlock, 0, 0x100);
    if (copyOwnerName != 0) {
        ownerCharCount = data_021759d0->mOwnerCharCount;
        ownerText = data_021759d0->mOwnerText;
        data_0217aa08->mFirstBlock->mUnk_31_0 = 1;
        MI_CpuFill8(data_0217aa08->mFirstBlock->mPlayerName, 0, 0x14);
        MI_CpuCopy8(ownerText, data_0217aa08->mFirstBlock->mPlayerName, ((u32) ownerCharCount << 17) >> 16);
    }
    data_0217aa08->mFirstBlock->mSoundMode = SOUND_MODE_SURROUND;
    data_0217aa08->mFirstBlock->mUnk_31_3 = 0;
    data_0217aa08->mFirstBlock->mLocateFriendOff = 0;
    data_0217aa08->mFirstBlock->mElo = 0x1388;
    func_0209119c();
    DWC_CreateUserData((DWCAccUserData *) data_0217aa08->mFirstBlock->mUserData, 0x414d434a);
}

#pragma thumb off
