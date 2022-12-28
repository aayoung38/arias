cmake_minimum_required(VERSION 3.16)

project(Arias)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/bin)

set(ARIAS_TYPES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/common/types)
set(ARIAS_COMMON_DIR ${CMAKE_CURRENT_SOURCE_DIR}/common)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/bin)

get_filename_component(TYPES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/common/types" ABSOLUTE)
get_filename_component(COMMON_DIR "${CMAKE_CURRENT_SOURCE_DIR}/common" ABSOLUTE)

add_subdirectory(common/types/instrument/guitar)
add_subdirectory(common/types/note)
#add_subdirectory(platform)
