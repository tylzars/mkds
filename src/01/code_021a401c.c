#include "01/code_021a401c.h"
#include "01/code_021a5140.h"
#include "01/code_02185000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_02110000.h"
#include "Main/Unknown/code_0214a000.h"
#include "code_0214b824.h"

void func_ov001_021a401c(void) {
    int a;
    int b;

    a = func_02077a5c();
    b = func_02077a4c();
    func_02078158();
    if (b >= 10) {
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0828, 4), 0);
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0828, 5), -5);
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0828, 6), b / 10);
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0828, 7), b % 10);
        if (a >= 10) {
            func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0828, 1), a / 10);
            func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0828, 2), a % 10);
        } else {
            func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0828, 1), -5);
            func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0828, 2), a);
        }
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0828, 3), -5);
    } else {
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0828, 4), -5);
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0828, 5), 0);
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0828, 6), -5);
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0828, 7), b);
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0828, 1), -5);
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0828, 2), -5);
        func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0828, 3), a);
    }
}
