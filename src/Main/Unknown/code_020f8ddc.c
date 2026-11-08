#include "Main/Unknown/code_020f8ddc.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020f36d8.h"

#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020f6be8.h"

void func_020f8ddc(void *itemParam) {
    ItemObject *item = itemParam;

    if (item == NULL) {
        return;
    }
    if (gRaceSetup->mMode != MODE_MISSION_RUN) {
        return;
    }
    if ((u32) item->mKind > 1) {
        return;
    }
    StartEffect(0x441, &item->mPos);
    StartEffect(0x440, &item->mPos);
}
