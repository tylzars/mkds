#include "01/code_0218c790.h"

#include "01/code_0218dce4.h"
#include "01/code_02185ef4.h"
#include "Main/Unknown/code_0209b000.h"
#include "01/code_02181000.h"
#include "01/code_0218e000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_0209b60c.h"
#include "Main/Unknown/code_02110000.h"
#include "Main/Unknown/code_0209bef0.h"

u32 GetMapObjectNsbtpFrameIndex(Unk02188950 *mapObject) {
    return GetMapObjectModelNsbtpFrameIndex(mapObject->mNsbmd);
}
