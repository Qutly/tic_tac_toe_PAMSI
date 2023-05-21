#ifndef KOLKO_I_KRZYZYK_SFMLVIEW_H
#define KOLKO_I_KRZYZYK_SFMLVIEW_H
#include "Board.h"
#include "MainGame.h"
class SfmlView {
    Board& _board;
    MainGame& _mainGame;
public:
    SfmlView(Board &b, MainGame& mainGame)
            :_board(b), _mainGame(mainGame){}
    void draw(sf::RenderWindow& window);
};

#endif