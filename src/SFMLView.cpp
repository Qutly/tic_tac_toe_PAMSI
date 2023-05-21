#include "../inc/SFMLView.h"

void SfmlView::draw(sf::RenderWindow &window) {
    int gridSize = _board.getSize();

    sf::Texture textureCross;
    sf::Texture textureNought;
    sf::Font font;
    sf::Text textGameOver;
    sf::Text textPlayerTurn;
    sf::RectangleShape squares[gridSize][gridSize];

    const float squareSize = 65.f;
    const float squareSpacing = 5.f;
    float totalWidth = (gridSize * squareSize) + ((gridSize - 1) * squareSpacing);
    float totalHeight = (gridSize * squareSize) + ((gridSize - 1) * squareSpacing);
    float startX = (window.getSize().x - totalWidth) / 2.f;
    float startY = (window.getSize().y - totalHeight) / 2.f;

    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
            float posX = startX + (x * (squareSize + squareSpacing));
            float posY = startY + (y * (squareSize + squareSpacing));
            squares[y][x].setSize(sf::Vector2f(squareSize, squareSize));
            squares[y][x].setPosition(posX, posY);
            squares[y][x].setFillColor(sf::Color(200, 200, 200));
            if (_board.getVal(y,x) == NO_VAL) {
                window.draw(squares[y][x]);
            }
            if (_board.getVal(y,x) == X_VAL) {
                if (textureCross.loadFromFile("../assets/cross.png")) {
                    squares[y][x].setTexture(&textureCross);
                    window.draw(squares[y][x]);
                    squares[y][x].setTexture(nullptr);
                }
            }
            if (_board.getVal(y,x) == O_VAL) {
                if (textureNought.loadFromFile("../assets/nought.png")) {
                    squares[y][x].setTexture(&textureNought);
                    window.draw(squares[y][x]);
                    squares[y][x].setTexture(nullptr);
                }
            }
        }
    }
    int whichMarkWon = _board.checkVictory();
    if(font.loadFromFile("../assets/arial.ttf")) {
        textPlayerTurn.setFont(font);
        textPlayerTurn.setFillColor(sf::Color::White);
        textPlayerTurn.setCharacterSize(30);
        textPlayerTurn.setLetterSpacing(2);

        if (_mainGame.getCurrentPlayer() == _mainGame.getAiPlayer()) {
            textPlayerTurn.setString("Computer's Turn");
            textPlayerTurn.setPosition(window.getSize().x / 2.f - textPlayerTurn.getLocalBounds().width / 2.f, 15);
        } else {
            textPlayerTurn.setString("Your Turn");
            textPlayerTurn.setPosition(window.getSize().x / 2.f - textPlayerTurn.getLocalBounds().width / 2.f, 15);
        }

        textGameOver.setFont(font);
        textGameOver.setFillColor(sf::Color::White);
        textGameOver.setCharacterSize(30);
        textGameOver.setLetterSpacing(2);

        if (whichMarkWon == TIE_VAL) {
            textPlayerTurn.setString("");
            textGameOver.setString("TIE!");
            textGameOver.setPosition(window.getSize().x / 2.f - textGameOver.getLocalBounds().width / 2.f, 15);
        } else if (whichMarkWon == X_VAL) {
            textPlayerTurn.setString("");
            textGameOver.setString("Player 'X' Wins!");
            textGameOver.setPosition(window.getSize().x / 2.f - textGameOver.getLocalBounds().width / 2.f, 15);
        } else if (whichMarkWon == O_VAL) {
            textPlayerTurn.setString("");
            textGameOver.setString("Player 'O' Wins!");
            textGameOver.setPosition(window.getSize().x / 2.f - textGameOver.getLocalBounds().width / 2.f, 15);
        }
        window.draw(textPlayerTurn);
        window.draw(textGameOver);
    }
}

