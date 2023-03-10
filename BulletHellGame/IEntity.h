#pragma once
#include "C:\Users\Justin\Desktop\Github\BulletHellCPP\Bullet-Hell-Holiday-Project\MathLib\Mat3.h"
#include "Renderer2D.h"
#include "Texture.h"

using ::aie::Texture;
using MathLib::Mat3;
using aie::Renderer2D;
class IEntity
{
public:
    virtual ~IEntity() = default;
    virtual void Awake() = 0;
    virtual void Update(float _dt) = 0;
    virtual void Draw(Renderer2D* _renderer2D) = 0;
    
    MathLib::Mat3 Transform;
    aie::Texture* Sprite;
protected:
private:
};
