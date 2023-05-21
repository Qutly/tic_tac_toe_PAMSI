#pragma once

#include "Board.h"
#include <climits>

struct AiMove
{
	AiMove() {}
	int x;
	int y;
};

class AI {
    int _aiPlayer;
    int _humanPlayer;
    int _depth;
public:
    void init(int aiPlayer, int depth);
    int minimax(Board& board, int depth, bool isMaximizing, int alpha, int beta);
    static int evaluateLine(int aiCount, int humanCount);
    int evaluate(const Board& board);
    int evaluatePositionValues(Board& board, int aiCount, int humanCount, int boardSize, int row, int col);
    void performMove(Board& board);

};

