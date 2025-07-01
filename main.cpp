#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "SFML works!");
    
    sf::Clock clock;

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin({shape.getRadius(), shape.getRadius()});
    shape.setPosition({ window.getSize().x / 2.f, window.getSize().y / 2.f });

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        float scalefactor = std::sin(clock.getElapsedTime().asSeconds());
        std::cout << std::sin(clock.getElapsedTime().asSeconds());
        shape.setScale({ scalefactor, scalefactor });
        window.draw(shape);

        window.display();
    }
}