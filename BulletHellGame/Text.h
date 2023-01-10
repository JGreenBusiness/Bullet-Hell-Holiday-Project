#pragma once
#include "Application2D.h"
#include "C:/Users/Justin/Desktop/Github/BulletHellCPP/Bullet-Hell-Holiday-Project/MathLib/Vec2.h"


using MathLib::Vec2;

class Text
{
public:
    Text(const char* _body, Vec2 _pos,aie::Font * _font,unsigned short _size,unsigned int _colour ,Application2D* _app );
    ~Text();

    void Draw();

    void SetSize(unsigned short _size);

    void SetColour(unsigned int _colour);    
private:
    Vec2 m_pos;
    const char* m_body = "";
    unsigned int m_colour;
    unsigned short m_size;
    aie::Font* m_font;

    Application2D* m_app;
    aie::Renderer2D* m_2dRend;
};
