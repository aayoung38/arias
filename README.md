# arias
Repository for the Arias music generation project. This project represents some of my more recent work to build my knowledge base around using C++ to interact with musical instruments in realtime.

Build:

cmake -S . -B build
cd build
make

Outputs can be found at - 

arias_bin/bin/arias
arias_bin/bin/ariastest
    
Generate coverage:
make coverage 

Manual method-
cd build
arias_bin/bin/ariastest
lcov -c -d . -o main_coverage.info
genhtml main_coverage.info --output-directory coverage
