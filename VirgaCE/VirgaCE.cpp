// VirgaCE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>
#include <ctime>
#include "BoardInitialization.h"
#include "BoardRepresentation.h"
#include "MoveGen.h"

int main()
{


    std::clock_t start;
    double duration;

    BoardInitialization bi = BoardInitialization();

    BoardRepresentation br = BoardRepresentation();

    MoveGen mg = MoveGen();


    bi.board_initialization("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", br);

  //  br.print_the_board();

    //std::cout << std::endl;

    start = std::clock();

    int x = mg.perft(br, 4);

    //int x = mg.perft_divide(br, 5, 5);

    std::cout << "nodes: " << x << std::endl;

    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

    std::cout << "duration: " << duration;
     
  //  Move new_move = Move(1, 34, white_knight, null_piece, false, ' ', false);

   // mg.make_move(br, new_move);

   // Move new_movee = Move(3, 4, white_king, null_piece, false, ' ', false);

//    mg.make_move(br, new_movee);


   // std::map<int, int> usable_piece_list = br.get_piece_list();

   // std::cout << std::endl;

   // mg.print_move_list();


    


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
