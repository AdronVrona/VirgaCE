#pragma once

// helper variables
static const int board_size = 128;
static const int pawn_array_size = 3;
static const int sliding_array_size = 4;
static const int leaping_array_size = 8;
static const int queen_array_size = 8;


static const int pawn_offset[3] = { 16, 15, 17 };
static const int knight_offset[8] = { -33, -31, -18, -14, 14, 18, 31, 33 };
static const int bishop_offset[4] = { -17, -15, 15, 17};
static const int rook_offset[4] = { -16,  -1,   1,  16 };
static const int queen_offset[8] = { -17, -16, -15,  -1,  1, 15, 16, 17 };
static const int king_offset[8] = { -17, -16, -15,  -1,  1, 15, 16, 17   };


enum File: unsigned int {
    file_a = 0,
    file_b,
    file_c,
    file_d,
    file_e,
    file_f,
    file_g,
    file_h
};

enum Rank: unsigned int {
    rank_1 = 1,
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8
};


enum Coordinate : const unsigned int {

    a1,
    b1,
    c1,
    d1,
    e1,
    f1,
    g1,
    h1,
    a2 = 16,
    b2,
    c2,
    d2,
    e2,
    f2,
    g2,
    h2,
    a3 = 32,
    b3,
    c3,
    d3,
    e3,
    f3,
    g3,
    h3,
    a4 = 48,
    b4,
    c4,
    d4,
    e4,
    f4,
    g4,
    h4,
    a5 = 64,
    b5,
    c5,
    d5,
    e5,
    f5,
    g5,
    h5,
    a6 = 80,
    b6,
    c6,
    d6,
    e6,
    f6,
    g6,
    h6,
    a7 = 96,
    b7,
    c7,
    d7,
    e7,
    f7,
    g7,
    h7,
    a8 = 112,
    b8,
    c8,
    d8,
    e8,
    f8,
    g8,
    h8

};