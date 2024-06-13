#include <iostream>
#include "Model/game.hpp"
#include "Model/board.hpp"
#include "View/board_ui.hpp"

int main(int argc, char* argv[]) {
    /*// USING PRINT METHOD IN BOARD
    std::cout << "board: " << std::endl;
    Board board = Board();
    board.print(std::cout);

    // USING PIECE ITERATOR
    std::cout << "\npieces: " << std::endl;
    Board::piece_iterator it = board.piece_begin();
    for(it; it != board.piece_end(); it++)
        std::cout << "piece: " << (*it).piece() << " side: " << (*it).side() << std::endl;
     
    // USING PATH ITERATOR
    coordinate start(0,4), end(8,4), dir(1,0);
    std::cout << "\npath: " << std::endl;
    try {
        Board::path_iterator pit = board.path_begin(start, end, dir);
        for(pit; pit != board.path_end(); pit++)
            std::cout << "piece: " << (*pit).piece() << " side: " << (*pit).side() << std::endl;
    }
    catch(std::exception& e) {
        std::cout << "\nErrors:\n" << e.what() << std::endl;
    }

    try {
        coordinate s2(1,1), e2(4,6), d2(1,2);
        Board::path_iterator pit2 = board.path_begin(s2,e2,d2);
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }*/

    BoardUI* UI = new BoardUI();
    Game* game = new Game(UI, UI);
    UI->addObserver(game);

    game->start();

    delete game;
    delete UI;

    return 0;
}
