Create an application that should represent an empty chessboard where the user will be able
to enter a starting position and an ending position. The application should then calculate a list 
of all possible movements that one knight piece in the starting position could take, to reach the ending
position. The program should return the minimum number of steps required for that or NOT FOUND if the path is not possible.

### How-To Build the project in Linux

In order to build the project follow these steps:
- Download cmake and follow installation guide (https://cmake.org/install/)
- Clear the cmake-build-debug directory if it has results from a previous build
- Go to cmake-build-debug and run: cmake -D CMAKE_CXX_FLAGS="-std=c++11 -O0 -ggdb" ..
- Run make
- Run the program as: ./ChessboardSimulation 
- Run the unit tests as: ./tests/ChessTests 
