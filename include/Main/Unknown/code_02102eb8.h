#pragma once

#include "types.h"

typedef struct ItemGesso ItemGesso;

unsigned int SetupItemGesso();
BOOL SetupNextItemGessoStep(ItemGesso *gesso);
void ResetItemGesso(ItemGesso *gesso);
