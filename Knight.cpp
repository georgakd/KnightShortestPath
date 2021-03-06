#include <iostream>
#include "fstream"
#include <stdexcept>
#include <queue>
#include "Knight.h"

#define NOT_FOUND (-1)

  knight::Knight::Knight() : m_x{0}, m_y{0} { }
  knight::Knight::Knight(int x, int y) : m_x{x}, m_y{y} { }

  std::ostream &operator<<(std::ostream &out, const knight::Knight &knight) {
      out << knight.getXPosition() + 1 << knight.getYPosition() + 1 << std::endl;
      return out;
  }


  int knight::Knight::findMinDistance(Knight &src, Knight &dest) {

    int xnew, ynew;
    std::string name;

    // map to store the unique node and mark it true when visited
    std::map<std::pair <int, int>, bool > checked;
    // maps to store the conversion to (A,H),(1,8) system
    const std::map<int, char> map_L = {{1, 'A'}, {2, 'B'}, {3, 'C'}, {4, 'D'}, {5, 'E'}, {6, 'F'}, {7, 'G'}, {8, 'H'}};
    const std::map<int, char> map_N = {{1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}};

    remove( "../output.txt" );

    std::queue<Knight> q_node;
    std::queue<std::string> q_paths;
    std::queue<std::string> empty;
    src.m_distance = 0;
    q_node.push(src);
    name.push_back(map_L.at(src.m_x+1));
    name.push_back(map_N.at(src.m_y+1));
    name.push_back(' ');
    q_paths.push(name); // push the name of the visited node to the queue m_paths

#ifndef UNIT_TEST
    std::cout << "The knight's visited nodes are: " << std::endl;
#endif

    while (!q_node.empty()) {
      Knight current = q_node.front();

      q_node.pop();
      q_paths.pop();

      int x = current.m_x;
      int y = current.m_y;
      int dist = current.m_distance;
      auto coords = std::make_pair(current.m_x, current.m_y);

      if ( x == dest.m_x && y == dest.m_y) {
        dest.m_distance = dist;
#ifndef UNIT_TEST
        std::cout << "*" << map_L.at(coords.first+1) << map_N.at(coords.second+1) << std::endl;
        std::cout << "--------------------------------------" << std::endl;
        dest.writePositions(map_L.at(coords.first+1), map_N.at(coords.second+1) );
#endif
        return dest.m_distance;
      }

      if (!checked.count(coords)) {

#ifndef UNIT_TEST
        std::cout << "*" << map_L.at(coords.first+1) << map_N.at(coords.second+1) << std::endl;
        std::cout << "--------------------------------------" << std::endl;
        dest.writePositions(map_L.at(coords.first+1), map_N.at(coords.second+1) );
#endif
        checked[coords] = true;
          for (int i = 0;i < xdim;++i) {
            xnew = x + chess_row[i];
            ynew = y + chess_col[i];

            if (xnew >= 0 && xnew < xdim && ynew >= 0 && ynew < ydim) {
              current.m_x = xnew;
              current.m_y = ynew;
              current.m_distance = dist + 1;
              q_node.push(current);
              name.push_back(map_L.at(current.m_x+1));
              name.push_back(map_N.at(current.m_y+1));
              name.push_back(' ');
              q_paths.push(name);
            }
          } // end for possible moves = 8
      }
    } //end while

    return NOT_FOUND;
  }

  void knight::Knight::setPositions(int x, int y) {
    m_x = x;
    m_y = y;
  }

  int knight::Knight::getXPosition() const {return m_x;}

  int knight::Knight::getYPosition() const {return m_y;}

  int knight::Knight::readPositions(int &xstart, int &ystart, int &xdest, int &ydest, const std::string &in_filename) {

    std::string line;
    std::ifstream input;
    input.open(in_filename);
    if(!input.is_open()) {
      return EXIT_FAILURE;
    }
      getline(input, line, ':');

      // Check whether the input is valid i.e. we cannot enter a number outside of the 8x8 grid
      try {
        input >> xstart >> ystart >> xdest >> ydest;

        if (xstart < 0 || xstart >= xdim || ystart < 0 || ystart >= ydim || xdest < 0 || xdest >= xdim || ydest < 0 || ydest >= ydim ) {
          throw "Positions outside of the board...\n";
        }
        std::cout << line << ":  " << xstart << " " << ystart << "   " << xdest << " " << ydest << std::endl;
      }
      catch (const char *msg) {
        std::cerr << msg;
        input.close();
        return EXIT_FAILURE;
      }

    input.close();
    return EXIT_SUCCESS;
  }

  void knight::Knight::writePositions(char x, char y) {
    std::fstream output;
    std::string out_filename = "../output.txt";
    output.open(out_filename, std::ios_base::out | std::ios_base::app);
    if(output.is_open()) {
      output << x << y << std::endl;

    }
    else {
      std::cout << "Output file not created!" << std::endl;
    }
    output.close();

  }

