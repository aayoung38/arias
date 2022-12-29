add_library(
    noteapi
    noteinterval.cpp
    noteletter.cpp
    notevalue.cpp
    note.cpp
)

target_include_directories(noteapi PUBLIC
    ${ARIAS_EXCEPTIONS}
    ${ARIAS_TYPES}
    .
)

install(TARGETS noteapi
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX})