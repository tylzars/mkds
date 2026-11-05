#include "code_0214578c.h"
#include "code_0200cdf8.h"
#include "code_021458c4.h"

void func_021457cc(u16 a) {
    func_02145a70(a, 1);
    OS_LockCard(a);
}

void func_021457ac(u16 a) {
    OS_UnlockCard(a);
    func_021459cc(a, 1);
}

void func_0214579c(u16 a) {
    func_02145a70(a, 2);
}

void func_0214578c(u16 a) {
    func_021459cc(a, 2);
}
