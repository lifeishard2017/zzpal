cmake_minimum_required(VERSION 3.4.0 FATAL_ERROR)

set(PROJ_NAME "zzpal")
set(PROJ_VERSION "0.0.1-dev")
set(PROJ_STRING "${PROJ_NAME} ${PROJ_VERSION}")


project(${PROJ_NAME} CXX)

#cmake moudles
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake" ${CMAKE_MODULE_PATH})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#src directors
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/zzpal")

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/CMake/preconfig.h.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/include/config/preconfig.h
)

# dependences
include(deps)


include_directories(${CMAKE_CURRENT_BINARY_DIR}/include/config)

list(APPEND src_list ${SRC_DIR}/main.cpp)

add_executable(main ${src_list})

target_include_directories(main PRIVATE ${LIBOCILIB_INCLUDE_DIRS})
target_link_libraries(main ${LIBOCILIB_LIBRARIES})