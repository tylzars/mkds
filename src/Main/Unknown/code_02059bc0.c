#include "Main/Unknown/code_02059bc0.h"

#include "Main/Unknown/code_0202a5a0.h"
#include "Main/Unknown/code_02036820.h"
#include "fs_file.h"
#include "Main/Unknown/code_0202a000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_0205a000.h"
#include "Main/Unknown/code_0205a4e8.h"
#include "Main/Unknown/code_0205a534.h"
#include "Main/Unknown/code_0205a50c.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/unk_00000000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_02180000.h"
#include "02/unk_02180500.h"
#include "code_02003be0.h"
#include "code_02004dc0.h"
#include "code_020176c0.h"
#include "frameheap.h"

static inline void func_0205a140_inline(s32 entryIndex, s32 overlayId, u32 startAddress, u32 endAddress) {
    OverlayLoaderEntry *entry;

    entry = &data_0217aa10->mEntries[entryIndex];
    entry->mOverlayId = overlayId;
    entry->mStart = startAddress;
    entry->mEnd = endAddress;
    if (entry->mStart < data_0217aa10->mLowestStart) {
        data_0217aa10->mLowestStart = entry->mStart;
    }
    if (entry->mEnd > data_0217aa10->mHighestEnd) {
        data_0217aa10->mHighestEnd = entry->mEnd;
    }
}

void func_0205a4b0(Unk0217aa14_104_68 *a, s32 b) {
    s32 t;

    a->mUnk_0e = 0;
    t = data_0217aa14->mUnk_728;
    a->mUnk_0c = 2;
    a->mUnk_00 = b;
    a->mUnk_08 = t + 0x78;
    a->mUnk_04 = 0x13;
}

void func_0205a350(void) {
    u8 i;
    Unk0217aa14_104_68 *p;
    s32 d;
    Unk0217aa14_104_20 *h;

    for (i = 0; i < 4; i++) {
        if (func_0205a50c(i) != 0) {
            p = &data_0217aa14->mUnk_104[i].mUnk_68_view;
            h = func_0205a4e8(i, i);
            switch (p->mUnk_0c) {
                case 0:
                    if (h->mUnk_00_12 == 2) {
                        func_0205a71c(i);
                        func_0205a4b0(p, h->mUnk_00_7);
                    }
                    break;
                case 2:
                    d = p->mUnk_08 - data_0217aa14->mUnk_728;
                    if ((s32) p->mUnk_0e < 100) {
                        func_0205a7dc(i, d, p->mUnk_00, 2);
                        p->mUnk_0e = p->mUnk_0e + 1;
                    } else if (d > 20) {
                        func_0205a7dc(i, d, p->mUnk_00, 2);
                    } else {
                        func_0205a7ac(i);
                        if (d <= 0) {
                            p->mUnk_0c = 3;
                        }
                    }
                    break;
                case 3:
                    func_0205a534(p);
                    break;
                case 4:
                    if (h->mUnk_00_12 != 2) {
                        p->mUnk_0c = 0;
                    }
                    break;
            }
        }
    }
}

s32 func_0205a310(s32 a) {
    BOOL r;
    Unk0217aa14_104 *e;

    e = &data_0217aa14->mUnk_104[a];
    r = FALSE;
    if ((u16) (e->mUnk_74 + 0xffff) <= 1) {
        r = TRUE;
    }
    return r;
}

s32 func_0205a2ac(s32 a) {
    s32 r;
    BOOL f;

    r = 0x13;
    f = FALSE;
    if ((u16) (data_0217aa14->mUnk_104[a].mUnk_74 + 0xffff) <= 1) {
        f = TRUE;
    }
    if (f == FALSE) {
        r = data_0217aa14->mUnk_104[a].mUnk_68;
    }
    return r;
}

// Allocates the overlay record and fills the table of the three overlays and the address range they cover.
void InitOverlayTable(void *heap) {
    data_0217aa10 = HeapAlloc(heap, 0xb0);
    data_0217aa10->mLowestStart = -1;
    data_0217aa10->mHighestEnd = 0;
    func_0205a140_inline(0, (s32) SDK_OVERLAY_OV000_ID, (u32) OV000_TEXT_START, (u32) OV000_BSS_END);
    func_0205a140_inline(1, (s32) SDK_OVERLAY_OV001_ID, (u32) OV001_TEXT_START, (u32) OV001_BSS_END);
    func_0205a140_inline(2, (s32) SDK_OVERLAY_OV002_ID, (u32) OV002_CTOR_START, (u32) OV002_BSS_END);
    data_0217aa10->mFrmHeap = NULL;
    data_0217aa10->mExpHeap = NULL;
}

// Creates the frame heap in a fixed 0x50000-byte buffer.
void CreateOverlayFrmHeap(void) {
    data_0217aa10->mFrmHeap = NNS_FndCreateFrmHeapEx(data_ov002_02180500, 0x50000, 0);
}

// Marks no overlay as current: index 4 is past the three table entries.
void ResetCurrentOverlay(void) {
    data_0217aa10->mCurrentOverlay = 4;
    data_0217aa10->mLoadState = 0;
}

// Starts loading the overlay: nothing while a load runs; a loaded overlay is unloaded first.
void StartLoadOverlay(s32 overlay) {
    OverlayLoader *loader;
    s32 current;
    s32 state;

    loader = data_0217aa10;
    current = loader->mCurrentOverlay;
    if (current == overlay) {
        return;
    }
    state = loader->mLoadState;
    switch (state) {
        case 0:
            FS_LoadOverlayInfo(&loader->mInfo, 0, loader->mEntries[overlay].mOverlayId);
            FS_InitFile(&data_0217aa10->mFile);
            FS_LoadOverlayImageAsync(&data_0217aa10->mInfo, &data_0217aa10->mFile);
            data_0217aa10->mLoadState = 1;
            data_0217aa10->mCurrentOverlay = overlay;
            break;
        case 1:
            break;
        case 2:
            switch (state) {
                case 1:
                case 2:
                    if (FS_UnloadOverlay(0, loader->mEntries[current].mOverlayId) != 0) {
                        data_0217aa10->mCurrentOverlay = 4;
                        data_0217aa10->mLoadState = 0;
                        if (data_0217aa10->mExpHeap != NULL) {
                            NNS_FndDestroyExpHeap(data_0217aa10->mExpHeap);
                            data_0217aa10->mExpHeap = NULL;
                        }
                    }
                    break;
            }
            FS_LoadOverlayInfo(&data_0217aa10->mInfo, 0, data_0217aa10->mEntries[overlay].mOverlayId);
            FS_InitFile(&data_0217aa10->mFile);
            FS_LoadOverlayImageAsync(&data_0217aa10->mInfo, &data_0217aa10->mFile);
            data_0217aa10->mLoadState = 1;
            data_0217aa10->mCurrentOverlay = overlay;
            break;
        case 3:
            switch (state) {
                case 1:
                case 2:
                    if (FS_UnloadOverlay(0, loader->mEntries[current].mOverlayId) != 0) {
                        data_0217aa10->mCurrentOverlay = 4;
                        data_0217aa10->mLoadState = 0;
                        if (data_0217aa10->mExpHeap != NULL) {
                            NNS_FndDestroyExpHeap(data_0217aa10->mExpHeap);
                            data_0217aa10->mExpHeap = NULL;
                        }
                    }
                    break;
            }
            FS_LoadOverlayInfo(&data_0217aa10->mInfo, 0, data_0217aa10->mEntries[overlay].mOverlayId);
            FS_InitFile(&data_0217aa10->mFile);
            FS_LoadOverlayImageAsync(&data_0217aa10->mInfo, &data_0217aa10->mFile);
            data_0217aa10->mLoadState = 1;
            data_0217aa10->mCurrentOverlay = overlay;
            break;
    }
}

// Waits in a loop for the read to end, then starts the overlay and closes the file.
void FinishOverlayLoad(void) {
    BOOL finished;
    s32 loadState;

    do {
        finished = FALSE;
        loadState = data_0217aa10->mLoadState;
        if (loadState == 2) {
            finished = TRUE;
        } else if (loadState == 1) {
            if (((data_0217aa10->mFile.mStat & 1) ? 1 : 0) == 0) {
                FS_StartOverlay(&data_0217aa10->mInfo);
                FS_CloseFile(&data_0217aa10->mFile);
                data_0217aa10->mLoadState = 2;
                finished = TRUE;
            }
        }
    } while (finished == FALSE);
}

// Creates the expandable heap only while overlay 1 is the current one.
void CreateOverlayExpHeap(void) {
    if (data_0217aa10->mCurrentOverlay != 1) {
        return;
    }
    data_0217aa10->mExpHeap = NNS_FndCreateExpHeapEx(data_ov002_021a9c00, 0x20800, 1);
}

void FreeOverlayExpHeap(void) {
    if (data_0217aa10->mExpHeap == NULL) {
        return;
    }
    NNS_FndDestroyExpHeap(data_0217aa10->mExpHeap);
    data_0217aa10->mExpHeap = NULL;
}

// Same finish as the wait loop without waiting: returns 1 when the overlay is loaded, else 0.
s32 TryFinishOverlayLoad(void) {
    enum { K0 } r;
    s32 state;
    OverlayLoader *loader;

    r = 0;
    loader = data_0217aa10;
    state = loader->mLoadState;
    if (state == 2) {
        return 1;
    }
    if (state != 1) {
        return r;
    }
    if (loader->mFile.mStat & 1) {
        state = 1;
    } else {
        state = r;
    }
    if (state != 0) {
        return r;
    }
    FS_StartOverlay(&loader->mInfo);
    FS_CloseFile(&data_0217aa10->mFile);
    data_0217aa10->mLoadState = 2;
    return 1;
}

void ReleaseCurrentOverlay(void) {
    if (data_0217aa10->mLoadState != 1 && data_0217aa10->mLoadState != 2) {
        return;
    }
    if (FS_UnloadOverlay(0, data_0217aa10->mEntries[data_0217aa10->mCurrentOverlay].mOverlayId) == 0) {
        return;
    }
    data_0217aa10->mCurrentOverlay = 4;
    data_0217aa10->mLoadState = 0;
    if (data_0217aa10->mExpHeap != NULL) {
        NNS_FndDestroyExpHeap(data_0217aa10->mExpHeap);
        data_0217aa10->mExpHeap = NULL;
    }
}

// 1 when the address lies between the lowest start and the highest end of the three overlays.
u32 IsInOverlayRange(struct MapObjectKindDescriptor *address) {
    u32 inRange;

    inRange = 0;
    if ((u32) address >= data_0217aa10->mLowestStart) {
        if ((u32) address <= data_0217aa10->mHighestEnd) {
            inRange = 1;
        }
    }
    return inRange;
}

void InitResultScene(void) {
    InitResultsByMode(GetHeap(GetCurrentHeapCall()));
}

void ReleaseResultScene(void) {
    u32 value12;
    func_0202a5d8();
}

void func_02059bcc(void) {
    u32 value12;
    func_0202a5a0();
}

void UpdateResultScene(u32 arg0) {
    u32 value0 = arg0;
    u32 value12;
    AdvanceResultsByMode(value0);
}
