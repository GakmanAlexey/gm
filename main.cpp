#include <SFML/Graphics.hpp>

using namespace sf;
int main()
{
    sf::RenderWindow window(sf::VideoMode(1550, 870), "RedLava");// ,sf::Style::Fullscreen параметры экрана
    Image logoImage;
    logoImage.loadFromFile("cl/resurse/texturs/layer/logo.png");

    Texture logoTexure;
    logoTexure.loadFromImage(logoImage);

    Sprite logoSprite;
    logoSprite.setTexture(logoTexure);
    logoSprite.setPosition(0,0);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(logoSprite);
        window.display();
    }

    return 0;
}