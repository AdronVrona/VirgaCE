#include "UCI.h"


void UCI::UCI_communication()
{
	std::string uci_line;

	while (true) {

		while (getline(std::cin, uci_line)) {

			if (uci_line == "uci") {
				std::cout << "id name VirgaCE" << std::endl;
				std::cout << "id author AdronVrona" << std::endl;
				std::cout << "uciok" << std::endl;
			}
			else if (uci_line == "quit") {
				std::cout << "Bye Bye" << std::endl;
				break;
			}
			else if (uci_line == "isready") {
				std::cout << "readyok" << std::endl;
			}
			else if (uci_line == "ucinewgame") {
				std::cout << "readyok" << std::endl;
			}

		}
	}
}
