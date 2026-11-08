#pragma once

#include "types.h"
#include "Main/Unknown/code_0207ffa4.h"

void SetRequestedLinkToPreviousIfNone(LinkCursor *linkCursor);
void ResetBattlePointLinkCursorNear(LinkCursor *linkCursor, Vec3 *position, Vec3 *direction, u16 c);
void ResetBattlePointLinkCursorTo(LinkCursor *linkCursor, PointLink *pointLink);
