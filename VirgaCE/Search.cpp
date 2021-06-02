#include "Search.h"
#include "Evaluation.h"

Search::Search(MoveGen& mg)
	:move_generator(mg), best_move(13, 13, null_piece, 0, false, ' ', 0, 0)
{
	root = 0;
}

double Search::alphaBeta(BoardRepresentation& board_representation, int depth, int root_distance, double alpha, double beta)
{

	//std::cout << "depth: " << depth << std::endl;

	//if (depth == 0) return Evaluation::material_eval(board_representation);

	//CHECK FOR DRAWS

	if (board_representation.dead_position() || is_threefold(board_representation) || board_representation.get_halfmove() > 100)  return VALUE_DRAW;

	if (depth == 0) return quiescence(board_representation, alpha, beta);

	//CHECK TRANSPOSITION TABLE

	//auto tt_entry = hash_tt->get(board_representation.position_key);


	//MATE DISTANCE PRUNING

	alpha = std::max(mated_score(board_representation, root_distance), alpha) - 1;
	beta = std::min(mate_score(board_representation, root_distance), beta) + 1;

	if (alpha >= beta) return alpha; 

	//NULL MOVE PRUNING

	double static_eval = Evaluation::material_eval(board_representation);

	int R = 3;

	if (allowed_null(board_representation, alpha, beta) && static_eval > beta && depth > (R + 1)) {

		move_generator.make_nullmove(board_representation);

		double eval = -alphaBeta(board_representation, depth - R - 1, root_distance + 1, -beta, -alpha);

		move_generator.unmake_nullmove(board_representation);

		if (eval >= beta) return beta;
	}
	
	// -------------------------------------------------------------//

	double max_eval = std::numeric_limits<int>::min();

	move_generator.generate_pseudo_legal_moves(board_representation); 

	if (board_representation.get_side()) move_generator.generate_legal_moves(board_representation, white);

	else move_generator.generate_legal_moves(board_representation, black);

	std::vector<Move> moves = test_sort(board_representation, move_generator.get_legal_move_list());

	//std::vector<Move> moves = sort_moves(move_generator.get_legal_move_list());

	double b = beta;
	unsigned int move_count = 0;

	for (const auto& move : moves) {

		move_generator.make_move(board_representation, move);

		double eval = -alphaBeta(board_representation, depth - 1, root_distance + 1, -b, -alpha);

		max_eval = std::max(max_eval, eval);

		move_generator.un_make_move(board_representation, move);

		alpha = std::max(alpha, eval);

		if (eval > alpha) {
			alpha = eval;

			if (beta > eval) {
				hash_tt->put(ZobristHashing::hash_position(board_representation), move, depth, eval, PV_NODE);
				//hash_tt->put(board_representation.position_key, move, depth, eval, PV_NODE);
				//std::cout << "alpha: " << move.start_index << " " << move.end_index << std::endl;
			}

		}
		if (alpha >= beta) return alpha;

	}

	//CHECKMATE OR STALEMATE
	if (moves.size() == 0) {
		max_eval = mated_score(board_representation, depth);
	}


	return max_eval;
}


void Search::search_init()
{
	hash_tt = new TranspositionTable(64);
}

void Search::search(BoardRepresentation& board_representation)
{

	double eval;

	search_init();

	//std::cout << ZobristHashing::hash_position(board_representation);

	// ITERATIVE DEEPENING

	for (int depth = 1; depth < 6; ++depth) {

		//std::cout << std::endl;
		//std::cout << "depth: " << depth << std::endl;
		//std::cout << std::endl;

	eval = NegaScout(board_representation, depth, 0, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

	}

	std::cout << std::endl;

	pv = hash_tt->extract_pv(board_representation);

}


double Search::quiescence(BoardRepresentation& board_representation, double alpha, double beta)
{
	double stand_pat = Evaluation::material_eval(board_representation);

	if (stand_pat >= beta) return beta;

	if (stand_pat > alpha) alpha = stand_pat;

	move_generator.generate_pseudo_legal_moves(board_representation);

	if (board_representation.get_side()) move_generator.generate_legal_moves(board_representation, white);

	else move_generator.generate_legal_moves(board_representation, black);

	std::vector<Move> moves = quiesence_sort(move_generator.get_legal_move_list());

	for (const auto& move : moves) {

		move_generator.make_move(board_representation, move);

		double eval = -quiescence(board_representation, -beta, -alpha);

		move_generator.un_make_move(board_representation, move);

		if (eval >= beta) {
			return beta;
		}

		if (eval > alpha) {
			alpha = eval;
		}

	}

	return alpha;

}



std::vector<Move> Search::sort_moves(std::vector<Move> moves)
{
	//MVV - LVA

	std::sort(std::begin(moves), std::end(moves), [](const Move& a, const Move& b) {
		return a.capture > b.capture || (a.capture == b.capture && a.piece_type < b.piece_type);
		});

	return moves;
}

std::vector<Move> Search::quiesence_sort(std::vector<Move>& moves)
{


	/*moves.erase(
		std::remove_if(moves.begin(), moves.end(),
			[&](Move m)-> bool { return m.promotion > 0 || m.capture > 0; }),
		moves.end());

	std::sort(std::begin(moves), std::end(moves), [](const Move& a, const Move& b) {
		return a.capture > b.capture || (a.capture == b.capture && a.piece_type < b.piece_type);
		});

	std::stable_partition(std::begin(moves),
		std::end(moves),
		[](const Move& m) { return m.promotion > 0; }
	);*/

	moves.erase(std::remove_if(moves.begin(), moves.end(), [](const Move& m) {return m.capture == 0;}), moves.end());

	std::sort(std::begin(moves), std::end(moves), [](const Move& a, const Move& b) {
		return a.capture > b.capture || (a.capture == b.capture && a.piece_type < b.piece_type);
		});


	return moves;

}

double Search::NegaScout(BoardRepresentation& board_representation, int depth, int root_distance, double alpha, double beta)
{

	//std::cout << "depth: " << depth << std::endl;

	//if (depth == 0) return Evaluation::material_eval(board_representation);

	//CHECK FOR DRAWS

	if (board_representation.dead_position() || is_threefold(board_representation) || board_representation.get_halfmove() > 100)  return VALUE_DRAW;

	if (depth == 0) return quiescence(board_representation, alpha, beta);

	double curr_score = std::numeric_limits<int>::min();
	int x = 3;


	//CHECK TRANSPOSITION TABLE

	//auto tt_entry = hash_tt->get(board_representation.position_key);


	//MATE DISTANCE PRUNING

	alpha = std::max(mated_score(board_representation, root_distance), alpha) - 1;
	beta = std::min(mate_score(board_representation, root_distance), beta) + 1;

	if (alpha >= beta) return alpha;

	//NULL MOVE PRUNING

	double static_eval = Evaluation::material_eval(board_representation);

	int R = 3;

	if (allowed_null(board_representation, alpha, beta) && static_eval > beta && depth > (R + 1)) {

		move_generator.make_nullmove(board_representation);

		double eval = -NegaScout(board_representation, depth - R - 1, root_distance + 1, -beta, -alpha);

		move_generator.unmake_nullmove(board_representation);

		if (eval >= beta) return beta;
	}

	// -------------------------------------------------------------//

	double max_eval = std::numeric_limits<int>::min();

	move_generator.generate_pseudo_legal_moves(board_representation);

	if (board_representation.get_side()) move_generator.generate_legal_moves(board_representation, white);

	else move_generator.generate_legal_moves(board_representation, black);

	std::vector<Move> moves = test_sort(board_representation, move_generator.get_legal_move_list());

	//std::vector<Move> moves = sort_moves(move_generator.get_legal_move_list());

	double b = beta;
	unsigned int move_count = 0;

	for (const auto& move : moves) {

		move_generator.make_move(board_representation, move);

		double eval = -NegaScout(board_representation, depth - 1, root_distance + 1, -b, -alpha);

		if ((eval > alpha) && (eval < beta) && (move_count > 1)) {
			eval = -NegaScout(board_representation, depth - 1, root_distance + 1, -beta, -alpha);
		}

		move_generator.un_make_move(board_representation, move);

		if (eval > alpha) {

			alpha = eval;

			hash_tt->put(ZobristHashing::hash_position(board_representation), move, depth, eval, PV_NODE);
		}

		if (eval > curr_score) {
			curr_score = eval;
			best_move = move;
		}

		if (alpha >= beta) {
			return alpha;
		}

		b = alpha + 1;
		++move_count;

	}

	//CHECKMATE OR STALEMATE
	if (moves.size() == 0) {
		return mated_score(board_representation, depth);
	}


	return alpha;
}

std::vector<Move> Search::test_sort(const BoardRepresentation& board_representation, std::vector<Move>& moves) {

	Move hash_move = hash_tt->get(ZobristHashing::hash_position(board_representation)).move;
	//Move hash_move = hash_tt->get(board_representation.position_key).move;

	for (auto& move : moves) {

		if (move.move_toInt() == hash_move.move_toInt()) move.score = HASH_MOVE;

		else if (move.promotion > 0) move.score = PROMOTION_SCORE + move.promotion;

		else move.score = 10 * move.capture - move.piece_type;

	}

	std::sort(std::begin(moves), std::end(moves), [](const Move& a, const Move& b) {
		return a.score > b.score;
		});

	return moves;
}

bool Search::allowed_null(BoardRepresentation& board_representation, double alpha, double beta) {

	int index;
	int attacking_color;

	if (board_representation.get_side()) {
		index = board_representation.white_king_square;
		attacking_color = black;
	}

	else {
		index = board_representation.black_king_square;
		attacking_color = white;
	}

	return (!(beta - alpha > 1) && !move_generator.is_attacked(board_representation, index, attacking_color));


}

double Search::mated_score(BoardRepresentation& board_representation, int remaining_depth)
{
	return VALUE_MATED + remaining_depth;

}

double Search::check_or_stale(BoardRepresentation& board_representation, int remaining_depth)
{
	//CHECKMATE
	if (in_check(board_representation)) return mated_score(board_representation, remaining_depth);

	//STALEMATE
	else return VALUE_DRAW;
}

double Search::mate_score(BoardRepresentation& board_representation, int remaining_depth)
{
	return VALUE_MATE - remaining_depth;
}

bool Search::is_threefold(const BoardRepresentation& board_representation)
{

	int repitition = 0;

	if (board_representation.get_halfmove() < 4) return false;

	auto zobrist = board_representation.position_key;

	for (int i = move_generator.get_main_info().size() - 2; i >= 0; i = i - 2) {

		if (move_generator.get_main_info()[i].last_key == zobrist) {
			++repitition;
		}	

		if (repitition == 2) return true;
	}

	return false;
}


bool Search::in_check(BoardRepresentation& board_representation) {

	if (board_representation.get_side()) return move_generator.is_attacked(board_representation, board_representation.white_king_square, black);

	else return move_generator.is_attacked(board_representation, board_representation.black_king_square, white);

}