cmake_minimum_required(VERSION 3.16)

project(Arias)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/arias_bin)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake/modules)

include(CodeCoverage)
append_coverage_compiler_flags()

# Aliases for subdirectories for ease of access
set(ARIAS_COMMON       ${CMAKE_CURRENT_SOURCE_DIR}/source/common)
set(ARIAS_TYPES        ${CMAKE_CURRENT_SOURCE_DIR}/source/common/types)
set(ARIAS_SCALES       ${CMAKE_CURRENT_SOURCE_DIR}/source/common/scale)
set(ARIAS_EXCEPTIONS   ${CMAKE_CURRENT_SOURCE_DIR}/source/common/exceptions)
set(ARIAS_NOTE_TYPES   ${CMAKE_CURRENT_SOURCE_DIR}/source/common/types/note)
set(ARIAS_CHORD_TYPES  ${CMAKE_CURRENT_SOURCE_DIR}/source/common/types/chord)
set(ARIAS_GUITAR_TYPES ${CMAKE_CURRENT_SOURCE_DIR}/source/common/types/instrument/guitar)

# subdirectories for build
add_subdirectory(${ARIAS_CHORD_TYPES})
add_subdirectory(${ARIAS_NOTE_TYPES})
add_subdirectory(${ARIAS_GUITAR_TYPES})
add_subdirectory(${ARIAS_SCALES})
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/source/platform/linux)

#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/googletest)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)

setup_target_for_coverage_lcov(
          NAME coverage
          EXECUTABLE ariastest
          BASE_DIRECTORY ".."
          EXCLUDE /usr/include/*
                  ${Project_SOURCE_DIR}/build/_deps/*
)