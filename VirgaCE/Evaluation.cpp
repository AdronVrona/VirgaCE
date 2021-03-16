#include "Evaluation.h"

const int Evaluation::pawn_pst[7][8] = {
{ },
{  3,   3,  10,  19,  16,  19,   7,  -5},
{ -9, -15,  11,  15,  32,  22,   5, -22},
{ -4, -23,   6,  20,  40,  17,   4,  -8},
{ 13,   0, -13,   1,  11,  -2, -13,   5},
{  5 ,-12,  -7,  22,  -8,  -5, -15,  -8},
{ -7,   7,  -3, -13,   5,  16,  10,  -8},

};

const int Evaluation::knight_pst[8][8] = {
{-175,-92, -74, -73, -73, -74, -92,-175},
{-77, -41, -27, -15, -15,  -27, -41,-77},
{-61, -17,   6,  12,  12,   6, -17, -61},
{-35,   8,  40,  49,  49,  40,   8, -35},
{-34,  13,  44,  51,  51,  44,  13, -34},
{-9 ,  22,  58,  53,  53,  58,  22,  -9},
{-67, -27,   4,  37,  37,   4, -27, -67},
{-201,-83, -56, -26, -26, -56, -83,-201},

};

const int Evaluation::bishop_pst[8][8] = {
{-37,  -4,  -6, -16, -16,  -6,  -4, -37},
{-11,   6,  13,   3,   3,  13,   6, -11},
{ -5,  15,  -4,  12,  12,  -4,  15,  -5},
{ -4,   8,  18,  27,  27,  18,   8,  -4},
{ -8,  20,  15,  22,  22,  15,  20,  -8},
{-11,   4,   1,   8,   8,   1,   4, -11},
{-12, -10,   4,   0,   0,   4, -10, -12},
{-34,   1, -10, -16, -16, -10,   1, -34},

};

const int Evaluation::rook_pst[8][8] = {
{-31,  -20, -14,  -5,  -5, -14, -20, -31},
{-21,  -13,  -8,   6,   6,  -8, -13, -21},
{-25,  -11,  -1,   3,   3,  -1, -11, -25},
{-13,   -5,  -4,  -6,  -6,  -4,  -5, -13},
{-27,  -15,  -4,   3,   3,  -4, -15, -27},
{-22,   -2,   6,  12,  12,   6,  -2, -22},
{ -2,   12,  16,  18,  18,  16,  12,  -2},
{-17,  -19,  -1,   9,   9,  -1, -19, -17},
	
};

const int Evaluation::queen_pst[8][8] = {
{  3,   -5,  -5,   4,   4,  -5,  -5,   3},
{ -3,    5,   8,  12,  12,   8,   5,  -3},
{ -3,    6,  13,   7,   7,  13,   6,  -3},
{  4,    5,   9,   8,   8,   9,   5,   4},
{  0,   14,  12,   5,   5,  12,  14,   0},
{ -4,   10,   6,   8,   8,   6,  10,  -4},
{ -5,    6,  10,   8,   8,  10,   6,  -5},
{ -2,   -2,   1,  -2,  -2,   1,  -2,  -2},

};

Evaluation::Evaluation() {


}

double Evaluation::material_eval(const BoardRepresentation& board_representation)
{
	double x = 0;
	int file = 0;
	int rank = 0;
	int pawns_white = 0, pawns_black = 0;
	int knights_white = 0, knights_black = 0;
	int bishops_white = 0, bishops_black = 0;
	int rooks_white = 0, rooks_black = 0;
	int queens_white = 0, queens_black = 0;

	std::array<int, board_size> board_arr = board_representation.get_chess_board();
	
	for (int i = 0; i < 120; ++i) {

		if (i % 8 == 0 && i != 0 && i < 112) i = i + 8;

		file = i & 7;
		rank = i >> 4;

		switch (board_arr[i]) {

		case (white_pawn): {
			++pawns_white;
			int y = pawn_pst[7 - rank][file];
			x = x + pawn_pst[7 - rank][7 - file];
			break;
		}
		case (black_pawn): {
			++pawns_black;
			int u = pawn_pst[7 - rank][7 - file];
			x = x - pawn_pst[7 - rank][7 - file];
			break;
		}
		case (white_knight): {
			++knights_white;
			int z = knight_pst[7 - rank][7 - file];
			x = x + knight_pst[7 - rank][7 - file];
			break;
		}
		case (black_knight): {
			++knights_black;
			x = x - knight_pst[7 - rank][7 - file];
			break;
		}
		case (white_bishop): {
			++bishops_white;
			x = x + bishop_pst[7 - rank][7 - file];
			break;
		}
		case (black_bishop): {
			++bishops_black;
			x = x - bishop_pst[7 - rank][7 - file];
			break;
		}
		case (white_rook): {
			++rooks_white;
			x = x + rook_pst[7 - rank][7 - file];
			break;
		}
		case (black_rook): {
			++rooks_black;
			x = x - bishop_pst[7 - rank][7 - file];
			break;
		}
		case (white_queen): {
			++queens_white;
			x = x + queen_pst[7 - rank][7 - file];
			break;
		}
		case (black_queen): {
			++queens_black;
			x = x - queen_pst[7 - rank][7 - file];
			break;
		}


		}

	}
	x = x + 900 * (queens_white - queens_black) + 500 * (rooks_white - rooks_black) + 320 * (bishops_white - bishops_black) + 300* (knights_white - knights_black) + 100 * (pawns_white - pawns_black);
	//std::cout << x / 100.0 << std::endl;
	return x/100.0;
}
