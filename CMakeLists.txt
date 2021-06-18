#cmake_minimum_required(VERSION 3.8.2)
cmake_minimum_required(VERSION 3.13)
project (sdmonitor C CXX)
set (CMAKE_CXX_STANDARD 17)


set(BUILD_LIBSYSTEMD ON CACHE INTERNAL "")
add_subdirectory(sdbus-cpp)

add_executable(sdmonitor
    source/svcmon.cpp
    source/main.cpp
)

target_include_directories(sdmonitor SYSTEM PRIVATE source)

target_compile_options(sdmonitor PUBLIC -Wall -g -Wno-unused-parameter -Wno-unused-function -O4)
target_link_libraries(sdmonitor PRIVATE ${LIBS} sdbus-c++)

install(TARGETS sdmonitor RUNTIME DESTINATION bin)