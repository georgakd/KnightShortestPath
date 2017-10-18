project(catch)
add_library(catchTestMain STATIC testMain.cpp)
target_include_directories(catchTestMain PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
