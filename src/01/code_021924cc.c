#include "01/code_021924cc.h"
#include "01/code_02181b54.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "01/code_02192000.h"
#include "Main/Unknown/unk_02175000.h"

void func_ov001_02192694(void) {
    Vec3 pos;
    Unk02188950 *obj;
    Unk02188950_a0 *a0;
    Unk0206bcb0 *other;
    int idx;
    u16 ang;

    if (data_021759c0->mUnk_08 == 4) {
        obj = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2));
    } else {
        obj = 0;
    }
    other = func_0207a974((u16) data_021759c0->mUnk_62);
    if (obj->mUnk_0a8 == 4) {
        a0 = obj->mUnk_0a0;
        ang = func_02148714(other->mUnk_80.z - obj->mUnk_000.mUnk_04.z, other->mUnk_80.x - obj->mUnk_000.mUnk_04.x) -
              a0->mUnk_26c;
    } else {
        a0 = obj->mUnk_0a0;
        ang = a0->mUnk_26c +
              func_02148714(other->mUnk_80.z - obj->mUnk_000.mUnk_04.z, other->mUnk_80.x - obj->mUnk_000.mUnk_04.x);
    }
    idx = (ang >> 4) * 2;
    pos.x = obj->mUnk_000.mUnk_04.x + (s32) (((s64) a0->mUnk_270 * data_0215d4b4[idx + 1]) >> 12);
    pos.y = obj->mUnk_000.mUnk_04.y;
    pos.z = obj->mUnk_000.mUnk_04.z + (s32) (((s64) obj->mUnk_0a0->mUnk_270 * data_0215d4b4[idx]) >> 12);
    func_ov001_02188998(obj, &pos);
}

void func_ov001_021924cc(void) {
    Vec3 b;
    Vec3 c;
    Vec3 a;
    Unk02188950 *objB;
    Unk02188950 *obj;
    Unk02188950 *objC;

    if (data_021759c0->mUnk_08 == 4) {
        objB = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2));
    } else {
        objB = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        obj = func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0));
    } else {
        obj = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        objC = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        objC = 0;
    }
    a.x = (s32) (((s64) objB->mUnk_0a0->mUnk_274 * data_0215d4b4[((u16) objB->mUnk_184 >> 4) * 2]) >> 12);
    a.y = objB->mUnk_000.mUnk_04.y;
    a.z = (s32) (((s64) objB->mUnk_0a0->mUnk_274 * data_0215d4b4[((u16) objB->mUnk_184 >> 4) * 2 + 1]) >> 12);
    b.x = -(s32) (((s64) objB->mUnk_0a0->mUnk_278 * data_0215d4b4[((u16) objB->mUnk_184 >> 4) * 2 + 1]) >> 12);
    b.y = objB->mUnk_000.mUnk_04.y;
    b.z = (s32) (((s64) objB->mUnk_0a0->mUnk_278 * data_0215d4b4[((u16) objB->mUnk_184 >> 4) * 2]) >> 12);
    c.x = (s32) (((s64) objB->mUnk_0a0->mUnk_278 * data_0215d4b4[((u16) objB->mUnk_184 >> 4) * 2 + 1]) >> 12);
    c.y = objB->mUnk_000.mUnk_04.y;
    c.z = -(s32) (((s64) objB->mUnk_0a0->mUnk_278 * data_0215d4b4[((u16) objB->mUnk_184 >> 4) * 2]) >> 12);
    func_ov001_02188968(obj, &a);
    func_ov001_02188968(objC, &a);
    func_ov001_02188980(obj, &b);
    func_ov001_02188980(objC, &c);
}
