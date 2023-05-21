#pragma once

#include "AI.h"
#include "Board.h"
#include <iostream>
#include <chrono>
#include <thread>

class MainGame {

    Board& _board;
    int _currentPlayer{};
    int _aiPlayer{};
    AI _ai{};
public:
    MainGame(Board& b) : _board(b) {
        _currentPlayer = X_VAL;

        int depth = 0;
        int inputSize = 0;
        int inputCondition = 0;
        char input = ' ';
        bool isValid;
        std::cout << "\nPlease enter size of the grid (3x3, 5x5, 7x7):  ";
        do {
            isValid = true;
            if (!(std::cin >> inputSize)) {
                std::cout << "Invalid input!\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                isValid = false;
                std::cout << "\nPlease enter size of the grid (3x3, 5x5, 7x7):  ";
            } else if (!(inputSize == 3 || inputSize ==5 || inputSize ==7)) {
                std::cout << "Must enter number 3,5 or 7\n";
                std::cout << "\nPlease enter size of the grid (3x3, 5x5, 7x7):  ";
                isValid = false;
            }
        } while (!isValid);

        std::cout << "\nPlease enter win condition (between 3 and grid input you provided): ";
        do {
            isValid = true;
            if (!(std::cin >> inputCondition)) {
                std::cout << "Invalid input!\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                isValid = false;
            } else if (inputCondition >= 3 && inputCondition <= inputSize) {
                _board.init(inputSize, inputCondition);
            } else {
                std::cout << "Must enter number between 3 and grid input you provided";
                isValid = false;
            }
        } while (!isValid);

        std::cout << "\nWould you like to be x or 0: ";
        do {
            isValid = true;
            if (!(std::cin >> input)) {
                std::cout << "Invalid input!";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                isValid = false;
            } else if (input == 'x' || input == 'X') {
                _aiPlayer = O_VAL;
            } else if (input == 'o' || input == 'O') {
                _aiPlayer = X_VAL;
            } else {
                std::cout << "Must enter X or O!";
                isValid = false;
            }
        } while (!isValid);
        if(_board.getSize() == 3) depth = 3;
        else if(_board.getSize() == 5) depth = 7;
        else if(_board.getSize() == 7) depth = 4;
        _ai.init(_aiPlayer, depth);
        printf("\n\n");
    }
    void playerMove(int x, int y);
    void aiMove();
    void changePlayer();
    int getCurrentPlayer() const { return _currentPlayer; }
    int getAiPlayer() const { return _aiPlayer; }
};

