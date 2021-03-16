#pragma once

#include "BoardRepresentation.h"
#include "MoveGen.h"

#include <algorithm> 

class Search {

	private:

		MoveGen& move_generator;
		int root;
		Move best_move;
		std::array <int, 10> principal_variation;
		std::array <int, 10> end_index;
	

	public: 

		void search_init(const MoveGen& mg);
		void search(BoardRepresentation& board_representation);
		double minimax(BoardRepresentation& board_representation, int depth, int root_depth, bool side, double alpha, double beta);
		double quiescence(BoardRepresentation& board_representation, double alpha, double beta);
		double alphaBeta(BoardRepresentation& board_representation);
		std::vector<Move> sort_moves(std::vector<Move> moves);
		Search(MoveGen& mg);




};