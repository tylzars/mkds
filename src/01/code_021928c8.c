#include "01/code_021928c8.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "01/code_02188158.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_0209b000.h"
#include "01/code_02192000.h"
#include "Main/Unknown/code_0209bef0.h"

EmblemInput *gEmblemInput;

void CreateEmblemInput(void) {
    gEmblemInput = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x54);
}

void AdvanceEmblemInput(void) {
    InputSlotIndex idx;
    BOOL f1;
    int f0;
    u16 v;
    u16 t;
    s32 n;

    gEmblemInput->mPrevX = gEmblemInput->mX;
    gEmblemInput->mPrevY = gEmblemInput->mY;
    gEmblemInput->mPrevPressed = gEmblemInput->mPressed;
    gEmblemInput->mPrevDown = gEmblemInput->mDown;
    gEmblemInput->mPrevReleased = gEmblemInput->mReleased;
    if (gEmblemInput->mDown == 0 && data_02175928[0x14] != 0 && data_02175928[0x15] != 0) {
        gEmblemInput->mPressed = 1;
    } else {
        gEmblemInput->mPressed = 0;
    }
    if (gEmblemInput->mDown != 0 && data_02175928[0x14] == 0 && data_02175928[0x15] == 0) {
        gEmblemInput->mReleased = 1;
    } else {
        gEmblemInput->mReleased = 0;
    }
    idx = UNK_02175628_INDEX_8;
    f1 = TRUE;
    f0 = 0;
    v = data_02175628[idx].mHasPair;
    if (v == 0 && data_02175628[idx].mNoPairCount < 5) {
        f0 = f1;
    }
    if (f0 == 0 && v == 0) {
        f1 = FALSE;
    }
    if (f1 != FALSE && (v = data_02175928[0x14]) != 0 && data_02175928[0x15] != 0) {
        gEmblemInput->mX = v;
        gEmblemInput->mY = data_02175928[0x15];
        gEmblemInput->mDown = 1;
    } else {
        gEmblemInput->mDown = 0;
    }
    if (gEmblemInput->mDown != 0 && gEmblemInput->mX <= gEmblemInput->mPrevX + 1 &&
        gEmblemInput->mX >= gEmblemInput->mPrevX - 1 && gEmblemInput->mY <= gEmblemInput->mPrevY + 1 &&
        gEmblemInput->mY >= gEmblemInput->mPrevY - 1) {
        gEmblemInput->mStillCallCount++;
        if (gEmblemInput->mStillCallCount > 0x3c) {
            gEmblemInput->mStillCallCount = 0;
            gEmblemInput->mPressed = 1;
            gEmblemInput->mReleased = 1;
        }
    } else {
        gEmblemInput->mStillCallCount = 0;
    }
    t = data_021758e8[0x11] & 0x20;
    if (t == 0) {
        n = 0;
    } else {
        n = gEmblemInput->mBit5HeldCount + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    gEmblemInput->mBit5HeldCount = n;
    t = data_021758e8[0x11] & 0x10;
    if (t == 0) {
        n = 0;
    } else {
        n = gEmblemInput->mBit4HeldCount + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    gEmblemInput->mBit4HeldCount = n;
    t = data_021758e8[0x11] & 0x40;
    if (t == 0) {
        n = 0;
    } else {
        n = gEmblemInput->mBit6HeldCount + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    gEmblemInput->mBit6HeldCount = n;
    t = data_021758e8[0x11] & 0x80;
    if (t == 0) {
        n = 0;
    } else {
        n = gEmblemInput->mBit7HeldCount + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    gEmblemInput->mBit7HeldCount = n;
    t = data_021758e8[0x11] & 0x1;
    if (t == 0) {
        n = 0;
    } else {
        n = gEmblemInput->mBit0HeldCount + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    gEmblemInput->mBit0HeldCount = n;
    t = data_021758e8[0x11] & 0x2;
    if (t == 0) {
        n = 0;
    } else {
        n = gEmblemInput->mBit1HeldCount + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    gEmblemInput->mBit1HeldCount = n;
    t = data_021758e8[0x11] & 0x400;
    if (t == 0) {
        n = 0;
    } else {
        n = gEmblemInput->mBit10HeldCount + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    gEmblemInput->mBit10HeldCount = n;
    t = data_021758e8[0x11] & 0x800;
    if (t == 0) {
        n = 0;
    } else {
        n = gEmblemInput->mBit11HeldCount + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    gEmblemInput->mBit11HeldCount = n;
    t = data_021758e8[0x11] & 0x200;
    if (t == 0) {
        n = 0;
    } else {
        n = gEmblemInput->mBit9HeldCount + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    gEmblemInput->mBit9HeldCount = n;
    t = data_021758e8[0x11] & 0x100;
    if (t == 0) {
        n = 0;
    } else {
        n = gEmblemInput->mBit8HeldCount + 1;
        if (n >= 0x11) {
            n = 0xf;
        }
    }
    gEmblemInput->mBit8HeldCount = n;
}

s32 GetEmblemInputX(void) {
    return gEmblemInput->mX;
}

u32 GetEmblemInputY(void) {
    return gEmblemInput->mY;
}

u32 GetEmblemInputPressed(void) {
    return gEmblemInput->mPressed;
}

u32 GetEmblemInputDown(void) {
    return gEmblemInput->mDown;
}

u32 GetEmblemInputPrevX(void) {
    return gEmblemInput->mPrevX;
}

u32 GetEmblemInputPrevY(void) {
    return gEmblemInput->mPrevY;
}

u32 GetEmblemInputPrevDown(void) {
    return gEmblemInput->mPrevDown;
}

u16 func_ov001_02192a14(u16 a) {
    return data_021758e8[0x10] & a;
}

u16 func_ov001_02192a04(u16 a) {
    return data_021758e8[0x11] & a;
}

BOOL IsEmblemInputRepeat(int a) {
    switch (a) {
        case 0x20:
            return gEmblemInput->mBit5HeldCount == 1 || gEmblemInput->mBit5HeldCount == 0xf;
        case 0x10:
            return gEmblemInput->mBit4HeldCount == 1 || gEmblemInput->mBit4HeldCount == 0xf;
        case 0x40:
            return gEmblemInput->mBit6HeldCount == 1 || gEmblemInput->mBit6HeldCount == 0xf;
        case 0x80:
            return gEmblemInput->mBit7HeldCount == 1 || gEmblemInput->mBit7HeldCount == 0xf;
        case 1:
            return gEmblemInput->mBit0HeldCount == 1 || gEmblemInput->mBit0HeldCount == 0xf;
        case 2:
            return gEmblemInput->mBit1HeldCount == 1 || gEmblemInput->mBit1HeldCount == 0xf;
        case 0x400:
            return gEmblemInput->mBit10HeldCount == 1 || gEmblemInput->mBit10HeldCount == 0xf;
        case 0x800:
            return gEmblemInput->mBit11HeldCount == 1 || gEmblemInput->mBit11HeldCount == 0xf;
        case 0x200:
            return gEmblemInput->mBit9HeldCount == 1 || gEmblemInput->mBit9HeldCount == 0xf;
        case 0x100:
            return gEmblemInput->mBit8HeldCount == 1 || gEmblemInput->mBit8HeldCount == 0xf;
    }
    return FALSE;
}
