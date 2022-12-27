add_library(
    guitarlib
    guitar.cpp
    guitarnote.cpp
    guitarstring.cpp
)
message(STATUS "${TYPES_DIR}")
target_include_directories(guitarlib PUBLIC
    ${TYPES_DIR}
    ../../note
    ../../../exceptions
    .
)
