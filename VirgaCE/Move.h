
#ifndef MOVE_CLASS 
#define MOVE_CLASS

class Move {


	public:

		bool LVA_MVV(const Move& first, const Move& second) {

			if (first.piece_type < second.piece_type) return true;
			if (second.piece_type < first.piece_type) return false;

			if (second.capture < first.capture) return true;
			if (first.capture < second.capture) return false;

			return false;

		}

		Move();

		int start_index;
		int end_index;
		int piece_type;
		int capture;
		bool enpassant;
		char castle;
		int promotion;


		Move(int st, int en, int pt, int ca, bool enp, char cas, int prom) {
			start_index = st;
			end_index = en;
			piece_type = pt;
			capture = ca;
			enpassant = enp;
			castle = cas;
			promotion = prom;

		}

		

};

#endif