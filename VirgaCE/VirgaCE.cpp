// VirgaCE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BoardInitialization.h"
#include "BoardRepresentation.h"
#include "MoveGen.h"

int main()
{


    std::cout << "Hello World!\n";

    BoardInitialization bi = BoardInitialization();

    BoardRepresentation br = BoardRepresentation();

    MoveGen mg = MoveGen();


    bi.board_initialization("8/8/4q3/8/4B3/4K3/8/8 w - - 0 1", br);

  //  br.print_the_board();

    std::cout << std::endl;

    mg.generate_pseudo_legal_moves(br);

    mg.generate_legal_moves(br, white);

   // Move new_move = Move(b1, c3, white_knight, false);

  // mg.make_move(br, new_move);

    std::cout << std::endl;

    mg.print_move_list();


    


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
