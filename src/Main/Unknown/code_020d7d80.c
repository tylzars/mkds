#include "Main/Unknown/code_020d7d80.h"

#pragma thumb on

void SetStraightSegmentLengths(GroupFollower *follower) {
    GroupPath *path;
    int index;
    int segmentCount;
    int byteOffset;
    Segment *segment;
    path = follower->mPath;
    segmentCount = path->mSegmentCount;
    index = 0;
    if (0 < segmentCount) {
        byteOffset = 0;
        do {
            segment = OFFSET_PTR(Segment, path->mSegments, byteOffset);
            segment->mProgressLength = segment->mStraightLength;
            segment->mInverseProgressLength = segment->mInverseStraightLength;
            byteOffset = byteOffset + 0x54;
            index = index + 1;
        } while (index < segmentCount);
    }
}

#pragma thumb off
