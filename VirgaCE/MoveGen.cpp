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

void MoveGen::generate_pseudo_legal_moves(const BoardRepresentation& board_representation)
{
	move_list.clear();

	for (const auto& map_pair : board_representation.get_piece_list()) {

		int helper = map_pair.second & piece_color_check;

		if (((helper == white) && board_representation.get_side()) || (helper == black) && !board_representation.get_side()){

			switch (map_pair.second) {

			case (white_pawn):
			case (black_pawn): {

				generate_pl_pawn_moves(board_representation, map_pair.first);
				break;

			}

			case(white_knight):
			case(black_knight): {

				generate_pl_leaping_moves(board_representation, map_pair.first, knight_offset, leaping_array_size);
				break;

			}

			case(white_bishop):
			case(black_bishop): {

				int array_size = 4;
				generate_pl_sliding_moves(board_representation, map_pair.first, bishop_offset, sliding_array_size);
				break;

			}

			case(white_rook):
			case(black_rook): {

	
				generate_pl_sliding_moves(board_representation, map_pair.first, rook_offset, sliding_array_size);
				break;

			}

			case(white_king):
			case(black_king): {

				generate_pl_leaping_moves(board_representation, map_pair.first, king_offset, leaping_array_size);
				generate_pl_castle_moves(board_representation, map_pair.first);
				break;

			}

			case(white_queen):
			case(black_queen): {

				generate_pl_sliding_moves(board_representation, map_pair.first, queen_offset, queen_array_size);
				break;

			}

			}

		}

	}

}

void MoveGen::generate_pl_pawn_moves(const BoardRepresentation& board_representation, int index)
{

	std::array<int, board_size> board_arr = board_representation.get_chess_board();

	int color = 1;

	if (board_arr[index] & black) color = -1;

	for (int i = 0; i < pawn_array_size; ++i) {

		int offset = pawn_offset[i];
		int target_square = index + color * offset;


		if (board_representation.is_on_board(target_square)) {

			// PAWN MOVING FORWARD
			if (i == 0 && board_arr[target_square] == null_piece) {

				move_list.push_back(Move(index, target_square, board_arr[index], null_piece, false, ' ', false));

				if ((index < a3 && color == 1) || (index > h6 && color == -1)) {

					if (board_arr[index + color * offset * 2] == null_piece) {

						move_list.push_back(Move(index, index + color * offset * 2, board_arr[index], null_piece, true, ' ', false));

					}
				}
				else if ((index <= h2 && color == -1) || (index >= a7 && color == 1)) {
					if (i != 0 && board_arr[target_square] != 0 && (board_arr[index] | board_arr[target_square]) == piece_color_check) {
						move_list.push_back(Move(index, target_square, board_arr[index], board_arr[target_square], false, ' ', true));
					}

					move_list.push_back(Move(index, target_square, board_arr[index], null_piece, false, ' ', true));

				}
			}
			//PAWN CAPTURE
			if (i != 0 && board_arr[target_square] != 0 && ((board_arr[index] & piece_color_check) & (board_arr[target_square] & piece_color_check)) == null_piece) {

				move_list.push_back(Move(index, target_square, board_arr[index], board_arr[target_square], false, ' ', false));

			}
			//ENPASSANT 
			if (i != 0 && target_square == board_representation.get_enpassant() && (board_arr[index] | board_arr[target_square]) == piece_color_check) {

				move_list.push_back(Move(index, board_representation.get_enpassant(), board_arr[index], board_arr[target_square], false, ' ', false));

			}
				
		}

		
	}
}

void MoveGen::generate_pl_sliding_moves(const BoardRepresentation& board_representation, int index, const int piece_offset[], int array_size)
{

	std::array<int, board_size> board_arr = board_representation.get_chess_board();

	int color = 1;

	if (board_arr[index] & black) color = -1;

	for (int i = 0; i < array_size ; ++i) {

		int target_square = index + piece_offset[i];

		while (board_representation.is_on_board(target_square)) {

			if (((board_arr[target_square] & board_arr[index]) & 0x03) == 0 && board_arr[target_square] > null_piece) {

				move_list.push_back(Move(index, target_square, board_arr[index], board_arr[target_square], false, ' ', false));

				break;

			}

			else if (board_arr[target_square] == 0) move_list.push_back(Move(index, target_square, board_arr[index], null_piece, false, ' ', false));

			else break;

			target_square += piece_offset[i];

		}


	}

}

void MoveGen::generate_pl_leaping_moves(const BoardRepresentation& board_representation, int index, const int piece_offset[], int array_size) {

	std::array<int, board_size> board_arr = board_representation.get_chess_board();
	
	int color = 1;

	if (board_arr[index] & black) color = -1;

	for (int i = 0; i < array_size; ++i) {

		int target_square = index + color * piece_offset[i];

		if (board_representation.is_on_board(target_square)) {

			if (((board_arr[target_square] & board_arr[index]) & piece_color_check) == 0 && board_arr[target_square] > 0) {

				move_list.push_back(Move(index, target_square, board_arr[index], board_arr[target_square], false, ' ', false));
			}

			else if (board_arr[target_square] == 0) move_list.push_back(Move(index, target_square, board_arr[index], null_piece, false, ' ', false));

		}

	}

}

void MoveGen::generate_legal_moves(BoardRepresentation& board_representation, int color)
	{

	legal_move_list.clear();

	int king_index;

	int color_helper = white;

	if (color == white) color_helper = black;

	for (Move& move : move_list) {

		make_move(board_representation, move);

		if (color == white) king_index = board_representation.white_king_square; else king_index = board_representation.black_king_square;

		if (move.castle != ' ') {
			make_castle(board_representation, move.castle);
		}
		
		if (!(is_attacked(board_representation, king_index, color_helper))) {
			legal_move_list.push_back(move);
		}
		
		un_make_move(board_representation, move);

	}
}

void MoveGen::generate_pl_castle_moves(const BoardRepresentation& board_representation, int index)
{
	std::array<int, board_size> board_arr = board_representation.get_chess_board();

	// WHITE CASTLING 

	if ((board_arr[index] & piece_color_check) == white) {

		// SHORT CASTLE 

		if (board_arr[index + 1] == null_piece && board_arr[index + 2] == null_piece && board_arr[index + 3] == white_rook && board_representation.get_castling_rights().find('K') != std::string::npos) {
			if (!(is_attacked(board_representation, index, black) || is_attacked(board_representation, index + 1, black) || is_attacked(board_representation, index + 2, black))) {
				move_list.push_back(Move(index, index + 2, white_king, null_piece, false, 'K', false));
			}
		}

		//LONG CASTLE
		std::string y = board_representation.get_castling_rights();
		if (board_representation.get_castling_rights().find('Q')!= std::string::npos) {
			if (board_arr[index - 1] == null_piece && board_arr[index - 2] == null_piece && board_arr[index - 3] == null_piece && board_arr[index - 4] == white_rook) {
				if (!(is_attacked(board_representation, index, black) || is_attacked(board_representation, index - 1, black) || is_attacked(board_representation, index - 2, black))) {
					move_list.push_back(Move(index, index - 2, white_king, null_piece, false, 'Q', false));
				}
			}
		}

	}

	// BLACK CASTLING 

	else {

		// SHORT CASTLE 

		if (board_arr[index + 1] == null_piece && board_arr[index + 2] == null_piece && board_arr[index + 3] == black_rook && board_representation.get_castling_rights().find('k') != std::string::npos) {
			if (!(is_attacked(board_representation, index, white) || is_attacked(board_representation, index - 1, white) || is_attacked(board_representation, index - 2, white))) {
				move_list.push_back(Move(index, index + 2, black_king, null_piece, false, 'k', false));
			}
		}

		//LONG CASTLE

		if (board_arr[index - 1] == null_piece && board_arr[index - 2] == null_piece && board_arr[index - 3] == null_piece && board_arr[index - 4] == black_rook && board_representation.get_castling_rights().find('q') != std::string::npos) {
			if (!(is_attacked(board_representation, index, white) || is_attacked(board_representation, index + 1, white) || is_attacked(board_representation, index + 2, white))) {
				move_list.push_back(Move(index, index - 2, black_king, null_piece, false, 'q', false));
			}
		}

	}

}


void MoveGen::make_move(BoardRepresentation& board_representation, Move m)
{

	if (m.enpassant == true) {
		board_representation.set_enpassant(m.end_index);
	}
	
	if (m.piece_type == white_king) {
		board_representation.white_king_square = m.end_index;
	}
	if (m.piece_type == black_king) {
		board_representation.black_king_square = m.end_index;
	}
	
	if (m.castle != ' ') {
		make_castle(board_representation, m.castle);
	}

	board_representation.remove_piece(m.start_index);
	board_representation.add_piece(m.piece_type, m.end_index);

	made_moves.push_back(m);

	board_representation.set_side(!board_representation.get_side());
}

void MoveGen::un_make_move(BoardRepresentation& board_representation, Move m)
{

	made_moves.pop_back();

	if (m.piece_type == white_king) {
		board_representation.white_king_square = m.start_index;
	}
	if (m.piece_type == black_king) {
		board_representation.black_king_square = m.start_index;
	}


	if (m.castle != ' ') {
		unmake_castle(board_representation, m);
	}

	board_representation.remove_piece(m.end_index);

	if (m.capture > 0) {
			board_representation.add_piece(m.capture, m.end_index);
	}

	board_representation.add_piece(m.piece_type, m.start_index);



	if (made_moves.size() > 0) {
		if (made_moves.back().enpassant) {
			board_representation.set_enpassant(m.end_index);
		}
	}

	board_representation.set_side(!board_representation.get_side());

}

void MoveGen::make_castle(BoardRepresentation& board_representation, char ch)
{
	std::string set_castle = board_representation.get_castling_rights();

	switch (ch) {

	case ('K'): {
		board_representation.add_piece(white_rook, f1);
		board_representation.remove_piece(h1);
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'K'), set_castle.end());
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'Q'), set_castle.end());
		break;
	}
	case ('k'): {
		board_representation.add_piece(black_rook, f8);
		board_representation.remove_piece(h8);
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'k'), set_castle.end());
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'q'), set_castle.end());
		break;
	}
	case ('Q'): {
		board_representation.add_piece(white_rook, d1);
		board_representation.remove_piece(a1);
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'K'), set_castle.end());
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'Q'), set_castle.end());
		break;
	}
	case ('q'): {
		board_representation.add_piece(black_rook, d8);
		board_representation.remove_piece(a8);
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'k'), set_castle.end());
		set_castle.erase(std::remove(set_castle.begin(), set_castle.end(), 'q'), set_castle.end());
		break;
	}

	}

	board_representation.set_castling_rights(set_castle);

}

void MoveGen::unmake_castle(BoardRepresentation& board_representation, Move m)
{

	std::string set_castle = board_representation.get_castling_rights();

	switch (m.castle) {

	case('K'): {
		board_representation.add_piece(white_rook, h1);
		board_representation.remove_piece(f1);
		set_castle.push_back('K');
		set_castle.push_back('Q');
		break;
	}
	case ('k'): {
		board_representation.add_piece(black_rook, h8);
		board_representation.remove_piece(f8);
		set_castle.push_back('k');
		set_castle.push_back('q');
		break;
	}
	case ('Q'): {
		board_representation.add_piece(white_rook, a1);
		board_representation.remove_piece(d1);
		set_castle.push_back('K');
		set_castle.push_back('Q');
		break;
	}
	case ('q'): {
		board_representation.add_piece(black_rook, a8);	
		board_representation.remove_piece(d8);
		set_castle.push_back('k');
		set_castle.push_back('q');
		break;
	}

	}

	board_representation.set_castling_rights(set_castle);
}



bool MoveGen::is_attacked(const BoardRepresentation& board_representation, int index, int color)
{

	std::array<int, board_size> board_arr = board_representation.get_chess_board();
	
	int target_square = index;



	//PAWN 
	if (color == white) {
		if (board_representation.is_on_board(index + pawn_offset[0]) && board_arr[index + pawn_offset[0]] == black_pawn) return true;
		if (board_representation.is_on_board(index + pawn_offset[2]) && board_arr[index + pawn_offset[2]] == black_pawn) return true;
	}
	else {
		if (board_representation.is_on_board(index - pawn_offset[0]) && board_arr[index - pawn_offset[0]] == white_pawn) return true;
		if (board_representation.is_on_board(index - pawn_offset[2]) && board_arr[index - pawn_offset[2]] == white_pawn) return true;
	}

	//SLIDING -- BISHOP + QUEEN

	for (int i = 0; i < sliding_array_size; ++i) {

		target_square = index;

		target_square += bishop_offset[i];

		while (board_representation.is_on_board(target_square)) {

			// if ((((board_arr[target_square] & piece_color_check) & (board_arr[index] & piece_color_check)) > 0)) break;

			if (board_arr[target_square] != null_piece) {

				if (board_arr[target_square] == neutral_bishop + color || board_arr[target_square] == neutral_queen + color) return true;

				else break;
			}

		//	if (board_arr[target_square] == neutral_bishop + color || board_arr[target_square] == neutral_queen + color) return true;

			target_square += bishop_offset[i];

		}
	}

	//LEAPING -- KNIGHT

	target_square = index;

	for (int i = 0; i < leaping_array_size; ++i) {

		target_square = index + knight_offset[i];

		if (board_representation.is_on_board(target_square)) {

			if (board_arr[target_square] == neutral_knight + color) return true; 

		}

	}

	//SLIDING -- ROOK + QUEEN

	for (int i = 0; i < sliding_array_size; ++i) {

		target_square = index;

		target_square += rook_offset[i];

		while (board_representation.is_on_board(target_square)) {

			if (board_arr[target_square] != null_piece) {

				if (board_arr[target_square] == neutral_rook + color || board_arr[target_square] == neutral_queen + color) return true;

				else break;
			}

			//if (((board_arr[target_square] & piece_color_check) & (board_arr[index] & piece_color_check)) > 0)	break;

			//if (board_arr[target_square] == (neutral_rook + color) || board_arr[target_square] == (neutral_queen + color)) {
				//std::cout << "target: " << index << std::endl;
				//return true;
			//}

			target_square += rook_offset[i];

		}
	}

	//LEAPING -- KING

	target_square = index;

	for (int i = 0; i < leaping_array_size; ++i) {

		target_square = index + king_offset[i];

		if (board_representation.is_on_board(target_square)) {

			if (board_arr[target_square] == neutral_king + color) return true;

		}

	}

	return false;

}

long MoveGen::perft(BoardRepresentation& board_representation, int depth)
{
		int nodes = 0;

	// test positions from CPW
	//"r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq -"
	//"8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - -"
	//"r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq -"
	//"r2q1rk1/pP1p2pp/Q4n2/bbp1p3/Np6/1B3NBn/pPPP1PPP/R3K2R b KQ -"
	//"rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ -"
	//"r4rk1/1pp1qppp/p1np1n2/2b1p1B1/2B1P1b1/P1NP1N2/1PP1QPPP/R4RK1 w - -"

	generate_pseudo_legal_moves(board_representation);

	if (board_representation.get_side()) {
		generate_legal_moves(board_representation, white);
		//std::cout << "white" << std::endl;
	}
	else {
		generate_legal_moves(board_representation, black);
		//std::cout << "black" << std::endl;
	}
	std::list<Move> help = legal_move_list;

	//print_move_list();


	// bulk count
	if (depth == 1) {
	//	std::cout << help.size() << std::endl;
	
		return help.size();
	}

	for (const auto& move : help) {
		if (depth == 1) {
			std::cout << for_print_movegen[move.start_index];
			std::cout << for_print_movegen[move.end_index];
		}
		//std::cout << "move start: " << move.start_index << "move end: " << move.end_index << std::endl;
		//if (move.capture > 0) std::cout << "WE GOT ONE" << std::endl;
		make_move(board_representation, move);
		nodes += perft(board_representation, depth - 1);
		un_make_move(board_representation, move);
		//std::cout << "move unmade" << std::endl;
	}

	//std::cout << "capture: " << capture_count << std::endl;
	//std::cout << "depth: " << depth << std::endl;
	return nodes;

}

inline bool MoveGen::can_capture(const BoardRepresentation& board_representation, int index, int target_square)
{
	return true;
}

void MoveGen::print_move_list()
{
	for (Move& move: legal_move_list) {
	
		std::cout << for_print_movegen[move.start_index];
		std::cout << for_print_movegen[move.end_index];
		std::cout << std::endl;
	}
}

long MoveGen::perft_divide(BoardRepresentation& board_representation, int depth, int divide)
{

	int nodes = 0;

	generate_pseudo_legal_moves(board_representation);

	if (board_representation.get_side()) {
		generate_legal_moves(board_representation, white);
	
	}
	else {
		generate_legal_moves(board_representation, black);
		
	}
	std::list<Move> help = legal_move_list;

	//print_move_list();


	// bulk count
	if (depth == 1) {
		//print_move_list();
		nodes = 0;
		return help.size();
	}

	for (const auto& move : help) {

		make_move(board_representation, move);
		nodes += perft_divide(board_representation, depth - 1, divide);
		if (depth == divide) {
			std::cout << for_print_movegen[move.start_index];
			std::cout << for_print_movegen[move.end_index];
			std::cout << " " << nodes << std::endl;
			nodes = 0;
		}
		un_make_move(board_representation, move);

	}

	return nodes;

}















