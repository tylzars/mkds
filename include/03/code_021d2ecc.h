#pragma once

#include "types.h"
#include "03/code_021d1770.h" // OamEntry

void *CreateNodeList(void);
OamEntry *GetOamBufferEntry(int screen, int index);
void DeleteOamEntry(u32 *entry);
OamEntry *CreateOamEntry(int screen, u8 *source);
void ReleaseOamBuffers(void);
