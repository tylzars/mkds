#include "01/code_0219d50c.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020b47d8.h"

void func_ov001_0219d50c(void) {
    void *v1;
    Unk02111684_v v;
    v1 = FindSceneFile(data_ov001_021a8b54);
    LoadNcgrData(&v.mNcgr, v1);
    v1 = FindSceneFile(data_ov001_021a8b74);
    LoadNscrData(&v.mNscr, v1);
    v1 = FindSceneFile(data_ov001_021a8b98);
    LoadNscrData(&v.mNscr, v1);
    v1 = FindSceneFile(data_ov001_021a8bbc);
    LoadNscrData(&v.mNscr, v1);
    v1 = FindSceneFile(data_ov001_021a8be0);
    LoadNclrData(&v.mNclr, v1);
    v1 = FindSceneFile(data_ov001_021a8c00);
    LoadNcgrData2(&v.mNcgr, v1);
    v1 = FindSceneFile(data_ov001_021a8c24);
    LoadNcerData(&v.mNcer, v1);
    v1 = FindSceneFile(data_ov001_021a8c48);
    LoadNclrData(&v.mNclr, v1);
    v1 = FindSceneFile(data_ov001_021a8c68);
    LoadNcgrData2(&v.mNcgr, v1);
    v1 = FindSceneFile(data_ov001_021a8c8c);
    LoadNcerData(&v.mNcer, v1);
    v1 = FindSceneFile(data_ov001_021a8cb0);
    LoadNclrData(&v.mNclr, v1);
    return;
}
