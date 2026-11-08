#pragma once

#include "types.h"

typedef struct Kart Kart;

void CollideKartWithMapObjects(Kart *kart);
void func_0206edac(Kart *kart, Vec3 *groundNormal);
