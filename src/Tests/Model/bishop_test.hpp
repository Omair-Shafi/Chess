#include "../../Model/bishop.hpp"

TEST(BishopTests,WhiteMoveMid) {
        Board* b = Board().move(coordinate(7,2), coordinate(4,5),2 );
        Move* m1 = new Move(coordinate(4,5), coordinate(2,3));
        Bishop test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m1,b),true);
        delete b;
        delete m1;
}

TEST(BishopTests,WhiteMoveMidWrong) {
        Board* b = new Board();
        Move* m1 = new Move(coordinate(7,5), coordinate(6,5));
        Bishop test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m1,b),false);
        delete b;
        delete m1;
}

TEST(BishopTests,WhiteMoveMid2) {
        Board* b = new Board();
        Move* m1 = new Move(coordinate(3,5), coordinate(1,3));
        Bishop test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m1,b),true);
        delete b;
        delete m1;
}

TEST(BishopTests, WhiteBishopCapture){
	Board* board1 = Board().move(coordinate(1, 3), coordinate(3, 1), 1);
	Board* board3 = board1->move(coordinate(2, 4), coordinate(5, 1), 1);

	Move* move = new Move(coordinate(2, 4), coordinate(6, 0));
	Bishop b;

	EXPECT_EQ(b.isMoveValid(move, board3), true);
	delete board1;
	delete board3;
	delete move;
}

TEST(BishopTests, WhiteBishopCaptureFriendlyPiece){
        Board* board1 =  Board().move(coordinate(5, 5), coordinate(1, 3), 1);
        Board* board2 = board1->move(coordinate(5, 5), coordinate(7, 5), 1);

        Move* move = new Move(coordinate(5, 7), coordinate(4, 6));
        Bishop b;

        EXPECT_EQ(b.isMoveValid(move, board2), false);
        delete board1;
        delete board2;
        delete move;
}
