#pragma once

#include "types.h"

typedef struct Unk02188950 Unk02188950;

void SetCollisionBoxOffsetAndExtentTarget(Unk02188950 *mapObject, int offsetX, u32 offsetY, u32 offsetZ,
                                          u32 offsetPerCall, u32 extentX, u32 extentY, u32 extentZ, u32 extentPerCall);
void SetCollisionBoxOffsetAndExtent(Unk02188950 *mapObject, int offsetX, int offsetY, int offsetZ, u32 extentX,
                                    u32 extentY, u32 extentZ);
void SetShadowOffsetAndScaleTarget(Unk02188950 *mapObject, int offsetX, u32 offsetY, u32 offsetZ, u32 offsetPerCall,
                                   u32 scaleX, u32 g, u32 scaleZ, u32 scalePerCall);
void SetShadowOffsetAndScale(Unk02188950 *mapObject, int offsetX, u32 offsetY, u32 offsetZ, u32 scaleX, u32 f,
                             u32 scaleZ);
void SetCollisionOffsetAndExtentTarget(Unk02188950 *mapObject, u32 offsetY, u32 offsetPerCall, u32 extentXZ,
                                       int extentY, u32 extentPerCall);
void SetCollisionOffsetAndExtent(Unk02188950 *mapObject, s32 offsetY, s32 extentXZ, s32 extentY);
void SetShadowOffsetYAndScaleTarget(Unk02188950 *mapObject, int offsetY, u32 offsetPerCall, u32 scaleXZ,
                                    u32 scalePerCall);
void SetShadowOffsetYAndScale(Unk02188950 *mapObject, s32 offsetY, s32 scaleXZ);
