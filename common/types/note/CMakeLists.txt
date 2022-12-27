add_library(
    notelib
    noteinterval.cpp
    noteletter.cpp
    notevalue.cpp
)

target_include_directories(notelib PUBLIC
    ../../exceptions
    .
)
