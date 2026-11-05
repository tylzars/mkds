#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c70ec.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0d9c.h"

void func_020c7310(void) {
    s32 i;
    s32 k;
    s32 n;
    s32 c;
    Unk0217b498_00 *p;
    Vec3 *v;

    n = 0;
    c = func_020c0db0();
    k = 0;
    for (i = 0; i < data_0217b3fc->mUnk_08; i++) {
        if (data_0217b3f8 == 0 || func_020b5f68(&data_0217b3fc->mUnk_0c[i]) != FALSE) {
            p = data_0217b3fc->mUnk_00[i];
            if ((p->mUnk_02 & 1) == 0) {
                v = &p->mUnk_04;
                if (func_020b5ae8(v, &data_0217b3fc->mUnk_10[k].mUnk_00, c, 0, 0) != FALSE) {
                    data_0217b3fc->mUnk_10[k].mUnk_08 = GetRaceSNcerEntry(0x4e);
                    data_0217b3fc->mUnk_10[k].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    data_0217b3fc->mUnk_10[k].mUnk_0e = p->mUnk_02 & 0x20;
                    n++;
                    k++;
                }
            }
        }
    }
    data_0217b3fc->mUnk_04 = n;
}

void func_020c72f4(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b3fc, 0);
}

void func_020c7164(void) {
    u8 a;
    u8 b;
    u16 c;
    u8 d;
    u8 e;
    u16 f;
    s32 j;
    s32 t;
    Unk02056bc0 *q;
    Unk02056bc0 *r;

    if (data_021759c0->mMode != 1) {
        return;
    }
    if (gRaceNewRecordTa == NULL) {
        return;
    }
    if (data_021759c0->mUnk_00c == 0) {
        gRaceNewRecordTa->mUnk_08 = func_020c657c(0);
        gRaceNewRecordTa->mUnk_10 = func_020c6428(0);
        return;
    }
    GetKartFinishTime(func_020b4d9c(), &a, &b, &c);
    r = gRaceNewRecordTa->mRecords;
    t = b * 1000 + a * 60000 + c;
    for (j = 4; j >= 0; j--) {
        q = &r[j];
        if (q->mUnk_18 != 0 && t == q->mUnk_00 + (q->mUnk_03 * 1000 + q->mUnk_02 * 60000)) {
            j = 1;
            goto found;
        }
    }
    j = 0;
found:
    gRaceNewRecordTa->mUnk_08 = j;
    q = &gRaceNewRecordTa->mRecords[5];
    gRaceNewRecordTa->mUnk_14 = GetKartBestLapTime(func_020b4d9c(), &d, &e, &f);
    gRaceNewRecordTa->mUnk_10 = (d == q->mUnk_02 && e == q->mUnk_03 && f == q->mUnk_00) ? 1 : 0;
}

s32 func_020c7148(void) {
    return gRaceNewRecordTa != NULL ? gRaceNewRecordTa->mUnk_08 : 0;
}

BOOL func_020c7108(void) {
    if (gRaceNewRecordTa != NULL) {
        if (gRaceNewRecordTa->mUnk_08 != 0) {
            if (gRaceNewRecordTa->mUnk_0c == 0) {
                return TRUE;
            }
        }
        return FALSE;
    }
    return FALSE;
}

s32 func_020c70ec(void) {
    return gRaceNewRecordTa != NULL ? gRaceNewRecordTa->mUnk_10 : 0;
}
