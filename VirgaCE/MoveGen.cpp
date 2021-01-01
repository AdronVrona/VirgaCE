#include "MoveGen.h"

MoveGen::MoveGen() {

	for_print_movegen.insert(std::pair<int, std::string>(0, "a1"));
	for_print_movegen.insert(std::pair<int, std::string>(1, "b1"));
	for_print_movegen.insert(std::pair<int, std::string>(2, "c1"));
	for_print_movegen.insert(std::pair<int, std::string>(3, "d1"));
	for_print_movegen.insert(std::pair<int, std::string>(4, "e1"));
	for_print_movegen.insert(std::pair<int, std::string>(5, "f1"));
	for_print_movegen.insert(std::pair<int, std::string>(6, "g1"));
	for_print_movegen.insert(std::pair<int, std::string>(7, "h1"));
	for_print_movegen.insert(std::pair<int, std::string>(16, "a2"));
	for_print_movegen.insert(std::pair<int, std::string>(17, "b2"));
	for_print_movegen.insert(std::pair<int, std::string>(18, "c2"));
	for_print_movegen.insert(std::pair<int, std::string>(19, "d2"));
	for_print_movegen.insert(std::pair<int, std::string>(20, "e2"));
	for_print_movegen.insert(std::pair<int, std::string>(21, "f2"));
	for_print_movegen.insert(std::pair<int, std::string>(22, "g2"));
	for_print_movegen.insert(std::pair<int, std::string>(23, "h2"));
	for_print_movegen.insert(std::pair<int, std::string>(32, "a3"));
	for_print_movegen.insert(std::pair<int, std::string>(33, "b3"));
	for_print_movegen.insert(std::pair<int, std::string>(34, "c3"));
	for_print_movegen.insert(std::pair<int, std::string>(35, "d3"));
	for_print_movegen.insert(std::pair<int, std::string>(36, "e3"));
	for_print_movegen.insert(std::pair<int, std::string>(37, "f3"));
	for_print_movegen.insert(std::pair<int, std::string>(38, "g3"));
	for_print_movegen.insert(std::pair<int, std::string>(39, "h3"));
	for_print_movegen.insert(std::pair<int, std::string>(48, "a4"));
	for_print_movegen.insert(std::pair<int, std::string>(49, "b4"));
	for_print_movegen.insert(std::pair<int, std::string>(50, "c4"));
	for_print_movegen.insert(std::pair<int, std::string>(51, "d4"));
	for_print_movegen.insert(std::pair<int, std::string>(52, "e4"));
	for_print_movegen.insert(std::pair<int, std::string>(53, "f4"));
	for_print_movegen.insert(std::pair<int, std::string>(54, "g4"));
	for_print_movegen.insert(std::pair<int, std::string>(55, "h4"));
	for_print_movegen.insert(std::pair<int, std::string>(64, "a5"));
	for_print_movegen.insert(std::pair<int, std::string>(65, "b5"));
	for_print_movegen.insert(std::pair<int, std::string>(66, "c5"));
	for_print_movegen.insert(std::pair<int, std::string>(67, "d5"));
	for_print_movegen.insert(std::pair<int, std::string>(68, "e5"));
	for_print_movegen.insert(std::pair<int, std::string>(69, "f5"));
	for_print_movegen.insert(std::pair<int, std::string>(70, "g5"));
	for_print_movegen.insert(std::pair<int, std::string>(71, "h5"));
	for_print_movegen.insert(std::pair<int, std::string>(80, "a6"));
	for_print_movegen.insert(std::pair<int, std::string>(81, "b6"));
	for_print_movegen.insert(std::pair<int, std::string>(82, "c6"));
	for_print_movegen.insert(std::pair<int, std::string>(83, "d6"));
	for_print_movegen.insert(std::pair<int, std::string>(84, "e6"));
	for_print_movegen.insert(std::pair<int, std::string>(85, "f6"));
	for_print_movegen.insert(std::pair<int, std::string>(86, "g6"));
	for_print_movegen.insert(std::pair<int, std::string>(87, "h6"));
	for_print_movegen.insert(std::pair<int, std::string>(96, "a7"));
	for_print_movegen.insert(std::pair<int, std::string>(97, "b7"));
	for_print_movegen.insert(std::pair<int, std::string>(98, "c7"));
	for_print_movegen.insert(std::pair<int, std::string>(99, "d7"));
	for_print_movegen.insert(std::pair<int, std::string>(100, "e7"));
	for_print_movegen.insert(std::pair<int, std::string>(101, "f7"));
	for_print_movegen.insert(std::pair<int, std::string>(102, "g7"));
	for_print_movegen.insert(std::pair<int, std::string>(103, "h7"));
	for_print_movegen.insert(std::pair<int, std::string>(112, "a8"));
	for_print_movegen.insert(std::pair<int, std::string>(113, "b8"));
	for_print_movegen.insert(std::pair<int, std::string>(114, "c8"));
	for_print_movegen.insert(std::pair<int, std::string>(115, "d8"));
	for_print_movegen.insert(std::pair<int, std::string>(116, "e8"));
	for_print_movegen.insert(std::pair<int, std::string>(117, "f8"));
	for_print_movegen.insert(std::pair<int, std::string>(118, "g8"));
	for_print_movegen.insert(std::pair<int, std::string>(119, "h8"));
	



}

std::list<Move> MoveGen::get_move_list()
{
	return move_list;
}

void MoveGen::generate_pseudo_legal_moves(BoardRepresentation& board_representation)
{

	for (const auto& map_pair : board_representation.get_piece_list()) {

		switch (map_pair.second) {

			case (white_pawn):
			case (black_pawn): {

			generate_pl_pawn_moves(board_representation, map_pair.first);
			break;

			}

			case(white_knight):
			case(black_knight): {

			int array_size = 8;
			generate_pl_leaping_moves(board_representation, map_pair.first, knight_offset, array_size);
			break;

			}

			case(white_bishop):
			case(black_bishop): {

			int array_size = 4;
			generate_pl_sliding_moves(board_representation, map_pair.first, bishop_offset, array_size);
			break;

			}
		
			case(white_rook):
			case(black_rook): {

			int array_size = 4;
			generate_pl_sliding_moves(board_representation, map_pair.first, rook_offset, array_size);
			break;

			}

			case(white_king):
			case(black_king): {
				
			int array_size = 8;
			generate_pl_leaping_moves(board_representation, map_pair.first, king_offset, array_size);
			generate_pl_castle_moves(board_representation, map_pair.first);
			break;

			}

			case(white_queen):
			case(black_queen): {

			int array_size = 8;
			generate_pl_sliding_moves(board_representation, map_pair.first, queen_offset, array_size);
			break;

			}

		}

	}

}

void MoveGen::generate_pl_pawn_moves(BoardRepresentation& board_representation, int index)
{

	std::array<int, board_size> board_arr = board_representation.get_chess_board();

	int color = 1;

	if (board_arr[index] & black) color = -1;

	for (int i = 0; i < 3; ++i) {

		int offset = pawn_offset[i];
		int target_square = index + color * offset;


		if (board_representation.is_on_board(target_square)) {

			// PAWN MOVING FORWARD
			if (i == 0 && board_arr[target_square] == null_piece) {

				move_list.push_back(Move(index, target_square, board_arr[index], null_piece, false, false));

				if ((index < 0x20 && color == 1) || (index > 0x57 && color == -1)) {

					if (board_representation.is_on_board(index + color * offset * 2) && board_arr[index + color * offset * 2] == null_piece) {

						move_list.push_back(Move(index, index + color * offset * 2, board_arr[index], null_piece, true, ' '));

					}
				}
			}
			//PAWN CAPTURE
			if (i != 0 && board_arr[target_square] != 0 && (board_arr[index] | board_arr[target_square]) == piece_color_check) {

				move_list.push_back(Move(index, target_square, board_arr[index], board_arr[target_square], false, ' '));

			}
			//ENPASSANT 
			if (i != 0 && target_square == board_representation.get_enpassant() && (board_arr[index] | board_arr[target_square]) == piece_color_check) {

				move_list.push_back(Move(index, board_representation.get_enpassant(), board_arr[index], board_arr[target_square], false, ' '));

			}
				
		}

		
	}
}

void MoveGen::generate_pl_sliding_moves(BoardRepresentation& board_representation, int index, const int piece_offset[], int array_size)
{

	std::array<int, board_size> board_arr = board_representation.get_chess_board();

	int color = 1;

	if (board_arr[index] & black) color = -1;

	for (int i = 0; i < array_size ; ++i) {

		int target_square = index + piece_offset[i];

		while (board_representation.is_on_board(target_square)) {

			int y = board_arr[target_square] & black;

			if (((board_arr[target_square] & board_arr[index]) & 0x03) == 0 && board_arr[target_square] > null_piece) {

				move_list.push_back(Move(index, target_square, board_arr[index], board_arr[target_square], false, ' '));

				break;

			}

			else if (board_arr[target_square] == 0) move_list.push_back(Move(index, target_square, board_arr[index], null_piece, false, ' '));

			else break;

			target_square += piece_offset[i];

		}


	}

}

void MoveGen::generate_pl_leaping_moves(BoardRepresentation& board_representation, int index, const int piece_offset[], int array_size) {

	std::array<int, board_size> board_arr = board_representation.get_chess_board();
	
	int color = 1;

	if (board_arr[index] & black) color = -1;

	for (int i = 0; i < array_size; ++i) {

		int target_square = index + color * piece_offset[i];

		if (board_representation.is_on_board(target_square)) {

			if (((board_arr[target_square] & board_arr[index]) & 0x03) == 0 && board_arr[target_square] > 0) {

				move_list.push_back(Move(index, target_square, board_arr[index], board_arr[target_square], false, ' '));
			}

			else if (board_arr[target_square] == 0) move_list.push_back(Move(index, target_square, board_arr[index], null_piece, false, ' '));

		}

	}

}

void MoveGen::generate_legal_moves(BoardRepresentation& board_representation, int color)
	{

	int king_index = 0;

	int color_helper = white;

	if (color == white) color_helper = black;

	for (Move& move : move_list) {

		make_move(board_representation, move);


		std::map<int, int> usable_piece_list = board_representation.get_piece_list();

		for (auto it = usable_piece_list.begin(); it != usable_piece_list.end(); ++it) {
			if (it->second == neutral_king + color) {
				king_index = it->first;
			}
		}

		if (move.castle != ' ') {
			
		}
		
		if (!(is_attacked(board_representation, king_index, color_helper))) {
			legal_move_list.push_back(move);
		}
		
		un_make_move(board_representation, move);

	}
}

void MoveGen::generate_pl_castle_moves(BoardRepresentation& board_representation, int index)
{
	std::array<int, board_size> board_arr = board_representation.get_chess_board();

	// WHITE CASTLING 

	if ((board_arr[index] & piece_color_check) == white) {

		// SHORT CASTLE 

		if (board_arr[index + 1] == null_piece && board_arr[index + 2] == null_piece && board_representation.get_castling_rights().find('K' != std::string::npos)) {
			move_list.push_back(Move(index, index + 2, white_king, null_piece, false, 'K'));
		}

		//LONG CASTLE

		if (board_arr[index - 1] == null_piece && board_arr[index - 2] == null_piece && board_arr[index - 3] == null_piece && board_representation.get_castling_rights().find('Q' != std::string::npos)) {
			move_list.push_back(Move(index, index - 2, white_king, null_piece, false, 'Q'));
		}

	}

	// BLACK CASTLING 

	else {

		// SHORT CASTLE 

		if (board_arr[index + 1] == null_piece && board_arr[index + 2] == null_piece && board_representation.get_castling_rights().find('k' != std::string::npos)) {
			move_list.push_back(Move(index, index - 2, black_king, null_piece, false, 'k'));
		}

		//LONG CASTLE

		if (board_arr[index - 1] == null_piece && board_arr[index - 2] == null_piece && board_arr[index - 3] == null_piece && board_representation.get_castling_rights().find('q' != std::string::npos)) {
			move_list.push_back(Move(index, index + 2, black_king, null_piece, false, 'q'));
		}

	}

}


void MoveGen::make_move(BoardRepresentation& board_representation, Move m)
{

	if (m.enpassant == true) {
		board_representation.set_enpassant(m.end_index);
	}
	
	if (m.castle != ' ') {
		make_castle(board_representation, m.castle);
	}

	board_representation.remove_piece(m.start_index);
	board_representation.add_piece(m.piece_type, m.end_index);

	//std::cout << std::endl;
	//std::cout << std::endl;
	//board_representation.print_the_board();

	made_moves.push_back(m);
}

void MoveGen::un_make_move(BoardRepresentation& board_representation, Move m)
{

	made_moves.pop_back();

	board_representation.remove_piece(m.end_index);

	if (m.capture > 0) {
		board_representation.add_piece(m.capture, m.end_index);
	}

	board_representation.add_piece(m.piece_type, m.start_index);

	if (made_moves.back().enpassant) {
		board_representation.set_enpassant(m.end_index);
	}

}

void MoveGen::make_castle(BoardRepresentation& board_representation, char ch)
{
	std::string set_castle	= board_representation.get_castling_rights().erase(ch);

	switch (ch) {

	case ('K'): {
		board_representation.add_piece(white_rook, f1);
		board_representation.remove_piece(h1);
		break;
	}
	case ('k'): {
		board_representation.add_piece(black_rook, f8);
		board_representation.remove_piece(h8);
		break;
	}
	case ('Q'): {
		board_representation.add_piece(white_rook, d1);
		board_representation.remove_piece(a1);
		break;
	}
	case ('q'): {
		board_representation.add_piece(black_rook, d8);
		board_representation.remove_piece(a8);
		break;
	}

	}

	board_representation.set_castling_rights(set_castle);

}

void MoveGen::unmake_castle(BoardRepresentation& board_representation, Move m)
{

	std::string set_castle = board_representation.get_castling_rights();
	set_castle.push_back(m.castle);

	switch (m.castle) {

	case('K'): {
		board_representation.add_piece(white_rook, h1);
		board_representation.remove_piece(f1);
	}
	case ('k'): {
		board_representation.add_piece(black_rook, h8);
		board_representation.remove_piece(f8);
		break;
	}
	case ('Q'): {
		board_representation.add_piece(white_rook, a1);
		board_representation.remove_piece(d1);
		break;
	}
	case ('q'): {
		board_representation.add_piece(black_rook, a8);	
		board_representation.remove_piece(d8);
		break;
	}

	}

	board_representation.set_castling_rights(set_castle);
}



bool MoveGen::is_attacked(BoardRepresentation& board_representation, int index, int color)
{

	std::array<int, board_size> board_arr = board_representation.get_chess_board();

	int target_square = index;

	int color_helper = 1;
	if (color == black) color_helper = -1;


	//PAWN 
	if (color == white) {
		if (board_representation.is_on_board(index + pawn_offset[0]) && board_arr[index + pawn_offset[0]] == black_pawn) return true;
		if (board_representation.is_on_board(index + pawn_offset[2]) && board_arr[index + pawn_offset[2]] == black_pawn) return true;
		color_helper = 1;
	}
	else {
		if (board_representation.is_on_board(index - pawn_offset[0]) && board_arr[index - pawn_offset[0]] == white_pawn) return true;
		if (board_representation.is_on_board(index - pawn_offset[2]) && board_arr[index - pawn_offset[2]] == white_pawn) return true;
		color_helper = -1;
	}

	//SLIDING -- BISHOP + QUEEN

	for (int i = 0; i < sliding_array_size; ++i) {

		target_square = index;

		while (board_representation.is_on_board(target_square)) {

			if ((board_arr[target_square] & color) == color) break;

			if (board_arr[target_square] == white_bishop * color_helper || board_arr[target_square] == white_queen * color_helper) return true;

			target_square += bishop_offset[i];

		}
	}

	//LEAPING -- KNIGHT

	target_square = index;

	for (int i = 0; i < leaping_array_size; ++i) {

		target_square = index + knight_offset[i];

		if (board_representation.is_on_board(target_square)) {

			if (board_arr[target_square] == white_knight * color_helper) return true; 

		}

	}

	//SLIDING -- ROOK + QUEEN

	for (int i = 0; i < sliding_array_size; ++i) {

		target_square = index;

		while (board_representation.is_on_board(target_square)) {

			if ((board_arr[index] & color) & (board_arr[target_square] & color)) break;

			if (board_arr[target_square] == white_rook * color_helper || board_arr[target_square] == (neutral_queen + color)) {
				std::cout << "target: " << target_square << std::endl;
				return true;
			}

			target_square += rook_offset[i];

		}
	}

	//LEAPING -- KING

	target_square = index;

	for (int i = 0; i < leaping_array_size; ++i) {

		target_square = index + king_offset[i];

		if (board_representation.is_on_board(target_square)) {

			if (board_arr[target_square] == white_king * color_helper) return true;

		}

	}

	return false;

}

void MoveGen::print_move_list()
{
	for (Move& move: legal_move_list) {
	
		std::cout << for_print_movegen[move.start_index];
		std::cout << for_print_movegen[move.end_index];
		std::cout << std::endl;
	}
}















