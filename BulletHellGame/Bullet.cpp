#include "Bullet.h"

#include <valarray>


Bullet::Bullet(Vec2 _bulletDir, Vec2 _pos)
{
   Transform.SetRotationZ(std::atan2(-_bulletDir.x,_bulletDir.y));

    m_pos = _pos;
    
    Transform.SetTranslation(m_pos);
    m_hitBox = new Circle(m_pos, 5);
}

Bullet::Bullet()
{
    m_hitBox = nullptr;
    
}

Bullet::~Bullet()
{
    delete m_hitBox;
    m_hitBox = nullptr;
}

void Bullet::Awake()
{
}

void Bullet::Update(float _dt)
{
    m_pos = Transform.GetTranslation();
    
    Transform = Mat3::Multiply(Mat3::CreateTranslation(0,m_speed),Transform);

    m_liveTime -= _dt;
}

void Bullet::Draw(Renderer2D* _renderer2D)
{
    _renderer2D->drawCircle(m_pos.x,m_pos.y, m_hitBox->Radius,.3f);
}
