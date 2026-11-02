#include "00/code_02194828.h"

BOOL func_ov000_02194828(void *unused, Unk02194828 *entry, Unk02194828Search *search) {
    if (entry->mValue != NULL && search->mKey == *entry->mValue) {
        search->mEntry = entry;
        return FALSE;
    }
    return TRUE;
}
