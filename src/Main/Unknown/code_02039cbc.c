#include "Main/Unknown/code_02039cbc.h"
#include "Main/Unknown/code_02039e08.h"
#include "Main/Unknown/code_02039e00.h"
#include "Main/Unknown/code_020364e0.h"
#include "code_02146af4.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02057524.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02108e94.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_02057ed8.h"
#include "Main/Unknown/code_02057ed4.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/code_020cefa0.h"
#include "Main/Unknown/code_020cef1c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0212b0b8.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02045000.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "code_0200e77c.h"
#include "code_0214d93c.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/code_0204984c.h"
#include "Main/Unknown/code_0204ad44.h"
#include "Main/Unknown/code_0204b714.h"

void func_02039cbc(void) {
    void *a;
    void *b;
    void *c;
    void *d;
    void *e;
    u32 f;
    f = func_02039e08(GetHeap(func_020364e8()), &a, &e, &b, &c, &d);
    func_02146b04(func_02039e00);
    func_0205e180(a);
    func_02049c3c(a);
    func_020486d4(a);
    func_0204af70(a);
    func_020545e8(a);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        InitWiFiSession(a);
    }
    func_02046a3c(a);
    func_02057524(a);
    func_02108344(e, f, ((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2);
    func_02108e94(1);
    if (func_0200e8fc() == 0) {
        RTC_Init();
    }
    func_02043d10(a);
    func_0204ba2c(a);
    func_02057ed8(a);
    func_0205a140(a);
    func_020cefa0(a);
    func_020471b0(a);
    func_0212b158(a);
    func_02057ed4();
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        func_02047544(b, c, d);
    }
    func_02045590();
    func_0204b9ac();
    func_0205a0e4();
    func_020cef1c();
}
