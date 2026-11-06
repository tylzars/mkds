#include "code_021507c8.h"

// Starts an MD5 context: the four initial state words and a zero byte count.
void DGT_Hash1Reset(DGTHash1Context *ctx) {
    ctx->mState[0] = 0x67452301;
    ctx->mState[1] = 0xefcdab89;
    ctx->mState[2] = 0x98badcfe;
    ctx->mState[3] = 0x10325476;
    ctx->mLength = 0;
}
