#pragma once

#include "types.h"
#include "Main/Unknown/code_020a2e4c.h" // Balloon

void func_020a2f30(Balloon *balloon, u16 kartIndex, s32 scaleStep);
void func_020a2f9c(Balloon *balloon, u16 kartIndex, s32 scaleStep);
Balloon *StartBalloon(u16 nsbtpFrameIndex, Vec3 *targetPos);
void func_020a305c(void);
void *CreateBalloonUpdateList(void);
void *CreateBalloonDrawList(void);
void UpdateBalloon(void *mapObjectList,
                   Balloon *balloon); /* skipped for objects with mFlags & 4 (parked pool objects) */
void UpdateBalloonAngle(Balloon *balloon);
