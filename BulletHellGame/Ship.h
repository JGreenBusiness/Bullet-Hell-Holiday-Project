#pragma once
#include "Bullet.h"
#include "IEntity.h"
#include "C:\Users\Justin\Desktop\Github\BulletHellCPP\Bullet-Hell-Holiday-Project\MathLib\Rect.h"
#include "Input.h"
#include "Renderer2D.h"

using MathLib::Rect;
using MathLib::Vec2;
using aie::Renderer2D;
class Ship : public IEntity
{
public:
    Ship(Vec2 _pos,Vec2 _size, aie::Input* _input);
    ~Ship() override;
    void Awake() override;
    void Update(float _dt) override;
    void Draw(Renderer2D* _renderer2D) override;
protected:
    Vec2 m_pos;
    Vec2 m_size;
    float m_acceleration = 0.5f;
    float m_velocity = 0.0f;
    float m_velCap = 8.1f;
    float m_reloadTime = 0.0f;
    float m_fireSpeed = 0.08f;
    float m_health =1.0f;
    Circle* m_hitBox;

    const int m_MAX_BULLETS = 50;
    Bullet* m_bullets[50];

    aie::Input* m_input;
 };
