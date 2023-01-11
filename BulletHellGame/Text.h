#pragma once
#include "Application2D.h"
#include "Renderer2D.h"
#include "C:/Users/Justin/Desktop/Github/BulletHellCPP/Bullet-Hell-Holiday-Project/MathLib/Vec2.h"


using MathLib::Vec2;
using aie::Renderer2D;
class Text
{
public:
    Text(const char* _body, Vec2 _pos,aie::Font * _font,unsigned int _colour);
    ~Text();

    void Draw(Renderer2D* _renderer2D);

    void SetColour(unsigned int _colour);
    void SetCenterAlign(bool _centerAlign) {m_centerAlign = _centerAlign;}

    const char* GetTextBody() {return m_body;}
    
    Vec2 m_pos;
    const char* m_body = "";
private:
    
    unsigned int m_colour;
    aie::Font* m_font;
    bool m_centerAlign = false;
};
