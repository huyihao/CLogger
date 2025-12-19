#include <stdio.h>
#include <time.h>
#include "logger.h"

char *get_date(char *date_str, size_t size)
{
    time_t now;
    struct tm *tm_info;

    // 获取当前时间
    time(&now);
    // 将时间转换为tm结构体
    tm_info = localtime(&now);

    // 格式化日期为yyyy-mm-dd
    strftime(date_str, size, "%Y-%m-%d", tm_info);

    return date_str;
}

char *get_time(char *time_str, size_t size)
{
    time_t now;
    struct tm *tm_info;

    time(&now);
    tm_info = localtime(&now);
    strftime(time_str, size, "%H:%M:%S", tm_info);

    return time_str;
}

char *get_timestamp(char *timestamp_str, size_t size)
{
    time_t now;
    struct tm *tm_info;

    time(&now);
    tm_info = localtime(&now);
    strftime(timestamp_str, size, "%Y-%m-%d %H:%M:%S", tm_info);

    return timestamp_str;
}

void logger(enum LogLevel level, const char *message, const char *file, int line)
{
    char date_str[20];
    switch (level)
    {
        case TRACE:
            printf("%s [TRACE] %s:%d: %s\n", get_timestamp(date_str, sizeof(date_str)),  file, line, message);
            break;

        case DEBUG:
            printf("%s [DEBUG] %s:%d: %s\n", get_timestamp(date_str, sizeof(date_str)), file, line, message);
            break;

        case INFO:
            printf("%s [INFO] %s:%d: %s\n", get_timestamp(date_str, sizeof(date_str)), file, line, message);
            break;

        case WARN:
            printf("%s [WARN] %s:%d: %s\n", get_timestamp(date_str, sizeof(date_str)), file, line, message);
            break;

        case ERROR:
            printf("%s [ERROR] %s:%d: %s\n", get_timestamp(date_str, sizeof(date_str)), file, line, message);
            break;

        case FATAL:
            printf("%s [FATAL] %s:%d: %s\n", get_timestamp(date_str, sizeof(date_str)), file, line, message);
            break;
    }
}