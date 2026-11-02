#include "code_0213c9e8.h"
#include "code_02134d30.h"

void *wmemcpy(u16 *dst, const u16 *src, u32 n) {
    return memcpy(dst, src, n * 2);
}
