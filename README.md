### How-To Build the project in Linux

In order to build the project follow these steps:
- Download cmake and follow installation guide (https://cmake.org/install/)
- Clear the cmake-build-debug directory if it has results from a previous build
- Go to cmake-build-debug and run: cmake -D CMAKE_CXX_FLAGS="-std=c++11 -O0 -ggdb" ..
- Run make
- Run the program as: ./ChessboardSimulation 
- Run the unit tests as: ./tests/ChessTests 
