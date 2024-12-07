cmake_minimum_required(VERSION 3.16)

project(win-keystore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(NOT WIN32)
    message(FATAL_ERROR "Win-Keystore only support Windows.")
endif()

set(MINGW_PATH "C:/msys64/mingw64/bin")
set(CMAKE_AR "${MINGW_PATH}/ar.exe")
if (NOT CMAKE_C_COMPILER)
    set(CMAKE_C_COMPILER "${MINGW_PATH}/gcc.exe")
endif()

if (NOT CMAKE_CXX_COMPILER)
    set(CMAKE_CXX_COMPILER "${MINGW_PATH}/g++.exe")
endif()

add_subdirectory(src)
add_subdirectory(thirdparty)