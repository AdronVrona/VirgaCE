#include "BoardRepresentation.h"

#include <ostream>
#include <sstream>
#include <iostream>
#include <string>

BoardRepresentation::BoardRepresentation()
{

	enpassant = ' ';

	half_move = 0;

	side_turn = white;

	for_print.insert(std::pair<char, int>('w', white));
	for_print.insert(std::pair<char, int>('b', black));
	for_print.insert(std::pair<char, int>(null_piece, 'x'));
	for_print.insert(std::pair<char, int>(black_pawn, 'p'));
	for_print.insert(std::pair<char, int>(black_knight, 'n'));
	for_print.insert(std::pair<char, int>(black_bishop, 'b'));
	for_print.insert(std::pair<char, int>(black_rook, 'r'));
	for_print.insert(std::pair<char, int>(black_queen, 'q'));
	for_print.insert(std::pair<char, int>(black_king, 'k'));
	for_print.insert(std::pair<char, int>(white_pawn, 'P'));
	for_print.insert(std::pair<char, int>(white_knight, 'N'));
	for_print.insert(std::pair<char, int>(white_bishop, 'B'));
	for_print.insert(std::pair<char, int>(white_rook, 'R'));
	for_print.insert(std::pair<char, int>(white_queen, 'Q'));
	for_print.insert(std::pair<char, int>(white_king, 'K'));

	index_convert[white_knight] = 1;
	index_convert[white_bishop] = 2;
	index_convert[white_rook] = 3;
	index_convert[white_queen] = 4;
	index_convert[white_king] = 5;
	index_convert[black_pawn] = 6;
	index_convert[black_knight] = 7;
	index_convert[black_bishop] = 8;
	index_convert[black_rook] = 9;
	index_convert[black_queen] = 10;
	index_convert[black_king] = 11;

	
	value_convert[white_pawn] = 1.00;
	value_convert[white_knight] = 3.00;
	value_convert[white_bishop] = 3.20;
	value_convert[white_rook] = 5.00;
	value_convert[white_queen] = 9.00;
	value_convert[black_pawn] = 1.00;
	value_convert[black_knight] = 3.00;
	value_convert[black_bishop] = 3.20;
	value_convert[black_rook] = 5.00;
	value_convert[black_queen] = 9.00;

	white_king_square = e1;
	black_king_square = e8;

	material_total = MATERIAL_TOTAL;

	piece_total = 32;


}

void BoardRepresentation::add_piece(unsigned char piece, unsigned char index)
{
	chess_board[index] = piece;

}

void BoardRepresentation::add_pieceo(unsigned char index){
	
	chess_board[index] = null_piece;	
}

void BoardRepresentation::remove_piece(unsigned char index)
{
	chess_board[index] = null_piece;
}

void BoardRepresentation::set_chess_board(std::array<int, board_size> b)
{
	chess_board = b;
}


void BoardRepresentation::set_side(bool side)
{
	side_turn = side;
}

void BoardRepresentation::set_castling_rights(std::string str)
{
	castling_rights = str;
}

void BoardRepresentation::set_enpassant(int index)
{
	enpassant = index;
}

void BoardRepresentation::set_halfmove(int n)
{
	half_move = n;
}

void BoardRepresentation::print_the_board() {

	for (int i = 0; i < 120; ++i) {
		if (i % 8 == 0 && i != 0 && i < 112) i = i + 8, std::cout << std::endl;
		std::cout << for_print[chess_board[i]];
	}
}

bool BoardRepresentation::is_on_board(int index) const {
	return ((index & 0x88) == 0);
}

int BoardRepresentation::return_square(std::string square)
{
	int file_char = 0;

	if (square.at(0) == 'a') {
		file_char = 0;
	}
	if (square.at(0) == 'b') {
		file_char = 1;
	}
	if (square.at(0) == 'c') {
		file_char = 2;
	}
	if (square.at(0) == 'd') {
		file_char = 3;
	}
	if (square.at(0) == 'e') {
		file_char = 4;
	}
	if (square.at(0) == 'f') {
		file_char = 5;
	}
	if (square.at(0) == 'g') {
		file_char = 6;
	}
	if (square.at(0) == 'h') {
		file_char = 7;
	}

	return (16 * (square.at(1) - '0' - 1) + file_char);

}

bool BoardRepresentation::dead_position()
{
	if (material_total > 272) return false;

	if (material_total == 260) return false;

	if (material_total <= 272 && piece_count > 3) return false; 

	return true;
}


std::ostream& operator<<(std::ostream& o, std::vector <std::string> vec)
{
	for (int i = 0; i < sizeof(vec); ++i) {

		o << vec.at(i);

		if (i % 8 == 0) {
			o << std::endl;
		}
	}

	return o;
}
