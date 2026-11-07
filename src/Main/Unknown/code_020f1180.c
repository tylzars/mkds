#include "Main/Unknown/code_020f1180.h"

#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f1258.h"

BOOL TrySetItemKouraRNearestKartItems(ItemKouraR *item, u32 checkRank) {
    u16 kartIndex;
    u32 nearestDistanceSquared;
    u32 kartCount;
    int distanceSquared;

    nearestDistanceSquared = 0;
    kartCount = gRaceSetup->mKartCount;
    for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
        distanceSquared = TrySetItemKouraRKartItems(item, kartIndex, nearestDistanceSquared, checkRank);
        if (distanceSquared != 0) {
            nearestDistanceSquared = distanceSquared;
        }
    }
    return nearestDistanceSquared != 0;
}
