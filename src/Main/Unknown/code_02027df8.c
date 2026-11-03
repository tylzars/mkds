#include "Main/Unknown/code_02027df8.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_02161000.h"

#pragma thumb on

void func_02027df8(void) {
    void *v1;
    Unk020b4934 *v2;
    Unk020b4a44 *v3;
    Unk02021dc8 *v4;
    Unk020b47d8 *v5[1];
    v2 = NULL;
    v3 = NULL;
    v4 = NULL;
    v5[0] = NULL;
    v1 = func_02047a28(data_02161e64);
    LoadNcgrData(&v2, v1);
    v1 = func_02047a28(data_02161e7c);
    LoadNcgrData2(&v2, v1);
    v1 = func_02047a28(data_02161e94);
    LoadNcerData(&v4, v1);
    v1 = func_02047a28(data_02161eac);
    LoadNclrData(&v3, v1);
    v1 = func_02047a28(data_02161ec4);
    LoadNclrData(&v3, v1);
    v1 = func_02047a28(data_02161edc);
    LoadNscrData(v5, v1);
}

#pragma thumb off
