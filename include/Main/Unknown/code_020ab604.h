#pragma once

#include "types.h"

u32 IsKeyboardTouchEnabled(void);
u32 GetKeyboardLastTouchY(void);
u32 GetKeyboardLastTouchX(void);
u32 GetKeyboardTouchStatus(void);
u32 GetKeyboardTouchDown(void);
u32 GetKeyboardKeysDown(u32 mask);
u32 GetKeyboardKeysPressed(u32 mask);
