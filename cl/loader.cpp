#pragma once
#include <SFML/Graphics.hpp>

/*
Загрузщик текстур!
Иконки      i_
Гуи         g_

Карта       e_ 
Здания      h_
Объекты     o_
Барьеры     b_
Игроки      p_
Мобы        m_
НПС         n_

Прочее      x_

*/

using namespace sf;
class Loader{
public:
    Image g_but1Image;
    Texture g_but1Texure;

    Image g_ipn1Image;
    Texture g_ipn1Texure;

    Image x_b80Image;
    Texture x_b80Texure;

    Image x_fonAuthImage;
    Texture x_fonAuthTexure;
    
    Image m_testImage;
    Texture m_testTexure;

    Image x_logoImage;
    Texture x_logoTexure;
    void PreLoad(void)
    {        
        g_but1Image.loadFromFile("cl/resurse/texturs/g_but1.png");
        g_ipn1Image.loadFromFile("cl/resurse/texturs/g_input1.png");
        x_b80Image.loadFromFile("cl/resurse/texturs/b80.png");
        x_fonAuthImage.loadFromFile("cl/resurse/texturs/layer/fonAuth.png");
        m_testImage.loadFromFile("cl/resurse/texturs/m_test.png");
        x_logoImage.loadFromFile("cl/resurse/texturs/layer/logo.png");
    }
    void Load(void)
    {        
        g_but1Texure.loadFromImage(Loader::g_but1Image);
        g_ipn1Texure.loadFromImage(Loader::g_ipn1Image);
        x_b80Texure.loadFromImage(Loader::x_b80Image);
        x_fonAuthTexure.loadFromImage(Loader::x_fonAuthImage);
        m_testTexure.loadFromImage(Loader::m_testImage);
        x_logoTexure.loadFromImage(Loader::x_logoImage);
    }
};