#include "Ship.h"

#include <complex>
#include <iostream>

Ship::Ship(Vec2 _pos,Vec2 _size,Renderer2D* _renderer2D,aie::Input* _input)
{
    m_renderer2D = _renderer2D;
    m_input = _input;
    
    Transform.m7 = _pos.x;
    Transform.m8 = _pos.y;
    m_pos = Vec2(Transform.m7,Transform.m8);
    m_size = _size;
    m_hitBox = new Rect(m_pos,Vec2(m_size.x,m_size.y));
}

Ship::~Ship()
{
    delete m_hitBox;
    m_hitBox = nullptr;

    if(Sprite != nullptr)
    {
        delete Sprite;
        Sprite = nullptr;
    }
}

void Ship::Awake()
{
}

void Ship::Update()
{
    m_pos = Vec2(Transform.m7,Transform.m8);
    m_hitBox->Position = m_pos;
    float speed = 3.1f;


    if(!m_input->getPressedKeys().empty())
    {
        Transform.SetTranslation(0,speed * m_input->isKeyDown(aie::INPUT_KEY_W));
        Transform.SetTranslation(0,-speed * m_input->isKeyDown(aie::INPUT_KEY_S));
        Transform.SetTranslation(-speed * m_input->isKeyDown(aie::INPUT_KEY_A),0);
        Transform.SetTranslation(speed * m_input->isKeyDown(aie::INPUT_KEY_D),0);

        float rotX = Transform.GetRotationX();
        Transform.SetRotationZ(rotX += -0.1f * m_input->isKeyDown(aie::INPUT_KEY_RIGHT));
        Transform.SetRotationZ(rotX += 0.1f * m_input->isKeyDown(aie::INPUT_KEY_LEFT));
    }
    
}
void Ship::Draw()
{
    if(Sprite != nullptr)
    {
        m_renderer2D->drawBox(m_hitBox->Position.x, m_hitBox->Position.y,m_hitBox->GetSize().x,m_hitBox->GetSize().y,Transform.GetRotationX(),1);
        m_renderer2D->drawSprite(Sprite,m_pos.x,m_pos.y,m_size.x*2,m_size.y*2,Transform.GetRotationX(),1);
    }
    else
    {
        m_renderer2D->drawBox(m_pos.x,m_pos.y,m_size.x,m_size.y,Transform.GetRotationX(),1);
    }
}
