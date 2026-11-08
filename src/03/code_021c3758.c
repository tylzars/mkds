#include "03/code_021c3758.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/code_021bf410.h"
#include "code_0200fc8c.h"
#include "code_0213c9f8.h"
#include "code_021510a4.h"
#include "code_02151868.h"

void PrintJb5Info(void) {
    void *a;
    u8 b[8];
    DWCWiFiInfo c;
    u32 d[4];
    u16 f[20];
    u64 g;
    s32 i;
    a = InitBgTextCanvas(0, 0);
    OS_GetMacAddress(b);
    swprintf(f, 0x14, gMacAddressFormat, b[0], b[1], b[2], b[3], b[4], b[5]);
    DrawCanvasTextRect(a, data_ov003_021d6338.mUnk_00, data_ov003_021d6338.mUnk_02, data_ov003_021d6338.mUnk_04,
                       data_ov003_021d6338.mUnk_06, 2, 0x480, f);
    DWCi_BM_GetWiFiInfo(&c);
    g = c.mAttestedUserId;
    if (g != 0) {
        d[3] = (g % 10) * 1000;
        g = g / 10;
        for (i = 0; i < 3; i++) {
            d[2 - i] = g % 10000;
            g = g / 10000;
        }
        swprintf(f, 0x14, gDashSeparatedNumbersFormat, d[0], d[1], d[2], d[3]);
    } else {
        swprintf(f, 0x14, gDashesFormat);
    }
    DrawCanvasTextRect(a, data_ov003_021d6340.mUnk_00, data_ov003_021d6340.mUnk_02, data_ov003_021d6340.mUnk_04,
                       data_ov003_021d6340.mUnk_06, 2, 0x480, f);
    RequestBgTextCanvasUpload(a);
}
