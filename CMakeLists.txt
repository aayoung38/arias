cmake_minimum_required(VERSION 3.16)

project(Arias)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/bin)

set(ARIAS_TYPES ${CMAKE_CURRENT_SOURCE_DIR}/source/common/types)
set(ARIAS_NOTE_TYPES ${CMAKE_CURRENT_SOURCE_DIR}/source/common/types/note)
set(ARIAS_GUITAR_TYPES ${CMAKE_CURRENT_SOURCE_DIR}/source/common/types/instrument/guitar)
set(ARIAS_EXCEPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/source/common/exceptions)
set(ARIAS_COMMON ${CMAKE_CURRENT_SOURCE_DIR}/source/common)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/bin)

add_subdirectory(${ARIAS_GUITAR_TYPES})
add_subdirectory(${ARIAS_NOTE_TYPES})
#add_subdirectory(platform)
