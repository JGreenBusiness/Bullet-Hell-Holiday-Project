#pragma once
#include "C:\Users\Justin\Desktop\Github\BulletHellCPP\Bullet-Hell-Holiday-Project\MathLib\Mat3.h"
#include "Texture.h"

using ::aie::Texture;
using MathLib::Mat3;
class IEntity
{
public:
    virtual ~IEntity() = default;
    virtual void Awake() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    
    MathLib::Mat3 Transform;
    aie::Texture* Sprite;
protected:
private:
};
