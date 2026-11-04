#include "00/code_02188ec0.h"
#include "00/code_0218a294.h"
#include "00/code_02187484.h"
#include "00/code_02188000.h"
#include "00/unk_021b4000.h"
#include "00/code_021884d8.h"
#include "00/code_02188ee0.h"
#include "00/code_0218a0f4.h"
#include "00/code_0218a118.h"
#include "00/code_0218a130.h"
#include "00/code_0218a194.h"
#include "00/code_0218a1bc.h"
#include "00/code_0218a24c.h"

u32 func_ov000_0218a294(void) {
    u32 s;
    Unk02188ec0 *v1;

    s = func_ov000_02188528();
    v1 = (Unk02188ec0 *) func_ov000_02188584(0x10);
    if (func_ov000_021a5bfc() == 9) {
        switch (s) {
            case 10:
                s = func_ov000_0218a24c(v1);
                break;
            case 12:
                s = func_ov000_0218a1bc(v1);
                break;
            case 13:
                s = func_ov000_0218a194();
                break;
            case 14:
                s = func_ov000_0218a130(v1);
                break;
            case 15:
                s = func_ov000_0218a118(v1);
                break;
            case 11:
                s = func_ov000_0218a0f4();
                break;
        }
    } else {
        switch (s) {
            case 15:
                s = func_ov000_0218a118(v1);
                break;
            case 11:
                s = func_ov000_0218a0f4();
                break;
            case 14:
                func_ov000_02187fb8();
                func_ov000_02188068();
            default:
                v1->mUnk_444[v1->mUnk_d13].mUnk_00 = 2;
                s = 0xb;
        }
    }
    return s;
}
