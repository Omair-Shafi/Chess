#ifndef __QUEEN_TESTS_HPP__
#define __QUEEN_TESTS_HPP__

#include "../../Model/queen.cpp"

TEST(QueenTests, WhiteBlockedPath1)
{
	Board* board = new Board();
	Move* move = new Move(coordinate(7, 3), coordinate(2, 3));
	Queen q;

	EXPECT_EQ(q.isMoveValid(move, board), false);
	delete board;
	delete move;
}

TEST(QueenTests, WhiteBlockedPath2)
{
	Board* board = new Board();
	Move* move = new Move(coordinate(7, 3), coordinate(7, 6));
	Queen q;

	EXPECT_EQ(q.isMoveValid(move, board), false);
	delete board;
	delete move;
}

TEST(QueenTests, WhiteBlockedPath3)
{
	Board* board = new Board();
	Move* move = new Move(coordinate(7, 3), coordinate(4, 0));
	Queen q;
	
	EXPECT_EQ(q.isMoveValid(move, board), false);
	delete board;
	delete move;
}

TEST(QueenTests, WhiteClearPathVertical)
{
	Board* board1 = new Board();
	Board* board2 = board1->move(coordinate(6, 3), coordinate(4, 3), 1); // move white pawn up
   	Board* board3 = board2->move(coordinate(1, 3), coordinate(3, 3), 1); // move black pawn down
	
	Move* move = new Move(coordinate(7, 3), coordinate(5, 3)); // move white queen up
	Queen q;

	EXPECT_EQ(q.isMoveValid(move, board3), true);
	delete board1;
	delete board2;
	delete board3;
	delete move;
} 

TEST(QueenTests, WhiteClearPathHorizontal)
{
	Board* board1 = new Board();
	Board* board2 = board1->move(coordinate(6, 3), coordinate(4, 3), 1); // move white pawn up
	Board* board3 = board2->move(coordinate(1, 3), coordinate(3, 3), 1); // move black pawn down
	Board* board4 = board3->move(coordinate(7, 3), coordinate(5, 3), 1); // move white queen up
	Board* board5 = board4->move(coordinate(1, 1), coordinate(3, 1), 1); // move another black pawn down

	Move* move = new Move(coordinate(5, 3), coordinate(5, 0)); // move white queen to the left
	Queen q;

	EXPECT_EQ(q.isMoveValid(move, board5), true);
	delete board1;
	delete board2;
	delete board3;
	delete board4;
	delete board5;
	delete move;
}

TEST(QueenTests, WhiteClearPathDiagonal1)
{
        Board* board1 = new Board();
        Board* board2 = board1->move(coordinate(6, 3), coordinate(4, 3), 1); // move white pawn up
        Board* board3 = board2->move(coordinate(1, 3), coordinate(3, 3), 1); // move black pawn down
        Board* board4 = board3->move(coordinate(7, 3), coordinate(5, 3), 1); // move white queen up
        Board* board5 = board4->move(coordinate(1, 1), coordinate(3, 1), 1); // move another black pawn down

        Move* move = new Move(coordinate(5, 3), coordinate(2, 6)); // move white queen top-right diagonally
        Queen q;

        EXPECT_EQ(q.isMoveValid(move, board5), true);
        delete board1;
        delete board2;
        delete board3;
        delete board4;
        delete board5;
        delete move;
}

TEST(QueenTests, WhiteClearPathDiagonal2)
{
        Board* board1 = new Board();
        Board* board2 = board1->move(coordinate(6, 3), coordinate(4, 3), 1); // move white pawn up
        Board* board3 = board2->move(coordinate(1, 3), coordinate(3, 3), 1); // move black pawn down
        Board* board4 = board3->move(coordinate(7, 3), coordinate(5, 3), 1); // move white queen up
        Board* board5 = board4->move(coordinate(1, 1), coordinate(3, 1), 1); // move another black pawn down

        Move* move = new Move(coordinate(5, 3), coordinate(4, 2)); // move white queen top-left diagonally
        Queen q;

        EXPECT_EQ(q.isMoveValid(move, board5), true);
        delete board1;
        delete board2;
        delete board3;
        delete board4;
        delete board5;
        delete move;
}

TEST(QueenTests, WhiteQueenCaptureDistance1)
{
	Board* board1 = new Board();
	Board* board2 = board1->move(coordinate(6, 3), coordinate(4, 3), 1);
	Board* board3 = board2->move(coordinate(1, 3), coordinate(3, 3), 1);
	Board* board4 = board3->move(coordinate(7, 3), coordinate(5, 3), 1);
	Board* board5 = board4->move(coordinate(1, 2), coordinate(3, 2), 1);
	Board* board6 = board5->move(coordinate(5, 3), coordinate(5, 2), 1);
	Board* board7 = board6->move(coordinate(1, 7), coordinate(3, 7), 1);

	Move* move = new Move(coordinate(5, 2), coordinate(3, 2));
	Queen q;

	EXPECT_EQ(q.isMoveValid(move, board7), true);
	delete board1;
	delete board2;
	delete board3;
	delete board4;
	delete board5;
	delete board6;
	delete board7;
	delete move;
}

TEST(QueenTests, WhiteQueenCaptureDistanceGreaterThan1Diagonal)
{
        Board* board1 = new Board();
        Board* board2 = board1->move(coordinate(6, 3), coordinate(4, 3), 1);
        Board* board3 = board2->move(coordinate(1, 3), coordinate(3, 3), 1);
        Board* board4 = board3->move(coordinate(7, 3), coordinate(5, 3), 1);
        Board* board5 = board4->move(coordinate(1, 2), coordinate(3, 2), 1);
        Board* board6 = board5->move(coordinate(5, 3), coordinate(5, 5), 1);
        Board* board7 = board6->move(coordinate(1, 7), coordinate(3, 7), 1);

        Move* move = new Move(coordinate(5, 5), coordinate(3, 3));
        Queen q;

        EXPECT_EQ(q.isMoveValid(move, board7), true);
        delete board1;
        delete board2;
        delete board3;
        delete board4;
        delete board5;
        delete board6;
        delete board7;
        delete move;
}

TEST(QueenTests, WhiteQueenCaptureWhite)
{
	Board* board1 = new Board();
	Board* board2 = board1->move(coordinate(6, 3), coordinate(4, 3), 1);
	Board* board3 = board2->move(coordinate(1, 3), coordinate(3, 3), 1);

	Move* move = new Move(coordinate(7, 3), coordinate(4, 3));
	Queen q;

	EXPECT_EQ(q.isMoveValid(move, board3), false);
	delete board1;
	delete board2;
	delete board3;
	delete move;
}

#endif
