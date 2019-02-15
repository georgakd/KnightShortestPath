
#include "catch.hpp"
#include "../Knight.h"

int xstart = 0;
int ystart = 0;
int xdest = 0;
int ydest = 0;
const std::string in_filename = "../../tests/input.txt";
const std::string in1_filename = "../../tests/input1.txt";
const std::string in2_filename = "../../tests/input2.txt";
const std::string in3_filename = "../../tests/input3.txt";
const std::string in6_filename = "../../tests/input6.txt";
const std::string in_oor_filename = "../../tests/input_oor.txt";

TEST_CASE("1. Test if the src/dest positions are read from file as expected.")
{

  knight::Knight testKnight;
  int result = testKnight.readPositions(xstart, ystart, xdest, ydest, in_filename);
  CHECK(result == 0);

}

TEST_CASE("2. Test the out of the board positions handling.")
{

  knight::Knight testKnight;
  int result = testKnight.readPositions(xstart, ystart, xdest, ydest, in_oor_filename);
  CHECK(result == 1);

}


TEST_CASE("3. Test if the source/dest positions are set as expected")
{

  knight::Knight testKnight;
  int xstart = 0, ystart = 7, xdest = 7, ydest = 0;

  testKnight.setPositions(xstart, ystart);
  CHECK(testKnight.getXPosition() == xstart);
  CHECK(testKnight.getYPosition() == ystart);

  testKnight.setPositions(xdest, ydest);
  CHECK(testKnight.getXPosition() == xdest);
  CHECK(testKnight.getYPosition() == ydest);

}


TEST_CASE("4. Test find Knight's destination with one move")
{

  knight::Knight read_knight;
  read_knight.readPositions(xstart, ystart, xdest, ydest, in1_filename);
  knight::Knight src_knight(xstart, ystart);
  knight::Knight dest_knight(xdest, ydest);

  auto result = dest_knight.findMinDistance(src_knight, dest_knight);
  CHECK(result == 1); //one move

}

TEST_CASE("5. Test find Knight's destination with two moves")
{

  knight::Knight read_knight;
  read_knight.readPositions(xstart, ystart, xdest, ydest, in2_filename);
  knight::Knight src_knight(xstart, ystart);
  knight::Knight dest_knight(xdest, ydest);

  auto result = dest_knight.findMinDistance(src_knight, dest_knight);
  CHECK(result == 2); //two moves

}

TEST_CASE("6. Test find Knight's destination with three moves")
{

  knight::Knight read_knight;
  read_knight.readPositions(xstart, ystart, xdest, ydest, in3_filename);
  knight::Knight src_knight(xstart, ystart);
  knight::Knight dest_knight(xdest, ydest);

  auto result = dest_knight.findMinDistance(src_knight, dest_knight);
  CHECK(result == 3); //three moves

}

TEST_CASE("7. Test find Knight's destination with six moves")
{

  knight::Knight read_knight;
  read_knight.readPositions(xstart, ystart, xdest, ydest, in6_filename);
  knight::Knight src_knight(xstart, ystart);
  knight::Knight dest_knight(xdest, ydest);

  auto result = dest_knight.findMinDistance(src_knight, dest_knight);
  CHECK(result == 6); //six moves

}



