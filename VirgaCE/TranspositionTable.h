#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "Move.h"
#include "BoardRepresentation.h"

class TranspositionTable {

private: 

	int piece_keys[12][64];
	int enpassant_keys[64];
	int castle_keys[4];
	int side_key;
	std::vector<int> initial_hashvalues;

	struct TTEntry {
		long zobrist;
		Move m;
		int depth;
		double eval;
		int type;
	};


public:

	void zobrist_initialization();
	void hash_position(const BoardRepresentation& board_representation);














};