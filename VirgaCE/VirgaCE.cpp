// VirgaCE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>
#include <ctime>
#include "BoardInitialization.h"
#include "BoardRepresentation.h"
#include "MoveGen.h"
#include "Search.h"
#include "UCI.h"
#include "TranspositionTable.h"

int main()
{

    std::clock_t start;
    double duration;



    // -------------------- FACTORY -------------------------------//




    BoardInitialization bi = BoardInitialization();

    BoardRepresentation br = BoardRepresentation();

    MoveGen mg = MoveGen();

    TranspositionTable tt = TranspositionTable();

    Search sh = Search(mg);


    // -------------------------------------------------------------//


   // UCI uci = UCI();

  //  uci.UCI_communication();

        // -------------------- FACTORY -------------------------------//


    bi.board_initialization("3rr3/8/k7/8/8/K2R4/4R2b/8 w - - 0 1", br);

   mg.initialize_struct(br);

    //tt.zobrist_initialization();

   // tt.hash_position(br);

//    br.print_piece_lists();
        
    start = std::clock();

    //mg.generate_pseudo_legal_moves(br);

    //mg.generate_legal_moves(br, white);

  //  sh.sort_moves(mg.get_legal_move_list());

    sh.search(br);



  // -------------------- PERFT -------------------------------//




  // long long x = mg.perft(br, 4);

   // int x = mg.perft_divide(br, 3,3); 

    // std::cout << "nodes: " << x << std::endl;




  // ----------------------------------------------------------//





    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

    std::cout << "duration: " << duration;
     


    


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
