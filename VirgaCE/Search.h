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

		//ESSENTIAL METHODS
		void search_init();
		void search(BoardRepresentation& board_representation);
		double quiescence(BoardRepresentation& board_representation, double alpha, double beta);

		//SEARCH ALGORITHMS
		double alphaBeta(BoardRepresentation& board_representation, int depth, int remaining_depth, double alpha, double beta);

		//double MTDF()
		//double AlphaBetaWithMemory()

		double NegaScout(BoardRepresentation& board_representation, int depth, int remaining_depth, double alpha, double beta);


		//MOVE SORTING
		std::vector<Move> test_sort(const BoardRepresentation& board_representation, std::vector<Move>& moves);
		std::vector<Move> sort_moves(std::vector<Move> moves);
		std::vector<Move> quiesence_sort(std::vector<Move>& moves);

		//HELPER FUNCTIONS
		bool allowed_null(BoardRepresentation& board_representation, double alpha, double beta);
		bool in_check(BoardRepresentation& board_representation);
		double mate_score(BoardRepresentation& board_representation, int remaining_depth);
		double mated_score(BoardRepresentation& board_representation, int remaining_depth);
		double check_or_stale(BoardRepresentation& board_representation, int remaining_depth);
		bool is_threefold(const BoardRepresentation& board_representation);


		Search(MoveGen& mg);




};