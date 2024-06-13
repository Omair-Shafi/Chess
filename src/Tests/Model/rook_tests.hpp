#ifndef __ROOK_TESTS_HPP
#define __ROOK_TESTS_HPP

#include "../../Model/rook.cpp"

TEST(RookTests, WhiteBlockedPath1)
{
	Board* board = new Board();
	Move* move = new Move(coordinate(7, 7), coordinate(3, 7));
	Rook r;

	EXPECT_EQ(r.isMoveValid(move, board), false);
	delete board;
	delete move;
}

TEST(RookTests, WhiteBlockedPath2)
{
	Board* board = new Board();
	Move* move = new Move(coordinate(7, 7), coordinate(7, 6));
	Rook r;

	EXPECT_EQ(r.isMoveValid(move, board), false);
	delete board;
	delete move;
}

TEST(RookTests, WhiteClearPathVertical)
{
	Board* board1 = new Board();
	Board* board2 = board1->move(coordinate(6, 0), coordinate(4, 0), 1); // move white pawn up
   	Board* board3 = board2->move(coordinate(1, 0), coordinate(3, 0), 1); // move black pawn down
	
	Move* move = new Move(coordinate(7, 0), coordinate(5, 0)); // move white rook up
	Rook r;

	EXPECT_EQ(r.isMoveValid(move, board3), true);
	delete board1;
	delete board2;
	delete board3;
	delete move;
} 

TEST(RookTests, WhiteClearPathHorizontal)
{
	Board* board1 = new Board();
	Board* board2 = board1->move(coordinate(6, 0), coordinate(4, 0), 1); // move white pawn up
	Board* board3 = board2->move(coordinate(1, 0), coordinate(3, 0), 1); // move black pawn down
	Board* board4 = board3->move(coordinate(7, 0), coordinate(5, 0), 1); // move white rook up
	Board* board5 = board4->move(coordinate(1, 1), coordinate(3, 1), 1); // move another black pawn down

	Move* move = new Move(coordinate(5, 0), coordinate(5, 2)); // move white rook to the right
	Rook r;

	EXPECT_EQ(r.isMoveValid(move, board5), true);
	delete board1;
	delete board2;
	delete board3;
	delete board4;
	delete board5;
	delete move;
}

TEST(RookTests, BlackBlockedPath1)
{
	Board* board1 = new Board();
	Board* board2 = board1->move(coordinate(6, 0), coordinate(4, 0), 1);
	
	Move* move = new Move(coordinate(0, 0), coordinate(3, 0));
	Rook r;

	EXPECT_EQ(r.isMoveValid(move, board2), false);
	delete board1;
	delete board2;
	delete move;
}

TEST(RookTests, BlackBlockedPath2)
{
	Board* board1 = new Board();
	Board* board2 = board1->move(coordinate(6, 0), coordinate(4, 0), 1);

	Move* move = new Move(coordinate(0, 0), coordinate(0, 5));
	Rook r;

	EXPECT_EQ(r.isMoveValid(move, board2), false);
	delete board1;
	delete board2;
	delete move;
}

TEST(RookTests, BlackClearPathVertical)
{
	Board* board1 = new Board();
	Board* board2 = board1->move(coordinate(6, 0), coordinate(4, 0), 1);
	Board* board3 = board2->move(coordinate(1, 0), coordinate(3, 0), 1);

	Move* move = new Move(coordinate(0, 0), coordinate(2, 0));
	Rook r;

	EXPECT_EQ(r.isMoveValid(move, board3), true);
	delete board1;
	delete board2;
	delete board3;
	delete move;
}

TEST(RookTests, BlackClearPathHorizontal)
{
	Board* board1 = new Board();
        Board* board2 = board1->move(coordinate(6, 0), coordinate(4, 0), 1);
        Board* board3 = board2->move(coordinate(1, 0), coordinate(3, 0), 1);
	Board* board4 = board3->move(coordinate(7, 0), coordinate(5, 0), 1);
	Board* board5 = board4->move(coordinate(0, 0), coordinate(2, 0), 1);
	Board* board6 = board5->move(coordinate(5, 0), coordinate(5, 2), 1);

        Move* move = new Move(coordinate(2, 0), coordinate(2, 2));
        Rook r;

        EXPECT_EQ(r.isMoveValid(move, board6), true);
        delete board1;
        delete board2;
        delete board3;
	delete board4;
	delete board5;
	delete board6;
        delete move;
}

TEST(RookTests, WhiteRookCaptureDistance1)
{
	Board* board1 = new Board();
	Board* board2 = board1->move(coordinate(6, 0), coordinate(4, 0), 1);
	Board* board3 = board2->move(coordinate(1, 0), coordinate(3, 0), 1);
	Board* board4 = board3->move(coordinate(7, 0), coordinate(5, 0), 1);
	Board* board5 = board4->move(coordinate(1, 1), coordinate(3, 1), 1);
	Board* board6 = board5->move(coordinate(5, 0), coordinate(5, 1), 1);
	Board* board7 = board6->move(coordinate(3, 1), coordinate(4, 1), 1);

	Move* move = new Move(coordinate(5, 1), coordinate(4, 1));
	Rook r;

	EXPECT_EQ(r.isMoveValid(move, board7), true);
	delete board1;
	delete board2;
	delete board3;
	delete board4;
	delete board5;
	delete board6;
	delete board7;
	delete move;
}

TEST(RookTests, WhiteRookCaptureDistanceGreaterThan1)
{
	Board* board1 = new Board();
        Board* board2 = board1->move(coordinate(6, 0), coordinate(4, 0), 1);
        Board* board3 = board2->move(coordinate(1, 0), coordinate(3, 0), 1);
        Board* board4 = board3->move(coordinate(7, 0), coordinate(5, 0), 1);
        Board* board5 = board4->move(coordinate(1, 1), coordinate(3, 1), 1);
        Board* board6 = board5->move(coordinate(5, 0), coordinate(5, 1), 1);
        Board* board7 = board6->move(coordinate(1, 7), coordinate(3, 7), 1);

        Move* move = new Move(coordinate(5, 1), coordinate(3, 1));
        Rook r;

        EXPECT_EQ(r.isMoveValid(move, board7), true);
        delete board1;
        delete board2;
        delete board3;
        delete board4;
        delete board5;
        delete board6;
        delete board7;
        delete move;	
}

TEST(RookTests, WhiteRookCaptureWhite)
{
	Board* board1 = new Board();
        Board* board2 = board1->move(coordinate(6, 0), coordinate(4, 0), 1);
        Board* board3 = board2->move(coordinate(1, 0), coordinate(3, 0), 1);

        Move* move = new Move(coordinate(7, 0), coordinate(4, 0));
        Rook r;

        EXPECT_EQ(r.isMoveValid(move, board3), false);
	delete board1;
	delete board2;
	delete board3;
	delete move;
}
#endif
