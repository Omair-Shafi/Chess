#include "gtest/gtest.h"

#include "Messages/move_tests.hpp"
#include "Model/coordinate_tests.hpp"
#include "Model/board_tests.hpp"
#include "Model/rook_tests.hpp"
#include "Model/king_tests.hpp"
#include "Model/bishop_test.hpp"
#include "Model/knight_test.hpp"
#include "Model/queen_tests.hpp"
#include "Model/pawn_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
