#include "Main/Unknown/code_021114cc.h"

#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02111a98.h"
#include "Main/Unknown/code_02114158.h"
#include "Main/Unknown/code_021145b4.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "01/code_02193b1c.h"
#include "01/code_021953d0.h"
#include "01/code_0219a050.h"

#pragma thumb on

void func_021114cc(void) {
    if (data_0217d344->mUnk_0c != -1) {
        data_0217d344->mUnk_18.mUnk_04();
        func_02111a98();
        func_02036ab0(data_0217d344->mUnk_04);
        data_0217d344->mUnk_04 = func_020369fc(data_0217d344->mUnk_00);
        switch (data_0217d344->mUnk_0c) {
            case 0:
                if (data_0217d344->mUnk_08 == 3) {
                    func_021143f4();
                }
                func_ov001_0219a050();
                break;
            case 1:
                func_ov001_02193c5c();
                break;
            case 2:
                func_ov001_021956dc();
                break;
            case 3:
                func_02111ab4();
                break;
            case 4:
                func_021145b4();
                break;
        }
        data_0217d344->mUnk_10 = data_0217d344->mUnk_08;
        data_0217d344->mUnk_08 = data_0217d344->mUnk_0c;
        data_0217d344->mUnk_0c = -1;
        data_0217d344->mUnk_2c = 2;
        data_0217d344->mUnk_18.mUnk_00(data_0217d344->mUnk_04);
    }
    data_0217d344->mUnk_18.mUnk_08();
    func_02125928();
    func_0212a920();
}

#pragma thumb off
