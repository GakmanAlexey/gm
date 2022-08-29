#pragma once
#include <SFML/Graphics.hpp>
#include <windows.h>
#pragma comment(lib, "winmm.lib")
#include <string>
#include "winAuth.cpp"
#include "loader.cpp"
#include "key.cpp"
#include <iostream>
    /*
    0 - Окно авторизации
    1 - Окно выбора персонажа
    2 - Окно загрузки
    3 - Окно игры
    */
class Game
{
public:

    String login_t = "";
    int i = 0;
    int active_windows = 0;//Окно
    
    int w = 1550;
    int h = 870;
    String nameprog = "RedLava";
    Clock clock;
    float time;

    Keys key;
//
    bool winAuthLoad = false;
    WinAuths WinAuth;

    
    String focus_mous = "";
    /*
    Основной цикл
    */
    
    void Run(void)
    {
        
        sf::RenderWindow window(sf::VideoMode(w, h), nameprog);// ,sf::Style::Fullscreen параметры экрана
        window.setFramerateLimit(200);
        load();
        
        while (window.isOpen())
        {

            if(active_windows == 0){
                if(!winAuthLoad)
                {
                    WinAuth.load();
                    winAuthLoad = true;
                }
                WinAuth.rend(window);
            }
            else if(active_windows == 1)
            {
                render(window);
            }
            else
            {
                
            }
            event(window); 
            //mciSendString("play cl/resurse/voice/test.mp3 wait", NULL, 0, NULL)  ;          
            
        }
    }
    /*
    Отрисовка
    */
    Loader Textur;
    void load(void){
        Textur.PreLoad();
        Textur.Load();
    }
    
    void render(sf::RenderWindow &window)
    {
        window.clear(); 
        Sprite x_fonAuthSprite;
        x_fonAuthSprite.setTexture(Textur.x_fonAuthTexure);
        x_fonAuthSprite.setPosition(0,0);
        window.draw(x_fonAuthSprite);
        Sprite x_b80Sprite;
        x_b80Sprite.setTexture(Textur.x_b80Texure);//применяем текстуру
        x_b80Sprite.setTextureRect(sf::IntRect(1, 1, 400, 870));//область для отображения
        x_b80Sprite.setPosition(0, 0);//позиция отрисовки
        window.draw(x_b80Sprite);

        sf::Font font;
        font.loadFromFile("cl/resurse/fonts/f.otf");
        sf::Text txt ;
        txt.setFont(font);
        txt.setPosition ( 70 , 20 ) ;
        txt.setString ( L"Выбор персонажа" ) ;
        txt.setCharacterSize(24);
        txt.setStyle(sf::Text::Bold );
        window.draw ( txt ) ;
        window.display();
    } 
    /*
    События
    */
    void event(sf::RenderWindow &window)
    {
        key.event(window,WinAuth);
            //if(Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Up)){m_testSprite.move(-0.1*time,-0.1*time); m_testSprite.setTextureRect(IntRect(128*int(currentFrame),896,128,128));}          
    } 
    void Timers(void){
        time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time =  time/600;    
    }
};