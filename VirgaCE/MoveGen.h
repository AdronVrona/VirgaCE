
#include "Move.h"
#include "BoardRepresentation.h"
#include <list>
#include <iostream>
#include <string>

class MoveGen {


	private:

		std::list<Move> move_list;
		std::list<Move> legal_move_list;
		std::list<Move> made_moves;
		std::map<int, std::string> for_print_movegen;
		int capture_count;


	public: 

		std::list<Move> get_move_list();

		//generate moves
		void generate_pl_pawn_moves(const BoardRepresentation& board_representation, int index);
		void generate_pl_sliding_moves(const BoardRepresentation& board_representation, int index, const int piece_offset[], int array_size);
		void generate_pl_leaping_moves(const BoardRepresentation& board_representation, int index, const int piece_offset[], int array_size);
		void generate_pl_castle_moves(const BoardRepresentation& board_representation, int index);
		void generate_pseudo_legal_moves(const BoardRepresentation& board_representation);
		void generate_legal_moves(BoardRepresentation& board_representation, int color);

		//make-unmake moves
		void make_move(BoardRepresentation& board_representation, Move m);
		void un_make_move(BoardRepresentation& board_representation, Move m);
		void make_castle(BoardRepresentation& board_representation, char ch);
		void unmake_castle(BoardRepresentation& board_representation, Move m);


		//helper methods
		inline bool is_attacked(const BoardRepresentation& board_representation, int index, int color);
		inline bool can_capture(const BoardRepresentation& board_representation, int index, int target_square);
		long perft(BoardRepresentation& board_representation, int depth);
		long perft_divide(BoardRepresentation& board_representation, int depth, int divide);

		void print_move_list();

		MoveGen();









};