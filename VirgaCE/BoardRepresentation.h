#pragma once

#ifndef boardrepresentation_h

#define boardrepresentation_h

#include <vector>
#include <bitset>
#include <string>
#include <map>
#include <array>

#include "Common.h"
#include "Piece.h"

class BoardRepresentation {

	private: 

		std::array <int, board_size> chess_board;
		std::map<int, int> piece_list;
		std::map<int, char> for_print;
		bool side_turn;
		std::string castling_rights; 
		unsigned char enpassant;
		unsigned int half_move;


	public:

		BoardRepresentation();

		friend std::ostream& operator<<(std::ostream& o, std::vector <std::string> vec );
		void print_the_board();
		void add_piece(unsigned char piece, unsigned char index);
		void remove_piece(unsigned char index);
		bool is_on_board(int index) const;
		int return_square(std::string square);
		int white_king_square;
		int black_king_square;

		// getters

		std::map<int, int> get_piece_list() const;
		std::array<int,board_size> get_chess_board() const;
		int get_enpassant() const;
		bool get_side() const;
		std::string get_castling_rights() const;

		// setters
		void set_chess_board(std::array<int, board_size> b);
		void set_side(bool side);
		void set_castling_rights(std::string str);
		void set_enpassant(int index);
		void set_halfmove(int n);


};

#endif 