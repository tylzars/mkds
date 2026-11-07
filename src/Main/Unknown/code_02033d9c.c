#include "Main/Unknown/code_02033d9c.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

void StartResultsBattleChoices(void) {
    void *firstText;
    void *secondText;
    firstText = GetBmgEntry(gResultsBattle->mCommonMessages, 0x5d);
    secondText = GetBmgEntry(gResultsBattle->mCommonMessages, 0x5f);
    StartSelectChoises(firstText, secondText, 0);
}

#pragma thumb off
