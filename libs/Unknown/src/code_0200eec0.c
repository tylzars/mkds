#include "code_0200eec0.h"
#include "code_0200c4a4.h"
#include "code_0200c914.h"
#include "code_0200cd04.h"
#include "code_0200ce60.h"
#include "code_0200db4c.h"
#include "code_0200ef10.h"
#include "code_0214d594.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200f3f4.h"
#include "code_0200fc1c.h"
#include "code_0200fd1c.h"
#include "code_0200fe7c.h"
#include "Main/Unknown/code_02146000.h"
#include "code_021458c4.h"
#include "code_0214d5b8.h"
#include "code_0214f4a4.h"
#include "Main/Unknown/code_02150000.h"

// Calls fifteen functions in a fixed order.
void func_0200eec0(void) {
    func_0200f210();
    PxiInit();
    func_0200d028();
    func_0200f190();
    func_0200cd04();
    func_0200ca34();
    func_0200f4f0();
    func_0214d594();
    func_0200fc1c();
    func_0200ffd8();
    ThreadSystemInit();
    func_0200fd74();
    func_0200c7f4();
    func_02146154();
    func_021500a0();
}
