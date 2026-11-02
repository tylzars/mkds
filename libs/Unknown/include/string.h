#pragma once

// memset lives here, with a size_t size, so that the compiler treats it as the standard function: it then writes
// small memset(p, 0, n) calls out inline as stores or a byte loop.
typedef unsigned long size_t;

void *memset(void *p, int c, size_t n);
