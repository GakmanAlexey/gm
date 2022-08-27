#include <SFML/Graphics.hpp>
#include "cl/loader.cpp"

using namespace sf;
Loader textur;
int main()
{
    textur.PreLoad();
    textur.Load();
    sf::RenderWindow window(sf::VideoMode(1550, 870), "RedLava");// ,sf::Style::Fullscreen параметры экрана


    Sprite logoSprite;
    logoSprite.setTexture(textur.logoTexure);
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