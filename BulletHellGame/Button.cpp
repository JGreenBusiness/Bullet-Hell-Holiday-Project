#include "Button.h"

#include "Input.h"

Button::Button(Vec2 _pos, Vec2 _size,unsigned int _colour,Application2D* _app)
{
    m_input = aie::Input::getInstance();
    m_app = _app;
    m_2dRend = m_app->GetRenderer();
    m_rect = new MathLib::Rect(_pos,_size);
    m_colour = _colour;
}

Button::Button(Vec2 _pos, float _width, float _height,unsigned int _colour,Application2D* _app)
{
    m_input = aie::Input::getInstance();

    m_app = _app;
    m_2dRend = m_app->GetRenderer();
    m_rect = new MathLib::Rect(_pos,Vec2(_width,_height));
    m_colour = _colour;
}

Button::Button(float _xPos, float _yPos, float _width, float _height,unsigned int _colour,Application2D* _app)
{
    m_input = aie::Input::getInstance();

    m_app = _app;
    m_2dRend = m_app->GetRenderer();
    m_rect = new MathLib::Rect(Vec2(_xPos,_yPos),Vec2(_width,_height));
    m_colour = _colour;
}

Button::~Button()
{
    delete m_rect;
    m_rect = nullptr;
}

void Button::Update(Vec2* _mousePos)
{
    if(m_rect->IsPointInside(*_mousePos))
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

void Button::Draw()
{
    
    float colour[4] = {m_2dRend->GetRed(),m_2dRend->GetGreen(),m_2dRend->GetBlue(),m_2dRend->GetAlpha()};
    m_2dRend->setRenderColour(m_colour);

    if(m_hovering)
    {
        if(m_mouseDown)
        {
            m_2dRend->setRenderColour(m_2dRend->GetRed(),m_2dRend->GetGreen(),m_2dRend->GetBlue(),.6f);
        }
        else
        {
            m_2dRend->setRenderColour(m_2dRend->GetRed(),m_2dRend->GetGreen(),m_2dRend->GetBlue(),.85f);
        }
    }
    else
    {
        m_2dRend->setRenderColour(m_2dRend->GetRed(),m_2dRend->GetGreen(),m_2dRend->GetBlue(),1.0f);
    }

    
    m_2dRend->drawBox(m_rect->Position.x,m_rect->Position.y,m_rect->GetSize().x,m_rect->GetSize().y);

    

    m_2dRend->setRenderColour(colour[0],colour[1],colour[2],colour[3]);

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
