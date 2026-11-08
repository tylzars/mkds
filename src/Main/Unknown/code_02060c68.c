#include "Main/Unknown/code_02060c68.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/unk_0217a000.h"

// Stores the session player in the buddy records; the second argument allows adding a new record.
s32 SetBuddyRecordFromPlayer(Unk0217aa00_45c *player, u32 addIfMissing) {
    u32 flag = (*(u8 *) (((u32) player) + (532)));
    u32 blocksPointerAddress = ((u32) (&data_0217aa08));
    u32 friendDataOffset = 0x874u;
    u32 blocks = (*(u32 *) ((blocksPointerAddress) + (0)));
    u32 buddyBlock = (*(u32 *) ((blocks) + (32)));
    s32 *friendData = &player->mUnk_218;
    u32 friendTable = ((buddyBlock) + (friendDataOffset));
    u32 slot = AddOrUpdateBuddyRecord((u8 *) friendTable, player, (u8 *) friendData, 0x0u, flag, addIfMissing);
    return slot;
}
