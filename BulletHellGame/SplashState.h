#pragma once
#include "IGameState.h"

class SplashState : public IGameState
{
public:
    SplashState(Application2D* _app);

    ~SplashState() override;

    void Load() override;
    void UnLoad() override;

    void Update(float _dt) override;
    void Draw() override;

protected:
private:
    aie::Font* m_font;

    float m_timer = 0;

};
