#include "03/code_021c1648.h"
#include "03/code_021c1000.h"

#include "03/code_021c105c.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d2940.h"
#include "03/code_021d250c.h"
#include "03/unk_021d6000.h"
#include "03/unk_021da000.h"

void func_ov003_021c1a44(void) {
    func_ov003_021c1908();
    func_ov003_021c17d4();
    func_ov003_021c1680();
    func_ov003_021c1510();
    return;
}

void func_ov003_021c1908(void) {
    Unk021d299c a;
    u16 *q;
    int j;
    int i;
    u16 *p;
    if (func_ov003_021d2a34(&data_ov003_021d67e8) == 0) {
        return;
    }
    data_ov003_021da160->mUnk_61 = -1;
    for (i = 0, p = data_ov003_021d6274; i < 10; p += 2, i++) {
        func_ov003_021d250c(p, data_ov003_021d622c, &a);
        if (func_ov003_021d2a34(&a) != 0) {
            if (data_ov003_021da160->mUnk_67 == 0) {
                func_ov003_021cdc10(9);
                return;
            }
            func_ov003_021cdc10(0);
            data_ov003_021da160->mUnk_61 = i;
            return;
        }
    }
    for (j = 0, q = data_ov003_021d623c; j < 2; q += 2, j++) {
        func_ov003_021d250c(q, data_ov003_021d6234, &a);
        if (func_ov003_021d2a34(&a) != 0) {
            if ((j == 0 && data_ov003_021da160->mUnk_66 == 0) || (j == 1 && data_ov003_021da160->mUnk_68 == 0)) {
                func_ov003_021cdc10(9);
                return;
            }
            func_ov003_021cdc10(0);
            data_ov003_021da160->mUnk_61 = j + 10;
            return;
        }
    }
    for (j = 0, p = data_ov003_021d6244; j < 2; p += 2, j++) {
        func_ov003_021d250c(p, data_ov003_021d6238, &a);
        if (func_ov003_021d2a34(&a) != 0) {
            func_ov003_021cdc10(0);
            data_ov003_021da160->mUnk_61 = j + 12;
            return;
        }
    }
}

void func_ov003_021c17d4(void) {
    Unk021d299c a;
    u16 *q;
    int j;
    int i;
    u16 *p;
    data_ov003_021da160->mUnk_60 = 0;
    if (func_ov003_021d299c(&data_ov003_021d67e8) == 0) {
        return;
    }
    for (i = 0, p = data_ov003_021d6274; i < 10; p += 2, i++) {
        func_ov003_021d250c(p, data_ov003_021d622c, &a);
        if (func_ov003_021d299c(&a) != 0) {
            if (data_ov003_021da160->mUnk_61 != i) {
                return;
            }
            data_ov003_021da160->mUnk_60 = data_ov003_021d624c[i];
            data_ov003_021da160->mUnk_63 = i;
            func_ov003_021c1268();
            return;
        }
    }
    for (j = 0, q = data_ov003_021d623c; j < 2; q += 2, j++) {
        func_ov003_021d250c(q, data_ov003_021d6234, &a);
        if (func_ov003_021d299c(&a) != 0) {
            if (data_ov003_021da160->mUnk_61 != j + 10) {
                return;
            }
            data_ov003_021da160->mUnk_60 = data_ov003_021d6228[j];
            data_ov003_021da160->mUnk_63 = j + 10;
            func_ov003_021c1268();
            return;
        }
    }
    for (j = 0, p = data_ov003_021d6244; j < 2; p += 2, j++) {
        func_ov003_021d250c(p, data_ov003_021d6238, &a);
        if (func_ov003_021d299c(&a) != 0) {
            if (data_ov003_021da160->mUnk_61 != j + 12) {
                return;
            }
            data_ov003_021da160->mUnk_60 = data_ov003_021d6224[j];
            data_ov003_021da160->mUnk_63 = j + 12;
            func_ov003_021c1268();
            return;
        }
    }
}

void func_ov003_021c1680(void) {
    Unk021d299c a;
    u16 *q;
    int j;
    int i;
    u16 *p;
    if (func_ov003_021d2a80(&data_ov003_021d67e8) == 0) {
        goto label_1;
    }
    for (i = 0, p = data_ov003_021d6274; i < 10; p += 2, i++) {
        func_ov003_021d250c(p, data_ov003_021d622c, &a);
        if (func_ov003_021d2a80(&a) != 0) {
            if (data_ov003_021da160->mUnk_61 != i) {
                goto label_1;
            }
            func_ov003_021c1648(i);
            goto label_2;
        }
    }
    for (j = 0, q = data_ov003_021d623c; j < 2; q += 2, j++) {
        func_ov003_021d250c(q, data_ov003_021d6234, &a);
        if (func_ov003_021d2a80(&a) != 0) {
            if (data_ov003_021da160->mUnk_61 != j + 10) {
                goto label_1;
            }
            func_ov003_021c1648(j + 10);
            if (j != 0) {
                goto label_2;
            }
            data_ov003_021da160->mUnk_65 = data_ov003_021da160->mUnk_65 + 1;
            if (data_ov003_021da160->mUnk_65 >= 0x28) {
                if (data_ov003_021da160->mUnk_66 == 0) {
                    func_ov003_021cdc10(9);
                    data_ov003_021da160->mUnk_61 = -1;
                    return;
                }
                data_ov003_021da160->mUnk_60 = 0x10;
                data_ov003_021da160->mUnk_65 = data_ov003_021da160->mUnk_65 - 7;
                return;
            }
            return;
        }
    }
    for (j = 0, p = data_ov003_021d6244; j < 2; p += 2, j++) {
        func_ov003_021d250c(p, data_ov003_021d6238, &a);
        if (func_ov003_021d2a80(&a) != 0) {
            j += 12;
            if (data_ov003_021da160->mUnk_61 != j) {
                goto label_1;
            }
            func_ov003_021c1648(j);
            goto label_2;
        }
    }
label_1:
    func_ov003_021c1648(-1);
label_2:
    data_ov003_021da160->mUnk_65 = 0;
}

void func_ov003_021c1648(int a) {
    if (a != data_ov003_021da160->mUnk_62) {
        func_ov003_021c12cc(a, 1);
        func_ov003_021c12cc(data_ov003_021da160->mUnk_62, 0);
        data_ov003_021da160->mUnk_62 = (s8) a;
    }
    return;
}
