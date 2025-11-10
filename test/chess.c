#include "_.h"

enum (PieceKind, Size) {
    pawn = 1,
    rook = 2,
    knight = 3,
    bishop = 4,
    queen = 5,
    king = 6,

    maximumPieceKind
};

enum (Side, Size) {
    gray = 0
    white = maximumPieceKind,
    black = 2 * maximumPieceKind
};

enum (PieceRole, Size) {
    minimumPieceRole = 0,
    whitePawn   = pawn + white,
    whiteRook   = rook + white,
    whiteKnight = knight + white,
    whiteBishop = bishop + white,
    whiteQueen  = queen + white,
    whiteKing   = king + white,
    blackPawn   = pawn + black,
    blackRook   = rook + black,
    blackKnight = knight + black,
    blackBishop = bishop + black,
    blackQueen  = queen + black,
    blackKing   = king + black
};

type (Natural(64)) Bitboard;

#define bit(shift) (1ull << (shift))

enum (BitboardPlace, Bitboard) {
    A1 = bit( 0), A2 = bit( 8), A3 = bit(16), A4 = bit(24), A5 = bit(32), A6 = bit(40), A7 = bit(48), A8 = bit(56),
    B1 = bit( 1), B2 = bit( 9), B3 = bit(17), B4 = bit(25), B5 = bit(33), B6 = bit(41), B7 = bit(49), B8 = bit(57),
    C1 = bit( 2), C2 = bit(10), C3 = bit(18), C4 = bit(26), C5 = bit(34), C6 = bit(42), C7 = bit(50), C8 = bit(58),
    D1 = bit( 3), D2 = bit(11), D3 = bit(19), D4 = bit(27), D5 = bit(35), D6 = bit(43), D7 = bit(51), D8 = bit(59),
    E1 = bit( 4), E2 = bit(12), E3 = bit(20), E4 = bit(28), E5 = bit(36), E6 = bit(44), E7 = bit(52), E8 = bit(60),
    F1 = bit( 5), F2 = bit(13), F3 = bit(21), F4 = bit(29), F5 = bit(37), F6 = bit(45), F7 = bit(53), F8 = bit(61),
    G1 = bit( 6), G2 = bit(14), G3 = bit(22), G4 = bit(30), G5 = bit(38), G6 = bit(46), G7 = bit(54), G8 = bit(62),
    H1 = bit( 7), H2 = bit(15), H3 = bit(23), H4 = bit(31), H5 = bit(39), H6 = bit(47), H7 = bit(55), H8 = bit(63)
};

struct (Board) {
    Bitboard blockers;
    Bitboard pieces[black + 1];
};

void Bitboard_print(Bitboard *bitboard) {

}

void Board_print(Board *board)
{

}

inline void Board_setPiece(Board *board, PieceRole role, BitboardPlace place)
{
    // remove any existing bitboard places
    for (Size pieceRole = 0; pieceRole < black; pieceRole += 1) {
        if (board->pieces[pieceRole] & place) {
            board->pieces[pieceRole] ^= place;
        }
    }
    board->pieces[role] |= place;
    board->blockers |= place;
}

int main() {
    Board board = {
        .pieces = {
            [whitePawn] = A2 | B2 | C2 | D2 | E2 | F2 | G2 | H2,
            [whiteRook] = A1 | H1,
            [whiteKnight] = B1 | G1,
            [whiteBishop] = C1 | F1,
            [whiteQueen] = D1,
            [whiteKing] = E1,
            [blackPawn] = A7 | B7 | C7 | D7 | E7 | F7 | G7 | H7,
            [blackRook] = A8 | H8,
            [blackKnight] = B8 | G8,
            [blackBishop] = C8 | F8,
            [blackQueen] = D8,
            [blackKing] = E8
        }
    }
}


