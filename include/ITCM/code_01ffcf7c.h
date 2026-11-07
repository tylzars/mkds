#pragma once

#include "types.h"

struct KartAi;

// Writes to b the quaternion a scaled to length 1 (0x1000); no test for a zero quaternion.
void QuaternionNormalize(const Vec4 *a, Vec4 *b);
// Writes the quaternion built from the cross and dot products of b and c to a; returns FALSE (identity written) when
// they point opposite ways.
s32 TryQuaternionFromVectors(Vec4 *a, const Vec3 *b, const Vec3 *c);
// Writes to c the quaternion of a rotation about the axis a by the angle b (0x10000 per turn): a scaled by the sine of
// half the angle in x, y, z and the cosine of half the angle in w.
void QuaternionFromAxisAngle(const Vec3 *a, s32 b, Vec4 *c);
// Adds to the heading of the CPU Kart (three ways; returns at once in some states) and sets mUnk_48 bit 8 or 0x10.
void AdvanceKartAiHeading(struct KartAi *p, Vec3 *a, Vec3 *b);
// Squared x and z distance to the camera ORed with the view test bits, checking two frustum planes.
s32 ComputeTwoPlaneViewTest(Vec3 *a, s32 b, s32 c, s32 d, u16 e);
// Same as ComputeTwoPlaneViewTest but checks the near plane and four more frustum planes.
s32 ComputeViewTest(Vec3 *a, s32 b, s32 c, s32 d, u16 e);
// Lists the slots overlapping slot a whose flags match mask b (at most 0x80) in the result arrays and count.
void FindCollisionSlotsOverlappingSlot(s32 a, s32 b);
// Refreshes the bounds of every slot from its position and radius, then re-sorts both end lists.
void UpdateCollisionSlotBounds(void);
