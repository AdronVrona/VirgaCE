#pragma once

#ifndef boardrepresentation_h

#define boardrepresentation_h

#include <vector>
#include <bitset>
#include <string>
#include <iostream>
#include <unordered_map>
#include <map>
#include <array>

#include "Common.h"
#include "Piece.h"


class BoardRepresentation {

	private: 

		std::array <int, board_size> chess_board;
		std::array <int, board_size> index_board;
		std::vector<int> piece_lists;
		std::unordered_map<int, int> piece_list;
		std::map<int, char> for_print;
		bool side_turn;
		std::string castling_rights; 
		unsigned int enpassant;
		unsigned int half_move;


	public:

		BoardRepresentation();

		friend std::ostream& operator<<(std::ostream& o, std::vector <std::string> vec );
		void print_the_board();
		void add_piece(unsigned char piece, unsigned char index);
		void add_pieceo(unsigned char index);
		void remove_piece(unsigned char index);
		bool is_on_board(int index) const;
		int return_square(std::string square);
		void print_piece_lists();
		int white_king_square;
		int black_king_square;

		// getters

		inline std::unordered_map<int, int> get_piece_list() const { return piece_list; }
		inline std::vector<int> get_piece_lists() const { return piece_lists;  }
		inline std::array<int, board_size> get_chess_board() const { return chess_board; }
		inline int get_enpassant() const { return enpassant; }
		inline bool get_side() const { return side_turn; }
		inline std::string get_castling_rights() const { return castling_rights; }
		inline int get_halfmove() const { return half_move; }

		// setters
		void set_chess_board(std::array<int, board_size> b);
		void set_side(bool side);
		void set_castling_rights(std::string str);
		void set_enpassant(int index);
		void set_halfmove(int n);


};

#endif 