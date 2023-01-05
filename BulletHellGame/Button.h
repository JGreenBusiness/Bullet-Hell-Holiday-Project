#pragma once
#include "Application2D.h"
#include "Input.h"
#include "Rect.h"
#include "Renderer2D.h"
#include "Vec2.h"

using MathLib::Vec2;
using MathLib::Rect;
using aie::Renderer2D;
using aie::Application;


class Button
{
public:
    Button(Vec2 _pos, Vec2 _size,Application2D* _app );
    Button(Vec2 _pos, float _width, float _height,Application2D* _app);
    Button(float _xPos, float _yPos, float _width, float _height,Application2D* _app);
    ~Button();

    void Update(Vec2 _mousePos);
    void Draw();
    bool Clicked() {return m_clicked;}
    void SetClicked(bool _clicked) {m_clicked = _clicked;}
    bool Hovering() {return m_hovering;}
    Rect* GetRect() {return m_rect;}

protected:
private:
    void OnClick();
    void OnHover();

    Vec2 m_mousePos;
    Rect* m_rect;
    bool m_clicked = false;
    bool m_hovering = false;
    
    Renderer2D* m_2dRenderer;
    aie::Input* m_input;
    Application2D* m_app;

};
