cmake_minimum_required(VERSION 3.14)
project(tic_tac_toe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ../src/main.cpp src/MainGame.cpp src/Board.cpp src/AI.cpp src/SFMLView.cpp src/SFMLController.cpp inc/AI.h inc/Board.h inc/MainGame.h inc/SFMLController.h inc/SFMLView.h)
add_executable(tictactoe ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(tictactoe sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

