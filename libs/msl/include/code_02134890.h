#pragma once

#include "types.h"
#include "code_02134398.h"

u32 fwrite(const char *a, u32 b, u32 c, FILE *d);
int fflush(FILE *a);
double LdexpViaFrexp(double a, int n);
