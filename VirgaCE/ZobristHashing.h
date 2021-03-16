#pragma once

#ifndef ZOBRISTHASHING_CLASS
#define ZOBRISTHASHING_CLASS

#include "BoardRepresentation.h"

#include <vector>

class ZobristHashing {

private:

	int piece_keys[12][64];
	int enpassant_keys[64];
	int castle_keys[4];
	int side_key;
	std::vector<int> initial_hashvalues;

public:

	void zobrist_initialization();
	void hash_position(const BoardRepresentation& board_representation);




























};

#endif