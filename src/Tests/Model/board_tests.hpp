#ifndef __BOARD_TESTS_HPP__
#define __BOARD_TESTS_HPP__

#include "../../Model/board.hpp"

TEST(BoardTests, BaseCase) {
    Board b;
    std::stringstream ss;
    std::string out = "RNBQKBNR\nPPPPPPPP\n        \n        \n        \n        \npppppppp\nrnbkqbnr\n";

    b.print(ss);

    EXPECT_EQ(ss.str(), out);
}

TEST(BoardTests, MoveTest) {
    Board* b1 = Board().move(coordinate(0,0), coordinate(3,5), 0);
    Board* b2 = b1->move(coordinate(7,7), coordinate(3,5), 200);
    Board* b3 = b2->move(coordinate(0,3), coordinate(7,2), 300);
    std::string out1 = " NBQKBNR\nPPPPPPPP\n        \n     R  \n        \n        \npppppppp\nrnbkqbnr\n";
    std::string out2 = " NBQKBNR\nPPPPPPPP\n        \n     r  \n        \n        \npppppppp\nrnbkqbn \n";
    std::stringstream ss;
    
    b1->print(ss);
    EXPECT_EQ(ss.str(), out1);
    EXPECT_EQ(b1->get_value(), -1);

    ss.clear();
    ss.str(std::string());    
    b2->print(ss);
    EXPECT_EQ(ss.str(), out2);
    EXPECT_EQ(b2->get_value(), 198);
    EXPECT_EQ(b3->get_value(), -97);

    delete b1;
    delete b2;
    delete b3;
}

TEST(BoardTests, PieceIteratorTest) {
    Board* b = new Board();
    std::string out1 = "RNBQKBNRPPPPPPPPpppppppprnbkqbnr";

    int i = 0;
    for(auto it = b->piece_begin(); it != b->piece_end(); it++) {
        ASSERT_EQ((*it).piece(), out1[i]);
        ASSERT_EQ((*it).pos().stringify(), coordinate(i/8 + (i < 16? 0: 4), i%8).stringify());
        ASSERT_EQ((*it).isWhite(), i > 15);
        i++;
    }
    EXPECT_EQ(i, 32);

    delete b;
    std::string out2 = "RNBKBNRPPPPPPPPpppppQpprnbkqbnr";
    b = Board().move(coordinate(0,3), coordinate(6,5), 200);
    
    i = 0;
    coordinate* c = nullptr;
    for(auto it = b->piece_begin(); it != b->piece_end(); it++) {
        ASSERT_EQ((*it).piece(), out2[i]);
        i++;
    }
    EXPECT_NE(i, 32);
    delete b;
}

TEST(BoardTests, PathIteratorTest) {
    Board* b = Board().move(coordinate(6,6), coordinate(3,3), 200);
    auto it1 = b->path_begin(coordinate(0,0), coordinate(7,7), coordinate(1,1));
    auto it2 = b->path_begin(coordinate(6,7), coordinate(6,0), coordinate(0,-1));
    std::stringstream piece_stream;
    std::stringstream side_stream;
    std::stringstream pos_stream;
    
    for(it1; it1 != b->path_end(); it1++) {
        piece_stream << (*it1).piece();
        side_stream << (*it1).side();
        pos_stream << (*it1).pos().stringify();
    }

    EXPECT_EQ(piece_stream.str(), "RP p   r");
    EXPECT_EQ(side_stream.str(), "-1-1010001");
    EXPECT_EQ(pos_stream.str(), "(0, 0)(1, 1)(2, 2)(3, 3)(4, 4)(5, 5)(6, 6)(7, 7)");

    piece_stream.clear();
    piece_stream.str(std::string());
    side_stream.clear();
    side_stream.str(std::string());
    pos_stream.clear();
    pos_stream.str(std::string());
    for(it2; it2 != b->path_end(); it2++) {
        piece_stream << (*it2).piece();
        side_stream << (*it2).side();
        pos_stream << (*it2).pos().stringify();
    }
    EXPECT_EQ(piece_stream.str(), "p pppppp");
    EXPECT_EQ(side_stream.str(), "10111111");
    EXPECT_EQ(pos_stream.str(), "(6, 7)(6, 6)(6, 5)(6, 4)(6, 3)(6, 2)(6, 1)(6, 0)");

    EXPECT_ANY_THROW(b->path_begin(coordinate(0,0), coordinate(7,1), coordinate(1,0)));
    EXPECT_ANY_THROW(b->path_begin(coordinate(1,0), coordinate(8,0), coordinate(1,0)));

    delete b;
}

#endif
