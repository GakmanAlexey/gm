#pragma once
#include <SFML/Graphics.hpp>
#include <windows.h>
#pragma comment(lib, "winmm.lib")
#include <string>
#include "winAuth.cpp"
#include "loader.cpp"
#include "key.cpp"
#include "winSelect.cpp"
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
    bool sound_job = false;

    bool winSelLoad = false;
    WinSelect WinSel;
    
    String focus_mous = "";
    /*
    Основной цикл
    */
    void sound(int x){
        mciSendString("play cl/resurse/voice/test.mp3 wait", NULL, 0, NULL)  ; 
    }
    void Run(void)
    {
        if(!sound_job){
        sound_job = true;  
        }
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
                if(!winSelLoad)
                {
                    WinSel.load();
                    winSelLoad = true;
                }
                WinSel.rend(window);
            }
            else
            {
                
            }
            event(window, WinAuth); 
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
    
    /*
    События
    */
    void event(sf::RenderWindow &window, WinAuths &WinAuth)
    {
        key.event(window,WinAuth,active_windows);
            //if(Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Up)){m_testSprite.move(-0.1*time,-0.1*time); m_testSprite.setTextureRect(IntRect(128*int(currentFrame),896,128,128));}          
    } 
    void Timers(void){
        time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time =  time/600;    
    }
};