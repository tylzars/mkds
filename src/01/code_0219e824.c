#include "01/code_0219e824.h"
#include "01/unk_021ca000.h"
#include "01/code_02192e78.h"
#include "01/code_0219853c.h"
#include "01/code_0219ea48.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "01/code_02192000.h"
#include "01/code_02198000.h"
#include "01/code_0219e000.h"
#include "Main/Unknown/code_02048000.h"
#include "01/code_0219e0a8.h"
#include "01/code_0219f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02105000.h"

u8 *data_ov001_021ca404;
u8 *data_ov001_021ca408;

static Unk021a9034 data_ov001_021a9064 = {
    func_ov001_0219e9e0, func_ov001_0219e960, func_ov001_0219e9c8, func_ov001_0219e9a4, 0, 0, 10, 10, 0};
static Unk021a9034 data_ov001_021a9084 = {
    func_ov001_0219ea8c, func_ov001_0219ea48, func_ov001_0219ea74, func_ov001_0219ea6c, 0, 0, 30, 1, 0};

int func_ov001_0219ea14(void *a) {
    Unk021a9034 local = data_ov001_021a9084;

    func_020487fc(a, &local);
    return 0;
}

void func_ov001_0219e9e0(s16 *a) {
    void *heap;

    heap = (void *) func_020364e0(func_020364e8());
    data_ov001_021ca408 = func_02036bec(heap, 0x808);
    func_ov001_02192fb8((void *) (heap), (s16) (*a));
}

void func_ov001_0219e9c8(void) {
    func_ov001_02192f8c();
    data_ov001_021ca408 = NULL;
}

void func_ov001_0219e9a4(void) {
    func_ov001_02192ec4();
    func_020ae5f0(data_ov001_021ca408, data_ov001_021ca408 + 0x404);
}

void func_ov001_0219e960(s16 *a) {
    func_020ae6ac(data_ov001_021ca408, data_ov001_021ca408 + 0x404);
    func_ov001_02192ee4();
    func_020ae630(data_ov001_021ca408, data_ov001_021ca408 + 0x404);
    if (a != NULL && func_ov001_02192e84() != -1) {
        a[2] = func_ov001_02192e84();
    }
}

int func_ov001_0219e92c(void *a) {
    Unk021a9034 local = data_ov001_021a9064;

    func_020487fc(a, &local);
    return 0;
}

u8 *func_ov001_0219e920(void) {
    return data_ov001_021ca408;
}

u8 *func_ov001_0219e90c(void) {
    return data_ov001_021ca408 + 0x404;
}

void func_ov001_0219e8d8(s16 *a) {
    void *heap;

    heap = (void *) func_020364e0(func_020364e8());
    data_ov001_021ca404 = func_02036bec(heap, 0x808);
    func_ov001_021987d4(heap, *a);
}

void func_ov001_0219e8c0(void) {
    func_ov001_021987bc();
    data_ov001_021ca404 = NULL;
}

void func_ov001_0219e89c(void) {
    u8 *p;

    func_ov001_0219854c();
    p = data_ov001_021ca404;
    func_020ae5f0(p, p + 0x404);
}

void func_ov001_0219e858(s16 *a) {
    func_020ae6ac(data_ov001_021ca404, data_ov001_021ca404 + 0x404);
    func_ov001_02198554();
    func_020ae630(data_ov001_021ca404, data_ov001_021ca404 + 0x404);
    if (a != NULL && func_ov001_0219853c() != -1) {
        a[2] = func_ov001_0219853c();
    }
}

int func_ov001_0219e824(void *a) {
    Unk021a9034 callbacks = {
        func_ov001_0219e8d8, func_ov001_0219e858, func_ov001_0219e8c0, func_ov001_0219e89c, 0, 0, 10, 10, 0,
    };

    func_020487fc(a, &callbacks);
    return 0;
}
