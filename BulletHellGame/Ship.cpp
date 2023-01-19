#include "Ship.h"

#include <complex>
#include <iostream>

#include "Bullet.h"

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

    if(m_bullet != nullptr)
    {
        delete m_bullet;
        m_bullet = nullptr;
    }
}

void Ship::Awake()
{
        m_bullet = nullptr;
}

void Ship::Update(float _dt)
{
    m_pos = Transform.GetTranslation();
    m_hitBox->Position = m_pos;
    float speed = 5.1f;

    Vec2 mousePos = Vec2(m_input->getMouseX(),m_input->getMouseY());
    Vec2 dir = Vec2::Normalise(Vec2::Subtract(mousePos,m_pos));
    if(dir.x < 1 && dir.y < 1)
    {
        Transform.SetRotationZ(std::atan2(-dir.x,dir.y));
        
    }

    if(Vec2::Distance(mousePos, m_pos) > 5)
    {
        Transform = Mat3::Multiply(Mat3::CreateTranslation(0,speed * m_input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_RIGHT)),Transform);
    }

    if(m_input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT))
    {
            Vec2 bulletPos = Vec2::Add(m_pos, Vec2::PostScale(dir,m_size.y));
        if(m_bullet == nullptr)
        {
            std::cout << "shot" << std::endl;

            m_bullet= new Bullet(dir,bulletPos,m_renderer2D);

        }
        else
        {
            std::cout << "shot" << std::endl;
            delete m_bullet;
            m_bullet= new Bullet(dir,bulletPos,m_renderer2D);
        }
        
    }

    if(m_bullet !=nullptr)
    {
        m_bullet->Update(_dt);
    }

}
void Ship::Draw()
{
    if(Sprite != nullptr)
    {
        //m_renderer2D->drawBox(m_hitBox->Position.x, m_hitBox->Position.y,m_hitBox->GetSize().x,m_hitBox->GetSize().y,Transform.GetRotationX(),1);
        m_renderer2D->drawSprite(Sprite,m_pos.x,m_pos.y,m_size.x*2,m_size.y*2,Transform.GetRotationX(),1);
    }
    else
    {
        m_renderer2D->drawBox(m_pos.x,m_pos.y,m_size.x,m_size.y,Transform.GetRotationX(),1);
    }

    if(m_bullet !=nullptr)
    {
        m_bullet->Draw();
    }
}
