#pragma once
#include "Application2D.h"
#include "Input.h"
#include "C:/Users/Justin/Desktop/Github/BulletHellCPP/Bullet-Hell-Holiday-Project/MathLib/Rect.h"

#include "Renderer2D.h"
#include "C:/Users/Justin/Desktop/Github/BulletHellCPP/Bullet-Hell-Holiday-Project/MathLib/Vec2.h"
#include "Text.h"


using MathLib::Vec2;
using aie::Renderer2D;
using aie::Application;


class Button
{
public:
    Button(Vec2 _pos, Vec2 _size,unsigned int _colour,const char* _text,aie::Font* _font,unsigned int _textColour);
    ~Button();

    void Update(Vec2 _mousePos);
    void Draw(Renderer2D* _renderer2D);
    void DrawRect(Renderer2D* _renderer2D);
    bool Clicked() {return m_clicked;}
    void SetClicked(bool _clicked) {m_clicked = _clicked;}
    bool Hovering() {return m_hovering;}
    MathLib::Rect* GetRect() {return m_rect;}
    Text* GetText(){return m_text;}

protected:
private:
    void OnClick();
    void OnHover();

    MathLib::Rect* m_rect;
    bool m_clicked = false;
    bool m_mouseDown = false;
    bool m_hovering = false;
    
    aie::Input* m_input;
    unsigned int m_colour;
    Text* m_text;

};
