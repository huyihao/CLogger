cmake_minimum_required(VERSION 3.27)
project(CLogger C)

set(CMAKE_C_STANDARD 11)
# ===== 统一输出到 target/ 目录 =====
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/target)
# ===== 指定项目所要求的 C 语言标准，并且强制使用该标准 =====
set(CMAKE_C_STANDARD_REQUIRED ON)

# ==============================
# 1. 构建公共静态库（来自 src/）
# ==============================
file(GLOB LIB_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.c)
# 如果 lib 目录存在且有 .c 文件，则创建静态库
if(LIB_SOURCES)
    add_library(clogger STATIC ${LIB_SOURCES})
    target_include_directories(clogger PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
            $<INSTALL_INTERFACE:include>
    )
endif()

# ==============================
# 2. 处理 test/ 目录：每个 .c 编译为独立可执行程序
# ==============================
file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test/*.c)
foreach(TEST_SRC ${TEST_SOURCES})
    # 生成目标名：test_basic → test_basic
    get_filename_component(FILE_NAME ${TEST_SRC} NAME_WE)
    set(TARGET_NAME "test_${FILE_NAME}")

    if(NOT TARGET ${TARGET_NAME})
        add_executable(${TARGET_NAME} ${TEST_SRC})
        target_link_libraries(${TARGET_NAME} clogger)
        # 虽然库已 PUBLIC，但显式加 include 路径更安全（尤其在旧版 CMake）
        target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
    endif()
endforeach()

# 如果 test/ 为空，给出提示
if(NOT TEST_SOURCES)
    message(STATUS "No test files found in test/")
endif()

#include_directories(.)
#
#add_executable(CLogger
#        src/logger.h src/logger.c)
