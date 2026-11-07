#include "Main/Unknown/code_020c2118.h"
#include "Main/Unknown/code_020c214c.h"

void func_020c2118(Unk020c06c4 *a) {
    int state;
    state = GetRaceHudSubScreenState();
    if (state != 5) {
        func_020c28dc(a);
        return;
    }
    func_020c214c(a);
}
