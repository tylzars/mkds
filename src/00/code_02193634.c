#include "00/code_02193634.h"

#include "00/code_021947e4.h"
#include "00/code_02196914.h"
#include "00/code_021965a0.h"
#include "00/code_021a3690.h"
#include "00/code_02196590.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "code_02135014.h"
#include "code_02139f70.h"
#include "code_02134d30.h"
#include "code_0213a460.h"
#include "00/code_021919ac.h"
#include "00/code_021906e4.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/code_02190ff8.h"
#include "00/code_02192d64.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/code_0218d818.h"
#include "00/code_02196000.h"
#include "00/code_02190000.h"
#include "00/code_0218f960.h"
#include "00/code_02194bb8.h"
#include "00/code_02193000.h"
#include "00/code_02193b88.h"
#include "00/code_021967b4.h"
#include "00/unk_021b3000.h"
#include "00/code_02190cd4.h"
#include "00/code_0218e2dc.h"
#include "00/code_02194000.h"
#include "00/unk_021b4000.h"
#include "00/code_021a3668.h"

s32 GpiQueueOperationCallback(GpConnection *connection, GpiOperation *operation) {
    GpiConnection *a = connection->mGpiConnection;
    GpiCallback b;
    Unk02193954_0 *c;
    Unk02193954_1 *d;
    Unk02193954_3 *e;
    Unk02193954_4 *f;
    s32 g;

    if (connection == NULL) {
        func_0213442c(data_ov000_021b32f0, data_ov000_021b32b0, NULL, 0x22);
    }
    if (connection->mGpiConnection == NULL) {
        func_0213442c(data_ov000_021b3304, data_ov000_021b32b0, NULL, 0x23);
    }
    if (operation == NULL) {
        func_0213442c(data_ov000_021b3318, data_ov000_021b32b0, NULL, 0x24);
    }
    b = operation->mUnk_0c;
    if (b.mCallback != NULL) {
        switch (operation->mType) {
            case 0:
                c = func_ov000_021a3690(0x20);
                if (c == NULL) {
                    GpiSetErrorMessage(connection, data_ov000_021b32e0);
                    return 1;
                }
                memset(c, 0, 0x20);
                c->mUnk_00 = operation->mUnk_1c;
                if (a->mErrorNumber == 0x201) {
                    c->mUnk_04 = a->mProfileId;
                    a->mProfileId = 0;
                }
                g = GpiQueueCallback(connection, b, c, operation, 0);
                if (g != 0) {
                    return g;
                }
                break;
            case 1:
                d = func_ov000_021a3690(8);
                if (d == NULL) {
                    GpiSetErrorMessage(connection, data_ov000_021b32e0);
                    return 1;
                }
                memset(d, 0, 8);
                d->mUnk_00 = operation->mUnk_1c;
                g = GpiQueueCallback(connection, b, d, operation, 0);
                if (g != 0) {
                    return g;
                }
                break;
            case 2:
                c = func_ov000_021a3690(0x204);
                if (c == NULL) {
                    GpiSetErrorMessage(connection, data_ov000_021b32e0);
                    return 1;
                }
                memset(c, 0, 0x204);
                c->mUnk_00 = operation->mUnk_1c;
                g = GpiQueueCallback(connection, b, c, operation, 0);
                if (g != 0) {
                    return g;
                }
                break;
            case 3:
                e = func_ov000_021a3690(0x10);
                if (e == NULL) {
                    GpiSetErrorMessage(connection, data_ov000_021b32e0);
                    return 1;
                }
                memset(e, 0, 0x10);
                e->mUnk_00 = operation->mUnk_1c;
                e->mUnk_0c = 0;
                g = GpiQueueCallback(connection, b, e, operation, 0);
                if (g != 0) {
                    return g;
                }
                break;
            case 4:
                f = func_ov000_021a3690(4);
                if (f == NULL) {
                    GpiSetErrorMessage(connection, data_ov000_021b32e0);
                    return 1;
                }
                memset(f, 0, 4);
                f->mUnk_00 = operation->mUnk_1c;
                g = GpiQueueCallback(connection, b, f, operation, 0);
                if (g != 0) {
                    return g;
                }
                break;
            default:
                func_0213442c(data_ov000_021b32ac, data_ov000_021b32b0, NULL, 0x6b);
                break;
        }
    }
    return 0;
}

u32 GpiCreateOperation(GpConnection *param_1, int param_2, int param_3, int *param_4, int param_5, int param_6,
                       int param_7) {
    GpiConnection *a = param_1->mGpiConnection;
    GpiOperation *b = func_ov000_021a3690(0x24);

    if (b == NULL) {
        GpiSetErrorMessage(param_1, data_ov000_021b32e0);
        return 1;
    }
    b->mType = param_2;
    b->mUnk_04 = (void *) param_3;
    b->mUnk_08 = param_5;
    b->mUnk_14 = 0;
    if (param_2 == 0) {
        b->mId = 1;
    } else {
        b->mId = a->mNextOperationId++;
        if (a->mNextOperationId < 2) {
            a->mNextOperationId = 2;
        }
    }
    b->mUnk_1c = 0;
    b->mUnk_0c.mCallback = (void (*)(void *, void *, u32)) param_6;
    b->mUnk_0c.mUnk_04 = param_7;
    b->mNext = a->mOperationList;
    a->mOperationList = b;
    *param_4 = (s32) b;
    return 0;
}

void GpiDeleteOperation(GpConnection *param_1, GpiOperation *param_2) {
    GpiConnection *a = param_1->mGpiConnection;
    Unk02193858 *b;

    if (param_2->mType == 3) {
        b = (Unk02193858 *) param_2->mUnk_04;
        a->mSearchCount--;
        if (a->mSearchCount < 0) {
            func_0213442c(data_ov000_021b32c0, data_ov000_021b32b0, NULL, 0xb6);
        }
        func_ov000_0218e524(b->mUnk_04, 2);
        func_ov000_0218e53c(b->mUnk_04);
        func_ov000_021a3668(b->mUnk_18);
        b->mUnk_18 = NULL;
        func_ov000_021a3668(b->mUnk_08);
        b->mUnk_08 = NULL;
    }
    func_ov000_021a3668(param_2->mUnk_04);
    param_2->mUnk_04 = NULL;
    func_ov000_021a3668(param_2);
}

void GpiRemoveOperation(GpConnection *param_1, GpiOperation *param_2) {
    GpiConnection *a = param_1->mGpiConnection;
    GpiOperation *b = a->mOperationList;
    GpiOperation *c = NULL;

    while (b != NULL) {
        if (b == param_2) {
            if (c == NULL) {
                a->mOperationList = b->mNext;
            } else {
                c->mNext = param_2->mNext;
            }
            GpiDeleteOperation(param_1, param_2);
            return;
        }
        c = b;
        b = b->mNext;
    }
}

BOOL GpiFindOperation(GpConnection *object, GpiOperation **output, u32 key) {
    GpiOperation *node = object->mGpiConnection->mOperationList;
    while (node != NULL) {
        if (node->mId == key) {
            if (output != NULL) {
                *output = node;
            }
            return TRUE;
        }
        node = node->mNext;
    }
    if (output != NULL) {
        *output = NULL;
    }
    return FALSE;
}

BOOL func_ov000_021937c0(GpConnection *object) {
    GpiOperation *node = object->mGpiConnection->mOperationList;
    while (node != NULL) {
        if (node->mUnk_08 != 0 && node->mType != 3) {
            return TRUE;
        }
        node = node->mNext;
    }
    return FALSE;
}

s32 GpiProcessOperation(GpConnection *c, GpiOperation *d, const char *e) {
    s32 a = 0;
    u32 b = d->mType;

    switch (b) {
        case 0:
            a = GpiProcessConnectOperation(c, d, e);
            break;
        case 1:
            a = func_ov000_02194a0c(c, d, e);
            break;
        case 2:
            a = GpiProcessInfoOperation(c, d, e);
            break;
        case 4:
            a = func_ov000_021964e4(c, d, e);
            break;
        default:
            func_ov000_0219690c(c, data_ov000_021b3264, b);
            func_0213442c(data_ov000_021b32ac, data_ov000_021b32b0, NULL, 0x146);
            break;
    }
    if (a != 0) {
        d->mUnk_1c = a;
    }
    return a;
}

u32 GpiIsValidDate(int a, int b, int c) {
    if (a == 0 && b == 0 && c == 0) {
        return 1;
    }
    if (a < 0 || b < 0 || c < 0) {
        return 0;
    }
    switch (b) {
        case 0:
            if (a != 0) {
                return 0;
            }
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (a > 0x1f) {
                return 0;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (a > 0x1e) {
                return 0;
            }
            break;
        case 2:
            if ((c % 4 == 0 && c % 100 != 0) || c % 400 == 0) {
                if (a > 0x1d) {
                    return 0;
                }
            } else if (a > 0x1c) {
                return 0;
            }
            break;
        default:
            return 0;
    }
    if (c < 0x76c) {
        return 0;
    }
    if (c > 0x81f) {
        return 0;
    }
    if (c == 0x81f) {
        if (b > 6) {
            return 0;
        }
        if (b == 6 && a > 6) {
            return 0;
        }
    }
    return 1;
}
