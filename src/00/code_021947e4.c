#include "00/code_021947e4.h"

u32 GpiIsProfileEmpty(GpiProfile *a) {
    if (a != NULL && a->mUnk_0c == 0 && a->mBuddyStatus == NULL && a->mUnk_18 == NULL && a->mUnk_10 == NULL) {
        return 1;
    }
    return 0;
}
