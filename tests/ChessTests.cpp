
#include "catch.hpp"
#include "../Knight.h"

int xstart = 0;
int ystart = 0;
int xdest = 0;
int ydest = 0;
const std::string in_filename = "../input.txt";
const std::string in1_filename = "../input1.txt";
const std::string in2_filename = "../input2.txt";
const std::string in3_filename = "../input3.txt";
const std::string in6_filename = "../input6.txt";
const std::string in_oor_filename = "../input_oor.txt";

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
  int xstart = 0;
  int ystart = 7;
  int xdest = 7;
  int ydest = 0;
  testKnight.setPositions(xstart, ystart);
  CHECK(testKnight.getXPosition() == xstart);
  CHECK(testKnight.getYPosition() == ystart);
  testKnight.setPositions(xdest, ydest);
  CHECK(testKnight.getXPosition() == xdest);
  CHECK(testKnight.getYPosition() == ydest);

}

TEST_CASE("4. Test find Knight's destination with one move")
{

  knight::Knight src_knight;
  knight::Knight dest_knight;
  knight::Knight read_knight;
  read_knight.readPositions(xstart, ystart, xdest, ydest, in1_filename);
  src_knight.setPositions(xstart, ystart);
  dest_knight.setPositions(xdest, ydest);
  auto result = dest_knight.findMinDistance(src_knight, dest_knight);
  CHECK(result == 1); //one move

}

TEST_CASE("5. Test find Knight's destination with two moves")
{

  knight::Knight src_knight;
  knight::Knight dest_knight;
  knight::Knight read_knight;
  read_knight.readPositions(xstart, ystart, xdest, ydest, in2_filename);
  src_knight.setPositions(xstart, ystart);
  dest_knight.setPositions(xdest, ydest);
  auto result = dest_knight.findMinDistance(src_knight, dest_knight);
  CHECK(result == 2); //two moves

}

TEST_CASE("6. Test find Knight's destination with three moves")
{

  knight::Knight src_knight;
  knight::Knight dest_knight;
  knight::Knight read_knight;
  read_knight.readPositions(xstart, ystart, xdest, ydest, in3_filename);
  src_knight.setPositions(xstart, ystart);
  dest_knight.setPositions(xdest, ydest);
  auto result = dest_knight.findMinDistance(src_knight, dest_knight);
  CHECK(result == 3); //three moves

}

TEST_CASE("7. Test find Knight's destination with six moves")
{

  knight::Knight src_knight;
  knight::Knight dest_knight;
  knight::Knight read_knight;
  read_knight.readPositions(xstart, ystart, xdest, ydest, in6_filename);
  src_knight.setPositions(xstart, ystart);
  dest_knight.setPositions(xdest, ydest);
  auto result = dest_knight.findMinDistance(src_knight, dest_knight);
  CHECK(result == 6); //six moves

}




