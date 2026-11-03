#include "00/code_021a998c.h"
#include "00/code_021aa054.h"
#include "00/code_021aa468.h"
#include "00/code_021ab728.h"
#include "00/code_021abca0.h"
#include "00/code_021adbac.h"
#include "00/types_021a998c.h"
#include "00/unk_021b6000.h"
#include "code_0214d018.h"

void func_ov000_021a998c(Unk021a998c *a) {
    u8 *msg;
    Unk021a998c_0c *obj;
    obj = a->mUnk_0c;
    msg = data_ov000_021b63a4(0x83);
    if (msg == NULL) {
        obj->mUnk_429 = 9;
        return;
    }
    msg[0] = 0x14;
    msg[1] = 3;
    msg[2] = 0;
    msg[3] = 0;
    msg[4] = 1;
    msg[5] = 1;
    func_0214d168(obj->mUnk_1a0, 0, 8);
    msg[6] = 0x16;
    msg[7] = 3;
    msg[8] = 0;
    msg[9] = 0;
    msg[10] = 0x28;
    msg[11] = 0x14;
    msg[12] = 0;
    msg[13] = 0;
    msg[14] = 0x24;
    func_0214d1fc(obj->mUnk_378, obj->mUnk_3d0, 0x58);
    func_ov000_021aa50c(obj, msg + 0xf, 0);
    func_0214d1fc(obj->mUnk_3d0, obj->mUnk_378, 0x58);
    func_0214d1fc(obj->mUnk_2c0, obj->mUnk_31c, 0x5c);
    func_ov000_021aa468(obj, msg + 0x1f, 0);
    func_0214d1fc(obj->mUnk_31c, obj->mUnk_2c0, 0x5c);
    func_ov000_021abca0(obj->mUnk_2c0, msg + 0xb, 0x28);
    func_ov000_021ab728(obj->mUnk_378, msg + 0xb, 0x28);
    func_ov000_021adcec(msg, func_ov000_021aa054(obj, msg + 6) + 6, NULL, 0, a);
    data_ov000_021b63ac(msg);
}
