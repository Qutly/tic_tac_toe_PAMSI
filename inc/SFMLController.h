#ifndef TIC_TAC_TOE_SFMLCONTROLLER_H
#define TIC_TAC_TOE_SFMLCONTROLLER_H

#include "MainGame.h"
#include "SFMLView.h"
#include "Board.h"

class SfmlController {
    MainGame& _mainGame;
    Board& _board;
    SfmlView& _view;
public:
    SfmlController(MainGame& mainGame, Board& b, SfmlView& v)
            :_mainGame(mainGame), _board(b), _view(v){}
    void play(sf::Event event, SfmlView& view, sf::RenderWindow &window);
};



#endif

