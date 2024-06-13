#ifndef __MOVE_TESTS_HPP__
#define __MOVE_TESTS_HPP__

#include "../../Messages/move.hpp"

TEST(MoveTest, BaseCase) {
    Move m1(coordinate(1,1), coordinate(3,2));
    EXPECT_TRUE(m1.get_origin() == coordinate(1,1));
    EXPECT_TRUE(m1.get_destination() == coordinate(3,2));

    Move m2(coordinate(1,0), coordinate(0,1));
    EXPECT_TRUE(m2.get_origin() == coordinate(1,0));
    EXPECT_TRUE(m2.get_destination() == coordinate(0,1));
    EXPECT_EQ(m2.info(), "Move from (1, 0) to (0, 1).\n");
}

TEST(MoveTest, DistanceBase) {
    Move m1(coordinate(1,0), coordinate(0,1));
    EXPECT_EQ(m1.get_distance(), 1);

    Move m2(coordinate(8,8), coordinate(1,1));
    EXPECT_EQ(m2.get_distance(), 7);    

    Move m3(coordinate(3,4), coordinate(7,4));
    EXPECT_EQ(m3.get_distance(), 4);

    Move m4(coordinate(5,3), coordinate(3,5));
    EXPECT_EQ(m4.get_distance(), 2);
}

TEST(MoveTest,  DistanceKnight) {
    Move m1(coordinate(1, 0), coordinate(2, 2));
    EXPECT_EQ(m1.get_distance(),  1);

    Move m2(coordinate(8, 8), coordinate(6, 7));
    EXPECT_EQ(m2.get_distance(),  1);    

    Move m3(coordinate(4, 3), coordinate(2, 4));
    EXPECT_EQ(m3.get_distance(),  1);

    Move m4(coordinate(5, 3), coordinate(3, 7));
    EXPECT_EQ(m4.get_distance(),  2);
}

TEST(MoveTest,  DistanceEdgeCases) {
    // no move
    Move m1(coordinate(1, 0), coordinate(1, 0));
    EXPECT_EQ(m1.get_distance(),  0);

    Move m2(coordinate(-8, 8), coordinate(8, -8));
    EXPECT_EQ(m2.get_distance(),  16);    

    Move m3(coordinate(12, 12), coordinate(3, 1));
    EXPECT_EQ(m3.get_distance(),  9);

    Move m4(coordinate(12233, 785131415), coordinate(0, 333333));
    EXPECT_EQ(m4.get_distance(),  12233);    
}

TEST(MoveTest, DirectionBase) {
    Move m1(coordinate(1,0), coordinate(0,1));
    EXPECT_EQ(m1.get_direction().stringify(), "(-1, 1)");

    Move m2(coordinate(8,8), coordinate(1,1));
    EXPECT_EQ(m2.get_direction().stringify(), "(-1, -1)");    

    Move m3(coordinate(3,4), coordinate(7,4));
    EXPECT_EQ(m3.get_direction().stringify(), "(1, 0)");

    Move m4(coordinate(5,3), coordinate(3,5));
    EXPECT_EQ(m4.get_direction().stringify(), "(-1, 1)");
}

TEST(MoveTest,  DirectionKnight) {
    Move m1(coordinate(1, 0), coordinate(2, 2));
    EXPECT_EQ(m1.get_direction().stringify(),  "(1, 2)");

    Move m2(coordinate(8, 8), coordinate(6, 7));
    EXPECT_EQ(m2.get_direction().stringify(),  "(-2, -1)");    

    Move m3(coordinate(4, 3), coordinate(2, 4));
    EXPECT_EQ(m3.get_direction().stringify(),  "(-2, 1)");

    Move m4(coordinate(5, 3), coordinate(3, 7));
    EXPECT_EQ(m4.get_direction().stringify(),  "(-1, 2)");
}

TEST(MoveTest,  DirectionFloats) {
    Move m1(coordinate(3, 4), coordinate(100, 100));
    EXPECT_EQ(m1.get_direction().stringify(),  "(1, 1)");

    Move m2(coordinate(1, 2), coordinate(4, 12));
    EXPECT_EQ(m2.get_direction().stringify(),  "(1, 3)");

    Move m3(coordinate(4, 3), coordinate(4, 7));
    EXPECT_EQ(m3.get_direction().stringify(),  "(0, 1)");

    Move m4(coordinate(5, 3), coordinate(3, 5));
    EXPECT_EQ(m4.get_direction().stringify(),  "(-1, 1)");
}

TEST(MoveTest,  DirectionEdgeCases) {
    // no move
    Move m1(coordinate(1, 0), coordinate(1, 0));
    EXPECT_EQ(m1.get_direction().stringify(),  "(0, 0)");

    Move m2(coordinate(-8, 8), coordinate(8, -8));
    EXPECT_EQ(m2.get_direction().stringify(),  "(1, -1)");    

    Move m3(coordinate(12, 12), coordinate(3, 1));
    EXPECT_EQ(m3.get_direction().stringify(),  "(-1, -1)");

    Move m4(coordinate(12233, 785131415), coordinate(0, 333333));
    EXPECT_EQ(m4.get_direction().stringify(),  "(-1, " + std::to_string((333333 - 785131415)/12233) + ")");    
}

#endif
