add_library(
    chordapi
    chord.cpp
)

target_include_directories(chordapi PUBLIC
    ${ARIAS_EXCEPTIONS}
    ${ARIAS_NOTE_TYPES}
    .
)

install(TARGETS chordapi
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX})