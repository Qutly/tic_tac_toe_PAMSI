#include "../inc/SFMLController.h"

void SfmlController::play(sf::Event event, SfmlView& view, sf::RenderWindow &window) {

    int gridSize = _board.getSize();
    int rv = _board.checkVictory();

    const float squareSize = 65.f;
    const float squareSpacing = 5.f;
    float totalWidth = (gridSize * squareSize) + ((gridSize - 1) * squareSpacing);
    float totalHeight = (gridSize * squareSize) + ((gridSize - 1) * squareSpacing);
    float startX = (window.getSize().x - totalWidth) / 2.f;
    float startY = (window.getSize().y - totalHeight) / 2.f;

     if(event.type == sf::Event::Closed) {
         window.close();
     }

     if(event.type == sf::Event::MouseButtonPressed) {
         if (rv == NO_VAL) {
             if (event.mouseButton.button == sf::Mouse::Left) {
                 sf::Vector2f mousePos = window.mapPixelToCoords(
                         sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                 int xIndex = (mousePos.x - startX) / (squareSize + squareSpacing);
                 int yIndex = (mousePos.y - startY) / (squareSize + squareSpacing);
                 if(_board.getVal(yIndex, xIndex) == NO_VAL) {
                     _mainGame.playerMove(yIndex, xIndex);
                     window.clear();
                     view.draw(window);
                     window.display();
                     if (_mainGame.getCurrentPlayer() == _mainGame.getAiPlayer() &&
                         _board.checkVictory() == NO_VAL)
                         _mainGame.aiMove();
                     window.clear();
                     view.draw(window);
                     window.display();
                 }
             }
         }
     }
}

