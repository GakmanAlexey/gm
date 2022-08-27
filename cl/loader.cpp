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
    Image logoImage;
    Texture logoTexure;
    Loader(){};
    void PreLoad(void)
    {        
        logoImage.loadFromFile("cl/resurse/texturs/layer/logo.png");
    }
    void Load(void)
    {        
        logoTexure.loadFromImage(Loader::logoImage);
    }
};