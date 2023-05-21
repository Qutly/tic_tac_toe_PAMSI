#include "../inc/Board.h"
#include <iostream>
#include <string>

void Board::init(int size, int winCondition) {
    if (size > 7) size = 7;
    _size = size;
    _winCondition = winCondition;
    _board.resize(size * size);
    clear();
}

void Board::clear() {
    for (int & i : _board) {
        i = NO_VAL;
    }
}


void Board::print() const {
    int i, j, k;
    std::cout << "    ";
    for (k = 1; k < _size + 1; k++) {
        std::cout << (k <= 9 ? std::to_string(k) + "  " : std::to_string(k) + " ");
    }
    std::cout << std::endl;

    for (i = 0; i < _size; i++) {
        for (j = 0; j < _size; j++) {
            std::cout
                    << (j == 0 ? (i <= 9 ? std::to_string(i + 1) + "  " : std::to_string(i + 1) + " ") : "")
                    << "["
                    << (getVal(i,j) == X_VAL || getVal(i,j) == O_VAL ? (getVal(i,j) == X_VAL ? "x" : "o") : ".")
                    << "]" << (j == _size - 1? "\n" : "");
        }
    }
}


int Board::checkVictory() const {
    bool victory;
    int c;

    for (int y = 0; y < _size; y++) {
        for (int x = 0; x <= _size - _winCondition; x++) {
            c = getVal(x, y);
            if (c != NO_VAL) {
                victory = true;
                for (int i = 1; i < _winCondition; i++) {
                    if (getVal(x + i, y) != c) {
                        victory = false;
                        break;
                    }
                }
                if (victory) return c;
            }
        }
    }

    for (int x = 0; x < _size; x++) {
        for (int y = 0; y <= _size - _winCondition; y++) {
            c = getVal(x, y);
            if (c != NO_VAL) {
                victory = true;
                for (int i = 1; i < _winCondition; i++) {
                    if (getVal(x, y + i) != c) {
                        victory = false;
                        break;
                    }
                }
                if (victory) return c;
            }
        }
    }

    for (int x = 0; x <= _size - _winCondition; x++) {
        for (int y = 0; y <= _size - _winCondition; y++) {
            c = getVal(x, y);
            if (c != NO_VAL) {
                victory = true;
                for (int i = 1; i < _winCondition; i++) {
                    if (getVal(x + i, y + i) != c) {
                        victory = false;
                        break;
                    }
                }
                if (victory) return c;
            }
        }
    }

    for (int x = _winCondition - 1; x < _size; x++) {
        for (int y = 0; y <= _size - _winCondition; y++) {
            c = getVal(x, y);
            if (c != NO_VAL) {
                victory = true;
                for (int i = 1; i < _winCondition; i++) {
                    if (getVal(x - i, y + i) != c) {
                        victory = false;
                        break;
                    }
                }
                if (victory) return c;
            }
        }
    }

    for (int i: _board) {
        if (i == NO_VAL) return NO_VAL;
    }

    return TIE_VAL;

}