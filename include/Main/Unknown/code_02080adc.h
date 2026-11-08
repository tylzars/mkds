#pragma once

#include "types.h"

typedef struct LinkCursor LinkCursor;
typedef struct PointLink PointLink;

void AdvancePointLinkCursorTo(LinkCursor *p, PointLink *a);
