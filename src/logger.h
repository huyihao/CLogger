#ifndef C_LOGGER_H
#define C_LOGGER_H

#include <stdbool.h>

/**
* 定义日志级别
 * 常见的日志级别有：
 * 1. TRACE: 最细粒度的日志，记录程序执行的每一步，用于超精细调试，一般极少使用。
 * 2. DEBUG: 提供对调试有帮助的细粒度信息，如变量值、方法调用，主要在开发时使用。
 * 3. INFO: 突出应用程序运行过程中的重要信息，适合生产环境了解程序运行概况，但不能滥用。
 * 4. WARN: 表明可能出现问题的情形，给出提示，但尚不影响程序运行。
 * 5. ERROR: 指出发生了错误事件，但系统仍能继续运行，通常记录异常信息。
 * 6. FATAL: 表示非常严重的错误，可能导致应用程序退出。
*/
enum LogLevel {
    TRACE,
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL
};

// 定义打印各个日志级别的函数声明
#define LOG_TRACE(message) logger(TRACE, message, __FILE__, __LINE__);
#define LOG_DEBUG(message) logger(DEBUG, message, __FILE__, __LINE__);
#define LOG_INFO(message) logger(INFO, message, __FILE__, __LINE__);
#define LOG_WARN(message) logger(WARN, message, __FILE__, __LINE__);
#define LOG_ERROR(message) logger(ERROR, message, __FILE__, __LINE__);
#define LOG_FATAL(message) logger(FATAL, message, __FILE__, __LINE__);

// 定义基础日志函数声明
char *get_date(char *date_str, size_t size);
void logger(enum LogLevel level, const char *message, const char *file, int line);

#endif