#include <stdio.h>
#include "logger.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void sleep_ms(int milliseconds)
{
    #ifdef _WIN32
        Sleep(milliseconds);
    #else
        sleep(milliseconds / 1000);
    #endif
}

int main(void)
{
    LOG_DEBUG("This is a debug message.");
    sleep_ms(3000);
    LOG_ERROR("This is an error message.");
    sleep_ms(3000);
    LOG_FATAL("This is a fatal message.");
    sleep_ms(3000);
    LOG_INFO("This is an info message.");
    sleep_ms(3000);
    LOG_TRACE("This is a trace message.");
    sleep_ms(3000);
    LOG_WARN("This is a warn message.");

    return 0;
}