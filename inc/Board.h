#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

const int TIE_VAL = -1;
const int NO_VAL = 0;
const int X_VAL = 1;
const int O_VAL = 2;

class Board {

    std::vector<int> _board;
    int _size;
    int _winCondition;
public:
    void init(int size, int winCondition);
    void clear();
    void print() const;
    int checkVictory() const;

    void setVal(int x, int y, int val) {
        _board[y * _size + x] = val;
    }
    int getVal(int x, int y) const {
        return _board[y * _size + x];
    }
    int getSize() const { return _size; }
    int getWinCondition() const { return _winCondition; }
};

