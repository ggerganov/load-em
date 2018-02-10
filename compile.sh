#!/bin/bash

echo "static const char * BUILD_TIMESTAMP=\"`date`\";" > build_timestamp.h

em++ -std=c++11 ./main.cpp -o load.js \
    -s EXPORTED_FUNCTIONS='["_setFile", "_main"]' \
    -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]'
