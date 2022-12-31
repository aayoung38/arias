#lcov -c -d . -o coverage.info
#lcov --remove coverage.info '/usr/include/*' 'src/*' -o filtered_coverage.info
genhtml coverage.info --output-directory coverage