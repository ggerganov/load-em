/*! \file main.cpp
 *  \brief Simple file loading in emscripten.
 *  \author Georgi Gerganov
 */

#include "build_timestamp.h"

#ifdef __EMSCRIPTEN__
#include "emscripten/emscripten.h"
#endif

extern "C" {
    void setFile(size_t n, const char * buf) {
        printf("Loaded file of size %zu bytes\n", n);

        size_t nPrint = (n < 100) ? n : 100;
        printf("First %zu bytes of the file (0 replaced with '.'):\n", nPrint);
        for (size_t i = 0; i < nPrint; ++i) {
            printf("%c", (buf[i] == 0) ? '.' : buf[i]);
        }
        printf("\n");
    }
}

void update() {
}

int main(int argc, char** argv) {
    printf("Build time: %s\n", BUILD_TIMESTAMP);

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(update, 0, 1);
#else
    while(true) {
        update();
    }
#endif

    return 0;
}
