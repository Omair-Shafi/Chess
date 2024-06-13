#ifndef __PAWN_TEST_HPP__
#define __PAWN_TEST_HPP__

#include "../../Model/pawn.hpp"

TEST(PawnTests,WhiteMove1Empty) {
	Board* b = new Board();
	Move* m1 = new Move(coordinate(6,1), coordinate(5,1));
	Pawn test_piece;
	
	EXPECT_EQ(test_piece.isMoveValid(m1,b),true);
	delete b;
        delete m1;
}

TEST(PawnTests,WhiteMove1WrongDirection) {
        Board* b = new Board();
        Move* m1 = new Move(coordinate(1,1), coordinate(2,1));
        Pawn test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m1,b),false);
        delete b;
        delete m1;
}

TEST(PawnTests,WhiteMove1Mid) {
        Board* b = new Board();
        Move* m1 = new Move(coordinate(3,3), coordinate(2,3));
        Pawn test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m1,b),true);
        delete b;
        delete m1;
}

TEST(PawnTests,WhiteMove2Mid) {
        Board* b = new Board();
        Move* m1 = new Move(coordinate(3,3), coordinate(1,3));
        Pawn test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m1,b),false);
        delete b;
        delete m1;
}

TEST(PawnTests,WhiteMove2Empty) {
        Board* b = new Board(); 
        Move* m1 = new Move(coordinate(6,1), coordinate(4,1));
        Pawn test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m1,b),true);
        delete b;
        delete m1;
}

TEST(PawnTests,WhiteMove2WrongDirection) {
        Board* b = new Board();
        Move* m1 = new Move(coordinate(1,1), coordinate(3,1));
        Pawn test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m1,b),false);
        delete b;
        delete m1;
}

TEST(PawnTests,BlackMove1Empty) {
        Board* b1 = Board().move(coordinate(3,3), coordinate(3,2) , 1);
        Move* m1 = new Move(coordinate(6,1), coordinate(5,1));
	Move* m2 = new Move(coordinate(1,1), coordinate(2,1));
        Pawn test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m2,b1),true);
        delete b1;
        delete m1;
        delete m2;
}

TEST(PawnTests,BlackMove1WrongDirection) {
        Board* b1 = Board().move(coordinate(3,3), coordinate(3,2) , 1);
        Move* m1 = new Move(coordinate(6,1), coordinate(5,1));
        Move* m2 = new Move(coordinate(6,0), coordinate(5,0));
        Pawn test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m2,b1),false);
        delete b1;
        delete m1;
        delete m2;
}

TEST(PawnTests,BlackMove1Mid) {
        Board* b1 = Board().move(coordinate(3,3), coordinate(3,2) , 1);
        Move* m1 = new Move(coordinate(6,1), coordinate(5,1));
        Move* m2 = new Move(coordinate(4,7), coordinate(5,7));
        Pawn test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m2,b1),true);
        delete b1;
        delete m1;
        delete m2;
}

TEST(PawnTests,BlackMove2Mid) {
        Board* b1 = Board().move(coordinate(3,3), coordinate(3,2) , 1);
        Move* m1 = new Move(coordinate(6,1), coordinate(5,1));
        Move* m2 = new Move(coordinate(3,7), coordinate(5,7));
        Pawn test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m2,b1),false);
        delete b1;
        delete m1;
        delete m2;
}

TEST(PawnTests,BlackMove2Empty) {
        Board* b1 = Board().move(coordinate(3,3), coordinate(3,2) , 1);
        Move* m1 = new Move(coordinate(6,1), coordinate(4,1));
	Move* m2 = new Move(coordinate(1,1), coordinate(3,1));
        Pawn test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m2,b1),true);
        delete b1;
        delete m1;
        delete m2;
}

TEST(PawnTests,BlackMove2WrongDirection) {
        Board* b1 = Board().move(coordinate(3,3), coordinate(3,2) , 1);
        Move* m1 = new Move(coordinate(6,1), coordinate(4,1));
        Move* m2 = new Move(coordinate(6,0), coordinate(4,0));
        Pawn test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m2,b1),false);
        delete b1;
        delete m1;
        delete m2;
}


TEST(PawnTests,CaptureBRight) {
	// move diagonal
	Board* b1 = new Board();
	Board* b2 = Board().move(coordinate(6,1), coordinate(4,1) , 1);
	Board* b3 = b2->move(coordinate(1,2), coordinate(3,2) , 1);
	Move* m = new Move(coordinate(4,1), coordinate(3,2));
	
        Pawn test_piece;
	
        EXPECT_EQ(test_piece.isMoveValid(m,b3),true);
	delete b1;
        delete b2;
        delete b3;
	delete m;
}

TEST(PawnTests,CaptureBLeft) {
        // move diagonal
	Board* b1 = new Board();
        Board* b2 = Board().move(coordinate(6,3), coordinate(4,3) , 1);
        Board* b3 = b2->move(coordinate(1,2), coordinate(3,2) , 1);
        Move* m = new Move(coordinate(4,3), coordinate(3,2));

        Pawn test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m,b3),true);
        delete b1;
        delete b2;
        delete b3;
        delete m;
}

TEST(PawnTests,CaptureWRight) {
        // move diagonal
        Board* b1 = new Board();
        Board* b2 = Board().move(coordinate(6,3), coordinate(4,3) , 1);
        Board* b3 = b2->move(coordinate(1,2), coordinate(3,2) , 1);
	
        Board* b4 = b3->move(coordinate(5,5), coordinate(4,5) , 1);
	
	Move* m = new Move(coordinate(3,2), coordinate(4,3));
        
        Pawn test_piece;
        
        EXPECT_EQ(test_piece.isMoveValid(m,b4),true);
        delete b1;
        delete b2;
        delete b3;
	delete b4;
        delete m;
}

TEST(PawnTests,CaptureWLeft) {
        // move diagonal
        Board* b1 = new Board();
        Board* b2 = Board().move(coordinate(6,3), coordinate(4,3) , 1);
        Board* b3 = b2->move(coordinate(1,4), coordinate(3,4) , 1);
        
        Board* b4 = b3->move(coordinate(5,5), coordinate(4,5) , 1);
        
	Move* m = new Move(coordinate(3,4), coordinate(4,3));
        
        Pawn test_piece;
	
	EXPECT_EQ(test_piece.isMoveValid(m,b4),true);
        delete b1;
        delete b2;
        delete b3;
        delete b4;
        delete m;
}

TEST(PawnTests,WCaptureWLeft) {
        Board* b1 = new Board();
        Board* b2 = Board().move(coordinate(6,3), coordinate(4,3) , 1);
        Board* b3 = b2->move(coordinate(1,3), coordinate(3,3) , 1);
	
        Board* b4 = b3->move(coordinate(6,4), coordinate(5,4) , 1);
        Board* b5 = b4->move(coordinate(1,4), coordinate(2,4) , 1);
	
        Move* m = new Move(coordinate(5,4), coordinate(4,3));
        
        Pawn test_piece;
        
        EXPECT_EQ(test_piece.isMoveValid(m,b5),false);
        delete b1;
        delete b2;
        delete b3;
        delete b4;
	delete b5;
        delete m;
}

TEST(PawnTests,BCaptureBLeft) {
        Board* b1 = new Board();
        Board* b2 = Board().move(coordinate(6,3), coordinate(4,3) , 1);
        Board* b3 = b2->move(coordinate(1,3), coordinate(3,3) , 1);

        Board* b4 = b3->move(coordinate(6,4), coordinate(5,4) , 1);
        Board* b5 = b4->move(coordinate(1,4), coordinate(2,4) , 1);

        Board* b6 = b5->move(coordinate(6,7), coordinate(5,7) , 1);
	Move* m = new Move(coordinate(2,4), coordinate(3,3));

        Pawn test_piece;

        EXPECT_EQ(test_piece.isMoveValid(m,b6),false);
        delete b1;
        delete b2;
        delete b3;
        delete b4;
        delete b5;
        delete b6;
        delete m;
}

#endif
