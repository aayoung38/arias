add_library(
    scaleapi
    scalemanager.cpp
    majorscalemanager.cpp
    minorscalemanager.cpp
)

target_include_directories(scaleapi PUBLIC
    ${ARIAS_TYPES}
    ${ARIAS_NOTE_TYPES}
    ${ARIAS_CHORD_TYPES}
    ${ARIAS_EXCEPTIONS}
    .
)

install(TARGETS scaleapi
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX})