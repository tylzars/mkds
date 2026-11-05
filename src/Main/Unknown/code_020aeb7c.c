#include "Main/Unknown/code_020aeb7c.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020b2e98.h"
#include "Main/Unknown/code_020be950.h"
#include "Main/Unknown/code_020c5e30.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_020f36d8.h"
#include "00/code_02181f98.h"
#include "code_02022030.h"
#include "Main/Unknown/code_020c476c.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_020b2000.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020a128c.h"
#include "Main/Unknown/code_020c3e44.h"
#include "Main/Unknown/code_020c214c.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020be000.h"
#include "Main/Unknown/code_020c6000.h"
#include "Main/Unknown/code_0203c5f8.h"

void func_020aeb7c(void) {
    BOOL a;
    BOOL d;
    BOOL b;
    BOOL c;
    BOOL e;
    s32 v;

    func_020c525c();
    if (data_021759c0->mUnk_00c - 3 <= 3) {
        return;
    }
    if (gRaceHud->mEnabled == FALSE) {
        return;
    }
    switch (data_021759c0->mMode) {
        case 0:
            if (IsKartEnded(func_020b4d9c()) != 0 && gRaceHud->mUnk_8dc == 0) {
                if (data_021759c0->mUnk_00c == 0) {
                    if (gRaceHud->mUnk_83c != FALSE) {
                        gRaceHud->mUnk_82c = FALSE;
                    } else {
                        gRaceHud->mUnk_82c = TRUE;
                        gRaceHud->mSubScreenState = 4;
                        gRaceHud->mUnk_83c = TRUE;
                        gRaceHud->mUnk_840 = TRUE;
                        gRaceHud->mUnk_850 = 0xc;
                    }
                } else if (gRaceHud->mUnk_83c == FALSE) {
                    gRaceHud->mUnk_83c = TRUE;
                    gRaceHud->mUnk_840 = TRUE;
                    gRaceHud->mUnk_850 = 0xc;
                }
            } else {
                a = FALSE;
                b = FALSE;
                c = FALSE;
                if (data_021759c0->mUnk_00c != 1 && data_021759c0->mUnk_00c != 4) {
                    c = TRUE;
                }
                if (c != FALSE) {
                    if (func_020b32ec() == 0) {
                        b = TRUE;
                    }
                }
                if (b != FALSE) {
                    d = TRUE;
                    if ((u16) (data_0217562c[func_020435bc()].mUnk_00 & 0x800) == 0) {
                        e = FALSE;
                        if (func_020b2e98() == 0) {
                            if (data_02175680[func_020435bc()].mUnk_00 == 5) {
                                e = TRUE;
                            }
                        } else {
                            e = FALSE;
                        }
                        if (e == FALSE) {
                            d = FALSE;
                        }
                    }
                    if (d != FALSE) {
                        a = TRUE;
                    }
                }
                if (a != FALSE) {
                    gRaceHud->mUnk_82c = TRUE;
                    switch (gRaceHud->mSubScreenState) {
                        case 0:
                            gRaceHud->mSubScreenState = 1;
                            func_0212ecc0(&data_0217d068, 0, 0x18);
                            break;
                        case 1:
                            gRaceHud->mSubScreenState = 0;
                            func_0212ecc0(&data_0217d068, 0, 0x17);
                            break;
                    }
                } else {
                    gRaceHud->mUnk_82c = FALSE;
                }
            }
            break;
        case 1:
            if (gRaceProgress->mRaceDone != 0 && gRaceHud->mUnk_8dc == 0) {
                if (gRaceHud->mUnk_83c == FALSE) {
                    gRaceHud->mUnk_83c = TRUE;
                    gRaceHud->mUnk_840 = TRUE;
                    gRaceHud->mUnk_850 = 0xc;
                }
            } else {
                a = FALSE;
                b = FALSE;
                c = FALSE;
                if (data_021759c0->mUnk_00c != 1 && data_021759c0->mUnk_00c != 4) {
                    c = TRUE;
                }
                if (c != FALSE) {
                    if (func_020b32ec() == 0) {
                        b = TRUE;
                    }
                }
                if (b != FALSE) {
                    d = TRUE;
                    if ((u16) (data_0217562c[func_020435bc()].mUnk_00 & 0x800) == 0) {
                        e = FALSE;
                        if (func_020b2e98() == 0) {
                            if (data_02175680[func_020435bc()].mUnk_00 == 5) {
                                e = TRUE;
                            }
                        } else {
                            e = FALSE;
                        }
                        if (e == FALSE) {
                            d = FALSE;
                        }
                    }
                    if (d != FALSE) {
                        a = TRUE;
                    }
                }
                if (a != FALSE) {
                    gRaceHud->mUnk_82c = TRUE;
                    if (data_021759c0->mUnk_00c != 2) {
                        switch (gRaceHud->mSubScreenState) {
                            case 0:
                                gRaceHud->mSubScreenState = 1;
                                func_0212ecc0(&data_0217d068, 0, 0x18);
                                break;
                            case 1:
                                gRaceHud->mSubScreenState = 0;
                                func_0212ecc0(&data_0217d068, 0, 0x17);
                                break;
                        }
                    } else {
                        switch (gRaceHud->mSubScreenState) {
                            case 0:
                                gRaceHud->mSubScreenState = 1;
                                func_0212ecc0(&data_0217d068, 0, 0x18);
                                break;
                            case 1:
                                gRaceHud->mSubScreenState = 2;
                                func_0212ecc0(&data_0217d068, 0, 0x17);
                                break;
                            case 2:
                                gRaceHud->mSubScreenState = 0;
                                func_0212ecc0(&data_0217d068, 0, 0x17);
                                break;
                        }
                    }
                } else {
                    gRaceHud->mUnk_82c = FALSE;
                }
            }
            break;
        case 2:
            if (func_020a128c() != 0) {
                if (gRaceHud->mUnk_83c != FALSE) {
                    gRaceHud->mUnk_82c = FALSE;
                } else {
                    gRaceHud->mUnk_82c = TRUE;
                    gRaceHud->mSubScreenState = 4;
                    gRaceHud->mUnk_83c = TRUE;
                    gRaceHud->mUnk_840 = TRUE;
                    gRaceHud->mUnk_850 = 0x8c;
                }
            } else {
                a = FALSE;
                b = FALSE;
                c = FALSE;
                if (data_021759c0->mUnk_00c != 1 && data_021759c0->mUnk_00c != 4) {
                    c = TRUE;
                }
                if (c != FALSE) {
                    if (func_020b32ec() == 0) {
                        b = TRUE;
                    }
                }
                if (b != FALSE) {
                    d = TRUE;
                    if ((u16) (data_0217562c[func_020435bc()].mUnk_00 & 0x800) == 0) {
                        e = FALSE;
                        if (func_020b2e98() == 0) {
                            if (data_02175680[func_020435bc()].mUnk_00 == 5) {
                                e = TRUE;
                            }
                        } else {
                            e = FALSE;
                        }
                        if (e == FALSE) {
                            d = FALSE;
                        }
                    }
                    if (d != FALSE) {
                        a = TRUE;
                    }
                }
                if (a != FALSE) {
                    gRaceHud->mUnk_82c = TRUE;
                    switch (gRaceHud->mSubScreenState) {
                        case 0:
                            gRaceHud->mSubScreenState = 1;
                            func_0212ecc0(&data_0217d068, 0, 0x18);
                            break;
                        case 1:
                            gRaceHud->mSubScreenState = 0;
                            func_0212ecc0(&data_0217d068, 0, 0x17);
                            break;
                    }
                } else {
                    gRaceHud->mUnk_82c = FALSE;
                }
            }
            break;
        case 3:
        case 5:
            if (gRaceProgress->mRaceDone != 0 && data_021759c0->mUnk_00c == 0) {
                if (gRaceHud->mUnk_838 == FALSE) {
                    gRaceHud->mUnk_82c = TRUE;
                    gRaceHud->mSubScreenState = 4;
                    gRaceHud->mUnk_838 = TRUE;
                    if (gRaceHud->mUnk_83c == FALSE) {
                        gRaceHud->mUnk_83c = TRUE;
                        gRaceHud->mUnk_840 = TRUE;
                        gRaceHud->mUnk_850 = 0x8c;
                    }
                } else {
                    gRaceHud->mUnk_82c = FALSE;
                }
            } else if (IsKartEnded(func_020b4d9c()) != 0 && data_021759c0->mUnk_00c == 0) {
                if (gRaceHud->mUnk_83c == FALSE) {
                    gRaceHud->mUnk_82c = TRUE;
                    gRaceHud->mSubScreenState = 0;
                    gRaceHud->mUnk_83c = TRUE;
                    gRaceHud->mUnk_840 = TRUE;
                    gRaceHud->mUnk_850 = 0x8c;
                } else {
                    a = FALSE;
                    b = FALSE;
                    c = FALSE;
                    if (data_021759c0->mUnk_00c != 1 && data_021759c0->mUnk_00c != 4) {
                        c = TRUE;
                    }
                    if (c != FALSE) {
                        if (func_020b32ec() == 0) {
                            b = TRUE;
                        }
                    }
                    if (b != FALSE) {
                        d = TRUE;
                        if ((u16) (data_0217562c[func_020435bc()].mUnk_00 & 0x800) == 0) {
                            e = FALSE;
                            if (func_020b2e98() == 0) {
                                if (data_02175680[func_020435bc()].mUnk_00 == 5) {
                                    e = TRUE;
                                }
                            } else {
                                e = FALSE;
                            }
                            if (e == FALSE) {
                                d = FALSE;
                            }
                        }
                        if (d != FALSE) {
                            a = TRUE;
                        }
                    }
                    if (a != FALSE) {
                        gRaceHud->mUnk_82c = TRUE;
                        switch (gRaceHud->mSubScreenState) {
                            case 0:
                                gRaceHud->mSubScreenState = 3;
                                func_0212ecc0(&data_0217d068, 0, 0x18);
                                break;
                            case 3:
                                gRaceHud->mSubScreenState = 0;
                                func_0212ecc0(&data_0217d068, 0, 0x17);
                                break;
                        }
                    } else {
                        gRaceHud->mUnk_82c = FALSE;
                    }
                }
            } else {
                a = FALSE;
                b = FALSE;
                c = FALSE;
                if (data_021759c0->mUnk_00c != 1 && data_021759c0->mUnk_00c != 4) {
                    c = TRUE;
                }
                if (c != FALSE) {
                    if (func_020b32ec() == 0) {
                        b = TRUE;
                    }
                }
                if (b != FALSE) {
                    d = TRUE;
                    if ((u16) (data_0217562c[func_020435bc()].mUnk_00 & 0x800) == 0) {
                        e = FALSE;
                        if (func_020b2e98() == 0) {
                            if (data_02175680[func_020435bc()].mUnk_00 == 5) {
                                e = TRUE;
                            }
                        } else {
                            e = FALSE;
                        }
                        if (e == FALSE) {
                            d = FALSE;
                        }
                    }
                    if (d != FALSE) {
                        a = TRUE;
                    }
                }
                if (a != FALSE) {
                    gRaceHud->mUnk_82c = TRUE;
                    switch (gRaceHud->mSubScreenState) {
                        case 0:
                            gRaceHud->mSubScreenState = 1;
                            func_0212ecc0(&data_0217d068, 0, 0x18);
                            break;
                        case 1:
                            gRaceHud->mSubScreenState = 0;
                            func_0212ecc0(&data_0217d068, 0, 0x17);
                            break;
                    }
                } else {
                    gRaceHud->mUnk_82c = FALSE;
                }
            }
            break;
        case 4:
            if (func_0203c174() != FALSE) {
                if (gRaceHud->mUnk_83c == FALSE) {
                    gRaceHud->mUnk_83c = TRUE;
                    gRaceHud->mUnk_840 = TRUE;
                    if (IsKartEnded((u16) data_021759c0->mEntryIndex) != 0) {
                        v = gRaceProgress->mUnk_4e0;
                    } else {
                        v = 6;
                    }
                    if (v == 0) {
                        gRaceHud->mUnk_850 = 0xaf;
                    }
                }
            } else if (gRaceProgress->mRaceDone != 0) {
                if (IsKartEnded((u16) data_021759c0->mEntryIndex) != 0) {
                    v = gRaceProgress->mUnk_4e0;
                } else {
                    v = 6;
                }
                if (v != 0) {
                    gRaceHud->mUnk_84c = 1;
                }
            }
            if ((u16) (data_0217562c[func_020435bc()].mUnk_00 & 0x800) != 0) {
                func_0212ecc0(&data_0217d068, 0, 0x19);
            }
            gRaceHud->mUnk_82c = FALSE;
            break;
    }
    if (gRaceHud->mUnk_82c != FALSE) {
        switch (gRaceHud->mSubScreenState) {
            case 0:
                func_020be9d4();
                break;
            case 1:
            case 2:
            case 3:
                func_020be9d4();
                func_020c43c4();
                break;
            case 4:
            case 5:
                func_020c31c0();
                break;
            case 6:
                func_020c6f14();
                break;
        }
    }
    if (gRaceHud->mUnk_90c != FALSE) {
        return;
    }
    if (data_021759c0->mMode == 4) {
        v = (data_021759c0->mMode == 4 ? data_021759c0->mMissionTableColumn : -1) == 9;
    } else {
        v = 0;
    }
    if (v == 0) {
        return;
    }
    if (data_021759c0->mMode != 4) {
        v = 0;
    } else {
        v = func_020a128c();
    }
    if (v == 0) {
        return;
    }
    if (data_021759c0->mMode != 4) {
        v = 0;
    } else {
        v = IsKartEliminated(func_020b4d9c());
    }
    if (v != 0) {
        data_0217b488->mUnk_10 = 0;
    } else {
        data_0217b488->mUnk_10 = gRaceHud->mUnk_910 == 0;
    }
    gRaceHud->mUnk_90c = TRUE;
}
