#include "03/code_021c7844.h"
#include "03/code_021bf000.h"
#include "03/code_021bf410.h"
#include "03/code_021c2000.h"
#include "03/code_021c7d30.h"
#include "03/code_021c9000.h"
#include "03/code_021cb000.h"
#include "03/code_021cb11c.h"
#include "03/code_021cd000.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/unk_021da000.h"
#include "03/code_021d2940.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021c7000.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/code_021c2530.h"
#include "code_0213c9f8.h"

#include "03/code_021d254c.h"
#include "03/code_021bf098.h"
#include "03/code_021c209c.h"

void PrintJb4Error(void) {
    s32 a;
    s32 b;
    s32 c;
    void *d;
    void *e;
    u16 f;
    u16 g;
    u16 h[8];
    func_ov003_021c20dc(NULL, &b);
    a = *(s32 *) gJb4ErrorCode;
    if (a >= -0x4e83) {
        c = 0x0;
    } else if (a >= -0x4e84) {
        c = 0x15;
    } else if (a >= -0x4e85) {
        c = 0x4a;
    } else if (a >= -0x4e8b) {
        c = 0x15;
    } else if (a >= -0x4e8c) {
        c = 0x49;
    } else if (a >= -0x4e8d) {
        c = 0x15;
    } else if (a >= -0x4e8e) {
        c = 0x18;
    } else if (a >= -0x5207) {
        c = 0x15;
    } else if (a >= -0x59d7) {
        c = 0x0;
    } else if (a >= -0x5dbf) {
        c = 0x4a;
    } else if (a >= -0xc34f) {
        c = 0x0;
    } else if (a >= -0xc352) {
        c = 0x35;
    } else if (a >= -0xc353) {
        c = 0x26;
    } else if (a >= -0xc3b2) {
        c = 0x0;
    } else if (a >= -0xc3b3) {
        if (b == 2) {
            c = 0x26;
        } else {
            c = 0x35;
        }
    } else if (a >= -0xc79a) {
        c = 0x0;
    } else if (a >= -0xc79b) {
        if (b == 2) {
            c = 0x26;
        } else {
            c = 0x36;
        }
    } else if (a >= -0xc79e) {
        c = 0x37;
    } else if (a >= -0xc79f) {
        c = 0x26;
    } else if (a >= -0xc7ff) {
        c = 0x0;
    } else if (a >= -0xc863) {
        c = 0x4c;
    } else if (a >= -0xc866) {
        c = 0x4d;
    } else if (a >= -0xc867) {
        c = 0x25;
    } else if (a >= -0xcb1f) {
        c = 0x0;
    } else if (a >= -0xcb22) {
        c = 0x38;
    } else if (a >= -0xcb23) {
        c = 0x4e;
    } else if (a >= -0xcb83) {
        c = 0x0;
    } else if (a >= -0xcb87) {
        c = 0x3b;
    } else if (a >= -0xcbe7) {
        c = 0x0;
    } else if (a >= -0xcbeb) {
        c = 0x3b;
    } else if (a >= -0xcc4b) {
        c = 0x0;
    } else if (a >= -0xccaf) {
        c = 0x15;
    } else if (a >= -0xcf07) {
        c = 0x0;
    } else if (a >= -0xd033) {
        c = 0x15;
    } else {
        c = 0;
    }
    d = func_ov003_021d2288(0, data_ov003_021d6408[func_ov003_021c20d0()]);
    e = func_ov003_021c2530(data_ov003_021da19c, c);
    swprintf(h, 8, gDecimalFormat, -*(s32 *) gJb4ErrorCode);
    f = data_ov003_021d641a[func_ov003_021c20d0() * 2];
    g = data_ov003_021d6418[func_ov003_021c20d0() * 2];
    func_ov003_021d2094(d, g, f, 2, 0xa, h, 0);
    func_ov003_021d2070(d, data_ov003_021d6410[0], data_ov003_021d6410[1], data_ov003_021d6410[2],
                        data_ov003_021d6410[3], 2, GetLanguageTextFlags(), e);
    func_ov003_021d1fd0(d);
}

void func_ov003_021c79e4(void) {
    func_ov003_021d1ee0(2, 0, 0x15, 8);
    func_ov003_021d2784(0, 0x15);
    func_ov003_021c212c(func_ov003_021c79b4);
}

void func_ov003_021c79b4(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021bf5c8(4);
        func_ov003_021c212c(func_ov003_021c7990);
    }
}

void func_ov003_021c7990(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        func_ov003_021c212c(UpdateJb4Error);
    }
}

void UpdateJb4Error(void) {
    UpdateJb4ErrorInput();
    func_ov003_021c7958();
    func_ov003_021c7934();
}

void UpdateJb4ErrorInput(void) {
    int v1;
    v1 = func_ov003_021d2b04(1);
    if (v1 != 0) {
        SetButtonResultIfNone((u8) 0);
    }
}

void func_ov003_021c7958(void) {}

void func_ov003_021c7934(void) {
    int v1;
    v1 = GetButtonResult();
    if (v1 == 0) {
        StartSoundSeq(6);
        func_ov003_021c212c(func_ov003_021c7914);
    }
}

void func_ov003_021c7914(void) {
    DisableButtonTouch();
    func_ov003_021d1dd0(8);
    func_ov003_021c212c(func_ov003_021c78d8);
}

void func_ov003_021c78d8(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        StartSlideButtonsOut();
        func_ov003_021d1ee0(3, 1, 1, 8);
        func_ov003_021d1ee0(3, 0, 0x15, 8);
        func_ov003_021c212c(func_ov003_021c7850);
    }
}

void func_ov003_021c7850(void) {
    int v1;
    int v2[1];
    v1 = func_ov003_021d1f70(1);
    if (((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) && (v1 = func_ov003_021bf2f0(), v1 != 0)) {
        func_ov003_021d2168(0);
        func_ov003_021bf410();
        func_ov003_021d272c(1, 1);
        func_ov003_021d272c(0, 0x15);
        func_ov003_021c20dc(NULL, v2);
        if (v2[0] != 0) {
            func_ov003_021c2120(2, 1);
            func_ov003_021c212c(CreateAp);
            return;
        }
        func_ov003_021c2120(2, 0);
        func_ov003_021c20f8(0, 0);
        SetJb3ListMode(0);
        func_ov003_021c212c(CreateJb3List);
    }
}

void SetJb4ErrorCode(u32 a) {
    *(u32 *) &gJb4ErrorCode = a;
}
