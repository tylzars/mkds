#include "code_0214e258.h"

// Returns the seconds since midnight of time.
s32 RTCi_ConvertTimeToSecond(const RTCTime *time) {
    return (time->mHour * 60 + time->mMinute) * 60 + time->mSecond;
}
