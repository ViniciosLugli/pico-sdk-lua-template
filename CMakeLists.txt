cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(main C CXX ASM)

pico_sdk_init()

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.5.1")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.5.1 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

file(GLOB PROJECT_SOURCES src/*.cpp)
file(GLOB LUA_SOURCES lib/lua/*.c)

# Remove lua.c and onelua.c from the list of sources because is conflicting with the main function
list(REMOVE_ITEM LUA_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/lib/lua/lua.c)
list(REMOVE_ITEM LUA_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/lib/lua/onelua.c)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${LUA_SOURCES})

target_compile_definitions(${PROJECT_NAME} PRIVATE LUA_USE_C89)
target_include_directories(${PROJECT_NAME} PRIVATE include lib/lua)

target_link_libraries(${PROJECT_NAME} PRIVATE pico_stdlib)

pico_add_extra_outputs(${PROJECT_NAME})

pico_define_boot_stage2(slower_boot2 ${PICO_DEFAULT_BOOT_STAGE2_FILE})
target_compile_definitions(slower_boot2 PRIVATE PICO_FLASH_SPI_CLKDIV=4)
pico_set_boot_stage2(${PROJECT_NAME} slower_boot2)

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)
