# CLogger
A logging framework implemented in C.

![screenshot](https://private-user-images.githubusercontent.com/11757351/528432615-6b5eb627-de79-4660-989d-81e4ac8f0698.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NjYxMTY2NDUsIm5iZiI6MTc2NjExNjM0NSwicGF0aCI6Ii8xMTc1NzM1MS81Mjg0MzI2MTUtNmI1ZWI2MjctZGU3OS00NjYwLTk4OWQtODFlNGFjOGYwNjk4LnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNTEyMTklMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjUxMjE5VDAzNTIyNVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWM5MzVmODdkMGQ4OGFlZDE4YWJjZjUxYzIyZTM4MzE5ZGZmMmNkNzEyZDc4ZmRkNWU5YTE5NTViN2YyNjZhNmUmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0In0.R-p0lyaEXQW1B0iGzsEVGnKcvm_leNONBm4bJZ7QG08)

## Update Log
- 2025.12.19: 实现一个最基础的日志框架模板

## Usage
将 **[logger.c](src/logger.c?raw=1)** 和 **[log.h](src/logger.h?raw=1)** 添加到现有项目中，并与项目一起编译。

示例程序 **[logger_test.c](test/logger_test.c?raw=1)** 如下:
```c
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
```
运行结果如开头截图所示。
