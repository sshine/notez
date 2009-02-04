#include <notez.h>

#define MINUTE 60
#define HOUR 3600
#define DAY 86400
#define WEEK 604800
#define YEAR 31536000

char *duration(char *secs_str)
{
    // struct tm tm;
    char *str = (char *) malloc(sizeof(char) * 11);
    int tmp, years, weeks, days, hours, minutes, seconds;

    // strptime(seconds, "%s", &tm);
    // strftime(str, 11, "%F", &tm);
    // return str;

    tmp = (int) time(NULL) - atoi(secs_str);
    years = tmp / YEAR;
    tmp -= years * YEAR;
    weeks = tmp / WEEK;
    if (years > 0) {
        if (weeks > 0) {
            snprintf(str, 11, "%dy%dw", years, weeks);
            return str;
        }
        snprintf(str, 11, "%dy", years);
        return str;
    }
    tmp -= weeks * WEEK;
    days = tmp / DAY;
    if (weeks > 0) {
        if (days > 0)
            sprintf(str, "%dw%dd", weeks, days);
        else sprintf(str, "%dw", weeks);
        return str;
    }
    tmp -= days * DAY;
    hours = tmp / HOUR;
    if (days > 0) {
        if (hours > 0)
            sprintf(str, "%dd%dh", days, hours);
        else sprintf(str, "%dd", days);
        return str;
    }
    tmp -= hours * HOUR;
    minutes = tmp / MINUTE;
    if (hours > 0) {
        if (minutes > 0)
            sprintf(str, "%dh%dm", hours, minutes);
        else sprintf(str, "%dh", hours);
        return str;
    }
    tmp -= minutes * MINUTE;
    seconds = tmp;
    if (minutes > 0) {
        if (seconds > 0)
            sprintf(str, "%dm%ds", minutes, seconds);
        else sprintf(str, "%dm", minutes);
        return str;
    }
    sprintf(str, "%ds", seconds);
    return str;
}
