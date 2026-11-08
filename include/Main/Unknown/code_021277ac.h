#pragma once

#include "types.h"

s32 IsSelectChoisesState0NoState1Request(void);
u32 IsSelectChoisesState1NoState0Request(void);
void RequestSelectChoisesState0(void);
void StartSelectChoises(void *firstText, void *secondText, s32 startOnSecond);
void RequestSelectChoisesState1(void);
void WriteSelectChoisesRegisters(void);
void AdvanceSelectChoises(void);
