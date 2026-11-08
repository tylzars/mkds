#include "Main/Unknown/code_020c2118.h"
#include "Main/Unknown/code_020c214c.h"

void DrawRaceGoalS(RaceHudOamBuffer *oamBuffer) {
    int state;
    state = GetRaceHudSubScreenState();
    if (state != 5) {
        DrawRaceGoalSKarts(oamBuffer);
        return;
    }
    DrawRaceGoalSTeams(oamBuffer);
}
