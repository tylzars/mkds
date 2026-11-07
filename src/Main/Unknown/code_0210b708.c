#include "Main/Unknown/code_0210b708.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"

void func_0210b734(void *request, NNSSndSeqPlayer **handle) {
    u32 firstWord = ((u32 *) request)[0];
    u32 secondWord = ((u32 *) request)[1];
    u32 result = func_0210bcf4(0x0u, firstWord, secondWord, handle, request);
}

void func_0210b708(Unk0210b7a8 *request, NNSSndSeqPlayer **handle) {
    u32 firstWord = (*(u32 *) (((u32) request) + (0)));
    u32 secondWord = (*(u32 *) (((u32) request) + (4)));
    u32 result = func_0210bee8(0x0u, firstWord, secondWord, handle, request);
}
