#include "../inc/AI.h"

#include <vector>

void AI::init(int aiPlayer, int depth) {
    _aiPlayer = aiPlayer;
    _humanPlayer = _aiPlayer == X_VAL ? O_VAL : X_VAL;
    _depth = depth;
}

void AI::performMove(Board& board) {
    int i, j;
    AiMove move;
    int bestScore = INT_MIN;
    int alpha = INT_MIN;
    int beta = INT_MAX;
    for (i = 0; i < board.getSize(); i++) {
        for (j = 0; j < board.getSize(); j++) {
            if (board.getVal(i, j) == NO_VAL) {
                board.setVal(i, j, _aiPlayer);
                int score = minimax(board, 0, false, alpha, beta);
                board.setVal(i, j, NO_VAL);
                if (score > bestScore) {
                    bestScore = score;
                    move.x = i;
                    move.y = j;
                }
                alpha = std::max(alpha, bestScore);
            }
        }
    }
    board.setVal(move.x, move.y, _aiPlayer);
}

int AI::minimax(Board& board, int depth, bool isMaximizing, int alpha, int beta) {
    int retv = board.checkVictory();
    if (retv == _aiPlayer) {
        return 100 - depth;
    } else if (retv == _humanPlayer) {
        return depth - 100;
    } else if (retv == TIE_VAL) {
        return 0;
    }

    if (depth >= _depth) {
        return evaluate(board);
    }

    if (isMaximizing) {
        int bestScore = INT_MIN;
        for (int i = 0; i < board.getSize(); i++) {
            for (int j = 0; j < board.getSize(); j++) {
                if (board.getVal(i, j) == NO_VAL) {
                    board.setVal(i, j, _aiPlayer);
                    int score = minimax(board, depth + 1, false, alpha, beta);
                    board.setVal(i, j, NO_VAL);
                    bestScore = std::max(score, bestScore);
                    alpha = std::max(alpha, bestScore);
                    if(beta <= alpha) {
                        return bestScore;
                    }
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = INT_MAX;
        for (int i = 0; i < board.getSize(); i++) {
            for (int j = 0; j < board.getSize(); j++) {
                if (board.getVal(i, j) == NO_VAL) {
                    board.setVal(i, j, _humanPlayer);
                    int score = minimax(board, depth + 1, true, alpha, beta);
                    board.setVal(i, j, NO_VAL);
                    bestScore = std::min(score, bestScore);
                    beta = std::min(beta, bestScore);
                    if(beta <= alpha) {
                        return bestScore;
                    }
                }
            }
        }
        return bestScore;
    }
}

int AI::evaluate(const Board& board) {

    int aiScore = 0;
    int humanScore = 0;

    for (int i = 0; i < board.getSize(); i++) {
        int aiCount = 0;
        int humanCount = 0;
        for (int j = 0; j < board.getSize(); j++) {
            if (board.getVal(i, j) == _aiPlayer) {
                aiCount++;
            } else if (board.getVal(i, j) == _humanPlayer) {
                humanCount++;
            }
        }
        aiScore += evaluateLine(aiCount, humanCount);
    }

    for (int j = 0; j < board.getSize(); j++) {
        int aiCount = 0;
        int humanCount = 0;
        for (int i = 0; i < board.getSize(); i++) {
            if (board.getVal(i, j) == _aiPlayer) {
                aiCount++;
            } else if (board.getVal(i, j) == _humanPlayer) {
                humanCount++;
            }
        }
        aiScore += evaluateLine(aiCount, humanCount);
    }

    int aiCount = 0;
    int humanCount = 0;
    for (int i = 0; i < board.getSize(); i++) {
        if (board.getVal(i, i) == _aiPlayer) {
            aiCount++;
        } else if (board.getVal(i, i) == _humanPlayer) {
            humanCount++;
        }
    }
    aiScore += evaluateLine(aiCount, humanCount);

    aiCount = 0;
    humanCount = 0;
    for (int i = 0; i < board.getSize(); i++) {
        if (board.getVal(i, board.getSize() - 1 - i) == _aiPlayer) {
            aiCount++;
        } else if (board.getVal(i, board.getSize() - 1 - i) == _humanPlayer) {
            humanCount++;
        }
    }
    aiScore += evaluateLine(aiCount, humanCount);

    return aiScore - humanScore;
}

int AI::evaluateLine(int aiCount, int humanCount) {
    if (aiCount == 0) {
        if (humanCount == 0) {
            return 0;
        } else {
            return -humanCount;
        }
    } else if (humanCount == 0) {
        return aiCount;
    } else {
        return 0;
    }
}
