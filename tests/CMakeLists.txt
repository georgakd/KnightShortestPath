project(tests)

add_definitions (-DUNIT_TEST)
add_executable(ChessTests
               ../Knight.cpp
               ChessTests.cpp)

target_link_libraries(ChessTests
                      catchTestMain)
