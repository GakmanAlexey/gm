#pragma once
#include <SFML/Graphics.hpp>
#include "main2.cpp"
#include "winAuth.cpp"
#include <string>
#include <windows.h>
#include <shellapi.h>
class Keys
{    
public:    
    int reg = 0;
    String focus_mous="";
    int active_windows = 0;
    void load(sf::RenderWindow &window){
        
    }
    void event(sf::RenderWindow &window, WinAuths &WinAuth){
         sf::Event event;
            while (window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed){
                    window.close();
                }
                if(event.type == sf::Event::TextEntered){
                    if(focus_mous == "login"){
                         if (event.text.unicode >= 33 && event.text.unicode<=126){
                            WinAuth.login += event.text.unicode;
                         }
                         else if(event.text.unicode == 8){
                            WinAuth.lenlogin=0;
                            while (WinAuth.login[WinAuth.lenlogin] !='\0' && WinAuth.lenlogin < 100)
                            {
                                ++WinAuth.lenlogin;
                            }
                            WinAuth.lenlogin;
                            if((WinAuth.lenlogin) > 0){
                                WinAuth.login.erase((WinAuth.lenlogin-1),1);
                            }      
                         }
                    }
                    else if(focus_mous == "password"){
                         if (event.text.unicode >= 33 && event.text.unicode<=126){
                            WinAuth.password += event.text.unicode;
                         }else if(event.text.unicode == 8){
                            WinAuth.lenlogin=0;
                            while (WinAuth.password[WinAuth.lenlogin] !='\0' && WinAuth.lenlogin < 100)
                            {
                                ++WinAuth.lenlogin;
                            }
                            WinAuth.lenlogin;
                            if((WinAuth.lenlogin) > 0){
                                WinAuth.password.erase((WinAuth.lenlogin-1),1);
                            }
                         }
                    }
                }                
            }  
               
        if(active_windows == 0) 
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i position = sf::Mouse::getPosition (window);
                if(position.x > 624 && position.x < 926 && position.y > 600 && position.y <=640)
                {
                    focus_mous = "login";
                }
                else if(position.x > 624 && position.x < 926 && position.y >=650 && position.y < 690)
                    focus_mous = "password";
                else if(position.x > 721 && position.x < 930 && position.y >=721 && position.y < 762)
                {
                    focus_mous = "";
                    active_windows = 1;
                }
                else if(position.x > 672 && position.x < 881 && position.y >=710 && position.y < 750)
                {
                    focus_mous = "";
                    active_windows = 1;
                }
                else if(position.x > 672 && position.x < 881 && position.y >=760 && position.y < 800)
                {
                    focus_mous = "";
                    if(reg == 0){
                    ShellExecute(0, 0, "http://www.redlava.ru", 0, 0 , SW_SHOW );
                    reg =1;
                    }
                }
                else
                    focus_mous = "";

            }
        }
        
    }
};