#include "code_0212ba68.h"
#include "code_020207ec.h"
#include "code_02020e3c.h"
#include "code_02020eb0.h"
#include "code_0212b9ec.h"
#include "code_0212bcac.h"
#include "code_0212c9d4.h"
#include "code_0212ee54.h"
#include "code_0214f4a4.h"
#include "code_0201ec30.h"
#include "Main/Unknown/code_02021000.h"
#include "code_0212bb50.h"

CallbackEntry data_0217d42c;
CallbackEntry data_0217d420;
u32 data_0217d418;
u32 data_0217d41c;
s8 data_0217d414;

void func_0212baa8(void) {
    if (data_0217d41c != 0) {
        return;
    }
    data_0217d41c = 1;
    SND_Init();
    data_0217d420.mCallback = func_0212b9f8;
    data_0217d420.mArg = 0;
    data_0217d42c.mCallback = func_0212b9ec;
    data_0217d42c.mArg = 0;
    PM_PrependPreSleepCallback(&data_0217d420);
    PM_AppendPostSleepCallback(&data_0217d42c);
    func_0212bb50();
    func_0212d0ec();
    func_0212c310();
    data_0217d414 = -1;
    data_0217d418 = 1;
}

void func_0212ba74(void) {
    while (SND_RecvCommandReply(0) != 0) {
    }
    func_0212c19c();
    func_0212d03c();
    func_0212f094();
    SND_FlushCommand(0);
}

void func_0212ba68(u32 a) {
    SND_SetMasterVolume(a);
}
