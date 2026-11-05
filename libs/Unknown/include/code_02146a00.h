#pragma once

#include "types.h"

// Tag 11 callback: returns when the tag is not 11 or the third argument is 0; otherwise clears value 0x20 of the flag
// word and makes the thread at +0x104 runnable.
void ReceiveRequestReply(u32 arg0, u32 arg1, u32 arg2);
