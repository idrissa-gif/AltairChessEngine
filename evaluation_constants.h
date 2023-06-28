//
// Created by Alexander Tian on 6/26/23.
//

#ifndef ALTAIRCHESSENGINE_EVALUATION_CONSTANTS_H
#define ALTAIRCHESSENGINE_EVALUATION_CONSTANTS_H

#include "evaluation.h"
#include "types.h"

constexpr int GAME_PHASE_SCORES[6] = {0, 1, 1, 2, 4, 0};

constexpr int MVV_LVA_VALUES[6] = {  87, 390, 429, 561,1234,   0};

constexpr SCORE_TYPE PIECE_VALUES[6] = {S(  98, 138), S( 413, 420), S( 451, 465), S( 580, 812), S(1224,1482), S(   0,   0)};

constexpr SCORE_TYPE PIECE_SQUARE_TABLES[6][64] = {
        {
                S( -26, -52), S( -26, -52), S( -26, -52), S( -26, -52), S( -26, -52), S( -26, -52), S( -26, -52), S( -26, -52),
                S(  62, 114), S(  96, 108), S(  11, 108), S(  60,  48), S(  28,  71), S( 124,  61), S( -38, 130), S( -66, 137),
                S( -29,  51), S(  14,  41), S(  40,   6), S(  42, -25), S(  70, -32), S(  98, -14), S(  46,  22), S(   3,  30),
                S( -31,  21), S(   6,  11), S(   4,  -4), S(  24, -33), S(  30, -23), S(  32, -13), S(  27,   7), S( -20,   9),
                S( -39,  12), S(  -8,  10), S(  -9, -11), S(   7, -17), S(  10, -15), S(   5, -14), S(  18,   0), S( -21,  -7),
                S( -42,   0), S( -16,   9), S( -13,  -8), S( -13,  -8), S(   0,   6), S(  -2,  -2), S(  34,  -2), S( -10, -13),
                S( -48,  13), S( -18,  12), S( -29,  16), S( -36,  11), S( -24,  22), S(  16,  10), S(  41,  -1), S( -18, -18),
                S( -26, -52), S( -26, -52), S( -26, -52), S( -26, -52), S( -26, -52), S( -26, -52), S( -26, -52), S( -26, -52)
        },
        {
                S(-241, -65), S(-124, -23), S( -69,  14), S(  -4, -15), S( 129, -28), S(-146,   4), S( -26, -54), S(-152,-116),
                S( -23, -27), S( -44,   7), S(  69,  -7), S(  51,  28), S(  58,  16), S(  97, -17), S(  -6,  -9), S(   3, -39),
                S( -42, -14), S(  43,   5), S(  60,  36), S(  91,  44), S( 126,  17), S( 151,  18), S(  99,  -7), S(  63, -43),
                S(   7,  -4), S(  19,  38), S(  37,  54), S(  60,  60), S(  38,  64), S(  68,  57), S(  28,  40), S(  31,   7),
                S( -15,   6), S( -10,  20), S(  15,  54), S(  16,  64), S(  28,  55), S(  25,  60), S(  43,  28), S(  -3,   8),
                S( -27, -51), S( -11,   3), S(   9,  10), S(   9,  37), S(  18,  31), S(  14,  10), S(  18,  -8), S( -19, -10),
                S( -50, -48), S( -42, -12), S( -12, -20), S(  -4,  13), S(  -7,  24), S(   5, -20), S( -14, -15), S(  -1, -52),
                S(-138, -48), S( -32, -56), S( -63, -12), S( -50,  -2), S( -31, -13), S( -26, -12), S( -31, -31), S( -68, -57)
        },
        {
                S( -69,  -7), S(  -6,  -6), S(-119,  12), S( -74,  10), S( -73,  11), S( -71,  -2), S( -15, -10), S(   3, -20),
                S( -36,  -1), S(  15,   2), S(  -1,  13), S( -13,   7), S(  23,  11), S(  62,  -8), S(  20,   2), S( -34,  -8),
                S( -12,   3), S(  25,   4), S(  58,   6), S(  42,  11), S(  57,   2), S(  71,  20), S(  58,  10), S(  10,  11),
                S( -20,  -1), S(   7,  23), S(  16,  24), S(  57,  25), S(  40,  31), S(  49,  13), S(   8,  31), S(  -6,  11),
                S( -14,  -6), S(   5,  12), S(   5,  26), S(  18,  33), S(  37,  19), S(   3,  22), S(   2,   3), S(  15, -23),
                S(  -7, -20), S(   6,   1), S(   6,  11), S(   7,  10), S(   0,  24), S(   7,   9), S(  11,  -9), S(  12, -20),
                S( -11, -28), S(   7, -27), S(  15, -14), S( -11,  -2), S(  -4,  -4), S(  -5, -22), S(  21,  -1), S(   5, -42),
                S(   7, -61), S( -10, -30), S( -30, -12), S( -34, -10), S( -44, -11), S( -30, -12), S( -40,  -5), S( -22, -43)
        },
        {
                S(  63,   9), S(  64,  12), S(  52,  16), S(  63,  17), S( 104,   2), S(  75,   4), S(  37,  11), S( 141, -10),
                S(  27,  16), S(  17,  23), S(  56,  17), S(  73,  16), S(  75,   5), S( 122, -19), S(  47,   2), S(  70,  -6),
                S( -27,  18), S(  12,   9), S(  32,   8), S(  39,   7), S(  54,  -3), S(  93, -11), S( 114, -25), S(  53, -19),
                S( -35,  12), S( -22,   9), S(   5,  14), S(  19,   8), S(   2,  14), S(  24,   2), S( -12,   2), S(  -7,   0),
                S( -65,  10), S( -62,  17), S( -43,  14), S( -34,  16), S( -35,   8), S( -26,  -6), S(  -7,  -8), S( -24, -17),
                S( -75,  -8), S( -50,  -6), S( -52,  -4), S( -49,   0), S( -45,   1), S( -45, -12), S( -14, -17), S( -46, -24),
                S( -85,  -9), S( -46, -15), S( -51,  -2), S( -52,  -4), S( -43,  -9), S( -33, -19), S( -19, -26), S(-114,   2),
                S( -48,  -7), S( -42,   0), S( -33,   3), S( -29,  -1), S( -33,  -3), S( -39,  -7), S( -43,   0), S( -46, -28)
        },
        {
                S( -36,  -8), S( -33,  51), S(  27,  35), S(  47,  21), S( 107,  15), S( 123,  -4), S(  80,   4), S(  52,  17),
                S( -15, -22), S( -57,  28), S( -22,  49), S( -24,  58), S( -16,  81), S(  80,  41), S(  23,  54), S(  35,  30),
                S( -23, -29), S( -15, -12), S(   0,   4), S( -15,  72), S(   7,  84), S( 109,  32), S( 115,  11), S(  38,  78),
                S( -23, -40), S( -30,  16), S( -21,  29), S( -26,  62), S( -20,  92), S(  14,  75), S(   1,  84), S(  -4,  99),
                S( -27, -29), S( -18,  16), S( -19,  10), S( -27,  59), S( -17,  43), S(  -9,  41), S(   6,  23), S(  -4,  21),
                S( -30, -27), S(   0, -79), S( -18,   3), S( -15, -17), S( -17,  -9), S(  -9,  -7), S(  12, -34), S( -13, -13),
                S( -38, -53), S(  -8, -74), S(   3, -87), S( -13, -43), S(  -6, -61), S(   9,-108), S(   5,-104), S( -32, -46),
                S( -11, -64), S( -37, -52), S( -19, -64), S(  -8, -15), S( -22, -67), S( -32, -94), S( -13, -92), S( -50, -83)
        },
        {
                S( -19,-109), S( 256, -88), S( 183, -56), S( 143, -58), S(-179,   0), S( -93,  32), S(  78, -15), S(  23, -32),
                S( 214, -62), S(  77,  20), S(  82,  17), S(  93,   3), S(  75,  15), S(  67,  30), S( -54,  51), S(-154,  26),
                S(  66,  11), S( 107,  25), S(  88,  32), S( -10,  33), S(  55,  22), S( 119,  51), S( 147,  41), S( -30,  18),
                S(   3,   1), S(  -2,  41), S(  13,  47), S( -27,  58), S( -63,  58), S(   2,  52), S(   9,  41), S(-102,  22),
                S( -65, -16), S(  73,  -7), S( -30,  43), S( -85,  63), S( -60,  62), S( -60,  51), S( -31,  28), S( -93,   3),
                S( -19, -17), S( -22,  11), S( -64,  34), S( -78,  47), S( -55,  45), S( -55,  36), S(  -1,  10), S( -25, -11),
                S(  18, -29), S(   7, -11), S( -28,  16), S(-115,  32), S( -77,  31), S( -56,  23), S(  22, -11), S(  41, -42),
                S(  24,-104), S(  68, -61), S(  20, -32), S(-114,  -2), S( -17, -41), S( -75,  -5), S(  36, -40), S(  44, -93)
        }
};


constexpr SCORE_TYPE PASSED_PAWN_BONUSES[8] = {S(   0,   0), S(  -6,  -3), S( -14,   7), S( -18,  38), S(   3,  75), S(  24, 158), S(  91, 168), S(   0,   0)};

constexpr SCORE_TYPE PASSED_PAWN_BLOCKERS[6][8] = {
        {S(   0,   0), S(   0,   0), S(   0,   0), S(   0,   0), S(   0,   0), S(   0,   0), S(   0,   0), S(   0,   0)},
        {S(   0,   0), S(   0,   0), S(  14, -42), S( -30,   8), S( -11, -27), S( -10, -76), S( -10,-112), S( 173,-212)},
        {S(   0,   0), S(   0,   0), S( -10, -31), S(  -7, -51), S( -11, -45), S(  13, -69), S(  -7,-125), S(  88,-241)},
        {S(   0,   0), S(   0,   0), S(  31, -28), S(  -9,  19), S(  11,  -3), S(  30, -14), S(  24, -53), S(  25,-107)},
        {S(   0,   0), S(   0,   0), S(  -2, -24), S( -64,  62), S(   6, -37), S(   7,  -7), S(  20, -50), S( 103,  61)},
        {S(   0,   0), S(   0,   0), S( 101, -34), S(  62, -32), S( -40, -49), S(  -3, -86), S( -16,-180), S(  41,-302)}
};


#endif //ALTAIRCHESSENGINE_EVALUATION_CONSTANTS_H
