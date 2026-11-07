#pragma once

#include "types.h"

typedef struct Camera Camera;

// The object behind gCurrentCamera.
typedef Camera Unk02073904;

extern s32 data_usa_021656a4;
extern s32 data_usa_021656a8;
extern s32 data_usa_021656ac;
extern s32 data_usa_021656b0;
extern s32 data_usa_021656b8;
extern s32 data_usa_021656bc;
extern s32 data_usa_021656c8;
extern s32 data_usa_021656cc[];

void UpdateCameraShake(Unk02073904 *p);
