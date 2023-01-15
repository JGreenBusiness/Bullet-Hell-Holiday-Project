#pragma once
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
    Ship(Vec2 _pos,Vec2 _size,Renderer2D* _renderer2D, aie::Input* _input);
    ~Ship() override;
    void Awake() override;
    void Update() override;
    void Draw() override;
protected:
    Vec2 m_pos;
    Vec2 m_size;
    float m_speed = 0;
    float m_velocity = 0;
    //Bullet[] m_bullets
    float m_fireSpeed = 1;
    float m_health =1;
    Rect* m_hitBox;

    Renderer2D* m_renderer2D;
    aie::Input* m_input;
 };
