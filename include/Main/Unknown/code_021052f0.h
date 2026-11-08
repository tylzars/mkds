#pragma once

#include "types.h"

typedef struct ItemFBox ItemFBox;

typedef struct PooledMapObject PooledMapObject;

void SetPooledMapObjectCallback(PooledMapObject *object, void *callback, ItemFBox *owner);
