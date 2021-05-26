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

    bi.board_initialization("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - ", br);

    mg.initialize_struct(br);
        
    start = std::clock();

    mg.generate_pseudo_legal_moves(br);

    mg.generate_legal_moves(br, white);


    std::vector<Move> moves = (mg.get_legal_move_list());

    for (Move& move : moves) {
        std::cout << "test array: " << br.index_convert[move.piece_type] << std::endl;
        std::cout << move.start_index << " " << move.end_index << std::endl;
        std::cout << "positions key: " << br.position_key << std::endl;
        std::cout << "hash key: " << ZobristHashing::hash_position(br) << std::endl;
        mg.make_move(br, move);
        std::cout << "positions key after move: " << br.position_key << std::endl;
        std::cout << "new hash key after move: " << ZobristHashing::hash_position(br) << std::endl;
        mg.un_make_move(br, move);
        std::cout << "positions key after un make move: " << br.position_key << std::endl;
        std::cout << "new hash key after un make move: " << ZobristHashing::hash_position(br) << std::endl;
        mg.make_nullmove(br);
        std::cout << "positions key after move: " << br.position_key << std::endl;
        std::cout << "new hash key after move: " << ZobristHashing::hash_position(br) << std::endl;
        mg.unmake_nullmove(br);
        std::cout << "positions key after un make move: " << br.position_key << std::endl;
        std::cout << "new hash key after un make move: " << ZobristHashing::hash_position(br) << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;


    }

  //  sh.sort_moves(mg.get_legal_move_list());

    

     // sh.search(br);

    //Evaluation::material_eval(br);



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
