#include "code_0214578c.h"
#include "code_0200cdf8.h"
#include "code_021458c4.h"

void CARD_LockRom(u16 a) {
    LockAccessTarget(a, 1);
    OS_LockCard(a);
}

void CARD_UnlockRom(u16 a) {
    OS_UnlockCard(a);
    UnlockAccessTarget(a, 1);
}

void CARD_LockBackup(u16 a) {
    LockAccessTarget(a, 2);
}

void CARD_UnlockBackup(u16 a) {
    UnlockAccessTarget(a, 2);
}
