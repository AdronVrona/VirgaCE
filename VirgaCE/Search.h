#pragma once

#include "BoardRepresentation.h"
#include "MoveGen.h"
#include "TranspositionTable.h"
#include "ZobristHashing.h"

#include <algorithm> 

class Search {

	private:

		MoveGen& move_generator;
		int root;
		Move best_move;
		std::array <int, 10> principal_variation;
		std::array <int, 10> end_index;

		//transposition table
		TranspositionTable* hash_tt;

		//
		std::vector <Move> pv;
	

	public: 

		void search_init();
		void search(BoardRepresentation& board_representation);
		double quiescence(BoardRepresentation& board_representation, double alpha, double beta);
		double alphaBeta(BoardRepresentation& board_representation, int depth, int remaining_depth, double alpha, double beta);
		std::vector<Move> test_sort(BoardRepresentation& board_representation, std::vector<Move> moves);
		std::vector<Move> sort_moves(std::vector<Move> moves);
		std::vector<Move> quiesence_sort(std::vector<Move> moves);
		bool allowed_null(BoardRepresentation& board_representation, double alpha, double beta);
		bool in_check(BoardRepresentation& board_representation);
		double mate_score(BoardRepresentation& board_representation, int remaining_depth);
		Search(MoveGen& mg);




};