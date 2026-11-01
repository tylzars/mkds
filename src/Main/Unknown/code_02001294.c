#include "Main/Unknown/code_02001294.h"

void func_02001294(void) {
    Unk021a99c0_18 *v1;
    if (func_02125f54() != 0) {
        func_02125ebc(35);
        func_02125fc0();
        return;
    }
    if (func_02125f88() == 0) {
        return;
    }
    v1 = &data_usa_ov001_021a99c0->mUnk_18;
    v1->mUnk_10 = 8;
    v1->mUnk_12 = 1;
}

void func_02001300(void) {
    void *v1;
    func_02125ebc(33);
    v1 = func_020b3f7c(data_usa_ov001_021a99c0->mUnk_38, 127);
    func_02126230(v1, func_020b3f7c(data_usa_ov001_021a99c0->mUnk_38, 4));
}

void func_02001350(void) {
    Unk021a99c0 *v1;
    s32 v2;
    Unk021a99c0_18 *v3;
    data_usa_ov001_021a99c0->mUnk_34 = data_usa_ov001_021a99c0->mUnk_34 + 1;
    v1 = data_usa_ov001_021a99c0;
    if (v1->mUnk_2c_0 != 0) {
        if (func_02125f6c() != 0) {
            func_02105ac0(34);
        }
        if (data_0217aa08->mUnk_28 == 0) {
            if (data_021759d4->mUnk_0c != 0) {
                v2 = data_021759d4->mUnk_10;
            } else {
                v2 = 0;
            }
        } else {
            v2 = 1;
        }
        if (v2 != 0) {
            return;
        }
        if (func_02125fa4() == 0) {
            return;
        }
        if (data_usa_ov001_021a99c0->mUnk_34 > 90) {
            v3 = &data_usa_ov001_021a99c0->mUnk_18;
            v3->mUnk_10 = 7;
            v3->mUnk_12 = 1;
        }
    } else {
        if (data_0217aa08->mUnk_28 == 0) {
            if (data_021759d4->mUnk_0c != 0) {
                v2 = data_021759d4->mUnk_10;
            } else {
                v2 = 0;
            }
        } else {
            v2 = 1;
        }
        if (v2 == 0) {
            v3 = &v1->mUnk_18;
            v3->mUnk_10 = 8;
            v3->mUnk_12 = 1;
        }
    }
}

void func_0200148c(void) {
    void *v1;
    func_02057130();
    if (data_usa_ov001_021a99c0->mUnk_2c_0 == 0) {
        return;
    }
    v1 = func_020b3f7c(data_usa_ov001_021a99c0->mUnk_38, 126);
    func_02126248((u32) v1, 1, 1, 1, 0, 1);
    data_usa_ov001_021a99c0->mUnk_34 = 0;
}

void func_02001500(void) {
    Unk021a99c0_18 *v1;
    if (func_02125f54() != 0) {
        func_02125fc0();
        return;
    }
    if (func_02125f88() == 0) {
        return;
    }
    if (func_02125f60() == 0) {
        v1 = &data_usa_ov001_021a99c0->mUnk_18;
        v1->mUnk_10 = 6;
        v1->mUnk_12 = 1;
        return;
    }
    v1 = &data_usa_ov001_021a99c0->mUnk_18;
    v1->mUnk_10 = 8;
    v1->mUnk_12 = 1;
}

void func_02001598(void) {
    void *v1;
    void *v2;
    void *v3;
    void *v4;
    v1 = func_02047a28(data_usa_ov001_021a7680);
    v2 = func_020b3f7c(v1, 124);
    v3 = func_020b3f7c(v1, 0);
    v4 = func_020b3f7c(v1, 1);
    func_0212611c(v2, v3, v4, 1);
}

void func_020015f0(void) {
    Unk021a99c0_18 *v1;
    if (func_02125f54() != 0) {
        func_02125ebc(35);
        func_02125fc0();
        return;
    }
    if (func_02125f88() == 0) {
        return;
    }
    v1 = &data_usa_ov001_021a99c0->mUnk_18;
    v1->mUnk_10 = 8;
    v1->mUnk_12 = 1;
}

void func_0200165c(void) {
    void *v1;
    func_02125ebc(33);
    v1 = func_020b3f7c(data_usa_ov001_021a99c0->mUnk_38, 128);
    func_02126230(v1, func_020b3f7c(data_usa_ov001_021a99c0->mUnk_38, 4));
}

void func_020016ac(void) {
    s32 v1;
    Unk021a99c0_18 *v2;
    data_usa_ov001_021a99c0->mUnk_34 = data_usa_ov001_021a99c0->mUnk_34 + 1;
    if (func_02125f6c() != 0) {
        func_02105ac0(34);
    }
    if (data_0217aa08->mUnk_28 == 0) {
        if (data_021759d4->mUnk_0c != 0) {
            v1 = data_021759d4->mUnk_10;
        } else {
            v1 = 0;
        }
    } else {
        v1 = 1;
    }
    if (v1 != 0) {
        return;
    }
    if (func_02125fa4() == 0) {
        return;
    }
    if (data_usa_ov001_021a99c0->mUnk_34 > 90) {
        v2 = &data_usa_ov001_021a99c0->mUnk_18;
        v2->mUnk_10 = 4;
        v2->mUnk_12 = 1;
    }
}

void func_02001770(void) {
    void *v1;
    func_02056e48();
    v1 = func_020b3f7c(data_usa_ov001_021a99c0->mUnk_38, 126);
    func_02126248((u32) v1, 1, 1, 1, 0, 1);
    data_usa_ov001_021a99c0->mUnk_34 = 0;
}

void func_020017cc(void) {
    Unk021a99c0_18 *v1;
    if (func_02125f54() != 0) {
        func_02125fc0();
        return;
    }
    if (func_02125f88() == 0) {
        return;
    }
    v1 = &data_usa_ov001_021a99c0->mUnk_18;
    v1->mUnk_10 = 3;
    v1->mUnk_12 = 1;
}

void func_02001830(void) {
    void *v1;
    v1 = func_020b3f7c(data_usa_ov001_021a99c0->mUnk_38, 125);
    func_02126230(v1, func_020b3f7c(data_usa_ov001_021a99c0->mUnk_38, 4));
}

void func_02001878(void) {
    s32 v1;
    Unk021a99c0_18 *v2;
    s32 v3;
    Unk021a99c0 *v4;
    if (data_0217aa08->mUnk_28 == 0) {
        if (data_021759d4->mUnk_0c != 0) {
            v1 = data_021759d4->mUnk_10;
        } else {
            v1 = 0;
        }
    } else {
        v1 = 1;
    }
    if (v1 != 0) {
        return;
    }
    v3 = data_0217aa08->mUnk_2c;
    if (v3 != 0) {
        if (v3 == 3) {
            data_usa_ov001_021a99c0->mUnk_2c_1 = 1;
            v2 = &data_usa_ov001_021a99c0->mUnk_18;
            v2->mUnk_10 = 2;
            v2->mUnk_12 = 1;
        } else if ((u32) data_021759d4->mUnk_04 == 4) {
            data_usa_ov001_021a99c0->mUnk_2c_1 = 0;
            v2 = &data_usa_ov001_021a99c0->mUnk_18;
            v2->mUnk_10 = 6;
            v2->mUnk_12 = 1;
        } else {
            v2 = &data_usa_ov001_021a99c0->mUnk_18;
            v2->mUnk_10 = 8;
            v2->mUnk_12 = 1;
        }
    } else {
        v4 = data_usa_ov001_021a99c0;
        if (v4->mUnk_2c_0 != 0) {
            v2 = &v4->mUnk_18;
            v2->mUnk_10 = 5;
            v2->mUnk_12 = 1;
        } else {
            v2 = &v4->mUnk_18;
            v2->mUnk_10 = 8;
            v2->mUnk_12 = 1;
        }
    }
}
