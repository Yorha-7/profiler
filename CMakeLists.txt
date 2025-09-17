cmake_minimum_required(VERSION 3.10)
project(cpp_profiler VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(profiler STATIC src/profiler.cpp)

target_include_directories(profiler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(TARGETS profiler
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include)
