#include "Main/Unknown/code_020d2c2c.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/code_020d6000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d2000.h"

#pragma thumb on

// non-matching: the compiled code keeps the stack-passed fifth argument in r7 and the loop counter in memory, the
// original keeps the counter in r6 and the byte offset in r7; the two zero vectors are built the same way; one word
// longer
s32 func_020d2c2c(Vec3 *param_1, Vec3 *param_2, s32 param_3, s16 param_4, s32 param_5, Vec3 *param_6) {
    s32 a;
    s32 i;
    a = 0;
    func_01ffd900(param_4, 0x2000);
    i = 0;
    if (data_0217b5a8 != 0) {
        Vec3 v;
        Vec3 mn;
        Vec3 mx;
        Vec3 z1;
        Vec3 z2;
        Unk020e71a0 *p;
        Unk020f41c4_A *q;
        s32 r;
        z1.x = 0;
        z1.y = 0;
        z1.z = 0;
        mn = z1;
        z2.x = 0;
        z2.y = 0;
        z2.z = 0;
        mx = z2;
        q = &data_0217b4f0->mUnk_18c;
        for (; i < data_0217b5a8; i++) {
            p = data_0217b5c4[i];
            if (func_020d3e34(param_1, param_3, p, &v) != 0) {
                if (!(p->mUnk_02 & 0x40) && func_020d6968(param_5, p) != 0) {
                    mn.x = v.x < mn.x ? v.x : mn.x;
                    mn.y = v.y < mn.y ? v.y : mn.y;
                    mn.z = v.z < mn.z ? v.z : mn.z;
                    mx.x = v.x > mx.x ? v.x : mx.x;
                    mx.y = v.y > mx.y ? v.y : mx.y;
                    mx.z = v.z > mx.z ? v.z : mx.z;
                }
                q->mUnk_50 = *param_1;
                q->mUnk_5c = *param_2;
                q->mUnk_44 = param_5;
                r = func_020d6a54(q, p, 0);
                if (r > a) {
                    a = r;
                }
            }
        }
        if (a != 0 && param_6 != 0) {
            param_6->x = mx.x + mn.x;
            param_6->y = mx.y + mn.y;
            if (param_6->y < 0) {
                param_6->y = 0;
            }
            param_6->z = mx.z + mn.z;
        }
    }
    return a;
}

#pragma thumb off
