#include "../../Model/knight.hpp"

TEST(KnightTests,WhiteMove) {
        Board* b = Board().move(coordinate(6,7), coordinate(5,5),2 );
        Move* m1 = new Move(coordinate(5,5), coordinate(6,3));
        Knight test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m1,b),false);
        delete b;
        delete m1;
}

TEST(KnightTests,WhiteMoveInvalid) {
        Board* b = new Board();
        Move* m1 = new Move(coordinate(1,7), coordinate(1,5));
        Knight test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m1,b),false);
        delete b;
        delete m1;
}

TEST(KnightTests,WhiteMoveMidInvalid) {
        Board* b = new Board();
        Move* m1 = new Move(coordinate(2,5), coordinate(4,4));
        Knight test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m1,b),false);
        delete b;
        delete m1;
}

TEST(KnightTests, WhiteKnightCapture){
        Board* board1 = Board().move(coordinate(5, 5), coordinate(4, 3), 1);
        Board* board3 = board1->move(coordinate(4, 3), coordinate(3, 1), 1);

        Move* move = new Move(coordinate(4, 3), coordinate(3, 1));
        Knight k;

        EXPECT_EQ(k.isMoveValid(move, board3), false);
        delete board1;
        delete board3;
        delete move;
}

TEST(KnightTests, WhiteKnightCaptureFriendlyPiece){
        Board* board1 =  Board().move(coordinate(1, 3), coordinate(3, 1), 1);
        Board* board2 = board1->move(coordinate(6, 7), coordinate(4, 6), 1);

        Move* move = new Move(coordinate(6, 7), coordinate(4, 6));
        Knight k;

        EXPECT_EQ(k.isMoveValid(move, board2), false);
        delete board1;
        delete board2;
        delete move;
}
