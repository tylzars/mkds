#pragma once

#include "types.h"
#include "Main/Unknown/code_020f36d8.h"

// Sets up a freshly allocated object once: allocates the 0x1c-byte record behind mUnk_104, builds the model entry of
// the kind and releases it again.
void InitItemObject(ItemObject *a, u32 b, int c);
