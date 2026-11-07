#include "Main/Unknown/code_020f11f0.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020f1258.h"
#include "Main/Unknown/unk_021759c0.h"

u32 TrySetItemKouraRKartItemsByFrame(ItemKouraR *item, u32 checkRank) {
    u16 kartIndex;
    int distanceSquared;
    kartIndex = GetRaceUpdateFramesMod8();
    if (((u32) kartIndex < gRaceSetup->mKartCount) &&
        (distanceSquared = TrySetItemKouraRKartItems(item, kartIndex, 0, checkRank), distanceSquared != 0)) {
        return 1;
    }
    return 0;
}
