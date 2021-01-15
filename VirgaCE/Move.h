
class Move {


	public:

		Move();

		int start_index;
		int end_index;
		int piece_type;
		int capture;
		bool enpassant;
		char castle;
		bool promotion;


		Move(int st, int en, int pt, int ca, bool enp, char cas, bool prom) {
			start_index = st;
			end_index = en;
			piece_type = pt;
			capture = ca;
			enpassant = enp;
			castle = cas;
			promotion = prom;

		}

		

};

