# arias
Repository for the Arias music generation project.

Build:

cmake -S . -B build
cd build
make

Generate coverage:

cd build
arias_bin/bin/ariastest
lcov -c -d . -o main_coverage.info
genhtml main_coverage.info --output-directory coverage