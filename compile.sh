#!/bin/bash

echo "static const char * BUILD_TIMESTAMP=\"`date`\";" > build_timestamp.h

emcc -std=c++11 ./main.cpp -o load.js \
    -s ALLOW_MEMORY_GROWTH=1 \
    -s EXPORTED_FUNCTIONS='["_setFile", "_main"]' \
    -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap", "writeArrayToMemory"]'
