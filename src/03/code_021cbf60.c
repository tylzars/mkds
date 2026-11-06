#include "03/code_021cbf60.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/code_021bf410.h"
#include "03/code_021bf000.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd2e0.h"
#include "03/code_021bf810.h"
#include "03/code_021c209c.h"
#include "03/code_021cbed0.h"
#include "03/code_021cd000.h"
#include "03/code_021cd0d0.h"

void func_ov003_021cbf60(void) {
    s32 a;
    func_ov003_021cd27c();
    func_ov003_021c20dc(NULL, &a);
    func_ov003_021cbf0c();
    func_ov003_021bf43c(0x7d, -1, 0);
    if (a != 2) {
        LoadHlSetScr();
    }
    if (a == 1) {
        func_ov003_021cd6d0();
    }
    func_ov003_021c212c(func_ov003_021cbed0);
}
