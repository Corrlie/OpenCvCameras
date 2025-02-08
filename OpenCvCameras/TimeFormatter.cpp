#include "TimeFormatter.h"
#include <iomanip>
#include <sstream>

std::string TimeFormatter::formatTime(const std::tm& timeInfo)
{
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << timeInfo.tm_hour << ":"
        << std::setw(2) << std::setfill('0') << timeInfo.tm_min << ":"
        << std::setw(2) << std::setfill('0') << timeInfo.tm_sec;
    return oss.str();
}
