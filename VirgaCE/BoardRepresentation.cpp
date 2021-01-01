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


}

void BoardRepresentation::add_piece(unsigned char piece, unsigned char index)
{
	chess_board[index] = piece;
	piece_list.insert(std::pair <int, int>(index, piece));

}

void BoardRepresentation::remove_piece(unsigned char index)
{
	piece_list.erase(index);
	chess_board[index] = null_piece;

}

void BoardRepresentation::set_chess_board(std::array<int, board_size> b)
{
	chess_board = b;
}

void BoardRepresentation::set_side(char ch)
{
	side_turn = ch;
}

void BoardRepresentation::set_castling_rights(std::string str)
{
	castling_rights = str;
}

void BoardRepresentation::set_enpassant(int index)
{
	enpassant = index - 16;
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

std::map<int, int> BoardRepresentation::get_piece_list() {
	return piece_list;
}

std::array<int, board_size> BoardRepresentation::get_chess_board() {
	return chess_board;
}

int BoardRepresentation::get_enpassant()
{
	return enpassant;
}

char BoardRepresentation::get_side()
{
	return side_turn;
}

std::string BoardRepresentation::get_castling_rights()
{
	return std::string();
}

bool BoardRepresentation::is_on_board(int index) {
	return ((index & 0x88) == 0);
}

int BoardRepresentation::return_square(std::string square)
{
	int file_char;

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

	return file_char * 16 + (square.at(1) - 1);
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
