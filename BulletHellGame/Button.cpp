#include "Button.h"

#include "Font.h"
#include "Input.h"
Button::Button(Vec2 _pos, Vec2 _size,unsigned int _colour,const char* _text,aie::Font* _font, unsigned int _textColour)
{
    m_input = aie::Input::getInstance();
    m_rect = new MathLib::Rect(_pos,_size);
    m_text = new Text(_text,Vec2(_pos.x,_pos.y),_font,_textColour);
    m_text->SetCenterAlign(true);
    m_colour = _colour;
}

Button::~Button()
{
    delete m_rect;
    m_rect = nullptr;

    delete m_text;
    m_text = nullptr;
}

void Button::Update(Vec2 _mousePos)
{
    if(m_rect->IsPointInside(_mousePos))
    {
        m_hovering = true;
        OnHover();
    }
    else
    {
        m_mouseDown = false;
        m_hovering = false;
    }
}

void Button::Draw(Renderer2D* _renderer2D)
{

    DrawRect(_renderer2D);
    m_text->Draw(_renderer2D);
}

void Button::DrawRect(Renderer2D* _rend2D)
{
    float colour[4] = {_rend2D->GetRed(),_rend2D->GetGreen(),_rend2D->GetBlue(),_rend2D->GetAlpha()};
    _rend2D->setRenderColour(m_colour);
    
    if(m_hovering)
    {
        if(m_mouseDown)
        {
             _rend2D->setRenderColour(_rend2D->GetRed(),_rend2D->GetGreen(),_rend2D->GetBlue(),.6f);
        }
        else
        {
            _rend2D->setRenderColour(_rend2D->GetRed(),_rend2D->GetGreen(),_rend2D->GetBlue(),.85f);
        }
    }
    else
    {
        _rend2D->setRenderColour(_rend2D->GetRed(),_rend2D->GetGreen(),_rend2D->GetBlue(),1.0f);
    }
    _rend2D->drawBox(m_rect->Position.x,m_rect->Position.y,m_rect->GetSize().x,m_rect->GetSize().y);
    _rend2D->setRenderColour(colour[0],colour[1],colour[2],colour[3]);
}


void Button::OnClick()
{
    m_clicked = !m_clicked;
}

void Button::OnHover()
{
    
    if(m_input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT) && !m_mouseDown)
    {
        m_mouseDown = true;
    }
    

    if(m_input->isMouseButtonUp(aie::INPUT_MOUSE_BUTTON_LEFT) && m_mouseDown)
    {
        OnClick();
        m_mouseDown = false;
    }
}
