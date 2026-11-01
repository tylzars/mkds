#include "Main/Unknown/code_020d0f78.h"
#include "Main/Unknown/code_02048000.h"
#include "code_02135014.h"
#include "Main/Unknown/unk_0216a000.h"

#pragma thumb on
void func_020d10fc(void) {
    data_0217b4a4 = 0;
}

// non-matching: the original loads the word of data_0216aea8 first (into r1, compared against 0) and then the word of
// data_0216aeac (r0), with the shifted value in r2; the compiled code loads data_0216aeac first (r2), then
// data_0216aea8 (r0), shifted offset in r1, so the value stored at [sp] ends in r0 instead of r1
void func_020d1080(void) {
    char buf[0x100];
    s32 i;
    s32 a;
    s32 b;

    i = data_0217b4a4->mUnk_0c;
    a = data_0216aea8[i * 2];
    b = data_0216aeac[i * 2];
    func_02135048(buf, 0x100, "%s%s%02d%s", data_0216ae88, a == 0 ? data_0216ae78 : data_0216ae80, b, "_m_b.NCLR");
    func_02048684(buf, data_0217b4a4->mUnk_10, 0x228);
    func_020b4a7c(&data_0217b4a4->mUnk_00, data_0217b4a4->mUnk_10);
}

// non-matching: the original loads the word of data_0216aea8 first (into r1, compared against 0) and then the word of
// data_0216aeac (r0), with the shifted value in r2; the compiled code loads data_0216aeac first (r2), then
// data_0216aea8 (r0), shifted offset in r1, so the value stored at [sp] ends in r0 instead of r1
void func_020d0ffc(void) {
    char buf[0x100];
    s32 i;
    s32 a;
    s32 b;

    i = data_0217b4a4->mUnk_0c;
    a = data_0216aea8[i * 2];
    b = data_0216aeac[i * 2];
    func_02135048(buf, 0x100, "%s%s%02d%s", data_0216ae88, a == 0 ? data_0216ae78 : data_0216ae80, b, "_m_b.NCGR");
    func_02048684(buf, data_0217b4a4->mUnk_238, 0xe00);
    func_020b496c(&data_0217b4a4->mUnk_04, data_0217b4a4->mUnk_238);
}

// non-matching: the original loads the word of data_0216aea8 first (into r1, compared against 0) and then the word of
// data_0216aeac (r0), with the shifted value in r2; the compiled code loads data_0216aeac first (r2), then
// data_0216aea8 (r0), shifted offset in r1, so the value stored at [sp] ends in r0 instead of r1
void func_020d0f78(void) {
    char buf[0x100];
    s32 i;
    s32 a;
    s32 b;

    i = data_0217b4a4->mUnk_0c;
    a = data_0216aea8[i * 2];
    b = data_0216aeac[i * 2];
    func_02135048(buf, 0x100, "%s%s%02d%s", data_0216ae88, a == 0 ? data_0216ae78 : data_0216ae80, b,
                  "_m_picture.NSCR");
    func_02048684(buf, data_0217b4a4->mUnk_1038, 0x824);
    func_020b4810(&data_0217b4a4->mUnk_08, data_0217b4a4->mUnk_1038);
}
#pragma thumb off
