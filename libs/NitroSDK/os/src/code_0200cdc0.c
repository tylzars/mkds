#include "code_0200cdc0.h"
#include "code_0200ce60.h"

u16 OS_ReadOwnerOfLockWord(OSLockWord *lockp) {
    return lockp->mOwnerID;
}
