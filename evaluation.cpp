//
// Created by Alexander Tian on 6/26/23.
//

#include <iostream>
#include "evaluation.h"
#include "evaluation_constants.h"

Square get_white_relative_square(Square square, Color color) {
    return static_cast<Square>(square ^ (color * 56));
}

Square get_black_relative_square(Square square, Color color) {
    return static_cast<Square>(square ^ (~color * 56));
}

SCORE_TYPE evaluate_pawns(Position& position, Color color, int& game_phase) {
    SCORE_TYPE score = 0;
    BITBOARD our_pawns = position.get_pieces(PAWN, color);
    BITBOARD opp_pawns = position.get_pieces(PAWN, ~color);

    while (our_pawns) {
        Square square = poplsb(our_pawns);
        Square black_relative_square = get_black_relative_square(square, color);
        Rank relative_rank = rank_of(get_white_relative_square(square, color));

        score += PIECE_VALUES[PAWN];

        score += PIECE_SQUARE_TABLES[PAWN][black_relative_square];

        game_phase += GAME_PHASE_SCORES[PAWN];

        Direction up = color == WHITE ? NORTH : SOUTH;

        // PASSED PAWN
        if (!(passed_pawn_masks[color][square] & opp_pawns)) {
            score += PASSED_PAWN_BONUSES[relative_rank];

            // BLOCKERS
            auto blocker_square = static_cast<Square>(square + static_cast<Square>(up));
            if (from_square(blocker_square) & position.get_pieces(~color)) {
                score += PASSED_PAWN_BLOCKERS[get_piece_type(position.board[blocker_square], ~color)][rank_of(
                        get_white_relative_square(blocker_square, color))];
            }
        }
    }

    return score;
}

SCORE_TYPE evaluate_piece(Position& position, PieceType piece_type, Color color, int& game_phase) {
    SCORE_TYPE score = 0;
    BITBOARD pieces = position.get_pieces(piece_type, color);

    while (pieces) {
        Square square = poplsb(pieces);
        score += PIECE_VALUES[piece_type];

        score += PIECE_SQUARE_TABLES[piece_type][get_black_relative_square(square, color)];

        game_phase += GAME_PHASE_SCORES[piece_type];
    }

    return score;
}

SCORE_TYPE evaluate_pieces(Position& position, int& game_phase) {
    SCORE_TYPE score = 0;

    score += evaluate_pawns(position, WHITE, game_phase);
    score -= evaluate_pawns(position, BLACK, game_phase);

    for (int piece = 1; piece < 6; piece++) {
        score += evaluate_piece(position, static_cast<PieceType>(piece), WHITE, game_phase);
        score -= evaluate_piece(position, static_cast<PieceType>(piece), BLACK, game_phase);
    }

    return score;
}

SCORE_TYPE evaluate(Position& position) {

    SCORE_TYPE score = 0;
    int game_phase = 0;

    score += evaluate_pieces(position, game_phase);
    game_phase = std::min(game_phase, 24);

    SCORE_TYPE evaluation = (mg_score(score) * game_phase + eg_score(score) * (24 - game_phase)) / 24;

    return (position.side * -2 + 1) * evaluation;

}
