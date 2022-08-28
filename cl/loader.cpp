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

    Image m_testImage;
    Texture m_testTexure;

    Image x_logoImage;
    Texture x_logoTexure;
    void PreLoad(void)
    {        
        m_testImage.loadFromFile("cl/resurse/texturs/m_test.png");
        x_logoImage.loadFromFile("cl/resurse/texturs/layer/logo.png");
    }
    void Load(void)
    {        
        m_testTexure.loadFromImage(Loader::m_testImage);
        x_logoTexure.loadFromImage(Loader::x_logoImage);
    }
};