add_library(
    guitarapi
    guitar.cpp
    guitarnote.cpp
    guitarstring.cpp
)
message(STATUS "${TYPES_DIR}")
target_include_directories(guitarapi PUBLIC
${ARIAS_TYPES_DIR}
    ../../note
    ../../../exceptions
    .
)

install(TARGETS guitarapi
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX})