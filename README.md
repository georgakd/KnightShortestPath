Create an application that should represent an empty chessboard where the user will be able
to enter a starting position and an ending position. The application should then calculate a list 
of all possible paths that one knight piece in the starting position could take to reach the ending 
position in 3 moves. Some inputs might not have a solution, in this case the program should display 
a message that no solution has been found. Otherwise, the shortest path (if that exists) should be returned.


### How-To Build the project in Linux

In order to build the project follow these steps:
- Download cmake and follow installation guide (https://cmake.org/install/)
- Clear the cmake-build-debug directory if it has results from a previous build
- Go to cmake-build-debug and run: cmake -D CMAKE_CXX_FLAGS="-std=c++11 -O0 -ggdb" ..
- Run make
- Run the program as: ./ChessboardSimulation 
- Run the unit tests as: ./tests/ChessTests 
