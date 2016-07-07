cmake_minimum_required(VERSION 3.0)
project(CChip16)

file(GLOB_RECURSE sources "src/*.c*")
file(GLOB_RECURSE headers "include/*.h*")

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-std=c11")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

include_directories(${CMAKE_CURREND_SOURCE_DIR}/include)

# add a lib
# set (LLIB_LIB libllib.so)
# link_directories(path/to/lib)
# include_directories(path/to/headers)
add_executable(CChip16 ${sources})
target_link_libraries(CChip16 ${SDL2_LIBRARY})
