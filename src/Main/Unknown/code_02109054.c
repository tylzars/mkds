#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210c1b0.h"
#include "Main/Unknown/unk_0217c000.h"

Unk0210bf24 *func_021090c4(Unk0210bfbc *p, u32 a, u32 b, s16 c) {
    if (!(data_0217c780 & 1)) {
        return NULL;
    }
    return ((Unk0210bf24 * (*) (Unk0210bfbc *, u32, u32, u32, s32)) func_0210c86c)(p, 0, a, b, c);
}

Unk0210bf24 *func_02109078(Unk0210bfbc *p, u32 a, u32 b, s32 c) {
    if (!(data_0217c780 & 1)) {
        return NULL;
    }
    return ((Unk0210bf24 * (*) (Unk0210bfbc *, u32, u32, u32, s32)) func_0210c610)(p, 0, a, b, c);
}

void func_02109060(Unk0210bfbc *p, u32 a) {
    func_0210c558(p, 0, a, 0);
}

void func_02109054(Unk0210bfbc *p) {
    func_0210c1b0(p);
}
