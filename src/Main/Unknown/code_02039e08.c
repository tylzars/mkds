#include "Main/Unknown/code_02039e08.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02039774.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_0204984c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02045874.h"
#include "Main/Unknown/code_0203a3a4.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0204673c.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_02046c10.h"
#include "Main/Unknown/code_02049000.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020ae824.h"
#include "Main/Unknown/code_020aeb7c.h"
#include "Main/Unknown/code_020af66c.h"
#include "Main/Unknown/code_020b2574.h"
#include "Main/Unknown/code_020b255c.h"
#include "Main/Unknown/code_020b2e34.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020cb4c0.h"
#include "Main/Unknown/code_020cb9b8.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_020cc168.h"
#include "Main/Unknown/code_0210f72c.h"
#include "Main/Unknown/code_0210f744.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "01/code_0219e0a8.h"
#include "code_020176c0.h"
#include "Main/Unknown/code_02044618.h"

void UpdateRaceScene(Unk0203a0dc *a, u32 b) {
    Unk021759c0 *q;
    u32 c;
    if (func_02049b6c() == 0) {
        if (func_0204359c() == 0) {
            if (a != NULL) {
                if (func_0203a8f4() == 5) {
                    c = func_0205bba8();
                } else {
                    c = func_020b2e34();
                }
                if (c != 0) {
                    func_0203a8e0(c);
                    func_0203a520(a, c);
                }
                switch (func_0203a50c()) {
                    case 1:
                        c = 0;
                        if (b > func_0210f72c()) {
                            if (func_0210f75c(1) != 0) {
                                c = 1;
                                func_0203a4d4(0);
                            }
                        }
                        if (c == 0) {
                            if (func_0203a4a8(func_0203a4cc(), 0x2fff) != 0) {
                                c = 1;
                                func_0203a48c(5);
                                func_0203a4d4(1);
                            } else if (func_0203a440(func_0203a4cc()) != 0) {
                                c = 1;
                                func_0203a48c(5);
                                func_0203a4d4(1);
                            }
                        }
                        if (c != 0) {
                            a->mUnk_04 = 0;
                        }
                        break;
                    case 3:
                    case 4:
                        if (func_0203a42c() != 0 || (b > 0x5a && (func_0203a4a8(func_0203a4cc(), 0xc0f) != 0 ||
                                                                  func_0203a3cc(func_0203a4cc()) != 0))) {
                            a->mUnk_04 = 2;
                            func_0203a3b8(0);
                        }
                        break;
                    case 2:
                        switch (func_0203a8f4()) {
                            case MODE_GRAND_PRIX:
                            case MODE_TIME_ATTACK:
                                if (func_0203c0bc() != 0) {
                                    a->mUnk_04 = 2;
                                }
                                break;
                        }
                        break;
                    case 5:
                        if (func_0203a9ec(b) != 0) {
                            a->mUnk_04 = 0xa;
                        }
                        break;
                    case 6:
                        c = 0x2a5a;
                        if (func_0203a3a4() == COURSE_ID_STAFFROLLTRUE) {
                            c = 0x2b02;
                        }
                        if (b > c) {
                            a->mUnk_04 = 0xf;
                            break;
                        }
                        if (func_0203a908(b) != 0) {
                            func_ov001_0219e0c4();
                            a->mUnk_04 = 0xf;
                        }
                        break;
                }
            }
            if (func_0203afe4(b) != 0) {
                UpdateRace();
            }
            func_020af66c();
        }
        func_020aeb7c();
        switch (func_0203a50c()) {
            case 0:
            case 2:
            case 3:
            case 4:
                func_020b2574();
                break;
        }
        if (func_020b2ec0() != 0) {
            func_020435d4(1);
        } else {
            func_020435d4(0);
        }
    }
    q = data_021759c0;
    if (q->mUnk_00c != 6) {
        c = 1;
    } else {
        if (b < 0x708) {
            c = 0;
        } else {
            c = 1;
        }
    }
    if (c != 0) {
        if (q->mMode != 5 || func_02037a20() == 0) {
            DrawRace();
        }
    }
    func_020ae824();
    func_020b255c();
}

void func_0203a05c(void) {
    data_021759d0->mUnk_54 = FALSE;
    if (data_021759c0->mUnk_00c == 0) {
        func_020b2e64(1);
    }
    func_02046e84();
    while ((u32) data_0217c7ac != 0) {
        PrepareDisplayFrame();
        func_020b2574();
        func_0210823c();
        FinishDisplayFrame();
        func_020b255c();
        RecordFrameTimes();
    }
}

void func_0203a050(void) {
    func_02046e24();
}

u32 RunRaceScene(SceneNumbers *a) {
    SceneCallbacks b = gRaceSceneCallbacks;
    func_02044940();
    if (data_021759c0->mMode == 5) {
        b.mUnk_1c = 1;
    }
    if (data_021759c0->mUnk_00c != 5) {
        if (data_021759c0->mUnk_00c == 6) {
            b.mUnk_18 = 1;
            b.mUnk_1a = 0x78;
        }
    } else {
        b.mUnk_18 = 0x3c;
        b.mUnk_1a = 0x78;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_02043f28(1);
    }
    RunScene(a, &b);
    return 0;
}

void InitMenuScene(void) {
    func_020cbb10();
}

void ReleaseMenuScene(void) {
    func_020cb9b8();
    data_021759d0->mUnk_50 &= ~1;
    func_0204465c();
}

void func_02039f50(void) {
    func_020cc36c();
}

void UpdateMenuScene(void) {
    func_020cb51c();
    func_020cb4c0();
}

u32 RunMenuScene(SceneNumbers *a) {
    SceneCallbacks b = gMenuSceneCallbacks;
    RunScene(a, &b);
    return 0;
}

u32 func_02039e08(NNSiFndHeapHead *a, void **b, void **c, void **d, void **e, void **f) {
    u32 r;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        *b = CreateFrmHeapFromBack(a, 0x19000);
    } else {
        *b = CreateFrmHeapFromBack(a, 0x1b800);
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        *d = NULL;
        *e = NULL;
        *f = NULL;
    } else {
        *d = CreateFrmHeapFromFront(a, 0x19000);
        *e = CreateFrmHeapFromFront(a, 0x4b000);
        *f = CreateFrmHeapFromFront(a, 0x1b800);
    }
    r = func_021087c4(((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 ? 2 : 0);
    *c = HeapAlloc(a, r);
    NNS_FndGetTotalFreeSizeForExpHeap(a);
    return r;
}
