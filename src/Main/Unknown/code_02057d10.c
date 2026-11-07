#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_020019b0.h"
#include "Main/Unknown/code_02057ed8.h"
#include "Main/Unknown/code_020364e0.h"
#include "os_irqHandler.h"
#include "os_thread.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"

void func_02057e8c(void *a) {
    for (;;) {
        if (data_0217aa0c->mUnk_f8 != 0) {
            void (*f)(void) = func_02057f8c(data_0217aa0c);
            if (f == NULL) {
                data_0217aa0c->mUnk_f8 = 0;
            } else {
                f();
            }
        }
        OS_Sleep(2);
    }
}

u32 func_02057df0(void (*a)(void)) {
    s32 n;
    s32 i;
    Unk0217aa0c *p = data_0217aa0c;
    u8 k;
    void (*f)(void);
    if (p->mUnk_f8 != 0) {
        return 0;
    }
    i = p->mUnk_28;
    n = 0;
    do {
        k = i % 10;
        f = p->mUnk_00[k];
        if (f == NULL) {
            break;
        }
        n++;
        i++;
    } while (n < 10);
    if (f != NULL) {
        return 0;
    }
    p->mUnk_00[k] = a;
    p->mUnk_28 = k;
    return 1;
}

void func_02057d9c(void) {
    while (data_0217aa0c->mUnk_f8 != 0) {
        OS_WaitIrq(1, 1);
    }
}

void func_02057d7c(void) {
    func_02001ba0(GetHeap(func_020364e8()));
}

void func_02057d70(void) {
    ApplySavedSoundMode();
}

void func_02057d64(void) {
    func_02001abc();
}

void func_02057d58(void *a) {
    func_02001a74(a);
}

s32 RunLogoScene(SceneNumbers *a) {
    SceneCallbacks b = data_02165280;

    RunScene(a, &b);
    return 0;
}
