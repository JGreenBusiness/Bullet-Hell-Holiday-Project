#include "Text.h"

Text::Text(const char* _body, Vec2 _pos, aie::Font* _font, unsigned int _colour)
{
    m_body = _body;
    m_pos = Vec2(_pos.x,_pos.y);
    m_font = _font;
    m_colour = _colour;
}

Text::~Text()
{
    
}


void Text::Draw(Renderer2D* _renderer2D)
{
    float colour[4] = {_renderer2D->GetRed(),_renderer2D->GetGreen(),_renderer2D->GetBlue(),_renderer2D->GetAlpha()};
    _renderer2D->setRenderColour(m_colour);

    _renderer2D->drawText(m_font,m_body,m_pos.x - strlen(m_body)*(m_centerAlign*8.0f), m_pos.y, 0);

    _renderer2D->setRenderColour(colour[0],colour[1],colour[2],colour[3]);
}

void Text::SetColour(unsigned _colour)
{
    m_colour = _colour;
}




