#include "Main/Unknown/code_02061540.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057800.h"
#include "01/code_021956dc.h"

void func_02061588(void) {
    u8 i;
    u8 *a;
    GhostRecord *b;

    a = data_0217aa08->mUnk_40;
    for (i = 0; i < 0x20; i++) {
        b = (GhostRecord *) (a + i * 0x30);
        if (func_020573f8(i) != 0) {
            func_0205786c(1, i, b);
            if (data_021759d4->mUnk_0c != 0) {
                CARD_WaitBackupAsync();
            }
            if (data_021759d4->mUnk_04 != NULL) {
                b->mFilled = 0;
            }
        } else {
            b->mFilled = 0;
        }
    }
    data_0217aa08->mUnk_40 = NULL;
    func_02057504();
}

void func_02061540(void *a) {
    data_0217aa08->mUnk_40 = a;
    func_02057514();
    func_02057df0((void (*)(void)) func_02061588);
    data_0217aa0c->mUnk_f8 = 1;
}
