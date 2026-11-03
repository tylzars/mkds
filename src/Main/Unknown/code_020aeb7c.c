#include "Main/Unknown/code_0203c07c.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020aeb7c.h"
#include "Main/Unknown/code_020b2e98.h"
#include "Main/Unknown/code_020be950.h"
#include "Main/Unknown/code_020c5e30.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_020f36d8.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_020c4bec.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_020b2000.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020a128c.h"
#include "Main/Unknown/code_020c3e44.h"
#include "Main/Unknown/code_020c31c0.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020be000.h"
#include "Main/Unknown/code_020c6000.h"

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
    if (data_0217b350->mUnk_898 == 0) {
        return;
    }
    switch (data_021759c0->mUnk_08) {
        case 0:
            if (func_0203c880(func_020b4d9c()) != 0 && data_0217b350->mUnk_8dc == 0) {
                if (data_021759c0->mUnk_00c == 0) {
                    if (data_0217b350->mUnk_83c != 0) {
                        data_0217b350->mUnk_82c = 0;
                    } else {
                        data_0217b350->mUnk_82c = 1;
                        data_0217b350->mUnk_828 = 4;
                        data_0217b350->mUnk_83c = 1;
                        data_0217b350->mUnk_840 = 1;
                        data_0217b350->mUnk_850 = 0xc;
                    }
                } else if (data_0217b350->mUnk_83c == 0) {
                    data_0217b350->mUnk_83c = 1;
                    data_0217b350->mUnk_840 = 1;
                    data_0217b350->mUnk_850 = 0xc;
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
                    data_0217b350->mUnk_82c = 1;
                    switch (data_0217b350->mUnk_828) {
                        case 0:
                            data_0217b350->mUnk_828 = 1;
                            func_0212ecc0(&data_0217d068, 0, 0x18);
                            break;
                        case 1:
                            data_0217b350->mUnk_828 = 0;
                            func_0212ecc0(&data_0217d068, 0, 0x17);
                            break;
                    }
                } else {
                    data_0217b350->mUnk_82c = 0;
                }
            }
            break;
        case 1:
            if (data_0217561c->mUnk_4cc != 0 && data_0217b350->mUnk_8dc == 0) {
                if (data_0217b350->mUnk_83c == 0) {
                    data_0217b350->mUnk_83c = 1;
                    data_0217b350->mUnk_840 = 1;
                    data_0217b350->mUnk_850 = 0xc;
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
                    data_0217b350->mUnk_82c = 1;
                    if (data_021759c0->mUnk_00c != 2) {
                        switch (data_0217b350->mUnk_828) {
                            case 0:
                                data_0217b350->mUnk_828 = 1;
                                func_0212ecc0(&data_0217d068, 0, 0x18);
                                break;
                            case 1:
                                data_0217b350->mUnk_828 = 0;
                                func_0212ecc0(&data_0217d068, 0, 0x17);
                                break;
                        }
                    } else {
                        switch (data_0217b350->mUnk_828) {
                            case 0:
                                data_0217b350->mUnk_828 = 1;
                                func_0212ecc0(&data_0217d068, 0, 0x18);
                                break;
                            case 1:
                                data_0217b350->mUnk_828 = 2;
                                func_0212ecc0(&data_0217d068, 0, 0x17);
                                break;
                            case 2:
                                data_0217b350->mUnk_828 = 0;
                                func_0212ecc0(&data_0217d068, 0, 0x17);
                                break;
                        }
                    }
                } else {
                    data_0217b350->mUnk_82c = 0;
                }
            }
            break;
        case 2:
            if (func_020a128c() != 0) {
                if (data_0217b350->mUnk_83c != 0) {
                    data_0217b350->mUnk_82c = 0;
                } else {
                    data_0217b350->mUnk_82c = 1;
                    data_0217b350->mUnk_828 = 4;
                    data_0217b350->mUnk_83c = 1;
                    data_0217b350->mUnk_840 = 1;
                    data_0217b350->mUnk_850 = 0x8c;
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
                    data_0217b350->mUnk_82c = 1;
                    switch (data_0217b350->mUnk_828) {
                        case 0:
                            data_0217b350->mUnk_828 = 1;
                            func_0212ecc0(&data_0217d068, 0, 0x18);
                            break;
                        case 1:
                            data_0217b350->mUnk_828 = 0;
                            func_0212ecc0(&data_0217d068, 0, 0x17);
                            break;
                    }
                } else {
                    data_0217b350->mUnk_82c = 0;
                }
            }
            break;
        case 3:
        case 5:
            if (data_0217561c->mUnk_4cc != 0 && data_021759c0->mUnk_00c == 0) {
                if (data_0217b350->mUnk_838 == 0) {
                    data_0217b350->mUnk_82c = 1;
                    data_0217b350->mUnk_828 = 4;
                    data_0217b350->mUnk_838 = 1;
                    if (data_0217b350->mUnk_83c == 0) {
                        data_0217b350->mUnk_83c = 1;
                        data_0217b350->mUnk_840 = 1;
                        data_0217b350->mUnk_850 = 0x8c;
                    }
                } else {
                    data_0217b350->mUnk_82c = 0;
                }
            } else if (func_0203c880(func_020b4d9c()) != 0 && data_021759c0->mUnk_00c == 0) {
                if (data_0217b350->mUnk_83c == 0) {
                    data_0217b350->mUnk_82c = 1;
                    data_0217b350->mUnk_828 = 0;
                    data_0217b350->mUnk_83c = 1;
                    data_0217b350->mUnk_840 = 1;
                    data_0217b350->mUnk_850 = 0x8c;
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
                        data_0217b350->mUnk_82c = 1;
                        switch (data_0217b350->mUnk_828) {
                            case 0:
                                data_0217b350->mUnk_828 = 3;
                                func_0212ecc0(&data_0217d068, 0, 0x18);
                                break;
                            case 3:
                                data_0217b350->mUnk_828 = 0;
                                func_0212ecc0(&data_0217d068, 0, 0x17);
                                break;
                        }
                    } else {
                        data_0217b350->mUnk_82c = 0;
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
                    data_0217b350->mUnk_82c = 1;
                    switch (data_0217b350->mUnk_828) {
                        case 0:
                            data_0217b350->mUnk_828 = 1;
                            func_0212ecc0(&data_0217d068, 0, 0x18);
                            break;
                        case 1:
                            data_0217b350->mUnk_828 = 0;
                            func_0212ecc0(&data_0217d068, 0, 0x17);
                            break;
                    }
                } else {
                    data_0217b350->mUnk_82c = 0;
                }
            }
            break;
        case 4:
            if (func_0203c174() != 0) {
                if (data_0217b350->mUnk_83c == 0) {
                    data_0217b350->mUnk_83c = 1;
                    data_0217b350->mUnk_840 = 1;
                    if (func_0203c880((u16) data_021759c0->mUnk_62) != 0) {
                        v = data_0217561c->mUnk_4e0;
                    } else {
                        v = 6;
                    }
                    if (v == 0) {
                        data_0217b350->mUnk_850 = 0xaf;
                    }
                }
            } else if (data_0217561c->mUnk_4cc != 0) {
                if (func_0203c880((u16) data_021759c0->mUnk_62) != 0) {
                    v = data_0217561c->mUnk_4e0;
                } else {
                    v = 6;
                }
                if (v != 0) {
                    data_0217b350->mUnk_84c = 1;
                }
            }
            if ((u16) (data_0217562c[func_020435bc()].mUnk_00 & 0x800) != 0) {
                func_0212ecc0(&data_0217d068, 0, 0x19);
            }
            data_0217b350->mUnk_82c = 0;
            break;
    }
    if (data_0217b350->mUnk_82c != 0) {
        switch (data_0217b350->mUnk_828) {
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
    if (data_0217b350->mUnk_90c != 0) {
        return;
    }
    if (data_021759c0->mUnk_08 == 4) {
        v = (data_021759c0->mUnk_08 == 4 ? data_021759c0->mMissionTableColumn : -1) == 9;
    } else {
        v = 0;
    }
    if (v == 0) {
        return;
    }
    if (data_021759c0->mUnk_08 != 4) {
        v = 0;
    } else {
        v = func_020a128c();
    }
    if (v == 0) {
        return;
    }
    if (data_021759c0->mUnk_08 != 4) {
        v = 0;
    } else {
        v = func_020a1084(func_020b4d9c());
    }
    if (v != 0) {
        data_0217b488->mUnk_10 = 0;
    } else {
        data_0217b488->mUnk_10 = data_0217b350->mUnk_910 == 0;
    }
    data_0217b350->mUnk_90c = 1;
}
