#ifndef __KING_TESTS_HPP__
#define __KING_TESTS_HPP__

#include "../../Model/king.cpp"

TEST(KingTests, WhiteBlockedPath1)
{
	Board* board = new Board();
	Move* move = new Move(coordinate(7, 4), coordinate(6, 4));
	King k;

	EXPECT_EQ(k.isMoveValid(move, board), false);
	delete board;
	delete move;
}

TEST(KingTests, WhiteBlockedPath2)
{
	Board* board = new Board();
	Move* move = new Move(coordinate(7, 4), coordinate(7, 3));
	King k;

	EXPECT_EQ(k.isMoveValid(move, board), false);
	delete board;
	delete move;
}

TEST(KingTests, WhiteBlockedPath3)
{
	Board* board = new Board();
	Move* move = new Move(coordinate(7, 4), coordinate(6, 5));
	King k;
	
	EXPECT_EQ(k.isMoveValid(move, board), false);
	delete board;
	delete move;
}

TEST(KingTests, WhiteClearPathVertical)
{
	Board* board1 = new Board();
	Board* board2 = board1->move(coordinate(6, 4), coordinate(4, 4), 1); // move white pawn up
   	Board* board3 = board2->move(coordinate(1, 4), coordinate(3, 4), 1); // move black pawn down
	
	Move* move = new Move(coordinate(7, 4), coordinate(6, 4)); // move white king sideways
	King k;

	EXPECT_EQ(k.isMoveValid(move, board3), true);
	delete board1;
	delete board2;
	delete board3;
	delete move;
} 

TEST(KingTests, WhiteClearPathHorizontal)
{
	Board* board1 = new Board();
	Board* board2 = board1->move(coordinate(6, 4), coordinate(4, 4), 1); // move white pawn up
	Board* board3 = board2->move(coordinate(1, 4), coordinate(3, 4), 1); // move black pawn down
	Board* board4 = board3->move(coordinate(7, 4), coordinate(6, 4), 1); // move white king up
	Board* board5 = board4->move(coordinate(1, 3), coordinate(3, 3), 1); // move another black pawn down
	Board* board6 = board5->move(coordinate(6, 4), coordinate(5, 4), 1); // move white king up again
	Board* board7 = board6->move(coordinate(1, 5), coordinate(3, 5), 1); // move another black pawn down

	Move* move = new Move(coordinate(5, 4), coordinate(5, 5)); // move white king to the right
	King k;

	EXPECT_EQ(k.isMoveValid(move, board7), true);
	delete board1;
	delete board2;
	delete board3;
	delete board4;
	delete board5;
	delete board6;
	delete board7;
	delete move;
}

TEST(KingTests, WhiteClearPathDiagonal)
{
        Board* board1 = new Board();
        Board* board2 = board1->move(coordinate(6, 4), coordinate(4, 4), 1); // move white pawn up
        Board* board3 = board2->move(coordinate(1, 0), coordinate(3, 0), 1); // move black pawn down
        Board* board4 = board3->move(coordinate(7, 4), coordinate(6, 4), 1); // move white king up
        Board* board5 = board4->move(coordinate(1, 1), coordinate(3, 1), 1); // move another black pawn down
        Board* board6 = board5->move(coordinate(6, 4), coordinate(5, 4), 1); // move white king up again
        Board* board7 = board6->move(coordinate(1, 7), coordinate(3, 7), 1); // move another black pawn down

        Move* move = new Move(coordinate(5, 4), coordinate(4, 5)); // move white king top-right
        King k;

        EXPECT_EQ(k.isMoveValid(move, board7), true);
        delete board1;
        delete board2;
        delete board3;
        delete board4;
        delete board5;
        delete board6;
        delete board7;
        delete move;
}


TEST(KingTests, WhiteKingCaptureBlack)
{
        Board* board1 = new Board();
        Board* board2 = board1->move(coordinate(6, 4), coordinate(4, 4), 1); // move white pawn up
        Board* board3 = board2->move(coordinate(1, 0), coordinate(3, 0), 1); // move black pawn down
        Board* board4 = board3->move(coordinate(7, 4), coordinate(6, 4), 1); // move white king up
        Board* board5 = board4->move(coordinate(1, 1), coordinate(3, 1), 1); // move another black pawn down
        Board* board6 = board5->move(coordinate(6, 4), coordinate(5, 4), 1); // move white king up again
        Board* board7 = board6->move(coordinate(1, 7), coordinate(3, 7), 1); // move another black pawn down
	Board* board8 = board7->move(coordinate(5, 4), coordinate(4, 3), 1); // move white king top-left
	Board* board9 = board8->move(coordinate(1, 6), coordinate(3, 6), 1); // move another black pawn down
	Board* board10 = board9->move(coordinate(4, 3), coordinate(3, 2), 1); // move white king top-left
	Board* board11 = board10->move(coordinate(1, 5), coordinate(3, 5), 1); // move another black pawn down

        Move* move = new Move(coordinate(3, 2), coordinate(3, 1)); // white king captures pawn
        King k;

        EXPECT_EQ(k.isMoveValid(move, board11), true);
        delete board1;
        delete board2;
        delete board3;
        delete board4;
        delete board5;
        delete board6;
        delete board7;
	delete board8;
	delete board9;
	delete board10;
	delete board11;
        delete move;
}
 
TEST(KingTests, WhiteKingCaptureWhite)
{
        Board* board1 = new Board();
        Board* board2 = board1->move(coordinate(6, 4), coordinate(4, 4), 1); // move white pawn up
        Board* board3 = board2->move(coordinate(1, 0), coordinate(3, 0), 1); // move black pawn down
        Board* board4 = board3->move(coordinate(7, 4), coordinate(6, 4), 1); // move white king up
        Board* board5 = board4->move(coordinate(1, 1), coordinate(3, 1), 1); // move another black pawn down
        Board* board6 = board5->move(coordinate(6, 4), coordinate(5, 4), 1); // move white king up again
        Board* board7 = board6->move(coordinate(1, 7), coordinate(3, 7), 1); // move another black pawn down

        Move* move = new Move(coordinate(5, 4), coordinate(4, 4)); // white king captures white pawn
        King k;

        EXPECT_EQ(k.isMoveValid(move, board7), false);
        delete board1;
        delete board2;
        delete board3;
        delete board4;
        delete board5;
        delete board6;
        delete board7;
        delete move;
}	

#endif
