#include "Main/Unknown/code_020fcb4c.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020ee684.h"

void func_020fcb4c(ItemInUse *a, HeldItem *rec) {
    StartHeldItemTimer(rec, 0x1c2);
    func_02069db8(rec->mKartItems->mKart);
    a->mKartItems->mUnk_204 = TRUE;
    func_020f4188(rec, 0xc);
}
