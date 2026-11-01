#include "Main/Unknown/code_02036820.h"
#include "code_020176c0.h"
#include "code_02017f24.h"
#include "code_02017550.h"
#include "code_0200fc8c.h"

void func_02036820(void *a) {
    u32 b = func_02017f24(a);
    func_020177b0(func_02017550(a), a, b);
}

void *func_02036854(void *a, u32 b) {
    Unk02017584 *h = a;
    void *c = 0;
    u32 d;
    switch (h->mUnk_00) {
        case 0x45585048:
            c = func_02017938(a, b, -4);
            break;
        case 0x46524d48:
            d = func_0200fca0();
            c = func_0201808c(a, b, -4);
            func_0200fcb4(d);
            break;
    }
    return func_020180e0(c, b, 1);
}

void *func_020368e0(void *a, u32 b) {
    Unk02017584 *h = a;
    void *c = 0;
    switch (h->mUnk_00) {
        case 0x45585048:
            c = func_02017938(a, b, 4);
            break;
        case 0x46524d48:
            c = func_0201808c(a, b, 4);
            break;
    }
    return func_020180e0(c, b, 1);
}

void *func_02036948(void *a) {
    Unk02017584 *h = a;
    u32 b = 0;
    void *c;
    switch (h->mUnk_00) {
        case 0x45585048:
            b = func_020176c0(a, 4);
            break;
        case 0x46524d48:
            b = func_0201800c(a, 4);
            break;
    }
    c = 0;
    switch (h->mUnk_00) {
        case 0x45585048:
            c = func_02017938(a, b, 4);
            break;
        case 0x46524d48:
            c = func_0201808c(a, b, 4);
            break;
    }
    return func_020180e0(c, b, 1);
}

void *func_020369fc(void *a) {
    Unk02017584 *h = a;
    u32 b = 0;
    void *c;
    switch (h->mUnk_00) {
        case 0x45585048:
            b = func_020176c0(a, 4);
            break;
        case 0x46524d48:
            b = func_0201800c(a, 4);
            break;
    }
    c = 0;
    switch (h->mUnk_00) {
        case 0x45585048:
            c = func_02017938(a, b, 4);
            break;
        case 0x46524d48:
            c = func_0201808c(a, b, 4);
            break;
    }
    return func_02017988(c, b, 1);
}

void func_02036ab0(void *a) {
    Unk02017584 *h = a;
    Unk020176c0 *p;
    switch (h->mUnk_00) {
        case 0x45585048:
            func_0201797c(a);
            break;
        case 0x46524d48:
            func_020180d4(a);
            break;
    }
    p = func_02017550(a);
    if (p == 0) {
        return;
    }
    switch (p->mUnk_00.mUnk_00) {
        case 0x45585048:
            func_02017770(p, a);
            break;
        case 0x46524d48:
            break;
    }
}

void func_02036b30(void *a, void *b) {
    Unk02017584 *h = a;
    switch (h->mUnk_00) {
        case 0x45585048:
            func_02017770(a, b);
            break;
        case 0x46524d48:
            break;
    }
}

void *func_02036b74(void *a, u32 b, s32 c) {
    Unk02017584 *h = a;
    void *d = 0;
    u32 e;
    switch (h->mUnk_00) {
        case 0x45585048:
            d = func_02017938(a, b, c);
            break;
        case 0x46524d48:
            e = func_0200fca0();
            d = func_0201808c(a, b, c);
            func_0200fcb4(e);
            break;
    }
    return d;
}

void *func_02036bec(void *a, u32 b) {
    Unk02017584 *h = a;
    void *c = 0;
    switch (h->mUnk_00) {
        case 0x45585048:
            c = func_02017938(a, b, 4);
            break;
        case 0x46524d48:
            c = func_0201808c(a, b, 4);
            break;
    }
    return c;
}
