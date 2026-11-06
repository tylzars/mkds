#include "code_0214e1e0.h"
#include "code_0214e274.h"
#include "code_0214e258.h"

// Returns the day count of date times 86400 plus the seconds of time, or -1 when either is out of range.
s64 RTC_ConvertDateTimeToSecond(const RTCDate *date, const RTCTime *time) {
    s32 day;
    s32 sec;

    day = RTC_ConvertDateToDay(date);
    if (day == -1) {
        return -1;
    }
    sec = RTCi_ConvertTimeToSecond(time);
    if (sec == -1) {
        return -1;
    }
    return (s64) day * 86400 + sec;
}
