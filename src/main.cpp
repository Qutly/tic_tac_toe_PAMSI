#include "../inc/SFMLView.h"
#include "../inc/SFMLController.h"

int main() {
    Board board;
    MainGame mainGame(board);
    SfmlView view(board, mainGame);
    SfmlController ctrl(mainGame, board, view);

    sf::RenderWindow window(sf::VideoMode(board.getSize() * 190, board.getSize() * 190), "Tic Tac Toe",
                            sf::Style::Titlebar | sf::Style::Close & ~sf::Style::Resize);

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    float centerX = static_cast<float>(desktop.width - window.getSize().x) / 2.0f;
    float centerY = static_cast<float>(desktop.height - window.getSize().y) / 2.0f;

    window.setPosition(sf::Vector2i(static_cast<int>(centerX), static_cast<int>(centerY)));

    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    if (mainGame.getCurrentPlayer() == mainGame.getAiPlayer()) {
        window.clear();
        view.draw(window);
        window.display();
        mainGame.aiMove();
    }

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            ctrl.play(event, view, window);
        }
        window.clear();
        view.draw(window);
        window.display();
    }

    return 0;
}