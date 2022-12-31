add_executable(
    arias
    main.cpp
)

target_include_directories(arias PUBLIC
    ${ARIAS_GUITAR_TYPES}
    ${ARIAS_NOTE_TYPES}
    ${ARIAS_CHORD_TYPES}
    ${ARIAS_SCALES}
    ${ARIAS_TYPES}
    ${ARIAS_EXCEPTIONS}
    .
)

target_link_libraries (arias LINK_PUBLIC noteapi guitarapi)
install(TARGETS arias
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX})