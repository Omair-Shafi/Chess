#ifndef __COORDINATE_TESTS_HPP__
#define __COORDINATE_TESTS_HPP__

#include "../../Model/coordinate.hpp"

TEST(CoordinateTests, Addition) {
    coordinate c1(1,2);
    coordinate c2(3,4);
    coordinate c3 = c1 + c2;

    EXPECT_EQ((c1 + c2).stringify(), "(4, 6)");
    EXPECT_EQ(c3.stringify(), "(4, 6)");
}

TEST(CoordinateTests, Subtraction) {
    coordinate c1(1,2);
    coordinate c2(3,4);
    coordinate c3 = c1 - c2;

    EXPECT_EQ((c1 - c2).stringify(), "(-2, -2)");
    EXPECT_EQ(c3.stringify(), "(-2, -2)");
}

TEST(CoordinateTests, ScalarMultiple) {
    coordinate c1(1,2);
    coordinate c2(3,4);
    coordinate c3 = (c1 + c2)*3;

    EXPECT_EQ((c1*2).stringify(), "(2, 4)");
    EXPECT_EQ((c2*0).stringify(), "(0, 0)");
    EXPECT_EQ((c1 + c2*-10).stringify(), "(-29, -38)");
    EXPECT_EQ(c3.stringify(), "(12, 18)");
}

TEST(CoordinateTests, InnerProduct) {
    coordinate c1(1,2);
    coordinate c2(3,4);

    EXPECT_EQ(c1 * c2, 11);
    EXPECT_EQ(c2 * c1, 11);
    EXPECT_EQ(c1 * 8 * c2, 88);
    EXPECT_EQ((c1 * (c2 * c1)).stringify(), "(11, 22)");
}

TEST(CoordinateTests, Rotate) {
    coordinate c1(1,0);
    coordinate c2(-3,5);
    coordinate c3 = rotate(c1, 45);

    EXPECT_EQ(rotate(c1, 90).stringify(), "(0, 1)");
    EXPECT_EQ(rotate(c2, 90).stringify(), "(-5, -3)");
    EXPECT_EQ(rotate(rotate(c1, 45), -45).stringify(), "(1, 0)");
    EXPECT_EQ(c3.stringify(), "(1, 1)");
}

TEST(CoordinateTests, LinearDependence) {
    coordinate c1(1,2);
    coordinate c2(3,4);

    EXPECT_TRUE(are_dependent(c1, c1));
    EXPECT_TRUE(are_dependent(c1*51, c1*-4));
    EXPECT_TRUE(are_dependent(c2 - c1, c1 - c2));
    EXPECT_TRUE(are_dependent(rotate(c1, 90), rotate(c1*-3, -90)));
    
    coordinate c3(1000000, 1999999);

    EXPECT_FALSE(are_dependent(c1, c3));
    EXPECT_FALSE(are_dependent(c3*-4, c1*-30));
    EXPECT_FALSE(are_dependent(c1, rotate(c3, 360)));
}

TEST(CoordinateTests, Direction) {
    coordinate c1(1,2);
    coordinate c2(3,4);

    EXPECT_TRUE(are_equivalent(c1, c1));
    EXPECT_TRUE(are_equivalent(c1*51, c1*4));
    EXPECT_TRUE(are_equivalent(c2 - c1, (c1 - c2)*-1));
    EXPECT_TRUE(are_equivalent(rotate(c1, 90), rotate(c1*-3, -90)));
    
    coordinate c3(1000000, 1999999);

    EXPECT_FALSE(are_equivalent(c1, c1*-1));
    EXPECT_FALSE(are_equivalent(c3, c1));
    EXPECT_FALSE(are_equivalent(c1, c1 - c1));
}

#endif
