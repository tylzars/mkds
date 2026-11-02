#include "Main/Unknown/code_020d0f78.h"
#include "Main/Unknown/code_02048000.h"
#include "code_02135014.h"
#include "Main/Unknown/unk_0216a000.h"

#pragma opt_propagation off

#pragma thumb on
void func_020d10fc(void) {
    data_0217b4a4 = 0;
}

void func_020d1080(void) {
    char buf[0x100];
    s32 i;
    s32 a;
    s32 b;

    i = data_0217b4a4->mUnk_0c;
    a = data_0216aea8[i * 2];
    b = data_0216aeac[i * 2];
    snprintf(buf, 0x100, "%s%s%02d%s", data_0216ae88, a == 0 ? data_0216ae78 : data_0216ae80, b, "_m_b.NCLR");
    func_02048684(buf, data_0217b4a4->mUnk_10, 0x228);
    func_020b4a7c(&data_0217b4a4->mUnk_00, data_0217b4a4->mUnk_10);
}

void func_020d0ffc(void) {
    char buf[0x100];
    s32 i;
    s32 a;
    s32 b;

    i = data_0217b4a4->mUnk_0c;
    a = data_0216aea8[i * 2];
    b = data_0216aeac[i * 2];
    snprintf(buf, 0x100, "%s%s%02d%s", data_0216ae88, a == 0 ? data_0216ae78 : data_0216ae80, b, "_m_b.NCGR");
    func_02048684(buf, data_0217b4a4->mUnk_238, 0xe00);
    func_020b496c(&data_0217b4a4->mUnk_04, data_0217b4a4->mUnk_238);
}

void func_020d0f78(void) {
    char buf[0x100];
    s32 i;
    s32 a;
    s32 b;

    i = data_0217b4a4->mUnk_0c;
    a = data_0216aea8[i * 2];
    b = data_0216aeac[i * 2];
    snprintf(buf, 0x100, "%s%s%02d%s", data_0216ae88, a == 0 ? data_0216ae78 : data_0216ae80, b, "_m_picture.NSCR");
    func_02048684(buf, data_0217b4a4->mUnk_1038, 0x824);
    func_020b4810(&data_0217b4a4->mUnk_08, data_0217b4a4->mUnk_1038);
}
#pragma thumb off
