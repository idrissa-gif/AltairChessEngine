//
// Created by Alexander Tian on 8/16/23.
//

#ifndef ALTAIRCHESSENGINE_DATAGEN_H
#define ALTAIRCHESSENGINE_DATAGEN_H

#include <chrono>
#include <vector>
#include "random.h"
#include "search.h"

constexpr int MAX_GAME_LENGTH = 600;

struct EvalFenStruct {
    std::string fen;
    int eval;
};

struct Datagen_Thread {
    int thread_id  = 0;
    uint64_t total_fens  = 0;
    uint64_t total_games = 0;
    uint64_t game_length = 0;

    bool ping = false;

    std::string current_stage = "none";


    PRNG prng = PRNG(0);

    std::unique_ptr<Engine> engine = std::make_unique<Engine>();

    uint64_t start_time;

    inline Datagen_Thread() {
        thread_id = 0;
    }

    inline explicit Datagen_Thread(int t_id, uint64_t random_seed) {
        thread_id = t_id;
        prng = PRNG(695848653836 + 6 * thread_id + random_seed);
    }
};

class Datagen {

    const int max_fens          = 100'000'000;
    const int soft_node_limit   =       5'000;
    const int hard_node_limit   =      80'000;
    const int max_time_per_move =         200;

    const int initial_random_moves      =    8;
    const int opening_max_score         =  800;
    // const uint64_t opening_chance       = 100;  // Out of 100

    const int win_adjudication_score   = 1500;
    const int win_adjudication_length  =    5;

    const int minimum_game_length = 16;
    const int fens_per_game       =  0;  // 0 for using all fens

    const std::string WDL_scores[3] = {"1.0", "0.5", "0.0"};

    std::vector<Datagen_Thread> datagen_threads;

    // std::vector<std::string> opening_fens{};

public:
    int threads = 1;

    uint64_t random_seed = 0;

    bool stopped = false;

    void integrity_check();
    void integrity_check_process();
    void start_datagen();

    std::string write_fen(Datagen_Thread& datagen_thread, EvalFenStruct eval_fen, double game_result);
    bool randomize_opening(Datagen_Thread& datagen_thread, FixedVector<Move, MAX_MOVES>& legal_moves) const;

    void datagen(Datagen_Thread& datagen_thread);

    std::vector<std::string> get_file_fens(const std::string &file_name);

    void merge();
};


#endif //ALTAIRCHESSENGINE_DATAGEN_H