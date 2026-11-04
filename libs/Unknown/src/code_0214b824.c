#include "code_0214b824.h"
#include "code_0214c778.h"
#include "code_0214cfe4.h"
#include "code_02148950.h"
#include "code_02149e90.h"
#include "code_02149fe0.h"
#include "code_0214a000.h"
#include "code_0214a054.h"
#include "code_0214a2c0.h"
#include "code_0214a314.h"
#include "code_0214a034.h"
#include "code_0214a2a0.h"
#include "code_0214a2f4.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0216f000.h"

void func_0214c160(const void *a, u32 b, u32 c) {
    if (data_0216f074[0] != -1 && c > 0x1c) {
        func_0214cb10(data_0216f074[0], a, (void *) (0x5000000 + b), c);
    } else {
        MemCopyHalfwords(a, (void *) (0x5000000 + b), c);
    }
}

void func_0214c0f8(const void *a, u32 b, u32 c) {
    if (data_0216f074[0] != -1 && c > 0x1c) {
        func_0214cb10(data_0216f074[0], a, (void *) (0x5000400 + b), c);
    } else {
        MemCopyHalfwords(a, (void *) (0x5000400 + b), c);
    }
}

void func_0214c090(const void *a, u32 b, u32 c) {
    if (data_0216f074[0] != -1 && c > 0x1c) {
        func_0214cb10(data_0216f074[0], a, (void *) (0x5000200 + b), c);
    } else {
        MemCopyHalfwords(a, (void *) (0x5000200 + b), c);
    }
}

void func_0214c028(const void *a, u32 b, u32 c) {
    if (data_0216f074[0] != -1 && c > 0x1c) {
        func_0214cb10(data_0216f074[0], a, (void *) (0x5000600 + b), c);
    } else {
        MemCopyHalfwords(a, (void *) (0x5000600 + b), c);
    }
}

void func_0214bfcc(const void *a, u32 b, u32 c) {
    if (data_0216f074[0] != -1 && c > 0x30) {
        func_0214cb88(data_0216f074[0], a, (void *) (0x7000000 + b), c);
    } else {
        MemCopyWords(a, (void *) (0x7000000 + b), c);
    }
}

void func_0214bf64(const void *a, u32 b, u32 c) {
    if (data_0216f074[0] != -1 && c > 0x30) {
        func_0214cb88(data_0216f074[0], a, (void *) (0x7000400 + b), c);
    } else {
        MemCopyWords(a, (void *) (0x7000400 + b), c);
    }
}

void func_0214bf04(const void *a, u32 b, u32 c) {
    enum { K0 } d = 0x6400000;

    if (data_0216f074[0] != -1 && c > 0x30) {
        func_0214cb88(data_0216f074[0], a, (void *) (d + b), c);
    } else {
        MemCopyWords(a, (void *) (d + b), c);
    }
}

void func_0214bea4(const void *a, u32 b, u32 c) {
    enum { K0 } d = 0x6600000;

    if (data_0216f074[0] != -1 && c > 0x30) {
        func_0214cb88(data_0216f074[0], a, (void *) (d + b), c);
    } else {
        MemCopyWords(a, (void *) (d + b), c);
    }
}

void MemCopyHalfwordsToG2Bg0CntBits8To12Address(const void *a, u32 b, u32 c) {
    u32 n = G2Bg0CntBits8To12Address();
    if (data_0216f074[0] != -1 && c > 0x1c) {
        func_0214cb10(data_0216f074[0], a, (void *) (n + b), c);
    } else {
        MemCopyHalfwords(a, (void *) (n + b), c);
    }
}

void MemCopyHalfwordsToG2sBg0CntBits8To12Address(const void *a, u32 b, u32 c) {
    u32 n = G2sBg0CntBits8To12Address();
    if (data_0216f074[0] != -1 && c > 0x1c) {
        func_0214cb10(data_0216f074[0], a, (void *) (n + b), c);
    } else {
        MemCopyHalfwords(a, (void *) (n + b), c);
    }
}

void MemCopyHalfwordsToG2Bg1CntBits8To12Address(const void *a, u32 b, u32 c) {
    u32 n = G2Bg1CntBits8To12Address();
    if (data_0216f074[0] != -1 && c > 0x1c) {
        func_0214cb10(data_0216f074[0], a, (void *) (n + b), c);
    } else {
        MemCopyHalfwords(a, (void *) (n + b), c);
    }
}

void MemCopyHalfwordsToG2sBg1CntBits8To12Address(const void *a, u32 b, u32 c) {
    u32 n = G2sBg1CntBits8To12Address();
    if (data_0216f074[0] != -1 && c > 0x1c) {
        func_0214cb10(data_0216f074[0], a, (void *) (n + b), c);
    } else {
        MemCopyHalfwords(a, (void *) (n + b), c);
    }
}

void MemCopyHalfwordsToG2Bg2CntBits8To12Address(const void *a, u32 b, u32 c) {
    u32 n = G2Bg2CntBits8To12Address();
    if (data_0216f074[0] != -1 && c > 0x1c) {
        func_0214cb10(data_0216f074[0], a, (void *) (n + b), c);
    } else {
        MemCopyHalfwords(a, (void *) (n + b), c);
    }
}

void MemCopyHalfwordsToG2sBg2CntBits8To12Address(const void *a, u32 b, u32 c) {
    u32 n = G2sBg2CntBits8To12Address();
    if (data_0216f074[0] != -1 && c > 0x1c) {
        func_0214cb10(data_0216f074[0], a, (void *) (n + b), c);
    } else {
        MemCopyHalfwords(a, (void *) (n + b), c);
    }
}

void MemCopyHalfwordsToG2Bg3CntBits8To12Address(const void *a, u32 b, u32 c) {
    u32 n = G2Bg3CntBits8To12Address();
    if (data_0216f074[0] != -1 && c > 0x1c) {
        func_0214cb10(data_0216f074[0], a, (void *) (n + b), c);
    } else {
        MemCopyHalfwords(a, (void *) (n + b), c);
    }
}

void MemCopyHalfwordsToG2sBg3CntBits8To12Address(const void *a, u32 b, u32 c) {
    u32 n = G2sBg3CntBits8To12Address();
    if (data_0216f074[0] != -1 && c > 0x1c) {
        func_0214cb10(data_0216f074[0], a, (void *) (n + b), c);
    } else {
        MemCopyHalfwords(a, (void *) (n + b), c);
    }
}

void MemCopyWordsToG2Bg0CntBits2To5Address(const void *a, u32 b, u32 c) {
    u32 n = G2Bg0CntBits2To5Address();
    if (data_0216f074[0] != -1 && c > 0x30) {
        func_0214cb88(data_0216f074[0], a, (void *) (n + b), c);
    } else {
        MemCopyWords(a, (void *) (n + b), c);
    }
}

void MemCopyWordsToG2sBg0CntBits2To5Address(const void *a, u32 b, u32 c) {
    u32 n = G2sBg0CntBits2To5Address();
    if (data_0216f074[0] != -1 && c > 0x30) {
        func_0214cb88(data_0216f074[0], a, (void *) (n + b), c);
    } else {
        MemCopyWords(a, (void *) (n + b), c);
    }
}

void MemCopyWordsToG2Bg1CntBits2To5Address(const void *a, u32 b, u32 c) {
    u32 n = G2Bg1CntBits2To5Address();
    if (data_0216f074[0] != -1 && c > 0x30) {
        func_0214cb88(data_0216f074[0], a, (void *) (n + b), c);
    } else {
        MemCopyWords(a, (void *) (n + b), c);
    }
}

void MemCopyWordsToG2sBg1CntBits2To5Address(const void *a, u32 b, u32 c) {
    u32 n = G2sBg1CntBits2To5Address();
    if (data_0216f074[0] != -1 && c > 0x30) {
        func_0214cb88(data_0216f074[0], a, (void *) (n + b), c);
    } else {
        MemCopyWords(a, (void *) (n + b), c);
    }
}

void MemCopyWordsToG2Bg2CntBits2To5Address(const void *a, u32 b, u32 c) {
    u32 n = G2Bg2CntBits2To5Address();
    if (data_0216f074[0] != -1 && c > 0x30) {
        func_0214cb88(data_0216f074[0], a, (void *) (n + b), c);
    } else {
        MemCopyWords(a, (void *) (n + b), c);
    }
}

void MemCopyWordsToG2sBg2CntBits2To5Address(const void *a, u32 b, u32 c) {
    u32 n = G2sBg2CntBits2To5Address();
    if (data_0216f074[0] != -1 && c > 0x30) {
        func_0214cb88(data_0216f074[0], a, (void *) (n + b), c);
    } else {
        MemCopyWords(a, (void *) (n + b), c);
    }
}

void MemCopyWordsToG2Bg3CntBits2To5Address(const void *a, u32 b, u32 c) {
    u32 n = G2Bg3CntBits2To5Address();
    if (data_0216f074[0] != -1 && c > 0x30) {
        func_0214cb88(data_0216f074[0], a, (void *) (n + b), c);
    } else {
        MemCopyWords(a, (void *) (n + b), c);
    }
}

void MemCopyWordsToG2sBg3CntBits2To5Address(const void *a, u32 b, u32 c) {
    u32 n = G2sBg3CntBits2To5Address();
    if (data_0216f074[0] != -1 && c > 0x30) {
        func_0214cb88(data_0216f074[0], a, (void *) (n + b), c);
    } else {
        MemCopyWords(a, (void *) (n + b), c);
    }
}
