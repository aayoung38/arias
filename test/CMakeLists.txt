cmake_minimum_required(VERSION 3.14)
project(arias_tests)

################################
# Unit Tests
################################
# Add test cpp file
add_executable( ariastest 
scale/testmajorscalemanager.cpp 
scale/testminorscalemanager.cpp 
scale/testscalemanager.cpp )

#include(CMakePrintHelpers)
#cmake_print_variables(ARIAS_SCALES)

target_include_directories(ariastest PUBLIC
    ${ARIAS_SCALES}
    ${ARIAS_NOTE_TYPES}
    ${ARIAS_CHORD_TYPES}
    ${ARIAS_EXCEPTIONS}
    ${ARIAS_TYPES}
    .
)

# GoogleTest requires at least C++14
#set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

################################
# GTest
################################
#ADD_SUBDIRECTORY (gtest-1.6.0)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Link test executable against gtest & gtest_main
target_link_libraries(ariastest chordapi noteapi scaleapi guitarapi gtest gtest_main)



install(TARGETS ariastest
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/test)

include(GoogleTest)
gtest_discover_tests( ariastest )