#pragma once
#include "C:\Users\Justin\Desktop\Github\BulletHellCPP\Bullet-Hell-Holiday-Project\MathLib\Circle.h"
#include "IEntity.h"
#include "Renderer2D.h"
#include "C:\Users\Justin\Desktop\Github\BulletHellCPP\Bullet-Hell-Holiday-Project\MathLib\Vec2.h"


using MathLib::Vec2;
using MathLib::Circle;
using aie::Renderer2D;
class Bullet : IEntity
{
public:
    Bullet(Vec2 _bulletDir,Vec2 _pos);
    Bullet();
    ~Bullet() override;

    void Awake() override;
    void Update(float _dt) override;
    void Draw(Renderer2D* _renderer2D) override;
protected:
private:
    float m_speed = 20.0f;
    Vec2 m_pos;
    Circle* m_hitBox;

    float m_liveTime = 1.0f;
};
