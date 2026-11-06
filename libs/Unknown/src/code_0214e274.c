#include "code_0214e274.h"
#include "Main/Unknown/unk_0216f000.h"

// Returns the number of days from 2000-01-01 to date, or -1 when a field is out of range. The leap day counts from
// March on in years divisible by 4.
s32 RTC_ConvertDateToDay(const RTCDate *date) {
    s32 dayNum;

    if (date->mYear >= 100 || date->mMonth < 1 || date->mMonth > 12 || date->mDay < 1 || date->mDay > 31 ||
        date->mWeek >= RTC_WEEK_MAX || date->mMonth < 1 || date->mMonth > 12) {
        return -1;
    }
    dayNum = date->mDay - 1;
    dayNum += data_0216f074[date->mMonth];
    if (date->mMonth >= 3 && (date->mYear & 3) == 0) {
        dayNum++;
    }
    dayNum += date->mYear * 365;
    dayNum += (date->mYear + 3) / 4;
    return dayNum;
}
