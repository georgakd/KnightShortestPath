#ifndef CHESSBOARDSIMULATION_KNIGHT_H
#define CHESSBOARDSIMULATION_KNIGHT_H

#include "Chess.h"

namespace knight {

  class Knight : public chessboard::Chess {

  public:
    Knight();
    Knight(int x, int y);
    friend std::ostream &operator<<(std::ostream &out, const Knight &knight);
    int findMinDistance(Knight &src, Knight &dest);
    void setPositions(int x, int y) override;
    int readPositions(int &xstart, int &ystart, int &xdest, int &ydest, const std::string &in_filename) override;
    int getXPosition() const override;
    int getYPosition() const override;
    void writePositions(char x, char y) override;
    virtual ~Knight() = default;

  private:
    // arrays to store all possible knight movements
    const int chess_row[xdim] = {2, 2, -2, -2, 1, 1, -1, -1};
    const int chess_col[ydim] = {-1, 1, 1, -1, 2, -2, 2, -2};
    int m_x;
    int m_y;

    //a vertex's distance is set to -1 until the node has been visited
    int m_distance = -1;
  };

}

#endif //CHESSBOARDSIMULATION_KNIGHT_H
