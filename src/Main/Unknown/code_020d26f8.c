#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_02109054.h"

u32 func_020d26f8(MapObject *a, Unk0206bcb0 *b) {
    if (b->mUnk_29c != 1 && b->mUnk_29c != 3) {
        return 0;
    }
    if (a->mUnk_94 != NULL) {
        func_021090c4(&a->mUnk_94->mUnk_00, 0xe8, 0x7f, 0);
    } else {
        func_020719bc(&b->mUnk_00, 0xe8);
    }
    return 1;
}
