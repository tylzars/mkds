#include "03/code_021c38f0.h"
#include "03/code_021bf810.h"
#include "03/code_021bf000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/code_021bf410.h"
#include "03/code_021c209c.h"
#include "03/code_021c36ec.h"
#include "03/code_021c3758.h"
#include "03/code_021c388c.h"

void SetupJb5Info(void) {
    LoadJb5InfoFileAndSetBgCnt();
    func_ov003_021bf86c(0x11);
    func_ov003_021bf43c(0x89, -1, 0);
    PrintJb5Info();
    func_ov003_021c212c(func_ov003_021c371c);
}
