#include "../inc/MainGame.h"

void MainGame::playerMove(int x, int y) {

    _board.setVal(x, y, _currentPlayer);
    changePlayer();
}

void MainGame::aiMove() {
    if(_board.getSize() == 3) std::this_thread::sleep_for(std::chrono::seconds(2));
    _ai.performMove(_board);
    changePlayer();
}

void MainGame::changePlayer() {
    if (_currentPlayer == X_VAL) {
        _currentPlayer = O_VAL;
    } else {
        _currentPlayer = X_VAL;
    }
}
