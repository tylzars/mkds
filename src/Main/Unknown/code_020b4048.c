#include "Main/Unknown/code_020b4048.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020b41d4.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void func_020b409c(void) {
    if (func_020b41d4(1) != 0) {
        func_020b478c(&data_0217b39c, func_02047a28("LC_Font_s.NFTR"));
        func_020b478c(&data_0217b3a8, func_02047a28("LC_Font_m.NFTR"));
        func_020b478c(&data_0217b3b4, func_02047a28("marioFont.NFTR"));
        data_0217b390[0] = &data_0217b39c;
        data_0217b390[1] = &data_0217b3a8;
        data_0217b390[2] = &data_0217b3b4;
        func_020b4a7c(data_0217b368, func_02047a28("player_character_M_o.NCLR"));
        func_020b4a7c(data_0217b388, func_02047a28("player_character_M_shyguy_o.NCLR"));
        func_020b49f4(data_0217b370, func_02047a28("player_character_M.nce.ncgr"));
        func_020b48ec(data_0217b378, func_02047a28("player_character_M.nce.ncer"));
        data_0217b380[0] = func_02047a28("player_character_M.bncl");
        func_020b4a7c(&data_0217b36c, func_02047a28("player_character_L_o.NCLR"));
        func_020b4a7c(&data_0217b38c, func_02047a28("player_character_L_shyguy_o.NCLR"));
        func_020b49f4(&data_0217b374, func_02047a28("player_character_L.nce.ncgr"));
        func_020b48ec(&data_0217b37c, func_02047a28("player_character_L.nce.ncer"));
        data_0217b380[1] = func_02047a28("player_character_L.bncl");
    }
}

void func_020b4048(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 3; i++) {
        data_0217b390[i] = 0;
    }
    for (j = 0; j < 2; j++) {
        data_0217b368[j] = 0;
        data_0217b388[j] = 0;
        data_0217b370[j] = 0;
        data_0217b378[j] = 0;
        data_0217b380[j] = 0;
    }
}
#pragma thumb off
