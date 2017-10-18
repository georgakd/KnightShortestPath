#ifndef CHESSBOARDSIMULATION_CHESS_H
#define CHESSBOARDSIMULATION_CHESS_H
#include <map>
#include <vector>
#include <queue>
#include <fstream>

// Abstract class Chess

namespace chessboard {


  class Chess {
  public:
    const static int xdim = 8;
    const static int ydim = 8;
    virtual void setPositions(int x, int y) = 0;
    virtual int readPositions(int &xstart, int &ystart, int &xdest, int &ydest, const std::string &in_filename) = 0;
    virtual int getXPosition() const = 0;
    virtual int getYPosition() const = 0;
    virtual void writePositions(char x, char y) = 0;
    virtual ~Chess() = default;

  };

}
#endif //CHESSBOARDSIMULATION_CHESS_H
