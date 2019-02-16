// Chessboard application.
// x position is marked from a-h and y from 1-8
// for simplicity reasons in our program we will have x (0-7) and y (0-7)
// and then we will transform it in the print output

#include <iostream>
#include "Knight.h"

int main() {
  
  const std::string in_filename = "../input.txt";
  
  // Read the initial coordinates of the knight from file and set initial positions
  int xstart, ystart, xdest, ydest;
  knight::Knight read_knight;

  if (read_knight.readPositions(xstart, ystart, xdest, ydest, in_filename)) {
    return EXIT_FAILURE;
  }

  knight::Knight src_knight(xstart, ystart);
  knight::Knight dest_knight(xdest, ydest);

  // Find the min distance from source to destination
  auto result = dest_knight.findMinDistance(src_knight, dest_knight);
  if (result == -1) {
    std::cout << "Solution not found" << std::endl;
  }
  else {
    std::cout << "Solution found at minimum moves: " << result << std::endl;
  }
  return EXIT_SUCCESS;
}
