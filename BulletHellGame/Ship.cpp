#include "Ship.h"

#include <complex>
#include <iostream>

#include "Bullet.h"

Ship::Ship(Vec2 _pos,Vec2 _size, aie::Input* _input)
{
    m_input = _input;
    
    Transform.m7 = _pos.x;
    Transform.m8 = _pos.y;
    m_pos = Vec2(Transform.m7,Transform.m8);
    m_size = _size;
    m_hitBox = new Circle(m_pos,(m_size.x + m_size.y)/4);

    *m_bullets = new Bullet[m_MAX_BULLETS];

    for(int i = 0; i < m_MAX_BULLETS; i++)
    {
        m_bullets[i] = nullptr;
    }
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

    for(int i = 0; i < m_MAX_BULLETS; i++)
    {
        if(m_bullets[i] != nullptr)
        {
            delete m_bullets[i];
            m_bullets[i] = nullptr;
        }
        
    }
}

void Ship::Awake()
{
}

void Ship::Update(float _dt)
{
    m_pos = Transform.GetTranslation();
    m_hitBox->Position = m_pos;

    Vec2 mousePos = Vec2(m_input->getMouseX(),m_input->getMouseY());
    Vec2 dir = Vec2::Normalise(Vec2::Subtract(mousePos,m_pos));
    
    if(dir.x < 1 && dir.y < 1 && Vec2::Distance(mousePos,m_pos) > m_hitBox->Radius)
    {
        Transform.SetRotationZ(std::atan2(-dir.x,dir.y));
    }
    
    if(m_input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_RIGHT) && Vec2::Distance(mousePos,m_pos) > m_hitBox->Radius)
    {
        m_velocity += (m_velocity <= m_velCap) ? m_acceleration : 0;
    }
    else
    {
        m_velocity -= (m_velocity >= 0) ? m_acceleration : 0;
    }
    Transform = Mat3::Multiply(Mat3::CreateTranslation(0,(m_velocity < .1f) ? 0 : m_velocity ),Transform);

    if(m_input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT)&& Vec2::Distance(mousePos,m_pos) > m_hitBox->Radius)
    {
        Vec2 bulletPos = Vec2::Add(m_pos, Vec2::PostScale(dir,m_size.y));

        for(int i = 0; i < m_MAX_BULLETS; i++)
        {
            if(m_bullets[i] == nullptr)
            {
                m_bullets[i] = new Bullet(dir,bulletPos);
                break;
            }
            else if(m_bullets[i]->IsDead())
            {
                delete m_bullets[i];
                m_bullets[i] = nullptr;
            }
        }
    }

    for(int i = 0; i < m_MAX_BULLETS; i++)
    {
        if(m_bullets[i] != nullptr)
        {
            m_bullets[i]->Update(_dt);
        }
    }

}
void Ship::Draw(Renderer2D* _renderer2D)
{
    if(Sprite != nullptr)
    {
        _renderer2D->drawCircle(m_pos.x,m_pos.y,m_hitBox->Radius,1);

        _renderer2D->drawSprite(Sprite,m_pos.x,m_pos.y,m_size.x*2,m_size.y*2,Transform.GetRotationX(),1);
    }
    else
    {
        _renderer2D->drawCircle(m_pos.x,m_pos.y,m_hitBox->Radius,1);
    }

    for(int i = 0; i < m_MAX_BULLETS; i++)
    {
        if(m_bullets[i] != nullptr)
        {
            m_bullets[i] ->Draw(_renderer2D);
        }
    }
}
