#include "SFML/Graphics.hpp"

const int numLayers = 5;
const float baseMajor = 59.0f;
const float baseMinor = 52.0f;
const float layerHeights[numLayers - 1] = {4.4f, 4.4f, 4.4f, 5.2f};
const float barrelLength = 4.3f;
const int numBarrels = 24;

void drawBarrel(sf::RenderWindow& window, float startX, float startY) {
    float currentY = startY;

    for (int i = 0; i < numLayers - 1; ++i) {
        sf::ConvexShape trapezoid(4);
        trapezoid.setPoint(0, sf::Vector2f(0, currentY));
        trapezoid.setPoint(1, sf::Vector2f(baseMajor, currentY));
        trapezoid.setPoint(2, sf::Vector2f(baseMinor, currentY + layerHeights[i]));
        trapezoid.setPoint(3, sf::Vector2f(0, currentY + layerHeights[i]));

        trapezoid.setFillColor(sf::Color::Blue);

        window.draw(trapezoid);

        currentY += layerHeights[i];
    }

    // Draw the last layer
    sf::ConvexShape trapezoid(4);
    trapezoid.setPoint(0, sf::Vector2f(0, currentY));
    trapezoid.setPoint(1, sf::Vector2f(baseMajor, currentY));
    trapezoid.setPoint(2, sf::Vector2f(baseMinor, currentY + layerHeights[numLayers - 2]));
    trapezoid.setPoint(3, sf::Vector2f(0, currentY + layerHeights[numLayers - 2]));

    trapezoid.setFillColor(sf::Color::Blue);
    window.draw(trapezoid);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Barrel Drawing");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        // Draw 24 barrels
        for (int i = 0; i < numBarrels; ++i) {
            float startX = i * barrelLength;
            drawBarrel(window, startX, 0);
        }

        window.display();
    }

    return 0;
}
