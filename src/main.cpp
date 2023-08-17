

#include <iostream>
#include "position.h"
#include "perft.h"
#include "uci.h"
#include "bench.h"
#include "datagen.h"

int main(int argc, char* argv[]) {

    /*
    Position position{};
    position.set_fen(START_FEN);

    uci_perft(position, 6, 0);

    return 0;
     */

    UCI main_uci;
    main_uci.initialize_uci();

    // BENCH arg-parsing

    bool bench_flag = false;
    bool datagen_flag = false;
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "bench") == 0) {
            bench_flag = true;
        }
        if (strcmp(argv[i], "datagen") == 0) {
            datagen_flag = true;
        }
    }


    if (bench_flag) {
        run_bench(*main_uci.engine, BENCH_DEPTH);
        return 0;
    }

    if (datagen_flag) {
        Datagen datagen{};
        datagen.start_datagen();
        return 0;
    }

    // Datagen datagen{};
    // datagen.merge();


    // Begin the UCI input loop
    main_uci.uci_loop();


    return 0;
}
