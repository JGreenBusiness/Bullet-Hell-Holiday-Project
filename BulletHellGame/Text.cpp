#include "Text.h"

#include "Font.h"

Text::Text(const char* _body, Vec2 _pos, aie::Font* _font, unsigned short _size, unsigned _colour, Application2D* _app)
{
    m_body = _body;
    m_pos = _pos;
    m_font = _font;
    m_size = _size;
    m_colour = _colour;

    m_app = _app;
    m_2dRend = m_app->GetRenderer();
}

Text::~Text()
{
    
}


void Text::Draw()
{
    float colour[4] = {m_2dRend->GetRed(),m_2dRend->GetGreen(),m_2dRend->GetBlue(),m_2dRend->GetAlpha()};
    m_2dRend->setRenderColour(m_colour);

    unsigned short initialSize = m_font->GetFontSize();

    m_font->SetFontSize(m_size);
    m_2dRend->drawText(m_font,m_body,m_pos.x,m_pos.y,1);
    m_font->SetFontSize(initialSize);


    m_2dRend->setRenderColour(colour[0],colour[1],colour[2],colour[3]);
}

void Text::SetSize(unsigned short _size)
{
    m_size = _size;
}

void Text::SetColour(unsigned _colour)
{
    m_colour = _colour;
}
