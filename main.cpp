#include <SFML/Graphics.hpp>
#include "cl/loader.cpp"

using namespace sf;
Loader textur;
int main()
{
    textur.PreLoad();
    textur.Load();
    sf::RenderWindow window(sf::VideoMode(1550, 870), "RedLava");// ,sf::Style::Fullscreen параметры экрана
    float currentFrame = 0;

    Sprite logoSprite;
    logoSprite.setTexture(textur.x_logoTexure);
    logoSprite.setPosition(0,0);
    Sprite m_testSprite;
    m_testSprite.setTexture(textur.m_testTexure);
    m_testSprite.setTextureRect(IntRect(0,0,128,128));
    m_testSprite.setPosition(30,30);


    Clock clock;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/600;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        currentFrame+= 0.005*time;
        if(currentFrame> 10){currentFrame -=10;}
        
        if(Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Up)){m_testSprite.move(-0.1*time,-0.1*time); m_testSprite.setTextureRect(IntRect(128*int(currentFrame),896,128,128));}
        else if(Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Down)){m_testSprite.move(-0.1*time,0.1*time); m_testSprite.setTextureRect(IntRect(128*int(currentFrame),640,128,128));}
        else if(Keyboard::isKeyPressed(Keyboard::Right)&& Keyboard::isKeyPressed(Keyboard::Up)){m_testSprite.move(0.1*time,-0.1*time); m_testSprite.setTextureRect(IntRect(128*int(currentFrame),128,128,128));}
        else if(Keyboard::isKeyPressed(Keyboard::Right)&& Keyboard::isKeyPressed(Keyboard::Down)){m_testSprite.move(0.1*time,0.1*time); m_testSprite.setTextureRect(IntRect(128*int(currentFrame),384,128,128));}
        else if(Keyboard::isKeyPressed(Keyboard::Left)){m_testSprite.move(-0.1*time,0); m_testSprite.setTextureRect(IntRect(128*int(currentFrame),768,128,128));}
        else if(Keyboard::isKeyPressed(Keyboard::Right)){m_testSprite.move(0.1*time,0); m_testSprite.setTextureRect(IntRect(128*int(currentFrame),256,128,128));}
        else if(Keyboard::isKeyPressed(Keyboard::Up)){m_testSprite.move(0,-0.1*time); m_testSprite.setTextureRect(IntRect(128*int(currentFrame),0,128,128));}
        else if(Keyboard::isKeyPressed(Keyboard::Down)){m_testSprite.move(0,0.1*time); m_testSprite.setTextureRect(IntRect(128*int(currentFrame),512,128,128));}

        window.clear();
        window.draw(logoSprite);
        window.draw(m_testSprite);
        window.display();
    }

    return 0;
}