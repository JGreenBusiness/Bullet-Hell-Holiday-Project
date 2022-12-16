#pragma once

#include "IGameState.h"

class SplashState : public IGameState
{
public:
    SplashState();
    virtual ~SplashState();

    virtual void Load() {}
    virtual void UnLoad() {}

    virtual void Update(float _dt) {}
    virtual void Draw() {}

protected:
private:
    
    
};
