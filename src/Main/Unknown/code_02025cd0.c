#include "Main/Unknown/code_02025cd0.h"

#pragma thumb on

void WriteMinuteSecondMillisecondText(short *text, u32 minute, u32 second, u32 millisecond) {
    text[0] = (minute / 10) % 10 + '0';
    text[1] = minute % 10 + '0';
    text[2] = ':';
    text[3] = (second / 10) % 10 + '0';
    text[4] = second % 10 + '0';
    text[5] = ':';
    text[6] = (millisecond / 100) % 10 + '0';
    text[7] = (millisecond / 10) % 10 + '0';
    text[8] = millisecond % 10 + '0';
    text[9] = 0;
}

#pragma thumb off
