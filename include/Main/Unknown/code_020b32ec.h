#pragma once

#include "types.h"

typedef struct Ncgr Ncgr;
typedef struct Nclr Nclr;

unsigned int IsChoisesSPickLocked(void);
void *GetChoisesSListScreenMapData(void);
Ncgr *GetChoisesSBNcgrWithListChars(void);
Nclr *GetChoisesSBNclr(void);
