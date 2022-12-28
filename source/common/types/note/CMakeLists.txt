add_library(
    noteapi
    noteinterval.cpp
    noteletter.cpp
    notevalue.cpp
)

target_include_directories(noteapi PUBLIC
    ${ARIAS_EXCEPTIONS}
    .
)

install(TARGETS noteapi
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX})