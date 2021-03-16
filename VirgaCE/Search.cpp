#include "Search.h"
#include "Evaluation.h"

Search::Search(MoveGen& mg)
	:move_generator(mg), best_move(13, 13, null_piece, 0, false, ' ', 0)
{
	root = 0;
}


void Search::search(BoardRepresentation& board_representation)
{


	// ITERATIVE DEEPENING

	for (int depth = 1; depth < 4; ++depth) {

		std::cout << std::endl;
		std::cout << "depth: " << depth << std::endl;
		std::cout << std::endl;

		minimax(board_representation, depth, depth, white, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

	}

	std::cout << std::endl;

	for (int i = 0; i < 10; ++i) {
		std::cout << "var: " << principal_variation[i] << std::endl;
		std::cout << "end: " << end_index[i] << std::endl;
	}

}

double Search::minimax(BoardRepresentation& board_representation, int depth, int root_depth, bool side, double alpha, double beta)
{

	if (depth == 0) return Evaluation::material_eval(board_representation);

	if (side) {

		double max_eval = std::numeric_limits<int>::min(); 

		move_generator.generate_pseudo_legal_moves(board_representation);

		move_generator.generate_legal_moves(board_representation, white);

		for (Move& move : move_generator.get_legal_move_list()) {

			move_generator.make_move(board_representation, move);

			double eval = minimax(board_representation, depth - 1, root_depth, false, alpha, beta);

			//if (eval > max_eval) {
			//}

			max_eval = std::max(max_eval, eval);

			if (eval > alpha) {
				alpha = eval;
				std::cout << "alpha: " << move.start_index << " " << move.end_index << std::endl;
				principal_variation[depth] = move.start_index;
				end_index[depth] = move.end_index;
			}
			//alpha = std::max(alpha, eval);

			move_generator.un_make_move(board_representation, move);

			if (beta <= alpha) break;

		}

		return max_eval;

	}

	else {

		double min_eval = std::numeric_limits<int>::max();

		move_generator.generate_pseudo_legal_moves(board_representation);

		move_generator.generate_legal_moves(board_representation, black);

		for (Move& move : move_generator.get_move_list()) {

			move_generator.make_move(board_representation, move);

			double eval = minimax(board_representation, depth - 1, root_depth, true, alpha, beta);

		/*	if (eval < min_eval) {

			}*/

			min_eval = std::min(min_eval, eval);

			//beta = std::min(beta, eval);

			if (eval < beta) {
				beta = eval;
				std::cout  << "beta: " << move.start_index << " " << move.end_index << std::endl;
				principal_variation[depth] = move.start_index;
				end_index[depth] = move.end_index;
			}

			move_generator.un_make_move(board_representation, move);

			if (beta <= alpha) break;

		}

		return min_eval;
	}

}

double Search::quiescence(BoardRepresentation& board_representation, double alpha, double beta)
{
	double stand_pat = Evaluation::material_eval(board_representation);

	if (stand_pat > beta) return beta;

	if (stand_pat > alpha) alpha = stand_pat;


}

std::vector<Move> Search::sort_moves(std::vector<Move> moves)
{
	//std::stable_sort(moves.begin(), moves.end(), &Move::LVA_MVV);

	//return moves;

	std::sort(std::begin(moves), std::end(moves), [](const Move& a, const Move& b) {
		return a.piece_type < b.piece_type || (a.piece_type == b.piece_type && a.capture < b.capture);
		});

	return moves;
}
