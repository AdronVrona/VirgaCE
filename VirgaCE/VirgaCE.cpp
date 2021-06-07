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
#include "ZobristHashing.h"
#include "Evaluation.h"

int main()
{

    std::clock_t start;



    // -------------------- FACTORY -------------------------------//




    BoardInitialization bi = BoardInitialization();

    BoardRepresentation br = BoardRepresentation();

    MoveGen mg = MoveGen();

    Search sh = Search(mg);

   // TranspositionTable tt = TranspositionTable();


   // -------------------------------------------------------------//


   // UCI uci = UCI();

  //  uci.UCI_communication();

 
    ZobristHashing::zobrist_initialization();

    bi.board_initialization("r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq - 0 1", br);

    mg.initialize_struct(br);
        
    start = std::clock();

    sh.search(br);

    //Evaluation::material_eval(br);

    std::cout << "q counter: " << sh.qcounter << std::endl;
    std::cout << "s counter: " << sh.scounter << std::endl;




  // -------------------- PERFT -------------------------------//




  // long long x = mg.perft(br, 4);

   // int x = mg.perft_divide(br, 3,3); 

    // std::cout << "nodes: " << x << std::endl;




  // ----------------------------------------------------------//





    auto duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

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
