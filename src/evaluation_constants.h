

#ifndef ALTAIRCHESSENGINE_EVALUATION_CONSTANTS_H
#define ALTAIRCHESSENGINE_EVALUATION_CONSTANTS_H

#include "evaluation.h"
#include "types.h"

constexpr int GAME_PHASE_SCORES[6] = {0, 1, 1, 2, 4, 0};

constexpr int MVV_LVA_VALUES[6] = {  87, 390, 429, 561, 1234,   0};

constexpr SCORE_TYPE CANONICAL_PIECE_VALUES[6] = {100, 310, 340, 500, 900, 0};

constexpr SCORE_TYPE MAX_MINOR_PIECE_VALUE = CANONICAL_PIECE_VALUES[BISHOP];
constexpr SCORE_TYPE MIN_MINOR_PIECE_VALUE = CANONICAL_PIECE_VALUES[KNIGHT];


constexpr SCORE_TYPE PIECE_VALUES[6] = {S(   114,    79), S(   400,   169), S(   406,   164), S(   630,   260), S(  1526,   297), S(     0,     0)};

constexpr SCORE_TYPE PIECE_SQUARE_TABLES[6][64] = {
        {
                S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0),
                S(   111,     2), S(    98,    28), S(   125,    31), S(   115,    21), S(     9,    29), S(   -29,    61), S(     8,    78), S(   133,    14),
                S(   -17,    10), S(   -18,    10), S(    13,    10), S(    28,    -5), S(    21,   -13), S(    26,    -5), S(   -38,    19), S(   -10,     3),
                S(   -24,     4), S(   -21,    -5), S(   -20,    -8), S(    -1,   -19), S(     4,   -16), S(    11,   -16), S(    -9,   -16), S(   -24,   -11),
                S(   -33,     2), S(   -33,     2), S(   -18,   -20), S(    -2,   -19), S(    -8,   -17), S(   -22,    -7), S(   -14,   -10), S(   -31,    -1),
                S(   -28,    -4), S(   -28,    -8), S(   -29,    -8), S(   -12,   -15), S(    -4,   -12), S(   -12,   -10), S(    -7,    -5), S(   -28,   -14),
                S(   -35,     3), S(   -34,    -4), S(   -40,    -1), S(   -22,   -21), S(   -22,    -7), S(    -1,   -11), S(    -1,    -7), S(   -28,    -8),
                S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0)
        },
        {
                S(   -29,  -218), S(   -57,    15), S(    21,   -17), S(    19,    16), S(    61,   -12), S(    64,    -6), S(   -28,    33), S(  -135,    48),
                S(   -14,     9), S(    18,    17), S(    22,    -7), S(     0,    20), S(    61,    -3), S(    47,     0), S(   -24,    21), S(    18,    24),
                S(    17,    -6), S(    -4,     8), S(    43,    11), S(    53,    11), S(    59,    11), S(    84,     8), S(    41,     5), S(     1,    12),
                S(     2,    12), S(    12,     7), S(    23,    19), S(    38,    23), S(    23,    27), S(    19,    26), S(    20,    -2), S(    29,     3),
                S(   -14,    12), S(    14,     1), S(     6,    25), S(    14,    11), S(    10,    21), S(     7,    11), S(    16,     1), S(   -21,    23),
                S(   -29,   -13), S(    -7,    -7), S(   -12,    11), S(    -1,     8), S(     1,     0), S(    -8,   -14), S(   -17,   -17), S(   -22,    -5),
                S(   -43,    12), S(   -30,     4), S(   -24,   -30), S(    -8,    -4), S(   -15,    -5), S(    -2,   -20), S(   -28,     0), S(   -29,   -11),
                S(   -52,   -46), S(   -24,    -8), S(   -40,    -6), S(   -22,    -8), S(   -21,   -20), S(   -22,   -18), S(   -29,    -9), S(   -51,   -16)
        },
        {
                S(   -22,     5), S(   -26,    13), S(   -46,    11), S(   -35,    14), S(   -30,     4), S(    34,     5), S(    -6,    -5), S(   -52,    14),
                S(    15,     6), S(    43,    -3), S(     9,     8), S(    24,     1), S(     5,     8), S(    -7,     3), S(   -15,     8), S(    45,   -13),
                S(    16,     2), S(    24,     7), S(    45,    -5), S(    13,     1), S(    41,    -3), S(    39,     8), S(    70,    -7), S(    17,     5),
                S(    -4,    13), S(    22,     3), S(    34,    -1), S(    52,    -8), S(    12,     6), S(    21,     2), S(    -2,    14), S(   -15,     5),
                S(    -7,     0), S(     5,     4), S(    11,     0), S(    14,     6), S(    20,    -2), S(    -9,    15), S(     4,     2), S(   -12,     2),
                S(   -13,    -4), S(     9,    -1), S(     3,    -3), S(     1,    -1), S(    -7,    13), S(    11,    -8), S(    -5,    -1), S(     5,    -1),
                S(     0,   -33), S(    -5,   -10), S(    -7,    -5), S(   -10,     1), S(    -4,     0), S(     3,    -7), S(    15,   -15), S(    -8,   -37),
                S(   -29,   -27), S(   -93,    11), S(   -28,     2), S(   -31,    -8), S(    -9,   -14), S(   -25,    -1), S(  -111,    18), S(   -10,   -17)
        },
        {
                S(    35,     1), S(     0,    19), S(    36,     5), S(    56,    -3), S(    20,     1), S(    98,   -18), S(    42,    -6), S(    53,    -8),
                S(    20,    10), S(     8,    17), S(    10,    14), S(    35,     7), S(    35,     7), S(    56,     0), S(    40,    -1), S(    68,    -3),
                S(     8,     4), S(    21,     5), S(    15,     4), S(    28,    -4), S(     9,     3), S(    69,   -10), S(    66,    -8), S(    43,     1),
                S(    -7,     3), S(    -8,    13), S(     0,     7), S(    -4,     4), S(    15,    -8), S(     6,     4), S(    -5,    -2), S(    -6,     3),
                S(   -19,     3), S(   -20,    10), S(   -42,    16), S(   -27,     8), S(   -37,    14), S(   -26,     9), S(   -31,    14), S(   -37,    22),
                S(   -20,    -5), S(   -29,    12), S(   -27,     1), S(   -38,    14), S(   -33,     2), S(   -23,     1), S(   -25,     9), S(   -51,    21),
                S(   -20,   -23), S(   -28,   -13), S(   -23,   -10), S(   -25,    -7), S(   -23,   -14), S(   -29,    -9), S(   -11,   -34), S(   -82,    14),
                S(    -1,   -24), S(    -9,   -21), S(   -16,   -11), S(   -14,   -12), S(   -18,   -14), S(   -24,    -7), S(   -24,   -21), S(   -32,    -6)
        },
        {
                S(   -40,    31), S(     7,    -9), S(     7,    13), S(     3,    14), S(   -12,    29), S(   129,   -38), S(    83,   -36), S(    54,   -19),
                S(   -29,    10), S(   -54,    27), S(   -37,    50), S(   -44,    38), S(   -59,    63), S(     5,    41), S(    38,    -7), S(    38,   -14),
                S(   -17,     0), S(   -40,    23), S(   -51,    40), S(   -65,    55), S(   -35,    40), S(     4,    21), S(    25,    13), S(     6,    23),
                S(   -10,     9), S(   -19,    16), S(   -48,    62), S(   -37,    55), S(   -36,    44), S(   -29,    52), S(   -18,    53), S(   -18,    39),
                S(     8,   -23), S(     2,     3), S(   -10,    16), S(   -16,    45), S(   -15,    12), S(   -12,    17), S(    -9,     6), S(    -6,    20),
                S(     4,     2), S(     7,    -2), S(    -5,    23), S(     0,    13), S(    -6,     5), S(     2,     7), S(    11,   -25), S(    15,   -36),
                S(    13,   -23), S(    20,   -21), S(    19,   -25), S(    20,   -29), S(    22,   -37), S(    35,   -74), S(    24,   -68), S(    18,   -39),
                S(     8,   -31), S(    23,   -59), S(    20,   -63), S(    20,   -28), S(    18,   -58), S(    17,   -75), S(    18,   -98), S(    35,   -92)
        },
        {
                S(  -548,  -155), S(   390,   -70), S(   195,    -7), S(    20,    12), S(    58,     4), S(   164,   -20), S(   203,  -281), S(  -198,  -268),
                S(   185,   -27), S(   206,   -20), S(   185,    23), S(    31,    20), S(    17,    24), S(   125,     7), S(    72,     8), S(  -112,    15),
                S(   168,   -36), S(   171,    -3), S(    84,    31), S(    15,    22), S(     3,    26), S(    66,    25), S(   122,    11), S(   -30,    18),
                S(    30,     5), S(    68,    16), S(    42,    32), S(    31,    10), S(    -8,    19), S(    69,    14), S(    90,     9), S(    -7,    13),
                S(    17,    15), S(    13,    28), S(    64,    23), S(    60,    -2), S(    90,    -5), S(    96,     7), S(    59,    11), S(   -47,    20),
                S(   -87,    36), S(    -9,    30), S(    45,    19), S(    42,   -12), S(    35,    -8), S(    61,     9), S(    21,    15), S(   -39,    17),
                S(   -62,    27), S(   -37,    30), S(   -11,    23), S(   -32,    -3), S(   -27,    -5), S(   -12,    20), S(     1,    21), S(   -24,    10),
                S(  -178,    60), S(   -39,    22), S(   -67,    30), S(   -90,    -7), S(   -26,   -24), S(   -66,    20), S(   -19,    14), S(   -45,     4)
        }
};


constexpr SCORE_TYPE MOBILITY_VALUES[4][28] = {
        {S(   -33,   -85), S(   -14,   -38), S(    -9,    -4), S(    -5,    15), S(     0,    24), S(     6,    29), S(    13,    25), S(    19,    23), S(    24,    11), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0)},
        {S(   -29,   -46), S(   -25,   -31), S(   -18,   -24), S(   -13,    -7), S(   -11,     4), S(    -8,     9), S(    -4,    13), S(    -3,    11), S(    -1,    14), S(     4,    14), S(     3,    15), S(    13,    12), S(    51,    13), S(    42,     3), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0)},
        {S(   -43,   -55), S(   -36,   -18), S(   -34,    -9), S(   -30,     0), S(   -28,     9), S(   -25,    17), S(   -19,    16), S(   -13,    13), S(    -7,    19), S(     1,    17), S(     8,    16), S(    12,    11), S(    23,     9), S(    35,     0), S(   157,   -45), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0)},
        {S(   -98,  -232), S(  -109,  -182), S(  -112,   -71), S(  -114,   -30), S(  -114,    29), S(  -112,    47), S(  -112,    73), S(  -109,    79), S(  -107,    87), S(  -104,    89), S(  -105,   101), S(  -102,   101), S(  -103,   107), S(  -103,   110), S(   -99,   110), S(   -98,   117), S(   -95,   113), S(   -71,    90), S(   -56,    84), S(   -20,    59), S(    49,    18), S(   103,   -21), S(   100,   -18), S(   423,  -217), S(   256,  -115), S(   520,  -244), S(   206,  -117), S(   288,  -167)}
};


constexpr SCORE_TYPE PASSED_PAWN_BONUSES[3][8] = {
        {S(     0,     0), S(  -102,    50), S(   -68,    40), S(   -62,    39), S(   -44,    38), S(    52,    27), S(   146,    79), S(     0,     0)},
        {S(     0,     0), S(     0,     0), S(   -56,    46), S(   -59,    38), S(   -12,    50), S(   148,    52), S(   242,    68), S(     0,     0)},
        {S(     0,     0), S(     0,     0), S(  -187,    72), S(   -69,    14), S(    20,    46), S(   137,    53), S(   124,   -27), S(     0,     0)}
};


constexpr SCORE_TYPE PASSED_PAWN_BLOCKERS[6][8] = {
        {S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0)},
        {S(     0,     0), S(     0,     0), S(  -100,     2), S(    13,    -8), S(   -35,   -19), S(     7,   -23), S(   -64,   -20), S(  -296,    38)},
        {S(     0,     0), S(     0,     0), S(   -18,   -49), S(    -4,   -33), S(    27,   -45), S(     2,   -70), S(    -2,   -74), S(   -36,  -118)},
        {S(     0,     0), S(     0,     0), S(    33,   -10), S(    12,     3), S(     4,     2), S(     7,    32), S(   -37,    18), S(  -163,    51)},
        {S(     0,     0), S(     0,     0), S(     6,   -61), S(   -84,    90), S(    -2,   -65), S(    24,     6), S(     4,    49), S(   149,    37)},
        {S(     0,     0), S(     0,     0), S(   314,   -36), S(    70,   -32), S(   132,   -41), S(    54,   -33), S(   -35,   -27), S(   -34,   -93)}
};


constexpr SCORE_TYPE PASSED_PAWN_BLOCKERS_2[6][8] = {
        {S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0), S(     0,     0)},
        {S(     0,     0), S(     0,     0), S(     0,     0), S(    23,     3), S(    36,   -18), S(    22,   -14), S(   -46,    15), S(    84,   -18)},
        {S(     0,     0), S(     0,     0), S(     0,     0), S(    13,   -18), S(    26,   -19), S(    -4,   -23), S(   -25,    -5), S(   -59,     1)},
        {S(     0,     0), S(     0,     0), S(     0,     0), S(    54,   -34), S(    -9,     1), S(    31,     5), S(    -7,    29), S(   -41,    18)},
        {S(     0,     0), S(     0,     0), S(     0,     0), S(    19,   -34), S(   -15,    14), S(    -9,   -23), S(    -8,    49), S(   -57,   154)},
        {S(     0,     0), S(     0,     0), S(     0,     0), S(    17,   -16), S(   -71,     0), S(     0,   -29), S(    12,   -28), S(    -7,   -49)}
};


constexpr SCORE_TYPE PHALANX_PAWN_BONUSES[8] = {S(     0,     0), S(     0,    -6), S(    -1,    -6), S(    16,     9), S(    52,    47), S(   122,    87), S(   121,   130), S(     0,     0)};

constexpr SCORE_TYPE ISOLATED_PAWN_PENALTY = S(   -17,    -8);

constexpr SCORE_TYPE BISHOP_PAIR_BONUS = S(    26,    32);

constexpr SCORE_TYPE TEMPO_BONUS = S(    12,     4);

constexpr SCORE_TYPE SEMI_OPEN_FILE_VALUES[6] = {S(     0,     0), S(     0,     0), S(     0,     0), S(    21,     1), S(     7,     7), S(    -8,     3)};

constexpr SCORE_TYPE OPEN_FILE_VALUES[6] = {S(     0,     0), S(     0,     0), S(     0,     0), S(    34,   -10), S(     4,     1), S(   -38,     5)};

constexpr SCORE_TYPE PIECE_THREATS[6][6] = {
        {S(    14,   -43), S(    50,    29), S(    46,    44), S(    51,    31), S(    27,    32), S(     0,     0)},
        {S(    -7,    13), S(     0,     0), S(    30,    11), S(    52,     7), S(    16,    54), S(     0,     0)},
        {S(    -1,    16), S(    15,    26), S(    22,   -18), S(    57,    13), S(    38,    59), S(     0,     0)},
        {S(    -9,    21), S(     5,    16), S(     7,    14), S(     8,   -12), S(    47,     6), S(     0,     0)},
        {S(     1,     7), S(     2,    -3), S(    -4,    21), S(    -3,     3), S(   -19,     7), S(   266,  -235)},
        {S(    68,    13), S(    -4,     8), S(    64,     1), S(    44,   -10), S(     0,     0), S(     0,     0)}
};


constexpr SCORE_TYPE KING_RING_ATTACKS[2][6] = {
        {S(    16,    -6), S(    14,    -8), S(    23,    -2), S(    13,    -2), S(    19,     0), S(     0,     0)},
        {S(    11,    -4), S(    13,    -2), S(    15,    -1), S(     6,     1), S(    13,     0), S(     0,     0)}
};


constexpr SCORE_TYPE TOTAL_KING_RING_ATTACKS[40] = {S(    28,    15), S(    13,   -16), S(    -3,   -11), S(    -9,   -12), S(   -18,   -10), S(   -29,    -4), S(   -35,    -2), S(   -38,    -3), S(   -35,    -5), S(   -37,    -5), S(   -36,    -5), S(   -34,    -5), S(   -26,    -7), S(   -23,    -7), S(   -21,    -8), S(   -32,     0), S(   -21,    -1), S(   -15,     1), S(     0,    -8), S(    11,    -4), S(   -25,    12), S(    -8,     4), S(    45,   -19), S(    -6,    15), S(    36,    -6), S(    -6,    44), S(    33,    29), S(   -26,    32), S(   116,   -12), S(   149,   -49), S(    -7,    36), S(    86,    51), S(    19,   -69), S(    80,    46), S(   167,    79), S(   -74,    -8), S(    44,    18), S(   126,    33), S(   -66,     6), S(    67,    17)};

constexpr SCORE_TYPE KING_PAWN_SHIELD[5][8] = {
        {S(   -15,     1), S(    38,   -14), S(    34,   -19), S(     0,     0), S(     0,     0), S(     8,    -2), S(    20,   -12), S(     4,    -8)},
        {S(    35,    -8), S(    38,   -13), S(    -4,    -4), S(     0,     0), S(     0,     0), S(     1,   -14), S(     3,   -12), S(    13,    -5)},
        {S(    10,    -3), S(    -7,    -3), S(   -13,     6), S(     0,     0), S(     0,     0), S(     4,   -14), S(    -9,   -12), S(    11,   -14)},
        {S(    13,     1), S(     4,    11), S(    16,     6), S(     0,     0), S(     0,     0), S(    -2,    -3), S(     0,    -6), S(     5,   -10)},
        {S(   -13,    -2), S(   -22,    -5), S(   -17,    -5), S(     0,     0), S(     0,     0), S(   -19,     6), S(   -30,    10), S(   -29,    10)}
};


constexpr SCORE_TYPE KING_PAWN_STORM[6][8] = {
        {S(    96,     4), S(   218,   -19), S(   208,    -7), S(     0,     0), S(     0,     0), S(    15,    25), S(   106,    27), S(   161,    -8)},
        {S(   -41,    21), S(  -100,    34), S(   -38,    36), S(     0,     0), S(     0,     0), S(   -33,     3), S(   -96,    24), S(     2,     4)},
        {S(     7,    17), S(    11,     4), S(   -40,    15), S(     0,     0), S(     0,     0), S(     6,     4), S(    20,   -15), S(     2,    -5)},
        {S(    -9,     2), S(   -12,    -2), S(    -9,     0), S(     0,     0), S(     0,     0), S(    -2,    -2), S(     4,    -6), S(    -6,     4)},
        {S(    -5,     2), S(     9,   -11), S(    -9,     1), S(     0,     0), S(     0,     0), S(    -3,    -7), S(     6,    -6), S(    -7,    -4)},
        {S(     0,    -9), S(   -34,    -2), S(    -3,    -6), S(     0,     0), S(     0,     0), S(     6,    -2), S(   -13,     1), S(   -12,    -2)}
};


constexpr SCORE_TYPE OPP_KING_TROPISM[6] = {S(     0,     0), S(     0,    -2), S(     2,    -1), S(    -5,     4), S(    -6,    -1), S(     0,     0)};

constexpr SCORE_TYPE OUR_KING_TROPISM[6] = {S(     0,     0), S(    -1,    -2), S(    -4,     1), S(    -2,     2), S(     2,     0), S(     0,     0)};

constexpr SCORE_TYPE DOUBLED_PAWN_PENALTY = S(   -24,   -24);

constexpr SCORE_TYPE SQUARE_OF_THE_PAWN = S(     3,     1);

constexpr SCORE_TYPE BACKWARDS_PAWN_PENALTY[2] = {S(   -10,    -1), S(   -18,   -18)};

constexpr SCORE_TYPE PASSED_OUR_DISTANCE[8] = {S(     0,     0), S(    -1,     2), S(    -1,     0), S(     7,    -5), S(    13,    -9), S(    -3,    -7), S(     3,   -14), S(     0,     0)};

constexpr SCORE_TYPE PASSED_OPP_DISTANCE[8] = {S(     0,     0), S(    16,    -6), S(    10,    -5), S(     8,     3), S(     0,    13), S(     7,    20), S(    -9,    12), S(     0,     0)};





#endif //ALTAIRCHESSENGINE_EVALUATION_CONSTANTS_H
