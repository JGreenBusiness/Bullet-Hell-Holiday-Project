#include "Button.h"

#include "Input.h"

Button::Button(Vec2 _pos, Vec2 _size,Application2D* _app)
{
    m_input = aie::Input::getInstance();
    m_app = _app;
    m_2dRenderer = m_app->GetRenderer();
    m_rect = new Rect(_pos,_size);
}

Button::Button(Vec2 _pos, float _width, float _height,Application2D* _app)
{
    m_input = aie::Input::getInstance();

    m_app = _app;
    m_2dRenderer = m_app->GetRenderer();
    m_rect = new Rect(_pos,Vec2(_width,_height));
}

Button::Button(float _xPos, float _yPos, float _width, float _height,Application2D* _app)
{
    m_input = aie::Input::getInstance();

    m_app = _app;
    m_2dRenderer = m_app->GetRenderer();
    m_rect = new Rect(Vec2(_xPos,_yPos),Vec2(_width,_height));
}

Button::~Button()
{
    delete m_rect;
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
        m_hovering = false;
    }
}

void Button::Draw()
{
    m_2dRenderer->drawBox(m_rect->Position.x,m_rect->Position.y,m_rect->GetSize().x,m_rect->GetSize().y);
}


void Button::OnClick()
{
    m_clicked = true;
}

void Button::OnHover()
{
    if(m_input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT))
    {
        OnClick();
    }
}
