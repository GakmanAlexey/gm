#include <SFML/Graphics.hpp>
#include <string>
#include "loader.cpp"

    /*
    0 - Окно авторизации
    1 - Окно выбора персонажа
    2 - Окно загрузки
    3 - Окно игры
    */
class MAIN
{
public:
    int active_windows = 0;//Окно
    
    int w = 1550;
    int h = 870;
    String nameprog = "RedLava";

    Clock clock;
    
    /*
    Основной цикл
    */
    void Run(void)
    {
        sf::RenderWindow window(sf::VideoMode(w, h), nameprog);// ,sf::Style::Fullscreen параметры экрана
        while (window.isOpen())
        {
           render(window);
           event(window);    
            
        }
    }
    /*
    Отрисовка
    */
    void render(sf::RenderWindow &window)
    {
        window.clear(); 
        //window.draw();
        window.display();
    } 
    /*
    События
    */
    void event(sf::RenderWindow &window)
    {
        sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }        
            //if(Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Up)){m_testSprite.move(-0.1*time,-0.1*time); m_testSprite.setTextureRect(IntRect(128*int(currentFrame),896,128,128));}          
    } 
    void Job(void){
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/600;    
    }
};